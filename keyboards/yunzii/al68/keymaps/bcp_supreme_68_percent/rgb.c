#include "layers/alpha_qwerty_rgb.c"
#include "layers/navigation_rgb.c"


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t current_layer = get_highest_layer(layer_state);

    switch (current_layer) {
        case L_ALPHA_QWERTY:
            alpha_qwerty_rgb_indicators();
            break;
        case L_NAVIGATION:
            navigation_rgb_indicators();
            break;
    }

    return false;
}
