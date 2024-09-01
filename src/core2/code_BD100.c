#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void spriteRender_drawWithSegment(Gfx**, Vtx**, BKSprite *, s32, s32);
extern void func_80252330(f32, f32, f32);
extern void mlMtxRotatePYR(f32, f32, f32);
extern void mlMtxApply(Mtx *);
extern void func_80349AD0(void);
extern void func_8024C5A8(f32[3]);



/* .data */
struct {
    void (*unk0)(ActorMarker *);
    void *unk4;
    s32 unk8;
}D_80371EC0 = {0};
f32 D_80371ECC = 0.1f;

/* .bss */
u8 D_803858B0;

/* .code */
void func_80344090(BKSpriteDisplayData *self, s32 frame, Gfx **gfx) {
    BKSpriteFrameDisplayData *temp_a1;

    func_80349AD0();
    temp_a1 = (BKSpriteFrameDisplayData *)((s32)self + sizeof(BKSpriteDisplayData) + frame*sizeof(BKSpriteFrameDisplayData));
    gSPSegment((*gfx)++, 1, osVirtualToPhysical(temp_a1->vtx));
    gSPDisplayList((*gfx)++, temp_a1->gfx);
}


void func_80344124(void){
    D_80371EC0.unk0 = NULL;
    D_803858B0 = FALSE;
}

void func_80344138(BKSpriteDisplayData *self, s32 frame, s32 mirrored, f32 position[3], f32 scale[3], Gfx **gfx, Mtx **mtx) {
    f32 sp6C[3];
    f32 sp60[3];
    f32 temp_f14;
    f32 sp50[3];
    f32 temp_f0;
    f32 temp_f12;
    f32 var_f2_2;
    BKSpriteFrameDisplayData *temp_a3;
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    viewport_get_position_vec3f(sp6C);
    func_8024C5A8(sp60);
    sp50[0] = position[0] - sp6C[0];
    sp50[1] = position[1] - sp6C[1];
    sp50[2] = position[2] - sp6C[2];
    temp_f14 = sp60[0]*sp50[0] + sp60[1]*sp50[1] + sp60[2]*sp50[2];
    if ((temp_f14 < 0.0f) || (20000.0f < temp_f14)) {
        func_80344124();
        return;
    }
    if (scale != NULL) {
        sp3C = scale[0];
        sp38 = scale[1];
        sp34 = scale[2];
    } else {
        sp3C = 1.0f;
        sp34 = 1.0f;
        sp38 = 1.0f;
    }

    temp_f0 = sp3C * self->sprite->unk8;
    temp_f12 = sp38 * self->sprite->unkA;
    var_f2_2 = (temp_f12 <= temp_f0) ? temp_f0 : temp_f12;
    if ((3000.0f < temp_f14) && ((var_f2_2 / temp_f14) < D_80371ECC) && !D_803858B0) {
        func_80344124();
        return;
    }
    if (D_80371EC0.unk0 != NULL) {
        D_80371EC0.unk0(D_80371EC0.unk4);
    }
    mlMtxSet(func_8024DD90());
    func_80252330(sp50[0], sp50[1], sp50[2]);
    if ((scale != NULL) || mirrored) {
        mlMtxScale_xyz((mirrored) ? -scale[0] : scale[0], sp38, sp34);
    }
    mlMtxApply(*mtx);
    gSPMatrix((*gfx)++, (*mtx)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    temp_a3 = (BKSpriteFrameDisplayData *)((s32)self + sizeof(BKSpriteDisplayData) + frame*sizeof(BKSpriteFrameDisplayData));
    gSPSegment((*gfx)++, 1, osVirtualToPhysical(temp_a3->vtx));
    gSPDisplayList((*gfx)++, temp_a3->gfx);
    gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);
    func_80349AD0();
    func_80344124();
}

void func_80344424(BKSpriteDisplayData *arg0, s32 frame, bool mirrored, f32 position[3], f32 scale[3], f32 rotation, Gfx **gfx, Mtx **mtx) {
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp5C;
    f32 sp50[3];
    f32 temp_f0;
    f32 temp_f12;
    f32 var_f2_2;
    BKSpriteFrameDisplayData *temp_a3;
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    viewport_get_position_vec3f(sp6C);
    func_8024C5A8(sp60);
    sp50[0] = position[0] - sp6C[0];
    sp50[1] = position[1] - sp6C[1];
    sp50[2] = position[2] - sp6C[2];
    sp5C = sp60[0]*sp50[0] + sp60[1]*sp50[1] + sp60[2]*sp50[2];
    if ((sp5C < 0.0f) || (20000.0f < sp5C)) {
        func_80344124();
        return;
    }
    if (scale != NULL) {
        sp3C = scale[0];
        sp38 = scale[1];
        sp34 = scale[2];
    } else {
        sp3C = 1.0f;
        sp34 = 1.0f;
        sp38 = 1.0f;
    }

    temp_f0 = sp3C * arg0->sprite->unk8;
    temp_f12 = sp38 * arg0->sprite->unkA;
    var_f2_2 = (temp_f12 <= temp_f0) ? temp_f0 : temp_f12;
    if ((3000.0f < sp5C) && ((var_f2_2 / sp5C) < D_80371ECC) && !D_803858B0) {
        func_80344124();
        return;
    }

    if (D_80371EC0.unk0 != NULL) {
        D_80371EC0.unk0(D_80371EC0.unk4);
    }
    mlMtxSet(func_8024DD90());
    mlMtxRotatePYR(0.0f, 0.0f, rotation);
    func_80252330(sp50[0], sp50[1], sp50[2]);
    if ((scale != NULL) || mirrored) {
        mlMtxScale_xyz((mirrored) ? -scale[0] : scale[0], sp38, sp34);
    }
    mlMtxApply(*mtx);
    gSPMatrix((*gfx)++, (*mtx)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    temp_a3 = (BKSpriteFrameDisplayData *)((s32)arg0 + sizeof(BKSpriteDisplayData) + frame*sizeof(BKSpriteFrameDisplayData));
    gSPSegment((*gfx)++, 1, osVirtualToPhysical(temp_a3->vtx));
    gSPDisplayList((*gfx)++, temp_a3->gfx);
    gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);
    func_80349AD0();
    func_80344124();
}


