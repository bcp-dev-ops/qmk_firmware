#include "trackball_state.h"

trackball_state_t tb_state = {0};

void reset_trackball_state(void) {
    tb_state = (trackball_state_t){0};
}
