#ifdef OLED_DRIVER_ENABLE
#    include <split_util.h>
#    include <oled_tasks.h>
#    include <constants.h>
#    include <command_mode/oled.h>

static void __attribute__((unused)) render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};
    oled_write_P(qmk_logo, false);
}

void __attribute__((unused)) render_status(void) {
    // Host Keyboard LED Status
    const led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR(" NUM ") : PSTR("     "), led_state.num_lock);
    oled_write_P(led_state.caps_lock ? PSTR(" CAP ") : PSTR("     "), led_state.caps_lock);
    oled_write_P(led_state.scroll_lock ? PSTR(" SCR ") : PSTR("     "), led_state.scroll_lock);
    oled_write_ln_P(PSTR(""), false);

    switch (get_highest_layer(layer_state)) {
        case LAYER_BASE:
            // Don't show anything
            oled_write_ln_P(PSTR(""), false);
            break;
        case LAYER_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case LAYER_RAISE:
            oled_write_ln_P(PSTR("Upper"), false);
            break;
        case LAYER_ADJUST:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Unknown"), false);
            break;
    }
}

oled_rotation_t oled_init_user(const oled_rotation_t rotation) {
    if (isLeftHand) {
        return OLED_ROTATION_180;  // Flip orientation on the left hand side
    }
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        if (!oled_task_user_command()) {
            return;
        }
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
#    ifdef ENABLE_SLAVE_OLED
        render_logo();       // Renders a static logo
        oled_scroll_left();  // Turns on scrolling
#    endif
    }
}

#endif  // OLED_DRIVER_ENABLE
