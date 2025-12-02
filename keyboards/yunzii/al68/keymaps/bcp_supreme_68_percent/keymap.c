#include QMK_KEYBOARD_H
#include "layers.h"
#include "keycodes.h"

// Register keyboard layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_ALPHA_QWERTY] =
		#include "layers/alpha_qwerty.c"
	,
	[L_FUNCTIONAL] =
		#include "layers/functional.c"
	,
};

// Register encoder layers
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [L_ALPHA_QWERTY] = {
        #include "layers/alpha_qwerty_encoder.c"
    },
    [L_FUNCTIONAL] = {
        #include "layers/functional_encoder.c"
    },
};


// Register Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO_FOCUS_WINDOW_LEFT:
            if (record->event.pressed) {
                #include "macros/focus_window_left.c"
            }
            return false;
        case MACRO_FOCUS_WINDOW_RIGHT:
            if (record->event.pressed) {
                #include "macros/focus_window_right.c"
            }
            return false;
    }
    return true;
}

// Register Combos
#include "combos.c"

// Register Lighting
#include "rgb.c"

