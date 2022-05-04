#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_8037D468;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_28220/func_802AF1B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_28220/func_802AF268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_28220/func_802AF3B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_28220/func_802AF4B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_28220/func_802AF4E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_28220/func_802AF550.s")

void func_802AF604(void){
    f32 anim_duration;
    enum asset_e anim_id;

    func_8029BCF8(&anim_id, &anim_duration);
    func_8028A010(anim_id, anim_duration);
    func_8029C7F4(1,1,3,7);
    func_80294378(6);
    func_802AF4E0();
    D_8037D468 = 0;
    func_802AF1B0(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_28220/func_802AF668.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/core2/code_28220/func_802AF768.s")
void func_802AF768(void){
    func_802AF4B0();
    func_80294378(1);
    func_80291D04();
}
