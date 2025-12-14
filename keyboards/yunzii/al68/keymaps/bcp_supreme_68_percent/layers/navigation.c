/* ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────────┬────┐ */
/* │ ESC│  1 │  2 │  3 │  4 │  5 │  6 │  7 │  8 │  9 │  0 │  - │  = │ BSPACE │MUTE│ */
/* ├────┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─────┼────┤ */
/* │  TAB  │  Q │  W │  E │  R │  T │  Y │  U │  I │  O │  P │  [ │  ] │  \  │BOOT│ */
/* ├───────┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴─────┼────┤ */
/* │  CTRL  │  A │  S │  D │  F │  G │  H │  J │  K │  L │  ; │  ' │  ENTER  │PGUP│ */
/* ├────────┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴────┬────┼────┤ */
/* │   SHIFT   │  Z │  X │  C │  V │  B │  N │  M │  , │  . │  / │ SHIFT│ ↑  │PGDN│ */
/* ├──────┬────┴┬───┴──┬─┴────┴────┴────┴────┴────┴───┬┴────┼────┼────┬─┴──┬─┴──┬─┘ */
/* │ CTRL │ ALT │ GUI  │          SPACE               │ LCK │RCK │LEFT│  ↓ │RGHT│   */
/* └──────┴─────┴──────┴──────────────────────────────┴─────┴────┴────┴────┴────┘   */

LAYOUT_65_ansi_blocker(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_BSPC,  MACRO_TOGGLE_RAINBOW,
    KC_TAB,  MACRO_FOCUS_SPACE_LEFT, MACRO_FOCUS_SPACE_RIGHT, MACRO_FOCUS_WINDOW_LEFT, MACRO_FOCUS_WINDOW_RIGHT, MACRO_FOCUS_TAB_LEFT, MACRO_FOCUS_TAB_RIGHT, _______, _______, _______, _______, MACRO_FOCUS_PREVIOUS_WORKSHEET, MACRO_FOCUS_NEXT_WORKSHEET, _______, _______,
    KC_LCTL, MACRO_GO_BACK, MACRO_GO_FORWARD, MS_BTN2, MS_BTN1, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, KC_ENT, _______,
    KC_LSFT, MACRO_UNDO, MACRO_CUT, MACRO_COPY, MACRO_PASTE, _______, _______, _______, _______, _______, _______, KC_RSFT, KC_UP, _______,
    KC_LCTL, KC_LALT, KC_LGUI,                          KC_SPC,                                  _______,                _______,   KC_LEFT,           KC_DOWN,   KC_RIGHT
)


