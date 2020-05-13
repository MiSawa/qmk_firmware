#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_number {
  _BASE = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST
};

