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
    ESC_TOGGLE_NAVIGATION_LAYER,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_BSPC,  _______,
    KC_TAB,  MACRO_FOCUS_TAB_LEFT, MACRO_FOCUS_TAB_RIGHT, _______, MACRO_DUPLICATE, _______, _______, _______, _______, _______, _______, MACRO_FOCUS_SPACE_LEFT, MACRO_FOCUS_SPACE_RIGHT, _______, _______,
    KC_LCTL, MACRO_FOCUS_WINDOW_LEFT, MACRO_FOCUS_WINDOW_RIGHT, MS_BTN2, MS_BTN1, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, KC_ENT, _______,
    KC_LSFT, MACRO_UNDO, MACRO_CUT, MACRO_COPY, _______, MACRO_GO_BACK, MACRO_GO_FORWARD, _______, _______, _______, _______, KC_RSFT, KC_UP, _______,
    KC_LCTL, KC_LALT, KC_LGUI,                          KC_SPC,                                  _______,                _______,   KC_LEFT,           KC_DOWN,   KC_RIGHT

)


