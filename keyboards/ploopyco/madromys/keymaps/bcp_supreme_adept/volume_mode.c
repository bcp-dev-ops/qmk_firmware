#include "volume_mode.h"
#include "config.h"
#include "trackball_state.h"

report_mouse_t process_volume_mode(report_mouse_t mouse_report) {
    tb_state.volume_accumulator = clamp(
        tb_state.volume_accumulator - mouse_report.y,
        -MAX_VOLUME_DELTA,
        MAX_VOLUME_DELTA
    );

    while (tb_state.volume_accumulator >= VOLUME_DIVIDER) {
        tap_code(KC_AUDIO_VOL_UP);
        tb_state.volume_accumulator -= VOLUME_DIVIDER;
    }

    while (tb_state.volume_accumulator <= -VOLUME_DIVIDER) {
        tap_code(KC_AUDIO_VOL_DOWN);
        tb_state.volume_accumulator += VOLUME_DIVIDER;
    }

    mouse_report.x = 0;
    mouse_report.y = 0;
    return mouse_report;
}
