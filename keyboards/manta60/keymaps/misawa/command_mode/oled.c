#include QMK_KEYBOARD_H
#include "command_mode.h"
#include "oled.h"

bool oled_task_user_command(void) {
    if (!is_in_command_mode()) {
        return true;
    }
    const int num_commands = get_num_commands();
    for (int i = 0; i < num_commands; ++i) {
        if (i) oled_write_P(PSTR(" "), false);
        oled_write(commands[i].name, i == get_current_selection());
    }
    return false;
}
