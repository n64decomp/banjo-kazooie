#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_80390820(Actor *this)
{
    if (!this->unk38_0 && func_80329530(this, 200))
    {
        func_8030E624(0x665F4061);
        timed_playSfx(0.5f, 0x31, 1, 0x7D00);
        this->unk38_0 = TRUE;
    }
}
