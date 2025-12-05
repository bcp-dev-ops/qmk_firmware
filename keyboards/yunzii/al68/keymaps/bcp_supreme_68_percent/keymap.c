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


#include "macros/tab_navigation.c"
#include "macros/shift_numlock.c"
#include "macros/copy.c"
#include "macros/cut.c"
#include "macros/duplicate.c"
#include "macros/focus_space_left.c"
#include "macros/focus_space_right.c"
#include "macros/focus_tab_left.c"
#include "macros/focus_tab_right.c"
#include "macros/focus_window_left.c"
#include "macros/focus_window_right.c"
#include "macros/go_back.c"
#include "macros/go_forward.c"
#include "macros/paste.c"
#include "macros/redo.c"
#include "macros/undo.c"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TAB_TOGGLE_NAVIGATION_LAYER:
            return process_tab_navigation(keycode, record);
        case SHIFT_TOGGLE_NUMLOCK:
            return process_shift_numlock(keycode, record);
        case MACRO_COPY:
            return process_macro_copy(keycode, record);
        case MACRO_CUT:
            return process_macro_cut(keycode, record);
        case MACRO_DUPLICATE:
            return process_macro_duplicate(keycode, record);
        case MACRO_FOCUS_SPACE_LEFT:
            return process_macro_focus_space_left(keycode, record);
        case MACRO_FOCUS_SPACE_RIGHT:
            return process_macro_focus_space_right(keycode, record);
        case MACRO_FOCUS_TAB_LEFT:
            return process_macro_focus_tab_left(keycode, record);
        case MACRO_FOCUS_TAB_RIGHT:
            return process_macro_focus_tab_right(keycode, record);
        case MACRO_FOCUS_WINDOW_LEFT:
            return process_macro_focus_window_left(keycode, record);
        case MACRO_FOCUS_WINDOW_RIGHT:
            return process_macro_focus_window_right(keycode, record);
        case MACRO_GO_BACK:
            return process_macro_go_back(keycode, record);
        case MACRO_GO_FORWARD:
            return process_macro_go_forward(keycode, record);
        case MACRO_PASTE:
            return process_macro_paste(keycode, record);
        case MACRO_REDO:
            return process_macro_redo(keycode, record);
        case MACRO_UNDO:
            return process_macro_undo(keycode, record);
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

