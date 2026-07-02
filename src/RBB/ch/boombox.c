#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/particle.h"


extern void bundle_setYaw(f32);
extern int  func_80309EB0(f32(*)[3], f32, f32 (*)[3], s32);
extern int func_803342AC(f32(*)[3], f32(*)[3],f32);

/* typedefs and declarations */
typedef struct {
    f32 *unk0;
    f32 unk4;
    f32 unk8[3];
    f32 currentPosition[3];
    f32 targetPosition[3];
    f32 unk2C;
    f32 unk30;
    s32 unk34;
    u8 unk38;
    u8 unk39;
}ActorLocal_RBB_8520;

void chBoomBox_setState(Actor *this, s32 arg1);
Actor *chBoomBox_draw(ActorMarker *marker, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void chBoomBox_update(Actor *this);


/* .data */
f32 D_80390D80[2] = {1.8f, 1.0f};  

ActorInfo chBoomBoxSlow = {
    MARKER_1B7_BOOM_BOX, ACTOR_2A4_BOOM_BOX_SLOW, ASSET_48C_MODEL_BOOM_BOX,
    0x0, NULL,
    chBoomBox_update, NULL, chBoomBox_draw,
    0, 0, 0.0f, 0
};

ActorInfo chBoomBoxFast = {
    MARKER_1B7_BOOM_BOX, ACTOR_30D_BOOM_BOX_FAST, ASSET_48C_MODEL_BOOM_BOX,
    0x0, NULL,
    chBoomBox_update, NULL, chBoomBox_draw,
    0, 0, 0.0f, 0
};

s32 RBB_D_80390DD0[3] = {0xDE, 0xA7, 0x71};
s32 D_80390DDC[4] = {0xFF, 0xFF, 0xFF, 0xFF};
f32 D_80390DEC[4] = {0.0f, 0.0f, 0.0f, 0.0f};

enum chboombox_state_e {
    CH_BOOM_BOX_STATE_0_NOT_INIT,
    CH_BOOM_BOX_STATE_1_UNK,
    CH_BOOM_BOX_STATE_2_UNK,
    CH_BOOM_BOX_STATE_3_EXPLODE
};

/* .bss */
f32 D_803912A0[3];

/* .code */
void func_8038E910(Actor *this){
    ActorLocal_RBB_8520 *local = (ActorLocal_RBB_8520 *)&this->local;
    local->unk30 = 3.0f;
}

void func_8038E920(Actor *this){
    ActorLocal_RBB_8520 *local = (ActorLocal_RBB_8520 *)&this->local;
    local->unk30 = 0.0f;
}

void func_8038E92C(Actor *this){
    ActorLocal_RBB_8520 *local = (ActorLocal_RBB_8520 *)&this->local;

    if(this->state == CH_BOOM_BOX_STATE_2_UNK && local->unk34 == 0)
        return;
    if(ml_timer_update( &local->unk30, time_getDelta()))
        chBoomBox_setState(this, CH_BOOM_BOX_STATE_3_EXPLODE);
}

void chBoomBox_emitSmokeBeforeExplosion(Actor *this){
    ParticleEmitter *other = partEmitMgr_newEmitter(2);
    f32 temp_f0;

    particleEmitter_setSprite(other, ASSET_70E_SPRITE_SMOKE_2);
    particleEmitter_setFade(other, 0.0f, 0.1f);
    particleEmitter_setStartingFrameRange(other, 0, 7);
    particleEmitter_setPosition(other, this->position);
    particleEmitter_setStartingScaleRange(other, 0.25f, 0.75f);
    particleEmitter_setFinalScaleRange(other, 0.75f, 1.75f);
    particleEmitter_setSpawnPositionRange(other, -50.0f, 25.0f, -50.0f, 50.0f, 25.0f, 50.0f);
    particleEmitter_setParticleVelocityRange(other, -50.0f, 100.0f, -50.0f, 50.0f, 200.0f, 50.0f);
    particleEmitter_setParticleLifeTimeRange(other, 0.5f, 1.0f);
    particleEmitter_emitN(other, 2);
}

void chBoomBox_emitExplosion(Actor *this){
    ParticleEmitter *other;
    func_802BB3DC(0, 60.0f, 0.9f);
    other = partEmitMgr_newEmitter(1);
    particleEmitter_setSprite(other, ASSET_4A0_SPRITE_EXPLOSION);
    particleEmitter_setFade(other, 0.1f, 0.2f);
    particleEmitter_setDrawMode(other, PART_EMIT_NO_LOOP);
    particleEmitter_setStartingFrameRange(other, 0, 0);
    particleEmitter_setParticleFramerateRange(other, 4.0f, 4.0f);
    particleEmitter_setSpawnPositionRange(other, 0.0f, 200.0f, 0.0f, 0.0f, 200.0f, 0.0f);
    particleEmitter_setPosition(other, this->position);
    particleEmitter_setStartingScaleRange(other, 3.0f, 3.0f);
    particleEmitter_setFinalScaleRange(other, 8.0f, 8.0f);
    particleEmitter_setParticleLifeTimeRange(other, 0.5f, 0.5f);
    particleEmitter_setParticleVelocityRange(other, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    particleEmitter_emitN(other, 1);
}

void chBoomBox_emitSmokeAfterExplosion(Actor *this){
    ParticleEmitter *other;
    other = partEmitMgr_newEmitter(6);
    particleEmitter_setSprite(other, ASSET_70E_SPRITE_SMOKE_2);
    particleEmitter_setFade(other, 0.05f, 0.1f);
    particleEmitter_setStartingFrameRange(other, 0, 7);
    particleEmitter_setPosition(other, this->position);
    particleEmitter_setStartingScaleRange(other, 1.0f, 1.5f);
    particleEmitter_setFinalScaleRange(other, 2.0f, 3.0f);
    particleEmitter_setSpawnPositionRange(other, -75.0f, 25.0f, -75.0f, 75.0f, 75.0f, 75.0f);
    particleEmitter_setParticleVelocityRange(other, -70.0f, 50.0f, -70.0f, 70.0f, 100.0f, 70.0f);
    particleEmitter_setRGB(other, RBB_D_80390DD0);
    particleEmitter_setParticleLifeTimeRange(other, 3.0f, 4.0f);
    particleEmitter_emitN(other, 6);
}

void chBoomBox_emitModelsAfterExplosion(Actor * actor, s32 arg1){
    ParticleEmitter *other = partEmitMgr_newEmitter(0xa);
    particleEmitter_setAccelerationRange(other, 0.0f, -800.0f, 0.0f, 0.0f, -800.0f, 0.0f);
    particleEmitter_func_802EF9F8(other, 0.6f);
    particleEmitter_func_802EFA18(other, 3);
    particleEmitter_setModel(other, arg1);
    particleEmitter_setPosition(other, actor->position);
    particleEmitter_setStartingScaleRange(other, 0.05f, 0.4f);
    particleEmitter_setAngularVelocityRange(other, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setSpawnIntervalRange(other, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(other, 10.0f, 10.0f);
    particleEmitter_setParticleVelocityRange(other, -700.0f, 200.0f, -700.0f, 700.0f, 500.0f, 700.0f);
    particleEmitter_emitN(other, 0xa);
}

int func_8038EE90(Actor *this){
    f32 sp2C[3];
    f32 sp20[3];
    ActorLocal_RBB_8520 *local = (ActorLocal_RBB_8520 *)&this->local;

    sp2C[0] = local->currentPosition[0];
    sp2C[1] = local->currentPosition[1];
    sp2C[2] = local->currentPosition[2];

    sp20[0] = local->targetPosition[0];
    sp20[1] = local->targetPosition[1];
    sp20[2] = local->targetPosition[2];

    sp2C[1] += 75.0f;
    sp20[1] += 75.0f;
    return func_803342AC(&sp2C, &sp20, 100.0f);
}

bool chBoombox_isValidMovePosition(Actor *this, f32 position[3], f32 speed_multiplier){
    f32 position_diff[3];
    bool ceiling_exists;
    ActorLocal_RBB_8520 *local = (ActorLocal_RBB_8520 *)&this->local;
    f32 ceiling_check_position[3];
    f32 collision_radius;
    f32 ceiling_collision_output[3];
    

    position_diff[0] = position[0] - this->position_x;
    position_diff[1] = position[1] - this->position_y;
    position_diff[2] = position[2] - this->position_z;
    if(180.0 < LENGTH_VEC3F(position_diff))
        ml_vec3f_set_length(position_diff, 150.0f);
    
    local->targetPosition[0] = position_diff[0] + this->position_x;
    local->targetPosition[1] = position_diff[1] + this->position_y;
    local->targetPosition[2] = position_diff[2] + this->position_z;

    local->targetPosition[1] = mapModel_getFloorY(local->targetPosition);

    ceiling_check_position[0] = local->targetPosition[0];
    ceiling_check_position[1] = local->targetPosition[1] + this->scale * 100.0f;
    ceiling_check_position[2] = local->targetPosition[2];
    collision_radius = this->scale * 60.0f;
    if(func_80309EB0(&ceiling_check_position, collision_radius, &ceiling_collision_output, 0)){
        ceiling_exists = TRUE;
    }else{
        ceiling_exists = FALSE;
    }
    if( !func_80329210(this, &local->targetPosition) 
        || ((local->unk2C + 30.0f) < local->targetPosition[1])
        || ceiling_exists
    ){
        local->targetPosition[0] = this->position_x;
        local->targetPosition[1] = this->position_y;
        local->targetPosition[2] = this->position_z;
        if(local->unk39 < 3 && ++local->unk39 == 3){
            local->unk39 = 0;
            return FALSE;
        }
    }else{
        local->unk34 = func_8038EE90(this);
        if(local->unk34 == 0){
            local->targetPosition[0] = this->position_x;
            local->targetPosition[1] = this->position_y;
            local->targetPosition[2] = this->position_z;
        }
    }
    skeletalAnim_set(this->unk148, ASSET_147_ANIM_BOOMBOX_MOVE, 0.1f, randf2(-0.1f, 0.1f) + (1.0 / speed_multiplier) * 0.4);
    skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    local->currentPosition[0] = this->position_x; 
    local->currentPosition[1] = this->position_y; 
    local->currentPosition[2] = this->position_z;
    return TRUE;
}

void chBoomBox_setState(Actor *this, s32 next_state){
    f32 player_position[3];
    ActorLocal_RBB_8520 *local = (ActorLocal_RBB_8520 *)&this->local;
    
    player_getPosition(player_position);

    if(local->unk34){
        func_803343F8(local->unk34);
        local->unk34 = FALSE;
    }

    if(next_state == CH_BOOM_BOX_STATE_1_UNK){
        skeletalAnim_set(this->unk148, ASSET_147_ANIM_BOOMBOX_MOVE, 0.2f, 1.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_4_STOPPED);
    }//L8038F204

    if(next_state == CH_BOOM_BOX_STATE_2_UNK){
        bool is_valid_move_position = FALSE;
        if(func_80329210(this, &player_position)){
            local->unk4 += 0.3;
            if(*local->unk0 < local->unk4)
                local->unk4 = *local->unk0;
            is_valid_move_position = chBoombox_isValidMovePosition(this, player_position, local->unk4);
        }//L8038F28C
        if(!is_valid_move_position){
            func_8038E920(this);
            local->unk4 -= 0.5;
            if(local->unk4 < 0.5)
                local->unk4 = 0.5f;
            chBoombox_isValidMovePosition(this, local->unk8, local->unk4);
        }
    }//L8038F2FC

    if(next_state == CH_BOOM_BOX_STATE_3_EXPLODE){
        chBoomBoxMinigameCtrl_countDec();
        actor_collisionOff(this);
        func_80324D54(0.0f, SFX_1B_EXPLOSION_1, 1.0f, 0x7d00, this->position, 1000.0f, 2000.0f);
        skeletalAnim_set(this->unk148, ASSET_148_ANIM_BOOMBOX_DIE, 0.2f, 1.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        chBoomBox_emitExplosion(this);
        chBoomBox_emitSmokeAfterExplosion(this);
        chBoomBox_emitModelsAfterExplosion(this, ASSET_53A_MODEL_SHRAPNAL_PIECE_EYE);
        chBoomBox_emitModelsAfterExplosion(this, ASSET_53B_MODEL_SHRAPNAL_PIECE_SPIKE);
        chBoomBox_emitModelsAfterExplosion(this, ASSET_53C_MODEL_SHRAPNAL_PIECE_PLATE);
        func_80326310(this);
        this->unk10_1 = 0;
        func_8038E920(this);

    }//L8038F3C8
    this->state = next_state;
}


void func_8038F3F0(ActorMarker *marker, ActorMarker *arg1){
    Actor* actor =  marker_getActor(marker);
    if(actor->state < 3){
        chBoomBox_setState(actor, CH_BOOM_BOX_STATE_3_EXPLODE);
    }
}

void func_8038F430(ActorMarker *marker, ActorMarker *arg1){
    Actor* actor =  marker_getActor(marker);
    f32 player_position[3];

    if(actor->state < 3){
        player_getPosition(player_position);
        if(ml_vec3f_distance(actor->position, player_position) < 300.0f)
            func_8028F55C(5, actor->marker);
        chBoomBox_setState(actor, CH_BOOM_BOX_STATE_3_EXPLODE);
    }//L8038F4A4
}

Actor * chBoomBox_draw(ActorMarker *marker, Gfx **gdl, Mtx **mptr, Vtx **arg3){
    Actor *actor;
    ActorLocal_RBB_8520 *local;
    s32 sp28[4];
    f32 temp_f2;
    //s32 temp_v0;

    actor = marker_getActor(marker);
    local = (ActorLocal_RBB_8520 *)&actor->local;
    modelRender_setAppendageVisibility(1,2);
    modelRender_setAppendageVisibility(3,1);
    modelRender_setAppendageVisibility(6,1);
    modelRender_setAppendageVisibility(7,1);
    if(local->unk30 > 0.0f && local->unk30 <= 1.0){
        temp_f2 = 2*(3*local->unk30 - (s32)(3*local->unk30));
        if (temp_f2 > 1.0f) 
            temp_f2 = 2 - temp_f2;
        
        sp28[0] = (s32) (temp_f2*255);\
        sp28[1] = (s32) (temp_f2*255);\
        sp28[2] = (s32) (temp_f2*255);
        sp28[3] = 255;
        D_803912A0[0] = actor->pitch;
        D_803912A0[1] = actor->yaw;
        D_803912A0[2] = actor->roll;
        modelRender_setPrimAndEnvColors(sp28, D_80390DDC);
    }//L8038F5F8
    return actor_draw(marker, gdl, mptr, arg3);
}

void chBoomBox_update(Actor *this){
    f32 player_position[3];
    int sp78;
    ActorLocal_RBB_8520 *local = (ActorLocal_RBB_8520 *)&this->local;
    f32 sp70 = time_getDelta();
    f32 prev_anim_progress;
    f32 curr_anim_progress;
    f32 this_position[3];
    f32 sp50[3];
    f32 horizontal_distance;
    f32 distance_in_front;
    f32 side_angle_radian;
    f32 pad0;
    

    if(!this->volatile_initialized){
        this->marker->propPtr->unk8_3 = 0;
        this->volatile_initialized = TRUE;
        local->unk8[0] = this->position_x;
        local->unk8[1] = this->position_y;
        local->unk8[2] = this->position_z;
        local->unk38 = 0;
        local->unk39 = 0;
        local->unk0 = &D_80390D80[(this->modelCacheIndex ==  ACTOR_30D_BOOM_BOX_FAST)? 1 : 0];
        local->unk2C = mapModel_getFloorY(this->position);
        local->unk34 = 0;
        local->unk4 = 0.5f;
        local->unk30 = 0.0f;
        marker_setCollisionScripts(this->marker, func_8038F430, func_8038F3F0, func_8038F430);
        chBoomBox_setState(this, CH_BOOM_BOX_STATE_1_UNK);
        return;
    }//L8038F714

    player_getPosition(player_position);
    sp78 = func_80329210(this, player_position);
    if(!local->unk38){
        local->unk38 = TRUE;
        chBoomBoxMinigameCtrl_countInc();
    }
    func_8038E92C(this);
    if(this->state == CH_BOOM_BOX_STATE_1_UNK){
        if(sp78 && ml_vec3f_distance(this->position, player_position) < 500.0f){
            chBoomBox_setState(this, CH_BOOM_BOX_STATE_2_UNK);
        }
    }//L8038F7A0

    if(this->state == CH_BOOM_BOX_STATE_2_UNK){
        this_position[0] = this->position_x;
        this_position[1] = this->position_y;
        this_position[2] = this->position_z;
        
        if(0.0f != local->unk30 && !sp78)
            func_8038E920(this);

        if(0.0f == local->unk30 && sp78)
            func_8038E910(this);

        skeletalAnim_getProgressRange(this->unk148, &prev_anim_progress, &curr_anim_progress);

        if(0.1 <= curr_anim_progress && curr_anim_progress <= 0.6)
            ml_vec3f_interpolate_fast(this->position, local->currentPosition, local->targetPosition, (curr_anim_progress - 0.1) / 0.5);
        if(prev_anim_progress < 0.6 && 0.6 <= curr_anim_progress)
            func_8030E878(SFX_6C_LOCKUP_CLOSING, 1.1 + randf2(-0.05f, 0.05f), 20000, this->position, 500.0f, 1000.0f);

        if(prev_anim_progress < 0.1 && 0.1 <= curr_anim_progress)
            chBoomBox_emitSmokeBeforeExplosion(this);

        sp50[0] = local->targetPosition[0] - local->currentPosition[0];
        sp50[1] = local->targetPosition[1] - local->currentPosition[1];
        sp50[2] = local->targetPosition[2] - local->currentPosition[2];

        func_80258A4C(
            D_80390DEC, this->yaw - 90.0f, sp50,
            &horizontal_distance, &distance_in_front, &side_angle_radian);
        
        this->yaw += (side_angle_radian * 400.0f) * sp70;
        if(skeletalAnim_getLoopCount(this->unk148) > 0){
            if(ml_vec3f_distance(this->position, local->unk8) < 10.0f){
                chBoomBox_setState(this, CH_BOOM_BOX_STATE_1_UNK);
            }else{
                chBoomBox_setState(this, CH_BOOM_BOX_STATE_2_UNK);
            }
        }
    }//L8038FA50
}
