#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chEngineFanSwitch_update(Actor *this);

/* .data */
ActorInfo D_803906B0 = {
    0x194, 0x1BE, 0x412, 0x0, NULL,
    chEngineFanSwitch_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

/* .code */
void RBB_func_803898A0(void){
    mapSpecificFlags_set(0, 1);
}

void chEngineFanSwitch_setState(Actor * this, s32 arg1){
    this->state = arg1;
    if(this->state == 2){
        func_8030E6D4(SFX_90_SWITCH_PRESS);
        this->position_y -= 35.0f;
        func_80324E38(1.0f, 3);
        timed_setStaticCameraToNode(1.0f, 0);
        timedFunc_set_0(1.0f, RBB_func_803898A0);
        timed_exitStaticCamera(5.0f);
        func_80324E38(5.0f, 0);
    }
}

void __chEngineFanSwitch_pressCallback(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    if(actor->state == 1){
        chEngineFanSwitch_setState(actor, 2);
    }
}

void chEngineFanSwitch_update(Actor *this){
    if(!this->volatile_initialized){ //initialize
        this->marker->propPtr->unk8_3 = 1;
        this->volatile_initialized = TRUE;
        mapSpecificFlags_set(0, 0);
        marker_setCollisionScripts(this->marker, NULL, __chEngineFanSwitch_pressCallback, NULL);
        if(this->state == 0){
            this->position_x = -3209.95f;
            this->position_y = 1164.5f;
            this->position_z = -2649.95f;
            this->yaw = -90.0f;
            chEngineFanSwitch_setState(this, 1);
        }
    }
}
