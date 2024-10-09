// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "action.h"
#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "modifiers.h"
#include "features/achordion.h"
#include "osaware.h"
#include "hand_swap_config.h"



enum Layers {
    BASE,
    NUM,
    SYM,
    NAV,
};

enum my_keycodes {
  CTMD = SAFE_RANGE,
  GUICT,
  // LSMT,
  // RSMT,
  // LCMT,
  // RCMT,
  // LAMT
};

// Brackets ++
#define ED_LPAR S(KC_8)
#define ED_RPAR S(KC_9)
#define ED_LBRK ALGR(KC_8)
#define ED_RBRK ALGR(KC_9)
#define ED_LCBRK ALGR(KC_7)
#define ED_RCBRK ALGR(KC_0)

// Mod taps, homerow
#define  MT_A MT(MOD_LGUI, KC_A)

#define  MT_R MT(MOD_LALT, KC_R)
#define  MT_4 MT(MOD_LALT, KC_4)

#define  MT_S MT(MOD_LSFT, KC_S)
#define  MT_5 MT(MOD_LSFT, KC_5)

#define  MT_T MT(MOD_LCTL, KC_T)
#define  MT_6 MT(MOD_LCTL, KC_6)

#define  MT_N MT(MOD_LCTL, KC_N)
#define  MT_E MT(MOD_LSFT, KC_E)
#define  MT_I MT(MOD_LALT, KC_I)

#define  MT_O MT(MOD_LGUI, KC_O)

#define  AA  RALT(KC_W)
#define  OO  RALT(KC_L)
#define  AE  RALT(KC_Z)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    /* Colemak-DH
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |BCKSP |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |LShift|   Z  |   X  |   C  |   V  |   B  |------         -----|   N  |   M  |   ,  |   .  |   /  |RShift|
    * `-----------------------------------------/      \       /     \-----------------------------------------'
    *                   | LAlt | LGUI | SYM |  LCTRL  /       \ Enter   | SPACE| NAV | ALTGR|
    *                   |      |      |      |        /         \        |      |      |      |
    *                   `----------------------------'           '------''--------------------'
    */
    [BASE] = LAYOUT(
                         KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5,            KC_6,    KC_7,     KC_8,   KC_9,    KC_0, KC_MINUS,

                         KC_TAB,   KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,           KC_J,   KC_L,   KC_U,     KC_Y,     AA,        KC_QUOT, 
                         SC_LSPO,  KC_A,   MT_R,   MT_S,   MT_T,   KC_G,           KC_M,   MT_N,   MT_E,     MT_I,     KC_O,      SC_RSPC, 
                         GUICT,    KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,           KC_K,   KC_H,   KC_COMM,  KC_DOT,   KC_SLSH,   KC_MINS, 

                                          _______, CTMD, KC_SPC, MO(SYM),        KC_ENT, MO(NUM), KC_BSPC, _______
    ),          

    [SYM] = LAYOUT(
    KC_VOLD, KC_VOLU,    KC_MPRV,   KC_MPLY,  KC_MNXT,   KC_PSCR,                            XXXXXXX,    XXXXXXX,      XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
                                                                                                                            // ø          //  æ
    KC_DEL,    S(KC_1),      S(KC_2),   KC_MS_U,      S(KC_4),   S(KC_5),            S(KC_6),      S(KC_7),      S(KC_8),   OO,           AE,           KC_EQL,
    KC_BTN1,   KC_BTN2,      KC_MS_L,   KC_MS_D,      KC_MS_R,   S(KC_3),            KC_MINS,      S(KC_LBRC),   KC_LBRC,   KC_RBRC,      S(KC_RBRC),   KC_GRV, 
    KC_TRNS,   QK_MACRO_1,   KC_CUT,    QK_MACRO_2,   KC_SLCT,   QK_MACRO_3,         S(KC_MINS),   S(KC_EQL),    KC_SCLN,   S(KC_SCLN),   S(KC_BSLS),   KC_BSLS, 

                                           _______, KC_LGUI, KC_TRNS, KC_TRNS,       KC_TRNS, MO(NAV), KC_DEL,  _______
    ),
    [NUM] = LAYOUT(
        _______, _______, _______, _______,      _______,  _______,      _______,  _______,  _______,  _______,  _______, _______,

        KC_TAB,    KC_1,   KC_1,   KC_2,   KC_3,   KC_5,          LSFT(KC_1), KC_EQL,  KC_UP,    LSFT(KC_SLSH),   KC_0,   KC_TRNS,
        KC_TRNS,   KC_0,   MT_4,   MT_5,   MT_6,   KC_TRNS,       KC_QUOT, KC_LEFT, KC_DOWN, KC_RGHT, RALT(KC_L), KC_TRNS,
        KC_TRNS,   KC_DOT, KC_7,   KC_8,   KC_9,   KC_TRNS,       LSFT(KC_QUOT),   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,      KC_ESC,
                      _______, KC_LGUI, KC_TRNS, MO(NAV),              KC_TRNS, MO(NAV), KC_RALT, _______
    ),
    [NAV] = LAYOUT( 
        QK_BOOT, XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,

            RGB_TOG,    KC_TRNS,    KC_TRNS, KC_WH_U, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_PGUP, KC_TRNS, KC_TRNS, QK_MACRO_6, 
            RGB_MOD, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_R, KC_MPLY, KC_TRNS, KC_HOME, KC_PGDN, KC_END, RGB_VAI, KC_TRNS, 
            RGB_RMOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SPD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_TOG, 
                        _______, KC_LGUI, KC_TRNS, KC_SPC,          KC_ENT, KC_TRNS, KC_RALT, _______)
    // [TEMP] = LAYOUT( // NOT IN USE
    //     _______, _______,    _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______, _______,

    //     _______, _______,    _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______, _______,
    //     _______, _______,    _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______, _______,
    //     _______, _______,    _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______, _______,
    //                          _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______
    // )
};


bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_SCLN:
        case KC_SLSH:
        case KC_QUOT:
        case KC_LBRC:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;
        case RALT(KC_W):
        case RALT(KC_L):
        case RALT(KC_Z):

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

enum combos {
ZX_CUT,  
XC_COPY, 
CD_PASTE, 
FP_SRP,
ESCAPE,
SWAPL,
SWAPR, 
PRTSCR,
PRTSCR_LEFT,
};

                                                                                                                                              
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM tabq_combo[] = {KC_TAB, KC_Q, COMBO_END};
const uint16_t PROGMEM swapl_combo[] = {KC_W, KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM swapr_combo[] = {KC_L, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM prtscr_combo[] = {AA, KC_QUOT, COMBO_END};
const uint16_t PROGMEM prtscr_left_side_combo[] = {KC_TAB, KC_Q, KC_W, COMBO_END};




combo_t key_combos[] = {
  [ZX_CUT]    = COMBO(zx_combo, KC_CUT),
  [XC_COPY]   = COMBO(xc_combo, KC_COPY),
  [CD_PASTE]  = COMBO(cd_combo, KC_PASTE),
  [FP_SRP]    = COMBO(fp_combo, RCS(KC_P)),
  [ESCAPE]    = COMBO(tabq_combo, KC_ESC),
  // [SWAPL]     = COMBO(swapl_combo, SH_TOGG),
  // [SWAPR]     = COMBO(swapr_combo, SH_TOGG),
  [SWAPL]     = COMBO_ACTION(swapl_combo),
  [SWAPR]     = COMBO_ACTION(swapr_combo),
  [PRTSCR]     = COMBO_ACTION(prtscr_combo),
  [PRTSCR_LEFT]     = COMBO_ACTION(prtscr_left_side_combo)

};


int16_t opposite_color(int16_t color) {
  return abs(255 - color);
}

void swap_hands_set_rgb(void) {
    HSV hsv = rgblight_get_hsv();
    rgblight_sethsv(opposite_color(hsv.h), hsv.s, hsv.v);
  }


void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case SWAPL:
      if (pressed) {
        swap_hands_toggle();
        swap_hands_set_rgb();
      }
      break;
    case SWAPR:
      if (pressed) {
       swap_hands_toggle();
       swap_hands_set_rgb();
      }
      break;
    case PRTSCR:
      if (pressed) {
        if (ismac()) {
          register_mods_if(pressed, KC_LGUI);
          register_mods_if(pressed, KC_LEFT_SHIFT);
          tap_code16(KC_4); 
        } else {
          tap_code16(KC_PSCR);
        }
      } else {
        if (ismac()) {
          register_mods_if(pressed, KC_LGUI);
          register_mods_if(pressed, KC_LEFT_SHIFT);
        }
      }
      break;
          case PRTSCR_LEFT:
      if (pressed) {
        if (ismac()) {
          register_mods_if(pressed, KC_LGUI);
          register_mods_if(pressed, KC_LEFT_SHIFT);
          tap_code16(KC_4); 
        } else {
          tap_code16(KC_PSCR);
        }
      } else {
        if (ismac()) {
          register_mods_if(pressed, KC_LGUI);
          register_mods_if(pressed, KC_LEFT_SHIFT);
        }
      }
      break;
  }
}

// Used for achordion
void matrix_scan_user(void) {
  achordion_task();
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }

  switch (keycode) {
    case CTMD:
      if (record->event.pressed) {
        // Do something when pressed
        if (detected_host_os() == 3) {
              register_mods(MOD_BIT(KC_LGUI));
        } else {
          register_mods(MOD_BIT(KC_LCTL));
        }
      } else {
        // Do something else when release
        if (detected_host_os() == 3) {
              unregister_mods(MOD_BIT(KC_LGUI));
        } else {
          unregister_mods(MOD_BIT(KC_LCTL));
        }
      }
      return false; // Skip all further processing of this key

    case GUICT:
      if (record->event.pressed) {
        // Do something when pressed
        if (detected_host_os() == 3) {
              register_mods(MOD_BIT(KC_LCTL));
        } else {
          register_mods(MOD_BIT(KC_LGUI));
        }
      } else {
        // Do something else when release
        if (detected_host_os() == 3) {
              unregister_mods(MOD_BIT(KC_LCTL));
        } else {
          unregister_mods(MOD_BIT(KC_LGUI));
        }
      }
      return false; // Skip all further processing of this key

    case KC_COPY:
      return process_my_key(record, KC_C);

    case KC_PASTE:
      return process_my_key(record, KC_V);

    case KC_CUT:
      return process_my_key(record, KC_X);

    default:
      return true; // Process all other keycodes normally
  }

}