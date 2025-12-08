static bool is_navigation_mode = false;
static uint16_t last_navigation_time = 0;
static int16_t navigation_accumulator_x = 0;
static int16_t navigation_accumulator_y = 0;

void navigation_mode_set(bool enabled) {
    is_navigation_mode = enabled;
    if (enabled) {
        navigation_mode_reset_accumulators();
    }
}

bool navigation_mode_get(void) {
    return is_navigation_mode;
}

void navigation_mode_reset_accumulators(void) {
    navigation_accumulator_x = 0;
    navigation_accumulator_y = 0;
}

report_mouse_t navigation_mode_process(report_mouse_t mouse_report) {
    navigation_accumulator_x += mouse_report.x;
    navigation_accumulator_y += mouse_report.y;

    if (timer_elapsed(last_navigation_time) > NAV_COOLDOWN) {
        if (navigation_accumulator_x > NAV_THRESHOLD) {
            tap_code16(LCTL(LGUI(KC_RIGHT)));
            last_navigation_time = timer_read();
            navigation_mode_reset_accumulators();
        } else if (navigation_accumulator_x < -NAV_THRESHOLD) {
            tap_code16(LCTL(LGUI(KC_LEFT)));
            last_navigation_time = timer_read();
            navigation_mode_reset_accumulators();
        } else if (navigation_accumulator_y > NAV_THRESHOLD) {
            tap_code16(LCTL(LGUI(KC_DOWN)));
            last_navigation_time = timer_read();
            navigation_mode_reset_accumulators();
        } else if (navigation_accumulator_y < -NAV_THRESHOLD) {
            tap_code16(LCTL(LGUI(KC_UP)));
            last_navigation_time = timer_read();
            navigation_mode_reset_accumulators();
        }
    }

    mouse_report.x = 0;
    mouse_report.y = 0;

    return mouse_report;
}
