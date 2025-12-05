#include QMK_KEYBOARD_H

 // Register custom keycodes
#include "keymap_keycodes.h"

// Register keyboard layers
#include "layers.h"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_ALPHA_QWERTY] =
		#include "layers/alpha_qwerty.c"
	,
	[L_FUNCTIONAL] =
		#include "layers/functional.c"
	,
    [L_NAVIGATION] =
        #include "layers/navigation.c"
};

// Register encoder layers
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [L_ALPHA_QWERTY] = {
        #include "layers/alpha_qwerty_encoder.c"
    },
    [L_FUNCTIONAL] = {
        #include "layers/functional_encoder.c"
    },
    [L_NAVIGATION] = {
        #include "layers/navigation_encoder.c"
    },
};


#include "features/tab_navigation.c"
#include "features/shift_numlock.c"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_tab_navigation(keycode, record)) return false;
    if (!process_shift_numlock(keycode, record)) return false;
    switch (keycode) {
        case MACRO_COPY:
            if (record->event.pressed) {
                #include "macros/copy.c"
            }
            return false;
        case MACRO_CUT:
            if (record->event.pressed) {
                #include "macros/cut.c"
            }
            return false;
        case MACRO_DUPLICATE:
            if (record->event.pressed) {
                #include "macros/duplicate.c"
            }
            return false;
        case MACRO_FOCUS_SPACE_LEFT:
            if (record->event.pressed) {
                #include "macros/focus_space_left.c"
            }
            return false;
        case MACRO_FOCUS_SPACE_RIGHT:
            if (record->event.pressed) {
                #include "macros/focus_space_right.c"
            }
            return false;
        case MACRO_FOCUS_TAB_LEFT:
            if (record->event.pressed) {
                #include "macros/focus_tab_left.c"
            }
            return false;
        case MACRO_FOCUS_TAB_RIGHT:
            if (record->event.pressed) {
                #include "macros/focus_tab_right.c"
            }
            return false;
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
        case MACRO_GO_BACK:
            if (record->event.pressed) {
                #include "macros/go_back.c"
            }
            return false;
        case MACRO_GO_FORWARD:
            if (record->event.pressed) {
                #include "macros/go_forward.c"
            }
            return false;
        case MACRO_PASTE:
            if (record->event.pressed) {
                #include "macros/paste.c"
            }
            return false;
        case MACRO_REDO:
            if (record->event.pressed) {
                #include "macros/redo.c"
            }
            return false;
        case MACRO_UNDO:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    #include "macros/redo.c"
                } else {
                    #include "macros/undo.c"
                }
            }
            return false;
    }
    return true;
}

void matrix_scan_user(void) {
    matrix_scan_tab_navigation();
    matrix_scan_shift_numlock();
}

// Register Combos
#include "combos.c"

// Register Lighting
#include "rgb.c"

