#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void actor_predrawMethod(Actor *);
extern void actor_postdrawMethod(ActorMarker *);
extern void sfxSource_triggerCallbackByIndex(u8);
extern int func_803342AC(f32 (*)[3], f32(*)[3], f32);
extern void particleEmitter_setModel(ParticleEmitter *, s32);


typedef struct{
    s16 actorId;
    //u8 pad2[2];
    f32 spawnPositionDelta;
    f32 unk8;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    //u8 padF[1];
    f32 unk10;
    f32 volume;
} ActorLocal_ChBossBoomBoxInfo;

typedef struct{
    ActorLocal_ChBossBoomBoxInfo *unk0;
    u8 unk4;
    u8 pad5[3];
    f32 currentPosition[3];
    f32 spawnPosition[3];
    s32 unk20;
    f32 unk24;
    f32 turnAngle;
} ActorLocal_ChBossBoomBox;

void chBossBoomBox_setState(Actor *this, s32 new_state);
void func_8038D7E8(ActorMarker *marker, s32 arg1);
Actor *chBossBoomBox_draw(ActorMarker *marker, Gfx **gdl, Mtx ** mptr, Vtx **arg3);
void chBossBoomBox_update(Actor *this);

/* .data */
ActorLocal_ChBossBoomBoxInfo chBossBoomBoxTable[4] = {
    {ACTOR_281_BOSS_BOOM_BOX_LARGEST, 1.1f,  1.0f, 0x14, 0x01, 0x5, 0.9f, 0.8f},
    {ACTOR_282_BOSS_BOOM_BOX_LARGE,  0.75f,  1.0f,  0xF, 0x02, 0x4, 1.1f, 0.9f},
    {ACTOR_283_BOSS_BOOM_BOX_MEDIUM,  0.5f,  2.0f,  0xA, 0x02, 0x3, 1.3f, 1.0f},
    {ACTOR_284_BOSS_BOOM_BOX_SMALL,  0.25f,  2.0f,  0x5, 0x02, 0x2, 1.5f, 1.1f},
};

ActorInfo chBossBoomBoxLargest = {
    MARKER_1A1_BOSS_BOOM_BOX_LARGEST, ACTOR_281_BOSS_BOOM_BOX_LARGEST, ASSET_428_MODEL_BOSS_BOOM_BOX,
    0x0, NULL,
    chBossBoomBox_update, NULL, chBossBoomBox_draw,
    0, 0, 0.0f, 0
};

ActorInfo chBossBoomBoxLarge = {
    MARKER_1A2_BOSS_BOOM_BOX_LARGE, ACTOR_282_BOSS_BOOM_BOX_LARGE, ASSET_428_MODEL_BOSS_BOOM_BOX,
    0x0, NULL,
    chBossBoomBox_update, NULL, chBossBoomBox_draw,
    0, 0, 0.0f, 0
};

ActorInfo chBossBoomBoxMedium = {
    MARKER_1A3_BOSS_BOOM_BOX_MEDIUM, ACTOR_283_BOSS_BOOM_BOX_MEDIUM, ASSET_428_MODEL_BOSS_BOOM_BOX,
    0x0, NULL,
    chBossBoomBox_update, NULL, chBossBoomBox_draw,
    0, 0, 0.0f, 0
};

ActorInfo chBossBoomBoxSmall = {
    MARKER_1A4_BOSS_BOOM_BOX_SMALL, ACTOR_284_BOSS_BOOM_BOX_SMALL, ASSET_428_MODEL_BOSS_BOOM_BOX,
    0x0, NULL,
    chBossBoomBox_update, NULL, chBossBoomBox_draw,
    0, 0, 0.0f, 0
};

s32 ChBossBoomBoxSmoke1RGB[3] = {0xDE, 0xA7, 0x71};

ParticleSettingsVelocityAcceleration D_80390C6C = {
    { {-200.0f, 200.0f, -200.0f}, {200.0f, 500.0f, 200.0f} },
    { {0.0f, -800.0f, 0.0f}, {0.0f, -800.0f, 0.0f} }
};

s32 ChBossBoomBoxSmoke2RGB[3] = {0xDE, 0xA7, 0x71};

