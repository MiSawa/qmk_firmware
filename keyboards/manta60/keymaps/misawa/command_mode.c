#include QMK_KEYBOARD_H
#include <constants.h>
#include <command_mode.h>

bool in_command_mode = false;
int current_selection = 0;

int get_num_commands(void) {
  static int num_commands = -1;
  if (num_commands >= 0) {
    return num_commands;
  }
  while (commands[++num_commands].handler != NULL);
  return num_commands;
}

bool is_in_command_mode(void) {
  return in_command_mode;
}

void enter_command_mode(void) {
  oled_clear();
  in_command_mode = true;
  current_selection = 0;
}

void exit_command_mode(void) {
  oled_clear();
  in_command_mode = false;
}

int get_current_selection(void) {
  return current_selection;
}

void select_next(void) {
  ++current_selection;
  const int num_commands = get_num_commands();
  if (current_selection >= num_commands) {
    current_selection = num_commands - 1;
  }
}

void select_prev(void) {
  --current_selection;
  if (current_selection < 0) {
    current_selection = 0;
  }
}

bool oled_task_user_command(void) {
  if (!in_command_mode) {
    return true;
  }
  const int num_commands = get_num_commands();
  for (int i = 0; i < num_commands; ++i) {
    if (i) oled_write_P(PSTR(" "), false);
    oled_write(commands[i].name, i == current_selection);
  }
  return false;
}

bool process_record_user_command(uint16_t const keycode, keyrecord_t * const record) {
  if (!in_command_mode) {
    if (keycode == CMD_START && record->event.pressed) {
      enter_command_mode();
      return false;
    } else {
      return true;
    }
  }
  switch (keycode) {
    case KC_ENT:
      if (record->event.pressed) {
        const int cur = get_current_selection();
        if (0 <= cur && cur < get_num_commands()) {
          const Command command = commands[cur];
          if (command.handler != NULL) {
            if (command.handler()) {
              return false;
            }
          }
        }
        exit_command_mode();
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

