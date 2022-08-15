#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "SnS.h"

/* extern */
extern void func_802D6310(f32, enum map_e, s32, s32, enum bkprog_e);

/* .h */
void func_8038B5B4(void);


typedef struct {
    u8 *unk0;
    u8 unk4;
    u8 unk5;
    s16 unk6;
} struct_ttc_3E30_s;

typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    f32 unk4;
}Struct_TTC_3E30_1;

typedef struct {
    s16 unk0;
    s16 unk2;
}Struct_TTC_3E30_2;

s32 func_8038B778(void);

extern s32 D_8038C980;
extern Struct_TTC_3E30_1 D_8038C984[];
extern struct_ttc_3E30_s D_8038CA6C[];
extern u8 D_8038CC78;
extern Struct_TTC_3E30_2 D_8038CC7C[];
extern s32 D_8038CAD4;
extern struct_ttc_3E30_s D_8038CAD8[];
extern u8 D_8038CF0C[] = "j4663n86pink";
extern u8 D_8038CF1C[] = "knip68n3664j";


extern struct{
    BKModel *unk0;
    BKModel *unk4;
    u8  unk8;
    u8  unk9;
    u8  unkA;
    u8  padB[1];
    f32 unkC;
    u8  unk10;
} D_8038D720;



/* .code */
void func_8038A220( s32 arg0, BKVtxRef *vtx_ref, Vtx *vtx, s32 arg2){
    vtx->v.ob[1] += 2;
}

void func_8038A23C( s32 arg0, BKVtxRef *vtx_ref, Vtx *vtx, s32 arg2){
    vtx->v.ob[1] += 0xf0;
}

void func_8038A258(s32 arg0) {
    if (arg0 == 1) {
        if (func_803203FC(2)) {
            item_set(ITEM_0_HOURGLASS_TIMER, 3000 - 1);
        } else {
            item_set(ITEM_0_HOURGLASS_TIMER, 6000 - 1);
        }
        item_set(ITEM_6_HOURGLASS, TRUE);
    }
    if (D_8038D720.unk10 == 1) {
        item_set(ITEM_6_HOURGLASS, FALSE);
    }
    D_8038D720.unk10 = arg0;
}

Struct_TTC_3E30_1 *func_8038A2DC(s32 mesh_id) {
    Struct_TTC_3E30_1 *i_ptr;

    for(i_ptr = D_8038C984; i_ptr->unk0 != 0; i_ptr++){
        if(i_ptr->unk0 == mesh_id){
            return i_ptr;
        }
    }
    return NULL;
}

void func_8038A328(void) {
    Struct_TTC_3E30_1 *i_ptr;

    for(i_ptr = D_8038C984; i_ptr->unk0 != 0; i_ptr++){
        i_ptr->unk3 = 2;
        i_ptr->unk4 = 0.0f;
    }
    mapSpecificFlags_set(1, FALSE);
}

void func_8038A37C(s32 arg0, BKVtxRef *ref, Vtx *dst, s32 arg3) {
    Struct_TTC_3E30_1 *ptr = (Struct_TTC_3E30_1 *) arg3;
    f32 temp_f2;

    if (ptr->unk4 < 0.5) {
        temp_f2 = (ptr->unk4 / 0.5);
        dst->v.cn[0] = (ref->v.v.cn[0] - 0xFF) * temp_f2 + 255.0f;
        dst->v.cn[1] = ref->v.v.cn[1] * temp_f2;
        dst->v.cn[2] = ref->v.v.cn[2] * temp_f2;
    }
    else{
        dst->v.cn[0] = ref->v.v.cn[0];
        dst->v.cn[1] = ref->v.v.cn[1];
        dst->v.cn[2] = ref->v.v.cn[2];
        ptr->unk3 = 2;
    }
}

void func_8038A5D8(Struct_TTC_3E30_1 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg0->unk3;
    arg0->unk3 = arg1;
    arg0->unk4 = 0.0f;
    if ((arg1 == 1) && (temp_v0 != arg1)) {
        func_8025A6EC(COMUSIC_2C_BUZZER, 32000);
    }
}

