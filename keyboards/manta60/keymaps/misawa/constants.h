#pragma once
#include QMK_KEYBOARD_H
#include <quantum/version.h>

#define KEYMAP_VERSION "0.0.3"
#define ALL_VERSION KEYMAP_VERSION "_" QMK_VERSION "_" QMK_BUILDDATE
#define ENTER_COMMAND_MODE_KEY CMD_START

// Defines names for use in layer keycodes and the keymap
typedef enum {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_ADJUST,
} layer_ids;

// Defines the keycodes used by our macros in process_record_user
typedef enum {
    KC_VER = SAFE_RANGE,
    CMD_START,
    TOGGLE_SHIFT_TOGGLE,
    TOGGLE_SHIFT,
    TOGGLE_SHIFT_MAX = TOGGLE_SHIFT + QK_BASIC_MAX,
} custom_keycodes;

#define TS(kc) (TOGGLE_SHIFT + ((kc)&0xFF))

