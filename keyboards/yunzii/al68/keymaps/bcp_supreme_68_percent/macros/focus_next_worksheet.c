bool process_macro_focus_next_worksheet(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_DOWN);
        unregister_code(KC_LALT);
    }
    return false;
}
