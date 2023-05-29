/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_layers { 
  LAYER_BASE = 0,
  LAYER_MAIN,
  LAYER_NUM,
  LAYER_SYM1,
  LAYER_SYM2,
  LAYER_NAV,
  LAYER_CHAR,
  LAYER_CONF
};

// #define LAYER_BASE  0
// #define LAYER_MAIN 1
// #define LAYER_SYM 2
// #define LAYER_NAV 3
// #define LAYER_CHAR 4
// #define LAYER_CONF 5

enum custom_keycodes {
  FR_CCIR = SAFE_RANGE,
  FR_CCIRM,
  FR_EUR,
  FR_DEG,
  FR_OE,
  FR_AE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, ALT_T(KC_A), GUI_T(KC_S), CTL_T(KC_D), SFT_T(KC_F), KC_G, KC_H, SFT_T(KC_J), CTL_T(KC_K), GUI_T(KC_L), ALT_T(KC_SCLN), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                           XXXXXXX, LT(LAYER_MAIN, KC_ESC), XXXXXXX,   XXXXXXX, LT(LAYER_SYM1, KC_SPC), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [LAYER_MAIN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_Y, XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_TAB,  KC_ENT,  KC_DEL, KC_BSPC, XXXXXXX,                      XXXXXXX,    KC_H, TG(LAYER_NUM),  TG(LAYER_SYM2), TG(LAYER_CHAR), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX,                      XXXXXXX,    KC_N, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [LAYER_SYM1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_T, XXXXXXX,                      XXXXXXX,  KC_EQL, KC_ASTR, KC_UNDS, KC_TILD, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,TG(LAYER_NAV),KC_G, XXXXXXX,                      XXXXXXX, KC_LCBR, KC_LBRC, KC_LPRN,  KC_DQT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------|-------+--------+-+-------++--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_B, XXXXXXX,                      XXXXXXX, KC_RCBR, KC_RBRC, KC_RPRN, KC_PIPE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [LAYER_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      XXXXXXX, KC_EXLM,   KC_AT,  KC_DLR, KC_GRV, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_PLUS, KC_MINS, KC_HASH,  KC_DQT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------|-------+---------+-------++--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_AMPR, KC_CIRC, KC_PERC, KC_BSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_LALT, KC_LCTL,    XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [LAYER_SYM2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      XXXXXXX, KC_EXLM,   KC_AT,  KC_DLR, KC_GRV, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_PLUS, KC_MINS, KC_HASH,  KC_DQT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------|--------+---------+-------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_AMPR, KC_CIRC, KC_PERC, KC_BSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_LALT, KC_LCTL,    XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  [LAYER_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LGUI, XXXXXXX, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_F11, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_LALT, KC_LCTL,    _______,   MO(5), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [LAYER_CHAR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, ALGR(KC_DQT), ALGR(KC_CIRC), ALGR(KC_GRV), ALGR(KC_QUOTE), KC_ALGR,   XXXXXXX, FR_EUR, FR_DEG, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        FR_AE,   FR_OE, XXXXXXX,FR_CCIRM, FR_CCIR, KC_CAPS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,   XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [LAYER_CONF] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,   _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FR_CCIR:
      if (record->event.pressed)
        SEND_STRING(SS_TAP(X_ALGR) SS_TAP(X_COMM) "c");
      break;
    case FR_CCIRM:
      if (record->event.pressed)
        SEND_STRING(SS_TAP(X_ALGR) SS_TAP(X_COMM) "C");
      break;
    case FR_EUR:
      if (record->event.pressed)
        SEND_STRING(SS_TAP(X_ALGR) SS_TAP(X_EQL) "e");
      break;
    case FR_DEG:
      if (record->event.pressed)
        SEND_STRING(SS_TAP(X_ALGR) "oo");
      break;
    case FR_OE:
      if (record->event.pressed)
        SEND_STRING(SS_TAP(X_ALGR) "oe");
      break;
    case FR_AE:
      if (record->event.pressed)
        SEND_STRING(SS_TAP(X_ALGR) "ae");
  }
  return true;
};
  
#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
    rgblight_disable();
}
#endif // RGBLIGHT_ENABLE

