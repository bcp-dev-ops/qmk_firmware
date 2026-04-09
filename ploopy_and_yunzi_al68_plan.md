# Ploopy Adept + Yunzii AL68: Cross-Device Drag-Select Mode

## Goal

Coordinate state between two QMK devices connected through a DeskHop KVM to a Mac:

- **Yunzii AL68** (`keyboards/yunzii/al68/keymaps/bcp_supreme_68_percent/`)
- **Ploopy Adept** (`keyboards/ploopyco/madromys/keymaps/bcp_supreme_adept/`)

When a "drag-select mode" is toggled on the Yunzi keyboard, the Ploopy trackball should hold down left-click (enabling drag/text-select) until the mode is toggled off. The Yunzi navigation layer (Space held) should also gain left-click, right-click, and a visual indicator for the toggle state.

---

## Original Approach: Num Lock as Cross-Device Signal

The initial idea was to use the num_lock LED state as a shared signal between devices:

1. Yunzi sends `KC_NUM_LOCK` to toggle the OS num_lock state
2. Both devices read `host_keyboard_led_state().num_lock` to sync behavior
3. Ploopy enters drag-select mode when num_lock is on

### Why This Does Not Work

**Blocker 1: macOS does not properly handle num_lock.**
macOS largely ignores the num_lock HID usage. When a keyboard sends `KC_NUM_LOCK`, macOS does not reliably toggle an internal num_lock state or send back an updated LED output report with the num_lock bit set. This is a known macOS behavior — it only sends "turn off" LED reports, not proper toggle behavior. Even the keyboard itself cannot reliably read num_lock state on Mac via `host_keyboard_led_state().num_lock`.

**Blocker 2: USB HID LED reports are only sent to keyboard interfaces.**
The host OS sends LED output reports (containing num_lock, caps_lock, scroll_lock bits) only to USB devices that enumerate with a keyboard HID interface. The Ploopy Adept enumerates as a pointing device (mouse). The `host_keyboard_led_state()` function compiles into all QMK firmware, but the USB driver on the Ploopy will never receive LED data from the host. The function will always return 0.

**Blocker 3: DeskHop does not relay LED state to the mouse port.**
DeskHop has separate Pico microcontrollers for the keyboard side and mouse side, communicating over internal UART. The host's LED output report is routed only to the keyboard-side Pico. There is no mechanism in stock DeskHop firmware to forward LED state to the mouse-side Pico. Even if macOS sent a proper num_lock LED report, it would never reach the Ploopy.

These three blockers are independent — any one of them alone would prevent the num_lock approach from working.

---

## Alternative Approaches Considered

### Option A: Modify DeskHop Firmware (Custom UART Relay)

Forward a custom signal over DeskHop's internal UART from the keyboard-side Pico to the mouse-side Pico.

- **Pros**: True cross-device sync, no host software needed
- **Cons**: Requires custom DeskHop firmware changes, adds maintenance burden on a third firmware codebase, DeskHop UART protocol is not well-documented for extension
- **Complexity**: High

### Option B: Host-Side Relay App (Raw HID Daemon)

The Yunzi sends a Raw HID message to a small macOS background daemon. The daemon receives it and sends a Raw HID message to the Ploopy to toggle drag-select mode.

- **Pros**: No hardware mods, true cross-device sync
- **Cons**: Requires a persistent macOS app/daemon, adds a software dependency outside the firmware, Raw HID setup is non-trivial on macOS (requires signing or disabling SIP for HID access)
- **Complexity**: High

### Option C: Self-Contained on Each Device (No Cross-Device Sync)

Skip cross-device synchronization entirely. Implement drag-select mode as a Ploopy-only toggle, triggered by a button combo or tap dance on the trackball itself. The Yunzi gets its navigation layer changes (Space+S = left-click, Space+D = right-click) independently.

- **Pros**: Simple, no external dependencies, works today with stock DeskHop firmware
- **Cons**: No visual feedback on the keyboard for Ploopy state, requires interacting with the trackball to toggle drag-select
- **Complexity**: Low

### Option D: Caps Lock Instead of Num Lock

macOS does properly report caps_lock state. Use caps_lock as the signal instead.

- **Pros**: macOS cooperates (fixes Blocker 1)
- **Cons**: Blockers 2 and 3 remain — the Ploopy still won't receive LED reports. Also sacrifices caps_lock functionality.
- **Complexity**: Does not solve the problem

