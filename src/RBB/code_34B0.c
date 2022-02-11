#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_803899C0(Actor *this);

/* .data */
ActorInfo D_803906B0 = {
    0x194, 0x1BE, 0x412, 0x0, NULL,
    func_803899C0, NULL, func_80325888,
    {0, 0}, 0, 0.0f, {0,0,0,0}
};

/* .code */
void func_803898A0(void){
    mapSpecificFlags_set(0, 1);
}

void func_803898C4(Actor * this, s32 arg1){
    this->state = arg1;
    if(this->state == 2){
        func_8030E6D4(SFX_90_SWITCH_PRESS);
        this->position_y -= 35.0f;
        func_80324E38(1.0f, 3);
        timed_setCameraToNode(1.0f, 0);
        timedFunc_set_0(1.0f, func_803898A0);
        func_80324E88(5.0f);
        func_80324E38(5.0f, 0);
    }
}

void func_80389980(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    if(actor->state == 1){
        func_803898C4(actor, 2);
    }
}

void func_803899C0(Actor *this){
    if(!this->unk16C_4){
        this->marker->propPtr->unk8_3 = 1;
        this->unk16C_4 = 1;
        mapSpecificFlags_set(0, 0);
        marker_setCollisionScripts(this->marker, NULL, func_80389980, NULL);
        if(this->state == 0){
            this->position_x = -3209.95f;
            this->position_y = 1164.5f;
            this->position_z = -2649.95f;
            this->yaw = -90.0f;
            func_803898C4(this, 1);
        }
    }
}
