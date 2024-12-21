
 #include QMK_KEYBOARD_H

bool     is_gui_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t gui_tab_timer     = 0;     // we will be using them soon.
bool     is_alt_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t alt_tab_timer     = 0;     // we will be using them soon.

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (keycode == SE_TOGG) {
            return true;
        }
        else if (keycode == SE_LOCK) {
            return true;
        }
        else if (keycode == SE_UNLK) {
            return true;
        }
        else if (secure_is_locked()) {
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