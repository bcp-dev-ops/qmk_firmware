#include "layers/alpha_strdy_rgb.c"


bool rgb_matrix_indicators_user(void) {
    uint8_t current_layer = get_highest_layer(layer_state);

    switch (current_layer) {
        case ALPHA_STRDY:
            // alpha_strdy_rgb_indicators();
            break;
    }

    return false;
}
