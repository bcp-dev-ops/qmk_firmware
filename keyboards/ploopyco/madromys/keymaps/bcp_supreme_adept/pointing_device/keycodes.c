static uint16_t zoom_timer = 0;

bool process_pointing_device_keycodes(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DESKTOP_NAVIGATION:
            navigation_mode_set(record->event.pressed);
            return false;

        case ZOOM_BUTTON_3:
            if (record->event.pressed) {
                zoom_mode_set(true);
                zoom_timer = timer_read();
                register_code(KC_LCTL);
                register_code(KC_LSFT);
            } else {
                zoom_mode_set(false);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                if (timer_elapsed(zoom_timer) < TAPPING_TERM) {
                    tap_code(QK_MOUSE_BUTTON_3);
                }
            }
            return false;

        default:
            return true;
    }
}
