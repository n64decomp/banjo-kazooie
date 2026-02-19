#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chSlappa_update(Actor *this);

/* .data */
enum chSlappa_state_e {
    SLAPPA_STATE_1_IDLE = 1,
    SLAPPA_STATE_2_RISE,
    SLAPPA_STATE_3_CHASING_PLAYER,
    SLAPPA_STATE_4_ABOUT_TO_ATTACK,
    SLAPPA_STATE_5_ATTACKING,
    SLAPPA_STATE_6_LAYING_DOWN,
    SLAPPA_STATE_7_GETTING_UP,
    SLAPPA_STATE_8_LOWER,
    SLAPPA_STATE_9_DIE,
    SLAPPA_STATE_A_DEAD,
};

ActorAnimationInfo chSlappaAnimations[] ={
    {0x00, 0.0f},
    {ASSET_E9_ANIM_SLAPPA_RISE, 800000.0f},
    {ASSET_E9_ANIM_SLAPPA_RISE, 0.8f},
    {ASSET_EA_ANIM_SLAPPA_CHASE, 1.0f},
    {ASSET_EA_ANIM_SLAPPA_CHASE, 2.0f},
    {ASSET_EB_ANIM_SLAPPA_ATTACK, 0.8f},
    {ASSET_EB_ANIM_SLAPPA_ATTACK, 800000.0f},
    {ASSET_EC_ANIM_SLAPPA_GETTING_UP, 1.2f},
    {ASSET_EF_ANIM_SLAPPA_LOWER, 1.4f},
    {ASSET_EE_ANIM_SLAPPA_DIE, 1.4f},
    {ASSET_EE_ANIM_SLAPPA_DIE, 1.4f}
};

ActorInfo chSlappa = {
    MARKER_AD_SLAPPA, ACTOR_120_SLAPPA, ASSET_376_MODEL_SLAPPA, 
    0x1, chSlappaAnimations, 
    chSlappa_update, actor_update_func_80326224, actor_draw, 
    0, 0, 0.0f, 0
};
s32 D_803910BC[3] = {175, 100, 0};
s32 D_803910C8[3] = {175, 140, 0};
ParticleSettingsVelocityAccelerationPosition D_803910D4 = {
    {{-120.0f, 550.0f, -120.0f}, {120.0f, 950.0f, 120.0f}},
    {{0.0f, -1400.0f, 0.0f}, {0.0f, -1400.0f, 0.0f}},
    {{-100.0f, 0.0f, -100.0f}, {100.0f, 30.0f, 100.0f}}
};

/* .bss */
f32 GV_D_80391A70[3];

/* .code */
void func_8038AB30(ParticleEmitter *pCtrl, f32 position[3], s32 cnt){
    if(gsworld_get_map() != MAP_1A_GV_INSIDE_JINXY)
        particleEmitter_setRGB(pCtrl, D_803910BC);
    else
        particleEmitter_setRGB(pCtrl, D_803910C8);
    
    particleEmitter_setAlpha(pCtrl, 0xBE);
    particleEmitter_setSprite(pCtrl, ASSET_700_SPRITE_DUST);
    particleEmitter_setFade(pCtrl, 0.0f, 0.01f);
    particleEmitter_setStartingFrameRange(pCtrl, 0, 7);
    particleEmitter_setPosition(pCtrl, position);
}

void func_8038ABD8(f32 position[3], s32 cnt){
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(cnt);
    func_8038AB30(pCtrl, position, cnt);
    particleEmitter_setSpawnPositionRange(pCtrl, 
        -40.0f, -5.0f, -40.0f,
        60.0f, 20.0f, 60.0f
    );
    particleEmitter_setParticleVelocityRange(pCtrl,
        -100.0f, 10.0f, -100.0f,
        100.0f, 60.0f, 100.0f
    );
    particleEmitter_setStartingScaleRange(pCtrl, 0.1f, 0.5f);
    particleEmitter_setFinalScaleRange(pCtrl, 1.2f, 2.6f);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 0.5f, 1.4f);
    particleEmitter_emitN(pCtrl, cnt);
}

void func_8038ACEC(f32 pos[3], s32 cnt){
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(cnt);
    func_8038AB30(pCtrl, pos, cnt);
    particleEmitter_setSpawnPositionRange(pCtrl, 
        -80.0f, 20.0f, -80.0f,
        120.0f, 120.0f, 120.0f
    );
    particleEmitter_setParticleVelocityRange(pCtrl,
        -200.0f, 20.0f, -200.0f,
        300.0f, 120.0f, 200.0f
    );
    particleEmitter_setStartingScaleRange(pCtrl, 1.0f, 2.6f);
    particleEmitter_setFinalScaleRange(pCtrl, 3.0f, 5.5f);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 1.2f, 3.2f);
    particleEmitter_emitN(pCtrl, cnt);
}

