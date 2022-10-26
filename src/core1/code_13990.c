#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "ml/mtx.h"



f32 func_80263FF0(f32);
f32 cosf(f32);
extern f64 D_80278220;

/*.bss*/
Mtx_t D_80282810;
u8 pad_D_80282850[0x780];
Mtx * D_80282FD0;

/*.code*/
#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_802513B0.s")
#else
void func_802513B0(f32 arg0[4][4]){
    s32 i;
    s32 j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            reinterpret_cast(f32, arg0[i][j]) = reinterpret_cast(f32, D_80282FD0->m[i][j]);
        }
    }
}
#endif

Mtx *func_80251488(void){
    return D_80282FD0;
}

void mlMtxApply(Mtx *mPtr){
    func_80245A7C(D_80282FD0, mPtr);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_802514BC.s")
#else
void func_802514BC(Mtx *arg0) {
    s32 i, j, k;
    f32 tmp;
    f32 sp38[4][4];
    f32 (*sp34)[4];
    f32 (*var_s0)[4];


    sp34 = reinterpret_cast(f32 *, *D_80282FD0);
    var_s0 = reinterpret_cast(f32 *, arg0);
    
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            tmp = 0.0f;
            for(k = 0; k < 4; k++){
                tmp += var_s0[i][k] * sp34[k][j];
            }
            sp38[i][j] = tmp;
        }
    }
    func_80253010(sp34, &sp38, sizeof(Mtx));
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_802515D4.s")

