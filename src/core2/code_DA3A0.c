#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include <core1/viewport.h>

typedef struct {
    u8 *unk0;
    f32 unk4;
} ActorLocal_Core2_DA3A0;

void func_8036158C(Actor *this);

/* .data */
u8 D_80373130[] = {0, 1, 0, 0};

ActorInfo D_80373134 = { 
    0x1a6, 0x289, 0x431, 
    0x0, NULL, 
    func_8036158C, NULL, actor_draw, 
    0, 0, 0.0f, 0
};

ActorInfo D_80373158 = { 
    0x1a6, 0x28f, 0x431, 
    0x0, NULL, 
    func_8036158C, NULL, actor_draw, 
    0, 0, 0.0f, 0
};

ParticleScaleAndLifetimeRanges D_8037317C = {
    {0.01f, 0.01f},
    {2.5f, 3.0f},
    {0.05f, 0.05f},
    {0.4f, 0.7f},
    0.1f, 0.5f
};

/* .code */
void func_80361330(Actor *this, s32 next_state){
    ActorLocal_Core2_DA3A0 *local = (ActorLocal_Core2_DA3A0 *)&this->local;
    ParticleEmitter *pctrl;
    s32 tmp_s0;
    f32 sp40[3];

    if(next_state == 1)
        local->unk4 = 3.0f;

    if(next_state == 2){
        pctrl = partEmitMgr_newEmitter(6);
        sp40[0] = 1000.0f;
        sp40[1] = 100.0f;
        sp40[2] = 0.0f;
        ml_vec3f_roll_rotate_copy(sp40, sp40, this->roll);
        ml_vec3f_yaw_rotate_copy(sp40, sp40, this->yaw);
        particleEmitter_setSprite(pctrl, ASSET_70E_SPRITE_SMOKE_2);
        particleEmitter_setParticleAccelerationRange(pctrl, 0.0f, 200.0f, 0.0f, 0.0f, 1000.0f, 0.0f);
        particleEmitter_setStartingFrameRange(pctrl, 0, 7);
        particleEmitter_setParticleSpawnPositionRange(pctrl, -20.0f, -20.0f, -20.0f, 20.0f, 20.0f, 20.0f);
        particleEmitter_setPosition(pctrl, this->position);
        particleEmitter_setScaleAndLifetimeRanges(pctrl, &D_8037317C);
        particleEmitter_setParticleVelocityRange(pctrl, 
            sp40[0] *0.6, sp40[1]*0.6, sp40[2]*0.6,
            sp40[0], sp40[1], sp40[2]
        );
        particleEmitter_setSpawnInterval(pctrl, 0.5f);
        tmp_s0 = func_802F9AA8(SFX_B0_SIZZLING_NOISE);
        func_802F9DB8(tmp_s0, 0.7f, 0.7f, 0.0f);
        func_802F9EC4(tmp_s0, this->position, 0x1f4, 0x5dc);
        func_802F9F80(tmp_s0, 0.0f, 0.2f, 0.6f);
        func_802FA060(tmp_s0, 27000, 27000, 0.0f);
        local->unk4 = 0.6f;
        skeletalAnim_set(this->unk148, 0x169, 0.0f, 0.6f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);

    }//L8036155C
    this->state = next_state;
}

void func_8036158C(Actor *this){
    ActorLocal_Core2_DA3A0 *local = (ActorLocal_Core2_DA3A0 *)&this->local;
    f32 sp30;
    f32 sp24[3];

    sp30 = time_getDelta();

    if(!this->unk16C_4){
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk16C_4 = TRUE;
        local->unk0 = &D_80373130[this->modelCacheIndex - 0x289];
        if(*local->unk0){
            this->roll = this->yaw;
            this->yaw = 0.0f;
        }
        func_80361330(this, 1);
    }

    if(this->state == 1){
        player_getPosition(sp24);
        actor_collisionOff(this);
        if( ml_distance_vec3f(this->position, sp24) < 1000.0f 
            && viewport_isPointOutsideFrustum_3f(this->position_x, this->position_y, this->position_z)
            && ml_timer_update(&local->unk4, sp30)
        ){
            func_80361330(this, 2);
        }
    }//L803616A0

    if(this->state == 2){
        actor_collisionOn(this);
        if(ml_timer_update(&local->unk4, sp30)){
            func_80361330(this, 1);
        }
    }
}
