#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"


extern bool func_80245314(f32[3], f32[3], f32, f32, u32);
extern int func_80244D94(f32[3], f32[3], f32[3], u32, f32);
extern int func_8024575C(f32[3], f32[3], f32, f32[3], s32, u32);
extern f32 ml_vec3f_length(f32[3], f32[3]);
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

void ncDynamicCamera_setState(s32 state);
void ncDynamicCamera_setPosition(f32 arg0[3]);
void ncDynamicCamera_getPosition(f32 arg0[3]);
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
f32 cameraPosition[3];
f32 cameraRotation[3];
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
u8 dynamicCameraState;
u8 cameraUpdateEnabled;
u8 D_8037D9F6;
u8 dynamicCameraInFirstPerson;

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
        if (phi_f26 < ml_vec3f_length(arg0, sp78)) {
            ncDynamicCamera_setPosition(sp78);
            ml_vec3f_clear(D_8037D9C8);
            ml_vec3f_clear(D_8037D9E0);
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_802BC84C(s32 arg0){
    f32 sp74[3];
    f32 target_direction[3];
    f32 d_target[3];
    f32 player_position[3];
    f32 sp44[3];
    f32 camera_position[3];
    f32 sp2C[3];
    f32 sp20[3];
    f32 target_distance;

    if(player_getTransformation() == TRANSFORM_3_PUMPKIN){
        player_getPosition(player_position);
        player_position[1] += 76.0f;
    }
    else{
        func_8028EC64(player_position);
    }
    ncDynamicCamera_getPosition(camera_position);
    ml_vec3f_diff_copy(d_target, player_position, camera_position);
    ml_vec3f_normalize_copy(target_direction, d_target);
    ml_vec3f_copy(sp44, player_position);
    target_distance = gu_sqrtf(d_target[0]*d_target[0] + d_target[1]*d_target[1] + d_target[2]*d_target[2]);
    if (1500.0f < target_distance) {
        ml_vec3f_scale_copy(d_target, target_direction, 1500.0f);
        ml_vec3f_add(sp44, camera_position, d_target);
    }
    switch(D_8037D9F6) {
        case 0: //802BC94C
            ml_vec3f_clear(sp2C);
            break;

        case 1: //802BC95C
            ml_vec3f_scale_copy(sp2C, target_direction, 100.0f);
            ml_vec3f_yaw_rotate_copy(sp2C, sp2C, -90.0f);
            break;

        case 2: //802BC984
            ml_vec3f_scale_copy(sp2C, target_direction, 100.0f);
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
    if (func_80320B98(camera_position, sp20, sp74, 0x9E0000)) {
        D_8037D9F6++;
        if (D_8037D9F6 >= 5) {
            D_8037D9F6 = 0;
            return func_802BC640(player_position, target_direction, target_distance, arg0);
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
    f32 player_position[3];

    player_getPosition(player_position);
    ml_vec3f_diff_copy(sp34, player_position, cameraPosition);
    sp4C = player_getYaw();
    sp48 = ml_map_f(mlAbsF((f32) (mlNormalizeAngle(cameraRotation[1] - sp4C) - 180.0)), 0.0f, 180.0f, D_8037D97C, D_8037D980);
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
    cameraUpdateEnabled = TRUE;
    func_802BD8EC(130.0f);
    func_802BD870(10.0f, 10.0f, 120.0f, 120.0f);
    func_802BE230(1.4f, 14.0f);
    func_802BD840();
    ncFirstPersonCamera_reset();
    func_802C0120();
    func_802C2258();
    func_802C0F4C();
    viewport_getRotation_vec3f(cameraRotation);
    viewport_getPosition_vec3f(cameraPosition);
    ml_vec3f_copy(D_8037D948, cameraPosition);
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
    dynamicCameraState = 0;
    ncDynamicCamera_setState(1);
}

void func_802BCD30(void){
    ncDynamicCamera_setState(0);
    func_802C2250();
    func_802C0148();
}

f32 func_802BCD60(void) {
    f32 sp34[3];
    f32 sp28[3];
    s32 temp_v0;

    if ((D_8037D940 & 1) && !func_802BC428()) 
        return D_8037D9A0;

    ml_vec3f_copy(sp28, cameraPosition);
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

void ncDynamicCamera_update(void){
    f32 sp24[3];
    f32 sp18[3];

    if(!cameraUpdateEnabled)
        return;
    
    func_802BCD60();
    D_8037D948[0] = cameraPosition[0];
    D_8037D948[1] = cameraPosition[1];
    D_8037D948[2] = cameraPosition[2];
    func_802BCA58();

    switch(dynamicCameraState){
        case 1:// L802BCF3C
            ncDynamicCam1_update();
            func_802BCE94();
            break;

        case 3:// L802BCF54
            ncDynamicCam3_update();
            break;
        
        case 4:// L802BCF64
            ncDynamicCam4_update();
            func_802BCE94();
            break;

        case 5:// L802BCF7C
            ncDynamicCam5_update();
            func_802BCE94();
            break;

        case 6:// L802BCF94
            func_802BCE94();
            break;

        case 8:// L802BCFA4
            ncDynamicCam8_update();
            break;

        case 9:// L802BCFB4
            ncDynamicCam9_update();
            func_802BCE94();
            break;

        case 0xA:// L802BCFCC
            ncDynamicCamA_update();
            break;

        case 0xB:// L802BCFDC
            ncDynamicCamB_update();
            break;

        case 0xC:// L802BCFEC
            ncDynamicCamC_update();
            func_802BCE94();
            break;

        case 0xD:// L802BD004
            ncDynamicCamD_update();
            func_802BCE94();
            break;

        case 0xF:// L802BD01C
            ncDynamicCamF_update();
            break;

        case 0x10:// L802BD02C
            ncDynamicCam10_update();
            break;

        case 0x11:// L802BD03C
            ncDynamicCam11_update();
            break;

        case 0x12:// L802BD04C
            ncDynamicCam12_update();
            break;

        case 0x13:// L802BD05C
            ncDynamicCam13_update();
            break;
    }//// L802BD064
    ml_vec3f_copy(sp24, cameraPosition);
    ml_vec3f_copy(sp18, cameraRotation);
    func_802C22C0(sp24, sp18);
    if(dynamicCameraInFirstPerson){
        ncFirstPersonCamera_getPositionAndRotation(sp24, sp18);
    }
    viewport_setPosition_vec3f(sp24);
    viewport_setRotation_vec3f(sp18);
}

int ncDynamicCamera_getState(void){
    return dynamicCameraState;
}

void ncDynamicCamera_setState(s32 state){
    if(state == dynamicCameraState) 
        return;

    switch(dynamicCameraState){
        case 0x1://L802BD114
            ncDynamicCam1_end();
            break;

        case 0x3://L802BD124
            ncDynamicCam3_end();
            break;

        case 0x4://L802BD134
            ncDynamicCam4_end();
            break;

        case 0x5://L802BD144
            ncDynamicCam5_end();
            break;

        case 0x8://L802BD154
            ncDynamicCam8_end();
            break;

        case 0x9://L802BD164
            ncDynamicCam9_end();
            break;

        case 0xa://L802BD174
            ncDynamicCamA_end();
            break;

        case 0xb://L802BD184
            ncDynamicCamB_end();
            break;

        case 0xc://L802BD194
            ncDynamicCamC_end();
            break;

        case 0xd://L802BD1A4
            ncDynamicCamD_end();
            break;

        case 0xf://L802BD1B4
            ncDynamicCamF_end();
            break;

        case 0x10://L802BD1C4
            ncDynamicCam10_end();
            break;

        case 0x11://L802BD1D4
            ncDynamicCam11_end();
            break;

        case 0x12://L802BD1E4
            ncDynamicCam12_end();
            break;

        case 0x13://L802BD1F4
            ncDynamicCam13_end();
            break;
    }//L802BD1FC

    switch (state)
    {
        case 0x1: //L802BD224
            ncDynamicCam1_init();
            break;

        case 0x3: //L802BD234
            ncDynamicCam3_init();
            break;

        case 0x4: //L802BD244
            ncDynamicCam4_init();
            break;

        case 0x5: //L802BD254
            ncDynamicCam5_init();
            break;

        case 0x8: //L802BD264
            ncDynamicCam8_init();
            break;

        case 0x9: //L802BD274
            ncDynamicCam9_init();
            break;

        case 0xa: //L802BD284
            ncDynamicCamA_init();
            break;

        case 0xb: //L802BD294
            ncDynamicCamB_init();
            break;

        case 0xc: //L802BD2A4
            ncDynamicCamC_init();
            break;

        case 0xd: //L802BD2B4
            ncDynamicCamD_init();
            break;

        case 0xf: //L802BD2C4
            ncDynamicCamF_init();
            break;

        case 0x10: //L802BD2D4
            ncDynamicCam10_init();
            break;

        case 0x11: //L802BD2E4
            ncDynamicCam11_init();
            break;

        case 0x12: //L802BD2F4
            dynamicCam12_init();
            break;

        case 0x13: //L802BD304
            ncDynamicCam13_init();
            break;
    }
    dynamicCameraState = state;
}

void ncDynamicCamera_setUpdateEnabled(bool arg0){
    cameraUpdateEnabled = arg0;
}

void ncDynamicCamera_setPosition(f32 arg0[3]){
    ml_vec3f_copy(cameraPosition, arg0);
}

void ncDynamicCamera_setRotation(f32 arg0[3]){
    ml_vec3f_copy(cameraRotation, arg0);
}

void ncDynamicCamera_getPosition(f32 arg0[3]){
    ml_vec3f_copy(arg0, cameraPosition);
}

void ncDynamicCamera_getRotation(f32 arg0[3]){
    ml_vec3f_copy(arg0, cameraRotation);
}

void func_802BD3CC(f32 arg0[3]) {
    f32 sp2C;
    f32 temp_f0;
    f32 temp_f2;

    player_getPosition(arg0);
    sp2C = func_8028E82C();
    if ((func_8028F2FC() != 0) && (player_getWaterState() != BSWATERGROUP_2_UNDERWATER) && (player_getTransformation() == TRANSFORM_1_BANJO)) {
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

    ncDynamicCamera_getRotation(sp24);
    func_802BD780(arg0, sp24, D_8037D984, D_8037D988, D_8037D98C, D_8037D990);
    ncDynamicCamera_setRotation(sp24);
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

void func_802BD904(f32 target_rotation[3]) {
    f32 camera_rotation[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 dt;
    f32 sp30;

    if (func_802BC428()) {
        ml_vec3f_clear(D_8037D9C8);
        ncDynamicCamera_setRotation(target_rotation);
        return;
    }
    
    dt = time_getDelta();
    ncDynamicCamera_getRotation(camera_rotation);
    sp50[0] = mlDiffDegF(target_rotation[0], camera_rotation[0]);
    sp50[1] = mlDiffDegF(target_rotation[1], camera_rotation[1]);
    sp50[2] = 0.0f;
    sp44[0] = sp50[0] * dt * D_8037D9D4;
    sp44[1] = sp50[1] * dt * D_8037D9D4;
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
        camera_rotation[0] = target_rotation[0];
    }
    sp30 = mlAbsF(D_8037D9C8[1]);
    if ((mlAbsF(sp50[1]) < sp30) && (D_8037D9C8[1]*sp50[1] > 0.0f)) {
        D_8037D9C8[1] = 0.0f;
        camera_rotation[1] = target_rotation[1];
    }
    camera_rotation[0] = mlNormalizeAngle(camera_rotation[0] + D_8037D9C8[0]);
    camera_rotation[1] = mlNormalizeAngle(camera_rotation[1] + D_8037D9C8[1]);
    ncDynamicCamera_setRotation(camera_rotation);
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
        ncDynamicCamera_setPosition(arg0);
        return;
    }

    end = func_8033DD90()*5;
    ncDynamicCamera_getPosition(sp34);
    for(i = 0; i < end; i++){
        func_802BDF5C(arg0, sp34);
    }
    ncDynamicCamera_setPosition(sp34);
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

    ml_vec3f_copy(sp1C, cameraPosition);
    func_802BE484(D_8037D948, cameraPosition);
    return !(sp1C[0] == cameraPosition[0]) || !(sp1C[1] == cameraPosition[1]) || !(sp1C[2] == cameraPosition[2]);
}

void func_802BE6FC(f32 arg0[3], f32 arg1[3]){
    func_802BC434(arg0, arg1, cameraPosition);
}

void func_802BE720(void){
    s32 sp34;
    f32 sp28[3];
    f32 sp1C[3];

    viewport_getPosition_vec3f(sp28);
    viewport_getRotation_vec3f(sp1C);
    ncDynamicCamera_setPosition(sp28);
    ncDynamicCamera_setRotation(sp1C);

    sp34 = ncDynamicCamera_getState();
    ncDynamicCamera_setState(0);
    ncDynamicCamera_setState(sp34);
    ml_vec3f_clear(D_8037D9C8);
    ml_vec3f_clear(D_8037D9E0);
    ncFirstPersonCamera_reset();
}

void func_802BE794(void){
    f32 sp2C[3];
    f32 sp20[3];
    if(dynamicCameraState == 1 || dynamicCameraState == 0xb || dynamicCameraState == 3){
        player_getPosition(sp2C);
        sp2C[1] += 100.0f;
        player_getRotation(sp20);
        sp20[1] = mlNormalizeAngle(sp20[1] + 180.0f);
        viewport_setPosition_vec3f(sp2C);
        viewport_setRotation_vec3f(sp20);
        viewport_moveAlongZAxis(300.0f);
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

void func_802BE894(f32 position[3], f32 rotation[3]){
    f32 sp1C[3];
    func_802C02D4(sp1C);
    func_802BC434(position, sp1C, rotation);
    position[2] = 0.0f;
}

void ncDynamicCamera_enterFirstPerson(void){
    dynamicCameraInFirstPerson = TRUE;
    ncFirstPersonCamera_setState(FIRSTPERSON_STATE_1_ENTER);
    ncFirstPersonCamera_setZoomedOutPosition(cameraPosition);
    ncFirstPersonCamera_setZoomedOutRotation(cameraRotation);
}

void ncDynamicCamera_exitFirstPerson(void){
    ncFirstPersonCamera_setState(FIRSTPERSON_STATE_3_EXIT);
}
