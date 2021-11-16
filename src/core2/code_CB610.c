#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3[1];
}Struct_Core2_CB610_0;

extern Struct_Core2_CB610_0 D_803861C0[];

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CB610/func_803525A0.s")

void func_80352614(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CB610/func_8035261C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CB610/func_803526DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CB610/func_80352830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CB610/func_80352874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CB610/func_8035287C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CB610/func_803529DC.s")

void func_80352A38(u8 arg0, s32 arg1){
    void (*funcPtr)(void);
    if(arg1){
        D_803861C0[arg0].unk2 = arg1;
        if(func_80352C44(D_803861C0[arg0].unk1)){
            funcPtr = func_80352C44(D_803861C0[arg0].unk1);
            funcPtr();
        }

        D_803861C0[arg0].unk0 = D_803861C0[arg0].unk1;
        D_803861C0[arg0].unk1 = D_803861C0[arg0].unk2;
        D_803861C0[arg0].unk2 = 0;
        if(func_80352C0C(D_803861C0[arg0].unk1)){
            funcPtr = func_80352C0C(D_803861C0[arg0].unk1);
            funcPtr();
        }

    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CB610/func_80352ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CB610/func_80352AE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CB610/func_80352B04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CB610/func_80352B20.s")
