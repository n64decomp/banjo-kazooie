#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chEngineFanSwitch_update(Actor *this);

/* .data */
ActorInfo chRBBGreyPropellerSwitch = {
    MARKER_194_RBB_GREY_PROPELLER_SWITCH, ACTOR_1BE_RBB_GREY_PROPELLOR_SWITCH, ASSET_412_MODEL_RBB_GREY_PROPELLER_SWITCH,
    0x0, NULL,
    chEngineFanSwitch_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

enum chrbbgreypropellerswitch_state_e {
    CH_RBB_GREY_PROPELLER_SWITCH_STATE_0_NOT_INIT,
    CH_RBB_GREY_PROPELLER_SWITCH_STATE_1_NOT_PRESSED,
    CH_RBB_GREY_PROPELLER_SWITCH_STATE_2_PRESSED
};

/* .code */
void chEngineFanSwitch_setPressedFlag(void){
    mapSpecificFlags_set(RBB_MAIN_SPECIFIC_FLAG_0_PROPELLER, TRUE);
}

void chEngineFanSwitch_setState(Actor * this, s32 arg1){
    this->state = arg1;
    if(this->state == CH_RBB_GREY_PROPELLER_SWITCH_STATE_2_PRESSED){
        func_8030E6D4(SFX_90_SWITCH_PRESS);
        this->position_y -= 35.0f;
        func_80324E38(1.0f, 3);
        timed_setStaticCameraToNode(1.0f, 0);
        timedFunc_set_0(1.0f, chEngineFanSwitch_setPressedFlag);
        timed_exitStaticCamera(5.0f);
        func_80324E38(5.0f, 0);
    }
}

void __chEngineFanSwitch_pressCallback(ActorMarker *marker, ActorMarker *arg1){
    Actor *actor = marker_getActor(marker);
    if(actor->state == CH_RBB_GREY_PROPELLER_SWITCH_STATE_1_NOT_PRESSED){
        chEngineFanSwitch_setState(actor, CH_RBB_GREY_PROPELLER_SWITCH_STATE_2_PRESSED);
    }
}

void chEngineFanSwitch_update(Actor *this){
    if(!this->volatile_initialized){ //initialize
        this->marker->propPtr->unk8_3 = 1;
        this->volatile_initialized = TRUE;
        mapSpecificFlags_set(RBB_MAIN_SPECIFIC_FLAG_0_PROPELLER, FALSE);
        marker_setCollisionScripts(this->marker, NULL, __chEngineFanSwitch_pressCallback, NULL);
        if(this->state == CH_RBB_GREY_PROPELLER_SWITCH_STATE_0_NOT_INIT){
            this->position_x = -3209.95f;
            this->position_y = 1164.5f;
            this->position_z = -2649.95f;
            this->yaw = -90.0f;
            chEngineFanSwitch_setState(this, CH_RBB_GREY_PROPELLER_SWITCH_STATE_1_NOT_PRESSED);
        }
    }
}
