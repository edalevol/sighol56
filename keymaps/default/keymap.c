// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define BASE 0
#define COLEMAK 1
#define NUMB 2
#define NAV 3
#define SETTINGS 4
#define TEMP 5

#define SH_LPAR S(KC_8)
#define SH_RPAR S(KC_9)
#define SH_LBRK ALGR(KC_8)
#define SH_RBRK ALGR(KC_9)
#define SH_LCBRK ALGR(KC_7)
#define SH_RCBRK ALGR(KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |LCTRL |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |LShift|   Z  |   X  |   C  |   V  |   B  |------         -----|   N  |   M  |   ,  |   .  |   /  |RShift|
    * `-----------------------------------------/      \       /     \-----------------------------------------'
    *                   | LAlt | LGUI | NAV  |  Space  /       \ Enter   | SPACE| NUMB | RALT |
    *                   |      |      |      |        /         \        |      |      |      |
    *                   `----------------------------'           '------''--------------------'
    */
    [BASE] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5,        KC_6,    KC_7,       KC_8,    KC_9,    KC_0,  KC_MINUS,

        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,        KC_Y,    KC_U,       KC_I,    KC_O,    KC_P,   KC_LBRC,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,      KC_G,        KC_H,    KC_J,       KC_K,    KC_L, KC_SCLN,   KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,        KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH,   KC_RSFT,
                       KC_LALT, KC_LGUI, MO(NAV),   KC_LCTL,        KC_ENT,  KC_SPC, MO(NUMB),  KC_RALT
    ),
    [COLEMAK] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,     KC_3,    KC_4,      KC_5,       KC_6,      KC_7,     KC_8,    KC_9,    KC_0, KC_MINUS,

        KC_TAB,  KC_Q,    KC_W,     KC_F,    KC_P,      KC_G,       KC_J,      KC_L,     KC_U,    KC_Y, KC_SCLN,  KC_LBRC,
        KC_BSPC, KC_A,    KC_R,     KC_S,    KC_T,      KC_D,       KC_H,      KC_N,     KC_E,    KC_I,    KC_O,  KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,     KC_C,    KC_V,      KC_B,       KC_K,      KC_M,  KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                       KC_LALT,   KC_LGUI,MO(NAV),   KC_LCTL,       KC_ENT,  KC_SPC, MO(NUMB), KC_RALT
    ),

    [NAV] = LAYOUT( // left up
        KC_VOLD, KC_VOLU, KC_MPRV,   KC_MPLY,  KC_MNXT, KC_PSCR,      _______,    _______,    _______,  _______, _______, _______,

        KC_MUTE, XXXXXXX, XXXXXXX,  SH_LCBRK, SH_RCBRK,  KC_EQL,      KC_PGUP, C(KC_LEFT),    KC_UP, C(KC_RGHT), _______, _______,
        _______,  KC_GRV, XXXXXXX,   SH_LPAR,  SH_RPAR, KC_RBRC,      KC_PGDN,    KC_LEFT,    KC_DOWN,  KC_RGHT, S(KC_2), KC_BSLS,
        _______, KC_NUBS, XXXXXXX,   SH_LBRK,  SH_RBRK, KC_BSLS,      _______,    KC_HOME,     KC_END,  _______, _______, _______,
                          _______,   _______,  _______, _______,      _______,  _______, MO(SETTINGS),  _______
    ),

    [NUMB] = LAYOUT( // Hold down right side
        _______, _______, _______, _______,      _______,  _______,      _______,  _______,  _______,  _______,  _______, _______,

        _______, _______,    KC_7,    KC_8,         KC_9,  _______,      _______,    KC_F7,    KC_F8,    KC_F9,   KC_F10,  KC_DEL,
        _______,    KC_0,    KC_4,    KC_5,         KC_6,     KC_0,      _______,    KC_F4,    KC_F5,    KC_F6,   KC_F11, KC_CAPS,
        _______, _______,    KC_1,    KC_2,         KC_3,  _______,      _______,    KC_F1,    KC_F2,    KC_F3,   KC_F12, _______,
                          _______, _______, MO(SETTINGS),  _______,      _______,  _______,  _______,  _______
    ),

    [SETTINGS] = LAYOUT(
        QK_BOOT, XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  DF(BASE),     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  DF(COLEMAK),  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
                             XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,      XXXXXXX,  XXXXXXX,  _______,  XXXXXXX
    ),

    [TEMP] = LAYOUT( // NOT IN USE
        _______, _______,    _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______, _______,

        _______, _______,    _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______, _______,
        _______, _______,    _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______, _______,
        _______, _______,    _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______, _______,
                             _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______
    )
};


/*

[WIN_BASE] = LAYOUT_iso_85(
     KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   RGB_MOD,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_ENT,             KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_BSLS,            KC_HOME,
     KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WIN_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[WIN_FN] = LAYOUT_iso_85(
     _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  RGB_TOG,
     _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
     _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______)
};


*/
