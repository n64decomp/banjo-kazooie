#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80336924(Gfx*, Vtx*, BKSprite *, s32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344090.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344124.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BD100/func_80344138.s")
#else
extern f32 D_80379080;
extern f32 D_80379084;
extern struct {
    void (*unk0)(void *);
    void *unk4;
}D_80371EC0;
extern f32 D_80371ECC;
extern u8 D_803858B0;

extern void func_80252330(f32, f32, f32);

void func_80344138(BKSpriteDisplayData *self, s32 frame, s32 arg2, f32 position[3], f32 arg4[3], Gfx **gfx, Mtx **mtx) {
    f32 sp6C[3];
    f32 sp60[3];
    f32 temp_f14;
    f32 sp50[3];
    BKSprite *temp_v0;
    f32 var_f2_2;
    BKSpriteFrameDisplayData *temp_a3;
    f32 sp30[3];

    func_8024C5CC(&sp6C);
    func_8024C5A8(&sp60);
    sp50[0] = position[0] - sp6C[0];
    sp50[1] = position[1] - sp6C[1];
    sp50[2] = position[2] - sp6C[2];
    temp_f14 = sp60[0]*sp50[0] + sp60[1]*sp50[1] + sp60[2]*sp50[2];
    if ((temp_f14 < 0.0f) || (D_80379080 < temp_f14)) {
        func_80344124();
        return;
    }
    if (arg4 != NULL) {
        sp30[0] = arg4[0];
        sp30[1] = arg4[1];
        sp30[2] = arg4[2];
    } else {
        sp30[0] = sp30[1] = sp30[2] = 1.0f;
    }


    var_f2_2 = (self->sprite->unkA * sp30[2] <= self->sprite->unk8 * sp30[0]) ? self->sprite->unk8 * sp30[0] : self->sprite->unkA * sp30[2];
    if ((D_80379084 < temp_f14) && ((var_f2_2 / temp_f14) < D_80371ECC) && (D_803858B0 == 0)) {
        func_80344124();
        return;
    }
    if (D_80371EC0.unk0 != NULL) {
        D_80371EC0.unk0(D_80371EC0.unk4);
    }
    func_80251BCC(func_8024DD90());
    func_80252330(sp50[0], sp50[1], sp50[2]);
    if ((arg4 != NULL) || (arg2 != 0)) {
        mlMtxScale_xyz((arg2 != 0) ? -arg4[0] : arg4[0], sp30[2], sp30[1]);
    }
    mlMtxApply(*mtx);
    gSPMatrix((*gfx)++, (*mtx)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    temp_a3 = &self->frame[frame];
    gSPSegment((*gfx)++, 1, osVirtualToPhysical(temp_a3->vtx));
    gSPDisplayList((*gfx)++, temp_a3->gfx);
    if(temp_a3);
    gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);
    func_80349AD0();
    func_80344124();
}
#endif


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
