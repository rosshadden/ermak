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
  _MELEE,
  
};

enum custom_keycodes {
  PG_LOCK = SAFE_RANGE,
  PG_SEL,
  KC_JUP, KC_JDOWN, KC_JLEFT, KC_JRIGHT, KC_JMOD,
  KC_CUP, KC_CDOWN, KC_CLEFT, KC_CRIGHT,
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
  [_ERMAK] = LAYOUT(L(KC_LEFT_BRACKET), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_RIGHT_BRACKET, KC_HASH, LGUI_T(KC_B), LALT_T(KC_Y), LCTL_T(KC_O), LSFT_T(KC_U), L(KC_QUOTE), KC_DOUBLE_QUOTE, RSFT_T(KC_L), RCTL_T(KC_D), RALT_T(KC_W), RGUI_T(KC_V), KC_Z, LCTL_T(KC_ESC), KC_C, KC_I, KC_E, KC_A, KC_COMMA, KC_DOT, KC_H, KC_T, KC_S, KC_N, L(KC_Q), KC_LSFT, LGUI_T(KC_G), LALT_T(KC_X), LCTL_T(KC_J), LSFT_T(KC_K), KC_MINUS, KC_MUTE, KC_F20, KC_SLASH, RSFT_T(KC_R), RCTL_T(KC_M), RALT_T(KC_F), RGUI_T(KC_P), KC_RSFT, L(KC_GRAVE), LALT_T(KC_NO), LGUI_T(KC_NO), KC_BACKSPACE, LT(_NUM, KC_TAB), LT(_NAV, KC_ENTER), KC_SPACE, RGUI_T(KC_NO), RALT_T(KC_NO), KC_QUESTION),
  [_TYPING] = LAYOUT(KC_LEFT_BRACKET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_B, KC_Y, KC_O, KC_U, KC_QUOTE, _______, KC_L, KC_D, KC_W, KC_V, _______, _______, KC_C, KC_I, KC_E, KC_A, _______, _______, KC_H, KC_T, KC_S, KC_N, _______, _______, KC_G, KC_X, KC_J, KC_K, _______, _______, _______, _______, KC_R, KC_M, KC_F, KC_P, _______, KC_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______),
  [_DVORAK] = LAYOUT(KC_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BACKSLASH, KC_EQUAL, KC_QUOTE, KC_COMMA, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLASH, _______, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINUS, _______, LGUI_T(KC_SEMICOLON), LALT_T(KC_Q), LCTL_T(KC_J), LSFT_T(KC_K), KC_X, _______, DF(_ERMAK), KC_B, RSFT_T(KC_M), RCTL_T(KC_W), RALT_T(KC_V), RGUI_T(KC_Z), KC_RSFT, KC_LEFT_BRACKET, _______, _______, _______, _______, _______, _______, _______, _______, KC_RIGHT_BRACKET),
  [_QWERTY] = LAYOUT(KC_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BACKSLASH, KC_EQUAL, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS, _______, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SEMICOLON, KC_QUOTE, _______, LGUI_T(KC_Z), LALT_T(KC_X), LCTL_T(KC_C), LSFT_T(KC_V), KC_B, _______, _______, KC_N, RSFT_T(KC_M), RCTL_T(KC_COMMA), RALT_T(KC_DOT), RGUI_T(KC_SLASH), KC_RSFT, KC_LEFT_BRACKET, _______, _______, _______, _______, _______, _______, _______, _______, KC_RIGHT_BRACKET),
  [_GAMING] = LAYOUT(KC_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BACKSLASH, KC_EQUAL, KC_P, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_MINUS, _______, KC_SEMICOLON, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_DOUBLE_QUOTE, _______, KC_SLASH, KC_Z, KC_X, KC_C, KC_V, _______, _______, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_RSFT, KC_LEFT_BRACKET, _______, _______, _______, _______, _______, _______, _______, _______, KC_RIGHT_BRACKET),
  [_NUM] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_AMPERSAND, KC_SEMICOLON, XXXXXXX, XXXXXXX, KC_KP_EQUAL, KC_AT, KC_NUM, XXXXXXX, KC_EXCLAIM, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_HASH, KC_GRAVE, KC_COLON, KC_KP_7, KC_KP_8, KC_KP_9, KC_PERCENT, XXXXXXX, QK_CAPS_WORD_TOGGLE, KC_CIRCUMFLEX, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_DOLLAR, KC_PIPE, KC_KP_MINUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_UNDERSCORE, LSFT_T(PG_LOCK), KC_LEFT_ANGLE_BRACKET, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_RIGHT_ANGLE_BRACKET, KC_TILDE, _______, _______, KC_KP_ASTERISK, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_SLASH, RSFT_T(PG_LOCK), QK_CLEAR_EEPROM, QK_BOOT, QK_MAKE, _______, _______, LT(_NAV, DF(_ERMAK)), _______, KC_KP_0, KC_KP_DOT, KC_COMMA),
  [_NAV] = LAYOUT(XXXXXXX, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, XXXXXXX, XXXXXXX, KC_MENU, XXXXXXX, KC_MS_WH_LEFT, KC_MS_WH_LEFT, KC_MS_UP, KC_MS_WH_RIGHT, KC_MS_WH_RIGHT, XXXXXXX, KC_BTN1, KC_UP, KC_BTN2, XXXXXXX, KC_PGUP, _______, KC_MS_WH_UP, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_UP, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, KC_PGDN, LSFT_T(PG_LOCK), KC_MS_WH_DOWN, KC_BTN3, KC_BTN2, KC_BTN1, KC_MS_WH_DOWN, _______, _______, XXXXXXX, PG_SEL, KC_UNDO, KC_AGAIN, XXXXXXX, RSFT_T(PG_LOCK), KC_BTN3, KC_BTN2, KC_BTN1, KC_DEL, LT(_NUM, DF(_ERMAK)), _______, _______, _______, _______, _______),
  [_MEDIA] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MEDIA_REWIND, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MEDIA_NEXT_TRACK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MEDIA_PREV_TRACK, XXXXXXX, KC_MEDIA_STOP, KC_MEDIA_NEXT_TRACK, XXXXXXX, LSFT_T(PG_LOCK), XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, KC_MUTE, KC_MEDIA_FAST_FORWARD, KC_MEDIA_PREV_TRACK, RSFT_T(PG_LOCK), XXXXXXX, _______, _______, _______, _______, _______, KC_MEDIA_PLAY_PAUSE, _______, _______, XXXXXXX),
  [_SYS] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WAKE, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP, XXXXXXX, XXXXXXX, LSFT_T(PG_LOCK), XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PWR, RSFT_T(PG_LOCK), XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX),
  [_LAYERS] = LAYOUT(KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, EH_LEFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_DVORAK), XXXXXXX, XXXXXXX, EH_RGHT, _______, XXXXXXX, XXXXXXX, DF(_ERMAK), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_TYPING), DF(_SYS), XXXXXXX, DF(_QWERTY), LSFT_T(PG_LOCK), DF(_GAMING), XXXXXXX, DF(_MELEE), XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, DF(_MEDIA), XXXXXXX, XXXXXXX, RSFT_T(PG_LOCK), XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX),
  [_MELEE] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JS_7, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_JUP, XXXXXXX, XXXXXXX, XXXXXXX, JS_6, JS_3, XXXXXXX, XXXXXXX, XXXXXXX, _______, JS_5, KC_JLEFT, KC_JDOWN, KC_JRIGHT, XXXXXXX, XXXXXXX, JS_1, JS_2, JS_4, XXXXXXX, XXXXXXX, LSFT_T(PG_LOCK), XXXXXXX, JS_8, JS_11, JS_9, JS_10, _______, _______, XXXXXXX, KC_CLEFT, KC_CDOWN, KC_CUP, KC_CRIGHT, RSFT_T(PG_LOCK), XXXXXXX, _______, _______, KC_JMOD, _______, _______, JS_0, XXXXXXX, XXXXXXX, XXXXXXX),
  
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NUM, _NAV, _LAYERS);
}

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
  JOYSTICK_AXIS_VIRTUAL, JOYSTICK_AXIS_VIRTUAL, // joystick
  JOYSTICK_AXIS_VIRTUAL, JOYSTICK_AXIS_VIRTUAL, // c-stick
};

