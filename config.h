// Copyright 2024 Ryan Neff (@JellyTitan)
// Copyright 2024 Ross Hadden (@rosshadden)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#undef TAPPING_TERM
#define TAPPING_TERM 175
#define PERMISSIVE_HOLD

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define ENABLE_COMPILE_KEYCODE

//encoders
#define ENCODER_DIRECTION_FLIP
#define ENCODER_MAP_ENABLE

// polling
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 12

// joystick
#define JOYSTICK_BUTTON_COUNT 16
#define JOYSTICK_AXIS_COUNT 4
#define JOYSTICK_AXIS_RESOLUTION 8

#define ACHORDION_STREAK

#define CUSTOM_SHIFT_KEYS_NEGMODS (MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI))
