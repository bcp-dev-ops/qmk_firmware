void alpha_qwerty_rgb_indicators(void) {
    uint8_t brightness = rgb_matrix_get_val();

    RGB warm_amber_rgb = hsv_to_rgb((HSV){RGB_MATRIX_DEFAULT_HUE, RGB_MATRIX_DEFAULT_SAT, brightness});
    uint8_t amber_r = warm_amber_rgb.r;
    uint8_t amber_g = warm_amber_rgb.g;
    uint8_t amber_b = warm_amber_rgb.b;

    uint8_t red_r = brightness;
    uint8_t red_g = 0;
    uint8_t red_b = 0;

    uint8_t green_r = 0;
    uint8_t green_g = brightness;
    uint8_t green_b = 0;

    uint8_t blue_r = 0;
    uint8_t blue_g = 0;
    uint8_t blue_b = (brightness * 128) / 255;

    uint8_t soft_purple_r = (brightness * 180) / 255;
    uint8_t soft_purple_g = (brightness * 100) / 255;
    uint8_t soft_purple_b = brightness;

    uint8_t navy_blue_r = 0;
    uint8_t navy_blue_g = 0;
    uint8_t navy_blue_b = (brightness * 128) / 255;

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t column = 0; column < MATRIX_COLS; column++) {
            uint8_t index = g_led_config.matrix_co[row][column];

            if (index != NO_LED) {
                uint16_t keycode = keymap_key_to_keycode(L_ALPHA_QWERTY, (keypos_t){column, row});

                if (keycode >= KC_A && keycode <= KC_Z) {
                    rgb_matrix_set_color(index, amber_r, amber_g, amber_b);
                } else if (keycode >= KC_1 && keycode <= KC_0) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        rgb_matrix_set_color(index, green_r, green_g, green_b);
                    } else {
                        rgb_matrix_set_color(index, amber_r, amber_g, amber_b);
                    }
                } else if (keycode == KC_LEFT_SHIFT || keycode == KC_RIGHT_SHIFT) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        rgb_matrix_set_color(index, navy_blue_r, navy_blue_g, navy_blue_b);
                    } else {
                        rgb_matrix_set_color(index, 0, 0, 0);
                    }
                } else if (keycode == KC_PAGE_UP || keycode == KC_PAGE_DOWN) {
                    rgb_matrix_set_color(index, 0, 0, 0);
                } else if (keycode == KC_UP || keycode == KC_DOWN ||
                           keycode == KC_LEFT || keycode == KC_RIGHT) {
                    rgb_matrix_set_color(index, 0, 0, 0);
                } else if (keycode == KC_BACKSPACE || keycode == KC_ESCAPE) {
                    rgb_matrix_set_color(index, red_r, red_g, red_b);
                } else if (keycode == KC_ENTER) {
                    rgb_matrix_set_color(index, green_r, green_g, green_b);
                } else if (keycode == KC_LEFT_CTRL || keycode == KC_RIGHT_CTRL) {
                    if (get_mods() & MOD_MASK_CTRL) {
                        rgb_matrix_set_color(index, green_r, green_g, green_b);
                    } else {
                        rgb_matrix_set_color(index, 0, 0, 0);
                    }
                } else if (keycode == KC_LEFT_ALT || keycode == KC_RIGHT_ALT) {
                    if (get_mods() & MOD_MASK_ALT) {
                        rgb_matrix_set_color(index, blue_r, blue_g, blue_b);
                    } else {
                        rgb_matrix_set_color(index, 0, 0, 0);
                    }
                } else if (keycode == KC_LEFT_GUI || keycode == KC_RIGHT_GUI) {
                    if (get_mods() & MOD_MASK_GUI) {
                        rgb_matrix_set_color(index, red_r, red_g, red_b);
                    } else {
                        rgb_matrix_set_color(index, 0, 0, 0);
                    }
                } else if (keycode == MO(L_NAVIGATION)) {
                    rgb_matrix_set_color(index, soft_purple_r, soft_purple_g, soft_purple_b);
                } else if (keycode == LT(L_NAVIGATION, KC_TAB) || keycode == QK_BOOT) {
                    rgb_matrix_set_color(index, 0, 0, 0);
                } else if (keycode == KC_SPACE) {
                    rgb_matrix_set_color(index, soft_purple_r, soft_purple_g, soft_purple_b);
                }
            }
        }
    }
}

