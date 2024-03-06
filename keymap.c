// Copyright 2024 Ryan Neff (@JellyTitan)
// SPDX-License-Identifier: GPL-2.0-or-later

// Copyright 2024 Ross Hadden (@JellyTitan)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum sofle_layers {
  _ERMAK,
  _DVORAK,
  _QWERTY,
  _LOWER,
  _RAISE,
};

enum custom_keycodes {
  KC_ERMAK = SAFE_RANGE,
  KC_DVORAK,
  KC_QWERTY,
  KC_LOWER,
  KC_RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
    ERMAK
    ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
    │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │               │ 6 │ 7 │ 8 │ 9 │ 0 │ \ │
    ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
    │ = │ B │ Y │ O │ U │ ' │               │ ; │ L │ D │ W │ V │ Z │
    ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
    │ESC│ C │ I │ E │ A │ , │               │ . │ J │ K │ S │ N │ Q │
    ├───┼───┼───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┼───┼───┤
    │SFT│ G │ X │ J │ K │ - │Min│       │Max│ / │ R │ M │ F │ P │SFT│
    └───┴───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┴───┘
            ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
            │ [ │GUI│ALT│BSP│TAB│       │ENT│SPC│GUI│ALT│ ] │
            └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
  */
  [_ERMAK] = LAYOUT(
    KC_GRAVE,       KC_1,         KC_2,            KC_3,         KC_4,          KC_5,                             KC_6,         KC_7,         KC_8,         KC_9,            KC_0,         KC_BACKSLASH,
    KC_EQUAL,       KC_B,         KC_Y,            KC_O,         KC_U,          KC_QUOTE,                         KC_SEMICOLON, KC_L,         KC_D,         KC_W,            KC_V,         KC_Z,
    LCTL_T(KC_ESC), LGUI_T(KC_C), LALT_T(KC_I),    LCTL_T(KC_E), LSFT_T(KC_A),  KC_COMMA,                         KC_DOT,       RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_S),    RGUI_T(KC_N), KC_Q,
    KC_LSFT,        KC_G,         KC_X,            KC_J,         KC_K,          KC_MINUS,     KC_MUTE, KC_DVORAK, KC_SLASH,     KC_R,         KC_M,         KC_F,            KC_P,         KC_RSFT,
                                  KC_LEFT_BRACKET, KC_LGUI,      KC_LALT,       KC_BACKSPACE, KC_TAB,  KC_ENTER,  KC_SPACE,     KC_RGUI,      KC_RALT,      KC_RIGHT_BRACKET
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
    │SFT│ ; │ Q │ J │ K │ X │Min│       │Max│ B │ M │ W │ V │ Z │SFT│
    └───┴───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┴───┘
            ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
            │ [ │GUI│ALT│BSP│TAB│       │ENT│SPC│GUI│ALT│ ] │
            └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
  */
  [_DVORAK] = LAYOUT(
    KC_GRV,   KC_1,         KC_2,            KC_3,         KC_4,         KC_5,                            KC_6,     KC_7,         KC_8,         KC_9,            KC_0,         KC_BACKSLASH,
    KC_EQUAL, KC_QUOTE,     KC_COMMA,        KC_DOT,       KC_P,         KC_Y,                            KC_F,     KC_G,         KC_C,         KC_R,            KC_L,         KC_SLASH,
    KC_TRNS,  LGUI_T(KC_A), LALT_T(KC_O),    LCTL_T(KC_E), LSFT_T(KC_U), KC_I,                            KC_D,     RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_N),    RGUI_T(KC_S), KC_MINUS,
    KC_LSFT,  KC_SEMICOLON, KC_Q,            KC_J,         KC_K,         KC_X,         KC_TRNS, KC_ERMAK, KC_B,     KC_M,         KC_W,         KC_V,            KC_Z,         KC_RSFT,
                            KC_TRNS,         KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS
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
    │SFT│ Z │ X │ C │ V │ B │Min│       │Max│ N │ M │ , │ . │ / │SFT│
    └───┴───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┴───┘
            ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
            │GUI│ALT│CTL│LOW│ENT│       │SPC│RSE│CTL│ALT│GUI│
            └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
  */
  [_QWERTY] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
    KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
    KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_TRNS, KC_ERMAK, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  /*
    Symbols/Numpad Layer
    ┌────┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬────┐
    │BOOT│F1 │F2 │F3 │F4 │F5 │               │F6 │F7 │F8 │F9 │F10│F11 │
    ├────┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼────┤
    │____│ ! │ @ │ { │ } │ | │               │QMK│ 7 │ 8 │ 9 │ * │F12 │
    ├────┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼────┤
    │____│ # │ $ │ ( │ ) │ ` │               │QMK│ 4 │ 5 │ 6 │ + │____│
    ├────┼───┼───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┼───┼────┤
    │____│ # │ $ │ [ │ ] │ ~ │___│       │___│QMK│ 1 │ 2 │ 3 │ / │BOOT│
    └────┴───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┴────┘
             ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
             │___│___│___│___│___│       │ 0 │ 0 │ 0 │ 0 │ 0 │
             └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
  */
  [_LOWER] = LAYOUT(
    QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7, KC_F8, KC_F9, KC_F10,  KC_F11,
    KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                    DT_PRNT, KC_7,  KC_8,  KC_9,  KC_ASTR, KC_F12,
    KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                     DT_UP,   KC_4,  KC_5,  KC_6,  KC_PPLS, KC_TRNS,
    KC_TRNS, KC_HASH, KC_DLR,  KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,  KC_TRNS, DT_DOWN, KC_1,  KC_2,  KC_3,  KC_PSLS, QK_BOOT,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_P0,   KC_P0, KC_P0,   KC_P0, KC_P0
  ),

