#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    s32 unk0;
    s32 unk4;
}struct_core2_35520;

extern s32 D_80365C4C;
extern struct_core2_35520 D_80365C64[];

extern s32 D_8037D930;
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_35520/func_802BC4B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_35520/func_802BC538.s")

void func_802BC5CC(void){
    int i;
    int overlay;
    overlay = get_loaded_overlay_id();
    D_8037D930 = &D_80365C4C;
    for(i = 0; D_80365C64[i].unk0; i++){
        if(D_80365C64[i].unk0 == overlay){
            D_8037D930 = D_80365C64[i].unk4;
        }
    }
}