void mlMtxPop(void){
    D_80282FD0--; 
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_802516E0.s")

void func_80251738(void){
    s32 i;
    f32 *v0 = ++D_80282FD0;
    for(i = 0; i<3; i++){
        v0[0] = 1.0f;
        v0[1] = 0.0f;
        v0[2] = 0.0f;
        v0[3] = 0.0f;
        v0[4] = 0.0f;
        v0 += 5;
    }
    v0[0] = 1.0f; 
}

f32 *func_80251788(f32 arg0, f32 arg1, f32 arg2){
    f32 * var_v0 = ++D_80282FD0;
    *(var_v0++) = 1.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = 0.0f; *(var_v0++) = 1.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = 0.0f; *(var_v0++) = 0.0f; *(var_v0++) = 1.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = arg0; *(var_v0++) = arg1; *(var_v0++) = arg2; *(var_v0++) = 1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_802517F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80251878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_802519C8.s")

//mlMtx
void mlMtxIdent(void){
    s32 i;
    f32 *v0 = D_80282FD0 = &D_80282810;
    for(i = 0; i<3; i++){
        v0[0] = 1.0f;
        v0[1] = 0.0f;
        v0[2] = 0.0f;
        v0[3] = 0.0f;
        v0[4] = 0.0f;
        v0 += 5;
    }
    v0[0] = 1.0f; 
}

void func_80251B5C(f32 arg0, f32 arg1, f32 arg2){
    f32 * var_v0 = D_80282FD0 = &D_80282810;
    *(var_v0++) = 1.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = 0.0f; *(var_v0++) = 1.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = 0.0f; *(var_v0++) = 0.0f; *(var_v0++) = 1.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = arg0; *(var_v0++) = arg1; *(var_v0++) = arg2; *(var_v0++) = 1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80251BCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80251C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/mlMtxRotPitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/mlMtxRotYaw.s")
/*void mlMtxRotYaw(f32 yaw) {
    f32 sin;
    f32 cos;
    f32 phi_f12;
    f32 phi_f10;
    f32 phi_f8;
    f32 phi_f4;
    f32 *phi_v0;
    s32 phi_v1;

    if (yaw == 0.0f)
        return;

    sin = sinf(yaw*0.0174533);
    cos = cosf(yaw*0.0174533);
    phi_v0 = D_80282FD0;
    for(phi_v1 = 0; phi_v1 < 0xC; phi_v1 += 4){
        phi_v0 = (u32)D_80282FD0 + phi_v1;
        phi_f12 = phi_v0[0] * cos;
        phi_f10 = phi_v0[8] * sin;
        phi_f8 = phi_v0[0] * sin;
        phi_f4 = phi_v0[8] * cos;
        phi_v0[0] = phi_f12 - phi_f10;
        phi_v0 = (u32)D_80282FD0 + phi_v1;
        phi_v0[8] = phi_f8 + phi_f4;
    }

}//*/

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/mlMtxRotRoll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80251F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_8025208C.s")

void mlMtxRotate(f32 pitch, f32 yaw, f32 roll){
    mlMtxRotYaw(yaw);
    mlMtxRotPitch(pitch);
    mlMtxRotRoll(roll);
}

void mlMtxScale_xyz(f32 x, f32 y, f32 z){
    int i;
    for(i = 0; i < 3; i++){
        reinterpret_cast(f32, D_80282FD0->m[0][i]) *= x;
        reinterpret_cast(f32, D_80282FD0->m[1][i]) *= y;
        reinterpret_cast(f32, D_80282FD0->m[2][i]) *= z;
    }
}

void mlMtxScale(f32 scale){
    int i;
    for(i = 0; i < 3; i++){
        reinterpret_cast(f32, D_80282FD0->m[0][i]) *= scale;
        reinterpret_cast(f32, D_80282FD0->m[1][i]) *= scale;
        reinterpret_cast(f32, D_80282FD0->m[2][i]) *= scale;
    }
}

void func_80252330(f32 x, f32 y, f32 z){
    reinterpret_cast(f32, D_80282FD0->m[3][0]) = x;
    reinterpret_cast(f32, D_80282FD0->m[3][1]) = y;
    reinterpret_cast(f32, D_80282FD0->m[3][2]) = z;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_8025235C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80252434.s")

void func_802524F0(f32 dst[3], f32 x, f32 y, f32 z) {
    dst[0] = x*((f32 (*)[4])D_80282FD0)[0][0] + y*((f32 (*)[4])D_80282FD0)[1][0] + z*((f32 (*)[4])D_80282FD0)[2][0] + ((f32 (*)[4])D_80282FD0)[3][0];
    dst[1] = x*((f32 (*)[4])D_80282FD0)[0][1] + y*((f32 (*)[4])D_80282FD0)[1][1] + z*((f32 (*)[4])D_80282FD0)[2][1] + ((f32 (*)[4])D_80282FD0)[3][1];
    dst[2] = x*((f32 (*)[4])D_80282FD0)[0][2] + y*((f32 (*)[4])D_80282FD0)[1][2] + z*((f32 (*)[4])D_80282FD0)[2][2] + ((f32 (*)[4])D_80282FD0)[3][2];
}

void mlMtx_apply_vec3s(s16 dst[3], s16 src[3]) {
    f32 spC[3];
    f32 sp0[3];
    f32 (*temp_v0)[4];

    temp_v0 = D_80282FD0;
    sp0[0] = (f32) src[0];
    sp0[1] = (f32) src[1];
    sp0[2] = (f32) src[2];

    spC[0] = sp0[0]*temp_v0[0][0] + sp0[1]*temp_v0[1][0] + sp0[2]*temp_v0[2][0] + temp_v0[3][0];
    spC[1] = sp0[0]*temp_v0[0][1] + sp0[1]*temp_v0[1][1] + sp0[2]*temp_v0[2][1] + temp_v0[3][1];
    spC[2] = sp0[0]*temp_v0[0][2] + sp0[1]*temp_v0[1][2] + sp0[2]*temp_v0[2][2] + temp_v0[3][2];

    dst[0] = (spC[0] >= 0.0) ? spC[0] + 0.5 : spC[0] - 0.5;
    dst[1] = (spC[1] >= 0.0) ? spC[1] + 0.5 : spC[1] - 0.5;
    dst[2] = (spC[2] >= 0.0) ? spC[2] + 0.5 : spC[2] - 0.5;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_8025276C.s")

void mlMtxTranslate(f32 x, f32 y, f32 z) {
    f32 *temp_t6;
    f32 *phi_v0;
    f32 phi_f18;
    f32 phi_f16;
    f32 phi_f10;
    s32 phi_v1;

    phi_v0 = D_80282FD0;
    for(phi_v1 = 0; phi_v1 < 0xC; phi_v1 +=4){
        phi_v0 = (u32)D_80282FD0 + phi_v1;
        phi_f18 = phi_v0[0] * x;
        phi_f16 = phi_v0[4] * y;
        phi_v0[0xC] += phi_f18 + phi_f16 + (phi_v0[8] * z);
    }
}

void func_80252A38(f32 x, f32 y, f32 z) {
    s32 var_v1;

    for(var_v1 = 0; var_v1 != 3; var_v1++){
        reinterpret_cast(f32, D_80282FD0->m[3][var_v1]) += reinterpret_cast(f32, D_80282FD0->m[0][var_v1])*x + reinterpret_cast(f32, D_80282FD0->m[1][var_v1])*y + reinterpret_cast(f32, D_80282FD0->m[2][var_v1])*z;
    }
}

void func_80252AF0(f32 arg0[3], f32 arg1[3], f32 rotation[3], f32 scale, f32 arg4[3]) {
    f32 sp1C[3];
    
    if (arg1 != NULL) {
        sp1C[0] = arg1[0] - arg0[0];
        sp1C[1] = arg1[1] - arg0[1];
        sp1C[2] = arg1[2] - arg0[2];
    } else {
        sp1C[0] = arg0[0] * -1.0f;
        sp1C[1] = arg0[1] * -1.0f;
        sp1C[2] = arg0[2] * -1.0f;
    }
    mlMtxTranslate(sp1C[0], sp1C[1], sp1C[2]);
    if (rotation != NULL) {
        mlMtxRotYaw(rotation[1]);
        mlMtxRotPitch(rotation[0]);
        mlMtxRotRoll(rotation[2]);
    }
    if (scale != 1.0f) {
        mlMtxScale_xyz(scale, scale, scale);
    }
    if (arg4 != NULL) {
        mlMtxTranslate(-arg4[0], -arg4[1], -arg4[2]);
    }
}


void func_80252C08(f32 arg0[3], f32 arg1[3], f32 scale, f32 arg3[3]){
    if(arg0 != NULL)
        mlMtxTranslate(arg0[0], arg0[1], arg0[2]);

    if(arg1 != NULL){
        mlMtxRotYaw(arg1[1]);  
        mlMtxRotPitch(arg1[0]);
        mlMtxRotRoll(arg1[2]);
    }

    if(scale != 1.0f){
        mlMtxScale_xyz(scale, scale, scale);
    }

    if(arg3 != NULL)
        mlMtxTranslate(-arg3[0], -arg3[1], -arg3[2]);

}

void func_80252CC4(f32 arg0[3], f32 arg1[3], f32 scale, f32 arg3[3]){
    if(arg3 != NULL)
        mlMtxTranslate(arg3[0], arg3[1], arg3[2]);
    
    if(scale != 1.0f){
        mlMtxScale_xyz(1.0f/scale, 1.0f/scale, 1.0f/scale);
    }

    if(arg1 != NULL){
        mlMtxRotRoll(-arg1[2]);
        mlMtxRotPitch(-arg1[0]);
        mlMtxRotYaw(-arg1[1]);  
    }

    if(arg0 != NULL)
        mlMtxTranslate(-arg0[0], -arg0[1], -arg0[2]);

}

void func_80252D8C(f32 arg0[3], f32 arg1[3]){
    mlMtxTranslate(arg0[0], arg0[1], arg0[2]);
    mlMtxRotRoll(arg1[2]);
    mlMtxRotPitch(arg1[0]);
    mlMtxRotYaw(arg1[1]);   
}

void func_80252DDC(f32 arg0[3], f32 arg1[3]){
    mlMtxRotYaw(-arg1[1]);
    mlMtxRotPitch(-arg1[0]);
    mlMtxRotRoll(-arg1[2]);
    mlMtxTranslate(-arg0[0], -arg0[1], -arg0[2]);
}

void func_80252E4C(f32 arg0[3], f32 arg1[3]){
    mlMtxTranslate(arg0[0], arg0[1], arg0[2]);
    mlMtxRotRoll(arg1[2]);
    mlMtxRotPitch(arg1[0]);
    mlMtxRotYaw(arg1[1]);    
    mlMtxTranslate(-arg0[0], -arg0[1], -arg0[2]);
}

void func_80252EC8(f32 arg0[3], f32 arg1[3]){
    mlMtxTranslate(arg0[0], arg0[1], arg0[2]);
    mlMtxRotYaw(-arg1[1]);
    mlMtxRotPitch(-arg1[0]);
    mlMtxRotRoll(-arg1[2]);
    mlMtxTranslate(-arg0[0], -arg0[1], -arg0[2]);
}

void func_80252F50(f32 arg0[3]){
    mlMtxRotYaw(arg0[1]);
    mlMtxRotPitch(arg0[0]);
    mlMtxRotRoll(arg0[2]);
}

void func_80252F8C(f32 arg0[3]){
    mlMtxRotRoll(arg0[2]);
    mlMtxRotPitch(arg0[0]);
    mlMtxRotYaw(arg0[1]);
}

void func_80252FC8(f32 arg0[3]){
    mlMtxRotYaw(-arg0[1]);
    mlMtxRotPitch(-arg0[0]);
    mlMtxRotRoll(-arg0[2]);
}

