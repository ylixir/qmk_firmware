#ifndef HALF_40_H
#define HALF_40_H

#include "quantum.h"

#define LAYOUT_RIGHT_HALF( \
    R00, R01, R02, R03, R04, R05, \
    R10, R11, R12, R13, R14, R15, \
    R20, R21, R22, R23, R24, R25, \
    R30, R31, R32,R33, R34,  R35   \
    ) \
    LAYOUT( \
        R05, R00, R01, R02, R03, R04,   R00, R01, R02, R03, R04, R05, \
        R15, R11, R12, R21, R14, R10,   R10, R11, R12, R13, R14, R15, \
        R25, R13, R22, R23, R24, R20,   R20, R21, R22, R23, R24, R25, \
        R35, R31, R32, R33, R34, R30,   R30, R31, R32, R33, R34, R35 \
    )

#endif
