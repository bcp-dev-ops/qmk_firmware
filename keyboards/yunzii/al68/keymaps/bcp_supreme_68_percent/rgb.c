#include "layers/alpha_qwerty_rgb.c"
#include "layers/navigation_rgb.c"


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (rgb_matrix_get_mode() != RGB_MATRIX_SOLID_COLOR) {
        return false;
    }

    // Deskhop
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(3, 255, 255, 255);  // Indicator LED, white
    }
    if (dh_game_active) {
        rgb_matrix_set_color(38, 255, 255, 255);  // KC_DH_GAME key, white
    }

    uint8_t current_layer = get_highest_layer(layer_state);

    switch (current_layer) {
        case L_ALPHA_QWERTY:
            alpha_qwerty_rgb_indicators();
            return true;
        case L_NAVIGATION:
            navigation_rgb_indicators();
            return true;
    }

    return false;
}
