// Copyright 2024 Ross Hadden (@rosshadden)
// Copyright 2024 Ryan Neff (@JellyTitan)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "print.h"
#include QMK_KEYBOARD_H

#include "features/achordion.h"
#include "features/custom_shift_keys.h"
#include "features/layer_lock.h"
#include "features/select_word.h"

#define BASE DF(_ENGRAM)
#define L(kc) LT(0, kc)
#define DQ KC_RIGHT_PAREN

enum sofle_layers {
  _ENGRAM,
  _ERMAK,
  _DOTA,
  _LAB,
  _DVORAK,
  _QWERTY,
  _GAMEPAD,
  _GAMING,
  _MEDIA,
  _SYS,
  _META,
  _ARROW,
  _NUM,
  _NAV,
  _LAYERS,
  
};

enum custom_keycodes {
  PG_LOCK = SAFE_RANGE, PG_SEL,
  KC_HRM,
  KC_HRMU,
  KC_RSPC,
  JS_L_LEFT,
  JS_L_RIGHT,
  JS_L_DOWN,
  JS_L_UP,
  JS_L_MOD,
  JS_L_LOCK,
  JS_R_LEFT,
  JS_R_RIGHT,
  JS_R_DOWN,
  JS_R_UP,
  JS_R_MOD,
  KC_MQL,
  KC_MQR,
  
};

