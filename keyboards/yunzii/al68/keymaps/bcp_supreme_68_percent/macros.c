bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO_FOCUS_WIN_LEFT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_E);
                wait_ms(10);
                unregister_code(KC_LCTL);
                wait_ms(10);
                tap_code(KC_H);
            }
            return false;
        case MACRO_FOCUS_WIN_RIGHT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_E);
                wait_ms(10);
                unregister_code(KC_LCTL);
                wait_ms(10);
                tap_code(KC_L);
            }
            return false;
    }
    return true;
}
