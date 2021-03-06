/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

//#define USE_MATRIX_I2C

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS
#define FORCE_NKRO

#define SSD1306OLED

#define USE_SERIAL_PD2

// repeat held key
// #define TAPPING_FORCE_HOLD
#undef TAPPING_FORCE_HOLD
// How long can you hold the key until it counts as a hold.
#define TAPPING_TERM 200
// Number of times to tap for tap toggle (TT) macro.
#define TAPPING_TOGGLE 3
// #define PERMISSIVE_HOLD
// #undef IGNORE_MOD_TAP_INTERRUPT

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #undef RGBLIGHT_ANIMATIONS
    #define RGBLED_NUM (27*2)
    #define RGBLED_SPLIT { 27, RGBLED_NUM }
    #define RGBLIGHT_LIMIT_VAL 60
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
    #define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
    #define RGBLIGHT_SLEEP
    #define RGBLIGHT_LAYERS
#endif
