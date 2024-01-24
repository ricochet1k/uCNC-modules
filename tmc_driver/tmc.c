/*
	Name: tmc.c
	Description: Minimalistic generic driver library for Trinamic stepper drivers.

	Copyright: Copyright (c) João Martins
	Author: João Martins
	Date: 21-03-2022

	µCNC is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version. Please see <http://www.gnu.org/licenses/>

	µCNC is distributed WITHOUT ANY WARRANTY;
	Also without the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See the	GNU General Public License for more details.
*/

#include "tmc.h"
#include "tmc_bitfields.h"

uint8_t tmc_crc8(uint8_t *data, uint8_t len)
{
	int i, j;
	uint8_t crc = 0; // CRC located in last byte of message
	uint8_t currentByte;
	for (i = 0; i < len; i++)
	{						   // Execute for all bytes of a message
		currentByte = data[i]; // Retrieve a byte to be sent from Array
		for (j = 0; j < 8; j++)
		{
			if ((crc >> 7) ^ (currentByte & 0x01)) // update CRC based result of XOR operation
			{
				crc = (crc << 1) ^ 0x07;
			}
			else
			{
				crc = (crc << 1);
			}
			currentByte = currentByte >> 1;
		} // for CRC bit
	}	  // for message byte

	return crc;
}

uint32_t tmc_read_register(tmc_driver_t *driver, uint8_t address)
{
	if (!(driver->rw))
	{
		return TMC_READ_ERROR;
	}

	uint8_t data[8];
	uint8_t crc = 0;
	uint32_t result = TMC_READ_ERROR;
	switch (driver->type)
	{
	case 2202:
	case 2208:
	case 2225:
		driver->slave = 0;
	case 2209:
	case 2226:
		/* code */
		data[0] = 0x05;
		data[1] = driver->slave;
		data[2] = address & 0x7F;
		data[3] = tmc_crc8(data, 3);
		driver->rw(data, 4, 8);
		crc = tmc_crc8(data, 7);
		if (data[0] != 0x05)
		{
			return TMC_READ_ERROR;
		}
		if (data[1] != 0xFF)
		{
			return TMC_READ_ERROR;
		}
		if (data[2] != address)
		{
			return TMC_READ_ERROR;
		}
		if (crc != data[7])
		{
			return TMC_READ_ERROR;
		}
		result = ((uint32_t)data[3] << 24) | ((uint32_t)data[4] << 16) | (data[5] << 8) | data[6];
		break;
	case 2130:
		data[0] = address & 0x7F;
		data[1] = 0;
		data[2] = 0;
		data[3] = 0;
		data[4] = 0;
		driver->rw(data, 5, 5);
		result = ((uint32_t)data[1] << 24) | ((uint32_t)data[2] << 16) | (data[3] << 8) | data[4];
	}

	switch (address)
	{
	case IHOLD_IRUN:
		driver->reg.ihold_irun = result;
		break;
	case TPWMTHRS:
		driver->reg.tpwmthrs = result;
		break;
	case TCOOLTHRS:
		driver->reg.tcoolthrs = result;
		break;
	case SGTHRS:
	case COOLCONF:
		switch (driver->type)
		{
		case 2209:
		case 2226:
			driver->reg.sgthrs_coolconf = (address == SGTHRS) ? result : TMC_READ_ERROR;
			break;
		case 2130:
			driver->reg.sgthrs_coolconf = (address == COOLCONF) ? result : TMC_READ_ERROR;
		default:
			return TMC_READ_ERROR;
		}
		break;
	}

	return result;
}

