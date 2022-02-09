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

void mlMtxApply(Mtx *mPtr){
    func_80245A7C(D_80282FD0, mPtr);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_802514BC.s")

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

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80251788.s")
#else
f32 *func_80251788(f32 arg0, f32 arg1, f32 arg2){
    f32 (* v0)[4][4] = (f32 *) ++D_80282FD0;

    (*v0)[0][3] = 0.0f;
    (*v0)[0][2] = 0.0f;
    (*v0)[0][1] = 0.0f;
    (*v0)[1][3] = 0.0f;
    (*v0)[1][2] = 0.0f;
    (*v0)[1][0] = 0.0f;
    (*v0)[2][3] = 0.0f;
    (*v0)[2][1] = 0.0f;
    (*v0)[2][0] = 0.0f;
    (*v0)[0][0] = 1.0f;
    (*v0)[1][1] = 1.0f;
    (*v0)[2][2] = 1.0f;
    (*v0)[3][3] = 1.0f;
    (*v0)[3][2] = arg2;
    (*v0)[3][1] = arg1;
    (*v0)[3][0] = arg0;
    return &(*v0)[3][3];
}
#endif

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

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80253010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13990/func_80253034.s")


typedef struct{
    u32 unk0;
    u32 unk4;
}struct49s;

extern struct49s D_803FFE10[];

extern u8 D_8000E800;
extern u32 D_8027BF2C;
extern u32 D_8027BF30;
extern u8 D_8002D500;

void func_80253050(
    s32 overlay_id, u32 ram_start, u32 ram_end, u32 rom_start, u32 rom_end, 
    u32 code_start, u32 code_end, u32 data_start, u32 data_end, u32 bss_start, u32 bss_end
){
    u32 sp34;
    u32 sp30;
    u32 sp2C;
    u32 *tmp;

    osWriteBackDCacheAll();
    osInvalDCache(ram_start, ram_end - ram_start);
    osInvalICache(ram_start, ram_end - ram_start);

    if(bss_start){
        osInvalDCache(bss_start, bss_end - bss_start);
    }

    rom_start = D_803FFE10[overlay_id].unk0;
    rom_end = D_803FFE10[overlay_id].unk4;

    if(overlay_id){
        func_80254008();
        sp34 = &D_8000E800;
    }
    else{
        sp34 = &D_8002D500;
    }
    func_802405F0(sp34, rom_start, rom_end - rom_start);
    rarezip_uncompress(&sp34, &ram_start);
    sp2C = D_8027BF2C;
    sp30 = D_8027BF30;
    rarezip_uncompress(&sp34, &ram_start);

    if(bss_start){
        bzero(bss_start, bss_end - bss_start);
        osWriteBackDCacheAll();
        tmp = (u32*) bss_start;
        tmp[0] = sp2C;
        tmp[1] = sp30;
        tmp[2] = D_8027BF2C;
        tmp[3] = D_8027BF30;
    }
}
