bool process_macro_lock_deskhop(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        add_mods(MOD_BIT(KC_RCTL));
        add_key(KC_K);
        send_keyboard_report();
        wait_ms(50);
        del_key(KC_K);
        del_mods(MOD_BIT(KC_RCTL));
        send_keyboard_report();
    }
    return false;
}
