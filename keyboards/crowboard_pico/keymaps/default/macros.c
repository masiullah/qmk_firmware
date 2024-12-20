
 #include QMK_KEYBOARD_H
//  #include "quantum.c"
// #include "os_detection.h"
// #include "secure.h"
// #include "process_secure.h"
// sticky_mod *prev_sticky_mod;
// bool isMac = true;

// sticky_mod alt_tab     = {.mod = KC_LALT, .keycode = KC_TAB, .active = false, .is_shifted = false};
// sticky_mod cmd_tab     = {.mod = KC_LCMD, .keycode = KC_TAB, .active = false, .is_shifted = false};
// sticky_mod alt_sft_tab = {.mod = KC_LALT, .keycode = KC_TAB, .active = false, .is_shifted = true};
// sticky_mod cmd_sft_tab = {.mod = KC_LCMD, .keycode = KC_TAB, .active = false, .is_shifted = true};

// void sticky_mod_rel(sticky_mod *this) {
//     if (this->active) {
//         unregister_code(this->mod);
//         this->active = false;
//         if (this->is_shifted) {
//             unregister_code(KC_LSFT);
//         }
//     }
// }

// void sticky_mod_press(sticky_mod *this) {
//     if (this->is_shifted != prev_sticky_mod->is_shifted) {
//         if (this->is_shifted) {
//             register_code(KC_LSFT);
//         } else {
//             unregister_code(KC_LSFT);
//         }
//     }
//     if (this->mod != prev_sticky_mod->mod) {
//         sticky_mod_rel(prev_sticky_mod);
//     }

//     if (!this->active) {
//         this->active = true;
//         register_code(this->mod);
//         if (this->is_shifted) {
//             register_code(KC_LSFT);
//         }
//     }
//     prev_sticky_mod = this;
//     tap_code(this->keycode);
// }

// void release_sticky_mod_main(void) {
//     sticky_mod_rel(&alt_tab);
//     sticky_mod_rel(&alt_sft_tab);
//     sticky_mod_rel(&cmd_tab);
//     sticky_mod_rel(&cmd_sft_tab);
// }

// // os_variant_t os_type;

// bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
//     //process_secure(keycode, record);
//     switch (keycode) {
//         case CG_TOGG:
//             // if (record->event.pressed) {
//             //     if(isMac){
//             //         isMac = false;
//             //     } else {
//             //         isMac = true;
//             //     }
//             // }
//             break;
//             return false;
//         case KC_ALT_TAB:
//             if (record->event.pressed) {
//                 sticky_mod_press(&alt_tab);
//             }
//             break;
//             return false;
//         case KC_CMD_TAB:
//             if (record->event.pressed) {
//                 sticky_mod_press(&cmd_tab);
//             }
//             break;
//             return false;
//         case KC_ALT_SFT_TAB:
//             if (record->event.pressed) {
//                 sticky_mod_press(&alt_sft_tab);
//             }
//             break;
//             return false;
//         case KC_CMD_SFT_TAB:
//             if (record->event.pressed) {
//                 sticky_mod_press(&cmd_sft_tab);
//             }
//             break;
//             return false;
//     }
//     return process_record_user(keycode, record);
// }

bool     is_gui_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t gui_tab_timer     = 0;     // we will be using them soon.
bool     is_alt_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t alt_tab_timer     = 0;     // we will be using them soon.

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (keycode == SE_TOGG) {
            return true;
        }
        if (secure_is_locked()) {
            return false;
        }
    }
    if (keycode == GUI_TAB || keycode == ALT_TAB) {
        if (keymap_config.swap_lctl_lgui) {
            keycode = ALT_TAB;
        } else {
            keycode = GUI_TAB;
        }
    }

    switch (keycode) { // This will do most of the grunt work with the keycodes.
        case GUI_TAB:
            if (record->event.pressed) {
                if (!is_gui_tab_active) {
                    is_gui_tab_active = true;
                    register_code(KC_LGUI);
                }
                gui_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case REDO:
            if (keymap_config.swap_lctl_lgui) {
                if (record->event.pressed) {
                    register_code16(G(KC_Y));
                } else {
                    unregister_code16(G(KC_Y));
                }
            } else {
                if (record->event.pressed) {
                    register_code16(G(S(KC_Z)));
                } else {
                    unregister_code16(G(S(KC_Z)));
                }
            }
            break;
            }
            secure_activity_event();
            return true;
    }

    void matrix_scan_user(void) { // The very important timer.
        if (is_gui_tab_active) {
            if (timer_elapsed(gui_tab_timer) > 1000) {
                unregister_code(KC_LGUI);
                is_gui_tab_active = false;
            }
        }
        if (is_alt_tab_active) {
            if (timer_elapsed(alt_tab_timer) > 1000) {
                unregister_code(KC_LALT);
                is_alt_tab_active = false;
            }
        }
    }