#pragma once

#include "rgb.h"

#undef MATRIX_COLS
#define MATRIX_COLS 7

#define VIAL_KEYBOARD_UID {0x8A, 0x3B, 0x2C, 0x1D, 0x4E, 0x5F, 0x6A, 0x7B}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

#define ONESHOT_TIMEOUT 1000
