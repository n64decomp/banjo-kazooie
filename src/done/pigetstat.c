#include <ultra64.h>
#include "functions.h"
#include "variables.h"

u32 osPiGetStatus(void) {
    return IO_READ(PI_STATUS_REG);
}
