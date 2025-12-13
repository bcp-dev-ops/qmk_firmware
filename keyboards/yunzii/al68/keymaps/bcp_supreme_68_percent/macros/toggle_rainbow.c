bool rainbow_enabled = false;

bool process_macro_toggle_rainbow(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        rainbow_enabled = !rainbow_enabled;

        if (rainbow_enabled) {
            rgb_matrix_mode(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
        } else {
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
        }
    }
    return false;
}
