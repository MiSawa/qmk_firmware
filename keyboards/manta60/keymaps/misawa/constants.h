#pragma once
#include QMK_KEYBOARD_H
#include <quantum/version.h>

#define KEYMAP_VERSION "0.0.3"
#define ALL_VERSION KEYMAP_VERSION "_" QMK_VERSION "_" QMK_BUILDDATE
#ifdef OLED_COMMAND_MODE_ENABLE
#define ENTER_COMMAND_MODE_KEY CMD_START
#endif // OLED_COMMAND_MODE_ENABLE

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
#ifdef OLED_COMMAND_MODE_ENABLE
    CMD_START,
#else
#define CMD_START XXXXXXX
#endif // OLED_COMMAND_MODE_ENABLE
    INVERT_SHIFT_ON,
    INVERT_SHIFT_OFF,
    INVERT_SHIFT_TOGGLE,
    INVERT_SHIFT,
    INVERT_SHIFT_MAX = INVERT_SHIFT + QK_BASIC_MAX,
} custom_keycodes;

#define INVERT_SHIFT(kc) (INVERT_SHIFT + ((kc)&0xFF))
#define IS INVERT_SHIFT

