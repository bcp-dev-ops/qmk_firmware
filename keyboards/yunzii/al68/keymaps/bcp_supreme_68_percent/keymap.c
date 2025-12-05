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


static bool tab_nav_tapped = false;
static uint16_t tab_nav_timer = 0;
static bool tab_nav_held = false;

static bool shift_tapped = false;
static uint16_t shift_timer = 0;
static bool shift_held = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TAB_TOGGLE_NAVIGATION_LAYER:
            if (record->event.pressed) {
                if (tab_nav_tapped && timer_elapsed(tab_nav_timer) < TAPPING_TERM) {
                    uint8_t current_layer = get_highest_layer(layer_state);
                    if (current_layer == L_NAVIGATION) {
                        layer_off(L_NAVIGATION);
                    } else {
                        layer_on(L_NAVIGATION);
                    }
                    tab_nav_tapped = false;
                    tab_nav_held = false;
                    return false;
                } else {
                    tab_nav_tapped = true;
                    tab_nav_timer = timer_read();
                    tab_nav_held = false;
                }
            } else {
                if (tab_nav_held) {
                    layer_off(L_NAVIGATION);
                    tab_nav_held = false;
                } else if (tab_nav_tapped && timer_elapsed(tab_nav_timer) < TAPPING_TERM) {
                    tap_code(KC_TAB);
                }
                tab_nav_tapped = false;
            }
            return false;
        case SHIFT_TOGGLE_NUMLOCK:
            if (record->event.pressed) {
                if (shift_tapped && timer_elapsed(shift_timer) < TAPPING_TERM) {
                    tap_code(KC_NUM_LOCK);
                    shift_tapped = false;
                    shift_held = false;
                    return false;
                } else {
                    shift_tapped = true;
                    shift_timer = timer_read();
                    shift_held = false;
                }
            } else {
                if (shift_held) {
                    unregister_code(KC_LSFT);
                    shift_held = false;
                } else if (shift_tapped && timer_elapsed(shift_timer) < TAPPING_TERM) {
                    unregister_code(KC_LSFT);
                }
                shift_tapped = false;
            }
            return false;
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
    if (tab_nav_tapped && !tab_nav_held && timer_elapsed(tab_nav_timer) > TAPPING_TERM) {
        layer_on(L_NAVIGATION);
        tab_nav_held = true;
    }
    if (shift_tapped && !shift_held && timer_elapsed(shift_timer) > TAPPING_TERM) {
        register_code(KC_LSFT);
        shift_held = true;
    }
}

// Register Combos
#include "combos.c"

// Register Lighting
#include "rgb.c"