const custom_shift_key_t custom_shift_keys[] = {
  { KC_0, KC_ASTERISK },
  { KC_1, KC_BACKSLASH },
  { KC_2, KC_EQUAL },
  { KC_3, KC_TILDE },
  { KC_4, KC_PLUS },
  { KC_5, KC_LEFT_ANGLE_BRACKET },
  { KC_6, KC_RIGHT_ANGLE_BRACKET },
  { KC_7, KC_CIRCUMFLEX },
  { KC_8, KC_AMPERSAND },
  { KC_9, KC_PERCENT },
  { KC_QUOTE, KC_LEFT_PAREN },
  { L(KC_QUOTE), KC_LEFT_PAREN },
  { KC_GRAVE, KC_DOLLAR },
  { KC_HASH, KC_AT },
  { LCTL_T(KC_HASH), KC_AT },
  { KC_COMMA, KC_SEMICOLON },
  { KC_DOT, KC_COLON },
  { KC_QUESTION, KC_EXCLAIM },
  { RCTL_T(KC_QUESTION), KC_EXCLAIM },
  { KC_SLASH, KC_PIPE },
  { L(KC_SLASH), KC_PIPE },
  { RGUI_T(KC_SLASH), KC_PIPE },
  { KC_DOUBLE_QUOTE, KC_RIGHT_PAREN },
  { L(DQ), KC_RIGHT_PAREN },
  
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ENGRAM] = LAYOUT(KC_LEFT_BRACKET, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_RIGHT_BRACKET, KC_GRAVE, KC_B, KC_Y, KC_O, KC_U, KC_QUOTE, KC_DOUBLE_QUOTE, KC_L, KC_D, KC_W, KC_V, KC_Z, LCTL_T(KC_ESC), KC_C, KC_I, KC_E, KC_A, KC_COMMA, KC_DOT, KC_H, KC_T, KC_S, KC_N, KC_Q, KC_LSFT, KC_G, KC_X, KC_J, KC_K, LGUI_T(KC_MINUS), KC_MUTE, KC_F20, RGUI_T(KC_SLASH), KC_R, KC_M, KC_F, KC_P, KC_RSFT, LCTL_T(KC_HASH), LGUI_T(KC_NO), LALT_T(KC_NO), KC_BACKSPACE, LT(_NUM, KC_TAB), LT(_NAV, KC_ENTER), KC_SPACE, RGUI_T(KC_NO), RALT_T(KC_NO), RCTL_T(KC_QUESTION)),
  [_ERMAK] = LAYOUT(L(KC_LEFT_BRACKET), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, L(KC_QUOTE), L(DQ), _______, _______, _______, _______, _______, _______, LGUI_T(KC_C), LALT_T(KC_I), LCTL_T(KC_E), LSFT_T(KC_A), _______, _______, RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_S), RGUI_T(KC_N), L(KC_Q), OSM(MOD_LSFT), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, OSM(MOD_RSFT), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
  [_DOTA] = LAYOUT(KC_ESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TAB, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RSFT, KC_F1, KC_F2, KC_BACKSPACE, KC_LALT, SH_T(KC_TAB), _______, _______, _______, _______, _______),
  [_LAB] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LGUI_T(_______), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
  [_DVORAK] = LAYOUT(KC_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BACKSLASH, KC_EQUAL, KC_QUOTE, KC_COMMA, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLASH, _______, LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U), KC_I, KC_D, RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_N), RGUI_T(KC_S), KC_MINUS, _______, KC_SEMICOLON, KC_Q, KC_J, KC_K, KC_X, _______, BASE, KC_B, KC_M, KC_W, KC_V, KC_Z, _______, LCTL_T(KC_LEFT_BRACKET), _______, _______, _______, _______, _______, _______, _______, _______, RCTL_T(KC_RIGHT_BRACKET)),
  [_QWERTY] = LAYOUT(KC_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BACKSLASH, KC_EQUAL, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS, _______, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SEMICOLON), KC_QUOTE, _______, KC_Z, KC_X, KC_C, KC_V, KC_B, _______, _______, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, _______, LCTL_T(KC_LEFT_BRACKET), _______, _______, _______, _______, _______, _______, _______, _______, RCTL_T(KC_RIGHT_BRACKET)),
  [_GAMEPAD] = LAYOUT(JS_15, JS_17, XXXXXXX, JS_L_LOCK, XXXXXXX, JS_8, JS_10, XXXXXXX, XXXXXXX, XXXXXXX, JS_16, JS_14, XXXXXXX, JS_8, XXXXXXX, JS_L_UP, XXXXXXX, JS_9, JS_11, JS_7, JS_R_UP, JS_6, JS_10, XXXXXXX, JS_12, JS_L_MOD, JS_L_LEFT, JS_L_DOWN, JS_L_RIGHT, JS_12, JS_13, JS_R_LEFT, JS_R_DOWN, JS_R_RIGHT, JS_R_MOD, JS_13, KC_LSFT, JS_9, JS_0, JS_1, JS_2, JS_3, _______, _______, JS_6, JS_4, JS_7, JS_5, JS_11, KC_RSFT, JS_10, JS_12, JS_9, JS_8, _______, _______, JS_10, JS_11, JS_13, JS_8),
  [_GAMING] = LAYOUT(KC_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BACKSLASH, KC_EQUAL, KC_P, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_MINUS, _______, KC_SEMICOLON, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOTE, KC_LSFT, KC_SLASH, KC_Z, KC_X, KC_C, KC_V, _______, _______, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_RSFT, LCTL_T(KC_LEFT_BRACKET), KC_LGUI, KC_LALT, KC_SPACE, _______, _______, KC_BACKSPACE, KC_RGUI, KC_RALT, RCTL_T(KC_RIGHT_BRACKET)),
  [_MEDIA] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MEDIA_REWIND, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MEDIA_NEXT_TRACK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BASE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MEDIA_PREV_TRACK, XXXXXXX, KC_MEDIA_STOP, KC_MEDIA_NEXT_TRACK, XXXXXXX, LSFT_T(PG_LOCK), XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, _______, _______, XXXXXXX, KC_F20, KC_MUTE, KC_MEDIA_FAST_FORWARD, KC_MEDIA_PREV_TRACK, RSFT_T(PG_LOCK), _______, _______, _______, _______, _______, _______, KC_MEDIA_PLAY_PAUSE, _______, _______, _______),
  [_SYS] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WAKE, XXXXXXX, XXXXXXX, BASE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP, XXXXXXX, XXXXXXX, LSFT_T(PG_LOCK), XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PWR, RSFT_T(PG_LOCK), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
  [_META] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BASE, KC_CLEAR, XXXXXXX, QK_CLEAR_EEPROM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LSFT_T(PG_LOCK), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, QK_REBOOT, QK_MAKE, XXXXXXX, XXXXXXX, RSFT_T(PG_LOCK), _______, _______, _______, _______, _______, _______, QK_BOOT, _______, _______, _______),
  [_ARROW] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX, BASE, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, LSFT_T(PG_LOCK), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RSFT_T(PG_LOCK), _______, _______, _______, _______, _______, _______, KC_RSPC, _______, _______, _______),
  [_NUM] = LAYOUT(SH_TOGG, KC_F1, KC_F2, KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET, KC_TILDE, KC_SEMICOLON, KC_INS, XXXXXXX, KC_KP_EQUAL, KC_AT, SH_TOGG, KC_PIPE, KC_CIRCUMFLEX, KC_HASH, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_DOLLAR, KC_COLON, KC_KP_7, KC_KP_8, KC_KP_9, KC_PERCENT, QK_LOCK, QK_CAPS_WORD_TOGGLE, KC_COLON, KC_EQUAL, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_AMPERSAND, KC_KP_MINUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_UNDERSCORE, LSFT_T(PG_LOCK), KC_EXCLAIM, KC_SEMICOLON, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_UNDERSCORE, _______, KC_NUM, KC_KP_SLASH, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ASTERISK, RSFT_T(PG_LOCK), _______, _______, _______, _______, _______, LT(_NAV, BASE), _______, KC_KP_0, KC_KP_DOT, KC_COMMA),
  [_NAV] = LAYOUT(SH_TOGG, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, XXXXXXX, KC_MQL, KC_BTN3, KC_MQR, KC_AGAIN, SH_TOGG, KC_F11, KC_MS_WH_LEFT, KC_BTN2, KC_MS_UP, KC_BTN1, KC_MS_WH_RIGHT, XXXXXXX, KC_BTN1, KC_UP, KC_BTN2, XXXXXXX, KC_UNDO, _______, KC_BTN1, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_BTN1, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, PG_SEL, LSFT_T(PG_LOCK), KC_BTN2, _______, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_BTN2, _______, _______, XXXXXXX, KC_PGUP, KC_PGDN, KC_MENU, XXXXXXX, RSFT_T(PG_LOCK), KC_BTN3, KC_BTN2, KC_BTN1, KC_DEL, LT(_NUM, BASE), _______, _______, _______, _______, _______),
  [_LAYERS] = LAYOUT(KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, EH_LEFT, BASE, XXXXXXX, XXXXXXX, XXXXXXX, DT_UP, XXXXXXX, DF(_LAB), TO(_DOTA), XXXXXXX, DF(_DVORAK), EH_RGHT, KC_CAPS, TG(_GAMEPAD), XXXXXXX, DF(_ENGRAM), XXXXXXX, DT_PRNT, XXXXXXX, KC_HRM, TO(_ENGRAM), TG(_SYS), XXXXXXX, DF(_QWERTY), LSFT_T(PG_LOCK), TG(_GAMING), XXXXXXX, XXXXXXX, XXXXXXX, DT_DOWN, _______, _______, XXXXXXX, KC_HRMU, TG(_MEDIA), XXXXXXX, XXXXXXX, RSFT_T(PG_LOCK), _______, _______, _______, _______, _______, _______, TG(_META), _______, _______, _______),
  
};

