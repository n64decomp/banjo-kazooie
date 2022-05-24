#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028F4B8(f32[3], f32, f32);
extern void func_8028F66C(s32);
extern void func_802D6310(f32, enum map_e, s32, s32, enum bkprog_e);
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

void func_8038AE2C(Actor *this);
Actor *func_8038B898(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorAnimationInfo D_80393520[];
extern ActorInfo D_80393560 = { 0x231, 0x23B, 0x4DF, 0x1, D_80393520, func_8038AE2C, func_80326224, func_8038B898, { 0x0, 0x0}, 0, 3.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80393584 = { 0x244, 0x2DB, 0x450, 0x1, D_80393520, func_8038AE2C, func_80326224, func_8038B898, { 0x0, 0x0}, 0, 3.0f, { 0x0, 0x0, 0x0, 0x0}};
extern f32 D_803935A8[][2][3];
extern Struct_lair_42A0_0 D_80393620[];
extern f32 D_80393670[];
extern f32 D_80393688[];
extern f32 D_803936A8[];
extern f32 D_803936E4[];

/* .code */
bool func_8038A690(Actor *this) {
    if (this->unkF4_8 != 3) {
        return func_803296B8(this, 0x190, 0x5A);
    }
    else{
        return func_80329628(this, 0x1F4, 0x104, 0x5A);
    }
}

enum bkprog_e func_8038A6DC(Actor *this){
    return this->unkF4_8 + 0x48;
}

enum bkprog_e func_8038A6EC(Actor *this){
    return ((this->unkF4_8 - 1) ^ 1) + 0x49;
}

void func_8038A704(Actor *this){
    func_80328B8C(this, 3, 0.99f, 1);
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

void func_8038A864(Actor *this) {
    switch (this->state) {
    case 2:
        func_8038A730(this, &D_80393670, SFX_3F_CAULDRON_SQEAK_1, SFX_40_CAULDRON_SQEAK_2, 11000);
        break;
    case 3:
        func_8038A730(this, &D_80393688, SFX_3F_CAULDRON_SQEAK_1, SFX_40_CAULDRON_SQEAK_2, 11000);
        break;
    case 5:
        if (actor_animationIsAt(this, 0.5f)) {
            func_8030E624(0x665F40C5U);
        }
        if (actor_animationIsAt(this, 0.596f)) {
            func_8030E624(0x6CBF402DU);
        }
        break;
    case 4:
        func_8038A730(this, &D_803936A8, SFX_3F_CAULDRON_SQEAK_1, SFX_40_CAULDRON_SQEAK_2, 11000);
        break;
    }
}

void func_8038A96C(Actor *this, s32 arg1) {
    s32 sp5C;
    s32 i;
    f32 sp48[4];
    f32 sp38[4];

    if( ( (arg1 != 3) || ( (this->unk1C[1] == 0.0f) && (this->marker->unk14_21 == 1))) 
        && (this->modelCacheIndex == 0x23B) 
        && ((arg1 != 0) || func_8031FF1C(func_8038A6DC(this))) 
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
                func_8034DF30(sp5C, &sp38, &sp38, 0.3f);
            }
            else{
                func_8034DF30(sp5C, &sp48, &sp38, func_8031FF1C(func_8038A6DC(this)) ? 0.3 : 3.0);
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
        func_80328AC8(this, arg1);
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
        && !func_8031FF1C(0xFC)
    ) {
        this->unk60 += time_getDelta();
        if (35.0 < this->unk60) {
            sp2C = (func_8031FF1C(0xCF)) ? 0xFB7 : 0xFAE;
            sp28 = (func_8031FF1C(0xCF)) ? 0xFBC : 0xFB7;
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


void func_8038ADC0(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    func_80320004(0xF3, TRUE);
}

bool func_8038ADF0(s32 arg0, s32 arg1) {
    s32 phi_v1;

    phi_v1 = arg1 - arg0;
    while (phi_v1 < 0)    { phi_v1 += 360; }
    while (phi_v1 >= 360) { phi_v1 -= 360;}
    return phi_v1 < 70;
}

#ifdef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_42A0/func_8038AE2C.s")
#else
void func_8038AE2C(Actor *this) {
    f32 sp54[3];
    s32 sp50;
    s32 sp4C;
    s32 phi_v0;
    enum sfx_e phi_a0;
    f32 temp_f0;
    s32 sp3C;
    s32 sp38;
    f32 sp34;
    
    func_8038A864(this);
    if (!this->unk16C_4) {
        sp50 = FALSE;
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk1C[1] = 0.0f;
        this->velocity[0] = this->yaw;
        if (this->modelCacheIndex == 0x2DB) {
            if (func_8031FF1C(0xF3)) {
                sp4C = (func_8031FF1C(0xCF)) ? 0xFB7 : 0xFAE;
                phi_v0 = (func_8031FF1C(0xCF)) ? 0xFBC : 0xFB7;
                this->unk60 = 35.0f;
                this->unk38_31 = randi2(0, phi_v0 - sp4C);
            }
            this->scale = 1.8f;
            func_80328B8C(this, 6, 0.99f, 1);
            func_802D09B8(this, 2);
        }
        if (func_8031FF1C(func_8038A6DC(this))) {
            func_8038A704(this);
            func_802D09B8(this, 2);
            func_8038A96C(this, 2);
            sp50 = TRUE;
            if( ( func_802D677C(-1) != 0 
                  && (func_802D677C(-1) == D_80393620[this->unkF4_8 - 1].unk0) 
                  && (func_802D67AC(-1) == MAP_16_GV_RUBEES_CHAMBER) 
                  && (func_802D680C(-1) == this->unkF4_8)
                ) 
                || (func_803348CC() == D_80393620[this->unkF4_8 - 1].unk2)
            ) {
                func_8028F85C(this->position);
                this->unk10_12 = 1;
                func_8038AB90(this, 5, 1, 0, 0.0f);
            }
            if (!func_8031FF1C(0xF5) && func_8031FF1C(func_8038A6EC(this))) {
                if (func_802D677C(-1) != map_get()) {
                    func_80311480(0xF7A, 4, NULL, NULL, NULL, NULL);
                    func_80320004(0xF5, 1);
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
                func_80328AC8(this, 2);
                this->unk38_0 = FALSE;
                func_8038A96C(this, 1);
                func_802BAFE4(D_80393620[this->unkF4_8 - 1].unk3);
                func_802D09B8(this, 2);
                phi_a0 = (func_8031FF1C(func_8038A6EC(this)) != 0) ? SFX_107_CAULDRON_ACTIVATION_1 : SFX_108_CAULDRON_ACTIVATION_2;
                func_8030E510(phi_a0, 0x7D00);
                if (!func_8031FF1C(0xF5) && !func_8031FF1C(func_8038A6EC(this))) {
                    func_80311480(0xF79, 4, NULL, NULL, NULL, NULL);
                }
                if (func_8031FF1C(func_8038A6EC(this))){
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
            temp_f0 = func_802877D8(this->animctrl);
            for(sp3C = 0; D_803936E4[sp3C] < temp_f0; sp3C++)
                ;
            
            this->unk38_0 = (sp3C & 1) ? TRUE : FALSE;
            if (actor_animationIsAt(this, 0.95f)) {
                func_8038A704(this);
                func_80320004(func_8038A6DC(this), 1);
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
                func_8038AB90(this, 4, 2, 0xA6, 2.6f);
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
                func_803204E4(0x1E, 0);
                func_802D677C(0);
                func_8028FCAC();
                func_80304D68(func_80304C38(D_80393620[this->unkF4_8 - 1].unk6, this), sp54);
                if (this->unkF4_8 == 7) {
                    func_8028F66C(0x36);
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
            if (func_8038A690(this) && !func_8031FF1C(0xF3)) {
                func_80311480(0xFAD, 0xA, this->position, NULL, func_8038ADC0, NULL);
            }
            this->unk38_0 = TRUE;

            sp3C = 0;
            if (func_8031FF1C(0xFC)){
                if(jiggyscore_total() == 0x64){
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
            if( func_8038ADF0(sp38, (s32) this->velocity[0]) 
                || func_8038ADF0((s32) this->velocity[0], sp38)
            ) {
                this->yaw_moving = (f32) sp38;
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
#endif

Actor *func_8038B898(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;
    s32 sp3C[4];

    this = marker_getActor(marker);
    if(this->modelCacheIndex == 0x23B) {
        func_8033A45C(3, this->unk38_0 ? TRUE : FALSE);
        func_8033A45C(4, this->unk38_0 ? FALSE : TRUE);
    }
    this = func_80325888(marker, gfx, mtx, vtx);
    if (marker->unk14_21 && this->unk38_0 && (getGameMode() != GAME_MODE_4_PAUSED)) {
        sp3C[1] = randi2(200, 255);
        sp3C[0] = randi2(150, sp3C[1]);
        sp3C[2] = 0;
        sp3C[3] = randi2(40, 80);
        if (func_8023DB5C() & 1) {
            func_802EE354(this, 0x3E9, 5, randi2(-10, 90), randf2(0.3f, 0.7f), 0.28f, 0.45f, sp3C, 5, 0);
        }
    }
    return this;
}
