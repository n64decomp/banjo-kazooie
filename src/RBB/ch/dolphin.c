#include <ultra64.h>
#include "functions.h"
#include "variables.h"

ParticleEmitter *func_802EDD8C(f32 [3], f32, f32);

void func_8038B900(Actor *this);

/* .data */
ActorInfo RBB_D_80390AB0 = {
    0x30, 0x1C8, 0x41C, 0x0, NULL,
    NULL, func_8038B900, actor_draw,
    0, 0, 0.0f, 0
};

/* .code */
void func_8038B880(Actor *this, s32 new_state){
    if(new_state == 1)
        skeletalAnim_set(this->unk148, ASSET_13F_ANIM_SNORKEL_STUCK, 0.0f, 5.5f);

    if(new_state == 2)
        skeletalAnim_swap(this->unk148, ASSET_13E_ANIM_SNORKEL_SWIM, 1.0f, 0.65f);

    this->state = new_state;
}

void func_8038B900(Actor *this){
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp48[3];
    ParticleEmitter *other;

    this->marker->propPtr->unk8_3 = 1;
    if(this->marker->unk14_21){
        sp54 = skeletalAnim_getProgress(this->unk148);
        if( ( globalTimer_getTime() & (1 << 4) )
            && ( globalTimer_getTime() & (1 << 2) )
            && ( randf() < 0.90 )
        ){
            if( ( this->state == 3 
                  && (0.255 <= sp54 && sp54 <= 0.856) 
                )
                || ( this->state == 1
                     && ( (0.053 <= sp54 && sp54 <= 0.35)
                          || (0.39 <= sp54 && sp54 <= 0.44999999999999996)
                          || (0.45999999999999996 <= sp54 && sp54 <= 0.52)
                          || (0.54 <= sp54 && sp54 <= 0.73)
                          || (0.76 <= sp54 && sp54 <= 0.8200000000000001)
                          || (0.84 <= sp54 && sp54 <= 0.9)
                          || (0.94 <= sp54 && sp54 <= 1.0)
                     )
                )
            ){//L8038BB24
                func_8034A174(this->marker->unk44, 5, sp48);
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
        func_8038B880(this, 1);
        if(jiggyscore_isSpawned(JIGGY_53_RBB_SNORKEL)){
            marker_despawn(this->marker);
        }
    }
    else{//L8038BC74
        skeletalAnim_getProgressRange(this->unk148, &sp5C, &sp58);
        if( sp5C < 0.22 && 0.22 <= sp58 ){
            func_8030E988(SFX_D1_SNORKEL_WAH, randf2(0.8f, 0.9f), 15000, this->position, 1500.0f, 2000.0f);
        }

        if( sp5C < 0.54 && 0.54 <= sp58 ){
            func_8030E988(SFX_D1_SNORKEL_WAH, randf2(0.9f, 1.0f), 19000, this->position, 1500.0f, 2000.0f);
        }

        if(this->state == 1){
            if( !this->has_met_before
                && subaddie_playerIsWithinSphereAndActive(this, 0x258)
                && !player_movementGroup()
            ){
                gcdialog_showDialog(ASSET_B9B_DIALOG_SNORKEL_MEET, 4, 0, 0, 0, 0);
                this->has_met_before = TRUE;
            }
        }

        if(this->state == 1){
            if(mapSpecificFlags_get(4))
                func_8038B880(this, 2);
        }

        if(this->state == 2){
            if(jiggyscore_isSpawned(JIGGY_53_RBB_SNORKEL))
                func_8038B880(this, 3);
        }

        if(this->state == 3){
            actor_update_func_80326224(this);
            if(0.99 < this->unk48){   
                mapSpecificFlags_set(4, FALSE);
                marker_despawn(this->marker);
            }
        }
    }//L8038BE90
}
