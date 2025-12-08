#define MEDIA_THRESHOLD 150

report_mouse_t media_mode_process(report_mouse_t mouse_report, int16_t *media_accumulator_x, int16_t *media_accumulator_y) {
    *media_accumulator_x += mouse_report.x;
    *media_accumulator_y += mouse_report.y;

    if (*media_accumulator_y > MEDIA_THRESHOLD) {
        tap_code(KC_VOLD);
        *media_accumulator_y = 0;
    } else if (*media_accumulator_y < -MEDIA_THRESHOLD) {
        tap_code(KC_VOLU);
        *media_accumulator_y = 0;
    }

    if (*media_accumulator_x > MEDIA_THRESHOLD) {
        tap_code(KC_BRIU);
        *media_accumulator_x = 0;
    } else if (*media_accumulator_x < -MEDIA_THRESHOLD) {
        tap_code(KC_BRID);
        *media_accumulator_x = 0;
    }

    mouse_report.x = 0;
    mouse_report.y = 0;
    mouse_report.v = 0;
    mouse_report.h = 0;

    return mouse_report;
}
