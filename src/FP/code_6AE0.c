#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_8038CED0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038D6C8(Actor *this);

/* .data */
extern ActorAnimationInfo D_803920C0[];

extern ActorInfo D_803920E8 = { 0x204, 0x336, 0x442,
    0x1, D_803920C0,
    func_8038D6C8, func_80326224, func_8038CED0,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038CED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038CF54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D01C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D0A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D208.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D294.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D324.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D3B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D3D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D41C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D5C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D6C8.s")

bool func_8038DD14(void){
    return mapSpecificFlags_get(0xD);
}

bool func_8038DD34(ActorMarker *marker){
    Actor *this = marker_getActor(marker);
    if(func_80329530(this, 800))
        return TRUE;
    return FALSE;
}
