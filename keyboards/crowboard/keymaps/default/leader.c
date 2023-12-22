#include QMK_KEYBOARD_H
#include "secret.h"
#ifdef LEADER_ENABLE


void leader_end_user(void) {
    if (leader_sequence_one_key(KC_Q)) {
        tap_code16(G(C(KC_Q)));
    } else if (leader_sequence_one_key(OSM(MOD_LSFT))) {
        tap_code(KC_LSFT);
        tap_code(KC_LSFT);
    } else if (leader_sequence_two_keys(KC_C, KC_P)) {
            SEND_STRING(CP);
        wait_ms(50);
        tap_code(KC_ENT);
    } else if (leader_sequence_three_keys(KC_ESC, KC_ESC, KC_ESC)) {
        reset_keyboard();
    } else if (leader_sequence_two_keys(KC_W, KC_P)) {
        SEND_STRING(WP);
    }else if (leader_sequence_two_keys(KC_W, KC_U)) {
         SEND_STRING(WU);
    }else if (leader_sequence_two_keys(KC_W, KC_E)) {
         SEND_STRING(WE);
    }else if (leader_sequence_two_keys(KC_B, KC_P)) {
        SEND_STRING(BP);
    }else if (leader_sequence_two_keys(KC_C, KC_N)) {
        SEND_STRING(CN);
    }else if (leader_sequence_two_keys(KC_G, KC_M)) {
        SEND_STRING(GM);
    } else if (leader_sequence_one_key(KC_P)) {
        tap_code16(S(C(G(KC_4))));
    } else if (leader_sequence_one_key(KC_X)) {
        bootloader_jump();
    }
    else if (leader_sequence_one_key(KC_D)) {
        tap_code16(A(C(KC_DEL)));
    }
}

#endif
