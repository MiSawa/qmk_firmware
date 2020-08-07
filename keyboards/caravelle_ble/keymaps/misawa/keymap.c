#include QMK_KEYBOARD_H
#include CONSTANTS_H
#include "ble_keymap.h"

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define KC_LOWER MO(LAYER_LOWER)
#define KC_RAISE MO(LAYER_RAISE)
#define KC_ADJ MO(LAYER_ADJUST)

#define LALTMHEN ALT_T(KC_MHEN)
#define RALTHENK RALT_T(KC_HENK)

#define LCTLDEL LCTL_T(KC_DEL)
#define RCTLBSPC RCTL_T(KC_BSPC)

#define LOWERSPC LT(LAYER_LOWER, KC_SPC)
#define RAISEENT LT(LAYER_RAISE, KC_ENT)

#define QWERTY KC_QWERTY
#define WORKMAN KC_WORKMAN

#define layer_state_t uint32_t

// clang-format off
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT(
 //.---------+---------+---------+---------+---------+---------\                        /---------+---------+---------+---------+---------+---------.
       KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                              KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  KC_BSLS,
 //|---------+---------+---------+---------+---------+---------+---------+    +---------+---------+---------+---------+---------+---------+---------|
      KC_LCTL,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,  KC_LBRC,       KC_RBRC,     KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,  KC_QUOT,
 //|---------+---------+---------+---------+---------+---------+---------|    |---------+---------+---------+---------+---------+---------+---------|
      KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,  KC_LPRN,       KC_RPRN,     KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_RSFT,
 //\---------+---------+---------+---------+---------+---------+---------|    |---------+---------+---------+---------+---------+---------+---------/
                                   LALTMHEN,  LCTLDEL, KC_LOWER,   KC_SPC,        KC_ENT, KC_RAISE, RCTLBSPC, RALTHENK
 //                              \---------+---------+---------+---------/    \---------+---------+---------+---------/
  ),

  [LAYER_WORKMAN] = LAYOUT(
 //.---------+---------+---------+---------+---------+---------\                        /---------+---------+---------+---------+---------+---------.
       KC_TAB,     KC_Q,     KC_D,     KC_R,     KC_W,     KC_B,                              KC_J,     KC_F,     KC_U,     KC_P,  KC_SCLN,  KC_BSLS,
 //|---------+---------+---------+---------+---------+---------+---------+    +---------+---------+---------+---------+---------+---------+---------|
      KC_LCTL,     KC_A,     KC_S,     KC_H,     KC_T,     KC_G,  KC_LBRC,       KC_RBRC,     KC_Y,     KC_N,     KC_E,     KC_O,     KC_I,  KC_QUOT,
 //|---------+---------+---------+---------+---------+---------+---------|    |---------+---------+---------+---------+---------+---------+---------|
      KC_LSFT,     KC_Z,     KC_X,     KC_M,     KC_C,     KC_V,  KC_LPRN,       KC_RPRN,     KC_K,     KC_L,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_RSFT,
 //\---------+---------+---------+---------+---------+---------+---------|    |---------+---------+---------+---------+---------+---------+---------/
                                   LALTMHEN,  LCTLDEL, KC_LOWER,   KC_SPC,        KC_ENT, KC_RAISE, RCTLBSPC, RALTHENK
 //                              \---------+---------+---------+---------/    \---------+---------+---------+---------/
  ),

  [LAYER_LOWER] = LAYOUT(
 //.---------+---------+---------+---------+---------+---------\                        /---------+---------+---------+---------+---------+---------.
       KC_ESC,  KC_EXLM,    KC_AT,  KC_HASH,   KC_DLR,  KC_PERC,                           KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,   KC_DEL,
 //|---------+---------+---------+---------+---------+---------+---------+    +---------+---------+---------+---------+---------+---------+---------|
      _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,       _______,   KC_GRV,  KC_MINS,   KC_EQL,  KC_LCBR,  KC_RCBR,   KC_GRV,
 //|---------+---------+---------+---------+---------+---------+---------|    |---------+---------+---------+---------+---------+---------+---------|
      _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,       _______,  KC_TILD,  KC_UNDS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_TILD,
 //\---------+---------+---------+---------+---------+---------+---------|    |---------+---------+---------+---------+---------+---------+---------/
                                    _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______
 //                              \---------+---------+---------+---------/    \---------+---------+---------+---------/
  ),

  [LAYER_RAISE] = LAYOUT(
 //.---------+---------+---------+---------+---------+---------\                        /---------+---------+---------+---------+---------+---------.
      _______,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                             KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,  _______,
 //|---------+---------+---------+---------+---------+---------+---------+    +---------+---------+---------+---------+---------+---------+---------|
      _______,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,   KC_F11,        KC_F12,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,  _______,
 //|---------+---------+---------+---------+---------+---------+---------|    |---------+---------+---------+---------+---------+---------+---------|
      _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,       KC_LGUI,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,  _______,  _______,
 //\---------+---------+---------+---------+---------+---------+---------|    |---------+---------+---------+---------+---------+---------+---------/
                                    _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______
 //                              \---------+---------+---------+---------/    \---------+---------+---------+---------/
  ),

  [LAYER_ADJUST] = LAYOUT(
 //.---------+---------+---------+---------+---------+---------\                        /---------+---------+---------+---------+---------+---------.
        RESET,  AD_WO_L,  ADV_ID1,  ADV_ID2,  ADV_ID3,  ADV_ID4,                            QWERTY,  WORKMAN,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 //|---------+---------+---------+---------+---------+---------+---------+    +---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX,  DELBNDS,  DEL_ID1,  DEL_ID2,  DEL_ID3,  DEL_ID4,  XXXXXXX,       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 //|---------+---------+---------+---------+---------+---------+---------|    |---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX,  BATT_LV,  ENT_SLP,  ENT_DFU,    RESET,  XXXXXXX,  XXXXXXX,       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 //\---------+---------+---------+---------+---------+---------+---------|    |---------+---------+---------+---------+---------+---------+---------/
                                    _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______
 //                              \---------+---------+---------+---------/    \---------+---------+---------+---------/
  )
};
// clang-format off


layer_state_t layer_state_set_user(const layer_state_t state) {
    return update_tri_layer_state(state, LAYER_LOWER, LAYER_RAISE, LAYER_ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_ble(keycode, record)) {
        return false;
    }
    if (record->event.pressed) {
        switch (keycode) {
            case KC_QWERTY:
                {
                    set_single_persistent_default_layer(LAYER_QWERTY);
                    return false;
                }
                break;
            case KC_WORKMAN:
                {
                    set_single_persistent_default_layer(LAYER_WORKMAN);
                    return false;
                }
                break;
        }
    }
    return true;
}