static bool precision = false;
static uint16_t precision_mod = 64;
// static uint16_t axis_val = 127;
static uint16_t axis_val = 255;

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

  int16_t precision_val = axis_val;
  if (precision) {
    precision_val -= precision_mod;
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
    case L(KC_Q):
      if (!record->event.pressed) return false;
      if (is_caps_word_on()) add_weak_mods(MOD_MASK_SHIFT);
      tap_code16(KC_Q);
      if (!record->tap.count) {
        del_mods(MOD_MASK_SHIFT);
        tap_code16(KC_U);
      }
      return false;

    case KC_JUP:
      joystick_set_axis(1, record->event.pressed ? precision_val : 0);
      return false;
    case KC_JDOWN:
      joystick_set_axis(1, record->event.pressed ? -precision_val : 0);
      return false;
    case KC_JLEFT:
      joystick_set_axis(0, record->event.pressed ? -precision_val : 0);
      return false;
    case KC_JRIGHT:
      joystick_set_axis(0, record->event.pressed ? precision_val : 0);
      return false;
    case KC_JMOD:
      precision = record->event.pressed;
      return false;
    case KC_CUP:
      joystick_set_axis(3, record->event.pressed ? precision_val : 0);
      return false;
    case KC_CDOWN:
      joystick_set_axis(3, record->event.pressed ? -precision_val : 0);
      return false;
    case KC_CLEFT:
      joystick_set_axis(2, record->event.pressed ? -precision_val : 0);
      return false;
    case KC_CRIGHT:
      joystick_set_axis(2, record->event.pressed ? precision_val : 0);
      return false;
  }

  return true;
}

