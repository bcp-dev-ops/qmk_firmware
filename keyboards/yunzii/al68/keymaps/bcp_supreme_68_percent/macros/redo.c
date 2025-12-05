bool process_macro_redo(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        tap_code(KC_Z);
        unregister_code(KC_LGUI);
        unregister_code(KC_LSFT);
    }
    return false;
}