---

## Recommended Implementation: Option C (Self-Contained)

This is the only approach that works today without modifications to DeskHop firmware or a host-side relay app. The two devices are configured independently.

---

## Implementation Plan

### Part 1: Yunzii AL68 Changes (`bcp_supreme_68_percent`)

#### 1.1 Update Navigation Layer Bindings

**File**: `layers/navigation.c`

Change the home row S, D, F keys on the navigation layer (activated by holding Space):

| Key | Current Binding           | New Binding                               |
| --- | ------------------------- | ----------------------------------------- |
| S   | `MACRO_FOCUS_SPACE_RIGHT` | `MS_BTN1` (left-click)                    |
| D   | `MS_BTN2` (right-click)   | `MS_BTN2` (right-click, no change)        |
| F   | `MS_BTN1` (left-click)    | `KC_NUM_LOCK` (drag-select toggle signal) |

Current navigation layer row 3 (0-indexed row 2 in the LAYOUT macro):

```c
KC_LCTL, MACRO_GO_BACK, MACRO_GO_FORWARD, MS_BTN2, MS_BTN1, ...
```

Change to:

```c
KC_LCTL, MACRO_GO_BACK, MS_BTN1, MS_BTN2, KC_NUM_LOCK, ...
```

Wait — the matrix positions need to be verified. Looking at the navigation layer layout comment:

```
/* │  CTRL  │BACK│FWD │MS2 │MS1 │    │    │LEFT│DOWN│UP  │RGHT│    │  ENTER  │PGUP│ */
```

The keys in order after CTRL are: A=BACK, S=FWD, D=MS2, F=MS1. So:

| Position  | Key              | Current                                         | New |
| --------- | ---------------- | ----------------------------------------------- | --- |
| A (col 1) | MACRO_GO_BACK    | MACRO_GO_BACK (keep)                            |
| S (col 2) | MACRO_GO_FORWARD | MS_BTN1 (left-click)                            |
| D (col 3) | MS_BTN2          | MS_BTN2 (keep)                                  |
| F (col 4) | MS_BTN1          | `MACRO_DRAG_SELECT_TOGGLE` (new custom keycode) |

**Note**: We use a custom keycode `MACRO_DRAG_SELECT_TOGGLE` rather than raw `KC_NUM_LOCK` so we can track internal state for the LED indicator. The macro will:

1. Toggle a `static bool drag_select_active` flag
2. Send `KC_NUM_LOCK` to the host (even though macOS ignores it, this keeps the door open for future cross-device sync)

**Relocated bindings**: `MACRO_GO_FORWARD` (currently on S) needs a new home. Move it to the G key position (currently `_______`):

| Position  | Key       | Current            | New |
| --------- | --------- | ------------------ | --- |
| G (col 5) | `_______` | `MACRO_GO_FORWARD` |

Updated navigation layer row 3:

```c
KC_LCTL, MACRO_GO_BACK, MS_BTN1, MS_BTN2, MACRO_DRAG_SELECT_TOGGLE, MACRO_GO_FORWARD, ...
```

Update the ASCII art comment at the top of `navigation.c` to reflect the new layout.

#### 1.2 Add Custom Keycode

**File**: `keymap_keycodes.h`

Add to the enum:

```c
MACRO_DRAG_SELECT_TOGGLE,
```

#### 1.3 Add Drag-Select Toggle Macro

**New file**: `macros/drag_select_toggle.c`

```c
static bool drag_select_active = false;

bool process_macro_drag_select_toggle(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        drag_select_active = !drag_select_active;
    }
    return false;
}
```

This is intentionally simple — it only tracks state for the LED indicator. No `KC_NUM_LOCK` is sent since macOS ignores it. If cross-device sync is added later (Option A or B), this macro is where the signaling code would go.

**File**: `macros/macros.c`

Add include:

```c
#include "drag_select_toggle.c"
```

**File**: `keymap.c` — `process_record_user()`

Add case:

```c
case MACRO_DRAG_SELECT_TOGGLE:
    return process_macro_drag_select_toggle(keycode, record);
```

#### 1.4 Add LED Indicator for Drag-Select State

**File**: `rgb.c`

