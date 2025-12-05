bool process_macro_duplicate(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(KC_LGUI);
        tap_code(KC_D);
        unregister_code(KC_LGUI);
    }
    return false;
}

