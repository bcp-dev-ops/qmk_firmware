void alpha_strdy_rgb_indicators(void) {
    uint8_t led_min = 0;
    uint8_t led_max = RGB_MATRIX_LED_COUNT;

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t column = 0; column < MATRIX_COLS; column++) {
            uint8_t index = g_led_config.matrix_co[row][column];

            if (index >= led_min && index < led_max && index != NO_LED) {
                uint16_t keycode = keymap_key_to_keycode(ALPHA_STRDY, (keypos_t){column, row});

                if (keycode >= KC_A && keycode <= KC_Z) {
                    rgb_matrix_set_color(index, 0, 255, 255);
                }
            }
        }
    }
}
