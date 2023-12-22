#include QMK_KEYBOARD_H
#include "layers.h"

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// void render_logo(void) {
//     static const char PROGMEM logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0};
//     oled_write_P(logo, false);
// }

bool oled_task_user(void) {
    // render_logo();
    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_ln("BASE\n", true);
            break;
        case NAV:
            oled_write_ln("NAV\n", true);
            break;
        case NUM:
            oled_write_ln("NUM\n", true);
            break;

        case SYM:
            oled_write_ln("SYM\n", true);
            break;
        case SRT:
            oled_write_ln("SRT\n", true);
            break;
        case ADJ:
            oled_write_ln("ADJ\n", true);
            break;
        case NPD:
            oled_write_ln("NPD\n", true);
            break;
        case MOS:
            oled_write_ln("MOS\n", true);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln("Undefined", true);
    }

    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_ln("", true);
    // oled_write_ln("Lock", false);
    oled_write_ln("CWD", is_caps_word_on());
    oled_write_ln("CAPS", led_usb_state & (2));

    /* Show Ctrl-Gui Swap options */
    oled_write_ln("", true);
    // oled_write_ln("Mode", false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln("WIN", true);
    } else {
        oled_write_ln("MAC", true);
    }
    /* Show Mod  */
    uint8_t modifiers = get_mods() | get_oneshot_mods();
    oled_write_ln("", true);
    // oled_write_ln("Mods", false);
    oled_write_ln("SFT", (modifiers & MOD_MASK_SHIFT));
    oled_write_ln("CTL", (modifiers & MOD_MASK_CTRL));
    oled_write_ln("ALT", (modifiers & MOD_MASK_ALT));
    oled_write_ln("GUI", (modifiers & MOD_MASK_GUI));

    return false;
}

#endif
