#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80303F7C(ActorMarker *, f32, s32, s32);
extern ActorProp *func_80303FE4(ActorMarker *, f32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_999A0/func_80320930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_999A0/func_803209C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_999A0/func_803209EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_999A0/func_803209F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_999A0/func_80320B24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_999A0/func_80320B44.s")

void func_80320B7C(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_999A0/func_80320B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_999A0/func_80320B98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_999A0/func_80320C94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_999A0/func_80320DB0.s")

ActorProp *func_80320EB0(ActorMarker *marker, f32 arg1, s32 arg2){
    return func_80303FE4(marker, arg1, arg2);
}

int func_80320ED8(ActorMarker *marker, f32 arg1, s32 arg2){
    func_80303F7C(marker, arg1, arg2, 0);
    return 0;
}