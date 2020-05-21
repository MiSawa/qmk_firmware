#pragma once

#include QMK_KEYBOARD_H

#define KEYMAP_VERSION "0.0.1"

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
} custom_keycodes;

