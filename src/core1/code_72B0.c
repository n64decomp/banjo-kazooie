#include <ultra64.h>
#include "functions.h"
#include "variables.h"

int func_802458E0(f32 arg0[3], Actor *arg1, s32 arg2);

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_80244CD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_80244D94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_80244E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_80244F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_80244FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_802450DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_802451A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_80245314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_802453A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_802453DC.s")

//over_water?
int func_8024549C(f32 arg0[3], f32 arg1){
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];
    int sp1C;

    sp20[0] = sp20[1] = sp20[2] = 0.0f;
    sp20[1] = arg1;

    ml_vec3f_diff_copy(sp2C, arg0, sp20);
    ml_vec3f_add(sp38, arg0, sp20);
    sp1C = func_80309B48(sp2C, sp38, sp44, 0xf800ff0f);
    if(sp1C){
        ml_vec3f_copy(arg0, sp38);
    }
    return sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_80245524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_8024559C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_8024560C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_8024575C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_802457C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_8024587C.s")

int func_802458A8(f32 arg0[3], ActorMarker *arg1, s32 arg2){
    return func_802458E0(arg0, marker_getActor(arg1), arg2);
}

int func_802458E0(f32 arg0[3], Actor *arg1, s32 arg2){
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    ml_vec3f_copy(sp28, arg0);
    ml_vec3f_copy(sp1C, arg1->position);
    sp1C[1] += (f32)arg2;
    if(sp1C[1] < sp28[1])
        return FALSE;

    if(func_80320B98(sp28, sp1C, sp34, 0x25e0000)){
        return FALSE;
    }
    return TRUE;
}
