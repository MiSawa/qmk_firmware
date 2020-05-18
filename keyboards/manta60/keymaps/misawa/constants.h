#pragma once

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
typedef enum {
  LAYER_BASE = 0,
  LAYER_LOWER,
  LAYER_RAISE,
  LAYER_ADJUST,
} layer_ids;

// Defines the keycodes used by our macros in process_record_user
// typedef enum {
//   LOWER = SAFE_RANGE,
//   RAISE,
//   ADJUST
// } custom_keycodes;

