#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    u8  unk0;
    u8  unk1;
    s16 currentPosition[3];
    s16 targetPosition[3];
    s16 spawnPosition[3];
    f32 unk14; // time related?
    f32 unk18;
    f32 unk1C[2]; // rand + time?
    // f32 unk20;
    f32 unk24; // rand/time related?
}ActorLocal_Flibbit;

extern f32 mapModel_getFloorY(f32 *);

void chFlibbit_update(Actor *this);
Actor *chFlibbit_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorInfo gChFlibbit = {
    MARKER_C1_FLIBBIT_RED, ACTOR_133_FLIBBIT_RED, ASSET_375_MODEL_FLIBBIT_RED,
    0, NULL, 
    chFlibbit_update, NULL, chFlibbit_draw,
    0, 0, 1.0f, 0
};

f32 bgsCenterOfMap[3] = {0.0f, 0.0f, 0.0f};

enum chFlibbitState {
    CH_FLIBBIT_STATE_1_IDLE = 1,
    CH_FLIBBIT_STATE_2_JUMPING,
    CH_FLIBBIT_STATE_3_TURN_IN_PLACE,
    CH_FLIBBIT_STATE_4_HIT_PLAYER,
    CH_FLIBBIT_STATE_5_OW,
    CH_FLIBBIT_STATE_6_DIE,
    CH_FLIBBIT_STATE_7_DEAD,
    CH_FLIBBIT_STATE_8_DESPAWN
};

/* .code */
bool BGS_func_803863F0(Actor *this, f32 arg1[3], s32 arg2){

    ActorLocal_Flibbit *local = (ActorLocal_Flibbit *)&this->local;

    local->unk1 = arg2;

    local->currentPosition[0] = this->position[0];\
    local->currentPosition[1] = this->position[1];\
    local->currentPosition[2] = this->position[2];
    local->targetPosition[0] = arg1[0];
    local->targetPosition[1] = arg1[1];
    local->targetPosition[2] = arg1[2];

    local->targetPosition[1] = mapModel_getFloorY(arg1);
    skeletalAnim_set(this->unk148, 0xdb, 0.2f,(arg2) ?  randf2(0.7f, 0.8f) :  randf2(0.75f, 0.85f));
    skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    func_80324D54(0.2f, 0x3f2, randf2(0.7f, 1.3f), randi2(0x61A8, 0x6978), this->position, 500.0f, 2500.0f);
    return TRUE;
}

bool func_80386564(Actor *this){
    f32 plyrPos[3];
    f32 horizontal_distance; // unused
    f32 distance_in_front; // unused
    f32 side_angle_radian;
    f32 dst[3];
    f32 target_position[3];

    player_getPosition(plyrPos);
    func_80258A4C(
        this->position,
        this->yaw - 90.0f,
        plyrPos,
        &horizontal_distance,
        &distance_in_front,
        &side_angle_radian);
    if(func_80329210(this, plyrPos)){
        if((-0.7 <= side_angle_radian) && (side_angle_radian <= 0.7)){
            dst[0] = plyrPos[0] - this->position_x;
            dst[1] = plyrPos[1] - this->position_y;
            dst[2] = plyrPos[2] - this->position_z;
            ml_vec3f_set_length(dst, 180.0f);
            target_position[0] = dst[0] + this->position_x;
            target_position[1] = dst[1] + this->position_y;
            target_position[2] = dst[2] + this->position_z;
            if(func_80329210(this, target_position))
                return BGS_func_803863F0(this, target_position, 1);
        }
    }
    return FALSE;

}