In `rgb_matrix_indicators_advanced_user()`, add a check for `drag_select_active` alongside the existing `dh_game_active` indicator. When the navigation layer is active and `drag_select_active` is true, light the F key red.

The F key is at matrix position `[2][4]` (row 2, col 4). From `keyboard.json`, the LED layout entry for `{"matrix": [2, 4], ...}` is at LED index 29 (0-indexed position in the `rgb_matrix.layout` array).

Add after the existing `dh_game_active` indicator block:

```c
if (drag_select_active) {
    rgb_matrix_set_color(29, 255, 0, 0);  // F key, red when drag-select active
}
```

This indicator should show on ALL layers (not just navigation) so the user always knows drag-select is active. The red F key serves as a persistent warning that the Ploopy is in drag-hold mode.

**File**: `layers/navigation_rgb.c`

Update the RGB logic to handle `MACRO_DRAG_SELECT_TOGGLE` keycode. Add it to the color mapping — when drag-select is active, show the F key as red; when inactive, show it as off/dark. Add a condition:

```c
} else if (keycode == MACRO_DRAG_SELECT_TOGGLE) {
    if (drag_select_active) {
        rgb_matrix_set_color(index, red_r, red_g, red_b);
    } else {
        rgb_matrix_set_color(index, 0, 0, 0);
    }
```

#### 1.5 Remove Old `shift_numlock.c`

**File**: `macros/shift_numlock.c` — Delete this file entirely.

It is an unused half-implementation from a previous attempt. It is not included in `macros/macros.c` and not referenced anywhere. Safe to delete.

#### 1.6 Update Navigation Layer ASCII Art and Comment

**File**: `layers/navigation.c`

Update the ASCII comment block at the top to reflect the new bindings:

```
/* │  CTRL  │BACK│LCK │RCK │DRGS│FWD │    │LEFT│DOWN│UP  │RGHT│    │  ENTER  │PGUP│ */
```

Where `DRGS` = drag-select toggle, `LCK` = left-click, `RCK` = right-click.

---

### Part 2: Ploopy Adept Changes (`bcp_supreme_adept`)

#### 2.1 Add Drag-Select Mode Toggle

Since cross-device sync is not possible without DeskHop firmware changes, drag-select must be triggered directly on the Ploopy.

**Triggering mechanism**: Add a new custom keycode `MACRO_DRAG_SELECT_TOGGLE` to the Ploopy. Assign it to a button combo or repurpose an existing binding.

**Recommended trigger**: Use the existing `MACRO_SWAP_MONITOR_WORKSPACES` button (top-left on the base layer) as a tap-dance or replace it, OR add a new combo. The simplest approach: add a new tap dance to an existing button.

**Alternative trigger (recommended)**: Double-tap the `MACRO_SWAP_MONITOR_WORKSPACES` key (currently a single-purpose key at position 0 on the base layer). Single tap = swap monitors, double tap = toggle drag-select. This uses the existing tap dance infrastructure.

The user should decide which button/combo to use. For the plan, we'll use a new custom keycode mapped to a button.

#### 2.2 Add Custom Keycode

**File**: `keymap_keycodes.h`

Add to the enum:

```c
MACRO_DRAG_SELECT_TOGGLE,
```

#### 2.3 Implement Drag-Select Mode in Pointing Device

**New file**: `pointing_device/drag_select_mode.c`

```c
static bool drag_select_active = false;

void drag_select_mode_set(bool enabled) {
    if (enabled && !drag_select_active) {
        drag_select_active = true;
        register_code(KC_MS_BTN1);  // Hold down left-click
    } else if (!enabled && drag_select_active) {
        drag_select_active = false;
        unregister_code(KC_MS_BTN1);  // Release left-click
    }
}

bool drag_select_mode_get(void) {
    return drag_select_active;
}

void drag_select_mode_toggle(void) {
    drag_select_mode_set(!drag_select_active);
}
```

**How this works**: `register_code(KC_MS_BTN1)` tells QMK to report the left mouse button as held in every subsequent HID mouse report. The host OS sees this as a continuous left-click hold — exactly what's needed for drag-selecting text, dragging files, etc. `unregister_code(KC_MS_BTN1)` releases it.

