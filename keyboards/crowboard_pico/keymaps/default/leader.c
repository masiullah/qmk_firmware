#include QMK_KEYBOARD_H
#include "secret.h"

#ifdef LEADER_ENABLE

#    ifdef AUDIO_ENABLE
float song_unlock[][2] = SONG(QWERTY_SOUND);
#    endif
void leader_end_user(void) {
    if (leader_sequence_one_key(KC_Q)) {
        if (keymap_config.swap_lctl_lgui) {
            tap_code16(G(KC_L));
        } else {
            tap_code16(G(C(KC_Q)));
        }
        if (!secure_is_locked()) {
            secure_lock();
        }
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
    } else if (leader_sequence_two_keys(KC_W, KC_U)) {
        SEND_STRING(WU);
    } else if (leader_sequence_two_keys(KC_W, KC_E)) {
        SEND_STRING(WE);
    } else if (leader_sequence_two_keys(KC_B, KC_P)) {
        SEND_STRING(BP);
    } else if (leader_sequence_two_keys(KC_C, KC_N)) {
        SEND_STRING(CN);
    } else if (leader_sequence_two_keys(KC_G, KC_M)) {
        SEND_STRING(GM);
    } else if (leader_sequence_two_keys(KC_S, KC_P)) {
        SEND_STRING(SP);
    } else if (leader_sequence_one_key(KC_P)) {
        tap_code16(S(C(G(KC_4))));
    } else if (leader_sequence_one_key(KC_X)) {
        bootloader_jump();
    } else if (leader_sequence_one_key(KC_D)) {
        if (keymap_config.swap_lctl_lgui) {
            tap_code16(A(C(KC_DEL)));
        } else {
            tap_code16(C(A(KC_ESC)));
        }
        
    } else if (leader_sequence_one_key(KC_I)) {
        if (keymap_config.swap_lctl_lgui) {
            tap_code16(G(KC_TAB));
        } else {
            tap_code16(C(KC_UP));
        }
#    ifdef SECURE_ENABLE
    } else if (leader_sequence_one_key(KC_U)) {
        if (secure_is_locked()) {
            secure_unlock();
#        ifdef AUDIO_ENABLE
            PLAY_SONG(song_unlock);
#        endif
        }
#    endif
    }
}
void leader_start_user(void) {
    // Do something when the leader key is pressed
}
#endif
