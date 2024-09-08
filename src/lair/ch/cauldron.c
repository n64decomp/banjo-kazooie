#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028F4B8(f32[3], f32, f32);
extern void func_8028F66C(s32);
extern void func_802D6310(f32, enum map_e, s32, s32, enum file_progress_e);
extern void func_802EE354(Actor *, s32, s32, s32, f32, f32, f32, s32[4], s32, s32);
extern void func_80324CFC(f32, enum comusic_e, s32);
extern void func_8034DF30(s32, f32[4], f32[4], f32);

/* .h */
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 pad4[0x2];
    s16 unk6;
}Struct_lair_42A0_0;

void chWarpCauldron_update(Actor *this);
Actor *chWarpCauldron_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorAnimationInfo D_80393520[] = {
    {    0, 0.0f},
    {0x213, 2.66f},
    {0x212, 2.0f},
    {0x214, 6.4f},
    {0x215, 3.4f},
    {0x216, 1.0f},
    {0x28F, 5.167f},
    {0x290, 6.26f}
};
ActorInfo D_80393560 = { MARKER_231_WARP_CAULDRON, ACTOR_23B_WARP_CAULDRON, ASSET_4DF_MODEL_WARP_CAULDRON, 1, D_80393520, chWarpCauldron_update, func_80326224, chWarpCauldron_draw, 0, 0, 3.0f, 0};
ActorInfo D_80393584 = { MARKER_244_DINGPOT, ACTOR_2DB_DINGPOT, ASSET_450_MODEL_DINGPOT, 1, D_80393520, chWarpCauldron_update, func_80326224, chWarpCauldron_draw, 0, 0, 3.0f, 0};
f32 D_803935A8[][2][3] = {
    {{1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 1.0f}}, 
    {{1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}}, 
    {{1.0f, 1.0f, 1.0f}, {1.0f, 0.4f, 0.0f}}, 
    {{1.0f, 1.0f, 1.0f}, {0.3f, 0.6f, 1.0f}}, 
    {{1.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 0.0f}}
};

Struct_lair_42A0_0 D_80393620[] = {
    {MAP_6A_GL_TTC_AND_CC_PUZZLE, 0x5A, 0x8, 0x72, 0x62, 0x6A, 0x240},
    {MAP_6F_GL_FP_LOBBY,          0x5B, 0x8, 0x73, 0x63, 0x6B, 0x240},
    {MAP_6F_GL_FP_LOBBY,          0x5C, 0x9, 0x74, 0x64, 0x6C, 0x241},
    {MAP_77_GL_RBB_LOBBY,         0x5D, 0x8, 0x75, 0x65, 0x6D, 0x240},
    {MAP_6C_GL_RED_CAULDRON_ROOM, 0x5E, 0x8, 0x76, 0x66, 0x6E, 0x240},
    {MAP_79_GL_CCW_LOBBY,         0x5F, 0x8, 0x77, 0x67, 0x6F, 0x240},
    {MAP_93_GL_DINGPOT,           0x60, 0x0, 0x78, 0x68, 0x70, 0x240},
    {0,                           0x61, 0x0, 0x79, 0x69, 0x71, 0x240},
    {MAP_8E_GL_FURNACE_FUN,       0x8A, 0x8, 0x90, 0x8C, 0x8E, 0x240},
    {MAP_93_GL_DINGPOT,           0x8B, 0x8, 0x91, 0x8D, 0x8F, 0x241}
};

f32 D_80393670[] = {0.083f, 0.202f, 0.285f, 0.371f, 0.417f, -1.0f};
f32 D_80393688[] = {0.571f, 0.608f, 0.645f, 0.685f, 0.716f, 0.75f, 0.791f, -1.0f};
f32 D_803936A8[] = {0.293f, 0.376f, 0.42f, 0.453f, 0.488f, 0.522f, 0.556f, 0.59f, 0.626f, 0.661f, 0.693f, 0.729f, 0.764f, 0.863f, -1.0f}; 
f32 D_803936E4[] = {0.03f, 0.09f, 0.2f, 0.25f, 0.32f, 0.4f, 0.45f, 1.0f};

