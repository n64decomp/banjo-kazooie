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

// Unclear, why the bitfield functions are in this file, while they are only used in gccube.c?

struct bitfield_s *bitfield_new(s32 count) {
    struct bitfield_s *bitfield = (struct bitfield_s*) malloc(sizeof(struct bitfield_s) + ((count + 31) >> 5) * sizeof(s32));
    bitfield->count = count;
    return bitfield;
}

void bitfield_free(struct bitfield_s *this) {
    free(this);
}

void bitfield_setBit(struct bitfield_s *this, s32 index, bool value) {
    if (value) {
        this->data[index >> 5] |= 1 << (index & 0x1F);
    }
    else {
        this->data[index >> 5] -= this->data[index >> 5] & (1 << (index & 0x1F));
    }
}

bool bitfield_isBitSet(struct bitfield_s *this, s32 index) {
    return BOOL(this->data[index >> 5] & (1 << (index & 0x1F)));
}

void bitfield_setAll(struct bitfield_s *this, bool value) {
    s32 i;

    for (i = 0; i < this->count; i++) {
        bitfield_setBit(this, i, value);
    }
}

s32 mapSpecificFlags_validateCRC1(void){
    return _mapSpecificFlags_calcCRC1() == D_8037DDE0;
}
