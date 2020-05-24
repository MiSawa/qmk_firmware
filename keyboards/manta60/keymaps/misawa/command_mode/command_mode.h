#pragma once

typedef struct {
  char const name[5];
  bool (*handler)(void); // return false to break command mode.
} Command;

#define END_OF_COMMANDS (Command) { .name = "_", .handler = NULL }

extern const Command commands[];

int get_num_commands(void);
void enter_command_mode(void);
void exit_command_mode(void);
bool is_in_command_mode(void);
void select_next(void);
void select_prev(void);
int get_current_selection(void);

// return false if the caller have to break command mode,
// including erronous cases.
bool execute_current_command(void);

