#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_80386070;
extern s32 D_80386074;
extern s32 D_80386078;
extern s32 D_8038607C;
extern s32 D_80386094;
extern s32 D_80386098;
extern s32 D_803860B0;
extern s32 D_803860B4;

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C0CF0/func_80347C80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C0CF0/func_80347CC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C0CF0/func_80347CF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C0CF0/func_80347DD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C0CF0/func_80347DE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C0CF0/func_80347DF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C0CF0/func_80347E34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C0CF0/func_80347E60.s")

void func_80347FA4(s32 arg0, s32 arg1, s32 arg2, s32 arg3){}

void func_80347FB8(s32 arg0){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C0CF0/func_80347FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C0CF0/func_80348044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C0CF0/func_80349AD0.s")

void func_80349B1C(Gfx **gfx) {
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;

    if (D_803860B0) {
        gDPPipeSync((*gfx)++);
        gDPSetTextureLUT((*gfx)++, G_TT_NONE);
        D_803860B0 = FALSE;
        if (D_803860B4) {
            gDPPipelineMode((*gfx)++, G_PM_NPRIMITIVE);
            D_803860B4 = FALSE;
        }
    }
}
