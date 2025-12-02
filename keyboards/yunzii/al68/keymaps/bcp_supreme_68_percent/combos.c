enum combo_events {
    COMBO_ALPHA_QWERTY_DRAGSCROLL,
};

// ---- Combo definition ----
const uint16_t PROGMEM dragscroll_combo[] = {
    MS_BTN1,
    LT(FUNCTIONAL, MS_BTN2),
    COMBO_END
};

combo_t key_combos[] = {
    [COMBO_ALPHA_QWERTY_DRAGSCROLL] = COMBO_ACTION(dragscroll_combo),
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

// ---- Restrict combo to ALPHA_QWERTY layer ----
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case COMBO_ALPHA_QWERTY_DRAGSCROLL:
            return layer_state_is(ALPHA_QWERTY);
    }
    return true;
}

// ---- Combo action ----
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case COMBO_ALPHA_QWERTY_DRAGSCROLL:
            if (pressed) {
                tap_code(MS_BTN3);
            }
            break;
    }
}

