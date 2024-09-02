#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void levelSpecificFlags_set(arg0, arg1);

//levelSpecificFlags
/* .bss */
struct{
    u32 unk0;
    u32 unk4;
    u8  unk8[8];
}D_80383320;

/* .code */
u32 _levelSpecificFlags_calcCRC1(void) {
    s32 scrambled_ptr;
    u8 *ptr;
    u32 var_a3;
    u32 var_v1;
    u32 var_v0;

    var_v1 = 0x05C9EC23;
    scrambled_ptr = (((s32) &D_80383320.unk8 & 0x55555555) * 2) + ((u32) ((s32) &D_80383320.unk8 & 0xAAAAAAAA) >> 1);
    ptr = (((scrambled_ptr & 0x55555555) * 2) | ((u32) (scrambled_ptr & 0xAAAAAAAA) >> 1));
    var_v0 = 8;
    for(var_a3 = 0; var_a3 < var_v0; var_a3++){
        var_v1 = ((((var_v1 + ptr[var_a3]) & 0x7F) << 0x14) ^ (var_v1 >> 7)) ^ (ptr[var_a3] * 0xD);
    }
    return var_v1;
}

void _levelSpecificFlags_updateCRC1(void) {
    s32 temp_a0;

    temp_a0 = (s32) &D_80383320.unk0 ^ ((((s32) &D_80383320.unk0 >> 8) & 0xFF0000) + (((s32) &D_80383320.unk0 & 0xFF) << 8));
    *(u32 *)((((u32) (temp_a0 & 0xFF000000) >> 8) + ((temp_a0 << 8) & 0xFF00)) ^ temp_a0) = _levelSpecificFlags_calcCRC1();
}

s32 _levelSpecificFlags_calcCRC2(void) {
    s32 temp_t7;
    s32 var_v1;
    u32 var_a2;
    u8 *scrambled_ptr; 
    u8 temp_t9;
    u32 var_v0;

    var_v1 = 0x03F2F59A;
    var_v0 = 8;
    scrambled_ptr = ((((((((s32) &D_80383320.unk8 >> 0x10) & 0xFFFF) ^ 0x195D) * 0x2F) / 0x2F) << 0x10) 
                  + (((((s32) &D_80383320.unk8 & 0xFFFF) ^ 0xA832) << 0xD) / 0x2000)) 
                  ^ 0x195DA832;
    for(var_a2 = 0; var_a2 < var_v0; var_a2++){
        var_v1 += (var_a2 + 7) * scrambled_ptr[var_a2];
    };
    return var_v1;
}

void _levelSpecificFlags_updateCRC2(void) {
    *(u32 *)(((((s32) (((((s32) &D_80383320.unk4 >> 0x10) & 0xFFFF) ^ 0x195D) * 0x2F) / 0x2F) << 0x10) + ((s32) ((((s32) &D_80383320.unk4 & 0xFFFF) ^ 0xA832) << 0xD) / 0x2000)) ^ 0x195DA832) = _levelSpecificFlags_calcCRC2();
}

s32 levelSpecificFlags_get(s32 i){
    return bitfield_get_bit(D_80383320.unk8, i);
}

s32 levelSpecificFlags_getN(s32 i, s32 n){
    return bitfield_get_n_bits(D_80383320.unk8, i, n);
}

s32 levelSpecificFlags_getSet(s32 arg0, s32 arg1){
    s32 retVal = levelSpecificFlags_get(arg0);
    levelSpecificFlags_set(arg0, arg1);
    return retVal;
}

void levelSpecificFlags_clear(void){
    s32 i;
    for(i = 0; i < 8; i++){
        D_80383320.unk8[i] = 0;
    }
    _levelSpecificFlags_updateCRC1();
    _levelSpecificFlags_updateCRC2();
}

void levelSpecificFlags_set(s32 index, s32 val){
    func_8032015C(&D_80383320.unk8, index, val);
    _levelSpecificFlags_updateCRC1();
    _levelSpecificFlags_updateCRC2();
}

void levelSpecificFlags_setN(s32 index, s32 val, s32 n){
    func_803201C8(&D_80383320.unk8, index, val, n);
    _levelSpecificFlags_updateCRC1();
    _levelSpecificFlags_updateCRC2();
}

s32 levelSpecificFlags_validateCRC1(void) {
    s32 temp_a0;

    temp_a0 = (((s32) &D_80383320.unk0 & 0x55555555) * 2) + ((u32) ((s32) &D_80383320.unk0 & 0xAAAAAAAA) >> 1);
    return _levelSpecificFlags_calcCRC1() == *(u32*)(((temp_a0 & 0x55555555) * 2) | ((u32) (temp_a0 & 0xAAAAAAAA) >> 1));
}

s32 levelSpecificFlags_validateCRC2(void){
    return _levelSpecificFlags_calcCRC2() == *(u32 *)((s32)&D_80383320.unk4 ^ 0x7EDDF5F4 ^ 0x7BEF9D80 ^ 0x5326874);
}
