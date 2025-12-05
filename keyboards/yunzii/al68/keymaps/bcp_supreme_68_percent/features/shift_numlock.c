static bool shift_tapped = false;
static uint16_t shift_timer = 0;
static bool shift_held = false;

bool process_shift_numlock(uint16_t keycode, keyrecord_t *record) {
    if (keycode != SHIFT_TOGGLE_NUMLOCK) {
        return true;
    }

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
}

void matrix_scan_shift_numlock(void) {
    if (shift_tapped && !shift_held && timer_elapsed(shift_timer) > TAPPING_TERM) {
        register_code(KC_LSFT);
        shift_held = true;
    }
}
