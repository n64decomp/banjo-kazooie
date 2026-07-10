#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct {
    s32 unk0;
    u8 sfxsourceIdx;
    //u8 pad5[3];
    u8 *unk8;
    f32 unkC;
    u8 unk10;
    //u8 pad11[3];
    ActorMarker *unk14;
    f32 unk18[3];
    f32 unk24;
}ActorLocal_GV_6370;

void chJinxyHeadSandybutt_setState(Actor *this, s32 next_state);
void chJinxyHeadSandybutt_update(Actor *this);
Actor *chJinxyHeadSandybutt_draw(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
u8 chJinxyHeadSandybuttIndices[3] =  {0, 1, 2};

// Jinxy Head 2
ActorInfo chJinxyHeadSandybutt1 = {
    MARKER_BB_JINXY_HEAD_SANDYBUTT, ACTOR_285_JINXY_HEAD_SANDYBUTT_1, ASSET_3E6_JINXY_HEAD_KING_SANDYBUTT, 
    0, NULL,
    chJinxyHeadSandybutt_update, actor_update_func_80326224, chJinxyHeadSandybutt_draw,
    0, 0, 0.0f, 0
};

ActorInfo chJinxyHeadSandybutt2 = {
    MARKER_BB_JINXY_HEAD_SANDYBUTT, ACTOR_286_JINXY_HEAD_SANDYBUTT_2, ASSET_3E6_JINXY_HEAD_KING_SANDYBUTT, 
    0, NULL,
    chJinxyHeadSandybutt_update, actor_update_func_80326224, chJinxyHeadSandybutt_draw,
    0, 0, 0.0f, 0
};

ActorInfo chJinxyHeadSandybutt3 = {
    MARKER_BB_JINXY_HEAD_SANDYBUTT, ACTOR_287_JINXY_HEAD_SANDYBUTT_3, ASSET_3E6_JINXY_HEAD_KING_SANDYBUTT, 
    0, NULL,
    chJinxyHeadSandybutt_update, actor_update_func_80326224, chJinxyHeadSandybutt_draw,
    0, 0, 0.0f, 0
};

enum chjinxyheadsandybutt_state_e {
    CHJINXYHEADSANDYBUTT_STATE_0_NOT_INIT,
    CHJINXYHEADSANDYBUTT_STATE_1_UNK,
    CHJINXYHEADSANDYBUTT_STATE_2_UNK,
    CHJINXYHEADSANDYBUTT_STATE_3_UNK,
    CHJINXYHEADSANDYBUTT_STATE_4_UNK,
    CHJINXYHEADSANDYBUTT_STATE_5_UNK,
    CHJINXYHEADSANDYBUTT_STATE_6_FED,
    CHJINXYHEADSANDYBUTT_STATE_7_GO_AWAY,
    CHJINXYHEADSANDYBUTT_STATE_8_COMPLETED
};

/* .code */
void chJinxyHeadSandybutt_raisePyramid(Actor *this, s32 arg1){
    ActorLocal_GV_6370 *local = (ActorLocal_GV_6370 *)&this->local;
    chBuriedPyramid_setRaisedAmount(local->unk14, arg1);
    FUNC_8030E624(SFX_3F6_RUBBING, 0.7f, 28000);
    FUNC_8030E624(SFX_3F6_RUBBING, 0.9f, 29000);
    FUNC_8030E624(SFX_3F6_RUBBING, 1.0f, 30000);
    timed_setStaticCameraToNode(0.0f, 8);
    if(arg1 < 3){
        timed_setStaticCameraToNode(3.5f, arg1 + 0x15);
        timedFunc_set_3(3.5f, (GenFunction_3)fileProgressFlag_setN, FILEPROG_F8_KING_SANDYBUTT_PYRAMID_STATE, arg1, 2);
        timed_exitStaticCamera(6.5f);
        func_80324E38(6.5f, 0);
    }
    else{
        timedFunc_set_2(3.5f, (GenFunction_2)coMusicPlayer_playMusic, COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x7fff);
        timedFunc_set_3(3.5f, (GenFunction_3)fileProgressFlag_setN, FILEPROG_F8_KING_SANDYBUTT_PYRAMID_STATE, arg1, 2);
        timed_exitStaticCamera(6.0f);
        func_80324E38(6.0f, 0);
    }
}

void chJinxyHeadSandybutt_free(Actor *this){
    chJinxyHeadSandybutt_setState(this, CHJINXYHEADSANDYBUTT_STATE_0_NOT_INIT);
}

void chJinxyHeadSandybutt_setState(Actor *this, s32 next_state){
    ActorLocal_GV_6370 *local = (ActorLocal_GV_6370 *)&this->local;
    
    local->unk0 = 0;
    local->unk24 = 0.0f;
    this->marker->propPtr->unk8_3 = (next_state == CHJINXYHEADSANDYBUTT_STATE_1_UNK) ? FALSE : TRUE;
    this->marker->collidable = (next_state == CHJINXYHEADSANDYBUTT_STATE_1_UNK) ? FALSE : TRUE;
    if(this->state == CHJINXYHEADSANDYBUTT_STATE_4_UNK
       || this->state == CHJINXYHEADSANDYBUTT_STATE_5_UNK)
    {
        sfxsource_freeSfxsourceByIndex(local->sfxsourceIdx);
    }
    
    if(next_state == CHJINXYHEADSANDYBUTT_STATE_4_UNK
       || next_state == CHJINXYHEADSANDYBUTT_STATE_5_UNK)
    {
        local->sfxsourceIdx = sfxsource_createSfxsourceAndReturnIndex();
        sfxsource_setSfxId(local->sfxsourceIdx, SFX_3EC_CCW_DOOR_OPENING);
        sfxSource_setunk43_7ByIndex(local->sfxsourceIdx, 3);
        sfxsource_playSfxAtVolume(local->sfxsourceIdx, 0.8f);
        sfxsource_setSampleRate(local->sfxsourceIdx, 0);
        sfxSource_func_8030E2C4(local->sfxsourceIdx);
    }//L8038C9B8

    if(next_state == CHJINXYHEADSANDYBUTT_STATE_2_UNK){
        skeletalAnim_set(this->unk148, ASSET_F0_ANIM_MINI_SHPYNX_EATING, 1.0f, 3.0f);
        skeletalAnim_setProgress(this->unk148, 0.27f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_4_STOPPED);
        local->unkC = 0.0f;
        local->unk18[0] = this->position_x;
        local->unk18[1] = this->position_y;
        local->unk18[2] = this->position_z;
        if(this->state == 1){
            baMotor_80250E94(0.0f, 0.6f, 1.0f, 0, 1.3f, 0.0f);
            timed_playSfx(1.0f, SFX_3F6_RUBBING, 0.8f, 30000);
        }
    }//L8038CA6C

    if(next_state == CHJINXYHEADSANDYBUTT_STATE_3_UNK){
        local->unk24 = 3.0f;
        skeletalAnim_set(this->unk148, ASSET_F0_ANIM_MINI_SHPYNX_EATING, 1.0f, 3.0f);
        skeletalAnim_setProgress(this->unk148, 0.27f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_4_STOPPED);
    }//L8038CAB4

    if(this->state == CHJINXYHEADSANDYBUTT_STATE_3_UNK){
        skeletalAnim_set(this->unk148, ASSET_F0_ANIM_MINI_SHPYNX_EATING, 0.5f, 3.0f);
        skeletalAnim_setProgress(this->unk148, 0.99f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        if(next_state == CHJINXYHEADSANDYBUTT_STATE_4_UNK
           || next_state == CHJINXYHEADSANDYBUTT_STATE_5_UNK)
        {
            sfx_playFadeShorthandDefault(SFX_DE_WOOD_SQUEAK, 1.0f, 32675, this->position, 500, 1500);
        }
    }//L8038CB20

    if(next_state == CHJINXYHEADSANDYBUTT_STATE_6_FED){
        func_80324E38(0.0f, 3);
        skeletalAnim_set(this->unk148, ASSET_F0_ANIM_MINI_SHPYNX_EATING, 0.0f, 3.0f);
        coMusicPlayer_playMusic(COMUSIC_2B_DING_B, 28000);
    }

    if(next_state == CHJINXYHEADSANDYBUTT_STATE_7_GO_AWAY){
        local->unkC = 0.0f;
        local->unk18[0] = this->position_x;
        local->unk18[1] = this->position_y;
        local->unk18[2] = this->position_z;
        baMotor_80250D94(0.7f, 0.5f, 1.3f);
        FUNC_8030E624(SFX_3F6_RUBBING, 0.8f, 30000);
    }

    if(next_state == CHJINXYHEADSANDYBUTT_STATE_8_COMPLETED){
        if(this->state == CHJINXYHEADSANDYBUTT_STATE_7_GO_AWAY){
            baMotor_80250D94(0.8f, 0.7f, 3.0f);
            chJinxyHeadSandybutt_raisePyramid(this, *local->unk8 + 1);
        }
        marker_despawn(this->marker);
    }
    this->state = next_state;
}

Actor *chJinxyHeadSandybutt_draw(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(this_marker);
    if(this->state == CHJINXYHEADSANDYBUTT_STATE_1_UNK) return this;
    return actor_draw(this_marker, gfx, mtx, vtx);
}

void chJinxyHeadSandybutt_update(Actor *this){
    ActorLocal_GV_6370 *local = (ActorLocal_GV_6370 *)&this->local;
    f32 time_delta = time_getDelta();
    s32 pyramid_file_progress;
    f32 pad70;
    f32 sp6C[3];
    f32 f12;
    f32 sp5C[3];
    f32 sp58;
    f32 sp54;
    f32 sp48[3];

    if(!this->volatile_initialized){
        pyramid_file_progress = fileProgressFlag_getN(FILEPROG_F8_KING_SANDYBUTT_PYRAMID_STATE, 2);
        this->volatile_initialized = TRUE;
        this->marker->actorFreeFunc = chJinxyHeadSandybutt_free;
        local->unk8 = &chJinxyHeadSandybuttIndices[this->modelCacheIndex - 0x285];
        local->unk10 = 0;
        local->unk14 = 0;
        local->unkC = 0.0f;
        local->unk18[0] = this->position_x;
        local->unk18[1] = this->position_y;
        local->unk18[2] = this->position_z;
        if(*local->unk8 < pyramid_file_progress){
            chJinxyHeadSandybutt_setState(this, CHJINXYHEADSANDYBUTT_STATE_8_COMPLETED);
        }
        else if(pyramid_file_progress == *local->unk8){
            chJinxyHeadSandybutt_setState(this, CHJINXYHEADSANDYBUTT_STATE_2_UNK);
        }
        else{
            chJinxyHeadSandybutt_setState(this, CHJINXYHEADSANDYBUTT_STATE_1_UNK);
        }
        return;
    }

    if(!local->unk14){
        local->unk14 = actorArray_findActorFromActorId(ACTOR_31D_SANDYBUTT_PYRAMID)->marker;
    }

    if(this->state == CHJINXYHEADSANDYBUTT_STATE_1_UNK){
        if(fileProgressFlag_getN(FILEPROG_F8_KING_SANDYBUTT_PYRAMID_STATE, 2) == *local->unk8){
            chJinxyHeadSandybutt_setState(this, CHJINXYHEADSANDYBUTT_STATE_2_UNK);
        }
    }

    if(this->state == CHJINXYHEADSANDYBUTT_STATE_2_UNK){
        local->unkC += 0.5 * time_delta;
        if(1.0f <= local->unkC){
            local->unkC = 1.0f;
            chJinxyHeadSandybutt_setState(this, CHJINXYHEADSANDYBUTT_STATE_3_UNK);
        }
        sp6C[0] = 0.0f;
        sp6C[1] = 0.0f;
        sp6C[2] = (1.0f - local->unkC) * -600.0f;
        ml_vec3f_yaw_rotate_copy(sp6C, sp6C, this->yaw);
        this->position_x = local->unk18[0] +  sp6C[0];
        this->position_y = local->unk18[1] +  sp6C[1];
        this->position_z = local->unk18[2] +  sp6C[2];
    }//L8038CECC

    if(this->state == CHJINXYHEADSANDYBUTT_STATE_3_UNK){
        if(0.0f < local->unk24){
            local->unk24 -= time_delta;
        }
        else{
            if(func_8038D388())
                chJinxyHeadSandybutt_setState(this, CHJINXYHEADSANDYBUTT_STATE_5_UNK);
        }
    }//L8038CF1C

    if(this->state == CHJINXYHEADSANDYBUTT_STATE_4_UNK
       || this->state == CHJINXYHEADSANDYBUTT_STATE_5_UNK)
    {
        local->unkC += ((this->state == 4)? -1 : 1) * time_delta;
        if(1.0f < local->unkC){
            local->unkC = 1.0f;
            chJinxyHeadSandybutt_setState(this, CHJINXYHEADSANDYBUTT_STATE_4_UNK);
            return;
        }
        else if(local->unkC < -1.0f){
            local->unkC = -1.0f;
            chJinxyHeadSandybutt_setState(this, CHJINXYHEADSANDYBUTT_STATE_5_UNK);
            return;
        }
        sp5C[0] = local->unkC*300.0f;
        sp5C[1] = 0.0f;
        sp5C[2] = 0.0f;
        ml_vec3f_yaw_rotate_copy(sp5C, sp5C, this->yaw);
        this->position_x = local->unk18[0] + sp5C[0];
        this->position_y = local->unk18[1] + sp5C[1];
        this->position_z = local->unk18[2] + sp5C[2];
        if(0.8 <= local->unkC){
            f12 = 1.0 - (local->unkC - 0.8) / 0.2;
        }
        else if(local->unkC <= -0.8){
            f12 = 1.0 - (-local->unkC - 0.8) / 0.2;
        }
        else{
            f12 = 1.0f;
        }
        func_8030DB04(local->sfxsourceIdx, f12 * 24000.0f, this->position, 200.0f, 1500.0f);
        if(!func_8038D388()){
            chJinxyHeadSandybutt_setState(this, CHJINXYHEADSANDYBUTT_STATE_3_UNK);
        }
    }//L8038D110

    if(this->state == CHJINXYHEADSANDYBUTT_STATE_6_FED){
        skeletalAnim_getProgressRange(this->unk148, &sp58, &sp54);
        if(sp58 < 0.28 && 0.28 <= sp54){
            FUNC_8030E624(SFX_4C_LIP_SMACK, 1.0f, 28000);
        }
        if(sp58 < 0.52 && 0.52 <= sp54){
            FUNC_8030E624(SFX_4C_LIP_SMACK, 0.9f, 28000);
        }
        if(sp58 < 0.7 && 0.7 <= sp54){
            FUNC_8030E624(SFX_4C_LIP_SMACK, 1.0f, 28000);
        }
        if(0.81 <= sp54){
            FUNC_8030E624(SFX_97_BLUBBER_BURPS, 1.0f, 28000);
            chJinxyHeadSandybutt_setState(this, CHJINXYHEADSANDYBUTT_STATE_7_GO_AWAY);
        }
    }//L8038D228

    if(this->state == CHJINXYHEADSANDYBUTT_STATE_7_GO_AWAY){
        local->unkC += 0.5 * time_delta;
        if(1.0f < local->unkC){
            chJinxyHeadSandybutt_setState(this, CHJINXYHEADSANDYBUTT_STATE_8_COMPLETED);
        }
        sp48[0] = 0.0f;
        sp48[1] = 0.0f;
        sp48[2] = local->unkC * -600.0f;
        ml_vec3f_yaw_rotate_copy(sp48, sp48, this->yaw);
        this->position_x = local->unk18[0] + sp48[0];
        this->position_y = local->unk18[1] + sp48[1];
        this->position_z = local->unk18[2] + sp48[2];
    }//L8038D2F0

    if(local->unk0){
        if(this->state == CHJINXYHEADSANDYBUTT_STATE_4_UNK
           || this->state == CHJINXYHEADSANDYBUTT_STATE_5_UNK)
        {
            local->unk0 = 0;
            local->unk10++;
            if(local->unk10 == 3){
                chJinxyHeadSandybutt_setState(this, CHJINXYHEADSANDYBUTT_STATE_6_FED);
            }
            else{
                coMusicPlayer_playMusic(COMUSIC_2B_DING_B, 28000);
            }
        }
    }
}
