#include QMK_KEYBOARD_H
#include "command_mode.h"

bool in_command_mode   = false;
int  current_selection = 0;

int get_num_commands(void) {
    static int num_commands = -1;
    if (num_commands >= 0) {
        return num_commands;
    }
    while (commands[++num_commands].handler != NULL)
        ;
    return num_commands;
}

bool __attribute__((unused)) is_in_command_mode(void) { return in_command_mode; }

void __attribute__((unused)) enter_command_mode(void) {
    oled_clear();
    in_command_mode   = true;
    current_selection = 0;
}

void __attribute__((unused)) exit_command_mode(void) {
    oled_clear();
    in_command_mode = false;
}

int get_current_selection(void) { return current_selection; }

void __attribute__((unused)) select_next(void) {
    ++current_selection;
    const int num_commands = get_num_commands();
    if (current_selection >= num_commands) {
        current_selection = num_commands - 1;
    }
}

void __attribute__((unused)) select_prev(void) {
    --current_selection;
    if (current_selection < 0) {
        current_selection = 0;
    }
}

bool __attribute__((unused)) execute_current_command(void) {
    const int cur = get_current_selection();
    if (0 <= cur && cur < get_num_commands()) {
        const Command command = commands[cur];
        if (command.handler != NULL) {
            if (command.handler()) {
                return true;
            }
        }
    }
    return false;
}