**Potential issue**: If the user physically clicks the left mouse button (`MS_BTN1` on the base layer) while drag-select is active, releasing that physical button might call `unregister_code(KC_MS_BTN1)` and cancel the drag-select hold. To prevent this, the `process_record_user` should intercept `MS_BTN1` presses while drag-select is active and suppress them (or just let them pass through — since the button is already "held" in the report, a physical press/release won't change the report state). Testing will determine if this is an issue.

**Another consideration**: The `pointing_device_task_user` runs on every scan cycle and constructs a mouse report. The `register_code`/`unregister_code` approach works at the HID report level, which is independent of the pointing device task. The button state set by `register_code` persists in the report until `unregister_code` is called. This should work correctly — the pointing device task handles movement (x, y, scroll) while the button state is managed separately by the HID report system.

#### 2.4 Add to Pointing Device Header

**File**: `pointing_device/pointing_device.h`

Add declarations:

```c
void drag_select_mode_set(bool enabled);
bool drag_select_mode_get(void);
void drag_select_mode_toggle(void);
```

#### 2.5 Add to Pointing Device Includes

**File**: `pointing_device/pointing_device.c`

Add include:

```c
#include "drag_select_mode.c"
```

#### 2.6 Wire Up Keycode Processing

**File**: `pointing_device/keycodes.c`

Add a case in `process_pointing_device_keycodes`:

```c
case MACRO_DRAG_SELECT_TOGGLE:
    if (record->event.pressed) {
        drag_select_mode_toggle();
    }
    return false;
```

#### 2.7 Assign Trigger on Base Layer

**Decision needed from user**: Which physical button or combo should toggle drag-select on the Ploopy?

Options:

- **A) Replace `MACRO_SWAP_MONITOR_WORKSPACES`** (top-left button) with `MACRO_DRAG_SELECT_TOGGLE`
- **B) Add a tap dance** to an existing button (e.g., double-tap top-left = drag-select, single-tap = swap monitors)
- **C) Add a combo** (e.g., press two buttons simultaneously)
- **D) Add to a different layer** (e.g., browser layer or a new layer)

The base layer currently is:

```
LAYOUT(
    MACRO_SWAP_MONITOR_WORKSPACES, MACRO_FOCUS_WINDOW_LEFT, MACRO_FOCUS_WINDOW_RIGHT, LT(L_BROWSER, MS_BTN2),
    MS_BTN1,                      DPI_TOGGLE_SCROLL
)
```

**Recommended**: Option B — tap dance on the top-left button. The tap dance infrastructure already exists in `bcp_supreme_adept`. Single tap = swap monitors, double tap = drag-select toggle. This preserves all existing functionality.

#### 2.8 (If Option B) Add Tap Dance for Drag-Select

**New file**: `tap_dances/drag_select_td.c`

Implement a tap dance that:

- Single tap: sends `MACRO_SWAP_MONITOR_WORKSPACES` behavior (include the swap monitor macro content inline)
- Double tap: calls `drag_select_mode_toggle()`

**File**: `tap_dances/tap_dances.c`

Add include for the new tap dance file.

**File**: `layers/base.c`

Replace `MACRO_SWAP_MONITOR_WORKSPACES` with the new tap dance keycode (e.g., `TD(TD_SWAP_DRAGSELECT)`).

---

### Part 3: Testing Plan

#### 3.1 Yunzi AL68 Testing

1. **Compile**: `make yunzii/al68:bcp_supreme_68_percent`
2. **Flash**: `make yunzii/al68:bcp_supreme_68_percent:flash`
3. **Verify navigation layer**:
    - Hold Space + S: should left-click
    - Hold Space + D: should right-click
    - Hold Space + F: should toggle drag-select state (visible via LED)
4. **Verify LED indicator**:
    - F key should light red when drag-select is active (on any layer)
    - F key should be dark/off when drag-select is inactive
    - When on navigation layer, F key should be red (active) or dark (inactive)
5. **Verify no regressions**:
    - Space tap still sends space
    - Space hold still activates navigation layer
    - All other navigation layer keys still work
    - MACRO_GO_FORWARD still works (now on G position)

#### 3.2 Ploopy Adept Testing

1. **Compile**: `make ploopyco/madromys:bcp_supreme_adept`
2. **Flash**: `make ploopyco/madromys:bcp_supreme_adept:flash`
3. **Verify drag-select mode**:
    - Double-tap top-left button (or chosen trigger): left-click should be held
    - Open a text document, move trackball: text should be selected
    - Double-tap again: left-click should release, text selection stops
