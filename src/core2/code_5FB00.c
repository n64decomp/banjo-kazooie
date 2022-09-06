#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_802E6A90(BKModelUnk28List *arg0, BKVertexList *arg1, s32 arg2, f32 arg3[3]) {
    Vtx *i_vtx;
    Vtx *vtx_list;
    s32 i;
    s32 var_a2;
    BKModelUnk28 *var_v1;

    vtx_list = vtxList_getVertices(arg1);

    var_v1 = (BKModelUnk28 *)(arg0 + 1);
    for(arg2 = arg2; arg2 != 0; arg2--){
        var_v1 = (BKModelUnk28 *)((s16*)(var_v1 + 1) + (var_v1->vtx_count - 1));
    }

    for(i = 0; i < var_v1->vtx_count; i++){
            i_vtx = &vtx_list[var_v1->vtx_list[i]];
            i_vtx->v.ob[0] = (s16) (s32) arg3[0];
            i_vtx->v.ob[1] = (s16) (s32) arg3[1];
            i_vtx->v.ob[2] = (s16) (s32) arg3[2];

    }
}

void func_802E6BD0(BKModelUnk28List *arg0, BKVertexList *arg1, struct58s *arg2) {
    Vtx *vtx_list;
    Vtx *i_vtx;
    s32 i;
    BKModelUnk28 *var_s1;
    s16 sp50[3];
    s32 temp_v0;
    s32 var_s3;
    s32 var_s4;

    vtx_list = vtxList_getVertices(arg1);
    var_s1 = (BKModelUnk28 *)(arg0 + 1);
    var_s3 = -2;
    for(var_s4 = 0; var_s4 < arg0->count; var_s4++){ 
        if (var_s3 != var_s1->unk6) {
            var_s3 = var_s1->unk6;
            func_80251BCC(func_802EA110(arg2, var_s3));
        }
        mlMtx_apply_vec3s(sp50, var_s1->unk0);
        for(i = 0; i < var_s1->vtx_count; i++){
            i_vtx = &vtx_list[var_s1->vtx_list[i]];
            i_vtx->v.ob[0] = sp50[0];
            i_vtx->v.ob[1] = sp50[1];
            i_vtx->v.ob[2] = sp50[2];
        }
        var_s1 = (BKModelUnk28 *)((s16*)(var_s1 + 1) + (var_s1->vtx_count - 1));
    }
    osWritebackDCache(vtx_list, vtxList_getVtxCount(arg1) * sizeof(Vtx));
}
