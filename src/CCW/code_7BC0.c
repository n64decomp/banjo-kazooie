#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038DFB0(Actor *this);


ActorAnimationInfo D_8038F8B0[] = {
    {0x000, 0.0f},
    {0x234, 2.0f}
};

ActorInfo D_8038F8C0 = { 0x251, 0x37E, 0x506,
    0x1, D_8038F8B0,
    func_8038DFB0, func_80326224, func_80325888, 
    0, 0, 0.0f, 0
};

/* .code */
void func_8038DFB0(Actor *this){
    this->marker->propPtr->unk8_3 = TRUE;
    actor_collisionOff(this);
}
