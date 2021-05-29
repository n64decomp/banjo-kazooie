#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "ml/mtx.h"

extern Mtx *D_80282FD0;
extern Mtx_t D_80282810;

f32 func_80263FF0(f32);
f32 cosf(f32);
extern f64 D_80278220;

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_802513B0.s")
/*void func_802513B0(Mtx *arg0){
    s32 i;
    for(i = 0; i < 4; i++){
       arg0->m[i][0] = D_80282FD0->m[i][0];
       arg0->m[i][1] = D_80282FD0->m[i][1];
       arg0->m[i][2] = D_80282FD0->m[i][2];
       arg0->m[i][3] = D_80282FD0->m[i][3];
    }
}//*/

Mtx *func_80251488(void){
    return D_80282FD0;
}

void func_80251494(Mtx *mPtr){
    func_80245A7C(D_80282FD0, mPtr);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_802514BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_802515D4.s")

void func_802516C8(void){
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

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80251788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_802517F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80251878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_802519C8.s")

//mlMtx
void mlMtxIdent(void){
    s32 i;
    f32 *v0 = D_80282FD0 = D_80282810;
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

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80251B5C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80252188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/mlMtxScale.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80252280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80252330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_8025235C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80252434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_802524F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_802525A4.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80252A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80252AF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80252C08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80252CC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80252D8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80252DDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80252E4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80252EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80252F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80252F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80252FC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80253010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80253034.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80253050.s")
