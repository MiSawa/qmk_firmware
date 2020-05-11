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

// Defines names for use in layer keycodes and the keymap
enum layer_number {
  _BASE = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //,---------------------------------------------------------------------.,---------------------------------------------------------------------.
        KC_ESC,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5, KC_MINUS,    KC_EQL,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,   KC_GRV,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
        KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,  KC_LBRC,   KC_RBRC,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  KC_BSLS,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
      KC_LCTRL,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,  KC_COMM,    KC_DOT,     KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,  KC_QUOT,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                          KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_RSFT,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
         LOWER,  XXXXXXX,  KC_LALT, KC_LCTRL,   KC_SPC,  KC_LGUI,   KC_ENT,    KC_ENT,   KC_DEL,  KC_BSPC, KC_RCTRL,  KC_RALT,  XXXXXXX,   RAISE
  //`---------+----------/\-------+---------+---------+---------+---------/\---------+---------+---------+---------+---------/\--------+----------'
  ),

  [_LOWER] = LAYOUT(
  //,---------------------------------------------------------------------.,---------------------------------------------------------------------.
        KC_GRV,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,  KC_MINS,   KC_EQL, KC_MINUS,   KC_EQL,  KC_BSPC,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LBRC,  KC_RBRC,  KC_BSLS,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  XXXXXXX,  XXXXXXX,   KC_DEL,  XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX,  KC_BSPC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
         LOWER,  XXXXXXX,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  XXXXXXX,   RAISE
  //`---------+----------/\-------+---------+---------+---------+---------/\---------+---------+---------+---------+---------/\--------+----------'
 ),

  [_RAISE] = LAYOUT(
  //,---------------------------------------------------------------------.,---------------------------------------------------------------------.
       _______,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F11,    KC_F12,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  XXXXXXX,  KC_MS_U,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,    KC_UP,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
         LOWER,  XXXXXXX,  _______,  _______,  KC_BTN2,  KC_BTN3,  KC_BTN1,   _______,  _______,  _______,  _______,  _______,  XXXXXXX,   RAISE
  //`---------+----------/\-------+---------+---------+---------+---------/\---------+---------+---------+---------+---------/\--------+----------'
  ),

  [_ADJUST] = LAYOUT(
  //,---------------------------------------------------------------------.,---------------------------------------------------------------------.
       EH_RGHT,  RGB_TOG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_M_R,  XXXXXXX,   EH_LEFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   RESET,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI, RGB_M_SN,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  RGB_M_T,  RGB_HUD,  RGB_SAD,  RGB_VAD,  RGB_M_K,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  RGB_M_P,  XXXXXXX,  XXXXXXX,  XXXXXXX, RGB_M_SW,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
         LOWER,  XXXXXXX,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  XXXXXXX,   RAISE
  //`---------+----------/\-------+---------+---------+---------+---------/\---------+---------+---------+---------+---------/\--------+----------'
  )
};

static inline void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
