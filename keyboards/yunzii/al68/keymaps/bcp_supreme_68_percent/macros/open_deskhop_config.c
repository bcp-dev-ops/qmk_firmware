bool process_macro_open_deskhop_config(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        add_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_RSFT));
        add_key(KC_C);
        add_key(KC_O);
        send_keyboard_report();
        wait_ms(50);
        del_key(KC_O);
        del_key(KC_C);
        del_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_RSFT));
        send_keyboard_report();
    }
    return false;
}
