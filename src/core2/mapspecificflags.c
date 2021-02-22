#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void mapSpecificFlags_set(s32 i, s32 val);

extern u32 D_8037DDE0;
extern u32 D_8037DDE4;
extern u32 D_8037DDE8;
extern u32 D_80367000;

u32 _mapSpecificFlags_calcCRC1(void){
    return D_80367000 ^ 0x1195E97;
}

void _mapSpecificFlags_updateCRCs(void){
    D_8037DDE4 = D_80367000 ^ 0xA84E38C8;
    D_8037DDE0 = _mapSpecificFlags_calcCRC1();
    D_8037DDE8 = D_80367000 ^ 0x3973e4d9;
}

void mapSpecificFlags_clearAll(void){
    D_80367000 = 0;
    _mapSpecificFlags_updateCRCs();
}

s32 mapSpecificFlags_get(s32 i){
    return (D_80367000 & (1 << i))? 1 : 0;
}

u32 mapSpecificFlags_getN(s32 idx, s32 n){
    s32 i;
    u32 ret_val = 0;
    for(i = 0; i < n; i++){
       ret_val |= mapSpecificFlags_get(idx + i) << i;
    }
    return ret_val;
}

u32 mapSpecificFlags_getClear(s32 i){
    u32 ret_val = mapSpecificFlags_get(i);
    mapSpecificFlags_set(i, 0);
    return ret_val;
}

void mapSpecificFlags_set(s32 i, s32 val){
    if(val)
        D_80367000 |= 1 << i;
    else
        D_80367000 &= ~(1 << i);
    _mapSpecificFlags_updateCRCs();
}

void mapSpecificFlags_setN(s32 idx, s32 val, s32 n){
    s32 i;
    for(i = 0; i < n; i++){
       mapSpecificFlags_set(idx + i, (1 << i) & val);
    }
}

u32 mapSpecificFlags_getAll(void){
    return D_80367000;
}

void mapSpecificFlags_setAll(u32 arg0){
    D_80367000 = arg0;
    _mapSpecificFlags_updateCRCs();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/mapspecificflags/func_802CAEBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/mapspecificflags/func_802CAEF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/mapspecificflags/func_802CAF14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/mapspecificflags/func_802CAF70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/mapspecificflags/func_802CAFA8.s")

s32 mapSpecificFlags_validateCRC1(void){
    return _mapSpecificFlags_calcCRC1() == D_8037DDE0;
}