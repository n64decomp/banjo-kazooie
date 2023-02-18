#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern bool func_80245314(f32[3], f32[3], f32, f32, u32);
extern int func_80244D94(f32[3], f32[3], f32[3], u32, f32);
extern int func_8024575C(f32[3], f32[3], f32, f32[3], s32, u32);
extern void func_8024C510(f32);
extern f32 func_80258708(f32[3], f32[3]);
extern f32 func_80259198(f32, f32);
extern f32 func_8028E82C(void);
extern f32 player_getYaw(void);
extern f32 func_8028EF88(void);
extern int func_80320DB0(f32[3], f32, f32[3], u32);
extern f32 ml_dotProduct_vec3f(f32[3], f32[3]);

typedef struct {
    f32* unk0;
    s32 unk4;
}Struct_core2_356B0_0;

void func_802BD0D8(s32 arg0);
void func_802BD334(f32 arg0[3]);
void func_802BD384(f32 arg0[3]);
void func_802BD780(f32[3], f32[3], f32, f32, f32, f32);
void func_802BD840(void);
void func_802BD870(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
f32  func_802BD8C8(void);
void func_802BD8EC(f32 arg0);

f32 D_80365CD0[] = {0.0f};
f32 D_80365CD4[] = {0.0f, -25.0f, 25.0f, -50.0f, 50.0f, -80.0f, 80.0f, -120.0f, 120.0f, -140.0f, 140.0f};
f32 D_80365D00[] = {0.0f, 20.0f, 40.0f, 60.0f, 80.0f, 100.0f, 120.0f, 140.0f, 160.0f, 180.0f, 200.0f, 220.0f, 240.0f, 260.0f, 280.0f, 300.0f, 320.0f, 340.0f};
Struct_core2_356B0_0 D_80365D48 = {D_80365CD0, 1};
Struct_core2_356B0_0 D_80365D50 = {D_80365CD4, 11};
Struct_core2_356B0_0 D_80365D58 = {D_80365D00, 18};


/* .bss */
s32 D_8037D940;
f32 D_8037D948[3];
f32 D_8037D958[3];
f32 D_8037D968[3];
f32 D_8037D96C;
f32 D_8037D974;
f32 D_8037D978;
f32 D_8037D97C;
f32 D_8037D980;
f32 D_8037D984;
f32 D_8037D988;
f32 D_8037D98C;
f32 D_8037D990;
f32 D_8037D994;
f32 D_8037D998;
f32 D_8037D99C;
f32 D_8037D9A0;
f32 D_8037D9A8[3];
f32 D_8037D9B8[3];
f32 D_8037D9C8[3];
f32 D_8037D9D4;
f32 D_8037D9D8;
f32 D_8037D9E0[3];
f32 D_8037D9EC;
f32 D_8037D9F0;
u8 D_8037D9F4;
u8 D_8037D9F5;
u8 D_8037D9F6;
u8 D_8037D9F7;

/* .code */
bool func_802BC640(f32 arg0[3], f32 arg1[3], f32 arg2, s32 arg3) {
    f32 sp9C[3];
    Struct_core2_356B0_0 *phi_s4;
    f32 *phi_s0;
    f32 sp88[3];
    f32 phi_f20;
    f32 sp78[3];
    f32 phi_f26;

    phi_f26 = ml_max_f(150.0f, arg2 - 100.0f);
    switch (arg3) {
    case 1:
        phi_s4 = &D_80365D50;
        break;
    case 2:
    case 3:
        phi_s4 = &D_80365D58;
        break;
    default:
    case 0:
        phi_s4 = &D_80365D48;
        phi_f26 = 150.0f;
        break;
    }
    for(phi_s0 = phi_s4->unk0; phi_s0 < phi_s4->unk0 + phi_s4->unk4; phi_s0++){
        phi_f20 = *phi_s0;
        if (arg3 == 3) {
            phi_f20 = -phi_f20;
        }
        ml_vec3f_scale_copy(sp9C, arg1, -arg2);
        ml_vec3f_yaw_rotate_copy(sp9C, sp9C, phi_f20);
        ml_vec3f_add(sp78, arg0, sp9C);
        func_80244D94(arg0, sp78, sp88, 0x9E0000, 40.0f);
        func_8024575C(arg0, sp78, 40.0f, sp88, 4, 0x9E0000);
        if (phi_f26 < func_80258708(arg0, sp78)) {
            func_802BD334(sp78);
            ml_vec3f_clear(D_8037D9C8);
            ml_vec3f_clear(D_8037D9E0);
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_802BC84C(s32 arg0){
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];
    f32 sp1C;

    if(player_getTransformation() == TRANSFORM_3_PUMPKIN){
        player_getPosition(sp50);
        sp50[1] += 76.0f;
    }
    else{
        func_8028EC64(sp50);
    }
    func_802BD384(sp38);
    ml_vec3f_diff_copy(sp5C, sp50, sp38);
    ml_vec3f_normalize_copy(sp68, sp5C);
    ml_vec3f_copy(sp44, sp50);
    sp1C = gu_sqrtf(sp5C[0]*sp5C[0] + sp5C[1]*sp5C[1] + sp5C[2]*sp5C[2]);
    if (1500.0f < sp1C) {
        ml_vec3f_scale_copy(sp5C, sp68, 1500.0f);
        ml_vec3f_add(sp44, sp38, sp5C);
    }
    switch(D_8037D9F6) {
        case 0: //802BC94C
            ml_vec3f_clear(sp2C);
            break;

        case 1: //802BC95C
            ml_vec3f_scale_copy(sp2C, sp68, 100.0f);
            ml_vec3f_yaw_rotate_copy(sp2C, sp2C, -90.0f);
            break;

        case 2: //802BC984
            ml_vec3f_scale_copy(sp2C, sp68, 100.0f);
            ml_vec3f_yaw_rotate_copy(sp2C, sp2C, 90.0f);
            break;

        case 3: //802BC9AC
            sp2C[0] = 0.0f;
            sp2C[1] = 100.0f;
            sp2C[2] = 0.0f;
            break;

        case 4: //802BC9C8
            ml_vec3f_clear(sp2C);
            break;
    }//L802BC9D0
    ml_vec3f_add(sp20, sp2C, sp44);
    if (func_80320B98(sp38, sp20, sp74, 0x9E0000)) {
        D_8037D9F6++;
        if (D_8037D9F6 >= 5) {
            D_8037D9F6 = 0;
            return func_802BC640(sp50, sp68, sp1C, arg0);
        }
    }else{
        D_8037D9F6 = 0;
    }
    return 0;
}

void func_802BCA58(void) {
    f32 sp4C;
    f32 sp48;
    s32 pad44;
    s32 pad40;
    f32 sp34[3];
    f32 sp28[3];

    player_getPosition(sp28);
    ml_vec3f_diff_copy(sp34, sp28, D_8037D958);
    sp4C = player_getYaw();
    sp48 = ml_map_f(mlAbsF((f32) (mlNormalizeAngle(D_8037D96C - sp4C) - 180.0)), 0.0f, 180.0f, D_8037D97C, D_8037D980);
    func_80256E24(D_8037D9A8, 0.0f, sp4C, 0.0f, 0.0f, ml_map_f(gu_sqrtf(sp34[0]*sp34[0] + sp34[2]*sp34[2]), 300.0f, 450.0f, 0.0f, sp48));
    ml_vec3f_diff_copy(sp34, D_8037D9A8, D_8037D9B8);
    if (func_802BC428()) {
        ml_vec3f_copy(D_8037D9B8, D_8037D9A8);
        return;
    }
    ml_vec3f_scale(sp34, 0.08f);
    D_8037D9B8[0] += sp34[0];\
    D_8037D9B8[1] += sp34[1];\
    D_8037D9B8[2] += sp34[2];
}

void func_802BCBD4(void) {
    D_8037D940 = 0;
    D_8037D9F5 = 1;
    func_802BD8EC(130.0f);
    func_802BD870(10.0f, 10.0f, 120.0f, 120.0f);
    func_802BE230(1.4f, 14.0f);
    func_802BD840();
    func_802C28C8();
    func_802C0120();
    func_802C2258();
    func_802C0F4C();
    func_8024C764(D_8037D968);
    func_8024C5CC(D_8037D958);
    ml_vec3f_copy(D_8037D948, D_8037D958);
    ml_vec3f_clear(D_8037D9C8);
    ml_vec3f_clear(D_8037D9E0);
    ml_vec3f_clear(D_8037D9A8);
    ml_vec3f_clear(D_8037D9B8);
    D_8037D994 = 550.0f;
    D_8037D998 = 620.0f;
    D_8037D99C = 150.0f;
    D_8037D9A0 = 0.0f;
    D_8037D9F6 = 0;
    D_8037D978 = 100.0f;
    D_8037D9F4 = 0;
    func_802BD0D8(1);
}

void func_802BCD30(void){
    func_802BD0D8(0);
    func_802C2250();
    func_802C0148();
}

f32 func_802BCD60(void) {
    f32 sp34[3];
    f32 sp28[3];
    s32 temp_v0;

    if ((D_8037D940 & 1) && !func_802BC428()) 
        return D_8037D9A0;

    ml_vec3f_copy(sp28, D_8037D958);
    temp_v0 = func_80245314(sp28, sp34, 10.0f, -600.0f, 0x800000);
    if (temp_v0 == 0) {
        D_8037D9A0 = sp28[1] - 600.0f;
    }
    if (temp_v0 != 0) {
        D_8037D9A0 = sp28[1];
    }

    return D_8037D9A0;
}


bool func_802BCE0C(f32 arg0[3], f32 arg1[3]) {
    f32 sp2C[3];
    f32 sp20[3];

    ml_vec3f_copy(sp2C, arg1);
    if (func_80244D94(arg0, sp2C, sp20, 0x9E0000, 40.0f)) {
        return FALSE;
    }
    if (func_8024575C(arg0, sp2C, 40.0f, sp20, 4, 0x9E0000)) {
        return FALSE;
    }
    return TRUE;
}


void func_802BCE94(void){
    if(func_802BE60C())
        func_802BC84C(0);
}

void func_802BCEC4(void){
    f32 sp24[3];
    f32 sp18[3];

    if(!D_8037D9F5)
        return;
    
    func_802BCD60();
    D_8037D948[0] = D_8037D958[0];
    D_8037D948[1] = D_8037D958[1];
    D_8037D948[2] = D_8037D958[2];
    func_802BCA58();

    switch(D_8037D9F4){
        case 1:// L802BCF3C
            func_802C18F8();
            func_802BCE94();
            break;

        case 3:// L802BCF54
            func_802C1B2C();
            break;
        
        case 4:// L802BCF64
            func_802BFAF0();
            func_802BCE94();
            break;

        case 5:// L802BCF7C
            func_802BF454();
            func_802BCE94();
            break;

        case 6:// L802BCF94
            func_802BCE94();
            break;

        case 8:// L802BCFA4
            func_802BF888();
            break;

        case 9:// L802BCFB4
            func_802C0D60();
            func_802BCE94();
            break;

        case 0xA:// L802BCFCC
            func_802C1F30();
            break;

        case 0xB:// L802BCFDC
            func_802C0558();
            break;

        case 0xC:// L802BCFEC
            func_802BFF8C();
            func_802BCE94();
            break;

        case 0xD:// L802BD004
            func_802BF2CC();
            func_802BCE94();
            break;

        case 0xF:// L802BD01C
            func_802C24B4();
            break;

        case 0x10:// L802BD02C
            func_802BF1D4();
            break;

        case 0x11:// L802BD03C
            func_802BF5F4();
            break;

        case 0x12:// L802BD04C
            func_802C14E0();
            break;

        case 0x13:// L802BD05C
            func_802C07A0();
            break;
    }//// L802BD064
    ml_vec3f_copy(sp24, D_8037D958);
    ml_vec3f_copy(sp18, D_8037D968);
    func_802C22C0(sp24, sp18);
    if(D_8037D9F7){
        func_802C292C(sp24, sp18);
    }
    func_8024CD88(sp24);
    func_8024CE18(sp18);
}

int func_802BD0CC(void){
    return D_8037D9F4;
}

void func_802BD0D8(s32 arg0){
    if(arg0 == D_8037D9F4) 
        return;

    switch(D_8037D9F4){
        case 0x1://L802BD114
            func_802C18F0();
            break;

        case 0x3://L802BD124
            func_802C1AD0();
            break;

        case 0x4://L802BD134
            func_802BFAE8();
            break;

        case 0x5://L802BD144
            func_802BF44C();
            break;

        case 0x8://L802BD154
            func_802BF880();
            break;

        case 0x9://L802BD164
            func_802C09E0();
            break;

        case 0xa://L802BD174
            func_802C1DA8();
            break;

        case 0xb://L802BD184
            func_802C0550();
            break;

        case 0xc://L802BD194
            func_802BFF78();
            break;

        case 0xd://L802BD1A4
            func_802BF2B8();
            break;

        case 0xf://L802BD1B4
            func_802C24AC();
            break;

        case 0x10://L802BD1C4
            func_802BF1CC();
            break;

        case 0x11://L802BD1D4
            func_802BF5EC();
            break;

        case 0x12://L802BD1E4
            func_802C0FCC();
            break;

        case 0x13://L802BD1F4
            func_802C0694();
            break;
    }//L802BD1FC

    switch (arg0)
    {
        case 0x1: //L802BD224
            func_802C18B0();
            break;

        case 0x3: //L802BD234
            func_802C1AD8();
            break;

        case 0x4: //L802BD244
            func_802BFA60();
            break;

        case 0x5: //L802BD254
            func_802BF3F0();
            break;

        case 0x8: //L802BD264
            func_802BF870();
            break;

        case 0x9: //L802BD274
            func_802C09A0();
            break;

        case 0xa: //L802BD284
            func_802C1DA0();
            break;

        case 0xb: //L802BD294
            func_802C04F8();
            break;

        case 0xc: //L802BD2A4
            func_802BFF1C();
            break;

        case 0xd: //L802BD2B4
            func_802BF270();
            break;

        case 0xf: //L802BD2C4
            func_802C2460();
            break;

        case 0x10: //L802BD2D4
            func_802BF174();
            break;

        case 0x11: //L802BD2E4
            func_802BF5C0();
            break;

        case 0x12: //L802BD2F4
            func_802C0F6C();
            break;

        case 0x13: //L802BD304
            func_802C0710();
            break;
    }
    D_8037D9F4 = arg0;
}

void func_802BD328(s32 arg0){
    D_8037D9F5 = arg0;
}

void func_802BD334(f32 arg0[3]){
    ml_vec3f_copy(D_8037D958, arg0);
}

void func_802BD35C(f32 arg0[3]){
    ml_vec3f_copy(D_8037D968, arg0);
}

void func_802BD384(f32 arg0[3]){
    ml_vec3f_copy(arg0, D_8037D958);
}

void func_802BD3A8(f32 arg0[3]){
    ml_vec3f_copy(arg0, D_8037D968);
}

void func_802BD3CC(f32 arg0[3]) {
    f32 sp2C;
    f32 temp_f0;
    f32 temp_f2;

    player_getPosition(arg0);
    sp2C = func_8028E82C();
    if ((func_8028F2FC() != 0) && (func_8028EE84() != BSWATERGROUP_2_UNDERWATER) && (player_getTransformation() == TRANSFORM_1_BANJO)) {
        temp_f0 = func_8028EF88();
        temp_f2 = temp_f0 - 500.0f;
        sp2C = ml_map_f(arg0[1], temp_f0 - 80.0f, temp_f2, temp_f0, temp_f2);
    }
    if ((sp2C + D_8037D974) < arg0[1]) {
        arg0[1] = (f32) (arg0[1] + (80.0f - D_8037D974));
    }
    else{
        arg0[1] = (f32) (sp2C + 80.0f);
    }
}

void func_802BD4C0(f32 arg0[3]) {
    func_802BD3CC(arg0);
    arg0[0] += D_8037D9B8[0];
    arg0[1] += D_8037D9B8[1];
    arg0[2] += D_8037D9B8[2];
}

f32 func_802BD51C(void) {
    f32 sp24[3];
    f32 sp20;
    f32 sp1C;
    
    player_getPosition(sp24);
    sp20 = func_8028E82C();
    sp1C = D_8037D9A0 + 35.0f + 20.0f;
    if (func_8028F2FC()) {
        sp20 = func_8028EF88();
    }
    if ((sp24[1] - sp20) > 130.0f) {
        D_8037D978 = sp24[1] + func_802BD8C8() - 130.0f;
    } else {
        D_8037D978 = func_802BD8C8() + sp20;
    }
    if (D_8037D978 < sp1C) {
        D_8037D978 = sp1C;
    }
    return D_8037D978;
}

void func_802BD610(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 sp24[3];

    sp24[0] = mlDiffDegF(arg0[0], arg1[0]);
    sp24[1] = mlDiffDegF(arg0[1], arg1[1]);
    sp24[0] *= 0.003333 * D_8037D984;
    sp24[1] *= 0.003333 * D_8037D988;
    sp24[0] = func_80259198(sp24[0], D_8037D98C * 0.003333);
    sp24[1] = func_80259198(sp24[1], D_8037D990 * 0.003333);
    sp24[2] = 0.0f;
    arg1[0] = mlNormalizeAngle(arg1[0] + sp24[0]);
    arg1[1] = mlNormalizeAngle(arg1[1] + sp24[1]);
}

void func_802BD720(f32 arg0[3]) {
    f32 sp24[3];

    func_802BD3A8(sp24);
    func_802BD780(arg0, sp24, D_8037D984, D_8037D988, D_8037D98C, D_8037D990);
    func_802BD35C(sp24);
}

void func_802BD780(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    s32 temp_s0;
    s32 temp_s1;
    s32 i;

    temp_s1 = func_8033DD90() * 5;
    for(i = 0; i < temp_s1; i++){
        func_802BD610(arg0, arg1, arg2, arg3, arg4, arg5);
    }
}

void func_802BD82C(f32 arg0, f32 arg1){
    D_8037D97C = arg0;
    D_8037D980 = arg1;
}

void func_802BD840(void){
    func_802BD82C(110.0f, 180.0f);
}

void func_802BD870(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    D_8037D984 = arg0;
    D_8037D988 = arg1;
    D_8037D98C = arg2;
    D_8037D990 = arg3;
}

void func_802BD8A4(f32 arg0, f32 arg1, f32 arg2) {
    D_8037D994 = arg0;
    D_8037D998 = arg1;
    D_8037D99C = arg2;
}

f32 func_802BD8C8(void){
    return D_8037D99C;
}

f32 func_802BD8D4(void){
    return D_8037D994;
}

f32 func_802BD8E0(void){
    return D_8037D998;
}

void func_802BD8EC(f32 arg0){
    D_8037D974 = arg0;
}

f32 func_802BD8F8(void){
    return D_8037D974;
}

void func_802BD904(f32 arg0[3]) {
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp34;
    f32 sp30;

    if (func_802BC428()) {
        ml_vec3f_clear(D_8037D9C8);
        func_802BD35C(arg0);
        return;
    }
    
    sp34 = time_getDelta();
    func_802BD3A8(sp5C);
    sp50[0] = mlDiffDegF(arg0[0], sp5C[0]);
    sp50[1] = mlDiffDegF(arg0[1], sp5C[1]);
    sp50[2] = 0.0f;
    sp44[0] = sp50[0] * sp34 * D_8037D9D4;
    sp44[1] = sp50[1] * sp34 * D_8037D9D4;
    sp44[2] = 0.0f;
    sp38[0] = sp44[0] - D_8037D9C8[0];
    sp38[1] = sp44[1] - D_8037D9C8[1];
    sp38[0] = D_8037D9D8*(0.0333*sp38[0]);
    sp38[1] = D_8037D9D8*(0.0333*sp38[1]);
    D_8037D9C8[0] += sp38[0];
    D_8037D9C8[1] += sp38[1];

    sp30 = mlAbsF(D_8037D9C8[0]);
    if ((mlAbsF(sp50[0]) < sp30) && (D_8037D9C8[0]*sp50[0] > 0.0f)) {
        D_8037D9C8[0] = 0.0f;
        sp5C[0] = arg0[0];
    }
    sp30 = mlAbsF(D_8037D9C8[1]);
    if ((mlAbsF(sp50[1]) < sp30) && (D_8037D9C8[1]*sp50[1] > 0.0f)) {
        D_8037D9C8[1] = 0.0f;
        sp5C[1] = arg0[1];
    }
    sp5C[0] = mlNormalizeAngle(sp5C[0] + D_8037D9C8[0]);
    sp5C[1] = mlNormalizeAngle(sp5C[1] + D_8037D9C8[1]);
    func_802BD35C(sp5C);
}

void func_802BDB30(f32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 phi_f0;
    f32 sp38;
    s32 pad34;
    f32 sp30;
    f32 sp2C;

    if (arg0 == *arg1) {
        *arg2 = 0.0f;
        return;
    }
    sp30 = time_getDelta();
    sp38 = mlDiffDegF(arg0, *arg1);
    if (mlAbsF(sp38) < arg5) {
        *arg2 = ml_mapAbsRange_f(sp38, 0.0f, arg5, 10.0f, arg4);
    } else {
        phi_f0 = arg3 * sp30;
        if (sp38 < 0.0f) {
            phi_f0 = -phi_f0;
        }
        *arg2 += phi_f0;
        if (*arg2 < 0.0f) {
            if (*arg2 < -arg4) {
                *arg2 = -arg4;
            }
        } else if (arg4 < *arg2) {
            *arg2 = arg4;
        }
    }
    sp2C = *arg2 * sp30;
    if (( mlAbsF(sp2C) > mlAbsF(sp38)) && ((sp2C * sp38) > 0.0f)) {
        *arg2 = 0.0f;
        *arg1 = arg0;
        sp2C = 0.0f;
    }
    *arg1 = mlNormalizeAngle(*arg1 + sp2C);
}

void func_802BDCE0(f32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4) {
    f32 sp34;
    f32 sp30;
    f32 sp24;
    f32 sp28;

    sp28 = time_getDelta();
    sp34 = mlDiffDegF(arg0, *arg1);
    sp30 = (sp34 * sp28 * arg3) - *arg2;
    *arg2 = (0.0333*sp30)*arg4;
    if ((mlAbsF(sp34) < 0.5) || ((mlAbsF(*arg2) > mlAbsF(sp34)) && ((sp34 * *arg2) > 0.0f))) {
        *arg2 = 0.0f;
        *arg1 = arg0;
    }
    *arg1 = mlNormalizeAngle(*arg1 + *arg2);
}


int func_802BDE10(f32 arg0, f32 arg1){
    f32 sp1C;
    sp1C = mlAbsF(arg0);
    return (mlAbsF(arg1) < sp1C) && (0.0f <= arg0*arg1);
}

void func_802BDE88(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 temp_f14;
    f32 temp_f2;
    s32 end;
    s32 i;

    end = func_8033DD90()*5;
    for(i = 0; i < end; i++){
        temp_f14 = arg2 - *arg1;
        temp_f2 = temp_f14*arg3 - *arg0;
        *arg0 += temp_f2* arg4;
        if (func_802BDE10(*arg0, temp_f14)) {
            *arg0 = 0.0f;
            *arg1 = arg2;
            return;
        }
        *arg1 = *arg0 + *arg1;
    }
}

void func_802BDF5C(f32 arg0[3], f32 arg1[3]) {
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];


    sp54[0] = arg0[0] - arg1[0];
    sp54[1] = arg0[1] - arg1[1];
    sp54[2] = arg0[2] - arg1[2];

    sp48[0] = D_8037D9EC * (0.003333 * sp54[0]);
    sp48[1] = D_8037D9EC * (0.003333 * sp54[1]);
    sp48[2] = D_8037D9EC * (0.003333 * sp54[2]);

    sp3C[0] = sp48[0] - D_8037D9E0[0];
    sp3C[1] = sp48[1] - D_8037D9E0[1];
    sp3C[2] = sp48[2] - D_8037D9E0[2];

    D_8037D9E0[0] += sp3C[0] * 0.003333 * D_8037D9F0;
    D_8037D9E0[1] += sp3C[1] * 0.003333 * D_8037D9F0;
    D_8037D9E0[2] += sp3C[2] * 0.003333 * D_8037D9F0;

    if (func_802BDE10(D_8037D9E0[0], sp54[0])) {
        D_8037D9E0[0] = 0.0f;
        arg1[0] = arg0[0];
    }
    if (func_802BDE10(D_8037D9E0[1], sp54[1])) {
        D_8037D9E0[1] = 0.0f;
        arg1[1] = arg0[1];
    }
    if (func_802BDE10(D_8037D9E0[2], sp54[2])) {
        D_8037D9E0[2] = 0.0f;
        arg1[2] = arg0[2];
    }

    arg1[0] = arg1[0] + D_8037D9E0[0];
    arg1[1] = arg1[1] + D_8037D9E0[1];
    arg1[2] = arg1[2] + D_8037D9E0[2];
}

void func_802BE190(f32 arg0[3]){
    f32 sp34[3];
    int i;
    int end;

    if(func_802BC428()){
        ml_vec3f_clear(D_8037D9E0);
        func_802BD334(arg0);
        return;
    }

    end = func_8033DD90()*5;
    func_802BD384(sp34);
    for(i = 0; i < end; i++){
        func_802BDF5C(arg0, sp34);
    }
    func_802BD334(sp34);
}

void func_802BE230(f32 arg0, f32 arg1){
    D_8037D9EC = arg0;
    D_8037D9F0 = arg1;
}

void func_802BE244(f32 arg0, f32 arg1){
    D_8037D9D4 = arg0;
    D_8037D9D8 = arg1;
}

void func_802BE258(f32 arg0[3], f32 arg1){
    f32 sp54[3];
    int i;
    s32 pad;

    for(i = 0; func_80320DB0(arg0, arg1, sp54, 0x9e0000) && i < 1; i++){//L802BE2C0
        if((sp54[0]*sp54[0] + sp54[1]*sp54[1] + sp54[2]*sp54[2]) < 0.01)
            return;
        arg0[0] += 1.5f * sp54[0];
        arg0[1] += 1.5f * sp54[1];
        arg0[2] += 1.5f * sp54[2];
    }
}

void func_802BE384(f32 arg0[3], f32 arg1[3], f32 arg2[3], f32 arg3[3], f32 arg4[3]){
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];
    f32 dp;

    sp34[0] = arg3[0] - arg2[0];
    sp34[1] = arg3[1] - arg2[1];
    sp34[2] = arg3[2] - arg2[2];

    sp28[0] = arg1[0] - arg0[0];
    sp28[1] = arg1[1] - arg0[1];
    sp28[2] = arg1[2] - arg0[2];

    sp1C[0] = sp34[0] - sp28[0];
    sp1C[1] = sp34[1] - sp28[1];
    sp1C[2] = sp34[2] - sp28[2];
    dp = -ml_dotProduct_vec3f(arg4, sp1C);
    arg3[0] += dp*arg4[0];
    arg3[1] += dp*arg4[1];
    arg3[2] += dp*arg4[2];

}

void func_802BE484(f32 arg0[3], f32 arg1[3]){
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    int sp2C;
    s32 tmp_v0;

    func_802BE258(arg0, 35.0f);
    ml_vec3f_copy(sp48, arg0);
    ml_vec3f_copy(sp3C, arg1);
    ml_vec3f_diff_copy(sp30, sp3C, sp48);
    ml_vec3f_normalize(sp30);
    ml_vec3f_scale(sp30, 35.0f);

    sp3C[0] += sp30[0];
    sp3C[1] += sp30[1];
    sp3C[2] += sp30[2];
    sp2C = func_80320B98(sp48, sp3C, sp54, 0x9e0000);
    ml_vec3f_diff(sp3C, sp30);

    tmp_v0 = func_8024575C(sp48, sp3C, 35.0f, sp54, 3, 0x9e0000);
    if(sp2C || tmp_v0){
        func_802BE384(sp48, sp3C, arg0, arg1, sp54);
        ml_vec3f_diff_copy(sp30, arg1, arg0);
        ml_vec3f_normalize(sp30);
        ml_vec3f_scale(sp30, 35.0f);
        arg1[0] += sp30[0];
        arg1[1] += sp30[1];
        arg1[2] += sp30[2];
        func_80320B98(arg0, arg1, sp54, 0x9e0000);
        ml_vec3f_diff(arg1, sp30);
    }
}

int func_802BE60C(void){
    f32 sp1C[3];

    if(func_802BC428())
        return 0;
    
    if(map_get() == MAP_91_FILE_SELECT)
        return 0;

    ml_vec3f_copy(sp1C, D_8037D958);
    func_802BE484(D_8037D948, D_8037D958);
    return !(sp1C[0] == D_8037D958[0]) || !(sp1C[1] == D_8037D958[1]) || !(sp1C[2] == D_8037D958[2]);
}

void func_802BE6FC(f32 arg0[3], f32 arg1[3]){
    func_802BC434(arg0, arg1, D_8037D958);
}

void func_802BE720(void){
    s32 sp34;
    f32 sp28[3];
    f32 sp1C[3];

    func_8024C5CC(sp28);
    func_8024C764(sp1C);
    func_802BD334(sp28);
    func_802BD35C(sp1C);

    sp34 = func_802BD0CC();
    func_802BD0D8(0);
    func_802BD0D8(sp34);
    ml_vec3f_clear(D_8037D9C8);
    ml_vec3f_clear(D_8037D9E0);
    func_802C28C8();
}

void func_802BE794(void){
    f32 sp2C[3];
    f32 sp20[3];
    if(D_8037D9F4 == 1 || D_8037D9F4 == 0xb || D_8037D9F4 == 3){
        player_getPosition(sp2C);
        sp2C[1] += 100.0f;
        player_getRotation(sp20);
        sp20[1] = mlNormalizeAngle(sp20[1] + 180.0f);
        func_8024CD88(sp2C);
        func_8024CE18(sp20);
        func_8024C510(300.0f);
        func_802BE720();
    }//L802BE828
}

int func_802BE834(f32 arg0[3]){
    s32 pad;
    f32 sp30[3];
    f32 sp24[3];
    f32 sp18[3];

    ml_vec3f_copy(sp18, arg0);
    player_getPosition(sp30);
    sp30[1] += 60.0f;
    if(func_80320B98(sp30, sp18, sp24, 0x9e0000))
        return 0;
    return 1;

}

void func_802BE894(f32 arg0[3], f32 arg1[3]){
    f32 sp1C[3];
    func_802C02D4(sp1C);
    func_802BC434(arg0, sp1C, arg1);
    arg0[2] = 0.0f;
}

void func_802BE8D8(void){
    D_8037D9F7 = 1;
    func_802C29A0(1);
    func_802C2A64(D_8037D958);
    func_802C2A8C(D_8037D968);
}

void func_802BE91C(void){
    func_802C29A0(3);
}
