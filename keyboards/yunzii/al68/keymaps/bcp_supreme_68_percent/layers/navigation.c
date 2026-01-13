/* ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────────┬────┐ */
/* │ ESC│ F1 │ F2 │ F3 │ F4 │ F5 │ F6 │ F7 │ F8 │ F9 │ F10│ F11│ F12│ BSPACE │RNBW│ */
/* ├────┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─────┼────┤ */
/* │  TAB  │ SL │ SR │ WL │ WR │ TL │ TR │    │    │    │    │    │ WSL│ WSR │BOOT│ */
/* ├───────┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴─────┼────┤ */
/* │  CTRL  │BACK│FWD │MS2 │MS1 │    │    │LEFT│DOWN│UP  │RGHT│    │  ENTER  │PGUP│ */
/* ├────────┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴────┬────┼────┤ */
/* │   SHIFT   │UNDO│CUT │COPY│PSTE│    │    │    │    │    │    │ SHIFT│ ↑  │PGDN│ */
/* ├──────┬────┴┬───┴──┬─┴────┴────┴────┴────┴────┴───┬┴────┼────┼────┬─┴──┬─┴──┬─┘ */
/* │ CTRL │ ALT │ GUI  │          SPACE               │ LCK │RCK │LEFT│  ↓ │RGHT│   */
/* └──────┴─────┴──────┴──────────────────────────────┴─────┴────┴────┴────┴────┘   */

LAYOUT_65_ansi_blocker(
    KC_ESC,  KC_F1,                  KC_F2,                   KC_F3,                   KC_F4,                    KC_F5,                KC_F6,                 KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,                         KC_F12,                     KC_BSPC, MACRO_TOGGLE_RAINBOW,
    KC_TAB,  MACRO_FOCUS_SPACE_LEFT, MACRO_FOCUS_SPACE_RIGHT, MACRO_FOCUS_WINDOW_LEFT, MACRO_FOCUS_WINDOW_RIGHT, MACRO_FOCUS_TAB_LEFT, MACRO_FOCUS_TAB_RIGHT, _______, _______, _______,  _______, MACRO_FOCUS_PREVIOUS_WORKSHEET, MACRO_FOCUS_NEXT_WORKSHEET, _______, _______,
    KC_LCTL, MACRO_GO_BACK,          MACRO_GO_FORWARD,        MS_BTN2,                 MS_BTN1,                  _______,              KC_LEFT,               KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,                        KC_ENT,                              _______,
    KC_LSFT, MACRO_UNDO,             MACRO_CUT,               MACRO_COPY,              MACRO_PASTE,              _______,              _______,               _______,_______,  _______,  _______, KC_RSFT,                        KC_UP,                               _______,
    KC_LCTL, KC_LALT,  KC_LGUI,                               KC_SPC,                  _______,                  _______,                                                                          KC_LEFT,                        KC_DOWN,                             KC_RIGHT
)