uint32_t tmc_write_register(tmc_driver_t *driver, uint8_t address, uint32_t val)
{
	if (!(driver->rw))
	{
		return TMC_WRITE_ERROR;
	}

	switch (address)
	{
	case IHOLD_IRUN:
		if (driver->reg.ihold_irun == val)
		{
			return val;
		}
		break;
	case TPWMTHRS:
		if (driver->reg.tpwmthrs == val)
		{
			return val;
		}
		break;
	case TCOOLTHRS:
		if (driver->reg.tcoolthrs == val)
		{
			return val;
		}
		break;
	case SGTHRS:
		switch (driver->type)
		{
		case 2209:
		case 2226:
			if (driver->reg.sgthrs_coolconf == val)
			{
				return val;
			}
			break;
		default:
			return TMC_WRITE_ERROR;
		}
		break;
	case COOLCONF:
		switch (driver->type)
		{
		case 2130:
			if (driver->reg.sgthrs_coolconf == val)
			{
				return val;
			}
			break;
		default:
			return TMC_WRITE_ERROR;
		}
		break;
		// restricts write commands build it on this driver (prevents write commands to other addresses)
#ifndef TMC_UNSAFE_MODE
	case GCONF:
	case CHOPCONF:
	case PWMCONF:
		break;
	default:
		return TMC_WRITE_ERROR;
#endif
	}

	uint8_t cnt = driver->reg.ifcnt + 1;

	uint8_t data[8];
	switch (driver->type)
	{
	case 2202:
	case 2208:
	case 2225:
		driver->slave = 0;
	case 2209:
	case 2226:
		/* code */
		data[0] = 0x05;
		data[1] = driver->slave;
		data[2] = address | 0x80;
		data[3] = (val >> 24) & 0xFF;
		data[4] = (val >> 16) & 0xFF;
		data[5] = (val >> 8) & 0xFF;
		data[6] = (val) & 0xFF;
		data[7] = tmc_crc8(data, 7);
		driver->rw(data, 8, 0);
		break;
	case 2130:
		data[0] = address | 0x80;
		data[4] = (uint8_t)(val & 0xFF);
		val >>= 8;
		data[3] = (uint8_t)(val & 0xFF);
		val >>= 8;
		data[2] = (uint8_t)(val & 0xFF);
		val >>= 8;
		data[1] = (uint8_t)(val & 0xFF);
		driver->rw(data, 5, 5);
		break;
	default:
		return TMC_WRITE_ERROR;
	}

	// checks if write was executed
	if (tmc_read_register(driver, IFCNT) == cnt)
	{
		driver->reg.ifcnt = cnt;
		switch (address)
		{
		case IHOLD_IRUN:
			driver->reg.ihold_irun = val;
			break;
		case TPWMTHRS:
			driver->reg.tpwmthrs = val;
			break;
		case TCOOLTHRS:
			driver->reg.tcoolthrs = val;
			break;
		case SGTHRS:
		case COOLCONF:
			driver->reg.sgthrs_coolconf = val;
			break;
		}

		return val;
	}

	return TMC_WRITE_ERROR;
}

// specific initializations
// based on Marlin
static void tmc220x_init(tmc_driver_t *driver)
{
	GCONF_t gconf = {0};
	gconf.sr = tmc_read_register(driver, GCONF);

	gconf.pdn_disable = 1;		// Use UART
	gconf.mstep_reg_select = 1; // Select microsteps with UART
	gconf.i_scale_analog = 0;	// disable I_scale_analog

	if (driver->reg.tpwmthrs == 0)
	{
		gconf.en_spreadcycle = 1; // set spreadcycle
	}
	else
	{
		gconf.en_spreadcycle = 0; // set cyclechop
	}
	tmc_write_register(driver, GCONF, gconf.sr);

	CHOPCONF_t chopconf = {0};
	chopconf.sr = tmc_read_register(driver, CHOPCONF);
	chopconf.tbl = 1; // tbl = 0b01 blank_time = 24
	/**
	 * {toff, hend, hstrt}
	 * #define CHOPPER_DEFAULT_12V  { 3, -1, 1 }
	 * #define CHOPPER_DEFAULT_19V  { 4,  1, 1 }
	 * #define CHOPPER_DEFAULT_24V  { 4,  2, 1 }
	 * #define CHOPPER_DEFAULT_36V  { 5,  2, 4 }
	 * #define CHOPPER_PRUSAMK3_24V { 3, -2, 6 }
	 * #define CHOPPER_MARLIN_119   { 5,  2, 3 }
	 * #define CHOPPER_09STEP_24V   { 3, -1, 5 }
	 * **/
	// using 24V by default
	chopconf.toff = 4;		 // toff
	chopconf.hend = (2 + 3); // hend
	chopconf.hstrt = (1 - 1);
	tmc_write_register(driver, CHOPCONF, gconf.sr);
}

