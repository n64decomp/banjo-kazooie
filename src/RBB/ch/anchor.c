#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038BF28(Actor *this);

/* .data */
ActorInfo RBB_D_80390AE0 = {
    0x31, 0x1C9, 0x41D, 0x0, NULL,
    func_8038BF28, NULL, actor_draw,
    0, 0, 0.0f, 0
};

/* .code */
void RBB_func_8038BEA0(Actor *this, s32 arg1){
    if(arg1 == 1)
        skeletalAnim_set(this->unk148, ASSET_141_ANIM_ANCHOR_LOWERED, 0.0f, 5.5f);
    
    if(arg1 == 2){
        skeletalAnim_set(this->unk148, ASSET_142_ANIM_ANCHOR_RISING, 0.0f, 8.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    }
    this->state = arg1;
}

void func_8038BF28(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        this->position_x = -5100.0f;
        this->position_y = -2600.0f;
        this->position_z = 1460.0f;
        this->marker->propPtr->unk8_3 = 1;
        this->yaw = 0.0f;
        RBB_func_8038BEA0(this, 1);
        if(jiggyscore_isSpawned(JIGGY_53_RBB_SNORKEL)){
            marker_despawn(this->marker);
        }
    }
    else{
        if(this->state == 1 && mapSpecificFlags_get(8)){
            RBB_func_8038BEA0(this, 2);
        }
    }
}

