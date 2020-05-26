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

#define KC_LOWER MO(LAYER_LOWER)
#define KC_RAISE MO(LAYER_RAISE)
#define KC_ADJ MO(LAYER_ADJUST)

#define LALTMHEN ALT_T(KC_MHEN)
#define RALTHENK RALT_T(KC_HENK)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_pinkey2u(
  //,---------------------------------------------------------------------.,---------------------------------------------------------------------.
       KC_GESC,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5, KC_MINUS,    KC_EQL,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,   KC_GRV,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
        KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,  KC_LBRC,   KC_RBRC,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  KC_BSLS,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
      KC_LCTRL,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,  KC_COMM,    KC_DOT,     KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,  KC_QUOT,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                          KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_RSFT,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
      KC_LOWER,           LALTMHEN, KC_LCTRL,   KC_SPC,  KC_LGUI,   KC_DEL,   KC_BSPC,   KC_DEL,   KC_ENT, KC_RCTRL, RALTHENK,           KC_RAISE
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
       _______,    KC_F5,    KC_F6,    KC_F7,    KC_F8,  XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  XXXXXXX,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,    KC_F9,   KC_F10,   KC_F11,   KC_F12,  XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,    KC_UP,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,            _______,  _______,  KC_BTN1,  KC_BTN3,  KC_BTN2,   KC_BTN2,  KC_BTN3,  KC_BTN1,  _______,  _______,            _______
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
       _______,  RGB_M_P,  XXXXXXX,  XXXXXXX,   KC_VER, RGB_M_SW,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
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

#define UNDEF (~(uint16_t)(0))

uint16_t keycode_to_emit = UNDEF;
keyrecord_t custom_record = {
    .event = {
        .key = (keypos_t) {.row = 0, .col = 0},
        .pressed = true,
        .time = 0
    }
};

void tap_custom_key(uint16_t const keycode) {
    if (keycode_to_emit != UNDEF) {
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

    keycode_to_emit = UNDEF;
}

uint16_t keymap_key_to_keycode(uint8_t const layer, keypos_t const key) {
    if (keycode_to_emit != UNDEF) {
        const uint16_t ret = keycode_to_emit;
        keycode_to_emit = UNDEF;
        return ret;
    }
    return pgm_read_word(&keymaps[layer][key.row][key.col]);
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
    if (!process_record_user_command(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case KC_VER:
            if (record->event.pressed) {
                emit_version();
            }
            return false;
            break;
    }
    return true;
}