void tmc_init(tmc_driver_t *driver, tmc_driver_setting_t *settings)
{
	switch (driver->type)
	{
	case 2202:
	case 2208:
	case 2225:
	case 2209:
	case 2226:
		tmc220x_init(driver);
		break;
	}

	if (driver->init)
	{
		driver->init();
	}

	tmc_set_current(driver, settings->rms_current, settings->rsense, settings->ihold_mul, settings->ihold_delay);
	tmc_set_microstep(driver, settings->mstep);
	tmc_write_register(driver, TPOWERDOWN, 128);
	tmc_set_stealthchop(driver, settings->stealthchop_threshold);
	tmc_set_stepinterpol(driver, settings->step_interpolation);
	switch (driver->type)
	{
	case 2209:
	case 2130:
		tmc_set_stallguard(driver, settings->stallguard_threshold);
		break;
	}
}

float tmc_get_current(tmc_driver_t *driver, float rsense)
{
	CHOPCONF_t chopconf = {0};
	chopconf.sr = tmc_read_register(driver, CHOPCONF);
	if (chopconf.sr == TMC_READ_ERROR)
	{
		return -1;
	}

	uint8_t irun = (uint8_t)((driver->reg.ihold_irun >> 8) & 0x1F);
	return (float)(irun + 1) / 32.0 * ((chopconf.vsense) ? 0.180 : 0.325) / (rsense + 0.02) / 1.41421 * 1000;
}

void tmc_set_current(tmc_driver_t *driver, float current, float rsense, float ihold_mul, uint8_t ihold_delay)
{
	uint8_t currentsense = 32.0 * 1.41421 * current / 1000.0 * (rsense + 0.02) / 0.325 - 1;
	// If Current Scale is too low, turn on high sensitivity R_sense and calculate again
	CHOPCONF_t chopconf = {0};
	chopconf.sr = tmc_read_register(driver, CHOPCONF);

	if (chopconf.sr == TMC_READ_ERROR)
	{
		return;
	}

	if (currentsense < 16)
	{
		// enable vsense
		chopconf.vsense = 1;
		currentsense = 32.0 * 1.41421 * current / 1000.0 * (rsense + 0.02) / 0.180 - 1;
	}
	else
	{
		// If CS >= 16, turn off high_sense_r if it's currently ON
		// disable vsense
		//  enable vsense
		chopconf.vsense = 0;
	}

	tmc_write_register(driver, CHOPCONF, chopconf.sr);

	// rms current
	uint32_t ihold_irun = ((uint32_t)(currentsense & 0x1F)) << 8;
	// hold current
	currentsense = (uint8_t)(currentsense * ihold_mul);
	ihold_irun |= (currentsense & 0x1F);
	ihold_irun |= ((uint32_t)ihold_delay << 16);
	tmc_write_register(driver, IHOLD_IRUN, ihold_irun);
}

int32_t tmc_get_microstep(tmc_driver_t *driver)
{
	CHOPCONF_t chopconf = {0};
	chopconf.sr = tmc_read_register(driver, CHOPCONF);

	if (chopconf.sr == TMC_READ_ERROR)
	{
		return -1;
	}

	switch ((uint8_t)chopconf.mres)
	{
	case 0:
		return 256;
	case 1:
		return 128;
	case 2:
		return 64;
	case 3:
		return 32;
	case 4:
		return 16;
	case 5:
		return 8;
	case 6:
		return 4;
	case 7:
		return 2;
	case 8:
		return 1;
	}
	return 0;
}

void tmc_set_microstep(tmc_driver_t *driver, int16_t ms)
{
	GCONF_t gconf = {0};
	gconf.sr = tmc_read_register(driver, GCONF);
	CHOPCONF_t chopconf = {0};
	chopconf.sr = tmc_read_register(driver, CHOPCONF);

	if (gconf.sr == TMC_READ_ERROR)
	{
		return;
	}

	if (chopconf.sr == TMC_READ_ERROR)
	{
		return;
	}

	switch (ms)
	{
	case 256:
		ms = 0;
		break;
	case 128:
		ms = 1;
		break;
	case 64:
		ms = 2;
		break;
	case 32:
		ms = 3;
		break;
	case 16:
		ms = 4;
		break;
	case 8:
		ms = 5;
		break;
	case 4:
		ms = 6;
		break;
	case 2:
		ms = 7;
		break;
	case 1:
		ms = 8;
		break;
	default:
		if (ms < 0)
		{
			if (driver->type != 2130)
			{
				gconf.mstep_reg_select = 0;
				tmc_write_register(driver, GCONF, gconf.sr);
			}
			return;
		}
		break;
	}

	if (driver->type != 2130)
	{
		gconf.mstep_reg_select = 1;
		tmc_write_register(driver, GCONF, gconf.sr);
	}

	chopconf.mres = ms;
	tmc_write_register(driver, CHOPCONF, chopconf.sr);
}

