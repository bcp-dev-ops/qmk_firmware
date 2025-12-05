bool process_macro_undo(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(KC_LGUI);
        tap_code(KC_Z);
        unregister_code(KC_LGUI);
    }
    return false;
}

