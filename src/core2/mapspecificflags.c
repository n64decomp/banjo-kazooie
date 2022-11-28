#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void mapSpecificFlags_set(s32 i, s32 val);

/* .data */
u32 D_80367000 = 0;

/* .bss */
u32 D_8037DDE0;
u32 D_8037DDE4;
u32 D_8037DDE8;

/* .code */
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

s32 *func_802CAEBC(s32 arg0){
    s32 *phi_v0;

    phi_v0 = (s32*)malloc( (((arg0 + 0x1F)>>5) + 1)*sizeof(s32));
    *phi_v0 = arg0;
    return phi_v0;
}

void func_802CAEF4(s32 *arg0){
    free(arg0);
}

void func_802CAF14(s32 *arg0, s32 arg1, bool arg2){
    if(arg2){
        arg0[(arg1 >> 5) + 1] |= 1 << (arg1 & (0x1F));
    }
    else{
        arg0[(arg1 >> 5) + 1] -= arg0[(arg1 >> 5) + 1] & (1 << (arg1 & 0x1F));
    }
}

bool func_802CAF70(s32 *arg0, s32 arg1){
    return (arg0[(arg1 >> 5) + 1] & (1 << (arg1 & 0x1F))) ? TRUE : FALSE;
}

void func_802CAFA8(s32 *arg0, bool arg1) {
    s32 i;

    for(i = 0; i < *arg0; i++){
        func_802CAF14(arg0, i, arg1);
    }
}

s32 mapSpecificFlags_validateCRC1(void){
    return _mapSpecificFlags_calcCRC1() == D_8037DDE0;
}