uint8_t tmc_get_stepinterpol(tmc_driver_t *driver)
{
	CHOPCONF_t chopconf = {0};
	chopconf.sr = tmc_read_register(driver, CHOPCONF);
	if (chopconf.sr == TMC_READ_ERROR)
	{
		return 0;
	}
	return (chopconf.intpol != 0) ? 1 : 0;
}

void tmc_set_stepinterpol(tmc_driver_t *driver, uint8_t enable)
{
	CHOPCONF_t chopconf = {0};
	chopconf.sr = tmc_read_register(driver, CHOPCONF);

	if (chopconf.sr == TMC_READ_ERROR)
	{
		return;
	}

	if (enable)
	{
		chopconf.intpol = 1;
	}
	else
	{
		chopconf.intpol = 0;
	}

	tmc_write_register(driver, CHOPCONF, chopconf.sr);
}

int32_t tmc_get_stealthchop(tmc_driver_t *driver)
{
	return driver->reg.tpwmthrs;
}

void tmc_set_stealthchop(tmc_driver_t *driver, int32_t value)
{
	GCONF_t gconf = {0};
	gconf.sr = tmc_read_register(driver, GCONF);
	PWMCONF_t pwmconf = {0};

	gconf.sr = tmc_read_register(driver, GCONF);

	if (gconf.sr == TMC_READ_ERROR)
	{
		return;
	}

	switch (driver->type)
	{
	case 2202:
	case 2208:
	case 2225:
	case 2209:
	case 2226:
		gconf.en_spreadcycle = (!value) ? 1 : 0;
		pwmconf.pwm_lim = 12;
		pwmconf.pwm_reg = 8;
		pwmconf.pwm_autograd = 1;
		pwmconf.pwm_autoscale = 1;
		pwmconf.pwm_freq = 1;
		pwmconf.pwm_grad = 14;
		pwmconf.pwm_ofs = 36;
		break;
	case 2130:
		pwmconf.pwm_freq = 1; // f_pwm = 2/683 f_clk
		pwmconf.pwm_autoscale = 1;
		pwmconf.pwm_grad = 5;
		pwmconf.tmc2130.pwm_ampl = 180;
		gconf.tmc2130.en_pwm_mode = (!value) ? 0 : 1;
		break;
	}

	tmc_write_register(driver, GCONF, gconf.sr);
	tmc_write_register(driver, PWMCONF, pwmconf.sr);
	tmc_write_register(driver, TPWMTHRS, value);
}

uint32_t tmc_get_status(tmc_driver_t *driver)
{
	return tmc_read_register(driver, DRV_STATUS);
}

int32_t tmc_get_stallguard(tmc_driver_t *driver)
{
	COOLCONF_t coolconf = {0};
	switch (driver->type)
	{
	case 2209:
	case 2226:
		return tmc_read_register(driver, SGTHRS);
	case 2130:
		coolconf.sr = tmc_read_register(driver, COOLCONF);
		return coolconf.tmc2130.sgt;
	}

	// return an invalid value
	return -255;
}

void tmc_set_stallguard(tmc_driver_t *driver, int32_t value)
{
	COOLCONF_t coolconf = {0};

	switch (driver->type)
	{
	case 2209:
	case 2226:
		tmc_write_register(driver, SGTHRS, (uint32_t)value);
		break;
	case 2130:
		coolconf.sr = tmc_read_register(driver, COOLCONF);
		if (coolconf.sr == TMC_READ_ERROR)
		{
			return;
		}
		coolconf.tmc2130.sgt = value;
		tmc_write_register(driver, COOLCONF, coolconf.tmc2130.sgt);
		break;
	}
}
