#include <ultra64.h>
#include "functions.h"
#include "variables.h"


Actor* func_80325888(ActorMarker *, Gfx **, Mtx**, u32);



void func_8038FCB0(Actor *);

/* .data */
ActorInfo D_80390D70 = {0xDC, actor_bigalligator, 0x397, 0x01, NULL,
    func_8038FCB0, func_80326224, func_80325888,
    {0,0,0,0}, 0.0f, {0,0,0,0}
};

/* .code */
void func_8038FCB0(Actor *this){
    if(this->initialized)
        return;
    this->marker->propPtr->unk8_3 = 1;
    actor_collisionOff(this);
    this->initialized = 1;
}
