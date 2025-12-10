void navigation_rgb_indicators(void) {
    uint8_t brightness = rgb_matrix_get_val();
    uint8_t soft_purple_r = (brightness * 180) / 255;
    uint8_t soft_purple_g = (brightness * 100) / 255;
    uint8_t soft_purple_b = brightness;

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t column = 0; column < MATRIX_COLS; column++) {
            uint8_t index = g_led_config.matrix_co[row][column];

            if (index != NO_LED) {
                uint16_t keycode = keymap_key_to_keycode(L_NAVIGATION, (keypos_t){.col = column, .row = row});

                if (keycode != KC_TRNS && keycode != KC_NO) {
                    if (keycode >= KC_F1 && keycode <= KC_F12) {
                        rgb_matrix_set_color(index, brightness, 0, 0);
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
