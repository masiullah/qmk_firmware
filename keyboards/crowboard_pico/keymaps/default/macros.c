
#include QMK_KEYBOARD_H
#include "os_detection.h"
sticky_mod *prev_sticky_mod;
bool isMac = true;

sticky_mod alt_tab     = {.mod = KC_LALT, .keycode = KC_TAB, .active = false, .is_shifted = false};
sticky_mod cmd_tab     = {.mod = KC_LCMD, .keycode = KC_TAB, .active = false, .is_shifted = false};
sticky_mod alt_sft_tab = {.mod = KC_LALT, .keycode = KC_TAB, .active = false, .is_shifted = true};
sticky_mod cmd_sft_tab = {.mod = KC_LCMD, .keycode = KC_TAB, .active = false, .is_shifted = true};

void sticky_mod_rel(sticky_mod *this) {
    if (this->active) {
        unregister_code(this->mod);
        this->active = false;
        if (this->is_shifted) {
            unregister_code(KC_LSFT);
        }
    }
}

void sticky_mod_press(sticky_mod *this) {
    if (this->is_shifted != prev_sticky_mod->is_shifted) {
        if (this->is_shifted) {
            register_code(KC_LSFT);
        } else {
            unregister_code(KC_LSFT);
        }
    }
    if (this->mod != prev_sticky_mod->mod) {
        sticky_mod_rel(prev_sticky_mod);
    }

    if (!this->active) {
        this->active = true;
        register_code(this->mod);
        if (this->is_shifted) {
            register_code(KC_LSFT);
        }
    }
    prev_sticky_mod = this;
    tap_code(this->keycode);
}

void release_sticky_mod_main(void) {
    sticky_mod_rel(&alt_tab);
    sticky_mod_rel(&alt_sft_tab);
    sticky_mod_rel(&cmd_tab);
    sticky_mod_rel(&cmd_sft_tab);
}

// os_variant_t os_type;

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CG_TOGG:
            // if (record->event.pressed) {
            //     if(isMac){
            //         isMac = false;
            //     } else {
            //         isMac = true;
            //     }
            // }
            break;
            return false;
        case KC_ALT_TAB:
            if (record->event.pressed) {
                sticky_mod_press(&alt_tab);
            }
            break;
            return false;
        case KC_CMD_TAB:
            if (record->event.pressed) {
                sticky_mod_press(&cmd_tab);
            }
            break;
            return false;
        case KC_ALT_SFT_TAB:
            if (record->event.pressed) {
                sticky_mod_press(&alt_sft_tab);
            }
            break;
            return false;
        case KC_CMD_SFT_TAB:
            if (record->event.pressed) {
                sticky_mod_press(&cmd_sft_tab);
            }
            break;
            return false;
    }
    return process_record_user(keycode, record);
}


