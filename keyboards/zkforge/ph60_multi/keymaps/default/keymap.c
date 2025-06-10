// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // BASE Layer - QWERTY
    [0] = LAYOUT_60_ansi_tsangan_split_rshift(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          MO(3),
        MO(2),   KC_LGUI, KC_LALT,                            KC_SPC,                                      KC_RALT, KC_RGUI, KC_RCTL
    ),

    // BASE Layer - DVORAK
    [1] = LAYOUT_60_ansi_tsangan_split_rshift(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS,
        KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,          KC_ENT,
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,          MO(3),
        MO(2),   KC_LGUI, KC_LALT,                            KC_SPC,                                      KC_RALT, KC_RGUI, KC_RCTL
    ),

    // Extended Layer
    [2] = LAYOUT_60_ansi_tsangan_split_rshift(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, _______, KC_INS,
        _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                                     _______, _______, _______
      ),

    // Function Layer
    [3] = LAYOUT_60_ansi_tsangan_split_rshift(
        _______, KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,
        _______, DF(0),   DF(1),   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, QK_BOOT, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                                     _______, _______, _______
    )
};

/* emulate ctrl+super+arrow without pressing MO(2) */

uint8_t filter_left_mods(uint8_t mod_state) {
    uint8_t left_mods = 0;

    if (mod_state & MOD_BIT(KC_LCTL)) {
        left_mods |= MOD_BIT(KC_LCTL);
    }
    if (mod_state & MOD_BIT(KC_LSFT)) {
        left_mods |= MOD_BIT(KC_LSFT);
    }
    if (mod_state & MOD_BIT(KC_LALT)) {
        left_mods |= MOD_BIT(KC_LALT);
    }
    if (mod_state & MOD_BIT(KC_LGUI)) {
        left_mods |= MOD_BIT(KC_LGUI);
    }

    return left_mods;
}

uint16_t get_arrow_keycode(uint16_t keycode) {
    switch (keycode) {
        case KC_RSFT: return KC_UP;
        case KC_RGUI: return KC_DOWN;
        case KC_RALT: return KC_LEFT;
        case KC_RCTL: return KC_RGHT;
        default: return KC_NO;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t mod_state;

    mod_state = get_mods();

    bool left_mods_enabled = (mod_state & (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT))) != 0;
    bool is_fake_arrow_key = keycode == KC_RSFT || keycode == KC_RGUI || keycode == KC_RALT || keycode == KC_RCTL;

    if (left_mods_enabled && is_fake_arrow_key) {
        uint16_t arrow_keycode = get_arrow_keycode(keycode);

        if (record->event.pressed) {
            add_mods(filter_left_mods(mod_state));
            register_code(arrow_keycode);
        } else {
            unregister_code(arrow_keycode);

            // Don't clear the modifier keys here, because they might still be
            // held down by other key presses.
        }

        // Prevent the original key behavior.
        return false;
    }

    return true;
}
