#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802F9AA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802F9AA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802F9C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802F9C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802F9CD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802F9D38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802F9D8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802F9DB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802F9E44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802F9EC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802F9F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802F9F80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802F9FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FA028.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FA060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FA0B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FA0F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FA4E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FA508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FA5D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FA69C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FA718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FA724.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FAB54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FAC3C.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FACA4.s")
typedef struct item_print_s{
    u8 pad0[0x14];
    u32 unk14;
} ItemPrint;

extern ItemPrint D_803692F8[];
extern f32 D_803810B8[];
extern f64 D_80377380;

void func_802FACA4(s32 itemId){
    if(func_802FB0D4(D_803692F8[itemId].unk14) == 2 || itemId < 6 || itemId == item_air ){
        D_803810B8[itemId] += ((f32)item_getCount(itemId) - D_803810B8[itemId] )*D_80377380;
    }
    func_802FB020(D_803692F8[itemId].unk14, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FAD64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FAD9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FADD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FAE1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FAE4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FAF0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FAFAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FAFC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FAFD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72B10/func_802FAFE8.s")
