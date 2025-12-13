#include QMK_KEYBOARD_H
#include "layers/layers.c"
#include "tap_dances/tap_dances.c"
#include "pointing_device/pointing_device.c"
#include "macros/macros.c"

void keyboard_post_init_user(void) {
    dpi_toggle_init();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_macro_keycodes(keycode, record)) {
        return false;
    }
    return process_pointing_device_keycodes(keycode, record);
}

