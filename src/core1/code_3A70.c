#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "n_libaudio.h"


extern s32 D_802758C0;
extern ALSndPlayer *D_802758CC;



#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80241490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80241928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_802424D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80242BE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80243070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_8024324C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_802432F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80243F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80243FE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80244050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80244110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80244190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_8024431C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_802444C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80244594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_802445AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_802445C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80244608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80244814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80244860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80244918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80244938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80244958.s")

void func_80244978(s32 arg0, s16 type, s32 arg2){
    ALEvent sp18;
    if(arg0){
        sp18.type = type;
        ((s32 *)&sp18.msg)[0] = arg0;
        ((s32 *)&sp18.msg)[1] = arg2;

        alEvtqPostEvent(&D_802758CC->evtq, &sp18, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_802449C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_802449E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80244A98.s")
