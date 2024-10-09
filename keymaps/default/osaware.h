#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <sys/_intsup.h>
#include QMK_KEYBOARD_H
// #include "modifiers.h"

bool ismac(void) {
    return detected_host_os() == 3;
};

void register_code_if(bool is_pressed, uint16_t keycode) {
    if (is_pressed) {
        register_code(keycode);
    } else {
        unregister_code(keycode);
    }
};

void register_mods_if(bool is_pressed, uint16_t mod) {
    if (is_pressed) {
        register_mods(MOD_BIT(mod));
    } else {
        unregister_mods(MOD_BIT(mod));
    }
};

bool process_my_key(keyrecord_t *record, int16_t keycode) {
    bool ep = record->event.pressed;

    // Do something when pressed
    if (ismac()) {
        register_mods_if(ep, KC_LGUI);
        register_code_if(ep, keycode);
    } else {
        register_mods_if(ep, KC_LCTL);
        register_code_if(ep, keycode);
    }
    return false; // Skip all further processing of this key
}
