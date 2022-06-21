#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80390820(Actor *this);

/* .data */
ActorInfo D_80394980 = { 0x299, 0x3C3, 0x0, 0x0, NULL, func_80390820, func_80326224, func_80325340, 0, 0, 0.0f, 0};

/* .code */
void func_80390820(Actor *this)
{
    if (!this->unk38_0 && func_80329530(this, 200))
    {
        func_8030E624(0x665F4061);
        timed_playSfx(0.5f, SFX_31_BANJO_OHHWAAOOO, 1, 32000);
        this->unk38_0 = TRUE;
    }
}
