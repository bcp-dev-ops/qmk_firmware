#include "layers.h"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_BASE] =
		#include "base.c"
	,
    [L_BROWSER] =
        #include "browser.c"
    ,
	[L_MEDIA] =
		#include "media.c"
	,
	[L_PLAYBACK] =
		#include "playback.c"

};
