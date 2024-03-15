// Copyright 2024 Ross Hadden (@rosshadden)
// Copyright 2024 Ryan Neff (@JellyTitan)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "features/custom_shift_keys.h"

{{keyboard}}

enum sofle_layers {
  _ERMAK,
  _DVORAK,
  _QWERTY,

  _LOWER,
  _RAISE,
  _LEGACY,
};

enum custom_keycodes {
  KC_ERMAK = SAFE_RANGE,
  KC_DVORAK,
  KC_QWERTY,
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
  { KC_GRAVE, KC_AT },
  { KC_HASH, KC_DOLLAR },
  { KC_QUESTION, KC_EXCLAIM },
  { KC_QUOTE, KC_LEFT_PAREN },
  { KC_SLASH, KC_BACKSLASH },
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// const key_override_t **key_overrides = (const key_override_t *[]){
//   &delete_key_override,
//   NULL
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
{% for layer in layers -%}
  LAYOUT(
  {% for key in layer -%}
    {{ key }},
  {% endfor %}
  ),

{% endfor %}
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _LEGACY);
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
    case KC_ERMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_ERMAK);
      }
      return false;
    case KC_DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
    case KC_QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
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
  oled_write_P(PSTR("Keebler\nv1.0.0\n~~~~~~~~~"), false);

  oled_write_P(PSTR("\nBASE:\n\t"), false);

  switch (get_highest_layer(default_layer_state)) {
    case _ERMAK:
      oled_write_P(PSTR("Ermak"), false);
      break;
    case _DVORAK:
      oled_write_P(PSTR("Dvorak"), false);
      break;
    case _QWERTY:
      oled_write_P(PSTR("Qwerty"), false);
      break;
    default:
      oled_write_P(PSTR("UNKNOWN"), false);
      break;
  }

  oled_write_P(PSTR("\nLAYER:\n\t"), false);

  switch (get_highest_layer(layer_state)) {
    case _ERMAK:
      oled_write_P(PSTR("Ermak"), false);
      break;
    case _DVORAK:
      oled_write_P(PSTR("Dvorak"), false);
      break;
    case _QWERTY:
      oled_write_P(PSTR("Qwerty"), false);
      break;
    case _LOWER:
      oled_write_P(PSTR("num"), false);
      break;
    case _RAISE:
      oled_write_P(PSTR("nav"), false);
      break;
    case _LEGACY:
      oled_write_P(PSTR("legacy"), false);
      break;
    default:
      oled_write_P(PSTR("UNKNOWN"), false);
      break;
  }
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

  [_LOWER] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_RAISE] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_LEGACY] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif