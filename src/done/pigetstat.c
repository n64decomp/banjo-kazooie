#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define osPiGetStatus func_800020E0

s32 osPiGetStatus(void) {
    return IO_READ(PI_STATUS_REG);
}