4. **Verify no regressions**:
    - Single-tap top-left button: swap monitors still works
    - All other buttons and pointing device modes still work
    - Scroll mode, zoom mode, navigation mode unaffected
5. **Edge case testing**:
    - Toggle drag-select on, then physically click MS_BTN1 — verify behavior
    - Toggle drag-select on, switch DeskHop outputs, switch back — verify state persists
    - Toggle drag-select on, then enter scroll mode — verify interaction

---

### Part 4: Future Cross-Device Sync (Option A — DeskHop Firmware Mod)

If cross-device sync is desired later, the architecture above is designed to support it:

1. **Yunzi side**: `process_macro_drag_select_toggle` would send a DeskHop-specific key combo (similar to `KC_DESKHOP_GAME_MODE` pattern) that the DeskHop keyboard-side Pico intercepts
2. **DeskHop firmware**: A new UART command would relay this signal to the mouse-side Pico
3. **Ploopy side**: DeskHop mouse-side Pico would inject a synthetic keycode or HID report that the Ploopy reads to toggle drag-select mode

This would require changes to three firmware codebases (Yunzi QMK, DeskHop, Ploopy QMK) but the QMK-side scaffolding from this plan would already be in place.

---

## Files Changed Summary

### Yunzii AL68 (`keyboards/yunzii/al68/keymaps/bcp_supreme_68_percent/`)

| File                          | Action | Description                                                                 |
| ----------------------------- | ------ | --------------------------------------------------------------------------- |
| `keymap_keycodes.h`           | Edit   | Add `MACRO_DRAG_SELECT_TOGGLE` to enum                                      |
| `keymap.c`                    | Edit   | Add case for `MACRO_DRAG_SELECT_TOGGLE` in `process_record_user`            |
| `layers/navigation.c`         | Edit   | Remap S=left-click, F=drag-select toggle, G=go-forward; update ASCII art    |
| `layers/navigation_rgb.c`     | Edit   | Add color rule for `MACRO_DRAG_SELECT_TOGGLE` based on `drag_select_active` |
| `macros/drag_select_toggle.c` | Create | New macro: toggle `drag_select_active` bool                                 |
| `macros/macros.c`             | Edit   | Add `#include "drag_select_toggle.c"`                                       |
| `macros/shift_numlock.c`      | Delete | Remove unused half-implementation                                           |
| `rgb.c`                       | Edit   | Add persistent red F key indicator when `drag_select_active` is true        |

### Ploopy Adept (`keyboards/ploopyco/madromys/keymaps/bcp_supreme_adept/`)

| File                                 | Action | Description                                                           |
| ------------------------------------ | ------ | --------------------------------------------------------------------- |
| `keymap_keycodes.h`                  | Edit   | Add `MACRO_DRAG_SELECT_TOGGLE` to enum                                |
| `pointing_device/drag_select_mode.c` | Create | New module: register/unregister `KC_MS_BTN1` on toggle                |
| `pointing_device/pointing_device.h`  | Edit   | Add drag-select function declarations                                 |
| `pointing_device/pointing_device.c`  | Edit   | Add `#include "drag_select_mode.c"`                                   |
| `pointing_device/keycodes.c`         | Edit   | Add case for `MACRO_DRAG_SELECT_TOGGLE`                               |
| `tap_dances/drag_select_td.c`        | Create | New tap dance: single=swap monitors, double=drag-select toggle        |
| `tap_dances/tap_dances.c`            | Edit   | Include new tap dance file                                            |
| `layers/base.c`                      | Edit   | Replace `MACRO_SWAP_MONITOR_WORKSPACES` with `TD(TD_SWAP_DRAGSELECT)` |

---

## Open Questions for User

1. **Ploopy trigger**: Confirm tap-dance on top-left button (double-tap = drag-select) is acceptable, or choose a different trigger method.
2. **Navigation layer displacement**: `MACRO_GO_FORWARD` is being moved from S to G. `MACRO_FOCUS_SPACE_RIGHT` (currently on S position) was already replaced earlier in the design — confirm losing quick access to space-right navigation on this layer is OK, or suggest an alternative position.
3. **Drag-select + physical click interaction**: Should physical `MS_BTN1` clicks on the Ploopy be suppressed while drag-select is active, or allowed to pass through? Needs testing to determine default behavior.
