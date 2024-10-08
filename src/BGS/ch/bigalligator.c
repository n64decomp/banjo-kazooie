#include <ultra64.h>
#include "functions.h"
#include "variables.h"





void func_8038FCB0(Actor *);

/* .data */
ActorInfo D_80390D70 = {MARKER_DC_BIG_ALLIGATOR, ACTOR_F6_BIG_ALLIGATOR, ASSET_397_MODEL_BIG_ALLIGATOR, 0x01, NULL,
    func_8038FCB0, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

/* .code */
void func_8038FCB0(Actor *this){
    if(this->initialized)
        return;
    this->marker->propPtr->unk8_3 = 1;
    actor_collisionOff(this);
    this->initialized = TRUE;
}