void func_8038A618(s32 arg0, BKVtxRef *ref, Vtx *dst, s32 arg3) {
    Struct_TTC_3E30_1 *ptr = (Struct_TTC_3E30_1 *) arg3;
    f32 temp_f12;


    if (ptr->unk4 <= 0.5) {
        temp_f12 = (ptr->unk4 / 0.5);
        dst->v.cn[0] = ref->v.v.cn[0] * (1.0f - temp_f12);
        dst->v.cn[1] = 0xFF;
        dst->v.cn[2] = ref->v.v.cn[2] * (1.0f - temp_f12);
    }
    if (ptr->unk4 >= 0.5) {
        ptr->unk3 = 4;
    }
}

void func_8038A7DC(s32 arg0, BKVtxRef *ref, Vtx *dst, s32 arg3){
    Struct_TTC_3E30_1 *ptr = (Struct_TTC_3E30_1 *) arg3;
    f32 temp_f2;

    if (ptr->unk4 < 0.5) {
        temp_f2 = (ptr->unk4 / 0.5);
        dst->v.cn[0] = (ref->v.v.cn[0] - 0xFF) * temp_f2 + 255.0f;
        dst->v.cn[1] = (ref->v.v.cn[1] - 0xFF) * temp_f2 + 255.0f;
        dst->v.cn[2] = ref->v.v.cn[2] * temp_f2;
    }
    else{
        dst->v.cn[0] = ref->v.v.cn[0];
        dst->v.cn[1] = ref->v.v.cn[1];
        dst->v.cn[2] = ref->v.v.cn[2];
        ptr->unk3 = 2;
    }
}

void func_8038AA2C(void) {
    f32 temp_f20;
    Struct_TTC_3E30_1 *var_s0;

    temp_f20 = time_getDelta();
    for(var_s0 = D_8038C984; var_s0->unk0 != 0; var_s0++){
        var_s0->unk4 += temp_f20;
        if (var_s0->unk3 == 1) {
            func_8033F120(D_8038D720.unk0, var_s0->unk0, func_8038A37C, (s32)var_s0);
        } else if (var_s0->unk3 == 3) {
            func_8033F120(D_8038D720.unk0, var_s0->unk0, func_8038A618, (s32)var_s0);
        } else if (var_s0->unk3 == 5) {
            func_8033F120(D_8038D720.unk0, var_s0->unk0, func_8038A7DC, (s32)var_s0);
        }
    }
}

void func_8038AB44(void){
    D_8038C980 = func_8038B600();
}

u32 func_8038AB68(s32 arg0){
    if(func_8031FF1C(0xAC + arg0)){
        return 1 << arg0;
    }
    return 0;
}

