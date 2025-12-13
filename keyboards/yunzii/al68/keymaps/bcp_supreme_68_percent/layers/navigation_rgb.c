void navigation_rgb_indicators(void) {
    uint8_t brightness = rgb_matrix_get_val();
    uint8_t soft_purple_r = (brightness * 180) / 255;
    uint8_t soft_purple_g = (brightness * 100) / 255;
    uint8_t soft_purple_b = (brightness * 128) / 255;

    uint8_t turquoise_r = 0;
    uint8_t turquoise_g = (brightness * 112) / 255;
    uint8_t turquoise_b = (brightness * 104) / 255;

    uint8_t blue_r = 0;
    uint8_t blue_g = 0;
    uint8_t blue_b = (brightness * 128) / 255;

    uint8_t red_r = (brightness * 128) / 255;
    uint8_t red_g = 0;
    uint8_t red_b = 0;

    uint8_t green_r = 0;
    uint8_t green_g = (brightness * 128) / 255;
    uint8_t green_b = 0;

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t column = 0; column < MATRIX_COLS; column++) {
            uint8_t index = g_led_config.matrix_co[row][column];

            if (index != NO_LED) {
                uint16_t keycode = keymap_key_to_keycode(L_NAVIGATION, (keypos_t){.col = column, .row = row});

                if (keycode != KC_TRNS && keycode != KC_NO) {
                    if (keycode == KC_ESC || keycode == KC_TAB || keycode == KC_LSFT || keycode == KC_RSFT ||
                        keycode == KC_LCTL || keycode == KC_LALT || keycode == KC_LGUI ||
                        keycode == KC_ENT || keycode == KC_SPC || keycode == KC_BSPC) {
                        rgb_matrix_set_color(index, 0, 0, 0);
                    } else if (keycode >= KC_F1 && keycode <= KC_F12) {
                        rgb_matrix_set_color(index, red_r, red_g, red_b);
                    } else if (keycode == KC_LEFT || keycode == KC_RIGHT || keycode == KC_UP || keycode == KC_DOWN) {
                        rgb_matrix_set_color(index, green_r, green_g, green_b);
                    } else if (keycode == MACRO_FOCUS_TAB_LEFT || keycode == MACRO_FOCUS_TAB_RIGHT ||
                               keycode == MACRO_FOCUS_WINDOW_LEFT || keycode == MACRO_FOCUS_WINDOW_RIGHT ||
                               keycode == MACRO_FOCUS_PREVIOUS_WORKSHEET || keycode == MACRO_FOCUS_NEXT_WORKSHEET ||
                               keycode == KC_LEFT_BRACKET || keycode == KC_RIGHT_BRACKET) {
                        rgb_matrix_set_color(index, turquoise_r, turquoise_g, turquoise_b);
                    } else if (keycode == MACRO_GO_BACK || keycode == MACRO_GO_FORWARD) {
                        rgb_matrix_set_color(index, blue_r, blue_g, blue_b);
                    } else if (keycode == MS_BTN1 || keycode == MS_BTN2 || keycode == KC_GRV) {
                        rgb_matrix_set_color(index, soft_purple_r, soft_purple_g, soft_purple_b);
                    } else {
                        rgb_matrix_set_color(index, soft_purple_r, soft_purple_g, soft_purple_b);
                    }
                } else {
                    rgb_matrix_set_color(index, 0, 0, 0);
                }
            }
        }
    }
}