ParticleSettingsVelocityAccelerationPosition D_80390CA8 = {
    { {-200.0f, 0.0f, -200.0f}, {200.0f, -50.0f, 200.0f} },
    { {0.0f, 200.0f, 0.0f}, {0.0f, 400.0f, 0.0f} },
    { {-10.0f, -10.0f, -10.0f}, {10.0f, 10.0f, 10.0f} }
};

enum chbossboombox_state_e {
    CH_BOSS_BOOM_BOX_STATE_0_NOT_INIT,
    CH_BOSS_BOOM_BOX_STATE_1_WAITING_FOR_PLAYER,
    CH_BOSS_BOOM_BOX_STATE_2_HIDES_JIGGY,
    CH_BOSS_BOOM_BOX_STATE_3_ATTACK_PLAYER,
    CH_BOSS_BOOM_BOX_STATE_4_PUSH_BACK,
    CH_BOSS_BOOM_BOX_STATE_5_BREAKING,
    CH_BOSS_BOOM_BOX_STATE_6_COMPLETE,
    CH_BOSS_BOOM_BOX_STATE_7_UNK,
    CH_BOSS_BOOM_BOX_STATE_8_FF_TIMER_RUN_OUT
};

/* .bss */
u8 D_80391280;
s32 pad_80391284;
f32 chBossBoomBoxJiggyPosition[3];

/* .code */
void RBB_func_8038C370(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    chBossBoomBox_setState(actor, arg1);
}

void func_8038C39C(Actor *this){
    ActorLocal_ChBossBoomBox *local = (ActorLocal_ChBossBoomBox *) &this->local;
    ParticleEmitter *other = partEmitMgr_newEmitter(local->unk0->unkE);
    particleEmitter_setSprite(other, ASSET_70E_SPRITE_SMOKE_2);
    particleEmitter_setFade(other, 0.0f, 0.1f);
    particleEmitter_setStartingFrameRange(other, 0, 7);
    particleEmitter_setDrawMode(other, 4);
    particleEmitter_setPosition(other, this->position);
    particleEmitter_setStartingScaleRange(other, local->unk0->spawnPositionDelta * 1, local->unk0->spawnPositionDelta * 3.0f);
    particleEmitter_setFinalScaleRange(other, 3.0f*local->unk0->spawnPositionDelta, local->unk0->spawnPositionDelta * 7.0f);
    particleEmitter_setSpawnPositionRange(other, 
        local->unk0->spawnPositionDelta * -200.0f, local->unk0->spawnPositionDelta * 100.0f, local->unk0->spawnPositionDelta * -200.0f,
        local->unk0->spawnPositionDelta * 200.0f, local->unk0->spawnPositionDelta * 100.0f, local->unk0->spawnPositionDelta * 200.0f
    );
    particleEmitter_setParticleVelocityRange(other, 
        -50.0f, 100.0f, -50.0f,
        50.0f, 200.0f, 50.0f
    );
    particleEmitter_setParticleLifeTimeRange(other, 0.5f, 1.0f);
    particleEmitter_emitN(other, local->unk0->unkE);
}

void RBB_func_8038C538(Actor *this){
    ActorLocal_ChBossBoomBox *local = (ActorLocal_ChBossBoomBox *) &this->local;
    ParticleEmitter *other = partEmitMgr_newEmitter(3*local->unk0->unkE);
    particleEmitter_setSprite(other, ASSET_70E_SPRITE_SMOKE_2);
    particleEmitter_setFade(other, 0.1f, 0.3f);
    particleEmitter_setDrawMode(other, 4);
    particleEmitter_setStartingFrameRange(other, 0, 7);
    particleEmitter_setPosition(other, this->position);
    particleEmitter_setStartingScaleRange(other, local->unk0->spawnPositionDelta * 1, local->unk0->spawnPositionDelta * 6.0f);
    particleEmitter_setFinalScaleRange(other, 0.5*local->unk0->spawnPositionDelta, local->unk0->spawnPositionDelta * 3.0f);
    particleEmitter_setSpawnPositionRange(other, 
        local->unk0->spawnPositionDelta * -300.0f, local->unk0->spawnPositionDelta * 100.0f, local->unk0->spawnPositionDelta * -300.0f,
        local->unk0->spawnPositionDelta * 300.0f, local->unk0->spawnPositionDelta * 300.0f, local->unk0->spawnPositionDelta * 300.0f
    );
    particleEmitter_setParticleVelocityRange(other, 
        -70.0f, 50.0f, -70.0f,
        70.0f, 100.0f, 70.0f
    );
    particleEmitter_setRGB(other, ChBossBoomBoxSmoke1RGB);
    particleEmitter_setParticleLifeTimeRange(other, 3.0f, 4.0f);
    particleEmitter_emitN(other, 3 * local->unk0->unkE);
}

