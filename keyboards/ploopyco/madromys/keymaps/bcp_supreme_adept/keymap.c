#include QMK_KEYBOARD_H
#include "layers/layers.c"
#include "tap_dances/tap_dances.c"
#include "pointing_device/pointing_device.c"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_pointing_device_keycodes(keycode, record);
}

