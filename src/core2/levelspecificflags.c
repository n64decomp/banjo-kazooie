#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void levelSpecificFlags_set(arg0, arg1);


//levelSpecificFlags
extern u8  D_80383328[];
extern u32 D_80383320;
extern u32 D_80383324;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/levelspecificflags/_levelSpecificFlags_calcCRC1.s")

void _levelSpecificFlags_updateCRC1(void) {
    s32 temp_a0;

    temp_a0 = (s32) &D_80383320 ^ ((((s32) &D_80383320 >> 8) & 0xFF0000) + (((s32) &D_80383320 & 0xFF) << 8));
    *(u32 *)((((u32) (temp_a0 & 0xFF000000) >> 8) + ((temp_a0 << 8) & 0xFF00)) ^ temp_a0) = _levelSpecificFlags_calcCRC1();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/levelspecificflags/_levelSpecificFlags_calcCRC2.s")

void _levelSpecificFlags_updateCRC2(void) {
    *(u32 *)(((((s32) (((((s32) &D_80383324 >> 0x10) & 0xFFFF) ^ 0x195D) * 0x2F) / 0x2F) << 0x10) + ((s32) ((((s32) &D_80383324 & 0xFFFF) ^ 0xA832) << 0xD) / 0x2000)) ^ 0x195DA832) = _levelSpecificFlags_calcCRC2();
}

s32 levelSpecificFlags_get(s32 i){
    return func_803200A4(D_80383328, i);
}

s32 levelSpecificFlags_getN(s32 i, s32 n){
    return func_803200E4(D_80383328, i, n);
}

s32 levelSpecificFlags_getSet(s32 arg0, s32 arg1){
    s32 retVal = levelSpecificFlags_get(arg0);
    levelSpecificFlags_set(arg0, arg1);
    return retVal;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/levelspecificflags/levelSpecificFlags_clear.s")

void levelSpecificFlags_set(s32 index, s32 val){
    func_8032015C(&D_80383328, index, val);
    _levelSpecificFlags_updateCRC1();
    _levelSpecificFlags_updateCRC2();
}

void levelSpecificFlags_setN(s32 index, s32 val, s32 n){
    func_803201C8(&D_80383328, index, val, n);
    _levelSpecificFlags_updateCRC1();
    _levelSpecificFlags_updateCRC2();
}

s32 levelSpecificFlags_validateCRC1(void) {
    s32 temp_a0;

    temp_a0 = (((s32) &D_80383320 & 0x55555555) * 2) + ((u32) ((s32) &D_80383320 & 0xAAAAAAAA) >> 1);
    return _levelSpecificFlags_calcCRC1() == *(u32*)(((temp_a0 & 0x55555555) * 2) | ((u32) (temp_a0 & 0xAAAAAAAA) >> 1));
}

s32 levelSpecificFlags_validateCRC2(void){
    return _levelSpecificFlags_calcCRC2() == *(u32 *)((s32)&D_80383324 ^ 0x7EDDF5F4 ^ 0x7BEF9D80 ^ 0x5326874);
}