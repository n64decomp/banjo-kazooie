#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "structs.h"

/* .bss */
s32 D_80383150;
s32 pad_80383154;
struct {
    u8 unk0;
    char *ptr;
    s32 index;
} s_dialogBin;

s32 code94620_func_8031B5B0(void) {
    return s_dialogBin.unk0;
}

s32 func_8031B5BC(void){ return 1; }

void func_8031B5C4(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < func_8031B5BC())) {
        s_dialogBin.unk0 = (s8) arg0;
    }
    D_80383150 = 1;
}

bool func_8031B604(char *arg0) {
    return (arg0[0] == 0xFD) && (arg0[1] == 0x6A);
}

void func_8031B62C(void) {
    s_dialogBin.unk0 = (u8)0;
}

s32 func_8031B638(void) {
    return D_80383150;
}

void dialogBin_initialize(void){
    s_dialogBin.ptr = NULL;
    s_dialogBin.index = -1;
}

void dialogBin_update(void){}

void dialogBin_terminate(void){}

char *dialogBin_get(enum asset_e text_id) {
    char *sp1C;
    char *var_v0;
    s32 var_a0; //offset where text starts (normally 0x3)

    //get text_bin from asset cache
    s_dialogBin.ptr = assetcache_get(text_id);
    sp1C = s_dialogBin.ptr + 1;
    sp1C += code94620_func_8031B5B0()*2;
    var_a0 = *(sp1C++);
    var_a0 += *(sp1C++)<< 8;
    if(sp1C);
    var_v0 = s_dialogBin.ptr + var_a0;
    s_dialogBin.index = text_id;
    return var_v0;
}

void dialogBin_release(s32 arg0){
    assetcache_release(s_dialogBin.ptr);
    s_dialogBin.ptr = NULL;
    s_dialogBin.index = -1;
}
