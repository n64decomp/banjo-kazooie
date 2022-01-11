#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "SnS.h"

typedef struct{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
}Struct_Core2_9B650_1s;

typedef struct{
    s16 map_id;
    s16 unk2;
    s16 sns_id;
}Struct_Core2_9B650_0s;

extern Struct_Core2_9B650_0s D_8036E2A0[] = 
{
    {MAP_61_CCW_WINTER_NABNUTS_HOUSE, -1, SNS_ITEM_EGG_YELLOW},
    {MAP_3F_RBB_CAPTAINS_CABIN, -2, SNS_ITEM_EGG_RED},
    {MAP_2C_MMM_BATHROOM, -3, SNS_ITEM_EGG_GREEN},
    {0, 0, 1}
};

extern Struct_Core2_9B650_1s D_8036DE80[] = {
    {-1, 0x87, -1, 0},
    {-2, 0x84, -1, 0},
    {-3, 0x86, -1, 0},
    {0}
};

extern struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} D_80383340;
extern int D_80383348;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9B650/func_803225E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9B650/func_803226BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9B650/func_803226E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9B650/func_80322714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9B650/func_80322740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9B650/func_8032274C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9B650/func_80322758.s")

void func_80322764(void){
    D_80383348 = FALSE;
    D_80383340.unk4 = 0;
    D_80383340.unk2 = D_80383340.unk4;
    D_80383340.unk0 = D_80383340.unk2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9B650/func_8032278C.s")

void func_803228D8(void){
    if(!D_80383348){
        func_8024BD08(0);
        D_80383348 = TRUE;
    }
}

int func_80322914(void){
    return D_80383348;
}
