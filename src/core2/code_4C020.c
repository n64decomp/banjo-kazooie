#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "SnS.h"

extern f32 func_80258640(f32 [3], f32[3]);
extern void func_8025A788(enum comusic_e, f32, f32);
extern void func_8031CC40(enum map_e, s32);
extern void func_802F363C(f32);
extern void func_802F9D38(s32);
extern void func_802EE6CC(f32[3], f32[3], s32[4], s32, f32, f32, s32, s32, s32);
extern void ml_vec3f_assign(f32[3], f32, f32, f32);


void func_802D3D54(Actor *this);
void func_802D3DA4(Actor *this);
Actor *func_802D3F48(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void func_802D3FD4(Actor *this);
Actor *func_802D41C4(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void func_802D4250(Actor *this);
void func_802D4388(Actor *this);
Actor *func_802D4588(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void func_802D4680(Actor *this);
void func_802D4B94(Actor *this);
void func_802D4BBC(Actor *this);
void func_802D4BE4(Actor *this);
void func_802D4C0C(Actor *this);
void func_802D4C34(Actor *this);
void func_802D4C5C(Actor *this);
void func_802D4C84(Actor *this);
void func_802D4CAC(Actor *this);
void func_802D4CD4(Actor *this);
void func_802D68F0(s32 seconds);

typedef struct {
    u8 pad0[4];
    s16 unk4;
    s16 unk6;
}Struct_core2_4C020_0;

/* .data */
extern ActorAnimationInfo D_803676B0[];
extern ActorInfo D_80367760 = { 0x26E, 0x2D9, 0x3B4,  0x1, NULL,       func_802D3D54, func_80326224, func_80325E78, 0, 0, 0.0f, 0};
extern ActorInfo D_80367784 = { 0x26F, 0x2DA, 0x3B5,  0x1, NULL,       func_802D3D54, func_80326224, func_80325E78, 0, 0, 0.0f, 0};
extern ActorInfo D_803677A8 = { MARKER_168_ICE_KEY, ACTOR_25D_ICE_KEY, ASSET_50C_MODEL_ICE_KEY,  0x1, NULL,       func_802D4250, func_80326224, func_80325E78, 0, 0, 0.0f, 0};
extern ActorInfo D_803677CC = { 0x233, 0x23D, 0x4DD, 0x12, D_803676B0, func_802D4388, func_80326224, func_802D4588, 0, 0, 0.0f, 0};
extern ActorInfo D_803677F0 = { 0x16A, 0x242,   0x0,  0x0, NULL,       func_802D4680,          NULL, func_80325340, 0, 0, 0.0f, 0};
extern ActorInfo D_80367814 = { MARKER_169_SNS_EGG, ACTOR_25E_SNS_EGG, ASSET_50D_MODEL_SNS_EGG,  0x1, NULL,       func_802D3FD4,          NULL, func_802D41C4, 0, 0, 0.0f, 0};
extern ActorInfo D_80367838 = { 0x265, 0x2E4, 0x55A,  0x1, NULL,       func_802D3DA4,          NULL, func_802D3F48, 0, 0, 0.0f, 0};
extern ActorInfo D_8036785C = { MARKER_103_MM_WITCH_SWITCH, ACTOR_204_MM_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4B94, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80367880 = { MARKER_104_MMM_WITCH_SWITCH, ACTOR_206_MMM_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4C34, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_803678A4 = { MARKER_105_TTC_WITCH_SWITCH, ACTOR_208_TTC_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4C5C, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_803678C8 = { MARKER_106_RBB_WITCH_SWITCH, ACTOR_20B_RBB_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4C84, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_803678EC = { MARKER_22A_CCW_WITCH_SWITCH, ACTOR_237_CCW_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4CAC, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80367910 = { MARKER_22B_FP_WITCH_SWITCH, ACTOR_239_FP_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4CD4, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80367934 = { MARKER_166_CC_WITCH_SWITCH, ACTOR_25B_CC_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4BBC, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80367958 = { MARKER_162_BGS_WITCH_SWITCH, ACTOR_257_BGS_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4BE4, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_8036797C = { MARKER_161_GV_WITCH_SWITCH, ACTOR_256_GV_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4C0C, func_80326224, func_80325888, 0, 0, 0.0f, 0};

extern f32 D_80367680;
extern s32 D_80367684; //enum map_e
extern s32 D_80367688;
extern s32 D_8036768C;
extern s32 D_80367690;
extern s32 D_80367694; //enum map_e
extern s32 D_80367698;
extern s32 D_8036769C; //enum bkprog_e
extern s32 D_803676A0; //enum actor_e
extern s32 D_803676A8;
extern u8  D_803676AC;
extern s32 D_803679A0[4];
extern s16 D_803679B0[];
extern Struct_core2_4C020_0 D_803679C8[];
extern s16 D_803679E0[];
extern s32 D_803679E8;
extern s32 D_803679EC;
extern f32 D_803679F0;


/* .rodata */
extern f32 D_80376984;
extern f64 D_80376988;
extern f64 D_80376990;
extern f64 D_80376998;
extern f64 D_803769A0;
extern f32 D_803769A8;
extern f32 D_803769AC;

extern f32 D_803769B0;
extern f64 D_803769B8; //3FA999999999999A
extern f32 D_803769C0; //3F666666

extern f32 D_80376A78;
extern f32 D_80376A7C;
extern f32 D_80376A80;
extern f32 D_80376A84;
extern f32 D_80376A88;
extern f64 D_80376A90;
extern f64 D_80376A98;

// 3ECCCCCD 3ECCCCCD
// 3ECCCCCD 3ECCCCCD  3ECCCCCD
// 4072C00000000000  4072C00000000000

/* .bss */
int D_8037DE00;
f32 D_8037DE04;
f32 D_8037DE08;

void func_802D6114(void);
void func_802D6264(f32 arg0, enum map_e arg1, s32 arg2, s32 arg3, s32 arg4, enum bkprog_e arg5);
void func_802D6344(void);
void func_802D63D4(void);
void func_802D6750(void);

/* .code */
void func_802D2FB0(Actor *this, s32 arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    f32 spA4[3];
    f32 sp98[3];
    s32 i;

    sp98[0] = this->position[0];
    sp98[2] = this->position[2];
    for(i = 0; i < arg1; i++){
        sp98[1] = this->position[1] + randf2((f32) arg2, (f32) arg3);
        spA4[1] = randf2(4.0f, 10.0f);
        spA4[0] = randf2(-8.0f, 8.0f);
        spA4[2] = randf2(-8.0f, 8.0f);
        func_802EE6CC(sp98, spA4, D_803679A0, 1, arg4, 50.0f, arg5, randi2(arg6, arg7), 0);
    }
}

void func_802D3138(ActorMarker *marker, ActorMarker *other_marker){
    if(marker->unk14_20 == 0x224 || marker->unk14_20 == 0x225){
        func_8025A70C(COMUSIC_2B_DING_B);
    }
}

void func_802D317C(ActorMarker *marker, enum bkprog_e prog_flag_id){
    func_80320004(prog_flag_id, TRUE);
    marker_despawn(marker);
}

#ifndef NONMATCHING
void func_802D31AC(ActorMarker *marker, ActorMarker *other_marker);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D31AC.s")
#else
void func_802D31AC(ActorMarker *marker, ActorMarker *other_marker){
    Actor *sp2C;

    sp2C = marker_getActor(marker);
    swtich(marker->unk14_20){
    //L802D3218 x < 0x23a //jmptbl D_80376720
    //L802D3292 x < 0x124 //jmptbl D_80376778
    //L802D32CC x < 0xa2  //jmptbl D_8037686C

    case 0x17d://L802D3308
        func_8030E624(0x599ff882);
        func_8030E624(0x4cbff882);
        func_802D2FB0(sp2C, 0x14, -0x1e, 0x190, 3.0f, 0x15e, 0x50, 0x96);
        sp2C->unk60 = 1.0f;
        func_80320004(0xA5, TRUE);
        break;

    case 0x163://L802D3558
        break;

    case 0x263://L802D35A8
        break;

    case 0x1f2://L802D3A8C
    case 0x1f3://L802D3A8C
        break;

    case 0x164://L802D3C68
    case 0x165://L802D3C68
        break;

    
    //L802D3CA0 else

    }
}
#endif

void func_802D3CC8(ActorMarker *marker){
    func_802D31AC(marker, NULL);
}

void func_802D3CE8(Actor *this){
    if(!this->initialized){
        marker_setCollisionScripts(this->marker, NULL, func_802D3138, func_802D31AC);
        this->marker->propPtr->unk8_3 = TRUE;
        this->initialized = TRUE;
    }
}

void func_802D3D54(Actor *this){
    func_802D3CE8(this);
}

void func_802D3D74(Actor *this){
    this->marker->propPtr->unk8_3 = TRUE;
    actor_collisionOff(this);
}

void func_802D3DA4(Actor *this) {
    f32 sp24[3];
    s32 phi_v0;

    if ((*(s32*)OS_PHYSICAL_TO_K1(0x22C) - 0x12600004)) {
        return;
    }

    if (!this->unk16C_4) {

        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk38_31 = 0;
    }
    player_getPosition(sp24);
    phi_v0 = ((this->position[1] - 5.0f) <= sp24[1]) && (sp24[1] <= (this->position[1] + 30.0f))
        && (((sp24[0] - this->position[0])*(sp24[0] - this->position[0]) + (sp24[2] - this->position[2])*(sp24[2] - this->position[2])) < D_80376984);

    if ((this->unk38_31 == 0) && (phi_v0 == 0)) {
        this->unk38_31 = 1;
    }
    if ((this->unk38_31 == 1) && (phi_v0 == 1) 
        && func_8028F20C() && (func_8028F66C(BS_INTR_37) == 2)) {
        this->unk38_31 = 2;
    }
}

Actor *func_802D3F48(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    s32 phi_s2;
    Actor *this;
    s32 i;

    this = marker_getActor(marker);
    phi_s2 = this->unkF4_8;
    for(i = 0; i < 9; i++){
        func_8033A45C(i + 1, i+1 == phi_s2);
    }
    return func_80325E78(marker, gfx, mtx, vtx);
}

void func_802D3FD4(Actor *this){
    if(!this->initialized){
        this->initialized = TRUE;
        func_802D3CE8(this);
        switch(map_get()){
            case MAP_1D_MMM_CELLAR: //L802D4058
                if(sns_get_item_state(SNS_ITEM_EGG_CYAN, 1) && !sns_get_item_state(SNS_ITEM_EGG_CYAN, 0)){
                    return;
                }
                break;

            case MAP_61_CCW_WINTER_NABNUTS_HOUSE://L802D4080
                if(sns_get_item_state(SNS_ITEM_EGG_YELLOW, 1) && !sns_get_item_state(SNS_ITEM_EGG_YELLOW, 0)){
                    return;
                }
                break;

            case MAP_2C_MMM_BATHROOM: //L802D40A8
                if(sns_get_item_state(SNS_ITEM_EGG_GREEN, 1) && !sns_get_item_state(SNS_ITEM_EGG_GREEN, 0)){
                    return;
                }
                break;

            case MAP_3F_RBB_CAPTAINS_CABIN: //L802D40D0
                if(sns_get_item_state(SNS_ITEM_EGG_RED, 1) && !sns_get_item_state(SNS_ITEM_EGG_RED, 0)){
                    return;
                }
                break;

            case MAP_92_GV_SNS_CHAMBER:
                if(!sns_get_item_state(SNS_ITEM_EGG_BLUE, 0))
                    return;
                break;

            case MAP_8F_TTC_SHARKFOOD_ISLAND: //L802D4110
                if(!sns_get_item_state(SNS_ITEM_EGG_PINK, 0))
                    return;
                break;
        }//L802D4124
        marker_despawn(this->marker);
        return;
    }//L802D4134

    this->yaw += (this->unkF4_8 & 1) ? D_80376988 : D_80376990;
    if(this->yaw < 0.0f){
        this->yaw += 360.0f;
    }
    if(360.0f <= this->yaw){
        this->yaw -= 360.0f;
    }
}

Actor *func_802D41C4(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    s32 sp2C;
    Actor *this;
    s32 i;

    this = marker_getActor(marker);
    sp2C = this->unkF4_8;
    for(i = 0; i < 6; i++){
        func_8033A45C(i+1, FALSE);
    }
    func_8033A45C(sp2C, TRUE);
    return func_80325E78(marker, gfx, mtx, vtx);
}

void func_802D4250(Actor *this){
    if(!this->initialized){
        this->initialized = TRUE;
        func_802D3CE8(this);
        if(sns_get_item_state(SNS_ITEM_ICE_KEY, FALSE)){
            marker_despawn(this->marker);
        }
        return;
    }
    this->yaw += 2.0;
    if(360.0f <= this->yaw){
        this->yaw -= 360.0f;
    }
}



bool func_802D42F8(Actor *this) {
    s32 i;

    for(i = 0; D_803679B0[i] != -1 && this->unkF4_8 != D_803679B0[i]; i+=2){
    }

    if (D_803679B0[i] == -1) {
        return FALSE;
    }
    else{
        return func_8031FF1C(D_803679B0[i + 1]);
    }
}


void func_802D4388(Actor *this){
    func_802D3CE8(this);
    this->unk38_0 = ( map_get() == MAP_7A_GL_CRYPT || item_getCount(ITEM_1C_MUMBO_TOKEN) >= this->unkF4_8 || func_802D42F8(this)) ? TRUE : FALSE;
    mapSpecificFlags_set(0x1F, (func_8028F20C() && func_8028FB48(0x78000000)) || func_8028ECAC() == BSGROUP_D_TRANSFORMING);
    switch(this->state){
        case 0x12: //L802D4468
            if(this->unk38_0 && mapSpecificFlags_get(0x1F)){
                func_80328B8C(this, 0x13, 0.0f, 1);
                actor_playAnimationOnce(this);
                func_8030E6D4(SFX_90_SWITCH_PRESS);
            }
            break;

        case 0x13: //L802D44B0
            if(D_80376998 <= animctrl_getAnimTimer(this->animctrl)){
                func_80328B8C(this, 0x14, 0.66f, 0);
            }
            break;

        case 0x14: //L802D44F0
            if(!this->unk38_0 || !mapSpecificFlags_get(0x1F)){
                func_80328B8C(this, 0x15, 0.66f, 0);
                actor_playAnimationOnce(this);
            }
            break;

        case 0x15: //L802D4534
             if(animctrl_getAnimTimer(this->animctrl) < D_803769A0){
                func_80328B8C(this, 0x12, 0.0f, 1);
            }
            break;
    }//L802D456C
    mapSpecificFlags_set(0x1F, FALSE);
}

Actor *func_802D4588(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    s32 phi_a1;

    phi_a1 = (marker_getActor(marker)->unk38_0) ? ((func_8023DB5C() & 4) != 0) ? 1 : 2 : 2;
    func_8033A45C(1, phi_a1);
    return func_80325888(marker, gfx, mtx, vtx);
}

bool func_802D4608(void){
    return D_803676AC;
}

void func_802D4614(enum map_e map_id){
    if(D_803676AC)
        return;
    D_803676AC = TRUE;
    func_8028F918(2);
    func_8025A788(COMUSIC_69_FF_WARP, 0.0f, 1.7f);
    timedFunc_set_2(1.0f, (TFQM2) func_8031CC40, map_id, 2);
}

void func_802D4680(Actor *this){
    f32 sp1C[3];

    player_getPosition(sp1C);
    switch(this->state){
        case 0:
            if(150.0f < func_80258640(this->position, sp1C)){
                func_80328A84(this, 1);
                D_803676AC = 0;
            }
            break;
        case 1:
            if(func_80258640(this->position, sp1C) < 150.0f && func_8028F20C()){
                if(func_8028ECAC() == 0 ||  func_8028ECAC() == BSGROUP_8_TROT){
                    if(map_get() == MAP_8E_GL_FURNACE_FUN){
                        func_803204E4(0, 0);
                        func_802D4614(MAP_80_GL_FF_ENTRANCE);
                    }
                    else{
                        func_802D4614(MAP_8E_GL_FURNACE_FUN);
                    }
                }
            }
            break;
    }
}

void func_802D4794(Actor *this, enum sfx_e sfx_id, f32 arg2, s32 arg3, s32 arg4){
    if(this->unk44_31 != 0)
        return;

    this->unk44_31 = func_802F9AA8(sfx_id);
    func_802FA060(this->unk44_31, arg3, arg3, 0.0f);
    func_802F9DB8(this->unk44_31, arg2, arg2, 0.0f);
    func_802F9F80(this->unk44_31, (f32)arg4, 1e+09f, 0.0f);
}

void func_802D4830(Actor *this, enum sfx_e arg1, f32 arg2){
    func_802D4794(this, arg1, arg2, 32000, 0);
}

void func_802D485C(Actor *this, enum sfx_e arg1, f32 arg2, s32 arg3){
    func_802D4794(this, arg1, arg2, arg3, 0);
}

void func_802D4884(Actor *this, enum sfx_e sfx_id, f32 arg2, s32 arg3, f32 arg4){
    func_802D4794(this, sfx_id, arg2, arg3, (s32)arg4);
}

void func_802D48B8(Actor *this){
    if(this->unk44_31){
        func_802F9D38(this->unk44_31);
        this->unk44_31 = 0;
    }
}

void func_802D48F0(void){
    if(D_803676A8){
        func_802F9D38(D_803676A8);
        D_803676A8 = 0;
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4928.s")
#else
void func_802D4928(Actor *this, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp1C;

    this->marker->propPtr->unk8_3 = TRUE;
    sp1C = arg1 & 0xC00000;
    if( ( ((sp1C == 0) && mapSpecificFlags_get(arg1 - 0)) 
          || ((sp1C == 0x800000) && func_8031FF1C(arg1 - 0x800000)) 
          || ((sp1C == 0x400000) && func_803203FC(arg1 - 0x400000))
        ) 
        && (arg2 != this->state)
    ) {
        func_80328B8C(this, arg2, 0.0f, 1);
        actor_playAnimationOnce(this);
    }
    sp1C = arg1 & 0xC00000;
    if( ( ((sp1C == 0) && !mapSpecificFlags_get(arg1 - 0)) 
          || ((sp1C == 0x800000) && !func_8031FF1C(arg1 - 0x800000)) 
          || ((sp1C == 0x400000) && !func_803203FC(arg1 - 0x400000))
        ) 
        && (arg2 == this->state)
    ) {
        func_80328B8C(this, arg3, 0.0f, 1);
        actor_playAnimationOnce(this);
    }
    if(sp1C);
}
#endif

void func_802D4A9C(Actor *this, s32 arg1){
    func_802D4928(this, arg1, 2, 3);
}

void func_802D4AC0(Actor *this, s32 arg1, s32 arg2) {
    if (func_8031FF1C(arg2)) {
        if (arg1 & 0x800000) {
            func_80320004(arg1 + 0xFF800000, 1);
        }
        if (arg1 & 0x400000) {
            func_803204E4(arg1 + 0xFFC00000, 1);
        }
    }
    if( (((arg1 & 0x800000) && (func_8031FF1C(arg1 + 0xFF800000))) || ((arg1 & 0x400000) && (func_803203FC(arg1 + 0xFFC00000)))) 
        && (func_8031FF1C(arg2)) && (this->animctrl == NULL)
    ) {
        func_80328B8C(this, 8, 0.0f, 1);
    }
    func_802D4A9C(this, arg1);
}


void func_802D4B94(Actor *this){
    func_802D4AC0(this, 0x4000b6, BKPROG_18_MM_WITCH_SWITCH_JIGGY_SPAWNED);
}

void func_802D4BBC(Actor *this){
    func_802D4AC0(this, 0x4000bc, 0x9A);
}

void func_802D4BE4(Actor *this){
    func_802D4AC0(this, 0x4000bd, 0x9F);
}

void func_802D4C0C(Actor *this){
    func_802D4AC0(this, 0x4000be, 0xA0);
}

void func_802D4C34(Actor *this){
    func_802D4AC0(this, 0x4000b7, BKPROG_19_MMM_WITCH_SWITCH_JIGGY_SPAWNED);
}

void func_802D4C5C(Actor *this){
    func_802D4AC0(this, 0x4000b8, BKPROG_1A_TTC_WITCH_SWITCH_JIGGY_SPAWNED);
}

void func_802D4C84(Actor *this){
    func_802D4AC0(this, 0x4000b9, BKPROG_1C_RBB_WITCH_SWITCH_JIGGY_SPAWNED);
}

void func_802D4CAC(Actor *this){
    func_802D4AC0(this, 0x4000ba, BKPROG_46_CCW_WITCH_SWITCH_JIGGY_SPAWNED);
}

void func_802D4CD4(Actor *this){
    if(map_get() == MAP_27_FP_FREEZEEZY_PEAK){
        if(func_8038BFA0()){
            this->unk58_0 = FALSE;
            return;
        }//L802D4D10
        this->unk58_0 = TRUE;
    }//L802D4D1C
    func_802D4AC0(this, 0x4000bb, 0x47);
}

void func_802D4D3C(s32 arg0, s32 arg1) {
    s32 sp5C[3];
    s32 sp4C[4];
    f32 sp40[3];

    if (func_80304E24(arg1, &sp5C)) {
        func_803331D8(arg0, &sp5C);
        func_8025A6EC(COMUSIC_3D_JIGGY_SPAWN, 0x7FFF);
        if (arg0 == 0x36) {
            
            sp4C[3] = 200;
            sp4C[0] = sp4C[1] = sp4C[2] = 180;\
            ml_vec3f_assign(&sp40, 0.0f, 0.0f, 0.0f);
            func_802EE6CC(&sp5C, &sp40, &sp4C, 0, 6.0f, 200.0f, 200, 100, 0);

            sp4C[3] = 230;
            sp4C[0] = sp4C[1] = sp4C[2] = 150;
            ml_vec3f_assign(&sp40, 0.0f, 2.0f, 0.0f);
            func_802EE6CC(&sp5C, &sp40, &sp4C, 0, 2.0f, 90.0f, 50, 33, 0);
          
            sp4C[3] = 150;
            sp4C[0] = sp4C[1] = sp4C[2] = 230;
            ml_vec3f_assign(&sp40, -3.0f, 1.0f, 1.0f);
            func_802EE6CC(&sp5C, &sp40, &sp4C, 0, 3.5f, 130.0f, 100, 80, 0);

            sp4C[3] = 200;
            sp4C[0] = sp4C[1] = sp4C[2] = 250;
            ml_vec3f_assign(&sp40, -1.0f, 3.0f, -3.0f);
            func_802EE6CC(&sp5C, &sp40, &sp4C, 0, D_803769A8, 40.0f, 10, 120, 0);
            
            sp4C[3] = 130;
            sp4C[0] = sp4C[1] = sp4C[2] = 130;
            ml_vec3f_assign(&sp40, 2.0f, -2.0f, 2.0f);
            func_802EE6CC(&sp5C, &sp40, &sp4C, 0, D_803769AC, 180.0f, 20, 160, 0);
            func_8030E6D4(SFX_1B_EXPLOSION_1);
        }
        else{
            func_802C3F04(func_802C4140, 0x4C, 
                reinterpret_cast(s32, sp5C[0]),
                reinterpret_cast(s32, sp5C[1]),
                reinterpret_cast(s32, sp5C[2])
            );
        }
    }
}

void func_802D5000(enum map_e map_id){
    if(map_getLevel(map_id) != level_get())
        func_802E4A70();
    func_803228D8();
    func_802E4078(D_80367684, 0x65, 0);
}

void func_802D5058(enum map_e map_id, s32 arg1, bool arg2) {
    func_803204E4(1, 1);
    D_80367684 = map_id;
    D_80367688 = arg1;
    if (arg2) {
        D_8036768C = 0x2D;
    } else {
        D_8036768C = 0x15;
    }
    D_80367690 = 0;
    D_80367694 = map_get();
    D_80367698 = 1;
    D_8036769C = 0;
    D_803676A0 = 0;
    if (map_id != D_80367694) {
        timedFunc_set_1(0.25f, func_802D5000, map_id);
    } else {
        timedFunc_set_0(0.25f, func_802D63D4);
    }
    gcpausemenu_80314AC8(0);
}


void func_802D5140(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    itemscore_noteScores_get(func_80320424(0x19, 4));
}

void func_802D5178(s32 arg0, enum bkprog_e arg1, s32 arg2, enum map_e arg3, s32 arg4, s32 arg5, enum actor_e arg6, s32 arg7){
    if(levelSpecificFlags_get(arg0) && !func_8031FF1C(arg1)){
        levelSpecificFlags_set(arg0, FALSE);
        func_80320004(arg1, TRUE);
        func_802D6264(D_803769B0, arg3, arg2, arg4, arg5, 0);
        D_803676A0 = arg6;
        D_80367690 = arg7;
    }
}

void func_802D520C(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    if(func_803203FC(1) && map_get() != MAP_8E_GL_FURNACE_FUN){
        func_80319214(gfx, mtx, vtx);
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D5260.s")
#else
extern f32 D_803676A4;
extern f32 D_803769B4;
void func_802D5260(void) {
    s32 sp3C;
    s32 sp38;
    f32 sp34;
    f32 sp28[3];
    s32 phi_v0_2;
    s32 phi_v1_2;

    sp3C = (map_get() == MAP_76_GL_640_NOTE_DOOR) ? 0
         : (map_get() == MAP_77_GL_RBB_LOBBY) ? 1
         : (map_get() == MAP_78_GL_RBB_AND_MMM_PUZZLE) ? 2
         : -1;

    if (sp3C == -1) {
        levelSpecificFlags_set(0x3C, FALSE);
        func_80320004(BKPROG_26_WATER_SWITCH_3_PRESSED, FALSE);
        func_80320004(BKPROG_27_LAIR_WATER_LEVEL_3,     FALSE);
        levelSpecificFlags_set(0x3D, FALSE);
        return;
    }
    sp38 = func_8034C528(sp3C + 0x190);
    if( func_8031FF1C(BKPROG_27_LAIR_WATER_LEVEL_3)
        && !levelSpecificFlags_get(0x3D)
        && !levelSpecificFlags_get(0x3C)
    ) {
        func_802D68F0(30);
        item_set(ITEM_6_HOURGLASS, TRUE);
        levelSpecificFlags_set(0x3D, TRUE);
    }
    if( levelSpecificFlags_get(0x3D)
        && !levelSpecificFlags_get(0x3C) 
        && item_getCount(ITEM_6_HOURGLASS) == FALSE
    ) {
        levelSpecificFlags_set(0x3C, TRUE);
        levelSpecificFlags_set(0x3D, FALSE);
        D_803676A4 = 0.0f;
    }
    if (levelSpecificFlags_get(0x3C)) {
        D_803676A4 -= 5.0;
        if (D_803676A8 == 0) {
            D_803676A8 = func_802F9AA8(SFX_3EC_CCW_DOOR_OPENING);
            func_802FA060(D_803676A8, 20000, 20000, 0.0f);
            func_802F9F80(D_803676A8, 0.0f, 1.0e8f, 0.0f);
        }
        if (D_803679C8[sp3C].unk6 + D_803676A4 <= D_803679C8[sp3C].unk4) {
            levelSpecificFlags_set(0x3C, FALSE);
            func_80320004(BKPROG_26_WATER_SWITCH_3_PRESSED, FALSE);
            func_80320004(BKPROG_27_LAIR_WATER_LEVEL_3,     FALSE);
            func_802F9D38(D_803676A8);
            D_803676A8 = 0;
        }
    }
    if (sp38 != 0) {
        if (levelSpecificFlags_get(0x3C) != 0) {
            sp34 = D_803679C8[sp3C].unk6 + D_803676A4;
        } else {
            if (func_8031FF1C(BKPROG_27_LAIR_WATER_LEVEL_3)) {
                phi_v0_2 = 3;
            } else {
                if (func_8031FF1C(BKPROG_25_LAIR_WATER_LEVEL_2)) {
                    phi_v1_2 = 2;
                } else {
                    if (func_8031FF1C(BKPROG_23_LAIR_WATER_LEVEL_1)) {
                        phi_v0_2 = 1;
                    } else {
                        phi_v0_2 = 0;
                    }
                    phi_v1_2 = phi_v0_2;
                }
                phi_v0_2 = phi_v1_2;
            }
            sp34 = ((s16 *)&D_803679C8[sp3C])[phi_v0_2];
        }
        func_8034DEB4(sp38, sp34);
        player_getPosition(sp28);
        
        if (sp3C != -1) {
            phi_v1_2 = (sp3C == 2) ? (D_803769B4 < sp28[0]) ? -200 : 0 : 0;
            phi_v0_2 = D_803679E0[sp3C] + phi_v1_2;
        }
        else{
            phi_v0_2 = 0;
        }
        func_802F363C((f32) phi_v0_2 + sp34);
    }
}
#endif


#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D5628.s")
#else
void func_802D5628(void){
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp50[6];
    s32 sp4C;
    // static s32 D_803679E8 = 0;
    // static s32 D_803679EC = 0;
    // static f32 D_803679F0 = 0.0f;

    if( map_get() != MAP_8E_GL_FURNACE_FUN
        && map_get() != MAP_80_GL_FF_ENTRANCE
    ){
        D_803676AC = 0;
    }

    if(getGameMode() != GAME_MODE_4_PAUSED){
        if( func_802BB294() == 0x82 
            && ! gctransition_8030BDC0()
        ){
            D_803679E8++;
            if(D_803679EC < D_803679E8){
                D_803679EC--;
                D_803679E8 = 0;
                if(D_803679EC < 2){
                    D_803679EC = 2;
                }
                func_8030E6A4(SFX_2_CLAW_SWIPE, MIN(2.0,D_803679F0), 20000);
                D_803679F0 += D_803769B8;
            }
        }
        else{//L802D5750
            D_803679F0 = 0.9f;
            D_803679EC = 0xD;
            D_803679E8 = 0;
        }
    }//L802D5774
    if(D_80367684 && map_get() == D_80367684){
        switch(D_8036768C){
            case 0x1: // L802D57C8
                if(!D_80367690){
                    timedFunc_set_2(0.4f, (TFQM2) func_802D4D3C, 0x34, 0x205);
                    D_80367690++;
                }
                break;

            case 0x2: // L802D5808
                if(!D_80367690){
                    timedFunc_set_2(0.4f, (TFQM2) func_802D4D3C, 0x39, 0x207);
                    D_80367690++;
                }
                break;

            case 0x3: // L802D5848
                if(!D_80367690){
                    timedFunc_set_2(0.4f, (TFQM2) func_802D4D3C, 0x36, 0x20a);
                    D_80367690++;
                }   
                break;

            case 0x4: // L802D5888
                func_802D5260();
                if(!D_80367690){
                    timedFunc_set_2(0.4f, (TFQM2) func_802D4D3C, 0x3b, 0x20c);
                    D_80367690++;
                }
                break;

            case 0x12: // L802D58D0
                if(!D_80367690){
                    timedFunc_set_2(0.4f, (TFQM2) func_802D4D3C, 0x3c, 0x238);
                    D_80367690++;
                }
                break;

            case 0x5: // L802D5910
                if(!D_80367690){
                    sp7C = func_802F9AA8(0x3EC);
                    sp78 = func_8034C528(0x191);
                    if(sp78){
                        func_8034DE60(sp78, -580.0f, 0.0f, 2.5f, 1);
                    }
                    func_802FA060(sp7C, 20000, 20000, 0.0f);
                    func_802F9F80(sp7C, 0.0f, 2.2f, 0.7f);
                    D_80367690++;
                }
                break;

            case 0x6:// L802D599C
                if(!D_80367690){
                    sp74 = func_802F9AA8(0x3EC);
                    sp70 = func_8034C528(0x191);
                     if(sp70){
                        func_8034DE60(sp70, 0.0f, 1550.0f, 6.5f, 1);
                    }
                    func_802FA060(sp74, 20000, 20000, 0.0f);
                    func_802F9F80(sp74, 0.0f, 6.2f, 0.5f);
                    D_80367690++;
                }
                break;

            case 0x7: // L802D5A28
                if(!D_80367690){
                    sp6C = func_802F9AA8(0x3EC);
                    sp68 = func_8034C528(0x190);
                     if(sp68){
                        func_8034DE60(sp68, 1200.0f, 1900.0f, 3.0f, 1);
                    }
                    func_802FA060(sp6C, 20000, 20000, 0.0f);
                    func_802F9F80(sp6C, 0.0f, 2.7f, 0.5f);
                    D_80367690++;
                }
                break;

            case 0x15:// L802D5AB4
            case 0x2d:// L802D5AB4
                if(D_80367684 && D_80367684 == map_get()){
                    func_80319EA4();
                    if(0.0f < D_8037DE08){
                        D_8037DE08 -= time_getDelta();
                    }
                    else{//L802D5B24
                        func_8024E55C(0, sp50); //get button inputs
                        if(sp50[FACE_BUTTON(BUTTON_C_UP)] == 1){
                            func_80324C58();
                            func_802D6114();
                        }
                    }
                }
                break;

            case 0xd: // L802D5B54
                func_802D5260();
                break;
        }//L802D6078
    }
    else{//L802D5B64
        func_802D5260();
        func_802D5178(0x1C, 0x28, 0x30, MAP_69_GL_MM_LOBBY,  0x8, 0xA, ACTOR_20E_MM_ENTRANCE_DOOR,  0x28);
        func_802D5178(0x21, 0x2D, 0x31, MAP_6E_GL_GV_LOBBY,  0xA, 0xA, ACTOR_226_GV_ENTRANCE,       0x12);
        func_802D5178(0x1E, 0x2A, 0x32, MAP_70_GL_CC_LOBBY,  0xE, 0xA, ACTOR_212_IRON_BARS,         0xA);
        func_802D5178(0x1D, 0x29, 0x33, MAP_6D_GL_TTC_LOBBY, 0x9, 0xB, ACTOR_211_CHEST_LID,         0xA);
        func_802D5178(0x1F, 0x2B, 0x34, MAP_72_GL_BGS_LOBBY, 0xB, 0xB, ACTOR_210_BGS_ENTRANCE_DOOR, 0xA);
        func_802D5178(0x23, 0x2F, 0x35, MAP_77_GL_RBB_LOBBY, 0xD, 0x5, ACTOR_20F_RBB_ENTRANCE_DOOR, 0xA);
        func_802D5178(0x22, 0x2E, 0x36, MAP_75_GL_MMM_LOBBY, 0xC, 0x6, ACTOR_228_INVISIBLE_WALL,    0xA);
        func_802D5178(0x24, 0x30, 0x37, MAP_79_GL_CCW_LOBBY, 0xF, 0xB, ACTOR_234_CCW_ENTRANCE_DOOR, 0xA);
        func_802D5178(0x20, 0x2C, 0x38, MAP_6F_GL_FP_LOBBY, 0x11, 0xA, ACTOR_235_FP_ENTANCE_DOOR,   0xA);
        func_802D5178(0x3F, 0xE2, 0x40, MAP_93_GL_DINGPOT,  0x10, 0xA, ACTOR_2E5_WOODEN_DOOR,       0x28);
        if(func_803203FC(0x18)){
            if(!func_8031FF1C(BKPROG_99_PAST_50_NOTE_DOOR_TEXT)){
                func_80311174(0xF75, 0xE, NULL, NULL, NULL, NULL, func_802D5140);
                func_80320004(BKPROG_99_PAST_50_NOTE_DOOR_TEXT, TRUE);
                func_803204E4(0x18, 0);
            }
            else{//L802D5DD8
                if(!func_803203FC(0x16)){
                    func_80311174(0xF77, 0x4, NULL, NULL, NULL, NULL, func_802D5140);
                    func_803204E4(0x18, 0);
                }
            }
        }//L802D5E18
        if(level_get() == LEVEL_6_LAIR){
            if( getGameMode() == GAME_MODE_3_NORMAL
                || func_802E4A08()
            ){
                if( map_get() != MAP_8E_GL_FURNACE_FUN
                    && map_get() != MAP_90_GL_BATTLEMENTS
                    && !func_8031FF1C(BKPROG_FC_DEFEAT_GRUNTY)
                ){
                    D_8037DE04 += time_getDelta();
                    if(D_80367680 < D_8037DE04 && !func_803203FC(0x16)){
                        if(func_8031FF1C(BKPROG_A6_FURNACE_FUN_COMPLETE)){
                            sp4C = 0xF9D;
                        }
                        else{
                            sp4C = 0xFA5;
                        }

                        if(!D_8037DE00){
                            D_8037DE00 = randi2(0xF86, sp4C);
                        }//L802D5F1C

                        if(func_803203FC(0x22)){
                            if(func_80311480(0xF82, 4, NULL, NULL, NULL, NULL)){
                                func_80320004(0xc1, 1);
                                func_803204E4(0x22, 0);
                                D_8037DE04 = 0.0f;
                                D_80367680 += 60.0;
                                if(300.0 < D_80367680)
                                    D_80367680 = 130.0f;
                            }
                        }
                        else{//L802D5FCC
                            if(func_80311480(D_8037DE00, 0, NULL, NULL, NULL, NULL)){
                                D_8037DE00++;
                                if(!(D_8037DE00 < sp4C)){
                                    D_8037DE00 = 0xF86;
                                }//L802D6018
                                D_8037DE04 = 0.0f;
                                D_80367680 += 60.0;
                                if(300.0 < D_80367680)
                                    D_80367680 = 130.0f;
                            }
                        }
                    }
                }
            }
        }//L802D607C
    }//L802D607C
}
#endif

//water_level_atleast_2;
int func_802D6088(void){
    return func_8031FF1C(BKPROG_25_LAIR_WATER_LEVEL_2)
        || func_8031FF1C(BKPROG_27_LAIR_WATER_LEVEL_3);
}

//water_level_atleast_1;
int func_802D60C4(void){
    return func_8031FF1C(BKPROG_23_LAIR_WATER_LEVEL_1)
        || func_8031FF1C(BKPROG_25_LAIR_WATER_LEVEL_2)
        || func_8031FF1C(BKPROG_27_LAIR_WATER_LEVEL_3);
}

void func_802D6114(void){
    s32 sp24; 
    s32 sp20;

    sp24 =  D_80367694;\
    sp20 =  D_80367698;
    if(D_8036769C)
        func_80320004(D_8036769C, TRUE);
    func_802D6344();
    if(map_get() != sp24){
        if(map_getLevel(sp24) != map_getLevel(map_get())){
            func_802E4A70();
        }//L802D6194
        func_803204E4(0x21, 1);
        if(sp24 != 0x1C || !func_8025ADBC(COMUSIC_23_MMM_INSIDE_CHURCH)){
            func_803228D8();
        }
        func_802E4078(sp24, sp20, 0);
    }
    else{//L802D61DC
        func_80347A14(1);
        gcpausemenu_80314AC8(1);
    }
}

void func_802D61FC(enum map_e arg0){
    if( map_getLevel(arg0) != map_getLevel(map_get()))
        func_802E4A70();
    func_803228D8();
    func_802E4078(D_80367684, 0, 0);
    func_802D6750();
}

void func_802D6264(f32 arg0, enum map_e arg1, s32 arg2, s32 arg3, s32 arg4, enum bkprog_e arg5){
    D_80367684 = arg1;
    D_80367688 = arg2;
    D_8036768C = arg3;
    D_80367690 = 0;

    D_80367694 = map_get();
    D_80367698 = arg4;
    D_8036769C = arg5;
    D_803676A0 = 0;

    if(arg1 != D_80367694){
        timedFunc_set_1(arg0, (TFQM1) func_802D61FC, arg1);
    }
    else{
        timedFunc_set_0(arg0, func_802D63D4);
    }
    gcpausemenu_80314AC8(0);
}

void func_802D6310(f32 arg0, enum map_e arg1, s32 arg2, s32 arg3, enum bkprog_e arg4){
    func_802D6264(arg0, arg1, arg2, arg3, 0x63, arg4);
    func_8028FCE8();
}

void func_802D6344(void){
    D_80367684 = 0;
    D_80367688 = 0;
    D_8036768C = 0;
    D_80367690 = 0;
    D_80367694 = 0;
    D_80367698 = 0;
    D_8036769C = 0;
    D_803676A0 = 0;
}

void func_802D6388(void){
    timedFunc_set_0(5.0f, func_802D6114);
    func_802BBC58(1);
    set_camera_to_node(D_80367688);
    D_8037DE08 = 0.5f;
}

void func_802D63D4(void){
    f32 sp1C[3];

    if(D_80367684 == 0)
        return;

    if(map_get() != D_80367684)
        return;

    func_80347A14(0);
    switch(D_8036768C){
        case 0x15:  //L802D6430
            func_802D6388();
            break;
        case 0x2D: //L802D6440
            func_802D6388();
            func_802BAEF4(sp1C);
            func_8028F85C(sp1C);
            break;
        default: //L802D6460
            func_802BAFE4(D_80367688);
            timedFuncQueue_update();
            func_803204E4(0xbf, 0);
            func_802D6750();
            break;
    }
}


void func_802D6494(void){
    if( (!D_80367684 || (D_80367684 && (map_get() == D_80367684)))
    ){
        switch(D_803676A0){
            case ACTOR_2E5_WOODEN_DOOR:
                break;
            case ACTOR_20E_MM_ENTRANCE_DOOR:// L802D6510
                FUNC_8030E624(SFX_6B_LOCKUP_OPENING, 0.6f, 32000);
                func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                break;
            case ACTOR_211_CHEST_LID:// L802D6530
                FUNC_8030E624(SFX_6B_LOCKUP_OPENING, 0.6f, 32000);
                func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                break;
            case ACTOR_212_IRON_BARS:// L802D6550
                if(map_get() == MAP_70_GL_CC_LOBBY && !func_803203FC(UNKFLAGS1_7F_SANDCASTLE_OPEN_CC)){
                    func_802D4830(func_80326EEC(ACTOR_212_IRON_BARS), SFX_9A_MECHANICAL_CLOSING, 0.5f);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_234_CCW_ENTRANCE_DOOR:// L802D65A0
                if(map_get() == MAP_79_GL_CCW_LOBBY && !func_803203FC(UNKFLAGS1_93_SANDCASTLE_OPEN_CCW)){
                    func_802D485C(func_80326EEC(ACTOR_234_CCW_ENTRANCE_DOOR), SFX_3EC_CCW_DOOR_OPENING, 0.8f, 15000);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_210_BGS_ENTRANCE_DOOR:// L802D65F8
                if(!func_803203FC(0x84)){
                FUNC_8030E624(SFX_6B_LOCKUP_OPENING, 0.6f, 32000);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_235_FP_ENTANCE_DOOR:// L802D6624
                if(map_get() == MAP_6F_GL_FP_LOBBY && !func_803203FC(UNKFLAGS1_8B_SANDCASTLE_OPEN_FP)){
                    func_802D4830(func_80326EEC(ACTOR_235_FP_ENTANCE_DOOR), SFX_18_BIGBUTT_SLIDE, 0.5f);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_226_GV_ENTRANCE:// L802D6674
                if(map_get() == MAP_6E_GL_GV_LOBBY && !func_803203FC(UNKFLAGS1_87_SANDCASTLE_OPEN_GV)){
                    func_802D485C(func_80326EEC(ACTOR_226_GV_ENTRANCE), SFX_3EC_CCW_DOOR_OPENING, 0.8f, 15000);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_228_INVISIBLE_WALL:// L802D66CC
                if(!func_803203FC(UNKFLAGS1_8C_SANDCASTLE_OPEN_MMM)){
                FUNC_8030E624(SFX_6B_LOCKUP_OPENING, 0.6f, 32000);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_20F_RBB_ENTRANCE_DOOR:// L802D66F8
                if(map_get() == MAP_77_GL_RBB_LOBBY && !func_803203FC(UNKFLAGS1_90_SANDCASTLE_OPEN_RBB)){
                    func_802D4830(func_80326EEC(ACTOR_20F_RBB_ENTRANCE_DOOR), SFX_9A_MECHANICAL_CLOSING, 0.5f);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
        }
    }
}

void func_802D6750(void){
    timedFunc_set_0(0.4f, func_802D6494);
}

enum map_e func_802D677C(enum map_e arg0){
    s32 out;
    if(arg0 == -1)
        return D_80367684;
    out = D_80367684;
    D_80367684 = arg0;
    return out;
}

s32 func_802D67AC(s32 arg0){
    s32 out;
    if(arg0 == -1)
        return D_8036768C;
    out = D_8036768C;
    D_8036768C = arg0;
    return out;
}

enum actor_e func_802D67DC(enum actor_e arg0){
    s32 out;
    if(arg0 == -1)
        return D_803676A0;
    out = D_803676A0;
    D_803676A0 = arg0;
    return out;
}

s32 func_802D680C(s32 arg0){
    s32 out;
    if(arg0 == -1)
        return D_80367690;
    out = D_80367690;
    D_80367690 = arg0;
    return out;
}

s32 func_802D683C(s32 arg0){
    s32 out;
    if(arg0 == -1)
        return D_80367688;
    out = D_80367688;
    D_80367688 = arg0;
    return out;
}

int func_802D686C(void){
    if(func_803203FC(0x1E)){
        return FALSE;
    } 
    return map_get() == D_80367684;
}

int func_802D68B4(void){
    return func_802D686C() || func_803203FC(0x21);
}

//BREAK????

//set_hourglass_timer_seconds
void func_802D68F0(s32 seconds){
    item_set(ITEM_0_HOURGLASS_TIMER, seconds*60 - 1);
}

//hide_hourglass_timer
void func_802D6924(void){
    item_set(ITEM_6_HOURGLASS, 0);
}

//update_has_entered_level_flags
void func_802D6948(void){
    switch(map_get()){
        case MAP_2_MM_MUMBOS_MOUNTAIN:
            func_80320004(BKPROG_B0_HAS_ENTERED_MM, TRUE);
            break;
        case MAP_7_TTC_TREASURE_TROVE_COVE:
            func_80320004(BKPROG_B2_HAS_ENTERED_TTC, TRUE);
            break;
        case MAP_B_CC_CLANKERS_CAVERN:
            func_80320004(BKPROG_B8_HAS_ENTERED_CC, TRUE);
            break;
        case MAP_D_BGS_BUBBLEGLOOP_SWAMP:
            func_80320004(BKPROG_B1_HAS_ENTERED_BGS, TRUE);
            break;
        case MAP_12_GV_GOBIS_VALLEY:
            func_80320004(BKPROG_B3_HAS_ENTERED_GV, TRUE);
            break;
        case MAP_1B_MMM_MAD_MONSTER_MANSION:
            func_80320004(BKPROG_B7_HAS_ENTERED_MMM, TRUE);
            break;
        case MAP_27_FP_FREEZEEZY_PEAK:
            func_80320004(BKPROG_B6_HAS_ENTERED_FP, TRUE);
            break;
        case MAP_31_RBB_RUSTY_BUCKET_BAY:
            func_80320004(BKPROG_B4_HAS_ENTERED_RBB, TRUE);
            break;
        case MAP_40_CCW_HUB:
            func_80320004(BKPROG_B5_HAS_ENTERED_CCW, TRUE);
            break;
    }
}

//has entered map and level
int func_802D6A38(enum map_e map_id){
    switch(map_id){
        case MAP_2_MM_MUMBOS_MOUNTAIN:
            return func_8031FF1C(BKPROG_B0_HAS_ENTERED_MM);
        case MAP_7_TTC_TREASURE_TROVE_COVE:
            return func_8031FF1C(BKPROG_B2_HAS_ENTERED_TTC);
        case MAP_B_CC_CLANKERS_CAVERN:
            return func_8031FF1C(BKPROG_B8_HAS_ENTERED_CC);
        case MAP_D_BGS_BUBBLEGLOOP_SWAMP:
            return func_8031FF1C(BKPROG_B1_HAS_ENTERED_BGS);
        case MAP_12_GV_GOBIS_VALLEY:
            return func_8031FF1C(BKPROG_B3_HAS_ENTERED_GV);
        case MAP_1B_MMM_MAD_MONSTER_MANSION:
            return func_8031FF1C(BKPROG_B7_HAS_ENTERED_MMM);
        case MAP_27_FP_FREEZEEZY_PEAK:
            return func_8031FF1C(BKPROG_B6_HAS_ENTERED_FP);
        case MAP_31_RBB_RUSTY_BUCKET_BAY:
            return func_8031FF1C(BKPROG_B4_HAS_ENTERED_RBB);
        case MAP_40_CCW_HUB:
            return func_8031FF1C(BKPROG_B5_HAS_ENTERED_CCW);
    }
    return FALSE;
}
