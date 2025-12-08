static bool is_zoom_mode_active = false;

void zoom_mode_set(bool enabled) {
    is_zoom_mode_active = enabled;
}

bool zoom_mode_get(void) {
    return is_zoom_mode_active;
}

report_mouse_t zoom_mode_process(report_mouse_t mouse_report) {
    mouse_report.v = -mouse_report.y;

    mouse_report.x = 0;
    mouse_report.y = 0;
    mouse_report.h = 0;

    return mouse_report;
}
