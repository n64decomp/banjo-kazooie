#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038B7E8(Actor *this);

/* .data */
ActorInfo D_80390A80 = {
    0x2F, 0x1C7, 0x41B, 0x0, NULL,
    func_8038B7E8, NULL, func_80325888,
    {0, 0}, 0, 0.0f, {0,0,0,0}
};

/* .code */
void func_8038B6E0(Actor *this, s32 arg1){
    if(arg1 == 2){
        if(this->state == 1){
            func_8030E6D4(SFX_90_SWITCH_PRESS);
        }
        actor_collisionOff(this);
        this->position_y -= 35.0f;
        if(this->state == 1){
            levelSpecificFlags_set(0x30, TRUE);
            func_803204E4(0xe, 1);
            timedFunc_set_0(1.0f, func_803228D8);
            timedFunc_set_3(1.0f, (TFQM3)func_802E4078, MAP_31_RBB_RUSTY_BUCKET_BAY, 0, 0);
        }
    }
    this->state = arg1;
}

void func_8038B7BC(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    func_8038B6E0(actor, 2);
}

void func_8038B7E8(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        this->marker->propPtr->unk8_3 = 1;
        marker_setCollisionScripts(this->marker, NULL, func_8038B7BC, NULL);
        if(jiggyscore_isSpawned(JIGGY_53_RBB_SNORKEL))
            func_8038B6E0(this, 2);
        else
            func_8038B6E0(this, 1);
    }
}