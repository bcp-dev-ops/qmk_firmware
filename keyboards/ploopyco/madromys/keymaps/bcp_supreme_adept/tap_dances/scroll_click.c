void scroll_click_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (!state->pressed) {
            tap_code(QK_MOUSE_BUTTON_3);
        } else {
            scroll_mode_set(true);
        }
    } else if (state->count == 2) {
        tap_code(KC_HOME);
    } else if (state->count == 3) {
        tap_code(KC_END);
    }
}

void scroll_click_reset(tap_dance_state_t *state, void *user_data) {
    scroll_mode_set(false);
}
