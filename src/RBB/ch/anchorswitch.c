#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chAnchorSwitch_update(Actor *this);

/* .data */
ActorInfo D_80390A80 = {
    0x2F, 0x1C7, 0x41B, 0x0, NULL,
    chAnchorSwitch_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

/* .code */
void __chAnchorSwitch_setState(Actor *this, s32 arg1){
    if(arg1 == 2){
        if(this->state == 1){
            func_8030E6D4(SFX_90_SWITCH_PRESS);
        }
        actor_collisionOff(this);
        this->position_y -= 35.0f;
        if(this->state == 1){
            levelSpecificFlags_set(LEVEL_FLAG_30_RBB_UNKNOWN, TRUE);
            volatileFlag_set(VOLATILE_FLAG_E, 1);
            timedFunc_set_0(1.0f, func_803228D8);
            timedFunc_set_3(1.0f, (GenFunction_3)transitionToMap, MAP_31_RBB_RUSTY_BUCKET_BAY, 0, 0);
        }
    }
    this->state = arg1;
}

void __chAnchorSwitch_press(ActorMarker *marker, ActorMarker *arg1){
    Actor *actor = marker_getActor(marker);
    __chAnchorSwitch_setState(actor, 2);
}

void chAnchorSwitch_update(Actor *this){
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = 1;
        marker_setCollisionScripts(this->marker, NULL, __chAnchorSwitch_press, NULL);
        if(jiggyscore_isSpawned(JIGGY_53_RBB_SNORKEL))
            __chAnchorSwitch_setState(this, 2);
        else
            __chAnchorSwitch_setState(this, 1);
    }
}
