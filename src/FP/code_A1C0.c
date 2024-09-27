#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_803905B0(Actor *this);

/* .data */
ActorInfo D_803926C0 = { 0x20E, 0x33E, 0x49C,
    0x1, NULL,
    func_803905B0, func_80326224, func_80325340,
    0, 0, 0.0f, 0
};

/* .code */
void func_803905B0(Actor *this){
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        actor_collisionOff(this);
    }
    this->marker->propPtr->unk8_3 = BOOL(func_8038DD14(this));
}
