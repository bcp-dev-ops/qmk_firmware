bool process_macro_focus_previous_worksheet(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_UP);
        unregister_code(KC_LALT);
    }
    return false;
}
