// Copyright 2024 Ross Hadden (@rosshadden)
// Copyright 2024 Ryan Neff (@JellyTitan)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "features/custom_shift_keys.h"
#include "features/layer_lock.h"

#define L(kc) LT(0, kc)

enum sofle_layers {
  _ERMAK,
  _TYPING,
  _DVORAK,
  _QWERTY,
  _GAMING,
  _NUM,
  _NAV,
  _LEGACY,
  
};

enum custom_keycodes {
  LOCK = SAFE_RANGE,
};

const custom_shift_key_t custom_shift_keys[] = {
  { KC_0, KC_ASTERISK },
  { KC_1, KC_PIPE },
  { KC_2, KC_EQUAL },
  { KC_3, KC_TILDE },
  { KC_4, KC_PLUS },
  { KC_5, KC_LEFT_ANGLE_BRACKET },
  { KC_6, KC_RIGHT_ANGLE_BRACKET },
  { KC_7, KC_CIRCUMFLEX },
  { KC_8, KC_AMPERSAND },
  { KC_9, KC_PERCENT },
  { KC_COMMA, KC_SEMICOLON },
  { KC_DOT, KC_COLON },
  { KC_DOUBLE_QUOTE, KC_RIGHT_PAREN },
  { KC_HASH, KC_DOLLAR },
  { KC_QUESTION, KC_EXCLAIM },
  { KC_SLASH, KC_BACKSLASH },
  { L(KC_GRAVE), KC_AT },
  { L(KC_QUOTE), KC_LEFT_PAREN },
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ERMAK] = LAYOUT(L(KC_LEFT_BRACKET), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_RIGHT_BRACKET, KC_HASH, KC_B, KC_Y, KC_O, KC_U, L(KC_QUOTE), KC_DOUBLE_QUOTE, KC_L, KC_D, KC_W, KC_V, KC_Z, LCTL_T(KC_ESC), LGUI_T(KC_C), LALT_T(KC_I), LCTL_T(KC_E), LSFT_T(KC_A), KC_COMMA, KC_DOT, RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_S), RGUI_T(KC_N), KC_Q, LSFT_T(LOCK), KC_G, KC_X, KC_J, KC_K, KC_MINUS, KC_MUTE, DF(_DVORAK), KC_SLASH, KC_R, KC_M, KC_F, KC_P, RSFT_T(LOCK), L(KC_GRAVE), KC_LALT, KC_LGUI, KC_BACKSPACE, LT(_NUM, KC_TAB), LT(_NAV, KC_ENTER), KC_SPACE, KC_RGUI, KC_RALT, KC_QUESTION),
  [_TYPING] = LAYOUT(KC_LEFT_BRACKET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_QUOTE, _______, _______, _______, _______, _______, _______, _______, KC_C, KC_I, KC_E, KC_A, _______, _______, KC_H, KC_T, KC_S, KC_N, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______),
  [_DVORAK] = LAYOUT(KC_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BACKSLASH, KC_EQUAL, KC_QUOTE, KC_COMMA, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLASH, _______, LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U), KC_I, KC_D, RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_N), RGUI_T(KC_S), KC_MINUS, _______, KC_SEMICOLON, KC_Q, KC_J, KC_K, KC_X, _______, DF(_ERMAK), KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSFT, KC_LEFT_BRACKET, _______, _______, _______, _______, _______, _______, _______, _______, KC_RIGHT_BRACKET),
  [_QWERTY] = LAYOUT(KC_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BACKSLASH, KC_EQUAL, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS, _______, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SEMICOLON), KC_DOUBLE_QUOTE, _______, KC_Z, KC_X, KC_C, KC_V, KC_B, _______, _______, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSFT, KC_LEFT_BRACKET, _______, _______, _______, _______, _______, _______, _______, _______, KC_RIGHT_BRACKET),
  [_GAMING] = LAYOUT(KC_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BACKSLASH, KC_EQUAL, KC_P, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_MINUS, _______, KC_SEMICOLON, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_DOUBLE_QUOTE, _______, KC_SLASH, KC_Z, KC_X, KC_C, KC_V, _______, _______, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_RSFT, KC_LEFT_BRACKET, _______, _______, _______, _______, _______, _______, _______, _______, KC_RIGHT_BRACKET),
  [_NUM] = LAYOUT(QK_BOOT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, QK_CLEAR_EEPROM, KC_EXCLAIM, KC_AT, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_PIPE, QK_DYNAMIC_TAPPING_TERM_PRINT, KC_7, KC_8, KC_9, KC_ASTERISK, KC_F12, _______, KC_HASH, KC_DOLLAR, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_GRAVE, QK_DYNAMIC_TAPPING_TERM_UP, KC_4, KC_5, KC_6, KC_KP_PLUS, XXXXXXX, _______, KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_TILDE, _______, _______, QK_DYNAMIC_TAPPING_TERM_DOWN, KC_1, KC_2, KC_3, KC_KP_SLASH, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_0, KC_KP_0, KC_KP_0),
  [_NAV] = LAYOUT(XXXXXXX, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, XXXXXXX, QK_MAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, XXXXXXX, KC_MS_UP, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_UP, KC_BTN2, XXXXXXX, XXXXXXX, QK_CAPS_WORD_TOGGLE, KC_BTN1, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, _______, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_BTN3, KC_BTN2, KC_BTN1, KC_DEL, _______, _______, _______, _______, _______, _______),
  [_LEGACY] = LAYOUT(KC_TILDE, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_PIPE, _______, _______, _______, _______, _______, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, _______, DF(_DVORAK), _______, _______, _______, _______, _______, _______, DF(_ERMAK), _______, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, _______, DF(_TYPING), _______, _______, DF(_QWERTY), _______, DF(_GAMING), _______, _______, _______, KC_PIPE, _______, _______, KC_EQUAL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
  
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NUM, _NAV, _LEGACY);
}

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_layer_lock(keycode, record, LOCK)) { return false; }

  if (
    get_highest_layer(default_layer_state) == _ERMAK &&
    get_highest_layer(layer_state) == _ERMAK &&
    !process_custom_shift_keys(keycode, record)
  ) {
    return false;
  }

  switch (keycode) {
    case LSFT_T(LOCK):
    case RSFT_T(LOCK):
      if (record->event.pressed && record->tap.count) {
        layer_lock_invert(get_highest_layer(layer_state));
        return false;
      }
      break;

    case L(KC_LEFT_BRACKET):
      if (!record->event.pressed) return false;
      if (record->tap.count) {
        tap_code16(KC_LEFT_BRACKET);
      } else {
        tap_code16(KC_LEFT_BRACKET);
        tap_code16(KC_RIGHT_BRACKET);
        tap_code16(KC_LEFT);
      }
      return false;
    case L(KC_QUOTE):
      if (!record->event.pressed) return false;
      if (record->tap.count) {
          tap_code16(KC_QUOTE);
      } else {
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
        tap_code16(KC_LEFT);
      }
      return false;
    case L(KC_GRAVE):
      if (!record->event.pressed) return false;
      if (record->tap.count) {
        tap_code16(KC_GRAVE);
      } else {
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
        tap_code16(KC_LEFT);
        return true;
      }
      return false;
  }

  return true;
}