void func_8038ADFC(f32 pos[3], s32 cnt){
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(cnt);
    particleEmitter_setModel(pCtrl, 0x389);
    particleEmitter_setPosition(pCtrl, pos);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_803910D4);
    particleEmitter_setAngularVelocityRange(pCtrl, -500.0f, -500.0f, -500.0f, 500.0f, 500.0f, 500.0f);
    particleEmitter_func_802EF9F8(pCtrl, 0.6f);
    particleEmitter_func_802EFA18(pCtrl, 2);
    particleEmitter_setStartingScaleRange(pCtrl, 1.0f, 1.0f);
    particleEmitter_setDrawMode(pCtrl, 2);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 4.0f, 6.0f);
    particleEmitter_setFade(pCtrl, 0.0f, 0.05f);
    particleEmitter_emitN(pCtrl, cnt);
}

void func_8038AF10(Actor *this){
    anctrl_setSmoothTransition(this->anctrl, TRUE);
    subaddie_set_state_with_direction(this, SLAPPA_STATE_3_CHASING_PLAYER, 0.00001f, 1);
    actor_loopAnimation(this);
    this->actor_specific_1_f = 16.0f;
    this->unk1C[0] = 1.0f;
}

int func_8038AF78(Actor *this, f32 arg1, f32 arg2){
    this->actor_specific_1_f = arg2;
    this->yaw_ideal = (f32)subaddie_getYawToPlayer(this);
    subaddie_turnToYaw(this, arg1);
    if(!func_80329030(this, 0) && func_80329480(this))
        return 0;
    return 1;

}

void func_8038AFF4(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    func_8032B4DC(this, other_marker, 0xC);
    actor_collisionOff(this);
    subaddie_set_state_with_direction(this, SLAPPA_STATE_9_DIE, 0.00001f, 1);
    actor_playAnimationOnce(this);
    this->unk1C[0] = 0.0f;
    func_8030E878(SFX_D7_GRABBA_DEATH, 1.0f, 32000, this->position, 2250.0f, 4500.0f);


}

void func_8038B08C(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    func_8032B4DC(this, other_marker, 0xC);
}


void func_8038B0BC(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    func_8030E878(SFX_3F5_UNKNOWN, randf2(0.95f, 1.05f), 32000, this->position, 2250.0f, 4500.0f);
}


