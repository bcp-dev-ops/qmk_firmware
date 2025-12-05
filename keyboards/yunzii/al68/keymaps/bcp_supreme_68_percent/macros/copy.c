bool process_macro_copy(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(KC_LGUI);
        tap_code(KC_C);
        unregister_code(KC_LGUI);
    }
    return false;
}


