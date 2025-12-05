static bool tab_nav_tapped = false;
static uint16_t tab_nav_timer = 0;
static bool tab_nav_held = false;

bool process_tab_navigation(uint16_t keycode, keyrecord_t *record) {
    if (keycode != TAB_TOGGLE_NAVIGATION_LAYER) {
        return true;
    }

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
}

void matrix_scan_tab_navigation(void) {
    if (tab_nav_tapped && !tab_nav_held && timer_elapsed(tab_nav_timer) > TAPPING_TERM) {
        layer_on(L_NAVIGATION);
        tab_nav_held = true;
    }
}
