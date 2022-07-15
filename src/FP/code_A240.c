#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028E668(f32[3], f32, f32, f32);

void func_80390630(Actor *this);

/* .data */
extern ActorAnimationInfo D_803926F0[]= {
    {0, 0.0f},
    {ASSET_221_ANIM_WOZZA_IN_CAVE, 5.0f}
};

extern ActorInfo D_80392700 = { MARKER_20F_WOZZA_IN_CAVE, ACTOR_33F_WOZZA_IN_CAVE, ASSET_494_MODEL_WOZZA,
    0x1, D_803926F0,
    func_80390630, func_80326224, func_80325888,
    2500, 0, 1.6f, 0
};

/* .code */
void func_80390630(Actor *this){
    if(func_803203FC(0xC4)){
        if(!this->unk16C_4){
            this->unk16C_4 = TRUE;
            this->marker->propPtr->unk8_3 = FALSE;
            actor_collisionOff(this);
            this->unk58_0 = FALSE;
        }
        return;
    }

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = FALSE;
        actor_collisionOn(this);
        this->unk38_31 = jiggyscore_isCollected(JIGGY_32_FP_WOZZA) || levelSpecificFlags_get(0x26) ? 0 : 1;
    }//L80390714
 
    if(this->unk38_31){
        this->unk58_0 = FALSE;
        return;
    }

    this->unk58_0 = TRUE;
    func_8028E668(this->position, 200.0f, -40.0f, 160.0f);
    
    if(this->state == 1){
        this->yaw_moving = (f32)func_80329784(this);
        func_80328FB0(this, 1.0f);

        if(!func_803114B0()){
            if( actor_animationIsAt(this, 0.09f)
                || actor_animationIsAt(this, 0.19f)
            ){
                FUNC_8030E8B4(SFX_88_WOZZA_NOISE, 1.0f, 22000, this->position, 500, 2000);
            }

            if( actor_animationIsAt(this, 0.68f)
                || actor_animationIsAt(this, 0.78f)
                || actor_animationIsAt(this, 0.85f)
                || actor_animationIsAt(this, 0.92f)
                
            ){
                FUNC_8030E8B4(SFX_3F2_UNKNOWN, 0.8f, 24000, this->position, 500, 2000);
            }
        }

        if(func_80329530(this, 350)){
            if(player_getTransformation() == TRANSFORM_4_WALRUS){
                if(!levelSpecificFlags_get(0x31)){
                    if(func_80311480(0xc27, 0x23, NULL, NULL, NULL, NULL)){
                        levelSpecificFlags_set(0x31, TRUE);
                    }
                }
            }
            else{
                 if(!levelSpecificFlags_get(0x32)){
                    if(func_80311480(0xc26, 0x23, NULL, NULL, NULL, NULL)){
                        levelSpecificFlags_set(0x32, TRUE);
                    }
                }
            }
        }
    }
}
