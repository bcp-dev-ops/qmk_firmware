/* Left Hand                                Right Hand                          */
/* ┌────┬────┬────┬────┬────┬────┬────┐    ┌────┬────┬────┬────┬────┬────┬────┐ */
/* │    │  v │  m │  l │  c │  p │    │    │    │  x │  f │  o │  u │  j │    │ */
/* ├────┼────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┼────┤ */
/* │    │  s │  t │  r │  d │  y │    │    │    │  . │  n │  a │  e │  i │    │ */
/* ├────┼────┼────┼────┼────┼────┼────┘    └────┼────┼────┼────┼────┼────┼────┤ */
/* │    │  z │  k │  q │  g │  w │              │  b │  h │  ' │  ; │  , │    │ */
/* └────┴────┴────┼────┼────┼────┤              ├────┼────┼────┼────┴────┴────┘ */
/*                │ T1 │ T2 │ T3 │              │ T4 │ T5 │ T6 │                */
/*                └────┴────┴────┘              └────┴────┴────┘                */
/* T1 - Space / Mouse Clicks Layer              T4 - Left Control / Space       */
/* T2 - Left Shift (Sticky)                     T5 - Key Repeat                 */
/* T3 - Backspace / Symbols Layer               T6 - Macropad Layer / Space     */
LAYOUT_split_3x6_3_ex2(
      QK_BOOT, KC_V,         KC_M,         KC_L,         KC_C,    KC_P,    MS_BTN2,           KC_NO,          KC_B,           KC_F,         KC_U,            KC_O,            KC_Q,            KC_BSPC,
      KC_LCTL, KC_S,         KC_T,         KC_R,         KC_D,    KC_Y,    MS_BTN1,           KC_NO,          KC_F,           KC_N,         KC_E,            KC_A,            KC_I,            KC_SCLN,
      KC_LSFT, LCTL_T(KC_X), LALT_T(KC_K), LCMD_T(KC_J), KC_G,    KC_W,                                       KC_Z,           RCMD_T(KC_H), RCMD_T(KC_QUOT), RALT_T(KC_QUES), RCTL_T(KC_DOT),  QK_BOOT,
                                                         KC_LGUI, OS_LSFT, KC_BSPC,           RCTL_T(KC_SPC), MO(RAISE),      KC_RALT
)
