#include QMK_KEYBOARD_H
#include "layers.h"



#ifdef ENCODER_ENABLE

bool encoder_update_kb(uint8_t index, bool clockwise) {
    uint8_t modifiers   = get_mods() | get_oneshot_mods();
    bool    sft_pressed = modifiers & MOD_MASK_SHIFT;
    bool    alt_pressed = modifiers & MOD_MASK_ALT;
    bool    cmd_pressed = modifiers & MOD_MASK_GUI;
    bool    ctl_pressed = modifiers & MOD_MASK_CTRL;
    switch (get_highest_layer(layer_state)) {
        case NUM:
            if (clockwise) {
                tap_code16(KC_UP);
            } else {
                tap_code16(KC_DOWN);
            }
            return false;
            break;
        case SYM:

            if (clockwise) {
                tap_code16(KC_PGUP);
            } else {
                tap_code16(KC_PGDN);
            }
            return false;
            break;
        case NAV:
            if (clockwise) {
                tap_code16(G(KC_Z));
            } else {
                tap_code16(G(S(KC_Z)));
            }
            return false;
            break;
        default:
            if (index != 0) {
                if (sft_pressed) {
                    #ifdef RGB_MATRIX_ENABLE
                    if (clockwise) {
                        rgb_matrix_step_reverse_noeeprom();
                    } else {
                        rgb_matrix_step_noeeprom();
                    }
                    #endif
                } else if (alt_pressed) {
                    if (!clockwise) {
                        tap_code16(KC_TAB);
                    } else {
                        tap_code16(S(KC_TAB));
                    }
                } else if (cmd_pressed) {
                    if (!clockwise) {
                        tap_code16(KC_TAB);
                    } else {
                        tap_code16(S(KC_TAB));
                    }
                } else if (ctl_pressed) {
                    if (!clockwise) {
                        tap_code16(KC_BRIU);
                    } else {
                        tap_code16(KC_BRID);
                    }
                } else {
                    if (clockwise) {
                        tap_code_delay(KC_VOLU, 10);
                    } else {
                        tap_code_delay(KC_VOLD, 10);
                    }
                }
            } else {
                if (sft_pressed) {
                    #ifdef RGB_MATRIX_ENABLE
                    if (clockwise) {
                        rgb_matrix_step_reverse_noeeprom();
                    } else {
                        rgb_matrix_step_noeeprom();
                    }
                    #endif
                } else if (alt_pressed) {
                    if (!clockwise) {
                        tap_code16(KC_TAB);
                    } else {
                        tap_code16(S(KC_TAB));
                    }
                } else if (cmd_pressed) {
                    if (!clockwise) {
                        tap_code16(KC_TAB);
                    } else {
                        tap_code16(S(KC_TAB));
                    }
                } else if (ctl_pressed) {
                    if (!clockwise) {
                        tap_code16(KC_BRIU);
                    } else {
                        tap_code16(KC_BRID);
                    }
                } else {
                    if (!clockwise) {
                        tap_code(KC_RIGHT);
                    } else {
                        tap_code(KC_LEFT);
                    }
                }
            }
    }

    return true;
}
// #    endif

#endif // ENCODER_ENABLE
