// Copyright 2024 Ross Hadden (@rosshadden)
// Copyright 2024 Ryan Neff (@JellyTitan)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "features/custom_shift_keys.h"

#define L(kc) LT(0, kc)

enum sofle_layers {
  {% for layer in layers -%}
    {{ layer.id }},
  {% endfor %}
};

// enum custom_keycodes {
// };

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

// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// const key_override_t **key_overrides = (const key_override_t *[]){
//   &delete_key_override,
//   NULL
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  {% for layer in layers -%}
    [{{ layer.id }}] = {{ layer.keymap }},
  {% endfor %}
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NUM, _NAV, _LEGACY);
}

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (
    get_highest_layer(default_layer_state) == _ERMAK &&
    get_highest_layer(layer_state) == _ERMAK &&
    !process_custom_shift_keys(keycode, record)
  ) {
    return false;
  }

  switch (keycode) {
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
  oled_write_P(PSTR("{{ firmware | capitalize }}\n{{ version }}\n~~~~~~~~~"), false);

  oled_write_P(PSTR("\nLAYER:\n\t"), false);
  switch (get_highest_layer(default_layer_state)) {
    {% for layer in layers -%}
    case {{ layer.id }}:
      oled_write_P(PSTR("{{ layer.name }}"), false);
      break;
    {% endfor -%}
    default:
      oled_write_P(PSTR("UNKNOWN"), false);
      break;
  }

  oled_write_P(PSTR("\nOVERLAY:\n\t"), false);
  switch (get_highest_layer(layer_state)) {
    {% for layer in layers -%}
    case {{ layer.id }}:
      oled_write_P(PSTR("{{ layer.name }}"), false);
      break;
    {% endfor -%}
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
