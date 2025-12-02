void navigation_rgb_indicators(void) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t column = 0; column < MATRIX_COLS; column++) {
            uint8_t index = g_led_config.matrix_co[row][column];

            if (index != NO_LED) {
                rgb_matrix_set_color(index, 255, 165, 0);
            }
        }
    }
}
