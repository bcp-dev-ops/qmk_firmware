void alpha_qwerty_rgb_indicators(void) {
    uint8_t brightness = rgb_matrix_get_val();
    uint8_t soft_blue_r = (brightness * 100) / 255;
    uint8_t soft_blue_g = (brightness * 150) / 255;
    uint8_t soft_blue_b = brightness;

    uint8_t red_r = brightness;
    uint8_t red_g = 0;
    uint8_t red_b = 0;

    uint8_t green_r = 0;
    uint8_t green_g = brightness;
    uint8_t green_b = 0;

    uint8_t blue_r = 0;
    uint8_t blue_g = 0;
    uint8_t blue_b = brightness;

    uint8_t soft_purple_r = (brightness * 180) / 255;
    uint8_t soft_purple_g = (brightness * 100) / 255;
    uint8_t soft_purple_b = brightness;

    uint8_t navy_blue_r = 0;
    uint8_t navy_blue_g = 0;
    uint8_t navy_blue_b = (brightness * 128) / 255;

    uint8_t yellow_r = brightness;
    uint8_t yellow_g = brightness;
    uint8_t yellow_b = 0;

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t column = 0; column < MATRIX_COLS; column++) {
            uint8_t index = g_led_config.matrix_co[row][column];

            if (index != NO_LED) {
                uint16_t keycode = keymap_key_to_keycode(L_ALPHA_QWERTY, (keypos_t){column, row});

                if (keycode >= KC_A && keycode <= KC_Z) {
                    rgb_matrix_set_color(index, soft_blue_r, soft_blue_g, soft_blue_b);
                } else if (keycode >= KC_1 && keycode <= KC_0) {
                    rgb_matrix_set_color(index, green_r, green_g, green_b);
                } else if (keycode == KC_LEFT_BRACKET || keycode == KC_RIGHT_BRACKET ||
                           keycode == KC_SEMICOLON || keycode == KC_QUOTE ||
                           keycode == KC_COMMA || keycode == KC_DOT ||
                           keycode == KC_SLASH || keycode == KC_BACKSLASH ||
                           keycode == KC_LEFT_SHIFT || keycode == KC_RIGHT_SHIFT) {
                    rgb_matrix_set_color(index, navy_blue_r, navy_blue_g, navy_blue_b);
                } else if (keycode == KC_PAGE_UP || keycode == KC_PAGE_DOWN) {
                    rgb_matrix_set_color(index, yellow_r, yellow_g, yellow_b);
                } else if (keycode == KC_UP || keycode == KC_DOWN ||
                           keycode == KC_LEFT || keycode == KC_RIGHT) {
                    rgb_matrix_set_color(index, green_r, green_g, green_b);
                } else if (keycode == KC_BACKSPACE || keycode == KC_ESCAPE) {
                    rgb_matrix_set_color(index, red_r, red_g, red_b);
                } else if (keycode == KC_ENTER) {
                    rgb_matrix_set_color(index, green_r, green_g, green_b);
                } else if (keycode == KC_LEFT_CTRL || keycode == KC_RIGHT_CTRL) {
                    rgb_matrix_set_color(index, green_r, green_g, green_b);
                } else if (keycode == KC_LEFT_ALT || keycode == KC_RIGHT_ALT) {
                    rgb_matrix_set_color(index, blue_r, blue_g, blue_b);
                } else if (keycode == KC_LEFT_GUI || keycode == KC_RIGHT_GUI) {
                    rgb_matrix_set_color(index, red_r, red_g, red_b);
                } else if (keycode == MO(L_NAVIGATION)) {
                    rgb_matrix_set_color(index, soft_purple_r, soft_purple_g, soft_purple_b);
                } else if (keycode == KC_TAB || keycode == KC_SPACE) {
                    rgb_matrix_set_color(index, soft_purple_r, soft_purple_g, soft_purple_b);
                }
            }
        }
    }
}

