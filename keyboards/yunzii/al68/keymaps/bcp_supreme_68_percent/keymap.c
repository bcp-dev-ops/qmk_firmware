#include QMK_KEYBOARD_H
#include "layers.h"
#include "custom_keycodes.h"

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [ALPHA_QWERTY] = {
        #include "layers/alpha_qwerty_encoder.c"
    },
    [FUNCTIONAL] = {
        #include "layers/functional_encoder.c"
    },
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ALPHA_QWERTY] =
		#include "layers/alpha_qwerty.c"
	,
	[FUNCTIONAL] =
		#include "layers/functional.c"
	,
};

#include "combos.c"
#include "macros.c"
#include "rgb.c"
