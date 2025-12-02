#pragma once

#include QMK_KEYBOARD_H

void reset_workspace_gesture(void);
report_mouse_t process_workspace_gesture(report_mouse_t mouse_report, uint32_t now);
