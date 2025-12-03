#include "workspace_gesture.h"
#include "config.h"
#include <math.h>

static int fast_h_distance = 0;
static uint32_t fast_h_start_time = 0;
static uint32_t last_fast_h_scroll_time = 0;

void reset_workspace_gesture(void) {
    fast_h_distance = 0;
    fast_h_start_time = 0;
}

report_mouse_t process_workspace_gesture(report_mouse_t mouse_report, uint32_t now) {
    if (abs(mouse_report.x) >= FAST_H_THRESHOLD_LAYER0) {
        if (fast_h_distance == 0) {
            fast_h_start_time = now;
        }
        fast_h_distance += mouse_report.x;
    }

    if ((now - fast_h_start_time <= FAST_H_TIME_WINDOW) &&
        (abs(fast_h_distance) >= FAST_H_DISTANCE_TRIGGER) &&
        (now - last_fast_h_scroll_time > FAST_H_COOLDOWN)) {

        if (fast_h_distance > 0) {
            tap_code16(LGUI(LCTL(KC_RGHT)));
        } else {
            tap_code16(LGUI(LCTL(KC_LEFT)));
        }

        fast_h_distance = 0;
        fast_h_start_time = now;
        last_fast_h_scroll_time = now;
    }

    if (now - fast_h_start_time > FAST_H_TIME_WINDOW) {
        fast_h_distance = 0;
    }

    return mouse_report;
}
