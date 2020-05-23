#pragma once

typedef struct {
  char const name[5];
  bool (*handler)(void); // return false to break command mode.
} Command;

#define END_OF_COMMANDS (Command) { .name = "_", .handler = NULL }

extern const Command commands[];

bool process_record_user_command(uint16_t const keycode, keyrecord_t * const record);
bool oled_task_user_command(void);