void func_80344720(BKSpriteDisplayData *arg0, s32 frame, bool mirrored, f32 position[3], f32 rotation[3], f32 scale[3], Gfx **gfx, Mtx **mtx) {
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp4C;
    f32 sp40[3];
    f32 temp_f0;
    f32 temp_f12;
    f32 var_f14;
    BKSpriteFrameDisplayData *temp_a3;

    viewport_get_position_vec3f(sp5C);
    func_8024C5A8(sp50);
    sp40[0] = position[0] - sp5C[0];
    sp40[1] = position[1] - sp5C[1];
    sp40[2] = position[2] - sp5C[2];
    sp4C = sp50[0]*sp40[0] + sp50[1]*sp40[1] + sp50[2]*sp40[2];
    if ((sp4C < 0.0f) || (20000.0f < sp4C)) {
        func_80344124();
        return;
    }

    temp_f0 = scale[0] * arg0->sprite->unk8;
    temp_f12 = scale[1] * arg0->sprite->unkA;
    var_f14 = (temp_f12 <= temp_f0) ? temp_f0 : temp_f12;
    if ((3000.0f < sp4C) && ((var_f14 / sp4C) < D_80371ECC) && !D_803858B0) {
        func_80344124();
        return;
    }

    if (D_80371EC0.unk0 != NULL) {
        D_80371EC0.unk0(D_80371EC0.unk4);
    }
    mlMtxIdent();
    func_80252330(sp40[0], sp40[1], sp40[2]);
    mlMtxRotatePYR(rotation[0], rotation[1], rotation[2]);
    mlMtxScale_xyz((mirrored) ? -scale[0] : scale[0], scale[1], scale[2]);
    mlMtxApply(*mtx);
    gSPMatrix((*gfx)++, (*mtx)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    temp_a3 = (BKSpriteFrameDisplayData *)((s32)arg0 + sizeof(BKSpriteDisplayData) + frame*sizeof(BKSpriteFrameDisplayData));
    gSPSegment((*gfx)++, 1, osVirtualToPhysical(temp_a3->vtx));
    gSPDisplayList((*gfx)++, temp_a3->gfx);
    gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);
    func_80349AD0();
    func_80344124();
}


void func_803449DC(BKSpriteDisplayData *arg0){
    free(arg0);
}

void func_803449FC(BKSpriteDisplayData *arg0){
    func_80255170(&arg0->sprite);
}

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
    s6->sprite = arg0;
    for(i = 0; i < arg0->frameCnt; i++){//L80344A88
        s1 = ALIGN(s1, 0x10);
        s6 = (BKSpriteDisplayData *)realloc(s6, header_size + s1 + 0x12C0);
        vtx_start = (Vtx *)((s32)s6 + header_size + s1);
        gfx_start = (Gfx *)(vtx_start + 200);
        vtx_end = vtx_start;
        gfx_end = gfx_start;
        spriteRender_drawWithSegment(&gfx_end, &vtx_end, arg0, i, 1);
        gSPEndDisplayList(gfx_end++);
        frame_vtx_size[i] = ALIGN(sizeof(Vtx)*(vtx_end - vtx_start), 0x10);
        frame_gfx_size[i] = sizeof(Gfx)*(gfx_end - gfx_start);
        s1 += frame_vtx_size[i] + frame_gfx_size[i];
        memcpy((void *)((s32)vtx_start + frame_vtx_size[i]), gfx_start, frame_gfx_size[i]);
        s6 = realloc(s6, header_size + s1);
    }//L80344B6C
    osWritebackDCache(s6, header_size + s1);
    v1 = &s6->frame[0];
    s1 = 0;\
    for(i = 0; i < arg0->frameCnt; i++, v1++){//L80344B94
        v1->vtx = (Vtx *)(s1 + ((s32)s6 + header_size));
        v1->gfx = (Gfx *)((s32)v1->vtx + frame_vtx_size[i]);
        s1 += ALIGN(frame_vtx_size[i] + frame_gfx_size[i], 0x10);
    }//L80344BE0
    return s6;
}

s32 func_80344C14(UNK_TYPE(s32) arg0){
    return 0;
}

s32 func_80344C20(BKSpriteDisplayData *self){
    return self->sprite->type;
}

void func_80344C2C(bool arg0){
    D_803858B0 = arg0;
}

void func_80344C38(void (*method)(ActorMarker *), ActorMarker *marker){
    D_80371EC0.unk0 = method;
    D_80371EC0.unk4 = marker;
}
