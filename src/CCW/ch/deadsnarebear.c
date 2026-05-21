#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chDeadSnarebear_update(Actor *this);


ActorAnimationInfo chDeadSnarebearAnimations[] = {
    {0x000, 0.0f},
    {ASSET_234_ANIM_DEAD_SNAREBEAR, 2.0f}
};

ActorInfo chDeadSnarebear = {
    MARKER_251_DEAD_SNAREBEAR, ACTOR_37E_DEAD_SNAREBEAR, ASSET_506_CCW_DEAD_SNAREBEAR,
    0x1, chDeadSnarebearAnimations,
    chDeadSnarebear_update, actor_update_func_80326224, actor_draw, 
    0, 0, 0.0f, 0
};

/* .code */
void chDeadSnarebear_update(Actor *this){
    this->marker->propPtr->unk8_3 = TRUE;
    actor_collisionOff(this);
}
