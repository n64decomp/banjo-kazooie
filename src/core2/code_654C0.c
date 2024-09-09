#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80252CC4(f32[3], f32 [3], f32, f32[3]);
extern f32 func_8034A9D0(f32[4], f32);

/*.bss */
struct {
    s32 unk0;
    f32 unk4[3];
    f32 unk10[3];
    f32 unk1C;
    f32 unk20[3];
}D_803808C0;

/* .code */
Vtx *vtxList_getVertices(BKVertexList *vtxList){
    return &vtxList->vtx_18[0];
}

void vtxList_getBounds_s32(BKVertexList *vtxList, s32 min[3], s32 max[3]){
    min[0] = vtxList->minCoord[0];
    min[1] = vtxList->minCoord[1];
    min[2] = vtxList->minCoord[2];

    max[0] = vtxList->maxCoord[0];
    max[1] = vtxList->maxCoord[1];
    max[2] = vtxList->maxCoord[2];
}

void vtxList_getBounds_f32(BKVertexList *vtxList, f32 min[3], f32 max[3]){
    min[0] = (f32) vtxList->minCoord[0];
    min[1] = (f32) vtxList->minCoord[1];
    min[2] = (f32) vtxList->minCoord[2];

    max[0] = (f32) vtxList->maxCoord[0];
    max[1] = (f32) vtxList->maxCoord[1];
    max[2] = (f32) vtxList->maxCoord[2];
}

void vtxList_getBoundsMlMtxTransformed(BKVertexList *self, f32 min[3], f32 max[3]) {
    Vtx *start_vtx;
    Vtx *end_vtx;
    Vtx *i_vtx;
    s32 i;
    f32 i_coord[3];

    start_vtx = (Vtx *)(self + 1);
    end_vtx = start_vtx + self->count;
    min[0] = (f32) start_vtx->v.ob[0];
    min[1] = (f32) start_vtx->v.ob[1];
    min[2] = (f32) start_vtx->v.ob[2];
    func_8025235C(min, min);
    max[0] = min[0];
    max[1] = min[1];
    max[2] = min[2];

    for( i_vtx = start_vtx + 1; i_vtx < end_vtx; i_vtx++){ 
        i_coord[0] = (f32) i_vtx->v.ob[0];
        i_coord[1] = (f32) i_vtx->v.ob[1];
        i_coord[2] = (f32) i_vtx->v.ob[2];
        func_8025235C(i_coord, i_coord);

        for(i = 0; i < 3; i++){
            if( i_coord[i] < min[i]){
                min[i] = i_coord[i];
            }
            if( max[i] < i_coord[i]){
                max[i] = i_coord[i];
            }
        }
    }
}

void func_802EC680(BKVertexList *self, s32 arg1, f32 arg2[3], f32 arg3[3]) {
    Vtx *start_vtx;
    Vtx *end_vtx;
    Vtx *i_vtx;
    s32 i;
    f32 i_coord[3];

    start_vtx = (Vtx*)(self + 1);
    end_vtx = start_vtx + self->count;

    for(i_vtx = start_vtx; i_vtx < end_vtx; i_vtx++){
        i_coord[0] = (f32) i_vtx->v.ob[0];
        i_coord[1] = (f32) i_vtx->v.ob[1];
        i_coord[2] = (f32) i_vtx->v.ob[2];
        func_8025235C(i_coord, i_coord);
        if ((i_vtx == start_vtx) || (i_coord[1] < arg2[1])) {
            arg2[1] = i_coord[1];
        }
    }

    arg3[1] = arg2[1]+ (f32) arg1;

    for(i_vtx = start_vtx; i_vtx < end_vtx; i_vtx++){
        i_coord[0] = (f32) i_vtx->v.ob[0];
        i_coord[1] = (f32) i_vtx->v.ob[1];
        i_coord[2] = (f32) i_vtx->v.ob[2];
        func_8025235C(i_coord, i_coord);
        if (i_coord[1] < arg3[1]) {

            arg2[0] = i_coord[0];
            arg2[2] = i_coord[2];
            
            arg3[0] = i_coord[0];
            arg3[2] = i_coord[2];
            break;
        } 
    }

    for(i_vtx = i_vtx + 1; i_vtx < end_vtx; i_vtx++) {
        i_coord[0] = (f32) i_vtx->v.ob[0];
        i_coord[1] = (f32) i_vtx->v.ob[1];
        i_coord[2] = (f32) i_vtx->v.ob[2];
        func_8025235C(i_coord, i_coord);
        if (i_coord[1] < arg3[1]) {
            for(i = 0; i < 3; i+=2){
                if (i_coord[i] < arg2[i]) {
                    arg2[i] = i_coord[i];
                }
                if (arg3[i] < i_coord[i]) {
                    arg3[i] = i_coord[i];
                }
            }
        }
    }
}

