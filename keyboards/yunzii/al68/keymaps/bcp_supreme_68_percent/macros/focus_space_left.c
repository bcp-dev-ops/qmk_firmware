bool process_macro_focus_space_left(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(KC_LCTL);
        tap_code(KC_E);
        unregister_code(KC_LCTL);
        wait_ms(10);
        tap_code(KC_P);
    }
    return false;
}


