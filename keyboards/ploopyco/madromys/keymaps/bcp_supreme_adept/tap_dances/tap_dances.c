#include "tap_dances.h"

#include "scroll_click.c"
#include "media_control.c"

tap_dance_action_t tap_dance_actions[] = {
    [TD_SCROLL_CLICK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, scroll_click_finished, scroll_click_reset),
    [TD_MEDIA_CONTROL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, media_control_finished, media_control_reset)
};
