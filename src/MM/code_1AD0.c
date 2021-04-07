#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#pragma GLOBAL_ASM("asm/nonmatchings/MM/code_1AD0/func_80387EC0.s")
// extern  s32 D_802D1724[];
// void func_80387EC0(void) {
//     s32 temp_sp18;

//     if (getGameMode() != 7) {
//         temp_sp18 = ((((s32)D_802D1724) + 0xC) & 0xF0000000) + ((D_802D1724[2] & 0x3FFFFFF) * 4);
//         ((s32*)temp_sp18)[0] = 0x3E00008;
//         ((s32*)temp_sp18)[1] = 0x24020002;
        
//         osWritebackDCache(temp_sp18, 8);
//         osInvalICache(temp_sp18, 8);
//     }
// }

void func_80387F44(void) {
    s32 sp1C;

    osPiReadIo(0x578, &sp1C);
    sp1C = sp1C & (sp1C ^ 0xFFFF0000);
    if (sp1C != 0x8965){
        func_80387EC0();
    }
}