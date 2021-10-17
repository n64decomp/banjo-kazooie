#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80336924(Gfx*, Vtx*, BKSprite *, s32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344090.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344124.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_803449DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_803449FC.s")



#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344A1C.s")
#else
BKSpriteDisplayData * func_80344A1C(BKSprite *arg0){
    s32 header_size; //s7
    BKSpriteDisplayData *s6;
    Gfx *gfx_end; //sp394
    Vtx* vtx_start; //s4
    Gfx *gfx_start; //s5
    s16 frame_vtx_size[200]; //sp1FC
    s16 frame_gfx_size[200]; //sp6C;
    int i;
    s32 s1;
    BKSpriteFrameDisplayData *v1;
    Vtx* vtx_end; //sp5C

    header_size = ALIGN(sizeof(BKSpriteDisplayData)+ sizeof(BKSpriteFrameDisplayData)*arg0->frameCnt, 0x10);
    s1 = 0;
    s6 = (BKSpriteDisplayData *) malloc(header_size);
    s6->unk0 = arg0;
    for(i = 0; i < arg0->frameCnt; i++){//L80344A88
        s1 = ALIGN(s1, 0x10);
        s6 = realloc(s6, header_size + s1 + 0x12C0);
        vtx_start = (s32)s6 + header_size + s1;
        gfx_start = vtx_start + 200;
        vtx_end = vtx_start;
        gfx_end = gfx_start;
        func_80336924(&gfx_end, &vtx_end, arg0, i, 1);
        gSPEndDisplayList(gfx_end++);
        frame_vtx_size[i] = ALIGN(sizeof(Vtx)*(vtx_end - vtx_start), 0x10);
        frame_gfx_size[i] = sizeof(Gfx)*(gfx_end - gfx_start);
        s1 += frame_vtx_size[i] + frame_gfx_size[i];
        memcpy((s32)vtx_start + frame_vtx_size[i], gfx_start, frame_gfx_size[i]);
        s6 = realloc(s6, header_size + s1);
    }//L80344B6C
    osWritebackDCache(s6, header_size + s1);
    s1 = 0;
    v1 = s6->frame
    for(i = 0; i < arg0->frameCnt; i++){//L80344B94
        v1[i].unk4 = ((s32)s6 + header_size) + s1;
        v1[i].unk0 = (s32)v1[i].unk4 + frame_vtx_size[i];
        s1 += ALIGN(frame_vtx_size[i] + frame_gfx_size[i], 0x10);
    }//L80344BE0
    return s6;
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344C2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344C50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344C80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344CDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344D94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344DD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344E18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344E7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344F18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344FF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80345000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_803450B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80345138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_803451B0.s")
