#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802BEA4C(f32[3], f32[3], f32, f32[3]);
extern void func_802BEBE8(f32[3], f32[3], f32, f32[3]);
extern void func_802BEAAC(f32[3], f32[3], f32, f32[3], f32[3], f32[3], f32[3]);
extern BKCollisionTri *func_80320B98(f32[3], f32[3], f32[3], s32);
f32 func_802BB938(f32[3], f32[3]);
f32 func_802BBD48(void);
f32 func_802BBEA4(f32 arg0[3], f32 arg1[3], f32 arg2, s32 arg3, s32 arg4);

/* .data */
extern s16 D_803657E0[];

/* .bss */
s32 D_8037D8C0;
u8 D_8037D8C4;
u8 D_8037D8C5;
u8 D_8037D8C6;
f32 D_8037D8C8;
f32 D_8037D8CC;
struct {
    s32 unk0[6];
    f32 unk18[6];
    u8 unk30;
    u8 unk31;
}D_8037D8D0;
f32 D_8037D908[3];
f32 D_8037D918[3];

/* .code */
bool func_802BB720(s32 arg0, f32 arg1[3], f32 arg2[3], s32 *arg3) {
    f32 temp_f6;
    s16 *temp_v0;

    if (arg0 == 0x65) {
        arg0 = 0x1A;
    }
    if (arg0 >= 0x80) {
        arg1[0] = (f32) func_802E4AE8(arg0);
        arg1[1] = (f32) func_802E4AFC(arg0);
        arg1[2] = (f32) func_802E4B10(arg0);
        arg2[0] = 0.0f;
        arg2[1] = mlNormalizeAngle((f32) func_802E4B24(arg0) - 180.0f);
        arg2[2] = 0.0f;
        return TRUE;
    }
    if ((arg0 >= 0x5B) && (arg0 < 0x63)) {
        arg0 -= 0x40;
    }
    temp_v0 = func_803049CC(D_803657E0[arg0], 0);
    if (temp_v0 != NULL) {
        nodeprop_getPosition(temp_v0, arg1);
        *arg3 = func_80304DB8(temp_v0);
        temp_f6 = (f32) func_80304DA8(temp_v0) - 180.0f;
        arg2[0] = 0.0f;\
        arg2[1] = mlNormalizeAngle(temp_f6);\
        arg2[2] = 0.0f;
        return TRUE;
    }
    return FALSE;
}


bool func_802BB884(f32 arg0[3], f32 *arg1) {
    f32 sp24[3];
    f32 sp18[3];

    if (!player_is_present() || !func_8028F070() || !func_8028F150()) {
        return FALSE;
    }
    player_getPosition(sp24);
    sp24[1] += 50.0f;
    ml_vec3f_diff_copy(sp18, arg0, sp24);
    *arg1 = gu_sqrtf(sp18[0]*sp18[0] + sp18[1]*sp18[1] + sp18[2]*sp18[2]);
    return TRUE;
}


f32 func_802BB938(f32 arg0[3], f32 arg1[3]) {
    f32 sp3C;
    f32 phi_f20;
    f32 phi_f12;
    f32 phi_f14;

    phi_f14 = func_802BBEA4(arg0, arg1, 350.0f, 1, 0x800000);
    phi_f12 = (D_8037D8D0.unk31) ? 25.0f : 10.0f;
    phi_f20 = max_f(phi_f12, phi_f14* 0.8 - 15.0);
    func_802BAC58();

    if (func_802BB884(arg0, &sp3C)) {
        phi_f20 = min_f(phi_f20, ml_map_f(sp3C, 90.0f, 450.0f, 20.0f, 240.0f));
    }

    if (65.0 < phi_f20 && func_802BAC1C()) {
        phi_f20 = 65.0f;
    }

    if (gctransition_8030BDAC()) {
        phi_f20 = min_f(phi_f20, gctransition_8030BD88() * 0.8);
    }
    return phi_f20;
}

void func_802BBA84(void) {
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    func_80309998(sp30, sp24);
    func_8024C5CC(sp54);
    func_8024C764(sp3C);
    func_8024C5A8(sp48);
    D_8037D8CC = (f32) func_8033EAF8(sp30, sp24, sp54, sp48);
    D_8037D8CC += 100.0f;
    if (D_8037D8CC < 1000.0f) {
        D_8037D8CC = 1000.0f;
    }
    if (20000.0 < D_8037D8CC) {
        D_8037D8CC = 20000.0f;
    }
    if (level_get() == LEVEL_D_CUTSCENE) {
        D_8037D8C8 = D_8037D8CC * 0.0078125;
        return;
    }
    if (map_get() == MAP_91_FILE_SELECT) {
        D_8037D8C8 = D_8037D8CC * 0.0078125;
        return;
    }
    D_8037D8C8 = D_8037D8CC * 0.0078125;
    if (D_8037D8C8 < 10.0) {
        D_8037D8C8 = 10.0f;
        return;
    }
    D_8037D8C8 = min_f(D_8037D8C8, func_802BB938(sp54, sp3C));
}

void func_802BBC58(s32 arg0) {
    switch (D_8037D8C0) {
        case 3:
            func_802BAD00();
            break;
        case 4:
            func_802BED00();
            break;
        case 1:
        case 2:
            break;
    }
    switch (arg0) {
        case 3:
            func_802BACD0(arg0);
            break;
        case 4:
            func_802BEC60(arg0);
            break;
        case 1:
        case 2:
            break;
    }
    D_8037D8C0 = arg0;
}


void func_802BBD0C(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    func_802BEE2C(gdl, mptr, vptr);
}

void func_802BBD2C(f32 *arg0, f32 *arg1){
    *arg0 = D_8037D8C8;
    *arg1 = D_8037D8CC;
}

