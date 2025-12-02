#pragma once

#include QMK_KEYBOARD_H

uint32_t get_layer1_exit_time(void);
uint32_t get_layer4_exit_time(void);
bool is_in_layer_exit_cooldown(uint32_t now);

layer_state_t handle_layer_state_change(layer_state_t state);
