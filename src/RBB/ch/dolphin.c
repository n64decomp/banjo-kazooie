#include <ultra64.h>
#include "functions.h"
#include "variables.h"

ParticleEmitter *func_802EDD8C(f32 [3], f32, f32);

void func_8038B900(Actor *this);

/* .data */
ActorInfo chSnorkel = {
    MARKER_30_SNORKEL, ACTOR_1C8_SNORKEL, ASSET_41C_MODEL_SNORKEL,
    0x0, NULL,
    NULL, func_8038B900, actor_draw,
    0, 0, 0.0f, 0
};

enum chsnorkel_state_e {
    CH_SNORKEL_STATE_0_NOT_INIT,
    CH_SNORKEL_STATE_1_TRAPPED,
    CH_SNORKEL_STATE_2_FREED,
    CH_SNORKEL_STATE_3_DESPAWN
};

/* .code */
void chSnorkel_setState(Actor *this, s32 new_state){
    if(new_state == CH_SNORKEL_STATE_1_TRAPPED)
        skeletalAnim_set(this->unk148, ASSET_13F_ANIM_SNORKEL_STUCK, 0.0f, 5.5f);

    if(new_state == CH_SNORKEL_STATE_2_FREED)
        skeletalAnim_swap(this->unk148, ASSET_13E_ANIM_SNORKEL_SWIM, 1.0f, 0.65f);

    this->state = new_state;
}

void func_8038B900(Actor *this){
    f32 prev_anim_progress;
    f32 curr_anim_progress;
    f32 anim_progress;
    f32 sp48[3];
    ParticleEmitter *other;

    this->marker->propPtr->unk8_3 = 1;
    if(this->marker->unk14_21){
        anim_progress = skeletalAnim_getProgress(this->unk148);
        if( ( globalTimer_getTime() & (1 << 4) )
            && ( globalTimer_getTime() & (1 << 2) )
            && ( randf() < 0.90 )
        ){
            if( ( this->state == CH_SNORKEL_STATE_3_DESPAWN 
                  && (0.255 <= anim_progress && anim_progress <= 0.856) 
                )
                || ( this->state == CH_SNORKEL_STATE_1_TRAPPED
                     && ( (0.053 <= anim_progress && anim_progress <= 0.35)
                          || (0.39 <= anim_progress && anim_progress <= 0.44999999999999996)
                          || (0.45999999999999996 <= anim_progress && anim_progress <= 0.52)
                          || (0.54 <= anim_progress && anim_progress <= 0.73)
                          || (0.76 <= anim_progress && anim_progress <= 0.8200000000000001)
                          || (0.84 <= anim_progress && anim_progress <= 0.9)
                          || (0.94 <= anim_progress && anim_progress <= 1.0)
                     )
                )
            ){//L8038BB24
                vec3fArray_get_vec3f(this->marker->unk44, 5, sp48);
                other = func_802EDD8C(sp48, 0.0f, -1300.0f);
                particleEmitter_setStartingScaleRange(other, 0.04f, 0.04f);
                particleEmitter_setFinalScaleRange(other, 0.18f, 0.18f);
                particleEmitter_setSpawnPositionRange(other, -10.0f, 0.0f, -10.0f, 10.0f, 20.0f, 10.0f);
                particleEmitter_setParticleVelocityRange(other, 0.0f, 31.0f, 0.0f, 0.0f, 37.0f, 0.0f);
                particleEmitter_emitN(other, 1);
            }
        }
    }////L8038BBFC

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->position_x = -5100.0f;
        this->position_y = -2600.0f;
        this->position_z = 1460.0f;
        this->yaw = 0.0f;
        chSnorkel_setState(this, CH_SNORKEL_STATE_1_TRAPPED);
        if(jiggyscore_isSpawned(JIGGY_53_RBB_SNORKEL)){
            marker_despawn(this->marker);
        }
    }
    else{//L8038BC74
        skeletalAnim_getProgressRange(this->unk148, &prev_anim_progress, &curr_anim_progress);
        if( prev_anim_progress < 0.22 && 0.22 <= curr_anim_progress ){
            func_8030E988(SFX_D1_SNORKEL_WAH, randf2(0.8f, 0.9f), 15000, this->position, 1500.0f, 2000.0f);
        }

        if( prev_anim_progress < 0.54 && 0.54 <= curr_anim_progress ){
            func_8030E988(SFX_D1_SNORKEL_WAH, randf2(0.9f, 1.0f), 19000, this->position, 1500.0f, 2000.0f);
        }

        if(this->state == CH_SNORKEL_STATE_1_TRAPPED){
            if( !this->has_met_before
                && subaddie_playerIsWithinSphereAndActive(this, 600)
                && !player_movementGroup()
            ){
                gcdialog_showDialog(VER_SELECT(ASSET_B9B_DIALOG_SNORKEL_MEET, 0x970, 0, 0), 4, 0, 0, 0, 0);
                this->has_met_before = TRUE;
            }
        }

        if(this->state == CH_SNORKEL_STATE_1_TRAPPED){
            if(mapSpecificFlags_get(RBB_MAIN_SPECIFIC_FLAG_4_ANCHOR_LIFTING))
                chSnorkel_setState(this, CH_SNORKEL_STATE_2_FREED);
        }

        if(this->state == CH_SNORKEL_STATE_2_FREED){
            if(jiggyscore_isSpawned(JIGGY_53_RBB_SNORKEL))
                chSnorkel_setState(this, CH_SNORKEL_STATE_3_DESPAWN);
        }

        if(this->state == CH_SNORKEL_STATE_3_DESPAWN){
            actor_update_func_80326224(this);
            if(0.99 < this->unk48){   
                mapSpecificFlags_set(RBB_MAIN_SPECIFIC_FLAG_4_ANCHOR_LIFTING, FALSE);
                marker_despawn(this->marker);
            }
        }
    }//L8038BE90
}
