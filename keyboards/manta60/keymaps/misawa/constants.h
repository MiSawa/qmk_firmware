#pragma once

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
typedef enum {
  LAYER_BASE = 0,
  LAYER_LOWER,
  LAYER_RAISE,
  LAYER_ADJUST,
} layer_id;

// Defines the keycodes used by our macros in process_record_user
typedef enum {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST
} custom_keycodes;

#define KC_LOWER MO(LAYER_LOWER)
#define KC_RAISE MO(LAYER_RAISE)
#define KC_ADJ   MO(LAYER_ADJUST)

