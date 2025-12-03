#include QMK_KEYBOARD_H
#include "layers/layers.c"

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return handle_layer_state_change(state);
// }

// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     uint32_t now = timer_read();
//     uint8_t highest_layer = get_highest_layer(layer_state);
//
//     switch (highest_layer) {
//         case 0:
//             if (!is_in_layer_exit_cooldown(now)) {
//                 mouse_report = process_workspace_gesture(mouse_report, now);
//             }
//             break;
//
//         case 1:
//             mouse_report = process_scroll_mode(mouse_report);
//             break;
//
//         case 2:
//             mouse_report = process_volume_mode(mouse_report);
//             break;
//
//         case 4:
//             mouse_report = process_tab_mode(mouse_report, now);
//             break;
//     }
//
//     return mouse_report;
// }