void RBB_func_8038C70C(Actor *this){
    ActorLocal_ChBossBoomBox *local = (ActorLocal_ChBossBoomBox *) &this->local;
    ParticleEmitter *other = partEmitMgr_newEmitter(0xa);

    particleEmitter_func_802EF9F8(other, 0.6f);
    particleEmitter_func_802EFA18(other, 3);
    particleEmitter_setDrawMode(other, 4);
    particleEmitter_setModel(other, ASSET_427_MODEL_WOODEN_PLANK);
    particleEmitter_setSpawnPositionRange(other, 
        local->unk0->spawnPositionDelta * -300.0f, local->unk0->spawnPositionDelta * 100.0f, local->unk0->spawnPositionDelta * -300.0f, 
        local->unk0->spawnPositionDelta * 300.0f, local->unk0->spawnPositionDelta * 200.0f, local->unk0->spawnPositionDelta * 300.0f
    );
    particleEmitter_setPosition(other, this->position);
    particleEmitter_setStartingScaleRange(other, local->unk0->spawnPositionDelta * 0.3, local->unk0->spawnPositionDelta*0.8);
    particleEmitter_setAngularVelocityRange(other, 
        -600.0f, -600.0f, -600.0f, 
        600.0f, 600.0f, 600.0f
    );
    particleEmitter_setSpawnIntervalRange(other, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(other, 10.0f, 10.0f);
    particleEmitter_setVelocityAndAccelerationRanges(other, &D_80390C6C);
    particleEmitter_emitN(other, 10);

}

void func_8038C8A8(Actor * this){
    ActorLocal_ChBossBoomBox *local = (ActorLocal_ChBossBoomBox *) &this->local;
    ParticleEmitter *other = partEmitMgr_newEmitter(5);
    f32 particle_position[3];
    

    player_getPosition(particle_position);
    particle_position[1] += 50.0f;

    particleEmitter_setSprite(other, ASSET_70E_SPRITE_SMOKE_2);
    particleEmitter_setFade(other, 0.0, 0.5f);
    particleEmitter_setDrawMode(other, 4);
    particleEmitter_setStartingFrameRange(other, 0, 7);
    particleEmitter_setPosition(other, particle_position);
    particleEmitter_setStartingScaleRange(other, local->unk0->spawnPositionDelta * 1, local->unk0->spawnPositionDelta * 3.0f);
    particleEmitter_setFinalScaleRange(other, local->unk0->spawnPositionDelta * 3.0f, local->unk0->spawnPositionDelta * 6.0f);
    particleEmitter_setVelocityAccelerationAndPositionRanges(other, &D_80390CA8);
    particleEmitter_setParticleLifeTimeRange(other, 1.0f, 2.0f);
    particleEmitter_setRGB(other, ChBossBoomBoxSmoke2RGB);
    particleEmitter_emitN(other, 5);
}

void chbossboombox_respawnJiggy(s32 position_x, s32 position_y, s32 position_z){
    Actor *jiggy = actorArray_findActorFromActorId(ACTOR_46_JIGGY);
    if(jiggy)
        marker_despawn(jiggy->marker);

    chBossBoomBoxJiggyPosition[0] = (f32)position_x;
    chBossBoomBoxJiggyPosition[1] = (f32)(position_y + 0x28);
    chBossBoomBoxJiggyPosition[2] = (f32)position_z;
    jiggy_spawn(JIGGY_56_RBB_BOSS_BOOM_BOX, chBossBoomBoxJiggyPosition);
}

void func_8038CA70(Actor *this, f32(*arg1)[3]){
    f32 tmp_f;
    ActorLocal_ChBossBoomBox *local = (ActorLocal_ChBossBoomBox *) &this->local;

    tmp_f = local->unk0->spawnPositionDelta * 300.0f;

    if( (*arg1)[0] - tmp_f < -1400.0f)
        (*arg1)[0] = -1400.0f + tmp_f;
    
    if(1400.0f < (*arg1)[0] + tmp_f)
        (*arg1)[0] = 1400.0f - tmp_f;

     if( (*arg1)[2] - tmp_f < -1200.0f)
        (*arg1)[2] = -1200.0f + tmp_f;
    
    if(1200.0f < (*arg1)[2] + tmp_f)
        (*arg1)[2] = 1200.0f - tmp_f;

}

void func_8038CB34(ActorMarker *marker, enum asset_e arg1, s32 arg2){
    comusic_8025AB44(COMUSIC_62_RBB_BOOMBOX, -1, 300);
}

void func_8038CB68(ActorMarker *marker, enum asset_e arg1, s32 arg2){
    Actor *actor = marker_getActor(marker);
    timed_exitStaticCamera(0.0f);
    func_80324E38(0.0f, 0);
    timedFunc_set_2(0.0f, (GenFunction_2)RBB_func_8038C370, (s32)actor->marker, 3);
}

void chbossboombox_hideJiggy(void){
    Actor * jiggy = actorArray_findActorFromActorId(ACTOR_46_JIGGY);
    if(jiggy)
        chjiggy_hide(jiggy);
}

int RBB_func_8038CBF0(Actor *this){
    f32 sp2C[3];
    f32 sp20[3];
    ActorLocal_ChBossBoomBox *local = (ActorLocal_ChBossBoomBox *) &this->local;
    
    sp2C[0] = local->currentPosition[0];
    sp2C[1] = local->currentPosition[1];
    sp2C[2] = local->currentPosition[2];

    sp20[0] = local->spawnPosition[0];
    sp20[1] = local->spawnPosition[1];
    sp20[2] = local->spawnPosition[2];

    sp2C[1] += 300.0f * local->unk0->spawnPositionDelta;
    sp20[1] += 300.0f * local->unk0->spawnPositionDelta;
    return func_803342AC(&sp2C, &sp20, local->unk0->spawnPositionDelta * 400.0f);
}

void chBossBoomBox_setState(Actor *this, s32 new_state){
    f32 player_position[3];
    f32 sp80[3];
    ActorLocal_ChBossBoomBox *local = (ActorLocal_ChBossBoomBox *) &this->local;
    int i;
    f32 pad;
    f32 spawn_position[3];
    f32 position_delta;
    f32 horizontal_distance;
    f32 distance_in_front;
    f32 side_angle_radian;

    player_getPosition(player_position);
    
    player_position[1] = 0.0f;

    sp80[0] = player_position[0] - this->position_x;
    sp80[1] = player_position[1] - this->position_y;
    sp80[2] = player_position[2] - this->position_z;
    if(this->state == CH_BOSS_BOOM_BOX_STATE_2_HIDES_JIGGY){
        chbossboombox_hideJiggy();
    }

    if(this->state == CH_BOSS_BOOM_BOX_STATE_7_UNK){
        actor_collisionOn(this);
    }

    local->currentPosition[0] = this->position_x;
    local->currentPosition[1] = this->position_y;
    local->currentPosition[2] = this->position_z;
    local->unk24 = local->turnAngle = this->yaw;
    this->state = new_state;

    if(local->unk20){
        func_803343F8(local->unk20);
        local->unk20 = NULL;
    }
    
    if(this->state == CH_BOSS_BOOM_BOX_STATE_1_WAITING_FOR_PLAYER){
        skeletalAnim_set(this->unk148, ASSET_146_ANIM_BOSS_BOOMBOX_APPEAR, 0.0f, 2.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_4_STOPPED);
    }

    if(this->state == CH_BOSS_BOOM_BOX_STATE_2_HIDES_JIGGY){
        func_8025A58C(0, 4000);
        coMusicPlayer_playMusic(COMUSIC_62_RBB_BOOMBOX, -1);
        func_8025AABC(COMUSIC_62_RBB_BOOMBOX);
        skeletalAnim_set(this->unk148, ASSET_146_ANIM_BOSS_BOOMBOX_APPEAR, 0.0f, 2.4f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        func_80324E38(0.0f, 3);
        timed_setStaticCameraToNode(0.0f, 0);
        timed_playSfx(0.5f, SFX_3F5_UNKNOWN, 1.0f, 0x7fc6);
        timed_playSfx(1.25f, SFX_6C_LOCKUP_CLOSING, 1.05f, 0x7d00);
        timed_playSfx(1.35f, SFX_6C_LOCKUP_CLOSING, 1.0f, 0x7d00);
        timed_playSfx(1.8f, SFX_6C_LOCKUP_CLOSING, 1.0f, 0x7d00);
        if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
            item_set(ITEM_6_HOURGLASS, 1);
            item_set(ITEM_0_HOURGLASS_TIMER, 0x1067);
            timed_exitStaticCamera(2.4f);
            func_80324E38(2.4f, 0);
            timedFunc_set_2(2.4f, (GenFunction_2)RBB_func_8038C370, (s32)this->marker, 3);
        }
        else{//L8038CEFC
            timedFunc_set_3(2.4f, (GenFunction_3)comusic_8025AB44, COMUSIC_62_RBB_BOOMBOX, 8000, 300);
            func_80324DBC(2.4f, ASSET_B9E_DIALOG_BOSS_BOOM_BOX_MEET, 4, NULL, this->marker, func_8038CB34, func_8038CB68);
        }
    }//L8038CF60

    if( this->state == CH_BOSS_BOOM_BOX_STATE_3_ATTACK_PLAYER
        || this->state == CH_BOSS_BOOM_BOX_STATE_4_PUSH_BACK)
    {
        func_8030E878(SFX_3F2_BOING, local->unk0->volume, 28000, this->position, 500.0f, 1000.0f);
        skeletalAnim_set(this->unk148, ASSET_147_ANIM_BOOMBOX_MOVE, 0.2f, (1.0 / (local->unk0->unk8) * randf2(1.0f, 1.1f)));
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        ml_vec3f_set_length(sp80, (this->state == 4)? -0x32 * (2 + func_80326218()) : 300.0f / local->unk0->unk8);
        local->spawnPosition[0] = sp80[0] + this->position_x;
        local->spawnPosition[1] = sp80[1] + this->position_y;
        local->spawnPosition[2] = sp80[2] + this->position_z;
        local->spawnPosition[1] = 0.0f;
        func_8038CA70(this, &local->spawnPosition);
    }//L8038D0B8

    if(this->state == CH_BOSS_BOOM_BOX_STATE_5_BREAKING){
        actor_collisionOff(this);
        timed_playSfx(0.2f, SFX_D9_WOODEN_CRATE_BREAKING_1, 0.9f, 30000);
        skeletalAnim_set(this->unk148, ASSET_148_ANIM_BOOMBOX_DIE, 0.2f, 1.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        ml_vec3f_set_length(sp80, -300.f);
        local->spawnPosition[0] = sp80[0] + this->position_x;
        local->spawnPosition[1] = sp80[1] + this->position_y;
        local->spawnPosition[2] = sp80[2] + this->position_z;
        local->spawnPosition[1] = 0.0f;
        func_8038CA70(this, &local->spawnPosition);
        RBB_func_8038C70C(this);
        RBB_func_8038C538(this);
    }//L8038D17C

    if(this->state == CH_BOSS_BOOM_BOX_STATE_6_COMPLETE){
        func_80326310(this);
        if(local->unk0->actorId == ACTOR_284_BOSS_BOOM_BOX_SMALL){
            if(++D_80391280 == 8){
                func_8025A58C(-1, 400);
                comusic_8025AB44(COMUSIC_62_RBB_BOOMBOX, 0, 400);
                func_8025AABC(COMUSIC_62_RBB_BOOMBOX);
                if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
                    item_set(ITEM_6_HOURGLASS, 0);
                    volatileFlag_set(VOLATILE_FLAG_3, 0);
                    volatileFlag_set(VOLATILE_FLAG_5_FF_MINIGAME_WON, 1);
                }
                else{//L8038D220
                    timedFunc_set_3(0.0f, (GenFunction_3)chbossboombox_respawnJiggy,  (s32)this->position_x, (s32)this->position_y, (s32)this->position_z);
                    gcdialog_showDialog(ASSET_B9F_DIALOG_BOSS_BOOM_BOX_COMPLETE, 4, 0, 0, 0, 0);
                }
            }//L8038D278
        }
        else{//L8038D28C
            spawn_position[0] = this->position_x + 200.0f * local->unk0->spawnPositionDelta;
            spawn_position[1] = this->position_y + 80.0f * local->unk0->spawnPositionDelta;
            spawn_position[2] = this->position_z;
            __spawnQueue_add_4(
                (GenFunction_4)spawnQueue_actor_f32,
                local->unk0->actorId + 1, 
                reinterpret_cast(s32, spawn_position[0]),
                reinterpret_cast(s32, spawn_position[1]),
                reinterpret_cast(s32, spawn_position[2]));

            spawn_position[0] = this->position_x - 200.0f * local->unk0->spawnPositionDelta;
            spawn_position[1] = this->position_y + 80.0f * local->unk0->spawnPositionDelta;
            spawn_position[2] = this->position_z;
            __spawnQueue_add_4(
                (GenFunction_4)spawnQueue_actor_f32,
                local->unk0->actorId + 1,
                reinterpret_cast(s32, spawn_position[0]),
                reinterpret_cast(s32, spawn_position[1]),
                reinterpret_cast(s32, spawn_position[2]));
        }
    }//L8038D378

    if(this->state == CH_BOSS_BOOM_BOX_STATE_7_UNK){
        actor_collisionOff(this);
        func_803262E4(this);
        skeletalAnim_set(this->unk148, ASSET_147_ANIM_BOOMBOX_MOVE, 0.0f, 1.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        local->currentPosition[0] = this->position_x;
        local->currentPosition[1] = this->position_y;
        local->currentPosition[2] = this->position_z;

        local->spawnPosition[0] = this->position_x;
        local->spawnPosition[1] = this->position_y;
        local->spawnPosition[2] = this->position_z;
        local->unk20 = RBB_func_8038CBF0(this);
    }//L8038D3FC

    if(this->state == CH_BOSS_BOOM_BOX_STATE_3_ATTACK_PLAYER
        || this->state == CH_BOSS_BOOM_BOX_STATE_4_PUSH_BACK
        || this->state == CH_BOSS_BOOM_BOX_STATE_5_BREAKING)
    {
        local->unk20 = RBB_func_8038CBF0(this);
        if( local->unk20 == 0){
            position_delta = local->unk0->spawnPositionDelta * 300.0f;
            for(i = 0; i < 10; i++){
                local->spawnPosition[0] = local->currentPosition[0] + randf2(-position_delta, position_delta);
                local->spawnPosition[1] = local->spawnPosition[1];
                local->spawnPosition[2] = local->currentPosition[2] + randf2(-position_delta, position_delta);
                func_8038CA70(this, &local->spawnPosition);
                local->unk20 = RBB_func_8038CBF0(this);
                if(local->unk20)
                    break;
            }
            if(i == 10){
                local->spawnPosition[0] = local->currentPosition[0];
                local->spawnPosition[2] = local->currentPosition[2];
                local->spawnPosition[1] = 0.0f;
            }
        }
    }//L8038D4DC
    
    if(this->state == CH_BOSS_BOOM_BOX_STATE_3_ATTACK_PLAYER){
        func_80258A4C(
            this->position, this->yaw - 90.0f, player_position,
            &horizontal_distance, &distance_in_front, &side_angle_radian);
        if(0.7 < side_angle_radian)
            local->turnAngle += 90.0f;
        else if(side_angle_radian < -0.7){
            local->turnAngle -= 90.0f;
        }
    }
}

void chBossBoomBox_hitPlayer(ActorMarker *marker, ActorMarker *arg1){
    Actor *actor = marker_getActor(marker);
    chBossBoomBox_setState(actor, CH_BOSS_BOOM_BOX_STATE_4_PUSH_BACK);
}

void chBossBoomBox_ow(ActorMarker *marker, ActorMarker *arg1){
    Actor *actor = marker_getActor(marker);
    ActorLocal_ChBossBoomBox *local = (ActorLocal_ChBossBoomBox *) &actor->local;

    gcsfx_playWithPitch(SFX_3F5_UNKNOWN, local->unk0->unk10, 20000);
    chBossBoomBox_setState(actor, CH_BOSS_BOOM_BOX_STATE_4_PUSH_BACK);
    func_8038C8A8(actor);
}

void chBossBoomBox_die(ActorMarker *marker, ActorMarker *other){
    func_8038D7E8(marker, other->id == 1);
}

Actor *chBossBoomBox_draw(ActorMarker *marker, Gfx **gdl, Mtx ** mptr, Vtx **arg3){
    f32 sp3C[3];
    Actor *actor = marker_getActorAndRotation(marker, sp3C);
    ActorLocal_ChBossBoomBox *local = (ActorLocal_ChBossBoomBox *) &actor->local;
    func_8033A45C(1, local->unk0->unkD);
    if(local->unk0->unkD == 1){
        func_8033A45C(2, (actor->state == 4)? 2: 1);
        func_8033A45C(4, (actor->state == 4)? 2: 1);
        func_8033A45C(5, (actor->state == 4)? 2: 1);
    }//L8038D714
    else{
        func_8033A45C(3, (actor->state == 4)? 2: 1);
        func_8033A45C(6, (actor->state == 4)? 2: 1);
        func_8033A45C(7, (actor->state == 4)? 2: 1);
    }
    modelRender_setPreDrawCallback(actor_predrawMethod, actor);
    modelRender_setPostDrawCallback(actor_postdrawMethod, marker);
    modelRender_draw(gdl, mptr, actor->position, sp3C, actor->scale, NULL, marker_loadModelBin(marker));
    
    return actor;
}

void func_8038D7E8(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    ActorLocal_ChBossBoomBox *local = (ActorLocal_ChBossBoomBox *) &actor->local;

    sfx_playFadeShorthandDefault(SFX_1E_HITTING_AN_ENEMY_2, 1.0f, 20000, actor->position, 1000, 2000);
    gcsfx_playWithPitch(SFX_D7_GRABBA_DEATH, local->unk0->unk10, 0x7530);
    local->unk4 += (arg1) ? 1 : 5;
    if(local->unk4 >= local->unk0->unkC)
        chBossBoomBox_setState(actor, CH_BOSS_BOOM_BOX_STATE_5_BREAKING);
    else{
        chBossBoomBox_setState(actor, CH_BOSS_BOOM_BOX_STATE_4_PUSH_BACK);
    }

    if(!arg1)
        func_8038C8A8(actor);

}

void func_8038D8B4(Actor *actor){}

void chBossBoomBox_update(Actor *this){
    f32 player_position[3];
    ActorLocal_ChBossBoomBox *local = (ActorLocal_ChBossBoomBox *) &this->local;
    f32 prev_anim_progress1;
    f32 curr_anim_progress1;
    f32 prev_anim_progress2;
    f32 curr_anim_progress2;
    f32 sp4C;
    f32 tmp_f2;
    f32 pad;
    

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        local->unk0 = &chBossBoomBoxTable[this->marker->id - MARKER_1A1_BOSS_BOOM_BOX_LARGEST];
        local->unk4 = 0;
        local->unk20 = 0;
        
        this->marker->propPtr->unk8_3 = 0;
        this->scale = local->unk0->spawnPositionDelta;
        if(local->unk0 == chBossBoomBoxTable){
            this->yaw = 270.0f;
        }
        marker_setCollisionScripts(this->marker, chBossBoomBox_hitPlayer, chBossBoomBox_ow, chBossBoomBox_die);
        marker_setFreeMethod(this->marker, func_8038D8B4);
        if(local->unk0->actorId == ACTOR_281_BOSS_BOOM_BOX_LARGEST){
            chBossBoomBox_setState(this, CH_BOSS_BOOM_BOX_STATE_1_WAITING_FOR_PLAYER);
            D_80391280 = 0;
        }
        else{
            chBossBoomBox_setState(this, CH_BOSS_BOOM_BOX_STATE_7_UNK);
        }

        if(jiggyscore_isSpawned(JIGGY_56_RBB_BOSS_BOOM_BOX) && !volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME))
            marker_despawn(this->marker);
        
        if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME))
            chbossboombox_hideJiggy();

        if(volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)){
            chbossboombox_hideJiggy();
            skeletalAnim_set(this->unk148, ASSET_146_ANIM_BOSS_BOOMBOX_APPEAR, 0.0f, 2.4f);
            skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
            this->state = CH_BOSS_BOOM_BOX_STATE_2_HIDES_JIGGY;
        }
        return;
    }

    player_getPosition(player_position);
    if(this->state == CH_BOSS_BOOM_BOX_STATE_1_WAITING_FOR_PLAYER){
        if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
            if(volatileFlag_get(VOLATILE_FLAG_3)){
                chBossBoomBox_setState(this, CH_BOSS_BOOM_BOX_STATE_2_HIDES_JIGGY);
            }
        }
        else{//L8038DAA8
            if(ml_vec3f_distance(this->position, player_position) < 1200.0f){
                chBossBoomBox_setState(this, CH_BOSS_BOOM_BOX_STATE_2_HIDES_JIGGY);
            }
        }
    }//L8038DAD8

    if(this->state == CH_BOSS_BOOM_BOX_STATE_2_HIDES_JIGGY){
        if(skeletalAnim_getAnimId(this->unk148) == ASSET_146_ANIM_BOSS_BOOMBOX_APPEAR && skeletalAnim_getLoopCount(this->unk148) > 0){
            skeletalAnim_set(this->unk148, ASSET_147_ANIM_BOOMBOX_MOVE, 0.2, 1.0f);
            skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        }
    }//L8038DB30

    if( this->state == CH_BOSS_BOOM_BOX_STATE_2_HIDES_JIGGY
        || this->state == CH_BOSS_BOOM_BOX_STATE_3_ATTACK_PLAYER
        || this->state == CH_BOSS_BOOM_BOX_STATE_4_PUSH_BACK){
        if(skeletalAnim_getAnimId(this->unk148) == ASSET_147_ANIM_BOOMBOX_MOVE){
            skeletalAnim_getProgressRange(this->unk148, &prev_anim_progress1, &curr_anim_progress1);
            if(prev_anim_progress1 < 0.6 && 0.6 <= curr_anim_progress1){
                func_8030E878(SFX_6C_LOCKUP_CLOSING, randf2(-0.05f, 0.05f) + local->unk0->volume, 20000, this->position, 500.0f, 1000.0f);
            }//L8038DC04
            if(prev_anim_progress1 < 0.1 && 0.1 <= curr_anim_progress1){
                func_8038C39C(this);
            }
        }
    }//L8038DC48

    if(this->state == CH_BOSS_BOOM_BOX_STATE_3_ATTACK_PLAYER
        || this->state == CH_BOSS_BOOM_BOX_STATE_4_PUSH_BACK){
        if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
            if(item_empty(ITEM_0_HOURGLASS_TIMER)){
                volatileFlag_set(VOLATILE_FLAG_3, 0);
                volatileFlag_set(VOLATILE_FLAG_5_FF_MINIGAME_WON, 0);
                chBossBoomBox_setState(this, CH_BOSS_BOOM_BOX_STATE_8_FF_TIMER_RUN_OUT);
            }
        }
        skeletalAnim_getProgressRange(this->unk148, &prev_anim_progress2, &curr_anim_progress2);
        if(0.1 <= curr_anim_progress2 && curr_anim_progress2 <= 0.6){
            sp4C = (curr_anim_progress2 - 0.1) / 0.5;
            ml_vec3f_interpolate_fast(this->position, local->currentPosition, local->spawnPosition, sp4C);
            this->yaw = local->unk24 + sp4C * (local->turnAngle - local->unk24);
        }

        if(skeletalAnim_getLoopCount(this->unk148) > 0)
            chBossBoomBox_setState(this, CH_BOSS_BOOM_BOX_STATE_3_ATTACK_PLAYER);
        
    }//L8038DD64

    if(this->state == CH_BOSS_BOOM_BOX_STATE_5_BREAKING){
        if(skeletalAnim_getLoopCount(this->unk148) > 0){
            chBossBoomBox_setState(this, CH_BOSS_BOOM_BOX_STATE_6_COMPLETE);
        }else{
            tmp_f2 = skeletalAnim_getProgress(this->unk148);
            if(tmp_f2 <= 0.3)
                tmp_f2 = tmp_f2 / 0.3;
            else
                tmp_f2 = 1.0f;
            ml_vec3f_interpolate_fast(this->position, local->currentPosition, local->spawnPosition, tmp_f2);
        }
    }//L8038DE10

    if(this->state == CH_BOSS_BOOM_BOX_STATE_7_UNK){
        if(skeletalAnim_getLoopCount(this->unk148) > 0)
            chBossBoomBox_setState(this, CH_BOSS_BOOM_BOX_STATE_3_ATTACK_PLAYER);
    }
}