layer_state_t layer_state_set_user(layer_state_t state) {
  uprintf("%d\n", state);
  // only trilayer if no layer is locked
  if (is_layer_locked(get_highest_layer(layer_state))) return state;
  return update_tri_layer_state(state, _NUM, _NAV, _LAYERS);
}

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
  JOYSTICK_AXIS_VIRTUAL, JOYSTICK_AXIS_VIRTUAL, // left stick
  JOYSTICK_AXIS_VIRTUAL, JOYSTICK_AXIS_VIRTUAL, // right stick
};
struct {
  bool up;
  bool down;
  bool left;
  bool right;
  bool mod;
  bool lock;
  int16_t value;
  int16_t x;
  int16_t y;
} left_stick, right_stick;
static uint16_t precision_mod = 75;
static uint16_t axis_val = 127;

void keyboard_post_init_user() {
  // Apply layer on startup
  layer_move(_ERMAK);
}

/* bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   if (get_highest_layer(layer_state) == _ENGRAM) { */
/*     if (record->event.key.row == 2) { */
/*       if (record->event.key.col == 1) { */
/*         if (record->event.pressed) { */
/*           register_code16(KC_LGUI); */
/*         } else { */
/*           unregister_code16(KC_LGUI); */
/*         } */
/*         return false; */
/*       } */
/*     } */
/*   } */
/*   return true; */
/* } */

