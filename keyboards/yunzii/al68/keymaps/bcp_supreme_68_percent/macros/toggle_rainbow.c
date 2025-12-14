static uint8_t effect_index = 0;

static const uint8_t effects[] = {
    RGB_MATRIX_SOLID_COLOR,
    RGB_MATRIX_RAINBOW_MOVING_CHEVRON,
    RGB_MATRIX_SOLID_MULTISPLASH,
    RGB_MATRIX_MULTISPLASH,
    RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE,
};

bool process_macro_toggle_rainbow(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        effect_index = (effect_index + 1) % (sizeof(effects) / sizeof(effects[0]));
        rgb_matrix_mode(effects[effect_index]);
    }
    return false;
}
