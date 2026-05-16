#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void animVerticesList_setCoords(BKAnimVerticesList *this, BKVertexList *bk_vtx_list, s32 index, f32 coords[3]) {
    Vtx *vtx, *vtx_list;
    int i;
    BKAnimVertices *anim_vertices;

    vtx_list = vtxList_getVertices(bk_vtx_list);
    anim_vertices = this->data;

    while (index != 0) {
        anim_vertices = (BKAnimVertices *) ((s16*)(anim_vertices + 1) + (anim_vertices->vtx_count - 1)); // TODO: Remove this ugly pointer calculation
        index--;
    }

    for (i = 0; i < anim_vertices->vtx_count; i++) {
        vtx = &vtx_list[anim_vertices->vtx_list[i]];
        vtx->v.ob[0] = coords[0];
        vtx->v.ob[1] = coords[1];
        vtx->v.ob[2] = coords[2];
    }
}

void animVerticesList_transform(BKAnimVerticesList *this, BKVertexList *bk_vtx_list, AnimMtxList *mtx_list) {
    Vtx *vtx, *vtx_list;
    int j;
    BKAnimVertices *anim_vertices;
    s16 transformed_coords[3];
    s32 mtx_index;
    int i;

    vtx_list = vtxList_getVertices(bk_vtx_list);
    anim_vertices = this->data;
    mtx_index = -2;

    for(i = 0; i < this->count; i++) { 
        if (mtx_index != anim_vertices->anim_index) {
            mtx_index = anim_vertices->anim_index;
            mlMtxSet(animMtxList_get(mtx_list, mtx_index));
        }
        mlMtx_apply_vec3s(transformed_coords, anim_vertices->coord);
        for (j = 0; j < anim_vertices->vtx_count; j++) {
            vtx = &vtx_list[anim_vertices->vtx_list[j]];
            vtx->v.ob[0] = transformed_coords[0];
            vtx->v.ob[1] = transformed_coords[1];
            vtx->v.ob[2] = transformed_coords[2];
        }

        anim_vertices = (BKAnimVertices *) ((s16*)(anim_vertices + 1) + (anim_vertices->vtx_count - 1)); // TODO: Remove this ugly pointer calculation
    }

    osWritebackDCache(vtx_list, vtxList_getVtxCount(bk_vtx_list) * sizeof(Vtx));
}
