#include "scroll_mode.h"
#include "config.h"
#include "trackball_state.h"
#include <math.h>

static void send_scroll_events(int scrolls, bool is_horizontal) {
    int count = 0;
    while (scrolls != 0 && count < MAX_SCROLL_EVENTS_PER_CYCLE) {
        report_mouse_t scroll_report = {0};
        int direction = (scrolls > 0) ? 1 : -1;

        if (is_horizontal) {
            scroll_report.h = direction;
            tb_state.scroll_accumulated_h -= (float)direction;
        } else {
            scroll_report.v = -direction;
            tb_state.scroll_accumulated_v -= (float)direction;
        }

        host_mouse_send(&scroll_report);
        scrolls += (scrolls > 0) ? -1 : 1;
        count++;
    }
}

report_mouse_t process_scroll_mode(report_mouse_t mouse_report) {
    tb_state.scroll_accumulated_h += (float)mouse_report.x / PLOOPY_DRAGSCROLL_DIVISOR_H;
    tb_state.scroll_accumulated_v += (float)mouse_report.y / PLOOPY_DRAGSCROLL_DIVISOR_V;

    int horizontal_scrolls = (int)truncf(tb_state.scroll_accumulated_h);
    int vertical_scrolls = (int)truncf(tb_state.scroll_accumulated_v);

    send_scroll_events(horizontal_scrolls, true);
    send_scroll_events(vertical_scrolls, false);

    mouse_report.x = 0;
    mouse_report.y = 0;
    return mouse_report;
}
