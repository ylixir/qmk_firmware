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

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

// #define MASTER_LEFT
#define MASTER_RIGHT
// #define EE_HANDS

//fix lag on spacebar layer switching
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS
#define C6_AUDIO

#ifdef AUDIO_ENABLE
  #define VADER \
    HD_NOTE(_A4), HD_NOTE(_A4), HD_NOTE(_A4), QD_NOTE(_F4), QD_NOTE(_C5), \
    HD_NOTE(_A4), QD_NOTE(_F4),  QD_NOTE(_C5), WD_NOTE(_A4), \
    HD_NOTE(_E5), HD_NOTE(_E5), HD_NOTE(_E5), QD_NOTE(_F5), QD_NOTE(_C5), \
    HD_NOTE(_A4), QD_NOTE(_F4),  QD_NOTE(_C5), WD_NOTE(_A4)

#define COIN \
    E__NOTE(_A5  ),      \
    HD_NOTE(_E6  ),

#define ONE_UP \
    Q__NOTE(_E6  ),  \
    Q__NOTE(_G6  ),  \
    Q__NOTE(_E7  ),  \
    Q__NOTE(_C7  ),  \
    Q__NOTE(_D7  ),  \
    Q__NOTE(_G7  ),

  #define GAME_ON \
    Q__NOTE(_E5), \
    H__NOTE(_E5), \
    H__NOTE(_E5), \
    Q__NOTE(_C5), \
    H__NOTE(_E5), \
    W__NOTE(_G5), \
    Q__NOTE(_G4),

  #define GAME_OFF \
    HD_NOTE(_C5 ), \
    HD_NOTE(_G4 ), \
    H__NOTE(_E4 ), \
    H__NOTE(_A4 ), \
    H__NOTE(_B4 ), \
    H__NOTE(_A4 ), \
    H__NOTE(_AF4), \
    H__NOTE(_BF4), \
    H__NOTE(_AF4), \
    WD_NOTE(_G4 ),

#define SONIC_RING_SOUND \
    E__NOTE(_E6),  \
    E__NOTE(_G6),  \
    HD_NOTE(_C7),

#define ZELDA_PUZZLE_SOUND \
    Q__NOTE(_G5),     \
    Q__NOTE(_FS5),    \
    Q__NOTE(_DS5),     \
    Q__NOTE(_A4),    \
    Q__NOTE(_GS4),     \
    Q__NOTE(_E5),     \
    Q__NOTE(_GS5),     \
    HD_NOTE(_C6),

#define ZELDA_TREASURE_SOUND \
    Q__NOTE(_A4 ), \
    Q__NOTE(_AS4), \
    Q__NOTE(_B4 ), \
    HD_NOTE(_C5 ), \

#define STARTUP_SONG SONG(ONE_UP)
#define GOODBYE_SONG SONG(COIN)
#endif

/* issue with avr-gcc putting enums in assembly */
#if !defined(__ASSEMBLER__)
enum shared_combos {
  SH_1,
  SHARED_COMBO_TOP,
};
enum qwerty_combos {
  QW_2 = SHARED_COMBO_TOP,
  QW_3,
  QW_4,
  QW_5,
  QW_6,
  QW_7,
  QW_8,
  QW_9,
  QW_0,
  QWERTY_COMBO_TOP,
};
enum colemak_combos {
  CK_2 = QWERTY_COMBO_TOP,
  CK_3,
  CK_4,
  CK_5,
  CK_6,
  CK_7,
  CK_8,
  CK_9,
  CK_0,
  CK_TILDE,
  CK_DOUBLE_QUOTE,
  CK_LT,
  CK_GT,
  CK_LCBR,
  CK_RCBR,
  CK_MINUS,
  CK_PLUS,
  CK_SCLN,
  CK_UNDS,
  COMBO_AUTO_COUNT,
};

#define TAPPING_TERM 200
#define COMBO_COUNT COMBO_AUTO_COUNT
#endif

#endif
