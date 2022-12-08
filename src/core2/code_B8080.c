#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void BKModel_getMeshCoordRange(BKModel *model, s32 mesh_id, s16 min[3], s16 max[3]);
s32  func_8033F3E8(BKModel *model, f32 position[3], s32 min_id, s32 max_id);
/* .code */
//performs operation "fn" for every vtx in every mesh of a model
void BKModel_transformMeshes(BKModel *model, void (*fn)(s32, BKVtxRef *, Vtx *, s32), s32 arg3) {
    s32 i;
    BKMesh *iMesh;
    BKVtxRef *iVtx;
    BKVtxRef *start_vtx_ref;
    BKVtxRef *end_vtx_ref;
    Vtx *verts;

    verts = vtxList_getVertices(model->vtxList_4);
    iMesh = (BKMesh *)(model + 1);
    for(i = 0; i < model->meshList_0->meshCount_0; i++){
        start_vtx_ref = (BKVtxRef *)(iMesh + 1);
        end_vtx_ref = start_vtx_ref + iMesh->vtxCount_2;
        for(iVtx = start_vtx_ref; iVtx < end_vtx_ref; iVtx++){
            fn(iMesh->uid_0, iVtx, &verts[iVtx->unk10], arg3);
        }
        iMesh =  (BKMesh*) (((BKVtxRef *)(iMesh + 1)) + iMesh->vtxCount_2);
    };
}

//performs operation "fn" for every vtx in a model's mesh
void BKModel_transformMesh(BKModel *model, s32 mesh_id, void (*fn)(s32, BKVtxRef *, Vtx *, s32), s32 arg3) {
    s32 i;
    BKMesh *iMesh;
    BKVtxRef *iVtx;
    BKVtxRef *start_vtx_ref;
    BKVtxRef *end_vtx_ref;
    Vtx *verts;

    verts = vtxList_getVertices(model->vtxList_4);
    iMesh = (BKMesh *)(model + 1);
    for(i = 0; i < model->meshList_0->meshCount_0; i++){
        if (mesh_id == iMesh->uid_0) {
            start_vtx_ref = (BKVtxRef *)(iMesh + 1);
            end_vtx_ref = start_vtx_ref + iMesh->vtxCount_2;
            for(iVtx = start_vtx_ref; iVtx < end_vtx_ref; iVtx++){
                fn(iMesh->uid_0, iVtx, &verts[iVtx->unk10], arg3);
            }
            return;
        }
        iMesh =  (BKMesh*) (((BKVtxRef *)(iMesh + 1)) + iMesh->vtxCount_2);
    };
}

//BKModel_getAveragePositionOfMesh
void BKModel_getMeshCenter(BKModel *model, s32 mesh_id, s16 arg2[3]) {
    s16 min[3];
    s16 max[3];

    BKModel_getMeshCoordRange(model, mesh_id, min, max);
    arg2[0] = (min[0] + max[0]) / 2;
    arg2[1] = (min[1] + max[1]) / 2;
    arg2[2] = (min[2] + max[2]) / 2;
}


BKMeshList *BKModel_getMeshList(BKModel *arg0){
    return arg0->meshList_0;
}

void BKModel_getMeshCoordRange(BKModel *model, s32 mesh_id, s16 min[3], s16 max[3]) {
    s32 pad2C;
    s32 pad28;
    BKMesh *mesh;
    Vtx *vtx_pool;
    Vtx *i_vtx;
    s16 *mesh_begin;
    s16 *mesh_end;
    s16 *phi_t4;
    s32 i;

    mesh = meshList_getMesh(model->meshList_0, mesh_id);
    vtx_pool = vtxList_getVertices(model->vtxList_4);
    if (mesh == NULL) return;
    
    mesh_begin = (s16*)(mesh + 1);
    mesh_end = mesh_begin + (mesh->vtxCount_2);
    for(phi_t4 = mesh_begin; phi_t4 < mesh_end; phi_t4++){
        i_vtx = &vtx_pool[*phi_t4];
        for(i = 0; i < 3; i++){
            if (phi_t4 == (s16*)(mesh + 1)) {
                min[i] = max[i] = i_vtx->v.ob[i];
            } else {
                min[i] = MIN(i_vtx->v.ob[i], min[i]);
                max[i] = MAX(i_vtx->v.ob[i], max[i]);
            }
        }
    }
}