#ifdef OLED_ENABLE

static void render_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0
  };
  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
  oled_write_P(PSTR("Keebler\nv0.1.0\n~~~~~~~~~"), false);

  oled_write_P(PSTR("\nLAYER:\n\t"), false);
  switch (get_highest_layer(default_layer_state)) {
    case _ERMAK:
      oled_write_P(PSTR("ermak"), false);
      break;
    case _TYPING:
      oled_write_P(PSTR("typing"), false);
      break;
    case _DVORAK:
      oled_write_P(PSTR("dvorak"), false);
      break;
    case _QWERTY:
      oled_write_P(PSTR("qwerty"), false);
      break;
    case _GAMING:
      oled_write_P(PSTR("gaming"), false);
      break;
    case _NUM:
      oled_write_P(PSTR("num"), false);
      break;
    case _NAV:
      oled_write_P(PSTR("nav"), false);
      break;
    case _LEGACY:
      oled_write_P(PSTR("legacy"), false);
      break;
    default:
      oled_write_P(PSTR("UNKNOWN"), false);
      break;
  }

  oled_write_P(PSTR("\nOVERLAY:\n\t"), false);
  switch (get_highest_layer(layer_state)) {
    case _ERMAK:
      oled_write_P(PSTR("ermak"), false);
      break;
    case _TYPING:
      oled_write_P(PSTR("typing"), false);
      break;
    case _DVORAK:
      oled_write_P(PSTR("dvorak"), false);
      break;
    case _QWERTY:
      oled_write_P(PSTR("qwerty"), false);
      break;
    case _GAMING:
      oled_write_P(PSTR("gaming"), false);
      break;
    case _NUM:
      oled_write_P(PSTR("num"), false);
      break;
    case _NAV:
      oled_write_P(PSTR("nav"), false);
      break;
    case _LEGACY:
      oled_write_P(PSTR("legacy"), false);
      break;
    default:
      oled_write_P(PSTR("UNKNOWN"), false);
      break;
  }

  oled_write_P(PSTR("\n\n\n"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_90;
  }
  return rotation;
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
  }
  return false;
}

#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_ERMAK] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(XXXXXXX, DF(_DVORAK)) },
  [_DVORAK] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(DF(_ERMAK), DF(_QWERTY)) },
  [_QWERTY] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(DF(_DVORAK), XXXXXXX) },

  // [_GAMING] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  // [_TYPING] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_LEGACY] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_NAV] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_NUM] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif

