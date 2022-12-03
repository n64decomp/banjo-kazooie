#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802DCA30(Actor *this);

/* .data */
f32 D_803680D0[3] = {0.0f, 0.0f, 0.0f};
ActorInfo D_803680DC = { 
    0x176, 0x1DD, 0x54E, 
    0x1, NULL, 
    func_802DCA30, func_80326224, func_802DC7E0, 
    0, 0, 0.0f, 0
};

/* .bss */
ActorMarker *D_8037DE70;

/* .code */
void func_802DCA20(Actor *this){
    D_8037DE70 = NULL;
}

void func_802DCA30(Actor *this){
    if(!this->initialized){
        this->initialized = TRUE;
        this->depth_mode = MODEL_RENDER_DEPTH_NONE;
        actor_collisionOff(this);
        func_803300D8(this->marker, func_802DCA20);
    }
}


void func_802DCA90(void) {
    Actor *actor;
    if (D_8037DE70 == 0) {
        actor = func_8032813C(0x1DD, D_803680D0, 0);
        D_8037DE70 = actor->marker;
    }
}

void func_802DCAD4(s32 arg0, s32 arg1){
    if(D_8037DE70 == NULL){
        __spawnQueue_add_0(func_802DCA90);
    }
}

void func_802DCB0C(s32 arg0, s32 arg1) {
    ActorMarker *temp_a0;

    temp_a0 = D_8037DE70;
    if (temp_a0 != 0) {
        func_80326310(marker_getActor(temp_a0));
    }
}
