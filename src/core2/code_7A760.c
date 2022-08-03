#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern BKSprite *D_8036A960;

/* .rodata */
extern f64 D_803774A0;

/* .bss */
s32 D_80381F50;
f32 D_80381F54;
f32 D_80381F58;
f32 D_80381F5C;
f32 D_80381F60;
f32 D_80381F68[6];
struct7s D_80381F80;

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7A760/func_803016F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7A760/func_80301754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7A760/func_8030179C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7A760/func_803017D0.s")

bool func_80301CE0(f32, s32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7A760/func_80301CE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7A760/func_80301D24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7A760/func_80301DBC.s")

#ifndef NONMATCHING //probably just need .rodata defined
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7A760/func_80301DE4.s")
#else
void func_80301DE4(enum item_e arg0, struct7s *arg1) {
    s32 temp_s0;
    s32 var_s0;

    temp_s0 = func_802FB0D4(arg1);
    if (D_80381F50 == 0) {
        D_80381F60 = (f32) func_80301D24(itemPrint_getValue(arg0));
    }
    switch (temp_s0) {
        case 2:
            break;
        case 1:
            if (D_8036A960 == NULL) {
                D_8036A960 = (BKSprite *)assetcache_get(ASSET_7E5_SPRITE_WATER_HONEYCOMB);
            }
            break;
        case 0:
            func_80301754(arg0, arg1);
            break;
    }
    if (temp_s0 != 0) {
        for(var_s0 = 5; var_s0 >= 0; var_s0--){
            if (func_80301CE0(-15.0f, var_s0, 6)) {
                D_80381F68[var_s0] *= D_803774A0;
            }
        }
    }
}
#endif
