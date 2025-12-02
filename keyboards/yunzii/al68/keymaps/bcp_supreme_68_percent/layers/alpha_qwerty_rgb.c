void alpha_qwerty_rgb_indicators(void) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t column = 0; column < MATRIX_COLS; column++) {
            uint8_t index = g_led_config.matrix_co[row][column];

            if (index != NO_LED) {
                uint16_t keycode = keymap_key_to_keycode(ALPHA_QWERTY, (keypos_t){column, row});

                if (keycode >= KC_A && keycode <= KC_Z) {
                    rgb_matrix_set_color(index, 0, 0, 255);
                }
            }
        }
    }
}

