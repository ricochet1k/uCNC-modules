// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 9.1.0
// Project name: uCNC-GFX

#include "ui.h"

void ui_idle_screen_init(void)
{
    ui_idle = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_idle, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_idle, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_idle, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_left(ui_idle, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_idle, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_idle, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_idle, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_idle, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_idle_container_header2 = lv_obj_create(ui_idle);
    lv_obj_remove_style_all(ui_idle_container_header2);
    lv_obj_set_width(ui_idle_container_header2, lv_pct(100));
    lv_obj_set_height(ui_idle_container_header2, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_idle_container_header2, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_idle_container_header2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_idle_container_header2, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_remove_flag(ui_idle_container_header2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_row(ui_idle_container_header2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_idle_container_header2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_idle_button_btnunlock = lv_button_create(ui_idle_container_header2);
    lv_obj_set_height(ui_idle_button_btnunlock, 50);
    lv_obj_set_flex_grow(ui_idle_button_btnunlock, 1);
    lv_obj_set_align(ui_idle_button_btnunlock, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_idle_button_btnunlock, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_idle_button_btnunlock, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    ui_object_set_themeable_style_property(ui_idle_button_btnunlock, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_button);
    ui_object_set_themeable_style_property(ui_idle_button_btnunlock, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_button);
    ui_object_set_themeable_style_property(ui_idle_button_btnunlock, LV_PART_MAIN | LV_STATE_PRESSED, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_buttonpressed);
    ui_object_set_themeable_style_property(ui_idle_button_btnunlock, LV_PART_MAIN | LV_STATE_PRESSED, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_buttonpressed);

    ui_idle_image_image8 = lv_image_create(ui_idle_button_btnunlock);
    lv_image_set_src(ui_idle_image_image8, &ui_img_lock_png);
    lv_obj_set_width(ui_idle_image_image8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_image_image8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_image_image8, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_idle_image_image8, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_remove_flag(ui_idle_image_image8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_idle_image_image17 = lv_image_create(ui_idle_button_btnunlock);
    lv_image_set_src(ui_idle_image_image17, &ui_img_unlocked_png);
    lv_obj_set_width(ui_idle_image_image17, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_image_image17, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_image_image17, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_idle_image_image17, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_remove_flag(ui_idle_image_image17, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_image_set_scale(ui_idle_image_image17, 0);

    ui_idle_container_statusinfo = lv_obj_create(ui_idle_container_header2);
    lv_obj_remove_style_all(ui_idle_container_statusinfo);
    lv_obj_set_height(ui_idle_container_statusinfo, 50);
    lv_obj_set_flex_grow(ui_idle_container_statusinfo, 2);
    lv_obj_set_align(ui_idle_container_statusinfo, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_idle_container_statusinfo, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_idle_container_statusinfo, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_idle_container_statusinfo, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_idle_container_statusinfo, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    ui_object_set_themeable_style_property(ui_idle_container_statusinfo, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_alarm);
    ui_object_set_themeable_style_property(ui_idle_container_statusinfo, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_alarm);
    lv_obj_set_style_pad_left(ui_idle_container_statusinfo, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_idle_container_statusinfo, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_idle_container_statusinfo, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_idle_container_statusinfo, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_idle_container_statusinfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_idle_container_statusinfo, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_idle_label_statuslabel = lv_label_create(ui_idle_container_statusinfo);
    lv_obj_set_width(ui_idle_label_statuslabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_label_statuslabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_label_statuslabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_idle_label_statuslabel, "St:");

    ui_idle_label_statusvalue = lv_label_create(ui_idle_container_statusinfo);
    lv_obj_set_width(ui_idle_label_statusvalue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_label_statusvalue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_label_statusvalue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_idle_label_statusvalue, "Alarm");

    ui_idle_button_btnholdres = lv_button_create(ui_idle_container_header2);
    lv_obj_set_height(ui_idle_button_btnholdres, 50);
    lv_obj_set_flex_grow(ui_idle_button_btnholdres, 1);
    lv_obj_set_align(ui_idle_button_btnholdres, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_idle_button_btnholdres, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_idle_button_btnholdres, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    ui_object_set_themeable_style_property(ui_idle_button_btnholdres, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_button);
    ui_object_set_themeable_style_property(ui_idle_button_btnholdres, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_button);
    ui_object_set_themeable_style_property(ui_idle_button_btnholdres, LV_PART_MAIN | LV_STATE_PRESSED, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_buttonpressed);
    ui_object_set_themeable_style_property(ui_idle_button_btnholdres, LV_PART_MAIN | LV_STATE_PRESSED, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_buttonpressed);

    ui_idle_image_image7 = lv_image_create(ui_idle_button_btnholdres);
    lv_image_set_src(ui_idle_image_image7, &ui_img_pause2_png);
    lv_obj_set_width(ui_idle_image_image7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_image_image7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_image_image7, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_idle_image_image7, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_remove_flag(ui_idle_image_image7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_idle_image_image12 = lv_image_create(ui_idle_button_btnholdres);
    lv_image_set_src(ui_idle_image_image12, &ui_img_play3_png);
    lv_obj_set_width(ui_idle_image_image12, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_image_image12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_image_image12, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_idle_image_image12, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_remove_flag(ui_idle_image_image12, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_image_set_scale(ui_idle_image_image12, 0);

    ui_idle_container_body2 = lv_obj_create(ui_idle);
    lv_obj_remove_style_all(ui_idle_container_body2);
    lv_obj_set_width(ui_idle_container_body2, lv_pct(100));
    lv_obj_set_flex_grow(ui_idle_container_body2, 1);
    lv_obj_set_align(ui_idle_container_body2, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_flex_flow(ui_idle_container_body2, LV_FLEX_FLOW_COLUMN_WRAP);
    lv_obj_set_flex_align(ui_idle_container_body2, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_END);
    lv_obj_remove_flag(ui_idle_container_body2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_idle_container_body2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_idle_container_body2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_idle_container_body2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_idle_container_body2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_idle_container_body2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_idle_container_body2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_idle_container_container7 = lv_obj_create(ui_idle_container_body2);
    lv_obj_remove_style_all(ui_idle_container_container7);
    lv_obj_set_width(ui_idle_container_container7, 460);
    lv_obj_set_flex_grow(ui_idle_container_container7, 1);
    lv_obj_set_align(ui_idle_container_container7, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_idle_container_container7, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_idle_container_container7, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_idle_container_container7, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_row(ui_idle_container_container7, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_idle_container_container7, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_idle_button_btnhome = lv_button_create(ui_idle_container_container7);
    lv_obj_set_height(ui_idle_button_btnhome, 50);
    lv_obj_set_flex_grow(ui_idle_button_btnhome, 1);
    lv_obj_set_align(ui_idle_button_btnhome, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_idle_button_btnhome, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_idle_button_btnhome, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    ui_object_set_themeable_style_property(ui_idle_button_btnhome, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_button);
    ui_object_set_themeable_style_property(ui_idle_button_btnhome, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_button);
    ui_object_set_themeable_style_property(ui_idle_button_btnhome, LV_PART_MAIN | LV_STATE_PRESSED, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_buttonpressed);
    ui_object_set_themeable_style_property(ui_idle_button_btnhome, LV_PART_MAIN | LV_STATE_PRESSED, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_buttonpressed);

    ui_idle_image_image9 = lv_image_create(ui_idle_button_btnhome);
    lv_image_set_src(ui_idle_image_image9, &ui_img_home3_png);
    lv_obj_set_width(ui_idle_image_image9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_image_image9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_image_image9, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_idle_image_image9, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_remove_flag(ui_idle_image_image9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_idle_button_btnjog = lv_button_create(ui_idle_container_container7);
    lv_obj_set_height(ui_idle_button_btnjog, 50);
    lv_obj_set_flex_grow(ui_idle_button_btnjog, 1);
    lv_obj_set_align(ui_idle_button_btnjog, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_idle_button_btnjog, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_idle_button_btnjog, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    ui_object_set_themeable_style_property(ui_idle_button_btnjog, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_button);
    ui_object_set_themeable_style_property(ui_idle_button_btnjog, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_button);
    ui_object_set_themeable_style_property(ui_idle_button_btnjog, LV_PART_MAIN | LV_STATE_PRESSED, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_buttonpressed);
    ui_object_set_themeable_style_property(ui_idle_button_btnjog, LV_PART_MAIN | LV_STATE_PRESSED, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_buttonpressed);

    ui_idle_image_image10 = lv_image_create(ui_idle_button_btnjog);
    lv_image_set_src(ui_idle_image_image10, &ui_img_enlarge_png);
    lv_obj_set_width(ui_idle_image_image10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_image_image10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_image_image10, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_idle_image_image10, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_remove_flag(ui_idle_image_image10, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_idle_button_btnsettings = lv_button_create(ui_idle_container_container7);
    lv_obj_set_height(ui_idle_button_btnsettings, 50);
    lv_obj_set_flex_grow(ui_idle_button_btnsettings, 1);
    lv_obj_set_align(ui_idle_button_btnsettings, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_idle_button_btnsettings, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_idle_button_btnsettings, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    ui_object_set_themeable_style_property(ui_idle_button_btnsettings, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_button);
    ui_object_set_themeable_style_property(ui_idle_button_btnsettings, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_button);
    ui_object_set_themeable_style_property(ui_idle_button_btnsettings, LV_PART_MAIN | LV_STATE_PRESSED, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_buttonpressed);
    ui_object_set_themeable_style_property(ui_idle_button_btnsettings, LV_PART_MAIN | LV_STATE_PRESSED, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_buttonpressed);

    ui_idle_image_image11 = lv_image_create(ui_idle_button_btnsettings);
    lv_image_set_src(ui_idle_image_image11, &ui_img_cog_png);
    lv_obj_set_width(ui_idle_image_image11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_image_image11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_image_image11, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_idle_image_image11, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_remove_flag(ui_idle_image_image11, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_idle_container_container1 = lv_obj_create(ui_idle_container_body2);
    lv_obj_remove_style_all(ui_idle_container_container1);
    lv_obj_set_width(ui_idle_container_container1, lv_pct(100));
    lv_obj_set_height(ui_idle_container_container1, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_idle_container_container1, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_idle_container_container1, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_idle_container_container1, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_START);
    lv_obj_remove_flag(ui_idle_container_container1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_row(ui_idle_container_container1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_idle_container_container1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_idle_container_modalmodesinfo = lv_obj_create(ui_idle_container_container1);
    lv_obj_remove_style_all(ui_idle_container_modalmodesinfo);
    lv_obj_set_height(ui_idle_container_modalmodesinfo, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_flex_grow(ui_idle_container_modalmodesinfo, 1);
    lv_obj_set_align(ui_idle_container_modalmodesinfo, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_idle_container_modalmodesinfo, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_idle_container_modalmodesinfo, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_remove_flag(ui_idle_container_modalmodesinfo, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_idle_container_modalmodesinfo, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_idle_container_modalmodesinfo, lv_color_hex(0x303030), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_idle_container_modalmodesinfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_idle_container_modalmodesinfo, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_idle_container_modalmodesinfo, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_idle_container_modalmodesinfo, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_idle_container_modalmodesinfo, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_idle_container_modalmodesinfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_idle_container_modalmodesinfo, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_idle_label_modalmodeslabel = lv_label_create(ui_idle_container_modalmodesinfo);
    lv_obj_set_width(ui_idle_label_modalmodeslabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_label_modalmodeslabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_label_modalmodeslabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_idle_label_modalmodeslabel, "Modes:");

    ui_idle_label_modalmodesvalue = lv_label_create(ui_idle_container_modalmodesinfo);
    lv_obj_set_width(ui_idle_label_modalmodesvalue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_label_modalmodesvalue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_label_modalmodesvalue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_idle_label_modalmodesvalue, "G1 G54 G17 G20 T1");

    ui_idle_container_container3 = lv_obj_create(ui_idle_container_body2);
    lv_obj_remove_style_all(ui_idle_container_container3);
    lv_obj_set_width(ui_idle_container_container3, lv_pct(100));
    lv_obj_set_height(ui_idle_container_container3, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_x(ui_idle_container_container3, 31);
    lv_obj_set_y(ui_idle_container_container3, 0);
    lv_obj_set_align(ui_idle_container_container3, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_idle_container_container3, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_idle_container_container3, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_START);
    lv_obj_remove_flag(ui_idle_container_container3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_idle_container_container3, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_idle_container_container3, lv_color_hex(0x303030), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_idle_container_container3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_idle_container_container3, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_idle_container_container3, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_idle_container_container3, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_idle_container_container3, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_idle_container_container3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_idle_container_container3, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_idle_label_unitsvalue = lv_label_create(ui_idle_container_container3);
    lv_obj_set_width(ui_idle_label_unitsvalue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_label_unitsvalue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_label_unitsvalue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_idle_label_unitsvalue, "MM");

    ui_idle_container_feedinfo = lv_obj_create(ui_idle_container_container3);
    lv_obj_remove_style_all(ui_idle_container_feedinfo);
    lv_obj_set_height(ui_idle_container_feedinfo, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_flex_grow(ui_idle_container_feedinfo, 1);
    lv_obj_set_align(ui_idle_container_feedinfo, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_idle_container_feedinfo, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_idle_container_feedinfo, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_remove_flag(ui_idle_container_feedinfo, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_row(ui_idle_container_feedinfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_idle_container_feedinfo, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_idle_label_feedlabel = lv_label_create(ui_idle_container_feedinfo);
    lv_obj_set_width(ui_idle_label_feedlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_label_feedlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_label_feedlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_idle_label_feedlabel, "F:");

    ui_idle_label_feedvalue = lv_label_create(ui_idle_container_feedinfo);
    lv_obj_set_width(ui_idle_label_feedvalue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_label_feedvalue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_label_feedvalue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_idle_label_feedvalue, "9999");

    ui_idle_container_toolnumberinfo = lv_obj_create(ui_idle_container_container3);
    lv_obj_remove_style_all(ui_idle_container_toolnumberinfo);
    lv_obj_set_height(ui_idle_container_toolnumberinfo, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_flex_grow(ui_idle_container_toolnumberinfo, 1);
    lv_obj_set_align(ui_idle_container_toolnumberinfo, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_idle_container_toolnumberinfo, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_idle_container_toolnumberinfo, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_remove_flag(ui_idle_container_toolnumberinfo, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_row(ui_idle_container_toolnumberinfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_idle_container_toolnumberinfo, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_idle_label_toolnumberlabel = lv_label_create(ui_idle_container_toolnumberinfo);
    lv_obj_set_width(ui_idle_label_toolnumberlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_label_toolnumberlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_label_toolnumberlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_idle_label_toolnumberlabel, "T:");

    ui_idle_label_toolnumbervalue = lv_label_create(ui_idle_container_toolnumberinfo);
    lv_obj_set_width(ui_idle_label_toolnumbervalue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_label_toolnumbervalue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_label_toolnumbervalue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_idle_label_toolnumbervalue, "9999");

    ui_idle_container_toolspeedinfo = lv_obj_create(ui_idle_container_container3);
    lv_obj_remove_style_all(ui_idle_container_toolspeedinfo);
    lv_obj_set_height(ui_idle_container_toolspeedinfo, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_flex_grow(ui_idle_container_toolspeedinfo, 1);
    lv_obj_set_align(ui_idle_container_toolspeedinfo, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_idle_container_toolspeedinfo, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_idle_container_toolspeedinfo, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_remove_flag(ui_idle_container_toolspeedinfo, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_row(ui_idle_container_toolspeedinfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_idle_container_toolspeedinfo, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_idle_label_toolspeedlabel = lv_label_create(ui_idle_container_toolspeedinfo);
    lv_obj_set_width(ui_idle_label_toolspeedlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_label_toolspeedlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_label_toolspeedlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_idle_label_toolspeedlabel, "S:");

    ui_idle_label_toolspeedvalue = lv_label_create(ui_idle_container_toolspeedinfo);
    lv_obj_set_width(ui_idle_label_toolspeedvalue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_label_toolspeedvalue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_label_toolspeedvalue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_idle_label_toolspeedvalue, "9999");

    ui_idle_container_switchinfo = lv_obj_create(ui_idle_container_container3);
    lv_obj_remove_style_all(ui_idle_container_switchinfo);
    lv_obj_set_height(ui_idle_container_switchinfo, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_flex_grow(ui_idle_container_switchinfo, 2);
    lv_obj_set_align(ui_idle_container_switchinfo, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_idle_container_switchinfo, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_idle_container_switchinfo, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_remove_flag(ui_idle_container_switchinfo, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_row(ui_idle_container_switchinfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_idle_container_switchinfo, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_idle_label_switchlabel = lv_label_create(ui_idle_container_switchinfo);
    lv_obj_set_width(ui_idle_label_switchlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_label_switchlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_label_switchlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_idle_label_switchlabel, "Sw:");

    ui_idle_label_switchvalue = lv_label_create(ui_idle_container_switchinfo);
    lv_obj_set_width(ui_idle_label_switchvalue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_label_switchvalue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_label_switchvalue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_idle_label_switchvalue, "XYZABCPHE");

    ui_idle_container_container8 = lv_obj_create(ui_idle_container_body2);
    lv_obj_remove_style_all(ui_idle_container_container8);
    lv_obj_set_width(ui_idle_container_container8, lv_pct(100));
    lv_obj_set_height(ui_idle_container_container8, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_idle_container_container8, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_idle_container_container8, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_idle_container_container8, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_idle_container_container8, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_idle_axisinfo_axisinfox = ui_container_axisinfo_create(ui_idle_container_container8);
    lv_obj_set_x(ui_idle_axisinfo_axisinfox, 0);
    lv_obj_set_y(ui_idle_axisinfo_axisinfox, 0);

    lv_label_set_text(ui_comp_get_child(ui_idle_axisinfo_axisinfox, UI_COMP_CONTAINER_AXISINFO_LABEL_AXISLABEL), "X:");

    lv_label_set_text(ui_comp_get_child(ui_idle_axisinfo_axisinfox, UI_COMP_CONTAINER_AXISINFO_LABEL_AXISVALUE),
                      "9999.999");

    ui_idle_axisinfo_axisinfoy = ui_container_axisinfo_create(ui_idle_container_container8);
    lv_obj_set_x(ui_idle_axisinfo_axisinfoy, 0);
    lv_obj_set_y(ui_idle_axisinfo_axisinfoy, 0);

    lv_label_set_text(ui_comp_get_child(ui_idle_axisinfo_axisinfoy, UI_COMP_CONTAINER_AXISINFO_LABEL_AXISLABEL), "Y:");

    lv_label_set_text(ui_comp_get_child(ui_idle_axisinfo_axisinfoy, UI_COMP_CONTAINER_AXISINFO_LABEL_AXISVALUE),
                      "9999.999");

    ui_idle_axisinfo_axisinfoz = ui_container_axisinfo_create(ui_idle_container_container8);
    lv_obj_set_x(ui_idle_axisinfo_axisinfoz, 0);
    lv_obj_set_y(ui_idle_axisinfo_axisinfoz, 0);

    lv_label_set_text(ui_comp_get_child(ui_idle_axisinfo_axisinfoz, UI_COMP_CONTAINER_AXISINFO_LABEL_AXISLABEL), "Z:");

    lv_label_set_text(ui_comp_get_child(ui_idle_axisinfo_axisinfoz, UI_COMP_CONTAINER_AXISINFO_LABEL_AXISVALUE),
                      "9999.999");

    ui_idle_container_container9 = lv_obj_create(ui_idle_container_body2);
    lv_obj_remove_style_all(ui_idle_container_container9);
    lv_obj_set_width(ui_idle_container_container9, lv_pct(100));
    lv_obj_set_height(ui_idle_container_container9, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_idle_container_container9, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_idle_container_container9, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_idle_container_container9, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_idle_container_container9, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_idle_axisinfo_axisinfoa = ui_container_axisinfo_create(ui_idle_container_container9);
    lv_obj_set_x(ui_idle_axisinfo_axisinfoa, 0);
    lv_obj_set_y(ui_idle_axisinfo_axisinfoa, 0);

    lv_label_set_text(ui_comp_get_child(ui_idle_axisinfo_axisinfoa, UI_COMP_CONTAINER_AXISINFO_LABEL_AXISLABEL), "A:");

    ui_idle_axisinfo_axisinfob = ui_container_axisinfo_create(ui_idle_container_container9);
    lv_obj_set_x(ui_idle_axisinfo_axisinfob, 0);
    lv_obj_set_y(ui_idle_axisinfo_axisinfob, 0);

    lv_label_set_text(ui_comp_get_child(ui_idle_axisinfo_axisinfob, UI_COMP_CONTAINER_AXISINFO_LABEL_AXISLABEL), "B:");

    ui_idle_axisinfo_axisinfoc = ui_container_axisinfo_create(ui_idle_container_container9);
    lv_obj_set_x(ui_idle_axisinfo_axisinfoc, 0);
    lv_obj_set_y(ui_idle_axisinfo_axisinfoc, 0);

    lv_label_set_text(ui_comp_get_child(ui_idle_axisinfo_axisinfoc, UI_COMP_CONTAINER_AXISINFO_LABEL_AXISLABEL), "C:");

    ui_idle_container_footer2 = lv_obj_create(ui_idle);
    lv_obj_remove_style_all(ui_idle_container_footer2);
    lv_obj_set_width(ui_idle_container_footer2, lv_pct(100));
    lv_obj_set_height(ui_idle_container_footer2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_container_footer2, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_idle_container_footer2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_idle_container_footer2, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_START);
    lv_obj_add_flag(ui_idle_container_footer2, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_remove_flag(ui_idle_container_footer2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_idle_container_footer2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_idle_container_footer2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_idle_container_footer2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_idle_container_footer2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_idle_container_footer2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_idle_container_footer2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_idle_button_btnprev2 = lv_button_create(ui_idle_container_footer2);
    lv_obj_set_height(ui_idle_button_btnprev2, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_flex_grow(ui_idle_button_btnprev2, 1);
    lv_obj_set_align(ui_idle_button_btnprev2, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_idle_button_btnprev2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_idle_button_btnprev2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_idle_label_btnprevlabel2 = lv_label_create(ui_idle_button_btnprev2);
    lv_obj_set_width(ui_idle_label_btnprevlabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_label_btnprevlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_label_btnprevlabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_idle_label_btnprevlabel2, "Back/Down");

    ui_idle_button_btnnext2 = lv_button_create(ui_idle_container_footer2);
    lv_obj_set_height(ui_idle_button_btnnext2, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_flex_grow(ui_idle_button_btnnext2, 1);
    lv_obj_set_align(ui_idle_button_btnnext2, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_idle_button_btnnext2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_idle_button_btnnext2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_idle_label_btnnextlabel2 = lv_label_create(ui_idle_button_btnnext2);
    lv_obj_set_width(ui_idle_label_btnnextlabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_label_btnnextlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_label_btnnextlabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_idle_label_btnnextlabel2, "Next/Up");

    ui_idle_button_btnenter2 = lv_button_create(ui_idle_container_footer2);
    lv_obj_set_height(ui_idle_button_btnenter2, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_flex_grow(ui_idle_button_btnenter2, 1);
    lv_obj_set_align(ui_idle_button_btnenter2, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_idle_button_btnenter2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_idle_button_btnenter2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_idle_label_btnenterlabel2 = lv_label_create(ui_idle_button_btnenter2);
    lv_obj_set_width(ui_idle_label_btnenterlabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_idle_label_btnenterlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_idle_label_btnenterlabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_idle_label_btnenterlabel2, "Enter/Set");

    lv_obj_add_event_cb(ui_idle_button_btnunlock, ui_event_idle_button_btnunlock, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_idle_button_btnholdres, ui_event_idle_button_btnholdres, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_idle_button_btnhome, ui_event_idle_button_btnhome, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_idle_button_btnjog, ui_event_idle_button_btnjog, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_idle_button_btnsettings, ui_event_idle_button_btnsettings, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_idle_button_btnprev2, ui_event_idle_button_btnprev2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_idle_button_btnnext2, ui_event_idle_button_btnnext2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_idle_button_btnenter2, ui_event_idle_button_btnenter2, LV_EVENT_ALL, NULL);

}
