// Copyright 2024 Ross Hadden (@rosshadden)
// Copyright 2024 Ryan Neff (@JellyTitan)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "features/custom_shift_keys.h"

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
  /*
    ERMAK
    ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
    │ [{│ 1|│ 2=│ 3~│ 4+│ 5<│               │ 6>│ 7^│ 8&│ 9%│ 0*│ ]}│
    ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
    │ #$│ B │ Y │ O │ U │ '(│               │ ")│ L │ D │ W │ V │ Z │
    ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
    │Esc│ C │ I │ E │ A │ ,;│               │ .:│ J │ K │ S │ N │ Q │
    ├───┼───┼───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┼───┼───┤
    │Sft│ G │ X │ J │ K │ -_│Vol│       │Lay│ /\│ R │ M │ F │ P │Sft│
    └───┴───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┴───┘
            ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
            │ `@│Gui│Alt│Bsp│Tab│       │Ent│Spc│Gui│Alt│ ?!│
            └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
  */
  [_ERMAK] = LAYOUT(
    KC_LEFT_BRACKET, KC_1,         KC_2,         KC_3,         KC_4,         KC_5,                                                   KC_6,            KC_7,         KC_8,         KC_9,         KC_0,         KC_RIGHT_BRACKET,
    KC_HASH,         KC_B,         KC_Y,         KC_O,         KC_U,         KC_QUOTE,                                               KC_DOUBLE_QUOTE, KC_L,         KC_D,         KC_W,         KC_V,         KC_Z,
    LCTL_T(KC_ESC),  LGUI_T(KC_C), LALT_T(KC_I), LCTL_T(KC_E), LSFT_T(KC_A), KC_COMMA,                                               KC_DOT,          RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_S), RGUI_T(KC_N), KC_Q,
    KC_LSFT,         KC_G,         KC_X,         KC_J,         KC_K,         KC_MINUS,     KC_MUTE,            KC_DVORAK,            KC_SLASH,        KC_R,         KC_M,         KC_F,         KC_P,         KC_RSFT,
                                   KC_GRAVE,     KC_LALT,      KC_LGUI,      KC_BACKSPACE, LT(_LOWER, KC_TAB), LT(_RAISE, KC_ENTER), KC_SPACE,        KC_RGUI,      KC_RALT,      KC_QUESTION
  ),

  /*
    DVORAK
    ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
    │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │               │ 6 │ 7 │ 8 │ 9 │ 0 │ \ │
    ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
    │ESC│ ' │ , │ . │ P │ Y │               │ F │ C │ C │ R │ L │ / │
    ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
    │TAB│ A │ O │ E │ U │ I │               │ D │ H │ T │ N │ S │ - │
    ├───┼───┼───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┼───┼───┤
    │SFT│ ; │ Q │ J │ K │ X │   │       │   │ B │ M │ W │ V │ Z │SFT│
    └───┴───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┴───┘
            ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
            │ [ │   │   │   │   │       │   │   │   │   │ ] │
            └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
  */
  [_DVORAK] = LAYOUT(
    KC_GRV,   KC_1,         KC_2,         KC_3,         KC_4,         KC_5,                       KC_6,    KC_7,         KC_8,         KC_9,         KC_0,         KC_BACKSLASH,
    KC_EQUAL, KC_QUOTE,     KC_COMMA,     KC_DOT,       KC_P,         KC_Y,                       KC_F,    KC_G,         KC_C,         KC_R,         KC_L,         KC_SLASH,
    _______,  LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U), KC_I,                       KC_D,    RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_N), RGUI_T(KC_S), KC_MINUS,
    _______,  KC_SEMICOLON, KC_Q,         KC_J,         KC_K,         KC_X,    _______, KC_ERMAK, KC_B,    KC_M,         KC_W,         KC_V,         KC_Z,         KC_RSFT,
                            KC_LEFT_BRACKET,      _______,      _______,      _______, _______, _______,  _______, _______,      _______,      KC_RIGHT_BRACKET
  ),

  /*
    QWERTY
    ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
    │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │               │ 6 │ 7 │ 8 │ 9 │ 0 │ ` │
    ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
    │ESC│ Q │ W │ E │ R │ T │               │ Y │ U │ I │ O │ P │BSP│
    ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
    │TAB│ A │ S │ D │ F │ G │               │ H │ J │ K │ L │ ; │ ' │
    ├───┼───┼───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┼───┼───┤
    │SFT│ Z │ X │ C │ V │ B │   │       │   │ N │ M │ , │ . │ / │SFT│
    └───┴───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┴───┘
            ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
            │ [ │   │   │   │   │       │   │   │   │   │ ] │
            └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
  */
  [_QWERTY] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BACKSLASH,
    KC_EQUAL,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_MINUS,
    _______,   LGUI_T(KC_A),   LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G,                       KC_H,    RSFT_T(KC_J),    RCTL_T(KC_K),    RALT_T(KC_L), RGUI_T(KC_SCLN),  KC_QUOT,
    _______,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    _______, KC_ERMAK, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,
                      KC_LEFT_BRACKET, _______, _______, _______, _______, _______,  _______, _______, _______, KC_RIGHT_BRACKET
  ),

  /*
    Symbols/Numpad Layer
    ┌────┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬────┐
    │BOOT│F1 │F2 │F3 │F4 │F5 │               │F6 │F7 │F8 │F9 │F10│F11 │
    ├────┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼────┤
    │EEPR│ ! │ @ │ { │ } │ | │               │QMK│ 7 │ 8 │ 9 │ * │F12 │
    ├────┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼────┤
    │    │ # │ $ │ ( │ ) │ ` │               │QMK│ 4 │ 5 │ 6 │ + │    │
    ├────┼───┼───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┼───┼────┤
    │    │ < │ > │ [ │ ] │ ~ │   │       │   │QMK│ 1 │ 2 │ 3 │ / │    │
    └────┴───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┴────┘
             ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
             │   │   │   │   │   │       │   │   │ 0 │ 0 │ 0 │
             └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
  */
  [_LOWER] = LAYOUT(
    QK_BOOT,         KC_F1,                 KC_F2,                  KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7, KC_F8, KC_F9, KC_F10,  KC_F11,
    QK_CLEAR_EEPROM, KC_EXLM,               KC_AT,                  KC_LCBR, KC_RCBR, KC_PIPE,                    DT_PRNT, KC_7,  KC_8,  KC_9,  KC_ASTR, KC_F12,
    _______,         KC_HASH,               KC_DLR,                 KC_LPRN, KC_RPRN, KC_GRV,                     DT_UP,   KC_4,  KC_5,  KC_6,  KC_PPLS, XXXXXXX,
    _______,         KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET, KC_LBRC, KC_RBRC, KC_TILD, _______,  _______, DT_DOWN, KC_1,  KC_2,  KC_3,  KC_PSLS, _______,
                                            _______,                _______, _______, _______, _______,  _______, _______, KC_P0, KC_P0, KC_P0
  ),

  /*
    Navigation/Function Layer
    ┌────┬────┬────┬────┬────┬────┐               ┌────┬────┬────┬────┬────┬────┐
    │    │ACL0│ACL1│ACL2│    │MAKE│               │    │    │MOD │RMOD│HUI │    │
    ├────┼────┼────┼────┼────┼────┤               ├────┼────┼────┼────┼────┼────┤
    │    │BTS2│    │MS_U│    │    │               │    │BTN1│ ↑  │BTN2│SAI │SAD │
    ├────┼────┼────┼────┼────┼────┤               ├────┼────┼────┼────┼────┼────┤
    │CAPW│BTS1│MS_L│MS_D│MS_R│    │               │    │ ←  │ ↓  │ →  │VAI │VAD │
    ├────┼────┼────┼────┼────┼────┼────┐     ┌────┼────┼────┼────┼────┼────┼────┤
    │    │BTS3│    │    │    │    │    │     │    │    │    │    │    │SPI │SPD │
    └────┴────┴────┴────┴────┴────┴────┘     └────┴────┴────┴────┴────┴────┴────┘
                   ┌───┬───┬───┬───┬───┐     ┌───┬───┬───┬───┬───┐
                   │   │   │   │   │   │     │   │   │   │   │   │
                   └───┴───┴───┴───┴───┘     └───┴───┴───┴───┴───┘
  */
  [_RAISE] = LAYOUT(
    XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, QK_MAKE,                     XXXXXXX, XXXXXXX, RGB_MOD, RGB_RMOD, RGB_HUI, XXXXXXX,
    XXXXXXX, KC_BTN3, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_BTN1, KC_UP,   KC_BTN2,  XXXXXXX, XXXXXXX,
    CW_TOGG, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                     XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT,  XXXXXXX, XXXXXXX,
    _______, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, _______,
                      KC_BTN3, KC_BTN2, KC_BTN1, KC_DELETE, _______, _______, _______, _______, _______, _______
  ),

  /*
    legacy
    ┌────┬────┬────┬────┬────┬────┐               ┌────┬────┬────┬────┬────┬────┐
    │    │    │    │    │    │    │               │    │    │    │    │    │    │
    ├────┼────┼────┼────┼────┼────┤               ├────┼────┼────┼────┼────┼────┤
    │    │    │    │    │    │    │               │    │    │    │    │    │    │
    ├────┼────┼────┼────┼────┼────┤               ├────┼────┼────┼────┼────┼────┤
    │    │    │    │    │    │    │               │    │    │    │    │    │    │
    ├────┼────┼────┼────┼────┼────┼────┐     ┌────┼────┼────┼────┼────┼────┼────┤
    │    │    │    │    │    │    │    │     │    │    │    │    │    │    │    │
    └────┴────┴────┴────┴────┴────┴────┘     └────┴────┴────┴────┴────┴────┴────┘
                   ┌───┬───┬───┬───┬───┐     ┌───┬───┬───┬───┬───┐
                   │   │   │   │   │   │     │   │   │   │   │   │
                   └───┴───┴───┴───┴───┘     └───┴───┴───┴───┴───┘
  */
  [_LEGACY] = LAYOUT(
    KC_TILDE, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT,              KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_PIPE,
    _______, _______, _______, _______, _______, KC_LEFT_CURLY_BRACE,                   KC_RIGHT_CURLY_BRACE, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_LEFT_BRACKET,                   KC_RIGHT_BRACKET, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_PIPE, _______, _______, KC_EQUAL, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /*
    blank
    ┌────┬────┬────┬────┬────┬────┐               ┌────┬────┬────┬────┬────┬────┐
    │    │    │    │    │    │    │               │    │    │    │    │    │    │
    ├────┼────┼────┼────┼────┼────┤               ├────┼────┼────┼────┼────┼────┤
    │    │    │    │    │    │    │               │    │    │    │    │    │    │
    ├────┼────┼────┼────┼────┼────┤               ├────┼────┼────┼────┼────┼────┤
    │    │    │    │    │    │    │               │    │    │    │    │    │    │
    ├────┼────┼────┼────┼────┼────┼────┐     ┌────┼────┼────┼────┼────┼────┼────┤
    │    │    │    │    │    │    │    │     │    │    │    │    │    │    │    │
    └────┴────┴────┴────┴────┴────┴────┘     └────┴────┴────┴────┴────┴────┴────┘
                   ┌───┬───┬───┬───┬───┐     ┌───┬───┬───┬───┬───┐
                   │   │   │   │   │   │     │   │   │   │   │   │
                   └───┴───┴───┴───┴───┘     └───┴───┴───┴───┴───┘
  */
  // [_BLANK] = LAYOUT(
  //   _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  //   _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  //   _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  //   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  //
  // ),
  // [_BLANK] = LAYOUT(
  //   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  // ),
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
