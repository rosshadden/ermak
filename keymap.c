// Copyright 2024 Ross Hadden (@rosshadden)
// Copyright 2024 Ryan Neff (@JellyTitan)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "features/custom_shift_keys.h"
#include "features/layer_lock.h"
#include "features/select_word.h"

#define L(kc) LT(0, kc)

enum sofle_layers {
  _ERMAK,
  _TYPING,
  _DVORAK,
  _QWERTY,
  _GAMING,
  _NUM,
  _NAV,
  _MEDIA,
  _SYS,
  _LAYERS,
  
};

enum custom_keycodes {
  PG_LOCK = SAFE_RANGE,
  PG_SEL,
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
  [_ERMAK] = LAYOUT(L(KC_LEFT_BRACKET), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_RIGHT_BRACKET, KC_HASH, KC_B, KC_Y, KC_O, KC_U, L(KC_QUOTE), KC_DOUBLE_QUOTE, KC_L, KC_D, KC_W, KC_V, KC_Z, LCTL_T(KC_ESC), LGUI_T(KC_C), LALT_T(KC_I), LCTL_T(KC_E), LSFT_T(KC_A), KC_COMMA, KC_DOT, RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_S), RGUI_T(KC_N), KC_Q, KC_LSFT, KC_G, KC_X, KC_J, KC_K, KC_MINUS, KC_MUTE, DF(_DVORAK), KC_SLASH, KC_R, KC_M, KC_F, KC_P, KC_RSFT, L(KC_GRAVE), LALT_T(KC_NO), LGUI_T(KC_NO), KC_BACKSPACE, LT(_NUM, KC_TAB), LT(_NAV, KC_ENTER), KC_SPACE, RGUI_T(KC_NO), RALT_T(KC_NO), KC_QUESTION),
  [_TYPING] = LAYOUT(KC_LEFT_BRACKET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_QUOTE, _______, _______, _______, _______, _______, _______, _______, KC_C, KC_I, KC_E, KC_A, _______, _______, KC_H, KC_T, KC_S, KC_N, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______),
  [_DVORAK] = LAYOUT(KC_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BACKSLASH, KC_EQUAL, KC_QUOTE, KC_COMMA, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLASH, _______, LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U), KC_I, KC_D, RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_N), RGUI_T(KC_S), KC_MINUS, _______, KC_SEMICOLON, KC_Q, KC_J, KC_K, KC_X, _______, DF(_ERMAK), KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSFT, KC_LEFT_BRACKET, _______, _______, _______, _______, _______, _______, _______, _______, KC_RIGHT_BRACKET),
  [_QWERTY] = LAYOUT(KC_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BACKSLASH, KC_EQUAL, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS, _______, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SEMICOLON), KC_DOUBLE_QUOTE, _______, KC_Z, KC_X, KC_C, KC_V, KC_B, _______, _______, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSFT, KC_LEFT_BRACKET, _______, _______, _______, _______, _______, _______, _______, _______, KC_RIGHT_BRACKET),
  [_GAMING] = LAYOUT(KC_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BACKSLASH, KC_EQUAL, KC_P, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_MINUS, _______, KC_SEMICOLON, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_DOUBLE_QUOTE, _______, KC_SLASH, KC_Z, KC_X, KC_C, KC_V, _______, _______, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_RSFT, KC_LEFT_BRACKET, _______, _______, _______, _______, _______, _______, _______, _______, KC_RIGHT_BRACKET),
  [_NUM] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_AMPERSAND, KC_SEMICOLON, XXXXXXX, XXXXXXX, KC_KP_EQUAL, KC_AT, KC_NUM, XXXXXXX, KC_EXCLAIM, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_HASH, KC_GRAVE, KC_COLON, KC_KP_7, KC_KP_8, KC_KP_9, KC_PERCENT, XXXXXXX, QK_CAPS_WORD_TOGGLE, KC_CIRCUMFLEX, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_DOLLAR, KC_PIPE, KC_KP_MINUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_UNDERSCORE, LSFT_T(PG_LOCK), KC_LEFT_ANGLE_BRACKET, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_RIGHT_ANGLE_BRACKET, KC_TILDE, _______, _______, KC_KP_ASTERISK, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_SLASH, RSFT_T(PG_LOCK), QK_CLEAR_EEPROM, QK_BOOT, QK_MAKE, _______, _______, LT(_NAV, DF(_ERMAK)), _______, KC_KP_0, KC_KP_DOT, KC_COMMA),
  [_NAV] = LAYOUT(XXXXXXX, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, XXXXXXX, XXXXXXX, KC_MENU, XXXXXXX, KC_MS_WH_LEFT, KC_MS_WH_LEFT, KC_MS_UP, KC_MS_WH_RIGHT, KC_MS_WH_RIGHT, XXXXXXX, KC_BTN1, KC_UP, KC_BTN2, XXXXXXX, KC_PGUP, _______, KC_MS_WH_UP, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_UP, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, KC_PGDN, LSFT_T(PG_LOCK), KC_MS_WH_DOWN, KC_BTN3, KC_BTN2, KC_BTN1, KC_MS_WH_DOWN, _______, _______, XXXXXXX, PG_SEL, KC_UNDO, KC_AGAIN, XXXXXXX, RSFT_T(PG_LOCK), KC_BTN3, KC_BTN2, KC_BTN1, KC_DEL, LT(_NUM, DF(_ERMAK)), _______, _______, _______, _______, _______),
  [_MEDIA] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MEDIA_REWIND, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MEDIA_NEXT_TRACK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MEDIA_PREV_TRACK, XXXXXXX, KC_MEDIA_STOP, KC_MEDIA_NEXT_TRACK, XXXXXXX, LSFT_T(PG_LOCK), XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, KC_MUTE, KC_MEDIA_FAST_FORWARD, KC_MEDIA_PREV_TRACK, RSFT_T(PG_LOCK), XXXXXXX, _______, _______, _______, _______, _______, KC_MEDIA_PLAY_PAUSE, _______, _______, XXXXXXX),
  [_SYS] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WAKE, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP, XXXXXXX, XXXXXXX, LSFT_T(PG_LOCK), XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PWR, RSFT_T(PG_LOCK), XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX),
  [_LAYERS] = LAYOUT(KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, EH_LEFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_DVORAK), XXXXXXX, XXXXXXX, EH_RGHT, _______, XXXXXXX, XXXXXXX, DF(_ERMAK), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_TYPING), DF(_SYS), XXXXXXX, DF(_QWERTY), LSFT_T(PG_LOCK), DF(_GAMING), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, DF(_MEDIA), XXXXXXX, XXXXXXX, RSFT_T(PG_LOCK), XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX),
  
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NUM, _NAV, _LAYERS);
}

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_layer_lock(keycode, record, PG_LOCK)) { return false; }
  if (!process_select_word(keycode, record, PG_SEL)) { return false; }

  if (
    (get_highest_layer(default_layer_state) == _ERMAK || get_highest_layer(default_layer_state) == _TYPING) &&
    !process_custom_shift_keys(keycode, record)
  ) {
    return false;
  }

  switch (keycode) {
    case LT(_NUM, DF(_ERMAK)):
    case LT(_NAV, DF(_ERMAK)):
      if (record->event.pressed && record->tap.count) {
        set_single_persistent_default_layer(_ERMAK);
        return false;
      }
      break;

    // hyprland
    case LGUI_T(KC_NO):
    case RGUI_T(KC_NO):
      if (record->event.pressed && record->tap.count) {
        tap_code16(LAG(KC_SPACE));
        return false;
      }
      break;

    // wezterm
    case LALT_T(KC_NO):
    case RALT_T(KC_NO):
      if (record->event.pressed && record->tap.count) {
        tap_code16(C(KC_SPACE));
        return false;
      }
      break;

    case LSFT_T(PG_LOCK):
    case RSFT_T(PG_LOCK):
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
        del_mods(MOD_MASK_SHIFT);
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
        del_mods(MOD_MASK_SHIFT);
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
        del_mods(MOD_MASK_SHIFT);
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
    case _MEDIA:
      oled_write_P(PSTR("media"), false);
      break;
    case _SYS:
      oled_write_P(PSTR("sys"), false);
      break;
    case _LAYERS:
      oled_write_P(PSTR("layers"), false);
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
    case _MEDIA:
      oled_write_P(PSTR("media"), false);
      break;
    case _SYS:
      oled_write_P(PSTR("sys"), false);
      break;
    case _LAYERS:
      oled_write_P(PSTR("layers"), false);
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
  [_ERMAK]  = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(XXXXXXX, DF(_DVORAK)) },
  [_DVORAK] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(DF(_ERMAK), DF(_QWERTY)) },
  [_QWERTY] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(DF(_DVORAK), XXXXXXX) },

  [_GAMING] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_LAYERS] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_MEDIA]  = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_NAV]    = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_NUM]    = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_SYS]    = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_TYPING] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif

