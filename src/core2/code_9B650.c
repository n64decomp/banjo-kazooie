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

/* .bss */
struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} D_80383340;
int D_80383348;

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9B650/func_803225E0.s")
#else
s32 func_803225E0(enum map_e map_id){
    s32 i;
    s16 *ptr = D_8036E2A0;

    for(i = 0; D_8036E2A0[i].map_id != 0 && D_8036E2A0[i].map_id != map_id; i++){}

    if( D_8036E2A0[i].map_id != 0 && sns_get_item_state(D_8036E2A0[i].sns_id, 1)){
        map_id = D_8036E2A0[i].unk2;
    }

    for(i = 0; D_8036DE80[i].unk0 != 0; i++){
        if( D_8036DE80[i].unk0 == map_id)
            return i;
    }

    return 0;
}
#endif

s32 func_803226BC(enum map_e map_id){
    return D_8036DE80[func_803225E0(map_id)].unk6;
}

s32 func_803226E8(enum map_e map_id){
    return D_8036DE80[func_803225E0(map_id)].unk2;
}

s32 func_80322714(enum map_e map_id){
    return D_8036DE80[func_803225E0(map_id)].unk4;
}

s32 func_80322740(void){
    return D_80383340.unk4;
}

s32 func_8032274C(void){
    return D_80383340.unk0;
}

s32 func_80322758(void){
    return D_80383340.unk2;
}

void func_80322764(void){
    D_80383348 = FALSE;
     D_80383340.unk0 = D_80383340.unk2 = D_80383340.unk4 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9B650/func_8032278C.s")
// extern s32 D_8036E2B4;

// void func_8032278C(s32 arg0, s32 arg1) {
//     s32 temp_v0;

//     D_80383340.unk4 = func_803226BC(map_get());
//     D_80383340.unk0 = func_803226E8(map_get());
//     D_80383340.unk2 = func_80322714(map_get());
//     if (arg1 == 3) {
//         D_8036E2B4 = 1;
//         return;
//     }
//     temp_v0 = func_80322740();
//     if ((arg1 == 2) && ((D_8036E2B4 != 0) || (arg0 != 1))) {
//         D_8036E2B4 = 0;
//         if (D_80383348 == 0) {
//             if ((temp_v0 & 1) != 0) {
//                 func_8024ADF0(0);
//             } else {
//                 func_8024ADF0(1);
//             }
//         } else {
//             D_80383348 = 0;
//             func_8024BD08(1);
//         }
//     }
//     if ((arg0 == 1) && (arg1 == 2)) {
//         func_8025A430(-1, 0xFA0, 8);
//     }
//     if ((arg1 == 1) && (arg0 == 2)) {
//         func_8025A430(0, 0xFA0, 8);
//     }
// }


void func_803228D8(void){
    if(!D_80383348){
        func_8024BD08(0);
        D_80383348 = TRUE;
    }
}

int func_80322914(void){
    return D_80383348;
}