/* .code */
bool func_8038A690(Actor *this) {
    if (this->unkF4_8 != 3) {
        return subaddie_playerIsWithinCylinder(this, 400, 90);
    }
    else{
        return subaddie_playerIsWithinAsymmetricCylinder(this, 500, 260, 90);
    }
}

enum file_progress_e chWarpCauldron_getFileProgressFlagIndex(Actor *this){
    return this->unkF4_8 -1 + 0x49;
}

enum file_progress_e chWarpCauldron_getPairedFileProgressFlagIndex(Actor *this){
    return ((this->unkF4_8 - 1) ^ 1) + 0x49;
}

void func_8038A704(Actor *this){
    subaddie_set_state_with_direction(this, 3, 0.99f, 1);
}

void func_8038A730(Actor *this, f32 *arg1, enum sfx_e arg2, enum sfx_e arg3, u32 arg4) {
    s32 i;

    for(i = 0; arg1[i] != -1.0f; i++){
        if (actor_animationIsAt(this, arg1[i])) {
            if (arg3 != SFX_0_BLOOP) {
                func_8030E878((randf() < 0.5) ? arg2 : arg3, randf2(1.0f, 1.1f), arg4, this->position, 0.0f, 1200.0f);
            }
            else{
                func_8030E878(arg2, 1.0f, arg4, this->position, 0.0f, 1200.0f);
            }
            return;
        }
    }
}

void lair_func_8038A864(Actor *this) {
    switch (this->state) {
    case 2:
        func_8038A730(this, D_80393670, SFX_3F_CAULDRON_SQEAK_1, SFX_40_CAULDRON_SQEAK_2, 11000);
        break;
    case 3:
        func_8038A730(this, D_80393688, SFX_3F_CAULDRON_SQEAK_1, SFX_40_CAULDRON_SQEAK_2, 11000);
        break;
    case 5:
        if (actor_animationIsAt(this, 0.5f)) {
            FUNC_8030E624(SFX_C5_TWINKLY_POP, 0.8f, 32000);

        }
        if (actor_animationIsAt(this, 0.596f)) {
            FUNC_8030E624(SFX_2D_KABOING, 0.85f, 32000);
        }
        break;
    case 4:
        func_8038A730(this, D_803936A8, SFX_3F_CAULDRON_SQEAK_1, SFX_40_CAULDRON_SQEAK_2, 11000);
        break;
    }
}

void func_8038A96C(Actor *this, s32 arg1) {
    s32 sp5C;
    s32 i;
    f32 sp48[4];
    f32 sp38[4];

    if( ( (arg1 != 3) || ( (this->unk1C[1] == 0.0f) && (this->marker->unk14_21 == 1))) 
        && (this->modelCacheIndex == ACTOR_23B_WARP_CAULDRON) 
        && ((arg1 != 0) || fileProgressFlag_get(chWarpCauldron_getFileProgressFlagIndex(this))) 
    ){
        sp5C = func_8034C2C4(this->marker, 0x1C3);
        if(sp5C != 0){
            for(i = 0; i < 3; i++){
                sp48[i] = D_803935A8[(((s32)this->unkF4_8 - 1)>>1)][0][i];
                sp38[i] = D_803935A8[(((s32)this->unkF4_8 - 1)>>1)][1][i];

            }
            sp48[3] = 1.0f;
            sp38[3] = 1.0f;
            if (arg1 == 2) {
                func_8034DF30(sp5C, sp38, sp38, 0.3f);
            }
            else{
                func_8034DF30(sp5C, sp48, sp38, fileProgressFlag_get(chWarpCauldron_getFileProgressFlagIndex(this)) ? 0.3 : 3.0);
            }
        }
    }
}

