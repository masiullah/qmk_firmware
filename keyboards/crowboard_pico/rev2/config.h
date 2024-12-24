/* Copyright 2018-2020
ENDO Katsuhiro <ka2hiro@curlybracket.co.jp>
David Philip Barr <@davidphilipbarr>
Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U
// Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#ifdef VIA_ENABLE
#    define TRANSIENT_EEPROM_SIZE 500
#endif

#ifdef OLED_ENABLE
/* i2c config for oleds */
#    define OLED_DISPLAY_128X32
#    define I2C_DRIVER I2CD0
#    define I2C1_SCL_PIN GP1
#    define I2C1_SDA_PIN GP0
#    define OLED_TIMEOUT 15000
#    define OLED_SCROLL_TIMEOUT 5000
#endif

/* Audio */
#ifdef AUDIO_ENABLE
#    define AUDIO_PIN GP5
#    define AUDIO_PWM_DRIVER PWMD2
#    define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_B
#    define AUDIO_INIT_DELAY

#    define STARTUP_SONG SONG(NO_SOUND)
#endif