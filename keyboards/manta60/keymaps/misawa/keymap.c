/* Copyright 2020 kamonanban
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include CONSTANTS_H
#include <pinkey2u/pinkey2u.h>
#include <command_mode/command_mode.h>
#include <command_mode/keymap.h>
#include <time_limited_auto_shift/process_time_limited_auto_shift.h>

#define KC_LOWER MO(LAYER_LOWER)
#define KC_RAISE MO(LAYER_RAISE)
#define KC_ADJ MO(LAYER_ADJUST)

#define LALTMHEN ALT_T(KC_MHEN)
#define RALTHENK RALT_T(KC_HENK)

#define LOWERSPC LT(LAYER_LOWER, KC_SPC)
#define RAISEENT LT(LAYER_RAISE, KC_ENT)

#define IST INVERT_SHIFT_TOGGLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_pinkey2u(
  //,---------------------------------------------------------------------.,---------------------------------------------------------------------.
       KC_GESC, IS(KC_1), IS(KC_2), IS(KC_3), IS(KC_4), IS(KC_5), KC_MINUS,    KC_EQL, IS(KC_6), IS(KC_7), IS(KC_8), IS(KC_9), IS(KC_0),   KC_GRV,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
        KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,  KC_LBRC,   KC_RBRC,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  KC_BSLS,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
      KC_LCTRL,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,  KC_COMM,    KC_DOT,     KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,  KC_QUOT,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                          KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_RSFT,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
      KC_LOWER,           LALTMHEN, KC_LCTRL, LOWERSPC,  KC_LGUI,   KC_DEL,   KC_BSPC,   KC_DEL, RAISEENT, KC_RCTRL, RALTHENK,           KC_RAISE
  //`---------+---------/\--------+---------+---------+---------+---------/\---------+---------+---------+---------+---------/\--------+---------'
  ),

  [LAYER_LOWER] = LAYOUT_pinkey2u(
  //,---------------------------------------------------------------------.,---------------------------------------------------------------------.
        KC_ESC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    KC_6,       KC_5,  XXXXXXX,  XXXXXXX,  XXXXXXX, KC_MINUS,   KC_EQL,  KC_BSPC,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    KC_Y,       KC_T,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LBRC,  KC_RBRC,  KC_BSLS,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  XXXXXXX,  XXXXXXX,   KC_DEL,  XXXXXXX,  XXXXXXX,    KC_H,       KC_G,  KC_BSPC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,            _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,            _______
  //`---------+---------/\--------+---------+---------+---------+---------/\---------+---------+---------+---------+---------/\--------+---------'
  ),

  [LAYER_RAISE] = LAYOUT_pinkey2u(
  //,---------------------------------------------------------------------.,---------------------------------------------------------------------.
       XXXXXXX,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F11,    KC_F12,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,    KC_F5,    KC_F6,    KC_F7,    KC_F8,  XXXXXXX,  XXXXXXX,   KC_BTN1,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  XXXXXXX,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,    KC_F9,   KC_F10,   KC_F11,   KC_F12,  XXXXXXX,  XXXXXXX,   KC_BTN2,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,    KC_UP,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,            _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,            _______
  //`---------+---------/\--------+---------+---------+---------+---------/\---------+---------+---------+---------+---------/\--------+---------'
  ),

  [LAYER_ADJUST] = LAYOUT_pinkey2u(
  //,---------------------------------------------------------------------.,---------------------------------------------------------------------.
         RESET,  RGB_TOG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_M_R,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    RESET,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI, RGB_M_SN,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  RGB_M_T,  RGB_HUD,  RGB_SAD,  RGB_VAD,  RGB_M_K,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,CMD_START,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
           IST,  RGB_M_P,  XXXXXXX,  XXXXXXX,   KC_VER, RGB_M_SW,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,            _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,            _______
  //`---------+---------/\--------+---------+---------+---------+---------/\---------+---------+---------+---------+---------/\--------+---------'
  )
};
// clang-format on

#define DECLARE_TAP_KEY_FUNC(keyname, ret) \
    bool tap_ ## keyname (void) { \
        SEND_STRING(SS_TAP(X_ ## keyname)); \
        return ret; \
    }

DECLARE_TAP_KEY_FUNC(VOLU, true);
DECLARE_TAP_KEY_FUNC(VOLD, true);
DECLARE_TAP_KEY_FUNC(MUTE, true);

bool emit_version(void) {
    SEND_STRING(ALL_VERSION);
    return false;
}


// Invert shift featture
bool invert_shift_enabled = false;
bool under_shift_invertion = false;
int shift_inverted_key_count = 0;

uint8_t mod_before_invert_shift = 0;
bool process_record_invert_shift(uint16_t const keycode, keyrecord_t* const record) {
    if (keycode == INVERT_SHIFT_TOGGLE) {
        shift_inverted_key_count = 0;
        if (record->event.pressed) {
            invert_shift_enabled ^= true;
        }
        return false;
    }
    if (under_shift_invertion) {
        if (record->event.pressed) {
            if (!shift_inverted_key_count++) {
                uint8_t const current_mods = get_mods();
                uint8_t const lshift_bit = MOD_BIT(KC_LSHIFT);
                uint8_t const rshift_bit = MOD_BIT(KC_RSHIFT);
                mod_before_invert_shift = current_mods;
                if (current_mods & (lshift_bit | rshift_bit)) {
                    set_mods(current_mods & ~(lshift_bit | rshift_bit));
                } else {
                    set_mods(current_mods ^ lshift_bit);
                }
            }
            register_code(keycode);
            return false;
        } else {
            if (!--shift_inverted_key_count) {
                set_mods(mod_before_invert_shift);
            }
            unregister_code(keycode);
            return false;
        }
    }
    return true;
}


// emit custom key code feature
#define UNDEF_KEY (~(uint16_t)(0))

uint16_t keycode_to_emit = UNDEF_KEY;
keyrecord_t custom_record = {
    .event = {
        .key = (keypos_t) {.row = 0, .col = 0},
        .pressed = true,
        .time = 0
    }
};

void tap_custom_key(uint16_t const keycode) {
    if (keycode_to_emit != UNDEF_KEY) {
        return;
    }

    keycode_to_emit = keycode;
    custom_record.event.time = (timer_read() | 1);
    custom_record.event.pressed = true;
    process_record(&custom_record);

    keycode_to_emit = keycode;
    custom_record.event.time = (timer_read() | 1);
    custom_record.event.pressed = false;
    process_record(&custom_record);

    keycode_to_emit = UNDEF_KEY;
}

uint16_t keymap_key_to_keycode(uint8_t const layer, keypos_t const key) {
    under_shift_invertion = false;
    // for tap_custom_key
    if (keycode_to_emit != UNDEF_KEY) {
        const uint16_t ret = keycode_to_emit;
        keycode_to_emit = UNDEF_KEY;
        return ret;
    }
    uint16_t const ret = pgm_read_word(&keymaps[layer][key.row][key.col]);
    if (ret < INVERT_SHIFT(QK_BASIC) || INVERT_SHIFT(QK_BASIC_MAX) < ret) {
        return ret;
    }
    // for invert_shift
    if (!invert_shift_enabled) {
        return ret - INVERT_SHIFT(QK_BASIC);
    }
    under_shift_invertion = true;
    return ret - INVERT_SHIFT(QK_BASIC);
}

#define DECLARE_TAP_CUSTOM_KEY_FUNC(keyname, ret) \
    bool tap_ ## keyname (void) { \
        tap_custom_key(KC_ ## keyname); \
        return ret; \
    }

DECLARE_TAP_CUSTOM_KEY_FUNC(ASUP, true);
DECLARE_TAP_CUSTOM_KEY_FUNC(ASDN, true);
DECLARE_TAP_CUSTOM_KEY_FUNC(ASRP, false);
DECLARE_TAP_CUSTOM_KEY_FUNC(ASTG, false);


// clang-format off
const Command commands[] = {
    (Command) {.name = "as+",  .handler = tap_ASUP},
    (Command) {.name = "as-",  .handler = tap_ASDN},
    (Command) {.name = "as?",  .handler = tap_ASRP},
    (Command) {.name = "as!",  .handler = tap_ASTG},
    (Command){.name = "vol+", .handler = tap_VOLU},
    (Command){.name = "vol-", .handler = tap_VOLD},
    (Command){.name = "mute", .handler = tap_MUTE},
    (Command){.name = "ver", .handler = emit_version},
    END_OF_COMMANDS,
};
// clang-format on

inline layer_state_t layer_state_set_user(layer_state_t const state) { return update_tri_layer_state(state, LAYER_LOWER, LAYER_RAISE, LAYER_ADJUST); }

bool process_record_user(uint16_t const keycode, keyrecord_t* const record) {
    if (!process_record_invert_shift(keycode, record)) {
        return false;
    }
    if (!process_auto_shift(keycode, record)) {
        return false;
    }
    if (!process_record_user_command(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case KC_VER:
            {
                if (record->event.pressed) {
                    emit_version();
                }
                return false;
            }
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    matrix_scan_process_auto_shift();
}