void chSlappa_update(Actor *this){
    if(!this->initialized){
        this->initialized = TRUE;
        this->unk38_31 = 0;
        this->unk1C[0] = 0.0f;
        this->unk1C[2] = 240.0f;
        this->velocity_x = this->position_x;
        this->velocity_y = this->position_y;
        this->velocity_z = this->position_z;
    }

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        if(this->state == SLAPPA_STATE_A_DEAD)
            marker_despawn(this->marker);

        marker_setCollisionScripts(this->marker, func_8038B0BC, func_8038B08C, func_8038AFF4);
        this->marker->propPtr->unk8_3 = TRUE;
        actor_collisionOn(this);
        this->unk138_27 = 1;
        this->unk1C[1] = 0.0f;
        if(this->unk44_31 == 0){
            this->unk44_31 = sfxsource_createSfxsourceAndReturnIndex();
            sfxsource_setSfxId(this->unk44_31, SFX_3EC_CCW_DOOR_OPENING);
            sfxSource_setunk43_7ByIndex(this->unk44_31, 2);
            sfxsource_playSfxAtVolume(this->unk44_31, 0.1f);
            sfxsource_setSampleRate(this->unk44_31, 32000);
        }
    }//L8038B25C

    if(!subaddie_playerIsWithinSphere(this, 4500)) return;

    this->unk58_0 = TRUE;
    switch(this->state){
        case SLAPPA_STATE_1_IDLE: //L8038B2A4
            this->unk58_0 = FALSE;
            if(0.0 < this->unk1C[1]){
                this->unk1C[1] = MAX((f64)(this->unk1C[1] - time_getDelta()), 0.0);
            }//L8038B33C

            if( this->unk1C[1] == 0.0 
                && subaddie_playerIsWithinSphereAndActive(this, 0x320)
                && func_803292E0(this)
            ){
                anctrl_setSmoothTransition(this->anctrl, 0);
                subaddie_set_state_with_direction(this, SLAPPA_STATE_2_RISE, 0.00001f, 1);
                actor_playAnimationOnce(this);
                this->yaw = (f32)subaddie_getYawToPlayer(this);
                this->actor_specific_1_f = 0.0f;
                this->unk1C[0] = 1.0f;
                func_802BB3DC(0, 14.0f, 0.92f);
                func_8038ABD8(this->position, 8);
            }
            else{//L8038B3E0
                this->yaw_ideal = func_80257204(this->position_x, this->position_z, this->velocity_x, this->velocity_z);
                subaddie_turnToYaw(this, 18.0f);
                this->actor_specific_1_f = 18.0f;
                func_80329030(this, 0);
                anctrl_setAnimTimer(this->anctrl, 0.0f);

            }
            break;

        case SLAPPA_STATE_2_RISE: //L8038B430
            sfxSource_func_8030E2C4(this->unk44_31);
            if(0.98 < anctrl_getAnimTimer(this->anctrl)){
                func_8038AF10(this);
            }
            else{
                this->yaw_ideal = subaddie_getYawToPlayer(this);
                subaddie_turnToYaw(this, 8.0f);
            }
            break;

        case SLAPPA_STATE_3_CHASING_PLAYER: //L8038B494
            sfxSource_func_8030E2C4(this->unk44_31);
            if(subaddie_playerIsWithinSphereAndActive(this, 175)){
                subaddie_set_state_with_direction(this, SLAPPA_STATE_4_ABOUT_TO_ATTACK, 0.00001f, 1);
                actor_loopAnimation(this);
                this->unk1C[0] = 1.0f;
            }
            else if(!subaddie_playerIsWithinSphereAndActive(this, 1100) || !func_8038AF78(this, 8.0f, 16.0f)){
                subaddie_set_state_with_direction(this, SLAPPA_STATE_8_LOWER, 0.00001f, 1);
                actor_playAnimationOnce(this);
                this->unk1C[0] = 1.0f;
                func_802BB3DC(0, 6.0f, 0.92f);
                func_8038ABD8(this->position, 8);
            }
            else{
                GV_D_80391A70[0] = 2 * this->actor_specific_1_f;
                GV_D_80391A70[1] = 0.0f;
                GV_D_80391A70[2] = 0.0f;
                ml_vec3f_yaw_rotate_copy(GV_D_80391A70, GV_D_80391A70, this->yaw - 90.0);

                GV_D_80391A70[0] = GV_D_80391A70[0] + this->position[0]; 
                GV_D_80391A70[1] = GV_D_80391A70[1] + this->position[1]; 
                GV_D_80391A70[2] = GV_D_80391A70[2] + this->position[2];  
                func_8038ABD8(GV_D_80391A70, 1);
            }
            break;

        case SLAPPA_STATE_4_ABOUT_TO_ATTACK: //L8038B5F0
            this->yaw_ideal = subaddie_getYawToPlayer(this);
            subaddie_turnToYaw(this, 8.0f);
            if(this->unk38_31 >= 20){
                subaddie_set_state_with_direction(this, SLAPPA_STATE_5_ATTACKING, 0.00001f, 1);
                actor_playAnimationOnce(this);
                this->unk38_31 = 0;
                this->unk1C[0] = 1.0f;
            }
            else{//L8038B660
                this->unk38_31++;
            }
            break;

        case SLAPPA_STATE_5_ATTACKING: //L8038B67C
            if(this->marker->unk14_21 && actor_animationIsAt(this, 0.79f)){
                func_8034A174(this->marker->unk44, 5, GV_D_80391A70);
                func_8038ACEC(GV_D_80391A70, 2);
                func_8034A174(this->marker->unk44, 6, GV_D_80391A70);
                func_8038ACEC(GV_D_80391A70, 3);
                func_802BB3DC(0, 18.0f, 0.92f);
                func_8030E878(SFX_3_DULL_CANNON_SHOT, 1.0f, 32000, this->position, 2250.0f, 4500.0f);
            }//L8038B734
            if(0.98 < anctrl_getAnimTimer(this->anctrl)){
                subaddie_set_state_with_direction(this, SLAPPA_STATE_6_LAYING_DOWN, 0.99f, 0);
                actor_playAnimationOnce(this);
                this->lifetime_value = 0.0f;
                this->unk1C[0] = 1.0f;
            }
            break;

        case SLAPPA_STATE_6_LAYING_DOWN: //L8038B78C
            if(75.0f <= this->lifetime_value){
                subaddie_set_state_with_direction(this, SLAPPA_STATE_7_GETTING_UP, 0.00001f, 1);
                actor_playAnimationOnce(this);
                this->unk1C[0] = 1.0f;
            }
            else{
                this->lifetime_value += 1.0f;
            }
            break;

        case SLAPPA_STATE_7_GETTING_UP: //L8038B7EC
            if(0.98 < anctrl_getAnimTimer(this->anctrl)){
                func_8038AF10(this);
            }
            break;

        case SLAPPA_STATE_8_LOWER: //L8038B820
            if(0.98 < anctrl_getAnimTimer(this->anctrl)){
                subaddie_set_state_with_direction(this, SLAPPA_STATE_1_IDLE, 0.00001f, 1);
                this->unk1C[0] = 0.0f;
                this->unk1C[1] = 2.0f;
            }
            break;

        case SLAPPA_STATE_9_DIE: //L8038B870
            subaddie_set_state(this, SLAPPA_STATE_A_DEAD);
            func_8038ACEC(this->position, 2);
            func_8034A174(this->marker->unk44, 5, GV_D_80391A70);
            func_8038ACEC(GV_D_80391A70, 2);
            func_8038ADFC(GV_D_80391A70, 3);
            func_8034A174(this->marker->unk44, 6, GV_D_80391A70);
            func_8038ACEC(GV_D_80391A70, 3);
            func_8038ADFC(GV_D_80391A70, 2);
            break;

        case SLAPPA_STATE_A_DEAD: //L8038B900
            this->unk58_0 = FALSE;
            if(0.0f != this->unk1C[2]){
                this->unk1C[2] -= 1.0f;
            }
            else{
                marker_despawn(this->marker);
            }
            break;
    }
}