void func_8038AB90(Actor *this, s32 arg1, s32 arg2, enum sfx_e sfx_id, f32 sfx_timing) {
    if (arg2 == this->unk10_12) {
        if (this->unkF4_8 == 7) {
            func_80324CFC(0.5f, COMUSIC_8C_JINJONATOR_POWERUP, 32000);
            func_80324D2C(7.0f, COMUSIC_8C_JINJONATOR_POWERUP);
        }
        this->unk10_12 = 0;
        subaddie_set_state_forward(this, arg1);
        actor_playAnimationOnce(this);
        func_8028FCBC();
        if (sfx_id != SFX_0_BLOOP) {
            timed_playSfx(sfx_timing, sfx_id, 1.0f, 32000);
            if (arg2 == 2) {
                func_8025A6CC(COMUSIC_3F_MAGIC_CARPET_RISING, 32000);
                func_80324D2C(2.6f, COMUSIC_3F_MAGIC_CARPET_RISING);
                func_8030E540(SFX_7C_CHEBOOF);
            }
        }
    }
}
void func_8038AC7C(Actor *this) {
    s32 sp2C;
    u32 sp28;

    if(
        (func_803114C4() != 0xFAD) 
        && func_80329530(this, 1200)
        && !fileProgressFlag_get(FILEPROG_FC_DEFEAT_GRUNTY)
    ) {
        this->unk60 += time_getDelta();
        if (35.0 < this->unk60) {
            sp2C = (fileProgressFlag_get(FILEPROG_CF_HAS_ENTERED_FINAL_FIGHT)) ? 0xFB7 : 0xFAE;
            sp28 = (fileProgressFlag_get(FILEPROG_CF_HAS_ENTERED_FINAL_FIGHT)) ? 0xFBC : 0xFB7;
            if (func_80311480(sp2C + this->unk38_31, 0, NULL, NULL, NULL, NULL)) {
                this->unk38_31++;
                this->unk60 = 0.0f;
                if (sp2C + this->unk38_31 >= sp28) {
                    this->unk38_31 = 0;
                }
            }
        }
    }
}


void __chWarpCauldron_dingpotDialogCallback(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    fileProgressFlag_set(FILEPROG_F3_MET_DINGPOT, TRUE);
}

bool lair_func_8038ADF0(s32 arg0, s32 arg1) {
    s32 phi_v1;

    phi_v1 = arg1 - arg0;
    while (phi_v1 < 0)    { phi_v1 += 360; }
    while (phi_v1 >= 360) { phi_v1 -= 360;}
    return phi_v1 < 70;
}

