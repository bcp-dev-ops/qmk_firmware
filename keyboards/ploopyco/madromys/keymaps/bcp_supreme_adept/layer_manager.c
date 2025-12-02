#include "layer_manager.h"
#include "config.h"

static uint32_t layer1_exit_time = 0;
static uint32_t layer4_exit_time = 0;
static bool wheel_click_active = false;

uint32_t get_layer1_exit_time(void) {
    return layer1_exit_time;
}

uint32_t get_layer4_exit_time(void) {
    return layer4_exit_time;
}

bool is_in_layer_exit_cooldown(uint32_t now) {
    return (now - layer1_exit_time < LAYER1_EXIT_COOLDOWN) ||
           (now - layer4_exit_time < LAYER1_EXIT_COOLDOWN);
}

layer_state_t handle_layer_state_change(layer_state_t state) {
    static bool was_layer1 = false;
    static bool was_layer4 = false;

    if (was_layer1 && !layer_state_cmp(state, 1)) {
        layer1_exit_time = timer_read();
    }
    was_layer1 = layer_state_cmp(state, 1);

    if (was_layer4 && !layer_state_cmp(state, 4)) {
        layer4_exit_time = timer_read();
    }
    was_layer4 = layer_state_cmp(state, 4);

    switch (get_highest_layer(state)) {
        case 2:
            pointing_device_set_cpi(DPI_LAYER_2);
            break;
        case 1:
            pointing_device_set_cpi(DPI_LAYER_1);
            break;
        default:
            pointing_device_set_cpi(dpi_array[keyboard_config.dpi_config]);
            break;
    }

    if (layer_state_cmp(state, 4)) {
        wheel_click_active = true;
        register_code(MS_BTN3);
    } else if (wheel_click_active) {
        wheel_click_active = false;
        unregister_code(MS_BTN3);
    }

    return state;
}