void vtxList_getVtxRange(BKVertexList *this, Vtx **vtx, Vtx **vtx_end){
    *vtx = &this->vtx_18[0];
    *vtx_end = &(*vtx)[this->count];
}

s32 vtxList_getVtxCount(BKVertexList *this){
    return this->count;
}

f32 vtxList_getGlobalNorm(BKVertexList *this){
    return (f32)this->global_norm;
}

void vtxList_getCenterAndNorm(BKVertexList *this, f32 center[3], f32 *norm){
    center[0] = (f32)this->centerCoord[0];
    center[1] = (f32)this->centerCoord[1];
    center[2] = (f32)this->centerCoord[2];
    *norm = this->local_norm; 
}

f32 vtxList_getLocalNorm(BKVertexList *this){
    return (f32)this->local_norm;
}

void vtxList_free(BKVertexList *vtxList){
    free(vtxList);
}

BKVertexList *vtxList_clone(BKVertexList *vtxList){
    BKVertexList *out_v0;
    size_t list_size;
    
    list_size = sizeof(BKVertexList) + vtxList->count*sizeof(Vtx);
    out_v0 = (BKVertexList *) malloc(list_size);
    wmemcpy(out_v0, vtxList, list_size);
    return out_v0;
}

void vtxList_copyColors(BKVertexList *dst, BKVertexList *src) {
    Vtx *start_ptr;
    Vtx *end_ptr;
    Vtx *i_ptr;
    Vtx *src_ptr;
    s32 i;

    src_ptr = &src->vtx_18[0];
    start_ptr = &dst->vtx_18[0];
    end_ptr = start_ptr + dst->count;
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
    end_ptr = start_ptr + dst->count;
    for(i_ptr = start_ptr, src_ptr = &src->vtx_18[0]; i_ptr < end_ptr; i_ptr++, src_ptr++){
        for(i = 0; i < 3; i++){
            i_ptr->v.cn[i] = src_ptr->v.cn[i] + (target_color[i] - src_ptr->v.cn[i]) * amount;
        }
    }
    osWritebackDCache(start_ptr, ((s32)(end_ptr - start_ptr)) * sizeof(Vtx));
}

void func_802ECBD4(BKVertexList *dst, BKVertexList *src, f32 arg2[3], f32 rotation[3], f32 arg4[4]) {
    f32 sp74[3];
    f32 sp68[3];
    Vtx *dst_vtx;
    Vtx *start_vtx;
    Vtx *end_vtx;
    Vtx *src_vtx;
    f32 sp4C[3];
    s32 i;
    f32 temp_f0;
    s32 pad40;

    viewport_getPosition_vec3f(sp74);
    viewport_getLookVector(sp68);
    mlMtxIdent();
    func_80252CC4(arg2, rotation, 1.0f, NULL);
    func_8025235C(sp74, sp74);

    mlMtxIdent();
    func_80252CC4(NULL, rotation, 1.0f, NULL);
    func_8025235C(sp68, sp68);

    start_vtx = (Vtx *)(dst + 1);
    end_vtx = start_vtx + dst->count;
    for(dst_vtx = start_vtx, src_vtx = (Vtx *)(src + 1); dst_vtx < end_vtx; dst_vtx++, src_vtx++){
            sp4C[0] = dst_vtx->v.ob[0] - sp74[0];
            sp4C[1] = dst_vtx->v.ob[1] - sp74[1];
            sp4C[2] = dst_vtx->v.ob[2] - sp74[2];
            temp_f0 = sp68[0]*sp4C[0] + sp68[1]*sp4C[1] + sp68[2]*sp4C[2];
            temp_f0 = func_8034A9D0(arg4, temp_f0);
            for(i = 0; i < 3; i++){
                dst_vtx->v.cn[i] = temp_f0*src_vtx->v.cn[i];
            }
    }
    osWritebackDCache(start_vtx, (end_vtx - start_vtx) * sizeof(Vtx));
}

void vtxList_randColors(BKVertexList *self) {
    Vtx *start_ptr;
    Vtx *end_ptr;
    Vtx *i_ptr;
    s32 i;

    start_ptr = &self->vtx_18[0];
    end_ptr = start_ptr + self->count;
    for(i_ptr = start_ptr; i_ptr < end_ptr; i_ptr++){
        for(i = 0; i < 3; i++){
            i_ptr->v.cn[i] = 0;
        }
        i_ptr->v.cn[0] = randf() * 255.0f;
    }
    osWritebackDCache(start_ptr, ((s32)(end_ptr - start_ptr)) * sizeof(Vtx));
}

