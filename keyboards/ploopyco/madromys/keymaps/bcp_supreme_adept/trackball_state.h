#pragma once

#include <stdint.h>

typedef struct {
    int volume_accumulator;
    float scroll_accumulated_h;
    float scroll_accumulated_v;
} trackball_state_t;

extern trackball_state_t tb_state;

void reset_trackball_state(void);

static inline int clamp(int value, int minimum, int maximum) {
    return (value < minimum) ? minimum : (value > maximum) ? maximum : value;
}