const uint8_t rows = MATRIX_ROWS / 2;
bool hrm = true;
uint8_t hrm_row = 2;
bool process_hrm(uint16_t keycode, keyrecord_t *record) {
  if (keycode == KC_HRM && record->event.pressed) {
    hrm = !hrm;
    return false;
  } else if (keycode == KC_HRMU && record->event.pressed) {
    hrm_row = (hrm_row + 1) % rows;
    return false;
  }

  if (!hrm || hrm_row != 2) {
    switch (keycode) {
      case LGUI_T(KC_C):
        if (record->tap.count) return true;
        if (record->event.pressed) {
          register_code(KC_C);
        } else {
          unregister_code(KC_C);
        }
        return false;
      case LALT_T(KC_I):
        if (record->tap.count) return true;
        if (record->event.pressed) {
          register_code(KC_I);
        } else {
          unregister_code(KC_I);
        }
        return false;
      case LCTL_T(KC_E):
        if (record->tap.count) return true;
        if (record->event.pressed) {
          register_code(KC_E);
        } else {
          unregister_code(KC_E);
        }
        return false;
      case LSFT_T(KC_A):
        if (record->tap.count) return true;
        if (record->event.pressed) {
          register_code(KC_A);
        } else {
          unregister_code(KC_A);
        }
        return false;
      case RSFT_T(KC_H):
        if (record->tap.count) return true;
        if (record->event.pressed) {
          register_code(KC_H);
        } else {
          unregister_code(KC_H);
        }
        return false;
      case RCTL_T(KC_T):
        if (record->tap.count) return true;
        if (record->event.pressed) {
          register_code(KC_T);
        } else {
          unregister_code(KC_T);
        }
        return false;
      case RALT_T(KC_S):
        if (record->tap.count) return true;
        if (record->event.pressed) {
          register_code(KC_S);
        } else {
          unregister_code(KC_S);
        }
        return false;
      case RGUI_T(KC_N):
        if (record->tap.count) return true;
        if (record->event.pressed) {
          register_code(KC_N);
        } else {
          unregister_code(KC_N);
        }
        return false;
    }
  }

  return true;
}

