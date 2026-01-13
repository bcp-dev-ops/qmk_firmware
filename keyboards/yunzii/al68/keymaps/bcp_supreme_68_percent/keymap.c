#include QMK_KEYBOARD_H

 // Register custom keycodes
#include "keymap_keycodes.h"

// Register keyboard layers
#include "layers.h"

// Vim-style Ctrl+U/D for Page Up/Down
const key_override_t ctrl_u_page_up = ko_make_basic(MOD_MASK_CTRL, KC_U, KC_PGUP);
const key_override_t ctrl_d_page_down = ko_make_basic(MOD_MASK_CTRL, KC_D, KC_PGDN);

const key_override_t *key_overrides[] = {
    &ctrl_u_page_up,
    &ctrl_d_page_down,
    NULL
};

// To be refactored later
static bool dh_game_active = false;


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


#include "macros/macros.c"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO_COPY:
            return process_macro_copy(keycode, record);
        case MACRO_CUT:
            return process_macro_cut(keycode, record);
        case MACRO_DISPLAY_BRIGHTNESS_DECREASE:
            return process_macro_display_brightness_decrease(keycode, record);
        case MACRO_DISPLAY_BRIGHTNESS_INCREASE:
            return process_macro_display_brightness_increase(keycode, record);
        case MACRO_DUPLICATE:
            return process_macro_duplicate(keycode, record);
        case MACRO_FOCUS_NEXT_WORKSHEET:
            return process_macro_focus_next_worksheet(keycode, record);
        case MACRO_FOCUS_PREVIOUS_WORKSHEET:
            return process_macro_focus_previous_worksheet(keycode, record);
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
        case MACRO_TOGGLE_RAINBOW:
            return process_macro_toggle_rainbow(keycode, record);
        case MACRO_UNDO:
            return process_macro_undo(keycode, record);
        case KC_DESKHOP_CONFIGOPEN:
            return process_macro_open_deskhop_config(keycode, record);
        case KC_DESKHOP_GAME_MODE:
            return process_macro_enable_deskhop_game_mode(keycode, record);
        case KC_LOCK_DESKHOP:
            return process_macro_lock_deskhop(keycode, record);
        case KC_SAVE_DESKHOP_OFFSET:
            return process_macro_save_deskhop_offset(keycode, record);
    }
    return true;
}

// Register Combos
#include "combos.c"

// Register Lighting
#include "rgb.c"

