#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void chGobiRope_update(Actor *this);

/* .data */
ActorInfo chGobiRope = { MARKER_BD_GOBI_ROPE, ACTOR_12F_GOBI_ROPE, ASSET_3E3_MODEL_GOBI_ROPE, 
    0, NULL, 
    chGobiRope_update, actor_update_func_80326224, actor_draw, 
    0, 0x533, 0.0f, 0
};

/* .code */
void chGobiRope_setState(Actor *this, s32 next_state){
    this->state = next_state;

    if(this->state == 1){
        skeletalAnim_set(this->unk148, ASSET_DD_ANIM_GOBI_ROPE, 0.5f, 4.0f);
    }

    if(this->state == 2){
        skeletalAnim_set(this->unk148, ASSET_DC_ANIM_GOBI_ROPE_PULLING, 1.0f, 5.0f);
    }

    if(this->state == 3){
        skeletalAnim_set(this->unk148, 0xF5, 0.1f, 1.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    }

    if(this->state == 4){
        marker_despawn(this->marker);
    }
}

void chGobiRope_update(Actor *this){
    Actor *sp2C;
    f32 sp28;
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        actor_collisionOff(this);
        sp2C = actorArray_findClosestActorFromActorId(this->position, ACTOR_12E_GOBI_1, -1, &sp28);
        if(sp2C){
            this->position_x = sp2C->position_x;
            this->position_y = sp2C->position_y;
            this->position_z = sp2C->position_z;
        }
        chGobiRope_setState(this, 1);
        if( jiggyscore_isSpawned(JIGGY_44_GV_GOBI_1)
            && !volatileFlag_get(VOLATILE_FLAG_1)
        ){
            marker_despawn(this->marker);
        }
    }
    else{
        if(this->state == 1 || this->state == 2){
            if(this->state == 1 && func_80387354()){
                chGobiRope_setState(this, 2);
            }
            else{
                if(func_80387360())
                    chGobiRope_setState(this, 4);
            }
        }//L80388AB4
        if(this->state == 2){
            if(skeletalAnim_getLoopCount(this->unk148) > 0)
                chGobiRope_setState(this, 1);
        }
        if(this->state == 3){
            if(skeletalAnim_getLoopCount(this->unk148) > 0)
                chGobiRope_setState(this, 4);
        }
    }
}