#if defined(OLED_ENABLE)

static void render_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0x70, 0xf0, 0xf0, 0xe0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf8, 0xfc, 0x3c, 0x3c, 0x3c, 0x7c, 0xf8, 0xf8, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x3f, 0x3f, 0x3f, 0x7c, 0x78, 0xf8, 0xf8, 0xf0, 0xe0, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0x3c, 0x1c, 0x1e, 0x1e, 0x3c, 0xfc, 0xf8, 0xf0, 0xc0, 0x00, 0x1c, 0x1c, 0xff, 0xff, 0xff, 0xff, 0x1c, 0x1c, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0xfc, 0xce, 0xce, 0xce, 0xdc, 0xfc, 0xfc, 0xf8, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x1e, 0x1e, 0x1e, 0x3c, 0x3c, 0x3c, 0x3e, 0x1f, 0x1f, 0x0f, 0x07, 0x01, 0x00, 0x01, 0x07,
    0x0f, 0x1f, 0x1e, 0x3c, 0x3c, 0x3c, 0x1e, 0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f, 0x3c, 0x38, 0x38, 0x3c, 0x1c, 0x1c, 0x0c, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0x06, 0x06, 0x06, 0x0e, 0x9e, 0xfc, 0xf8, 0x00, 0x00, 0x8e, 0x8e, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x7c, 0xfe, 0xff, 0x83, 0x01, 0x01, 0x01, 0x83, 0x83, 0x00, 0x00, 0x7e, 0xff, 0xc7, 0x83, 0x01, 0x01, 0x01,
    0x83, 0xff, 0xff, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc3, 0xe3, 0xe0, 0xe0, 0xe0, 0xf0, 0x70, 0x70, 0x70, 0x70, 0x30, 0x33, 0x73, 0xe0, 0x60, 0xe0, 0xe0, 0xc0, 0xc1, 0x83, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x70, 0x30, 0x70, 0x70, 0x70, 0x70, 0x70, 0xf0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0xff, 0xf8, 0xd0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x20, 0x20, 0x40, 0xc0, 0x80, 0x00, 0x01, 0x87, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xff, 0xff, 0x03, 0x01, 0x00, 0x80, 0xc0, 0x40, 0x20, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0xf0, 0xf8, 0x7f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x1c, 0x1c, 0x38, 0x78, 0x60, 0x60, 0x60, 0x60, 0x60, 0x70, 0x38, 0x39, 0xdf, 0xef, 0xf7, 0x7b, 0x39, 0x1c, 0x1c, 0x0e, 0x0e, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0e, 0x0e, 0x1e, 0x1c, 0x3c, 0x79, 0xfb, 0xf7, 0xef, 0x9f, 0x38, 0x30, 0x70, 0x60, 0x60, 0x60, 0x60, 0x70, 0x38, 0x3c, 0x1c, 0x0f, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0xfc, 0x7e, 0x7f, 0xff, 0xff, 0xe3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0xff, 0x7f, 0x7f, 0x3f, 0x7c, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7f, 0xff, 0x81, 0x00, 0x00, 0x00, 0x00, 0x01, 0xcf, 0xff, 0xfe, 0x7c, 0x78, 0x78, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x78, 0x78, 0x7c, 0xfe, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x0e, 0x1e, 0x3f, 0x7f, 0xf1, 0xe0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe1, 0xf3, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };
  // oled_write_P(qmk_logo, false);
  oled_write_raw_P(qmk_logo, sizeof(qmk_logo));
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
    case _MELEE:
      oled_write_P(PSTR("melee"), false);
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
    case _MELEE:
      oled_write_P(PSTR("melee"), false);
      break;
    default:
      oled_write_P(PSTR("UNKNOWN"), false);
      break;
  }

  oled_write_P(PSTR("\n\n\n"), false);
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

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_ERMAK]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(XXXXXXX, DF(_DVORAK)) },
  [_DVORAK] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(DF(_ERMAK), DF(_QWERTY)) },
  [_QWERTY] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(DF(_DVORAK), XXXXXXX) },

  [_GAMING] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_LAYERS] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_MEDIA]  = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_MELEE]  = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_NAV]    = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_NUM]    = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_SYS]    = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_TYPING] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif

