#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0[3];
    f32 unkC[3];
    f32 unk18;
    u8 unk1C;
    u8 pad1D[3];
}Struct_core2_AD110_0;

vector(Struct_core2_AD110_0) *D_803835C0;

/* .code */
bool func_803340A0(f32 arg0[3], f32 arg1[3], f32 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD110/func_803340A0.s")

s32 func_803342AC(f32 arg0[3], f32 arg1[3], f32 arg2){
    Struct_core2_AD110_0 * iPtr;
    Struct_core2_AD110_0 * end_ptr;

    if(!func_803340A0(arg0, arg1, arg2))
        return 0;

    end_ptr = (Struct_core2_AD110_0 *)vector_getEnd(D_803835C0);
    for(iPtr = (Struct_core2_AD110_0 *)vector_getBegin(D_803835C0); iPtr < end_ptr; iPtr++){
        if(iPtr->unk1C == 0)
            break;
    }
    if(iPtr == end_ptr){
        iPtr = (Struct_core2_AD110_0 *)vector_pushBackNew(&D_803835C0);
    }
    iPtr->unk1C = 1;

    iPtr->unk0[0] = arg0[0];
    iPtr->unk0[1] = arg0[1];
    iPtr->unk0[2] = arg0[2];

    iPtr->unkC[0] = arg1[0];
    iPtr->unkC[1] = arg1[1];
    iPtr->unkC[2] = arg1[2];

    iPtr->unk18 = arg2;
    return (iPtr - (Struct_core2_AD110_0 *)vector_getBegin(D_803835C0)) + 1;
}


void func_803343AC(void){
    vector_free(D_803835C0);
}

void func_803343D0(void){
    D_803835C0 = vector_new(sizeof(Struct_core2_AD110_0), 2);
}

void func_803343F8(s32 indx){
    Struct_core2_AD110_0 *elem;
    elem = (Struct_core2_AD110_0 *)vector_at(D_803835C0, indx - 1);
    elem->unk1C = 0;
}

void func_80334428(void){}

void func_80334430(s32 arg0, s32 arg1){}

void func_8033443C(s32 arg0, s32 arg1){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD110/func_80334448.s")

s32 func_8033451C(s32 arg0){
    return arg0 - 0x16;
}

s32 func_80334524(s32 arg0){
    return arg0 + 0xcc;
}

s32 func_8033452C(s32 arg0){
    return arg0 + 0x19d;
}