//return mesh id "position" is over/under
s32 func_8033F3C0(BKModel *model, f32 position[3]){
    return func_8033F3E8(model, position, 0, 100000);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8080/func_8033F3E8.s")
#else
s32 func_8033F3E8(BKModel *arg0, f32 arg1[3], s32 min_id, s32 max_id) {
    int i;
    int j;
    int k;
    s16 sp64[3];
    s16 sp5C[3];
    s16 sp54[3];
    s16 temp_v1_3;
    Vtx *temp_v0;
    BKMesh *phi_t3;
    Vtx *phi_a1;
    s32 mesh_cnt;
    s32 vtx_cnt;
    s16 *tmp;
    s16 t8;

    temp_v0 = vtxList_getVertices(arg0->vtxList_4);
    sp54[0] = (s16) arg1[0];
    sp54[1] = (s16) arg1[1];
    sp54[2] = (s16) arg1[2];
    phi_t3 = (BKMesh *)(arg0->meshList_0 + 1);
    for(k = 0; k < arg0->meshList_0->meshCount_0; k++){
        if ((min_id > phi_t3->uid_0 || phi_t3->uid_0 >= max_id)){
            vtx_cnt = phi_t3->vtxCount_2;
        }
        else{
            t8 = *(s16*)(phi_t3 + 1);
            phi_a1 = temp_v0 + t8;
            for(i = 0; &sp64[i] < &sp64[3]; i++){
                 temp_v1_3 = phi_a1->v.ob[i];
                sp64[i] = temp_v1_3;
                sp5C[i] = temp_v1_3;
            };

            tmp = (s16*)(phi_t3 + 1);
            for(j = 0; j < phi_t3->vtxCount_2; j++){
                phi_a1 = temp_v0 + tmp[j];
                for(i = 0; i < 3; i++){
                    temp_v1_3 = phi_a1->v.ob[i];
                    sp64[i] = (temp_v1_3 < sp64[i]) ? temp_v1_3 : sp64[i];
                    sp5C[i] = (sp5C[i] < temp_v1_3) ? temp_v1_3 : sp5C[i];
                };
            }
            if( (sp64[0] < sp54[0] && sp54[0] < sp5C[0])
                && (sp64[2] < sp54[2] && sp54[2] < sp5C[2])
            ){
                return phi_t3->uid_0;
            }
            vtx_cnt = phi_t3->vtxCount_2;
        }
        phi_t3 = &(((s16 *)(phi_t3 + 1))[vtx_cnt]); 
    }
    return 0;
}

#endif

void model_free(void *arg0){
    free(arg0);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8080/func_8033F5F8.s")
#else
BKModel *func_8033F5F8(BKMeshList *arg0, BKVertexList *arg1) {
    BKModel *sp40;
    s32 temp_s1;
    s32 temp_s6;
    void *temp_v0;
    BKMesh *phi_s3;
    BKMesh *phi_s5;
    s16 *phi_s2;
    BKVtxRef *phi_s0;
    s32 phi_s1;
    s32 phi_s6;

    sp40 = (BKModel *)malloc((meshList_getVtxCount(arg0) * sizeof(BKVtxRef)) + (arg0->meshCount_0 * sizeof(BKMesh)) + sizeof(BKModel));
    sp40->meshList_0 = arg0;
    sp40->vtxList_4 = arg1;
    phi_s3 = (BKMesh *)(arg0 + 1);
    phi_s5 = (BKMesh *)(sp40 + 1);
    for(phi_s6 = 0; phi_s6 < arg0->meshCount_0; phi_s6++){
            phi_s5->uid_0 = (s16) phi_s3->uid_0;
            phi_s5->vtxCount_2 = (s16) phi_s3->vtxCount_2;
            phi_s2 = (s16*)(phi_s3 + 1);
            phi_s0 = (BKVtxRef *)(phi_s5 + 1);
            for(phi_s1 = 0; phi_s1 < phi_s3->vtxCount_2; phi_s1++){
                phi_s0[phi_s1].unk10 = phi_s2[phi_s1];
                memcpy(&phi_s0->v, (Vtx *)(arg1 + 1) + phi_s0->unk10, sizeof(Vtx));
            }
            phi_s3 = (BKMesh *)((Vtx *)(phi_s3 + 1) + phi_s3->vtxCount_2);
            phi_s3 = (BKMesh *)((BKVtxRef *)(phi_s5 + 1) + phi_s5->vtxCount_2);
    }
    return sp40;
}
#endif

void func_8033F738(ActorMarker *arg0) {
    BKModelBin *sp1C;
    s32 sp18;

    sp1C = func_80330B1C(arg0);
    sp18 = func_8033A0B0(sp1C);
    arg0->unk48 = func_8033F5F8(sp18, func_8033A148(sp1C));
}


void func_8033F784(ActorMarker *arg0){
    model_free(arg0->unk48);
}

void func_8033F7A4(ActorMarker *arg0, BKVertexList *arg1) {
    arg0->unk48->meshList_0 = func_8033A0B0(func_80330DE4(arg0));
    arg0->unk48->vtxList_4  = arg1;
}

void func_8033F7E8(s32 arg0){}
