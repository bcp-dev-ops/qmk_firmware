int16_t media_accumulator_x = 0;
int16_t media_accumulator_y = 0;

void media_control_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (!state->pressed) {
            tap_code(QK_MOUSE_BUTTON_4);
        } else {
            layer_on(L_MEDIA);
            media_accumulator_x = 0;
            media_accumulator_y = 0;
        }
    } else if (state->count == 2) {
        if (!state->pressed) {
            layer_on(L_PLAYBACK);
        }
    }
}

void media_control_reset(tap_dance_state_t *state, void *user_data) {
    if (IS_LAYER_ON(L_MEDIA)) {
        layer_off(L_MEDIA);
    }
}
