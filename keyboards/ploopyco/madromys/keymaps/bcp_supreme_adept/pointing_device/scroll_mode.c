static bool is_scroll_mode_active = false;
static float scroll_accumulator_x = 0.0f;
static float scroll_accumulator_y = 0.0f;

void scroll_mode_set(bool enabled) {
    is_scroll_mode_active = enabled;
    if (enabled) {
        scroll_mode_reset_accumulators();
    }
}

bool scroll_mode_get(void) {
    return is_scroll_mode_active;
}

void scroll_mode_reset_accumulators(void) {
    scroll_accumulator_x = 0.0f;
    scroll_accumulator_y = 0.0f;
}

report_mouse_t scroll_mode_process(report_mouse_t mouse_report) {
    scroll_accumulator_x += (float)mouse_report.x * SCROLL_SENSITIVITY;
    scroll_accumulator_y += (float)mouse_report.y * SCROLL_SENSITIVITY;

    int8_t vertical_part = (int8_t)(scroll_accumulator_y * -1.0f);
    int8_t horizontal_part = (int8_t)(scroll_accumulator_x);

    mouse_report.v = vertical_part;
    mouse_report.h = horizontal_part;

    if (mouse_report.v != 0) {
        scroll_accumulator_y -= (float)(mouse_report.v * -1);
    }
    if (mouse_report.h != 0) {
        scroll_accumulator_x -= (float)(mouse_report.h);
    }

    mouse_report.x = 0;
    mouse_report.y = 0;

    return mouse_report;
}