f32 func_802BBD48(void) {
    f32 min;
    s32 val;
    s32 i;

    min = 1000.0f;
    for(i = 0; i < 6; i++){
        val = (s32)D_8037D8D0.unk18[i];
        if(val < min){
            min = val;
        }
    }
    return min;
}

f32 func_802BBEA4(f32 arg0[3], f32 arg1[3], f32 arg2, s32 arg3, s32 arg4) {
    f32 sp58[6][3];
    f32 sp4C[3];
    f32 phi_f2;
    f32 sp3C[3];
    BKCollisionTri *sp38;
    s32 i;

    if (arg3 == 0) {
        return func_802BBD48();
    }
    func_802BEA4C(arg1, arg0, arg2, sp58[0]);
    func_802BEBE8(arg1, arg0, arg2, sp58[3]);
    func_802BEAAC(arg1, arg0, arg2, sp58[1], sp58[4], sp58[2], sp58[5]);
    ml_vec3f_copy(sp4C, sp58[D_8037D8D0.unk30]);
    sp38 = func_80320B98(arg0, sp4C, sp3C, arg4);
    if (sp38 != NULL) {
        phi_f2 = ml_vec3f_distance(arg0, &sp4C);
        D_8037D8D0.unk0[D_8037D8D0.unk30] = sp38->flags;
    } else {
        phi_f2 = arg2;
        D_8037D8D0.unk0[D_8037D8D0.unk30] = 0;
    }
    D_8037D8D0.unk18[D_8037D8D0.unk30] = phi_f2;
    D_8037D8D0.unk30++;
    if (D_8037D8D0.unk30 >= 6) {
        D_8037D8D0.unk30 = 0;
    }
    
    D_8037D8D0.unk31 = FALSE;

    for(i = 0; i < 6; i++){
        if (D_8037D8D0.unk0[i]){
            if(D_8037D8D0.unk0[i] & 0x1E0000){
                D_8037D8D0.unk31 = TRUE;
            }
            else{
                 D_8037D8D0.unk31 = FALSE;
                 break;
            }
        }
    }
    return func_802BBD48();
}

void func_802BC044(void) {
    s32 i;

    D_8037D8C4 = 0;
    D_8037D8C5 = 0;
    D_8037D8C6 = 0;
    D_8037D8D0.unk31 = 0;
    D_8037D8D0.unk30 = 0;
    for(i = 0; i < 6; i++){
        D_8037D8D0.unk18[i] = 1000.0f;
        D_8037D8D0.unk0[i] = 0;
    }
    func_802BAC10();
    func_802BE940();
    func_802BCBD4();
    func_802BEF78();
    func_802BB2A8();
    D_8037D8C0 = 0;
    func_802BBC58(2);
}


void func_802BC10C(void){
    func_802BB2A0();
    func_802BBC58(1);
    func_802BCD30();
    func_802BEF70();
    func_802BABD8();
}

void func_802BC14C(void){
    f32 sp2C[3];
    f32 sp20[3];
    s32 v0;

    v0 = D_8037D8C0;
    if(!D_8037D8C5 && !D_8037D8C6){
        v0 = 0;
    }

    switch(v0){
        case 2:
            func_802BCEC4();
            break;
        case 3:
            func_802BADAC();
            break;
        case 4:
            func_802BED30();
            break;
    }

    func_8024C5CC(sp2C);
    func_8024C764(sp20);
    func_802BB4D8(sp2C, sp20);
    func_8024CD88(sp2C);
    func_8024CE18(sp20);
    func_8024CFD4();
    func_802BEFB0();
    func_802BBA84();
}

void func_802BC21C(s32 arg0, s32 arg1){
    if(arg1 == 2){
        D_8037D8C5 = TRUE;
    }
    else{
        D_8037D8C5 = FALSE;
    }
}

s32 func_802BC248(void){
    return D_8037D8C0;
}

void func_802BC254(void){
    D_8037D8C6 = 1;
    func_802BC14C();
    D_8037D8C6 = 0;
}

void func_802BC280(void){
    func_802BC254();
}

Actor *func_802BC2A0(f32 position[3], f32 rotation[3]){
    return func_80328230(0x66, position, rotation);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_34790/func_802BC2CC.s")
#else
void func_802BC2CC(s32 arg0) {
    f32 *sp24;
    f32 *sp20;
    s32 sp1C;
    
    sp24 = &D_8037D908;
    sp20 = &D_8037D918;
    if (func_803203FC(0xE) != 0) {
        func_80347A14(0);
    }
    if (func_80320454(0xE, 0) || func_802D686C() || (arg0 == 0x63) || !func_802BB720(arg0, D_8037D908, D_8037D918, &sp1C)) {
        if (D_8037D8C0 == 2) {
            func_802BE794();
        }
        func_802BC254();
        func_802BC254();
        return;
    }
    if (D_8037D8C0 == 2) {
        func_802BE894(D_8037D918, D_8037D908);
    }
    func_8024CD88(D_8037D908);
    func_8024CE18(D_8037D918);
    func_8024CFD4();
    func_802C3D3C(func_802BC2A0, D_8037D908, D_8037D918);
    if (D_8037D8C0 == 2) {
        func_802BE720();
        if (sp1C != 0x63) {
            func_802BC254();
            func_802BC254();
        }
    }
}
#endif

bool func_802BC428(void){
    return D_8037D8C6;
}

void func_802BC434(f32 arg0[3], f32 arg1[3], f32 arg2[3]) {
    func_8025727C(arg1[0], arg1[1], arg1[2], arg2[0], arg2[1], arg2[2], &arg0[0], &arg0[1]);
    arg0[0] = mlNormalizeAngle(-arg0[0]);
    arg0[2] = 0.0f;
}
