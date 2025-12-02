#include QMK_KEYBOARD_H
#include "layers.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [ALPHA_STRDY] =
        #include "layers/alpha_strdy.c"
    ,
};

#include "rgb.c"