s32 func_803866A4(Actor *this) {
    f32 spawn_position[3];
    f32 horizontal_distance;
    f32 distance_in_front; // unused
    f32 side_angle_radian;
    f32 dst[3];
    ActorLocal_Flibbit *local = (ActorLocal_Flibbit *)&this->local;
    f32 target_position[3];


    spawn_position[0] = (f32) local->spawnPosition[0];
    spawn_position[1] = (f32) local->spawnPosition[1];
    spawn_position[2] = (f32) local->spawnPosition[2];
    func_80258A4C(
        this->position,
        this->yaw - 90.0f,
        spawn_position,
        &horizontal_distance,
        &distance_in_front,
        &side_angle_radian);
    if ((-0.9 <= side_angle_radian) && (side_angle_radian <= 0.9)) {
        if ((f64) horizontal_distance > 216.0) {
            dst[0] = spawn_position[0] - this->position[0];
            dst[1] = spawn_position[1] - this->position[1];
            dst[2] = spawn_position[2] - this->position[2];
            ml_vec3f_set_length(dst, 180.0f);
            target_position[0] = this->position[0] + dst[0];
            target_position[1] = this->position[1] + dst[1];
            target_position[2] = this->position[2] + dst[2];
        } else {
            target_position[0] = (f32) local->spawnPosition[0];
            target_position[1] = (f32) local->spawnPosition[1];
            target_position[2] = (f32) local->spawnPosition[2];
        }
        if (func_80329210(this, target_position) != 0) {
            return BGS_func_803863F0(this, target_position, 0);
        }
    }
    return 0;
}


bool func_8038686C(Actor *this) {
    f32 player_position[3];
    f32 horizontal_distance;
    f32 distance_in_front; // unused
    f32 side_angle_radian;
    f32 *temp_s2;
    f32 sp68[3];
    f32 phi_f2;
    int i;

    player_getPosition(player_position);
    func_80258A4C(
        this->position,
        this->yaw - 90.0f,
        player_position,
        &horizontal_distance,
        &distance_in_front,
        &side_angle_radian);
    for(i = 0; i < 0xA; i++){
        if (i < 5) {
            if (side_angle_radian > 0.0f) {
                phi_f2 = randf2(10.0f, 90.0f) + this->yaw;
            } else {
                phi_f2 = randf2(-90.0f, -10.0f) + this->yaw;
            }
        } else {
            phi_f2 = randf2(-110.0f, 110.0f) + this->yaw;
        }
        func_80256E24(sp68, 0.0f, phi_f2, 0.0f, 0.0f, 180.0f);
        sp68[0] += this->position[0];
        sp68[1] += this->position[1];
        sp68[2] += this->position[2];
        if (func_80329210(this, sp68)) {
            return BGS_func_803863F0(this, sp68, 0);
        }
    }
    return FALSE;
}

bool func_80386A34(Actor * this){
    f32 plyrPos[3];
    bool out;

    if(volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE))
        return FALSE;
    
    player_getPosition(plyrPos);
    if(func_80329210(this, plyrPos)){
        if(!(out = func_80386564(this)) && (0.5 < randf())){
            return FALSE;
        }
    }else{
        out = func_803866A4(this);
    }

    if(!out)
        out = func_8038686C(this);
    
    return out;
}

