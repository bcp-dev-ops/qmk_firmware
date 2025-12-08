#pragma once

#include <math.h>
#include "../keymap_keycodes.h"

typedef struct {
    int16_t x;
    int16_t y;
} mouse_xy_t;

mouse_xy_t apply_mouse_acceleration(mouse_xy_t movement);

void navigation_mode_set(bool enabled);
bool navigation_mode_get(void);
void navigation_mode_reset_accumulators(void);
report_mouse_t navigation_mode_process(report_mouse_t mouse_report);

void scroll_mode_set(bool enabled);
bool scroll_mode_get(void);
void scroll_mode_reset_accumulators(void);
report_mouse_t scroll_mode_process(report_mouse_t mouse_report);

void zoom_mode_set(bool enabled);
bool zoom_mode_get(void);
report_mouse_t zoom_mode_process(report_mouse_t mouse_report);

report_mouse_t media_mode_process(report_mouse_t mouse_report, int16_t *media_accumulator_x, int16_t *media_accumulator_y);

bool process_pointing_device_keycodes(uint16_t keycode, keyrecord_t *record);
