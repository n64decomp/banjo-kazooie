#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chAnchorSwitch_update(Actor *this);

/* .data */
ActorInfo chAnchorSwitch = {
    MARKER_2F_ANCHOR_SWITCH, ACTOR_1C7_ANCHOR_SWITCH, ASSET_41B_MODEL_ANCHOR_SWITCH,
    0x0, NULL,
    chAnchorSwitch_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

enum chanchorswitch_state_e {
    CH_ANCHOR_SWITCH_STATE_0_NOT_INIT,
    CH_ANCHOR_SWITCH_STATE_1_NOT_PRESSED,
    CH_ANCHOR_SWITCH_STATE_2_PRESSED
};

/* .code */
void __chAnchorSwitch_setState(Actor *this, s32 next_state){
    if(next_state == CH_ANCHOR_SWITCH_STATE_2_PRESSED){
        if(this->state == CH_ANCHOR_SWITCH_STATE_1_NOT_PRESSED){
            func_8030E6D4(SFX_90_SWITCH_PRESS);
        }
        actor_collisionOff(this);
        this->position_y -= 35.0f;
        if(this->state == CH_ANCHOR_SWITCH_STATE_1_NOT_PRESSED){
            levelSpecificFlags_set(LEVEL_FLAG_30_RBB_UNKNOWN, TRUE);
            volatileFlag_set(VOLATILE_FLAG_E, 1);
            timedFunc_set_0(1.0f, musicKeepsPlaying);
            timedFunc_set_3(1.0f, (GenFunction_3)transitionToMap, MAP_31_RBB_RUSTY_BUCKET_BAY, 0, 0);
        }
    }
    this->state = next_state;
}

void __chAnchorSwitch_press(ActorMarker *marker, ActorMarker *arg1){
    Actor *actor = marker_getActor(marker);
    __chAnchorSwitch_setState(actor, CH_ANCHOR_SWITCH_STATE_2_PRESSED);
}

void chAnchorSwitch_update(Actor *this){
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = 1;
        marker_setCollisionScripts(this->marker, NULL, __chAnchorSwitch_press, NULL);
        if(jiggyscore_isSpawned(JIGGY_53_RBB_SNORKEL))
            __chAnchorSwitch_setState(this, CH_ANCHOR_SWITCH_STATE_2_PRESSED);
        else
            __chAnchorSwitch_setState(this, CH_ANCHOR_SWITCH_STATE_1_NOT_PRESSED);
    }
}
