bool process_macro_enable_deskhop_game_mode(uint16_t keycode, keyrecord_t *record) {
    // DeskHop needs all keys in the same HID report
    if (record->event.pressed) {
        dh_game_active = !dh_game_active;
        add_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_RSFT));
        add_key(KC_G);
        send_keyboard_report();
        wait_ms(50);
        del_key(KC_G);
        del_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_RSFT));
        send_keyboard_report();
    }

    return false;
}