void func_8038ABA0(u32 arg0){
    int i;
    func_80356520(0xC2);
    if(arg0 & 0x400){
        func_80356560(0xC5);
    }
    func_803204E4(0x78, 0);
    for(i = 4; i < 0xb; i++){
        if( arg0 & (1 << i)){
            func_803204E4(0x93 + i, TRUE);
            func_803204E4(0x78, TRUE);
        }
        else{
            func_803204E4(0x93 + i, FALSE);
        }
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038AC48.s")
#else
void func_8038AC48(Struct_TTC_3E30_1 *arg0) {
    s32 sp3C;
    s16 temp_a0;
    s16 temp_v0;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s1;
    s32 temp_s5;
    s32 temp_t9;
    s32 temp_v1;
    s32 phi_s0;
    u8 *phi_v0;
    s32 phi_s0_2;
    struct_ttc_3E30_s *phi_s2;
    s32 phi_s1;
    s32 phi_s7;
    s32 phi_s1_2;
    s32 phi_s1_3;
    s32 phi_s7_2;
    s32 phi_s1_4;
    s32 phi_s1_5;

    temp_s5 = func_803203FC(2);
    sp3C = func_8038BD10(arg0);
    phi_s7 = 0;
    for(phi_s2 = &D_8038CA6C; phi_s2->unk0 != 0; phi_s2++){
        phi_s0 = 1;
        phi_s1_2 = 0;
        if (D_8038D720.unk8 == 0) {
            phi_s1_2 = 1;
        }
        phi_s1 = phi_s1_2;
        phi_s1_5 = phi_s1_2;
        if (temp_s5 == 0) {
            do {
                temp_s0 = phi_s0 + 1;
                temp_s1 = phi_s1_5 | func_8038AB68(phi_s0);
                phi_s0 = temp_s0;
                phi_s1_4 = temp_s1;
                phi_s1_5 = temp_s1;
            } while (temp_s0 < 4);
            phi_v0 = &D_8037DCC0;
            phi_s0_2 = 0;
            do {
                phi_s1_3 = phi_s1_4;
                if (*phi_v0 != 0) {
                    phi_s1_3 = phi_s1_4 | (0x10 << phi_s0_2);
                }
                temp_s0_2 = phi_s0_2 + 1;
                phi_v0 += 1;
                phi_s0_2 = temp_s0_2;
                phi_s1 = phi_s1_3;
                phi_s1_4 = phi_s1_3;
            } while (temp_s0_2 != 7);
            if (func_803203FC(0x78)) {
                phi_s1 = phi_s1_3 | 0x800;
            }
        }
        if ((phi_s2->unk4 & phi_s1) != 0) {
            if ((func_8038BF68() != 0) && (temp_s5 == 0)) {
                phi_s2->unk6 = 0;
                func_8038A258(2);
            }
            temp_v0 = phi_s2->unk6;
            if (arg0->unk2 == *(phi_s2->unk0 + temp_v0)) {
                phi_s2->unk6 = (s16) (temp_v0 + 1);
                if (func_8038BF68() != 0) {
                    phi_s2->unk6 = 0;
                    phi_s7_2 = 1;
                } else {
                    if ((phi_s2->unk4 & 0xFFE) != 0) {
                        func_8038A258(2);
                        func_8038A5D8(arg0, 5);
                    } else {
                        func_8038A5D8(arg0, 3);
                    }
                    if (*(phi_s2->unk0 + phi_s2->unk6) == 0) {
                        func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 32000);
                        if (temp_s5 != 0) {
                            item_set(ITEM_6_HOURGLASS, FALSE);
                            func_803204E4(3, 0);
                            func_803204E4(5, 1);
                            func_8038A258(2);
                            phi_s7_2 = 1;
                        } else {
                            temp_a0 = phi_s2->unk4;
                            if ((temp_a0 & 1) != 0) {
                                D_8038D720.unk8 = 2U;
                                D_8038D720.unkC = 0.0f;
                                mapSpecificFlags_set(1, TRUE);
                                func_80320004(0xFA, TRUE);
                                func_8030E2C4(D_8038D720.unk9);
                                func_8038A258(2);
                            } else if ((temp_a0 & 0xE) != 0) {
                                temp_t9 = (s32) (phi_s2 - &D_8038CA6C) >> 3;
                                func_8035644C(temp_t9 + 0xBD, 1);
                                temp_v1 = temp_t9 - 1;
                                switch (temp_v1) { /* irregular */
                                default:
                                    break;
                                case 0:
                                    func_80346448(ITEM_D_EGGS);
                                    func_802FAFAC(ITEM_D_EGGS, COMUSIC_C_EGG_COLLECTED);
                                    break;
                                case 1:
                                    func_80346448(ITEM_F_RED_FEATHER);
                                    func_802FAFAC(ITEM_F_RED_FEATHER, COMUSIC_B_RED_FEATHER_COLLECTED);
                                    break;
                                case 2:
                                    func_80346448(ITEM_10_GOLD_FEATHER);
                                    func_802FAFAC(ITEM_10_GOLD_FEATHER, COMUSIC_14_GOLD_FEATHER_COLLECTED);
                                    break;
                                }
                            } else {
                                if ((temp_a0 & 0xFF0) != 0) {
                                    func_8038ABA0(temp_a0, 1);
                                }
                            }
                            phi_s7_2 = 1;
                        }
                    } else {
                        func_8025A6EC(COMUSIC_2B_DING_B, 0x6D60);
                        phi_s7_2 = 1;
                    }
                }
            } else if (sp3C != 0) {
                phi_s7_2 = 1;
            }
        }
    if ((func_8038BF68() == 0) && (phi_s7 == 0) && (D_8038D720.unk8 == 0)) {
        func_8038A5D8(arg0, 1);
    }
}
#endif



void func_8038AFC8(void){
    struct_ttc_3E30_s *iPtr;

    for(iPtr = D_8038CA6C; iPtr->unk0 != NULL; iPtr++){
        iPtr->unk6 = 0;
    }

    if(func_803203FC(2))
        strcpy(D_8038CA6C[0].unk0, D_8038CF0C);
    else
        strcpy(D_8038CA6C[0].unk0, D_8038CF1C);

    func_8038B5B4();
}

void func_8038B04C(void){
    if(D_8038D720.unk0){
        func_8038A258(0);
        func_8030DA44(D_8038D720.unk9);
        func_8030DA44(D_8038D720.unkA);
    }
}

void func_8038B094(void){
    void *sp2C;
    void *sp28;

    if( map_get() == MAP_7_TTC_TREASURE_TROVE_COVE
        && levelSpecificFlags_get(0x2)
    ){
        sp2C = func_8034C5AC(0x12C);
        if(sp2C){
            func_8034E71C(sp2C, -600, 0.0f);
        }
    }
    D_8038D720.unk0 = 0;
    if(map_get() != MAP_A_TTC_SANDCASTLE){
        func_8038AB44();
    }
    else{
        sp2C = func_8034C5AC(0x131);
        sp28 = func_8034C5AC(0x12C);
        if(levelSpecificFlags_get(5)){
            func_8034E71C(sp2C, -500, 10.0f);
            func_80324E38(0.0f, 3);
            timed_setCameraToNode(0.0f, 1);
            func_80324E88(2.0f);
            func_80324E38(2.0f, 0);
            func_803228D8();
            timedFunc_set_3(2.0f, (TFQM3) func_802E4078, MAP_7_TTC_TREASURE_TROVE_COVE, 1, 0);
        }
        else if(levelSpecificFlags_get(2) || func_803203FC(2)){
            func_8034E71C(sp2C, -500, 0.0f);
        }
        else{
            func_8034E71C(sp28, -500, 0.0f);
        }//L8038B1EC

        D_8038D720.unk0 = func_80309744(0);
        D_8038D720.unk4 = func_80309744(1);
        D_8038D720.unk8 = 0;
        D_8038D720.unk10 = 0;
        D_8038D720.unkC = 0.0f;

        D_8038D720.unk9 = func_8030D90C();
        func_8030DBB4(D_8038D720.unk9, 0.1f);
        sfxsource_setSfxId(D_8038D720.unk9, SFX_3EC_CCW_DOOR_OPENING);
        func_8030DD14(D_8038D720.unk9, 3);
        sfxsource_setSampleRate(D_8038D720.unk9, 28000);

        D_8038D720.unkA = func_8030D90C();
        sfxsource_setSfxId(D_8038D720.unkA, SFX_3_DULL_CANNON_SHOT);
        func_8030DD14(D_8038D720.unkA, 3);
        sfxsource_setSampleRate(D_8038D720.unkA, 0x7fff);
        func_8038A328();
        func_8038AFC8();

        if( jiggyscore_isCollected(JIGGY_10_TTC_SANDCASTLE)
            && !func_803203FC(2)
        ){
            func_8033F120(D_8038D720.unk4, 0x3C, func_8038A23C, 0);
            D_8038D720.unk8 = 3;
        }//L8038B2CC
        func_8038AB44();
        func_8038B5B4();
    }//L8038B2E0
}

void func_8038B2F0(void) {
    f32 sp2C[3];
    s32 mesh_id;
    f32 sp24;
    u8 temp_v0;
    Struct_TTC_3E30_1 *temp_v0_3;

    sp24 = time_getDelta();
    if (func_8038B778() == 3) {
        func_802C5A3C(-1);
    }
    if (D_8038D720.unk0 != 0) {
        func_8038AA2C();
        player_getPosition(sp2C);
        if ((D_8038D720.unk10 == 0) && func_803203FC(2) && func_803203FC(3)) {
            func_8038A258(1);
        }
        if ((D_8038D720.unk10 == 1) && item_empty(ITEM_0_HOURGLASS_TIMER)) {
            func_8038A258(2);
            if (func_803203FC(2)) {
                func_803204E4(3, FALSE);
                func_803204E4(5, FALSE);
            } else {
                func_8028F66C(BS_INTR_F);
            }
        }
        if ((D_8038D720.unk8 == 0) || (D_8038D720.unk8 == 3)) {
            if( (levelSpecificFlags_get(2) || func_803203FC(3)) 
                && (player_getActiveHitbox(0) == HITBOX_1_BEAK_BUSTER) 
                && func_8028F20C()
            ) {
                mesh_id = func_8033F3C0(D_8038D720.unk0, sp2C);
                if (mesh_id != 0) {
                    temp_v0_3 = func_8038A2DC(mesh_id);
                    if ((temp_v0_3 != NULL) && ((temp_v0_3->unk3 == 2) || (D_8038D720.unk8 == 3))) {
                        func_8038AC48(temp_v0_3);
                        if ((D_8038D720.unk8 == 0) && (D_8038D720.unk10 == 0) && (func_803203FC(2) == 0)) {
                            func_8038A258(1);
                        }
                    }
                }
            }
        } else if (D_8038D720.unk8 == 2) {
            D_8038D720.unkC = (f32) (D_8038D720.unkC + sp24);
            func_8033F120(D_8038D720.unk4, 0x3C, func_8038A220, 0);
            if (D_8038D720.unkC > 4.0f) {
                D_8038D720.unk8 = 3;
                func_8030E2C4(D_8038D720.unkA);
                func_8030E394(D_8038D720.unk9);
            }
        }
    }
}

bool func_8038B550(void){
    return NOT(D_8038D720.unk8 < 2);
}

void func_8038B564(s32 arg0, s32 arg1, enum map_e map_id, s32 arg3, s32 arg4){
    if(arg1 == D_8038CAD8[arg0].unk5){
        func_802D6310(1.0f, map_id, arg3, arg4, 0);
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038B5B4.s")
#else
void func_8038B5B4(void) {
    s32 i;

    for(i = 0; D_8038CAD8[i].unk0 != NULL; i++){
        D_8038CAD8[i].unk4 = 0;
    }
    D_8038CC78 = 0;
    func_8038AB44();
}
#endif


#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038B600.s")

void func_8038B6D4(s32 arg0, s32 arg1, s32 arg2, enum bkprog_e prog_id, s32 prog_val, s32 prog_bit_size, enum bkprog_e arg6){
    if( ((arg2 + 20 == D_8038CAD8[arg1].unk5) && func_803203FC(arg2))
        || arg0 == 3
    ){
        func_80320044(prog_id, prog_val, prog_bit_size);
        if(arg6){
            func_80320004(arg6, TRUE);
        }
    }
}

void func_8038B750(s32 arg0){
    func_80320044(0xfd, arg0, 2);
}

s32 func_8038B778(void){
    return func_8031FF44(0xFD, 2);
}

void func_8038B79C(s32 arg0, s32 arg1, s32 arg2, enum item_e item_id, s32 item_diff, s32 item_val) {
    if (((arg2 + 0x14) == D_8038CAD8[arg1].unk5) || (arg0 == 1)) {
        if (item_diff != 0) {
            func_803463D4(item_id, item_diff);
            return;
        }
        item_set(item_id, item_val);
    }
}

void func_8038B800(s32 arg0) {
    struct_ttc_3E30_s *sp30;
    s32 sp38;

    sp30 = &D_8038CAD8[arg0];
    sp38 = sp30->unk5 - 0x14;
    sns_set_item_and_update_payload(sp30->unk5, 1, 1);
    func_8038B564(arg0, 1, MAP_61_CCW_WINTER_NABNUTS_HOUSE, 0x83, 0x1B);
    func_8038B564(arg0, 2, MAP_3F_RBB_CAPTAINS_CABIN, 0x84, 0x1C);
    func_8038B564(arg0, 3, MAP_2C_MMM_BATHROOM, 0x85, 0x1D);
    func_8038B564(arg0, 4, MAP_12_GV_GOBIS_VALLEY, 0x86, 0x1E);
    func_8038B564(arg0, 5, MAP_7_TTC_TREASURE_TROVE_COVE, 0x87, 0x1F);
    func_8038B564(arg0, 6, MAP_1D_MMM_CELLAR, 0x88, 0x20);
    func_8038B564(arg0, 7, MAP_7F_FP_WOZZAS_CAVE, 0x89, 0x21);
    if (sp30->unk5 >= 0x14) {
        func_8030E58C(SFX_2B_BULL_MOO_1, 1.5f);
        func_803204E4(0x65, 1);
        func_803204E4(sp38, 1);
    }
    func_8038B6D4(0, arg0, 0x6C, 0x60, 5, 3, 0x33);
    func_8038B6D4(0, arg0, 0x6D, 0x63, 7, 3, 0x34);
    func_8038B6D4(0, arg0, 0x6E, 0x66, 8, 4, 0x35);
    func_8038B6D4(0, arg0, 0x6F, 0x6A, 9, 4, 0x36);
    func_8038B6D4(0, arg0, 0x70, 0x6E, 0xA, 4, 0x37);
    func_8038B6D4(0, arg0, 0x71, 0x72, 0xC, 4, 0x38);
    func_8038B6D4(0, arg0, 0x72, 0x76, 0xF, 4, 0x39);
    func_8038B79C(0, arg0, 0x94, ITEM_15_HEALTH_TOTAL, 0, 8);
    func_8038B79C(0, arg0, 0x77, ITEM_14_HEALTH, 0, item_getCount(ITEM_15_HEALTH_TOTAL));
    func_8038B79C(0, arg0, 0x95, ITEM_1C_MUMBO_TOKEN, 0, 99);
    if (sp38 == 0x81) {
        func_80320004(0x53, 1);
        func_80320004(0x54, 1);
    }
    func_8038B5B4();
}

void func_8038BB10(ActorMarker *caller, enum asset_e text_id, s32 arg2) {
    if (arg2 == 1) {
        func_8038B750(3);
        func_8038B800(D_8038CAD4);
        func_80311480(0xFBF, 0xC, NULL, NULL, NULL, NULL);
        func_8033D0FC(func_802C5A30());
        func_8033CFD4(func_802C5A30());
        func_802C5A3C(-1);
        return;
    }
    func_8038B5B4();
}

void func_8038BBA0(s32 arg0) {
    s32 i;

    if ((s32) D_8038CAD8[arg0].unk5 >= 0x14) {
        if (func_803203FC(D_8038CAD8[arg0].unk5 - 0x14)) {
            func_8038B5B4();
            return;
        }
        for( i = 0; D_8038CC7C[i].unk0 != 0; i++){
            if ((D_8038CAD8[arg0].unk5 >= D_8038CC7C[i].unk0) && (D_8038CC7C[i].unk2 >= D_8038CAD8[arg0].unk5)) {
                switch (func_8038B778()) {
                    case 0:
                        func_8038B750(1);
                        func_8038B800(arg0);
                        func_8038B5B4();
                        return;
                    case 1:
                        func_8038B750(2);
                        func_8038B800(arg0);
                        func_8038B5B4();
                        func_80311480(0xFBE, 0xC, NULL, NULL, NULL, NULL);
                        return;
                    case 2:
                        D_8038CAD4 = arg0;
                        func_80311480(0xE38, 0xC, NULL, NULL, func_8038BB10, NULL);
                        return;
                }
                return;
            }
        }
    }
    func_8038B800(arg0);
    func_8038B5B4();
}

extern f32 D_8038D68C;
extern f32 D_8038D690;

bool func_8038BD10(Struct_TTC_3E30_1 *arg0);
#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038BD10.s")

bool func_8038BF68(void){
    return *(u8*)(D_8038CAD8[0].unk4 + (s32)D_8038CAD8[0].unk0) == 0;
}


int ttc_func_8038BF8C(void){
    return func_8038B600() == D_8038C980;
}
