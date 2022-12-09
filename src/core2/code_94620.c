#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "structs.h"

/* .bss */
s32 D_80383150;
s32 pad_80383154;
struct {
    u8 unk0;
    void *unk4;
    s32 unk8;
}
D_80383158;

s32 func_8031B5B0(void) {
    return D_80383158.unk0;
}

s32 func_8031B5BC(void){ return 1; }

void func_8031B5C4(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < func_8031B5BC())) {
        D_80383158.unk0 = (s8) arg0;
    }
    D_80383150 = 1;
}

bool func_8031B604(char *arg0) {
    return (arg0[0] == 0xFD) && (arg0[1] == 0x6A);
}

void func_8031B62C(void) {
    D_80383158.unk0 = (u8)0;
}

s32 func_8031B638(void) {
    return D_80383150;
}

void func_8031B644(void){
    D_80383158.unk4 = NULL;
    D_80383158.unk8 = -1;
}

void func_8031B65C(void){}

void func_8031B664(void){}

char *func_8031B66C(enum asset_e text_id) {
    char *sp1C;
    s32 var_v0;
    s32 var_a0;

    D_80383158.unk4 = assetcache_get(text_id);
    sp1C = (s32)D_80383158.unk4 + 1;
    sp1C += func_8031B5B0()*2;
    var_a0 = *(sp1C++);
    var_a0 += *(sp1C++)<< 8;
    if(sp1C);
    var_v0 = (s32)D_80383158.unk4 + var_a0;
    D_80383158.unk8 = text_id;
    return var_v0;
}

void func_8031B6D8(s32 arg0){
    assetcache_release(D_80383158.unk4);
    D_80383158.unk4 = NULL;
    D_80383158.unk8 = -1;
}
