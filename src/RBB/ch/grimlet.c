#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    f32 unk0;
    u8 unk4;
    u8 unk5;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
}ActorLocal_RBB_1FC0;

Actor *chGrimlet_draw(ActorMarker * marker, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void chGrimlet_update(Actor *this);

/* .data */ 
ActorInfo chGrimlet = {
    MARKER_2E_GRIMLET, ACTOR_1C6_GRIMLET, ASSET_419_MODEL_GRIMLET,
    0x0, NULL,
    chGrimlet_update, NULL, chGrimlet_draw,
    0, 0, 0.0f, 0
};

enum chgrimlet_state_e {
    CH_GRIMLET_STATE_0_NOT_INIT,
    CH_GRIMLET_STATE_1_UNK,
    CH_GRIMLET_STATE_2_UNK
};

/* .code */
void chGrimlet_setState(Actor *this, s32 next_state){
    ActorLocal_RBB_1FC0 *local = (ActorLocal_RBB_1FC0 *)&this->local;
    
    local->unk5 = 0;
    if(next_state == CH_GRIMLET_STATE_2_UNK){
        FUNC_8030E624(SFX_66_BIRD_AUUGHH, 0.6f, 32675);
        skeletalAnim_set(this->unk148, ASSET_137_ANIM_GRIMLET_ATTACK, 0.0f, 0.8f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    }
    this->state = next_state;
}

void RBB_func_80388430(ActorMarker * marker, ActorMarker *other_marker){
    Actor * actor = marker_getActor(marker);
    ActorLocal_RBB_1FC0 *local = (ActorLocal_RBB_1FC0 *) &actor->local;
    func_8030E6D4(SFX_111_WHIPCRACK_DEATH);
    local->unk5 = 1;
}

Actor *chGrimlet_draw(ActorMarker * marker, Gfx **gdl, Mtx **mptr, Vtx **vtx){
    Actor *actor = marker_getActor(marker);
    ActorLocal_RBB_1FC0 *local = (ActorLocal_RBB_1FC0 *) &actor->local;
    BoneTransformList *sp5C;
    f32 pad58;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    
    if(actor->state == CH_GRIMLET_STATE_0_NOT_INIT){
        return actor;
    }

    if(local->unk4){
        sp5C = skeletalAnim_getBoneTransformList(actor->unk148);
        sp40[0] = 0.0f;
        sp40[1] = local->unk0;
        sp40[2] = 0.0f;
        func_80345C78(&sp4C, &sp40);
        func_8033A8F0(sp5C, 1, &sp4C);

        sp34[0] = 0.0f;
        sp34[1] = 0.0f;
        sp34[2] = (local->unkC*0.5)/200.0;
        ml_vec3f_yaw_rotate_copy(sp34, sp34, local->unk0);
        func_8033A968(sp5C, 1, sp34);

        sp34[0] = 0.0f;
        sp34[1] = 0.0f;
        sp34[2] = local->unkC/200.0f;
        func_8033A968(sp5C, 0x12, sp34);
        skeletalAnim_func_80335918(actor->unk148);
    }
    modelRender_setAppendageVisibility(3, (0.0f < local->unk8)? 1 : 0);
    modelRender_setAppendageVisibility(4, (0.0f < local->unk8)? 1 : 0);
    actor_draw(marker, gdl, mptr, vtx);
    local->unk4 = actor->marker->unk14_21;
    return actor;
}

void chGrimlet_update(Actor *this){
    f32 plyr_pos[3];
    f32 horizontal_distance;
    f32 distance_in_front;
    f32 side_angle_radian;
    ActorLocal_RBB_1FC0 *local = (ActorLocal_RBB_1FC0 *)&this->local;
    f32 time_delta = time_getDelta();
    f32 prev_anim_progress;
    f32 curr_anim_progress;
    f32 tmp_f2;

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = 1;
        marker_setCollisionScripts(this->marker, RBB_func_80388430, NULL, NULL);
        local->unk4 = 0;
        local->unk0 = 0.0f;
        local->unk8 = 0.0f;
        local->unkC = 0.0f;
        local->unk10 = 0.0f;
        local->unk14 = 0.0f;
        chGrimlet_setState(this, CH_GRIMLET_STATE_1_UNK);
    }
    player_getPosition(plyr_pos);
    func_80258A4C(
        this->position, this->yaw + -90.0f, plyr_pos,
        &horizontal_distance, &distance_in_front, &side_angle_radian);
    if(horizontal_distance < 600.0f)
        local->unk8 = 1.0f;
    else{
        local->unk8 -=  time_delta;
        local->unk8 = MAX(0.0f, local->unk8);
    }

    if( 500.0f <= local->unk10
        && horizontal_distance < 500.0f
        && (side_angle_radian < -0.2 || 0.2 < side_angle_radian)
    ){
        FUNC_8030E624(SFX_C4_TWINKLY_MUNCHER_GRR, 0.8f, 32675);
    }

    local->unk10 = horizontal_distance;
    local->unk14 = local->unk14 + time_delta;

    if( horizontal_distance < 600.0f 
        && -1.0f < side_angle_radian
        && side_angle_radian < 1.0f
        && plyr_pos[1] < this->position_y + this->scale*200.0f
    ){
        func_80258A4C(
            this->position, (this->yaw + -90.0f) + local->unk0, plyr_pos,
            &horizontal_distance, &distance_in_front, &side_angle_radian);
        local->unk0 += (side_angle_radian * 200.0f) * time_delta;
        if(1.0f < local->unk14 && (side_angle_radian < -0.1 || 0.1 < side_angle_radian)){
                gcsfx_playWithPitch(SFX_D0_GRIMLET_SQUEAK, mlAbsF(side_angle_radian) * 0.1 + 0.9, 0x4e20);
                local->unk14 = 0.0f;
        }
    }
    else{//L80388964
        if(0.0f < local->unk0){
            local->unk0 -=  30.0f * time_delta;
            local->unk0 = MAX(0.0f, local->unk0);
        }//L803889B4
        else{
            if(local->unk0 < 0.0f){
                local->unk0 +=  30.0f * time_delta;
                local->unk0 = MIN(0.0f, local->unk0);
            }
        }
    }//L803889F8

    if(this->state == CH_GRIMLET_STATE_1_UNK){
        if( horizontal_distance < 400.0f
            && -0.8 <= side_angle_radian
            && side_angle_radian  <= 0.8
            && (plyr_pos[1] - this->position_y) < 100.0f
            && -100.0f < (plyr_pos[1] - this->position_y)
        ){
            chGrimlet_setState(this, CH_GRIMLET_STATE_2_UNK);
        }
    }//L80388AB8

    if(this->state == CH_GRIMLET_STATE_2_UNK){
        skeletalAnim_getProgressRange(this->unk148, &prev_anim_progress, &curr_anim_progress);
        if(0.6 <= curr_anim_progress)
            tmp_f2 = 1.0 - 2 * (curr_anim_progress - 0.6);
        else
            tmp_f2 = curr_anim_progress * 1.6666666666666667;
        //L80388B34
        local->unkC = tmp_f2 * horizontal_distance;
        
        if( prev_anim_progress < 0.55
            && 0.55 <= curr_anim_progress
            && !local->unk5
        ){
            sfx_playFadeShorthandDefault(SFX_20_METAL_CLANK_1, 1.0f, 32000, this->position, 500, 2500);
        }

        if(skeletalAnim_getLoopCount(this->unk148) > 0)
            chGrimlet_setState(this, CH_GRIMLET_STATE_1_UNK);
    }//L80388BB0
}