void vtxList_randWalkColor(BKVertexList *self) {
    Vtx *start_ptr;
    Vtx *end_ptr;
    Vtx *i_ptr;
    s32 i;
    s32 phi_s0;

    start_ptr = &self->vtx_18[0];
    end_ptr = start_ptr + self->count;
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

void vtxList_recolor(BKVertexList *self, s32 arg1[3]) {
    Vtx *start_ptr;
    Vtx *end_ptr;
    Vtx *i_ptr;
    s32 i;
    s32 phi_s0;

    start_ptr = &self->vtx_18[0];
    end_ptr = start_ptr + self->count;
    for(i_ptr = start_ptr; i_ptr < end_ptr; i_ptr++){
        for(i = 0; i < 3; i++){
            i_ptr->v.cn[i] = arg1[i];
        }
    }
    osWritebackDCache(start_ptr, ((s32)(end_ptr - start_ptr)) * sizeof(Vtx));
}

void func_802ED108(f32 arg0[3]){
    arg0[0] = D_803808C0.unk20[0];
    arg0[1] = D_803808C0.unk20[1];
    arg0[2] = D_803808C0.unk20[2];
}

s32 func_802ED12C(void){
    return  D_803808C0.unk0;
}

void func_802ED138(f32 arg0[3], f32 arg1[3], f32 arg2){
    D_803808C0.unk0 = 0;
    D_803808C0.unk10[0] = arg0[0];
    D_803808C0.unk10[1] = arg0[1];
    D_803808C0.unk10[2] = arg0[2];

    D_803808C0.unk4[0] = arg1[0];
    D_803808C0.unk4[1] = arg1[1];
    D_803808C0.unk4[2] = arg1[2];

    D_803808C0.unk1C = arg2;
}

void func_802ED180(BKVertexList *self, f32 arg1[3], f32 arg2[3], f32 arg3, f32 arg4[3]) {
    Vtx *phi_s0;
    f32 sp88[3];
    f32 sp7C[3];
    f32 sp70[3];
    Vtx *phi_s1;
    Vtx *start;
    f32 sp5C[3];
    f32 temp_f20;
    f32 temp_f0;


    mlMtxIdent();
    func_80252CC4(arg1, arg2, arg3, arg4);
    func_8025235C(sp88, D_803808C0.unk10);
    func_8025235C(sp7C, D_803808C0.unk4);
    temp_f20 = D_803808C0.unk1C / arg3;
    temp_f20 = temp_f20*temp_f20;
    start = (Vtx*)(self + 1);
    phi_s1 = start + self->count;
    for(phi_s0 = start; phi_s0 < phi_s1; phi_s0++){
        sp70[0] = (f32) phi_s0->v.ob[0];
        sp70[1] = (f32) phi_s0->v.ob[1];
        sp70[2] = (f32) phi_s0->v.ob[2];

        sp5C[0] = sp70[0] - sp7C[0];
        sp5C[1] = sp70[1] - sp7C[1];
        sp5C[2] = sp70[2] - sp7C[2];

        temp_f0 = sp5C[0]*sp5C[0] + sp5C[1]*sp5C[1] + sp5C[2]*sp5C[2];
        if (!(temp_f20 <= temp_f0)) {
            D_803808C0.unk0 = 1;
            mlMtxIdent();
            func_80252C08(arg1, arg2, arg3, arg4);
            func_8025235C(D_803808C0.unk20, sp70);
        }
    }
}

void vtxList_getNthCoord(BKVertexList *self, s32 indx, f32 dst[3]){
    Vtx *vtx;

    vtx = (s32)(self + 1) + (indx * sizeof(Vtx));
    dst[0] = (f32) vtx->v.ob[0];
    dst[1] = (f32) vtx->v.ob[1];
    dst[2] = (f32) vtx->v.ob[2];
}

void vtxList_setNthCoord(BKVertexList *self, s32 indx, f32 arg2[3]){
    Vtx *vtx;
    s32 i;

    vtx = (s32)(self + 1) + (indx * sizeof(Vtx));
    for(i = 0; i < 3; i++){
        vtx->v.ob[i] = (arg2[i] >= 0.0) ? arg2[i] + 0.5 :  arg2[i] - 0.5;
    }
}
