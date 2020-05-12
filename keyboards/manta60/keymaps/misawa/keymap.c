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


#ifdef OLED_DRIVER_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Upper\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();  // Renders a static logo
        oled_scroll_left();  // Turns on scrolling
    }
}
#endif

