#pragma once
#ifdef OLED_DRIVER_ENABLE

#    include QMK_KEYBOARD_H

oled_rotation_t oled_init_user(oled_rotation_t rotation);
void            oled_task_user(void);

#endif  // OLED_DRIVER_ENABLE
