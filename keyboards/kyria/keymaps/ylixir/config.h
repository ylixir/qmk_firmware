/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
//#define SPLIT_USB_DETECT
//#define NO_USB_STARTUP_CHECK

#define TAPPING_TERM 200
#define ENCODER_RESOLUTION 2

/* issue with avr-gcc putting enums in assembly */
#if !defined(__ASSEMBLER__)
enum colemak_combos {
  CK_1,
  CK_2,
  CK_3,
  CK_4,
  CK_5,
  CK_6,
  CK_7,
  CK_8,
  CK_9,
  CK_0,
  CK_TILDE,
  CK_GRAVE,
  CK_LT,
  CK_GT,
  CK_EQL,
  CK_UNDERSCORE,
  CK_MINUS,
  CK_PLUS,
  CK_EXCLAIM,
  CK_AT,
  CK_HASH,
  CK_DOLLAR,
  CK_PERCENT,
  CK_CIRCUMFLEX,
  CK_AMPERSAND,
  CK_ASTERISK,
  CK_SCLN,
  CK_COLON,
  COMBO_AUTO_COUNT,
};
#define COMBO_COUNT COMBO_AUTO_COUNT
#endif