void chWarpCauldron_update(Actor *this) {
    f32 sp54[3];
    s32 sp50;
    s32 sp4C;
    s32 phi_v0;
    enum sfx_e phi_a0;
    f32 temp_f0;
    s32 sp3C;
    s32 sp38;
    f32 sp34;
    
    lair_func_8038A864(this);
    if (!this->unk16C_4) {
        sp50 = FALSE;
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk1C[1] = 0.0f;
        this->velocity[0] = this->yaw;
        if (this->modelCacheIndex == ACTOR_2DB_DINGPOT) {
            if (fileProgressFlag_get(FILEPROG_F3_MET_DINGPOT)) {
                sp4C = (fileProgressFlag_get(FILEPROG_CF_HAS_ENTERED_FINAL_FIGHT)) ? 0xFB7 : 0xFAE;
                phi_v0 = (fileProgressFlag_get(FILEPROG_CF_HAS_ENTERED_FINAL_FIGHT)) ? 0xFBC : 0xFB7;
                this->unk60 = 35.0f;
                this->unk38_31 = randi2(0, phi_v0 - sp4C);
            }
            this->scale = 1.8f;
            subaddie_set_state_with_direction(this, 6, 0.99f, 1);
            func_802D09B8(this, 2);
        }
        if (fileProgressFlag_get(chWarpCauldron_getFileProgressFlagIndex(this))) {
            func_8038A704(this);
            func_802D09B8(this, 2);
            func_8038A96C(this, 2);
            sp50 = TRUE;
            if( ( func_802D677C(-1) != 0 
                  && (func_802D677C(-1) == D_80393620[this->unkF4_8 - 1].unk0) 
                  && (func_802D67AC(-1) == MAP_16_GV_RUBEES_CHAMBER) 
                  && (func_802D680C(-1) == this->unkF4_8)
                ) 
                || (exit_get() == D_80393620[this->unkF4_8 - 1].unk2)
            ) {
                func_8028F85C(this->position);
                this->unk10_12 = 1;
                func_8038AB90(this, 5, 1, 0, 0.0f);
            }
            if (!fileProgressFlag_get(FILEPROG_F5_COMPLETED_A_WARP_CAULDRON_SET) && fileProgressFlag_get(chWarpCauldron_getPairedFileProgressFlagIndex(this))) {
                if (func_802D677C(-1) != map_get()) {
                    func_80311480(0xF7A, 4, NULL, NULL, NULL, NULL);
                    fileProgressFlag_set(FILEPROG_F5_COMPLETED_A_WARP_CAULDRON_SET, 1);
                }
            }
        }
        if (sp50 == 0) {
            this->unk10_12 = 0;
            func_8038A96C(this, 0);
        }
    }
    switch(this->state){
        case 1: //L8038B0F4
            if (func_8038A690(this)) {
                func_8028F918(2);
                subaddie_set_state_forward(this, 2);
                this->unk38_0 = FALSE;
                func_8038A96C(this, 1);
                func_802BAFE4(D_80393620[this->unkF4_8 - 1].unk3);
                func_802D09B8(this, 2);
                phi_a0 = (fileProgressFlag_get(chWarpCauldron_getPairedFileProgressFlagIndex(this)) != 0) ? SFX_107_CAULDRON_ACTIVATION_1 : SFX_108_CAULDRON_ACTIVATION_2;
                sfxsource_play(phi_a0, 32000);
                if (!fileProgressFlag_get(FILEPROG_F5_COMPLETED_A_WARP_CAULDRON_SET) && !fileProgressFlag_get(chWarpCauldron_getPairedFileProgressFlagIndex(this))) {
                    func_80311480(0xF79, 4, NULL, NULL, NULL, NULL);
                }
                if (fileProgressFlag_get(chWarpCauldron_getPairedFileProgressFlagIndex(this))){
                    switch(this->unkF4_8){
                        case 2://L8038B204
                            func_802D6310(2.0f, MAP_6A_GL_TTC_AND_CC_PUZZLE, 0x62, 0x22, 0);
                            break;

                        case 1://L8038B228 
                            func_802D6310(2.0f, MAP_6F_GL_FP_LOBBY, 0x63, 0x23, 0);
                            break;

                        case 4://L8038B24C
                            func_802D6310(2.0f, MAP_6F_GL_FP_LOBBY, 0x64, 0x24, 0);
                            break;

                        case 3://L8038B270
                            func_802D6310(2.0f, MAP_77_GL_RBB_LOBBY, 0x65, 0x25, 0);
                            break;

                        case 6://L8038B294
                            func_802D6310(2.0f, MAP_6C_GL_RED_CAULDRON_ROOM, 0x66, 0x26, 0);
                            break;

                        case 5://L8038B2B8
                            func_802D6310(2.0f, MAP_79_GL_CCW_LOBBY, 0x67, 0x27, 0);
                            break;

                        case 10://L8038B2DC
                            func_802D6310(2.0f, MAP_8E_GL_FURNACE_FUN, 0x8C, 0x29, 0);
                            break;

                        case 9://L8038B300
                            func_802D6310(2.0f, MAP_93_GL_DINGPOT, 0x8D, 0x2A, 0);
                            break;
                    }
                }
            }
            break;

        case 2: //L8038B324
            temp_f0 = animctrl_getAnimTimer(this->animctrl);
            for(sp3C = 0; D_803936E4[sp3C] < temp_f0; sp3C++)
                ;
            
            this->unk38_0 = (sp3C & 1) ? TRUE : FALSE;
            if (actor_animationIsAt(this, 0.95f)) {
                func_8038A704(this);
                fileProgressFlag_set(chWarpCauldron_getFileProgressFlagIndex(this), 1);
                func_8028F918(0);
                this->unk1C[2] = 4.0f;
            }
            break;

        case 3: //L8038B3DC
            this->unk38_0 = TRUE;
            if (this->unk1C[2] != 0.0f) {
                this->unk1C[2] = this->unk1C[2] - 1.0f;
            } else {
                func_8038AB90(this, 5, 1, 0, 0.0f);
                func_8038AB90(this, 4, 2, SFX_A6_MAGICAL_FINISH, 2.6f);
            }
            func_8038A96C(this, 3);
            break;

        case 7: //L8038B460
            this->unk38_0 = TRUE;
            if (actor_animationIsAt(this, 0.62f)) {
                func_8030E6D4(SFX_1B_EXPLOSION_1);
            }
        case 5: //L8038B48C
            func_8038A96C(this, 3);
            if (actor_animationIsAt(this, 0.01f)) {
                func_8030E540(SFX_7C_CHEBOOF);
            }
            if (actor_animationIsAt(this, 0.63f)) {
                volatileFlag_set(0x1E, 0);
                func_802D677C(0);
                func_8028FCAC();
                nodeprop_getPosition(func_80304C38(D_80393620[this->unkF4_8 - 1].unk6, this), sp54);
                if (this->unkF4_8 == 7) {
                    func_8028F66C(BS_INTR_36_DINGPOT);
                    func_802BAFE4(0x82);
                } else {
                    func_8028F4B8(sp54, 1620.0f, -4100.0f);
                }
            }
            if (actor_animationIsAt(this, 0.98f)) {
                func_8038A704(this);
                actor_loopAnimation(this);
            }
            break;

        case 4: //L8038B584
            func_8038A96C(this, 3);
            if (actor_animationIsAt(this, 0.99f)) {
                func_802D6344();
                func_802D677C(D_80393620[((this->unkF4_8 - 1) ^ 1)].unk0);
                func_802D67AC(0x16);
                func_802D680C(((this->unkF4_8 - 1) ^ 1) + 1);
                func_802D683C(D_80393620[((this->unkF4_8 - 1) ^ 1)].unk1);
                func_8031CC40(D_80393620[((this->unkF4_8 - 1) ^ 1)].unk0, D_80393620[((this->unkF4_8 - 1) ^ 1)].unk2);
            }
            break;

        case 6: //L8038B64C
            if (func_8038A690(this) && !fileProgressFlag_get(FILEPROG_F3_MET_DINGPOT)) {
                func_80311480(0xFAD, 0xA, this->position, NULL, __chWarpCauldron_dingpotDialogCallback, NULL);
            }
            this->unk38_0 = TRUE;

            sp3C = 0;
            if (fileProgressFlag_get(FILEPROG_FC_DEFEAT_GRUNTY)){
                if(jiggyscore_total() == 100){
                    sp3C = 1;
                }
            }
            else{ 
                sp3C = 1;
            }
            if (sp3C != 0) {
                func_8038AB90(this, 7, 1, 0, 0.0f);
            }
            func_8038AC7C(this);
            sp38 = func_80329784(this);
            if( lair_func_8038ADF0(sp38, (s32) this->velocity[0]) 
                || lair_func_8038ADF0((s32) this->velocity[0], sp38)
            ) {
                this->yaw_ideal = (f32) sp38;
            }
            func_80328FB0(this, 3.0f);
            if( actor_animationIsAt(this, 0.114f)
                || actor_animationIsAt(this, 0.217f)
                || actor_animationIsAt(this, 0.321f)
            ) {
                sp34 = randf2(0.85f, 0.95f);
                func_8030E878(SFX_20_METAL_CLANK_1, sp34, 16000, this->position, 100.0f, 1750.0f);
            }
            if( actor_animationIsAt(this, 0.49f)
                || actor_animationIsAt(this, 0.68f)
            ) {
                sp34 = randf2(0.65f, 0.75f);
                func_8030E878(SFX_F9_GRUNTLING_NOISE_1, sp34, 16000, this->position, 100.0f, 1750.0f);
            }
            break;

    }//L8038B854
    
    this->unk1C[1] = (f32)this->marker->unk14_21;
}

Actor *chWarpCauldron_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;
    s32 sp3C[4];

    this = marker_getActor(marker);
    if(this->modelCacheIndex == ACTOR_23B_WARP_CAULDRON) {
        func_8033A45C(3, this->unk38_0 ? TRUE : FALSE);
        func_8033A45C(4, this->unk38_0 ? FALSE : TRUE);
    }
    this = actor_draw(marker, gfx, mtx, vtx);
    if (marker->unk14_21 && this->unk38_0 && (getGameMode() != GAME_MODE_4_PAUSED)) {
        sp3C[1] = randi2(200, 255);
        sp3C[0] = randi2(150, sp3C[1]);
        sp3C[2] = 0;
        sp3C[3] = randi2(40, 80);
        if (globalTimer_getTime() & 1) {
            func_802EE354(this, 0x3E9, 5, randi2(-10, 90), randf2(0.3f, 0.7f), 0.28f, 0.45f, sp3C, 5, 0);
        }
    }
    return this;
}
