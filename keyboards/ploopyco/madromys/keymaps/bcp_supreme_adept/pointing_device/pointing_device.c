#include "pointing_device.h"
#include "mouse_acceleration.c"
#include "navigation_mode.c"
#include "scroll_mode.c"
#include "zoom_mode.c"
#include "media_mode.c"
#include "keycodes.c"

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    mouse_xy_t movement = {mouse_report.x, mouse_report.y};
    movement = apply_mouse_acceleration(movement);
    mouse_report.x = movement.x;
    mouse_report.y = movement.y;

    if (navigation_mode_get()) {
        return navigation_mode_process(mouse_report);
    }

    extern bool is_scroll_mode;
    if (is_scroll_mode) {
        return scroll_mode_process(mouse_report);
    }

    extern int16_t media_accumulator_x;
    extern int16_t media_accumulator_y;
    if (IS_LAYER_ON(L_MEDIA)) {
        return media_mode_process(mouse_report, &media_accumulator_x, &media_accumulator_y);
    }

    if (zoom_mode_get()) {
        return zoom_mode_process(mouse_report);
    }

    return mouse_report;
}
