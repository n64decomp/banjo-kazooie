#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028E668(f32[3], f32, f32, f32);

void chCaveWozza_update(Actor *this);

/* .data */
extern ActorAnimationInfo chCaveWozzaAnimations[]= {
    {0, 0.0f},
    {ASSET_221_ANIM_WOZZA_IN_CAVE, 5.0f}
};

extern ActorInfo gChWozzaCave = { MARKER_20F_WOZZA_IN_CAVE, ACTOR_33F_WOZZA_IN_CAVE, ASSET_494_MODEL_WOZZA,
    0x1, chCaveWozzaAnimations,
    chCaveWozza_update, actor_update_func_80326224, actor_draw,
    2500, 0, 1.6f, 0
};

/* .code */
void chCaveWozza_update(Actor *this){
    if(volatileFlag_get(VOLATILE_FLAG_C4_WOZZA_HIDE_IN_SNS_PARADE)){
        if(!this->volatile_initialized){
            this->volatile_initialized = TRUE;
            this->marker->propPtr->unk8_3 = FALSE;
            actor_collisionOff(this);
            this->unk58_0 = FALSE;
        }
        return;
    }

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = FALSE;
        actor_collisionOn(this);
        this->unk38_31 = jiggyscore_isCollected(JIGGY_32_FP_WOZZA) || levelSpecificFlags_get(LEVEL_FLAG_26_FP_WALRUS_JIGGY_DROPPED) ? 0 : 1;
    }//L80390714
 
    if(this->unk38_31){
        this->unk58_0 = FALSE;
        return;
    }

    this->unk58_0 = TRUE;
    func_8028E668(this->position, 200.0f, -40.0f, 160.0f); //something with collision around Wozza, third value is size
    
    if(this->state == 1){
        this->yaw_ideal = (f32)subaddie_getYawToPlayer(this);
        subaddie_turnToYaw(this, 1.0f);

        if(!gcdialog_hasCurrentTextId()){
            if( actor_animationIsAt(this, 0.09f)
                || actor_animationIsAt(this, 0.19f)
            ){
                sfx_playFadeShorthandDefault(SFX_88_WOZZA_NOISE, 1.0f, 22000, this->position, 500, 2000);
            }

            if( actor_animationIsAt(this, 0.68f)
                || actor_animationIsAt(this, 0.78f)
                || actor_animationIsAt(this, 0.85f)
                || actor_animationIsAt(this, 0.92f)
                
            ){
                sfx_playFadeShorthandDefault(SFX_3F2_BOING, 0.8f, 24000, this->position, 500, 2000);
            }
        }

        if (subaddie_playerIsWithinSphereAndActive(this, 350)) {
            if (player_getTransformation() == TRANSFORM_4_WALRUS) {
                if (!levelSpecificFlags_get(LEVEL_FLAG_31_FP_WOZZA_WALRUS_TALKED)) {
                    if (gcdialog_showDialog(ASSET_C27_DIALOG_WOZZA_CAVE_MEET_AS_WALRUS, 0x23, NULL, NULL, NULL, NULL)) {
                        levelSpecificFlags_set(LEVEL_FLAG_31_FP_WOZZA_WALRUS_TALKED, TRUE);
                    }
                }
            }
            else {
                if (!levelSpecificFlags_get(LEVEL_FLAG_32_FP_WOZZA_BEAR_TALKED)) {
                    if (gcdialog_showDialog(ASSET_C26_DIALOG_WOZZA_CAVE_MEET_AS_BEAR, 0x23, NULL, NULL, NULL, NULL)) {
                        levelSpecificFlags_set(LEVEL_FLAG_32_FP_WOZZA_BEAR_TALKED, TRUE);
                    }
                }
            }
        }
    }
}