  /*
    Navigation/Function Layer
    ┌────┬────┬────┬────┬────┬────┐               ┌────┬────┬────┬────┬────┬────┐
    │BOOT│ACL0│ACL1│ACL2│____│____│               │____│____│MOD │RMOD│HUI │EEP │
    ├────┼────┼────┼────┼────┼────┤               ├────┼────┼────┼────┼────┼────┤
    │____│____│____│MS_U│____│____│               │____│BTN1│ ↑  │BTN2│SAI │SAD │
    ├────┼────┼────┼────┼────┼────┤               ├────┼────┼────┼────┼────┼────┤
    │____│____│MS_L│MS_D│MS_R│____│               │____│ ←  │ ↓  │ →  │VAI │VAD │
    ├────┼────┼────┼────┼────┼────┼────┐     ┌────┼────┼────┼────┼────┼────┼────┤
    │____│____│____│____│____│____│____│     │____│____│____│____│____│SPI │SPD │
    └────┴────┴────┴────┴────┴────┴────┘     └────┴────┴────┴────┴────┴────┴────┘
                   ┌───┬───┬───┬───┬───┐     ┌───┬───┬───┬───┬───┐
                   │___│___│BT2│BT1│___│     │___│___│___│___│___│
                   └───┴───┴───┴───┴───┘     └───┴───┴───┴───┴───┘
  */
  [_RAISE] = LAYOUT(
    QK_BOOT, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, RGB_MOD, RGB_RMOD, RGB_HUI, QK_CLEAR_EEPROM,
    HF_TOGG, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_BTN1, KC_UP,   KC_BTN2,  RGB_SAI, RGB_SAD,
    HF_DWLU, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                   KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT,  RGB_VAI, RGB_VAD,
    HF_DWLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  RGB_SPI, RGB_SPD,
                      KC_TRNS, KC_TRNS, KC_BTN3, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
};

#ifdef OLED_ENABLE

static void render_logo(void) {
  static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
  oled_write_P(PSTR("Sofle Pico\nv3.04\n~~~~~~~~~\n"), false);
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
      oled_write_P(PSTR("num/sym"), false);
      break;
    case _RAISE:
      oled_write_P(PSTR("nav"), false);
      break;
    default:
      oled_write_P(PSTR("Unknown"), false);
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
    case KC_LOWER:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_LOWER);
      }
      return false;
    case KC_RAISE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_RAISE);
      }
      return false;
  }
  return true;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_ERMAK] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_RAISE, KC_DVORAK) },
  [_DVORAK] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_ERMAK, KC_QWERTY) },
  [_QWERTY] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_DVORAK, KC_LOWER) },
  [_LOWER] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_QWERTY, KC_RAISE) },
  [_RAISE] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_LOWER, KC_ERMAK) },
};
#endif
