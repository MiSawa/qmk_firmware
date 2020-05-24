#include QMK_KEYBOARD_H
#include <constants.h>
#include "command_mode.h"

#ifndef ENTER_COMMAND_MODE_KEY
# error ENTER_COMMAND_MODE_KEY should be defined
#endif

bool process_record_user_command(uint16_t const keycode, keyrecord_t * const record) {
  if (!is_in_command_mode()) {
    if ((keycode == ENTER_COMMAND_MODE_KEY) && record->event.pressed) {
      enter_command_mode();
      return false;
    } else {
      return true;
    }
  }
  switch (keycode) {
    case KC_ENT:
      if (record->event.pressed) {
        if (!execute_current_command()) {
          exit_command_mode();
        }
        return false;
      }
      break;
    case KC_UP:
    case KC_LEFT:
      if (record->event.pressed) {
        select_prev();
        return false;
      }
      break;
    case KC_DOWN:
    case KC_RIGHT:
      if (record->event.pressed) {
        select_next();
        return false;
      }
      break;
    case KC_C:
      if (record->event.pressed && (get_mods() & MOD_MASK_CTRL)) {
        exit_command_mode();
        return false;
      }
      break;
    case KC_ESC:
      if (record->event.pressed) {
        exit_command_mode();
        return false;
      }
  }
  return true;
}