void chFlibbit_setState(Actor *this, s32 next_state) {
    ActorLocal_Flibbit *local;

    local = (ActorLocal_Flibbit *) &this->local;
    local->unk1 = FALSE;
    local->unk18 = 0.0f;
    local->unk24 = 0.0f;

    if (next_state == CH_FLIBBIT_STATE_1_IDLE) {
        skeletalAnim_set(this->unk148, ASSET_FA_ANIM_FLIBBIT_IDLE, 0.2f, randf2(1.0f, 2.0f));
        skeletalAnim_setProgress(this->unk148, randf2(0.0f, 0.9f));
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        this->position[0] = (f32) local->spawnPosition[0];
        this->position[1] = (f32) local->spawnPosition[1];
        this->position[2] = (f32) local->spawnPosition[2];
        local->unk24 = randf2(1.0f, 3.0f);
    }
    
    if (next_state == CH_FLIBBIT_STATE_2_JUMPING){
        if(!func_80386A34(this)) {
            if (this->state != CH_FLIBBIT_STATE_3_TURN_IN_PLACE) {
                next_state = CH_FLIBBIT_STATE_3_TURN_IN_PLACE;
                chFlibbit_setState(this, next_state);
            }
            return;
        }
    } 

    if (next_state == CH_FLIBBIT_STATE_3_TURN_IN_PLACE) {
        skeletalAnim_set(this->unk148, ASSET_FB_ANIM_FLIBBIT_TURN, 0.2f, 1.0f);
        skeletalAnim_setProgress(this->unk148, randf2(0.0f, 1.0f));
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        local->unk24 = randf2(1.0f, 3.0f);
    }

    if (next_state == CH_FLIBBIT_STATE_4_HIT_PLAYER) {
        skeletalAnim_set(this->unk148, ASSET_FA_ANIM_FLIBBIT_IDLE, 0.2f, randf2(1.0f, 2.0f));
        skeletalAnim_setProgress(this->unk148, randf2(0.0f, 0.9f));
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        this->position[1] = mapModel_getFloorY(this->position);
        local->unk18 = 1.0f;
    }

    if (next_state == CH_FLIBBIT_STATE_5_OW) {
        sfx_playFadeShorthandDefault(SFX_8E_GRUNTLING_DAMAGE, 1.5f, 32200, this->position, 500, 2500);
        skeletalAnim_set(this->unk148, ASSET_288_ANIM_FLIBBIT_OW, 0.1f, 0.65f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        this->position[1] = mapModel_getFloorY(this->position);
        local->unk18 = 1.0f;
    }

    if (next_state == CH_FLIBBIT_STATE_6_DIE) {
        skeletalAnim_set(this->unk148, ASSET_112_ANIM_FLIBBIT_DIE, 0.2f, 0.4f);
        sfx_playFadeShorthandDefault(SFX_115_BUZZBOMB_DEATH, 1.0f, 32200, this->position, 500, 2500);
        this->marker->collidable = FALSE;
        this->unk10_1 = FALSE;
        local->unk14 = 1000.0f;
    }
    if (next_state == CH_FLIBBIT_STATE_7_DEAD) {
        skeletalAnim_set(this->unk148, ASSET_113_ANIM_FLIBBIT_DEAD, 0.2f, 1.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        sfx_playFadeShorthandDefault(SFX_2F_ORANGE_SPLAT, 0.8f, 32200, this->position, 500, 2500);
    }
    if (next_state == CH_FLIBBIT_STATE_8_DESPAWN) {
        func_80326310(this);
    }
    this->state = next_state;
}

void chFlibbit_attack(ActorMarker *this, ActorMarker *other){
    Actor *thisActor = marker_getActor(this);
    if(thisActor->state < CH_FLIBBIT_STATE_6_DIE){
        chFlibbit_setState(thisActor, CH_FLIBBIT_STATE_4_HIT_PLAYER);
    }
}

void chFlibbit_ow(ActorMarker *this, ActorMarker *other){
    Actor *thisActor = marker_getActor(this);
    if(thisActor->state < CH_FLIBBIT_STATE_6_DIE){
        chFlibbit_setState(thisActor, CH_FLIBBIT_STATE_5_OW);
    }
}

void chFlibbit_die(ActorMarker *this, ActorMarker *other){
    Actor *thisActor = marker_getActor(this);
    if(thisActor->state < CH_FLIBBIT_STATE_6_DIE){
        chFlibbit_setState(thisActor, CH_FLIBBIT_STATE_6_DIE);
    }
}

Actor *chFlibbit_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    ActorLocal_Flibbit *local;
    BoneTransformList *temp_a0;
    int i;
    f32 bone_scale[3];
    f32 phi_f2;

    this = marker_getActor(marker);
    local = (ActorLocal_Flibbit *)&this->local;
    if (local->unk0){
        if(((this->state == CH_FLIBBIT_STATE_1_IDLE)) || (this->state == CH_FLIBBIT_STATE_3_TURN_IN_PLACE)) {
            temp_a0 = skeletalAnim_getBoneTransformList(this->unk148);
            for(i = 0; i < 2; i++){
                
                if (0.1 <= local->unk1C[i]) {
                    phi_f2 = (f32) ((local->unk1C[i] - 0.1) / 0.1);
                } else if (local->unk1C[i] >= 0.0f) {
                    phi_f2 = (f32) (1.0 - (local->unk1C[i] / 0.1));
                } else {
                    phi_f2 = 1.0f;
                }
                bone_scale[0] = 1.0f;
                bone_scale[2] = 1.0f;
                bone_scale[1] = (f32) (((f64) phi_f2 * 0.99) + 0.01);

                boneTransformList_setBoneScale(temp_a0, (i != 0)? 0x2D :0x2E, bone_scale);
            }
        }
    }
    actor_draw(marker, gfx, mtx, vtx);
    local->unk0 = marker->unk14_21;

    return this;
}

void chFlibbit_update(Actor *this){
    f32 player_position[3];
    f32 spB0[3];
    f32 player_distance;
    ActorLocal_Flibbit *local = (ActorLocal_Flibbit *)&this->local;
    f32 time_delta = time_getDelta();
    f32 horizontal_distance_1;
    f32 distance_in_front_1;
    f32 side_angle_radian_1;
    f32 skel_anim_prev_prog;
    f32 skel_anim_progress;
    f32 spawn_position[3];
    f32 temp_f12;
    f32 horizontal_distance_2;
    f32 distance_in_front_2;
    f32 side_angle_radian_2;
    f32 dst[3];
    f32 phi_f2;
    f32 horizontal_distance_3;
    f32 distance_in_front_3;
    f32 side_angle_radian_3;
    f32 sp4C[3];

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        marker_setCollisionScripts(this->marker, chFlibbit_attack, chFlibbit_ow, chFlibbit_die);
        local->unk1C[0] = randf2(-2.0f, -1.0f);
        local->unk1C[1] = randf2(-2.0f, -1.0f);

        local->spawnPosition[0] = (s16) this->position_x;
        local->spawnPosition[1] = (s16) this->position_y;
        local->spawnPosition[2] = (s16) this->position_z;
        
        local->spawnPosition[1] = mapModel_getFloorY(this->position);
        chFlibbit_setState(this, CH_FLIBBIT_STATE_1_IDLE);
    }

    player_getPosition(player_position);

    TUPLE_DIFF_COPY(spB0, player_position, this->position)
    player_distance = LENGTH_VEC3F(spB0);

    if(ml_timer_update(&local->unk24, time_delta)){
        func_8030E878(0x3f0, randf2(0.9f, 1.1f), randi2(12000, 19000), this->position, 500.0f, 2500.0f);
        local->unk24 = randf2(1.0f, 6.0f);
    }//L80387274

    local->unk1C[0] += time_delta;
    local->unk1C[0] = (0.2 < local->unk1C[0]) ? randf2(-3.0f, -1.0f) : local->unk1C[0];

    local->unk1C[1] += time_delta;
    local->unk1C[1] = (0.2 < local->unk1C[1]) ? randf2(-3.0f, -1.0f) : local->unk1C[1];

    if(this->state == CH_FLIBBIT_STATE_1_IDLE){
        if(func_80329210(this, player_position)){
            chFlibbit_setState(this, CH_FLIBBIT_STATE_2_JUMPING);
            return;
        }

        if(player_distance < 2000.0f){
            func_80258A4C(
                this->position,
                this->yaw - 90.0f,
                player_position,
                &horizontal_distance_1,
                &distance_in_front_1,
                &side_angle_radian_1);
            this->yaw += (side_angle_radian_1 * 90.0f) *time_delta; 
        }
    }//L803873D0

    if(this->state == CH_FLIBBIT_STATE_2_JUMPING){
        skeletalAnim_getProgressRange(this->unk148, &skel_anim_prev_prog, &skel_anim_progress);
        if(skel_anim_prev_prog < 0.8 && 0.8 <= skel_anim_progress){
            func_8030E878(
                SFX_8_BANJO_LANDING_04,
                randf2(0.8f, 0.9f),
                randi2(25000, 27000),
                this->position,
                100.0f,
                1500.0f);
        }//L8038747C
        if(skeletalAnim_getLoopCount(this->unk148) > 0){
            spawn_position[0]  = (f32)local->spawnPosition[0];
            spawn_position[1]  = (f32)local->spawnPosition[1];
            spawn_position[2]  = (f32)local->spawnPosition[2];
            if(ml_vec3f_distance(this->position, spawn_position) < 30.0f){
                chFlibbit_setState(this, CH_FLIBBIT_STATE_1_IDLE);
            }
            else{
                chFlibbit_setState(this, CH_FLIBBIT_STATE_2_JUMPING);
            }
        }
        else{//L80387514
            if(0.2 <= skel_anim_progress && skel_anim_progress <= 0.8){
                temp_f12 = ((skel_anim_progress - 0.2) / 0.60000000000000009);
                this->position_x = local->currentPosition[0] + (local->targetPosition[0] - local->currentPosition[0]) * temp_f12;
                this->position_y = local->currentPosition[1] + (local->targetPosition[1] - local->currentPosition[1]) * temp_f12;
                this->position_z = local->currentPosition[2] + (local->targetPosition[2] - local->currentPosition[2]) * temp_f12;
                if(local->unk1){
                    if(skel_anim_progress <= 0.5){
                        phi_f2 = ((skel_anim_progress - 0.2) / 0.3) * 70.0;
                    }
                    else{
                        phi_f2 = (1.0 - (skel_anim_progress - 0.5) / 0.30000000000000004) * 70.0;
                    }
                    this->position_y += phi_f2;
                }//L80387684
                dst[0] =  (f32)(local->targetPosition[0] - local->currentPosition[0]);
                dst[1] =  (f32)(local->targetPosition[1] - local->currentPosition[1]);
                dst[2] =  (f32)(local->targetPosition[2] - local->currentPosition[2]);
                func_80258A4C(
                    bgsCenterOfMap,
                    this->yaw - 90.0f,
                    dst,
                    &horizontal_distance_2,
                    &distance_in_front_2,
                    &side_angle_radian_2);
                this->yaw += (side_angle_radian_2 * 220.0f * time_delta);

            }
        }
    }//L80387734

    if (this->state == CH_FLIBBIT_STATE_3_TURN_IN_PLACE) {
        func_80258A4C(
            this->position,
            this->yaw - 90.0f,
            player_position,
            &horizontal_distance_3,
            &distance_in_front_3,
            &side_angle_radian_3);
        this->yaw += side_angle_radian_3 * 90.0f * time_delta;
        if ((-0.4 <= side_angle_radian_3) && (side_angle_radian_3 <= 0.4) && ((f64) randf() > 0.5)) {
            chFlibbit_setState(this, CH_FLIBBIT_STATE_2_JUMPING);
        }
        if ((distance_in_front_3 < 0.0f) && (randf() > 0.5)) {
            chFlibbit_setState(this, CH_FLIBBIT_STATE_2_JUMPING);
        }
    }


    if(this->state == CH_FLIBBIT_STATE_4_HIT_PLAYER || this->state == CH_FLIBBIT_STATE_5_OW){
        if(ml_timer_update(&local->unk18, time_delta)){
            chFlibbit_setState(this, CH_FLIBBIT_STATE_3_TURN_IN_PLACE);
        }
    }

    if(this->state == CH_FLIBBIT_STATE_6_DIE){
        TUPLE_DIFF_COPY(sp4C, this->position, player_position)
        sp4C[1] = 0.0f;
        ml_vec3f_set_length(sp4C, 400.0f * time_delta);

        TUPLE_ADD_COPY(this->position, this->position, sp4C)

        this->position_y += local->unk14 * time_delta;
        local->unk14 -= 3000.0f * time_delta;
        if(this->position_y  < mapModel_getFloorY(this->position)){
            this->position_y  = mapModel_getFloorY(this->position);
            chFlibbit_setState(this, CH_FLIBBIT_STATE_7_DEAD);
        }
    }

    if(this->state == CH_FLIBBIT_STATE_7_DEAD){
        if(skeletalAnim_getLoopCount(this->unk148) > 0)
            chFlibbit_setState(this, CH_FLIBBIT_STATE_8_DESPAWN);
    }
}
