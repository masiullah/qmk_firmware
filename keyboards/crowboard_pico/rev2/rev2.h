/* Copyright 2018-2020 ENDO Katsuhiro <ka2hiro@curlybracket.co.jp> David Philip Barr <@davidphilipbarr> Pierre Chevalier <pierrechevalier83@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"

enum keyboard_keycodes {
    KC_ALT_TAB = SAFE_RANGE,
    KC_CMD_TAB,
    KC_ALT_SFT_TAB,
    KC_CMD_SFT_TAB,
    STORE_SETUPS,
    PRINT_SETUPS,
    NEW_SAFE_RANGE
};

typedef struct sticky_mod_s {
    uint16_t mod;
    uint16_t keycode;
    bool     active;
    bool     is_shifted;

} sticky_mod;
