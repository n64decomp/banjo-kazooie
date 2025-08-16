#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80390820(Actor *this);

/* .data */
ActorInfo D_80394980 = { 0x299, 0x3C3, 0x0, 0x0, NULL, func_80390820, actor_update_func_80326224, func_80325340, 0, 0, 0.0f, 0};

/* .code */
void func_80390820(Actor *this)
{
    if (!this->unk38_0 && subaddie_playerIsWithinSphereAndActive(this, 200))
    {
        FUNC_8030E624(SFX_61_CARTOONY_FALL, 0.8f, 32000);
        timed_playSfx(0.5f, SFX_31_BANJO_OHHWAAOOO, 1, 32000);
        this->unk38_0 = TRUE;
    }
}
