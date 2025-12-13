typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} color_t;

static color_t scale_color(uint8_t r, uint8_t g, uint8_t b, uint8_t brightness) {
    return (color_t){
        .r = (r * brightness) / 255,
        .g = (g * brightness) / 255,
        .b = (b * brightness) / 255
    };
}

static color_t get_key_color(uint16_t keycode, uint8_t active_mods, color_t amber, color_t red, color_t green, color_t blue, color_t navy_blue, color_t soft_purple, color_t off) {
    if (keycode >= KC_A && keycode <= KC_Z) {
        return amber;
    }

    if (keycode >= KC_1 && keycode <= KC_0) {
        return (active_mods & MOD_MASK_SHIFT) ? green : amber;
    }

    if (keycode == KC_LEFT_SHIFT || keycode == KC_RIGHT_SHIFT) {
        return (active_mods & MOD_MASK_SHIFT) ? navy_blue : off;
    }

    if (keycode == KC_LEFT_CTRL || keycode == KC_RIGHT_CTRL) {
        return (active_mods & MOD_MASK_CTRL) ? green : off;
    }

    if (keycode == KC_LEFT_ALT || keycode == KC_RIGHT_ALT) {
        return (active_mods & MOD_MASK_ALT) ? blue : off;
    }

    if (keycode == KC_LEFT_GUI || keycode == KC_RIGHT_GUI) {
        return (active_mods & MOD_MASK_GUI) ? red : off;
    }

    if (keycode == KC_BACKSPACE || keycode == KC_ESCAPE) {
        return red;
    }

    if (keycode == KC_ENTER) {
        return green;
    }

    if (keycode == MO(L_NAVIGATION) || keycode == KC_SPACE) {
        return soft_purple;
    }

    if (keycode == KC_PAGE_UP || keycode == KC_PAGE_DOWN ||
        keycode == KC_UP || keycode == KC_DOWN ||
        keycode == KC_LEFT || keycode == KC_RIGHT ||
        keycode == LT(L_NAVIGATION, KC_TAB) || keycode == QK_BOOT) {
        return off;
    }

    return off;
}

void alpha_qwerty_rgb_indicators(void) {
    uint8_t brightness = rgb_matrix_get_val();
    uint8_t active_mods = get_mods();

    RGB warm_amber_rgb = hsv_to_rgb((HSV){RGB_MATRIX_DEFAULT_HUE, RGB_MATRIX_DEFAULT_SAT, brightness});
    color_t amber = {warm_amber_rgb.r, warm_amber_rgb.g, warm_amber_rgb.b};
    color_t red = scale_color(255, 0, 0, brightness);
    color_t green = scale_color(0, 255, 0, brightness);
    color_t blue = scale_color(0, 0, 128, brightness);
    color_t navy_blue = scale_color(0, 0, 128, brightness);
    color_t soft_purple = scale_color(180, 100, 255, brightness);
    color_t off = {0, 0, 0};

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t column = 0; column < MATRIX_COLS; column++) {
            uint8_t index = g_led_config.matrix_co[row][column];

            if (index != NO_LED) {
                uint16_t keycode = keymap_key_to_keycode(L_ALPHA_QWERTY, (keypos_t){column, row});
                color_t color = get_key_color(keycode, active_mods, amber, red, green, blue, navy_blue, soft_purple, off);
                rgb_matrix_set_color(index, color.r, color.g, color.b);
            }
        }
    }
}

