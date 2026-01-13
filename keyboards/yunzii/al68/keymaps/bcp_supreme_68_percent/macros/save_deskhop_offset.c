bool process_macro_save_deskhop_offset(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        add_mods(MOD_BIT(KC_RSFT));
        add_key(KC_F12);
        add_key(KC_Y);
        send_keyboard_report();
        wait_ms(50);
        del_key(KC_Y);
        del_key(KC_F12);
        del_mods(MOD_BIT(KC_RSFT));
        send_keyboard_report();
    }
    return false;
}