uint16_t hrm_timeout(uint16_t keycode, uint16_t timeout) {
  if (!hrm || hrm_row != 2) {
    switch (keycode) {
      case LGUI_T(KC_C):
      case LGUI_T(KC_COMMA):
      case LALT_T(KC_I):
      case LCTL_T(KC_E):
      case LSFT_T(KC_A):
      case RSFT_T(KC_H):
      case RCTL_T(KC_T):
      case RALT_T(KC_S):
      case RGUI_T(KC_N):
      case RGUI_T(KC_DOT):
        return 0;
    }
  }
  return timeout;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) return false;
  if (!process_layer_lock(keycode, record, PG_LOCK)) return false;
  if (!process_select_word(keycode, record, PG_SEL)) return false;
  if (!process_hrm(keycode, record)) return false;

  switch (get_highest_layer(default_layer_state)) {
    case _ENGRAM:
      if (!process_custom_shift_keys(keycode, record)) return false;
  }

  left_stick.value = (left_stick.mod) ? precision_mod : axis_val;
  right_stick.value = (right_stick.mod) ? precision_mod : axis_val;

  switch (keycode) {
    // keys
    case KC_CLEAR:
      if (!record->event.pressed) return false;
      clear_mods();
      break;
    case KC_RSPC:
      if (!record->event.pressed) return false;
      tap_code16(KC_SPACE);
      tap_code16(KC_LEFT);
      break;

    // modifiers
    case LSFT_T(PG_LOCK):
    case RSFT_T(PG_LOCK):
      if (record->event.pressed && record->tap.count) {
        layer_lock_invert(get_highest_layer(layer_state));
        return false;
      }
      break;
    case LCTL_T(KC_HASH):
      if (record->event.pressed && record->tap.count) {
        tap_code16(KC_HASH);
        return false;
      }
      break;
    case RCTL_T(KC_QUESTION):
      if (record->event.pressed && record->tap.count) {
        tap_code16(KC_QUESTION);
        return false;
      }
      break;

    // layers
    case BASE:
      if (record->event.pressed) {
        default_layer_set(_ENGRAM);
        layer_move(_ERMAK);
        return false;
      }
      break;
    case LT(_NUM, BASE):
    case LT(_NAV, BASE):
      if (record->event.pressed && record->tap.count) {
        default_layer_set(_ENGRAM);
        layer_move(_ERMAK);
        return false;
      }
      break;
    case SH_T(KC_TAB):
      // make base reset work as expected
      if (
        record->event.pressed
        && !is_swap_hands_on()
      ) {
        swap_hands_on();
        default_layer_set(_ENGRAM);
        layer_move(_ERMAK);
        return false;
      }
      return true;
      break;

    // lingers
    case L(KC_LEFT_BRACKET):
      if (!record->event.pressed || record->tap.count) return true;
      tap_code16(KC_LEFT_BRACKET);
      tap_code16(KC_RIGHT_BRACKET);
      del_mods(MOD_MASK_SHIFT);
      tap_code16(KC_LEFT);
      return false;
    case L(KC_QUOTE):
      if (!record->event.pressed || record->tap.count) return true;
      if (get_mods() & MOD_MASK_SHIFT) {
        tap_code16(KC_LEFT_PAREN);
        tap_code16(KC_RIGHT_PAREN);
        del_mods(MOD_MASK_SHIFT);
        tap_code16(KC_LEFT);
      } else {
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
        del_mods(MOD_MASK_SHIFT);
        tap_code16(KC_LEFT);
      }
      return false;
    case L(KC_MINUS):
      if (!record->event.pressed || record->tap.count) return true;
      if (get_mods() & MOD_MASK_SHIFT) {
        tap_code16(KC_UNDERSCORE);
        tap_code16(KC_UNDERSCORE);
        del_mods(MOD_MASK_SHIFT);
        tap_code16(KC_LEFT);
      } else {
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
        del_mods(MOD_MASK_SHIFT);
        tap_code16(KC_LEFT);
      }
      return false;
    case L(KC_SLASH):
      if (!record->event.pressed || record->tap.count) return true;
      if (get_mods() & MOD_MASK_SHIFT) {
        tap_code16(KC_PIPE);
        tap_code16(KC_PIPE);
        del_mods(MOD_MASK_SHIFT);
        tap_code16(KC_LEFT);
      } else {
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
        del_mods(MOD_MASK_SHIFT);
        tap_code16(KC_LEFT);
      }
      return false;
    case L(DQ):
      // TODO: avoid manually custom shifting
      if (!record->event.pressed) return true;
      if (record->tap.count) {
        if (get_mods() & MOD_MASK_SHIFT) {
          return true;
        } else {
          tap_code16(KC_DOUBLE_QUOTE);
        }
      } else {
        if (get_mods() & MOD_MASK_SHIFT) {
          tap_code16(KC_RIGHT_PAREN);
        } else {
          tap_code16(KC_DOUBLE_QUOTE);
          tap_code16(KC_DOUBLE_QUOTE);
          del_mods(MOD_MASK_SHIFT);
          tap_code16(KC_LEFT);
        }
      }
      return false;
    case L(KC_Q):
      if (!record->event.pressed) return true;
      if (is_caps_word_on()) add_weak_mods(MOD_MASK_SHIFT);
      tap_code16(KC_Q);
      if (!record->tap.count) {
        del_mods(MOD_MASK_SHIFT);
        tap_code16(KC_U);
      }
      return false;

    // apps
    case LGUI_T(KC_NO):
    case RGUI_T(KC_NO):
      if (record->event.pressed && record->tap.count) {
        // hyprland
        tap_code16(LAG(KC_SPACE));
        return false;
      }
      break;
    case LALT_T(KC_NO):
    case RALT_T(KC_NO):
      if (record->event.pressed && record->tap.count) {
        // wezterm
        tap_code16(C(KC_SPACE));
        return false;
      }
      break;

    // mouse
    case KC_MQL:
      if (record->event.pressed) {
        register_code(KC_MS_ACCEL2);
        register_code(KC_MS_LEFT);
      } else {
        unregister_code(KC_MS_LEFT);
        unregister_code(KC_MS_ACCEL2);
      }
      break;
    case KC_MQR:
      if (record->event.pressed) {
        register_code(KC_MS_ACCEL2);
        register_code(KC_MS_RIGHT);
      } else {
        unregister_code(KC_MS_RIGHT);
        unregister_code(KC_MS_ACCEL2);
      }
      break;

    // joystick
    case JS_L_LEFT:
      left_stick.left = record->event.pressed || left_stick.lock;
      left_stick.x = (record->event.pressed) ? -left_stick.value : 0;
      if (left_stick.right) {
        left_stick.x = (record->event.pressed) ? 0 : left_stick.value;
      }
      joystick_set_axis(0, left_stick.x);
      return false;
    case JS_L_RIGHT:
      left_stick.right = record->event.pressed || left_stick.lock;
      left_stick.x = (record->event.pressed) ? left_stick.value : 0;
      if (left_stick.left) {
        left_stick.x = (record->event.pressed) ? 0 : -left_stick.value;
      }
      joystick_set_axis(0, left_stick.x);
      return false;
    case JS_L_DOWN:
      left_stick.down = record->event.pressed || left_stick.lock;
      left_stick.y = (record->event.pressed) ? -left_stick.value : 0;
      if (left_stick.up) {
        left_stick.y = (record->event.pressed) ? 0 : left_stick.value;
      }
      joystick_set_axis(1, left_stick.y);
      return false;
    case JS_L_UP:
      if (left_stick.lock) return false;
      left_stick.up = record->event.pressed;
      left_stick.y = (record->event.pressed) ? left_stick.value : 0;
      if (left_stick.down) {
        left_stick.y = (record->event.pressed) ? 0 : -left_stick.value;
      }
      joystick_set_axis(1, left_stick.y);
      return false;
    case JS_L_MOD:
      left_stick.mod = record->event.pressed;
      if (left_stick.x < 0) {
        joystick_set_axis(0, (record->event.pressed) ? -precision_mod : -axis_val);
      } else if (left_stick.x > 0) {
        joystick_set_axis(0, (record->event.pressed) ? precision_mod : axis_val);
      }
      if (left_stick.y < 0) {
        joystick_set_axis(1, (record->event.pressed) ? -precision_mod : -axis_val);
      } else if (left_stick.y > 0) {
        joystick_set_axis(1, (record->event.pressed) ? precision_mod : axis_val);
      }
      return false;
    case JS_L_LOCK:
      if (record->event.pressed) {
        left_stick.lock = record->tap.count == 1;
      }
      return false;
    //
    case JS_R_LEFT:
      right_stick.left = record->event.pressed;
      right_stick.x = (record->event.pressed) ? -right_stick.value : 0;
      if (right_stick.right) {
        right_stick.x = (record->event.pressed) ? 0 : right_stick.value;
      }
      joystick_set_axis(2, right_stick.x);
      return false;
    case JS_R_RIGHT:
      right_stick.right = record->event.pressed;
      right_stick.x = (record->event.pressed) ? right_stick.value : 0;
      if (right_stick.left) {
        right_stick.x = (record->event.pressed) ? 0 : -right_stick.value;
      }
      joystick_set_axis(2, right_stick.x);
      return false;
    case JS_R_DOWN:
      right_stick.down = record->event.pressed;
      right_stick.y = (record->event.pressed) ? -right_stick.value : 0;
      if (right_stick.up) {
        right_stick.y = (record->event.pressed) ? right_stick.value : 0;
      }
      joystick_set_axis(3, right_stick.y);
      return false;
    case JS_R_UP:
      right_stick.up = record->event.pressed;
      right_stick.y = (record->event.pressed) ? right_stick.value : 0;
      if (right_stick.down) {
        right_stick.y = (record->event.pressed) ? -right_stick.value : 0;
      }
      joystick_set_axis(3, right_stick.y);
      return false;
    case JS_R_MOD:
      right_stick.mod = record->event.pressed;
      if (right_stick.x < 0) {
        joystick_set_axis(2, (record->event.pressed) ? -precision_mod : -axis_val);
      } else if (right_stick.x > 0) {
        joystick_set_axis(2, (record->event.pressed) ? precision_mod : axis_val);
      }
      if (right_stick.y < 0) {
        joystick_set_axis(3, (record->event.pressed) ? -precision_mod : -axis_val);
      } else if (right_stick.y > 0) {
        joystick_set_axis(3, (record->event.pressed) ? precision_mod : axis_val);
      }
      return false;
  }

  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
  switch (tap_hold_keycode) {
    case LGUI_T(KC_C):
      if (other_keycode == LCTL_T(KC_ESC) || other_keycode == KC_ESC || other_keycode == KC_G) return true;
      break;
    case LGUI_T(KC_MINUS):
      if (other_keycode == LCTL_T(KC_ESC) || other_keycode == LGUI_T(KC_C) || other_keycode == KC_ESC || other_keycode == KC_C || other_keycode == KC_G || other_keycode == KC_I) return true;
      break;
    case LALT_T(KC_I):
      if (other_keycode == LGUI_T(KC_C) || other_keycode == LSFT_T(KC_A) || other_keycode == KC_B || other_keycode == KC_G || other_keycode == KC_J || other_keycode == KC_K || other_keycode == KC_U || other_keycode == KC_X || other_keycode == L(KC_MINUS) || other_keycode == KC_COMMA || other_keycode == L(KC_QUOTE) || other_keycode == KC_GRAVE) return true;
      break;
    case LCTL_T(KC_E):
      if (other_keycode == LGUI_T(KC_C)) return true;
      break;
    case LSFT_T(KC_A):
      if (other_keycode == KC_GRAVE || other_keycode == KC_DOT || other_keycode == RGUI_T(KC_SLASH) || other_keycode == KC_SLASH) return true;
      break;
    case RSFT_T(KC_H):
      if (other_keycode == KC_COMMA || other_keycode == LGUI_T(KC_MINUS) || other_keycode == KC_MINUS) return true;
      break;
    case RCTL_T(KC_T):
      if (other_keycode == L(KC_Q) || other_keycode == KC_V || other_keycode == KC_W || other_keycode == KC_Z) return true;
      break;
    case RALT_T(KC_S):
      if (other_keycode == L(KC_Q)) return true;
      break;
    case RGUI_T(KC_N):
      if (other_keycode == RSFT_T(KC_H) || other_keycode == KC_F || other_keycode == KC_L || other_keycode == KC_P) return true;
      break;
    case RGUI_T(KC_SLASH):
      if (other_keycode == RSFT_T(KC_H) || other_keycode == RGUI_T(KC_N) || other_keycode == KC_N || other_keycode == KC_F || other_keycode == KC_L || other_keycode == KC_P || other_keycode == KC_S || other_keycode == KC_W) return true;
      break;
  }

  const uint8_t row = other_record->event.key.row % (MATRIX_ROWS / 2);
  if (row == 0 || row == 4) return true;

  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case LALT_T(KC_NO):
    case RALT_T(KC_NO):
    case LGUI_T(KC_NO):
    case RGUI_T(KC_NO):
    case LCTL_T(KC_ESC):
    case LCTL_T(KC_HASH):
    case RCTL_T(KC_QUESTION):
    case LT(_NAV, BASE):
    case LT(_NAV, KC_ENTER):
    case LT(_NUM, BASE):
    case LT(_NUM, KC_TAB):
      return 0;
  }

  return hrm_timeout(tap_hold_keycode, 800);
}

