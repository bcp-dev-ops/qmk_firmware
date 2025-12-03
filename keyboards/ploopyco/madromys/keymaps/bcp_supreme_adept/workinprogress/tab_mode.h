#pragma once

#include QMK_KEYBOARD_H

void reset_tab_mode(void);
report_mouse_t process_tab_mode(report_mouse_t mouse_report, uint32_t now);
