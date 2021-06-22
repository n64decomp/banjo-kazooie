#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern Actor *func_80325934(ActorMarker*, Gfx **, Mtx **, u32);

void func_802C9C30(Actor* this);

/* .data */
ActorInfo D_80366C50 = { 
    0x5f, 0x51, 0x6d6, 0, NULL,
    func_802C9C30, func_80326224, func_80325934,
    {0, 0, 0, 0}, 0.6f, {0,0,0,0}
};

/* .code */
void func_802C9C30(Actor* this){
    this->scale = 0.42857143f;
}