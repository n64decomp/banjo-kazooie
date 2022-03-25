#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Vtx *vtxList_getVertices(BKVertexList *vtxList){
    return &vtxList->vtx_18[0];
}

//vtxList_getBoundingBox_i
void func_802EC458(BKVertexList *vtxList, s32 min[3], s32 max[3]){
    min[0] = vtxList->minCoord_0[0];
    min[1] = vtxList->minCoord_0[1];
    min[2] = vtxList->minCoord_0[2];

    max[0] = vtxList->maxCoord_6[0];
    max[1] = vtxList->maxCoord_6[1];
    max[2] = vtxList->maxCoord_6[2];
}

//vtxList_getBoundingBox_f
void func_802EC48C(BKVertexList *vtxList, f32 min[3], f32 max[3]){
    min[0] = (f32) vtxList->minCoord_0[0];
    min[1] = (f32) vtxList->minCoord_0[1];
    min[2] = (f32) vtxList->minCoord_0[2];

    max[0] = (f32) vtxList->maxCoord_6[0];
    max[1] = (f32) vtxList->maxCoord_6[1];
    max[2] = (f32) vtxList->maxCoord_6[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802EC508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802EC680.s")

//vtxList_getBeginAndEndPtrs
void func_802EC8FC(BKVertexList *this, Vtx **vtx, Vtx **vtx_end){
    *vtx = &this->vtx_18[0];
    *vtx_end = &(*vtx)[this->cnt_14];
}

//vtxList_getVtxCount
s32 func_802EC918(BKVertexList *this){
    return this->cnt_14;
}

f32 func_802EC920(BKVertexList *this){
    return (f32)this->unk16;
}

void func_802EC930(BKVertexList *this, f32 arg1[3], f32 *arg2){
    arg1[0] = (f32)this->unkC[0];
    arg1[1] = (f32)this->unkC[1];
    arg1[2] = (f32)this->unkC[2];
    *arg2 = this->unk12; 
}

f32 func_802EC984(BKVertexList *this){
    return (f32)this->unk12;
}

void vtxList_free(BKVertexList *vtxList){
    free(vtxList);
}

BKVertexList *vtxList_clone(BKVertexList *vtxList){
    BKVertexList *out_v0;
    size_t list_size;
    
    list_size = sizeof(BKVertexList) + vtxList->cnt_14*sizeof(Vtx);
    out_v0 = (BKVertexList *) malloc(list_size);
    func_80254630(out_v0, vtxList, list_size);
    return out_v0;
}

// vtxList_copy_colors
void func_802EC9FC(BKVertexList *dst, BKVertexList *src) {
    Vtx *start_ptr;
    Vtx *end_ptr;
    Vtx *i_ptr;
    Vtx *src_ptr;
    s32 i;

    src_ptr = &src->vtx_18[0];
    start_ptr = &dst->vtx_18[0];
    end_ptr = start_ptr + dst->cnt_14;
    for(i_ptr = start_ptr; i_ptr < end_ptr; i_ptr++, src_ptr++){
            i_ptr->v.cn[0] = src_ptr->v.cn[0];
            i_ptr->v.cn[1] = src_ptr->v.cn[1];
            i_ptr->v.cn[2] = src_ptr->v.cn[2];
            i_ptr->v.cn[3] = src_ptr->v.cn[3];
    }
    osWritebackDCache(start_ptr, ((s32)(end_ptr - start_ptr)) * sizeof(Vtx));
}

void vtxList_tint(BKVertexList *dst, s32 target_color[3], f32 amount, BKVertexList *src) {
    Vtx *start_ptr;
    Vtx *end_ptr;
    Vtx *i_ptr;
    Vtx *src_ptr;
    s32 i;

    start_ptr = &dst->vtx_18[0];
    end_ptr = start_ptr + dst->cnt_14;
    for(i_ptr = start_ptr, src_ptr = &src->vtx_18[0]; i_ptr < end_ptr; i_ptr++, src_ptr++){
        for(i = 0; i < 3; i++){
            i_ptr->v.cn[i] = src_ptr->v.cn[i] + (target_color[i] - src_ptr->v.cn[i]) * amount;
        }
    }
    osWritebackDCache(start_ptr, ((s32)(end_ptr - start_ptr)) * sizeof(Vtx));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802ECBD4.s")

void func_802ECE30(BKVertexList *arg0) {
    Vtx *start_ptr;
    Vtx *end_ptr;
    Vtx *i_ptr;
    s32 i;

    start_ptr = &arg0->vtx_18[0];
    end_ptr = start_ptr + arg0->cnt_14;
    for(i_ptr = start_ptr; i_ptr < end_ptr; i_ptr++){
        for(i = 0; i < 3; i++){
            i_ptr->v.cn[i] = 0;
        }
        i_ptr->v.cn[0] = randf() * 255.0f;
    }
    osWritebackDCache(start_ptr, ((s32)(end_ptr - start_ptr)) * sizeof(Vtx));
}

void func_802ECF64(BKVertexList *arg0) {
    Vtx *start_ptr;
    Vtx *end_ptr;
    Vtx *i_ptr;
    s32 i;
    s32 phi_s0;

    start_ptr = &arg0->vtx_18[0];
    end_ptr = start_ptr + arg0->cnt_14;
    for(i_ptr = start_ptr; i_ptr < end_ptr; i_ptr++){
        for(i = 0; i < 3; i++){
            phi_s0 = i_ptr->v.cn[i];
            phi_s0 += randf()*21.0f - 10.0f;
            phi_s0 = (phi_s0 > 0xff) ? 0xff : phi_s0;
            phi_s0 =  (phi_s0 < 0) ? 0 : phi_s0;
            i_ptr->v.cn[i] = phi_s0;
        }
    }
    osWritebackDCache(start_ptr, ((s32)(end_ptr - start_ptr)) * sizeof(Vtx));
}

void vtxList_recolor(BKVertexList *arg0, s32 arg1[3]) {
    Vtx *start_ptr;
    Vtx *end_ptr;
    Vtx *i_ptr;
    s32 i;
    s32 phi_s0;

    start_ptr = &arg0->vtx_18[0];
    end_ptr = start_ptr + arg0->cnt_14;
    for(i_ptr = start_ptr; i_ptr < end_ptr; i_ptr++){
        for(i = 0; i < 3; i++){
            i_ptr->v.cn[i] = arg1[i];
        }
    }
    osWritebackDCache(start_ptr, ((s32)(end_ptr - start_ptr)) * sizeof(Vtx));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802ED108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802ED12C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802ED138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802ED180.s")

void func_802ED340(BKVertexList *arg0, s32 indx, f32 dst[3]){
    Vtx *vtx;

    vtx = (s32)(arg0 + 1) + (indx * sizeof(Vtx));
    dst[0] = (f32) vtx->v.ob[0];
    dst[1] = (f32) vtx->v.ob[1];
    dst[2] = (f32) vtx->v.ob[2];
}

void func_802ED38C(BKVertexList *arg0, s32 indx, f32 arg2[3]){
    Vtx *vtx;
    s32 i;

    vtx = (s32)(arg0 + 1) + (indx * sizeof(Vtx));
    for(i = 0; i < 3; i++){
        vtx->v.ob[i] = (arg2[i] >= 0.0) ? arg2[i] + 0.5 :  arg2[i] - 0.5;
    }
}
