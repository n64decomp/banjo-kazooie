#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Vtx *vtxList_getVertices(BKVertexList *vtxList){
    return (Vtx *)&vtxList->vtx_18[0];
}

//vtxList_getBoundingBox
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802EC8FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802EC918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802EC920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802EC930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802EC984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802EC994.s")

BKVertexList *func_802EC9B4(BKVertexList *vtxList){
    BKVertexList *out_v0;
    size_t list_size;
    
    list_size = sizeof(BKVertexList) + vtxList->unk14*sizeof(Vtx);
    out_v0 = (BKVertexList *) malloc(list_size);
    func_80254630(out_v0, vtxList, list_size);
    return out_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802EC9FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802ECA7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802ECBD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802ECE30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802ECF64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802ED074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802ED108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802ED12C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802ED138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802ED180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802ED340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_654C0/func_802ED38C.s")
