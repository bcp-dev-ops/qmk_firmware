#include "tab_mode.h"
#include "trackball_state.h"

static uint32_t last_tab_time = 0;

void reset_tab_mode(void) {
    last_tab_time = 0;
}

report_mouse_t process_tab_mode(report_mouse_t mouse_report, uint32_t now) {
    if (now - last_tab_time > 200) {
        if (mouse_report.y >= 2) {
            tap_code16(LCTL(KC_PGDN));
            reset_trackball_state();
            last_tab_time = now;
            mouse_report.y = 0;
        } else if (mouse_report.y <= -2) {
            tap_code16(LCTL(KC_PGUP));
            reset_trackball_state();
            last_tab_time = now;
            mouse_report.y = 0;
        }
    }
    return mouse_report;
}
