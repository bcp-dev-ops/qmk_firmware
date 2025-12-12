bool process_macro_keycodes(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case MACRO_GO_BACK:
            #include "go_back.c"
            return false;

        case MACRO_GO_FORWARD:
            #include "go_forward.c"
            return false;

        case MACRO_COPY:
            #include "copy.c"
            return false;

        case MACRO_CUT:
            #include "cut.c"
            return false;

        case MACRO_PASTE:
            #include "paste.c"
            return false;

        case MACRO_UNDO:
            #include "undo.c"
            return false;

        case MACRO_REDO:
            #include "redo.c"
            return false;

        case MACRO_DUPLICATE:
            #include "duplicate.c"
            return false;

        case MACRO_FOCUS_SPACE_LEFT:
            #include "focus_space_left.c"
            return false;

        case MACRO_FOCUS_SPACE_RIGHT:
            #include "focus_space_right.c"
            return false;

        case MACRO_FOCUS_TAB_LEFT:
            #include "focus_tab_left.c"
            return false;

        case MACRO_FOCUS_TAB_RIGHT:
            #include "focus_tab_right.c"
            return false;

        case MACRO_FOCUS_WINDOW_LEFT:
            #include "focus_window_left.c"
            return false;

        case MACRO_FOCUS_WINDOW_RIGHT:
            #include "focus_window_right.c"
            return false;

        default:
            return true;
    }
}
