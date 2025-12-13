static uint16_t dpi_high = 1000;
static uint16_t dpi_low = 250;
static uint16_t dpi_scroll = 50;
static uint16_t current_dpi = 1000;
static bool is_in_scroll_mode = false;
static uint16_t dpi_timer = 0;

void dpi_toggle_init(void) {
    pointing_device_set_cpi(current_dpi);
}

void dpi_toggle_scroll_set(bool enabled) {
    if (enabled) {
        is_in_scroll_mode = true;
        pointing_device_set_cpi(dpi_scroll);
        scroll_mode_set(true);
    } else {
        is_in_scroll_mode = false;
        pointing_device_set_cpi(current_dpi);
        scroll_mode_set(false);
    }
}

bool dpi_toggle_scroll_get(void) {
    return is_in_scroll_mode;
}

void dpi_toggle(void) {
    if (current_dpi == dpi_high) {
        current_dpi = dpi_low;
    } else {
        current_dpi = dpi_high;
    }

    if (!is_in_scroll_mode) {
        pointing_device_set_cpi(current_dpi);
    }
}

bool process_dpi_toggle_scroll(uint16_t keycode, keyrecord_t *record) {
    if (keycode == DPI_TOGGLE_SCROLL) {
        if (record->event.pressed) {
            dpi_timer = timer_read();
            dpi_toggle_scroll_set(true);
        } else {
            dpi_toggle_scroll_set(false);
            if (timer_elapsed(dpi_timer) < TAPPING_TERM) {
                dpi_toggle();
            }
        }
        return false;
    }
    return true;
}