bool achordion_eager_mod(uint8_t mod) {
  return !hrm;
}

#if defined(SWAP_HANDS_ENABLE)
__attribute__ ((weak))
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  // Left
  { {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5} },
  { {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6} },
  { {0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7} },
  { {0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8} },
  { {0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9} },
  // Right
  { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0} },
  { {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1} },
  { {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2} },
  { {0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3} },
  { {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4} },
};
#endif
#if defined(SWAP_HANDS_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint8_t PROGMEM encoder_hand_swap_config[NUM_ENCODERS] = { 0, 1 };
#endif

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
  oled_write_raw_P(qmk_logo, sizeof(qmk_logo));

  // static const char PROGMEM tux[] = {
  //   153,154,10,
  //   185,186,0,
  // };
  // oled_write_P(tux, false);
}

static void render_status(void) {
  oled_write_P(PSTR(" Keebler   v0.8.0   "), true);
  oled_write_P(PSTR("~~~~~~~~~~"), false);

  led_t led_state = host_keyboard_led_state();
  if (led_state.num_lock) oled_write_P(PSTR("NUM "), false);
  if (led_state.caps_lock) oled_write_P(PSTR("CAP "), false);
  if (is_caps_word_on()) oled_write_P(PSTR("CAPW "), false);
  if (led_state.scroll_lock) oled_write_P(PSTR("SCR "), false);
  if (is_swap_hands_on()) oled_write_P(PSTR("SWP "), false);
  oled_write_ln_P(PSTR(""), false);

  oled_write_P(PSTR("\n\nLAYER:\n  "), false);
  switch (get_highest_layer(default_layer_state)) {
    case _ENGRAM:
      oled_write_P(PSTR("engram"), false);
      break;
    case _ERMAK:
      oled_write_P(PSTR("ermak"), false);
      break;
    case _DOTA:
      oled_write_P(PSTR("dota"), false);
      break;
    case _LAB:
      oled_write_P(PSTR("lab"), false);
      break;
    case _DVORAK:
      oled_write_P(PSTR("dvorak"), false);
      break;
    case _QWERTY:
      oled_write_P(PSTR("qwerty"), false);
      break;
    case _GAMEPAD:
      oled_write_P(PSTR("gamepad"), false);
      break;
    case _GAMING:
      oled_write_P(PSTR("gaming"), false);
      break;
    case _MEDIA:
      oled_write_P(PSTR("media"), false);
      break;
    case _SYS:
      oled_write_P(PSTR("sys"), false);
      break;
    case _META:
      oled_write_P(PSTR("meta"), false);
      break;
    case _ARROW:
      oled_write_P(PSTR("arrow"), false);
      break;
    case _NUM:
      oled_write_P(PSTR("num"), false);
      break;
    case _NAV:
      oled_write_P(PSTR("nav"), false);
      break;
    case _LAYERS:
      oled_write_P(PSTR("layers"), false);
      break;
    default:
      oled_write_P(PSTR("UNKNOWN"), false);
      break;
  }

  oled_write_P(PSTR("\nSTATE:\n  "), false);
  switch (get_highest_layer(layer_state)) {
    case _ENGRAM:
      oled_write_P(PSTR("engram"), false);
      break;
    case _ERMAK:
      oled_write_P(PSTR("ermak"), false);
      break;
    case _DOTA:
      oled_write_P(PSTR("dota"), false);
      break;
    case _LAB:
      oled_write_P(PSTR("lab"), false);
      break;
    case _DVORAK:
      oled_write_P(PSTR("dvorak"), false);
      break;
    case _QWERTY:
      oled_write_P(PSTR("qwerty"), false);
      break;
    case _GAMEPAD:
      oled_write_P(PSTR("gamepad"), false);
      break;
    case _GAMING:
      oled_write_P(PSTR("gaming"), false);
      break;
    case _MEDIA:
      oled_write_P(PSTR("media"), false);
      break;
    case _SYS:
      oled_write_P(PSTR("sys"), false);
      break;
    case _META:
      oled_write_P(PSTR("meta"), false);
      break;
    case _ARROW:
      oled_write_P(PSTR("arrow"), false);
      break;
    case _NUM:
      oled_write_P(PSTR("num"), false);
      break;
    case _NAV:
      oled_write_P(PSTR("nav"), false);
      break;
    case _LAYERS:
      oled_write_P(PSTR("layers"), false);
      break;
    default:
      oled_write_P(PSTR("UNKNOWN"), false);
      break;
  }

  oled_write_ln_P(PSTR("\n\n"), false);

  char hrm_str[4];
  snprintf(hrm_str, sizeof(hrm_str), "%d", hrm_row);
  oled_write_P(PSTR("  HRM: "), false);
  if (hrm) {
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR(hrm_str), false);
  } else {
    oled_write_P(PSTR("OFF"), false);
  }

  oled_write_ln_P(PSTR("\n"), false);
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
  [_ENGRAM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(TG(_GAMEPAD), TG(_GAMING)) },
  [_ERMAK] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_DOTA] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_LAB] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_DVORAK] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_QWERTY] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_GAMEPAD] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_GAMING] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_MEDIA] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_SYS] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_META] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_ARROW] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_NUM] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_NAV] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_LAYERS] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  
};
#endif

