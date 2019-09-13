#ifndef MINIDOX_40_H
#define MINIDOX_40_H

#include "quantum.h"

// Used to create a keymap using only KC_ prefixed keys
#define LAYOUT_MINI_DOX( \
    L00, L01, L02,  L03, L04,/*L05, R00,*/R01, R02, R03, R04, R05, \
    L10, L11, L12,  L13, L14,/*L15, R10,*/R11, R12, R13, R14, R15, \
    L20, L21, L22,  L23, L24,/*L25, R20,*/R21, R22, R23, R24, R25, \
  /*L30, L31, L32,*/L33, L34,  L35, R30,  R31, R32/*,R33, R34, R35*/ \
    ) \
    LAYOUT( \
        L00,   L01,   L02,   L03, L04, KC_NO, KC_NO, R01, R02, R03,   R04,   R05, \
        L10,   L11,   L12,   L13, L14, KC_NO, KC_NO, R11, R12, R13,   R14,   R15, \
        L20,   L21,   L22,   L23, L24, KC_NO, KC_NO, R21, R22, R23,   R24,   R25, \
        KC_TRNS,KC_TRNS,KC_TRNS, L33,L34,L35, R30,R31,R32, KC_TRNS,KC_TRNS,KC_TRNS \
    )

#endif