#pragma once

enum tap_dance_indices {
    TD_SCROLL_CLICK = 0,
    TD_MEDIA_CONTROL,
};

extern bool is_scroll_mode;
extern int16_t media_accumulator_x;
extern int16_t media_accumulator_y;

void scroll_click_finished(tap_dance_state_t *state, void *user_data);
void scroll_click_reset(tap_dance_state_t *state, void *user_data);
void media_control_finished(tap_dance_state_t *state, void *user_data);
void media_control_reset(tap_dance_state_t *state, void *user_data);
