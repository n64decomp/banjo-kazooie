#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chAnchor_update(Actor *this);

/* .data */
ActorInfo chAnchor = {
    MARKER_31_ANCHOR, ACTOR_1C9_ANCHOR, ASSET_41D_MODEL_ANCHOR,
    0x0, NULL,
    chAnchor_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

enum chanchor_state_e {
    CH_ANCHOR_STATE_0_NOT_INIT,
    CH_ANCHOR_STATE_1_LOWERED,
    CH_ANCHOR_STATE_2_RAISED
};

/* .code */
void chAnchor_setState(Actor *this, s32 next_state){
    if(next_state == CH_ANCHOR_STATE_1_LOWERED)
        skeletalAnim_set(this->unk148, ASSET_141_ANIM_ANCHOR_LOWERED, 0.0f, 5.5f);
    
    if(next_state == CH_ANCHOR_STATE_2_RAISED){
        skeletalAnim_set(this->unk148, ASSET_142_ANIM_ANCHOR_RISING, 0.0f, 8.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    }
    this->state = next_state;
}

void chAnchor_update(Actor *this){
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->position_x = -5100.0f;
        this->position_y = -2600.0f;
        this->position_z = 1460.0f;
        this->marker->propPtr->unk8_3 = 1;
        this->yaw = 0.0f;
        chAnchor_setState(this, CH_ANCHOR_STATE_1_LOWERED);
        if(jiggyscore_isSpawned(JIGGY_53_RBB_SNORKEL)){
            marker_despawn(this->marker);
        }
    }
    else{
        if(this->state == CH_ANCHOR_STATE_1_LOWERED
            && mapSpecificFlags_get(8))
        {
            chAnchor_setState(this, CH_ANCHOR_STATE_2_RAISED);
        }
    }
}

