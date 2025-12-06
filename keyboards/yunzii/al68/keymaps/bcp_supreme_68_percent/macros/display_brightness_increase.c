bool process_macro_display_brightness_increase(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        tap_code(KC_BRIGHTNESS_UP);
    }
    return false;
}
