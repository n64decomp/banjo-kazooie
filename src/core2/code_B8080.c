#include <ultra64.h>
#include "functions.h"
#include "variables.h"

//performs operation "fn" for every vtx in every mesh of a model
void model_transformMeshes(BKModel *this, bk_model_transform_func_s fn, s32 transform_func_arg) {
    int i;
    BKModelMesh *iMesh;
    BKModelVtxRef *iVtx;
    BKModelVtxRef *start_vtx_ref;
    BKModelVtxRef *end_vtx_ref;
    Vtx *verts;

    verts = vtxList_getVertices(this->vtx_list);
    iMesh = (BKModelMesh *) this->data;
    for (i = 0; i < this->mesh_list->count; i++){
        start_vtx_ref = (BKModelVtxRef *) iMesh->data;
        end_vtx_ref = start_vtx_ref + iMesh->vtx_count;
        for (iVtx = start_vtx_ref; iVtx < end_vtx_ref; iVtx++) {
            fn(iMesh->uid, iVtx, &verts[iVtx->vtx_id], transform_func_arg);
        }
        iMesh = (BKModelMesh *) ((BKModelVtxRef *) iMesh->data + iMesh->vtx_count);
    };
}

//performs operation "fn" for every vtx in a model's mesh
void model_transformMesh(BKModel *this, s32 mesh_id, bk_model_transform_func_s fn, s32 transform_func_arg) {
    int i;
    BKModelMesh *iMesh;
    BKModelVtxRef *iVtx;
    BKModelVtxRef *start_vtx_ref;
    BKModelVtxRef *end_vtx_ref;
    Vtx *verts;

    verts = vtxList_getVertices(this->vtx_list);
    iMesh = (BKModelMesh *) this->data;
    for (i = 0; i < this->mesh_list->count; i++) {
        if (mesh_id == iMesh->uid) {
            start_vtx_ref = (BKModelVtxRef *) iMesh->data;
            end_vtx_ref = start_vtx_ref + iMesh->vtx_count;
            for (iVtx = start_vtx_ref; iVtx < end_vtx_ref; iVtx++) {
                fn(iMesh->uid, iVtx, &verts[iVtx->vtx_id], transform_func_arg);
            }
            return;
        }
        iMesh = (BKModelMesh *) ((BKModelVtxRef *) iMesh->data + iMesh->vtx_count);
    };
}

void model_getMeshCenter(BKModel *this, s32 mesh_id, s16 dst[3]) {
    s16 min[3];
    s16 max[3];

    model_getMeshCoordRange(this, mesh_id, min, max);
    dst[0] = (min[0] + max[0]) / 2;
    dst[1] = (min[1] + max[1]) / 2;
    dst[2] = (min[2] + max[2]) / 2;
}


BKMeshList *model_getMeshList(BKModel *this) {
    return this->mesh_list;
}

void model_getMeshCoordRange(BKModel *this, s32 mesh_id, s16 min[3], s16 max[3]) {
    s32 pad2C;
    s32 pad28;
    BKMesh *mesh;
    Vtx *vtx_pool;
    Vtx *i_vtx;
    s16 *mesh_begin;
    s16 *mesh_end;
    s16 *phi_t4;
    s32 i;

    mesh = meshList_getMesh(this->mesh_list, mesh_id);
    vtx_pool = vtxList_getVertices(this->vtx_list);
    if (mesh == NULL) return;
    
    mesh_begin = mesh->vertices;
    mesh_end = mesh_begin + mesh->vtx_count;
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
s32 model_func_8033F3C0(BKModel *this, f32 position[3]){
    return model_func_8033F3E8(this, position, 0, 100000);
}

s32 model_func_8033F3E8(BKModel *this, f32 position[3], s32 min_id, s32 max_id) {
    int i;
    int j;
    int k;
    s16 min[3];
    s16 max[3];
    s16 position_s16[3];
    s32 temp_v1_3;
    Vtx *vertex_pool;
    BKMesh *current_mesh;
    Vtx *current_vertex;
    s16 *vertex_index_list;

    vertex_pool = vtxList_getVertices(this->vtx_list);
    position_s16[0] = (s16) position[0];
    position_s16[1] = (s16) position[1];
    position_s16[2] = (s16) position[2];
    current_mesh = this->mesh_list->data;
    for(k = 0; k < this->mesh_list->count; k++, current_mesh = &current_mesh->vertices[current_mesh->vtx_count]){
        if ((min_id > current_mesh->uid || current_mesh->uid >= max_id))
            continue;

        vertex_index_list = ((s16*)(current_mesh + 1));
        current_vertex = vertex_pool + vertex_index_list[0];
        for(j = 0; j < 3; j++){
            min[j] = max[j] = current_vertex->v.ob[j];
        };

        
        for(j = 1; j < current_mesh->vtx_count; j++){
            current_vertex = vertex_pool + vertex_index_list[j];
            for(i = 0; i < 3; i++){\
                temp_v1_3 = current_vertex->v.ob[i];
                min[i] = MIN(temp_v1_3, min[i]);
                max[i] = MAX(temp_v1_3, max[i]);
            };
        }
        if( (min[0] < position_s16[0] && position_s16[0] < max[0])
            && (min[2] < position_s16[2] && position_s16[2] < max[2])
        ){
            return current_mesh->uid;
        }
         
    }
    return 0;
}

void model_free(BKModel *this) {
    free(this);
}

BKModel *meshList_createModel(BKMeshList *this, BKVertexList *bk_vtx_list) {
    s32 temp_s1;
    BKModel *model;
    void *temp_v0;
    BKMesh *in_mesh;
    BKModelMesh *out_mesh;
    BKModelVtxRef *vtx_ref;
    Vtx *new_var;
    int j, i;

    model = (BKModel *) malloc(sizeof(BKModel) + (this->count * sizeof(BKModelMesh)) + (meshList_getVtxCount(this) * sizeof(BKModelVtxRef)));
    model->mesh_list = this;
    model->vtx_list = bk_vtx_list;

    in_mesh = this->data; 
    out_mesh = (BKModelMesh *) model->data;

    for (i = 0; i < this->count; i++) {
            out_mesh->uid = in_mesh->uid;
            out_mesh->vtx_count = in_mesh->vtx_count;
            vtx_ref = (BKModelVtxRef *) out_mesh->data;
            
            for (j = 0; j < in_mesh->vtx_count; j++) {
                vtx_ref->vtx_id = in_mesh->vertices[j];
                memcpy(&vtx_ref->v, &bk_vtx_list->vertices[vtx_ref->vtx_id], sizeof(Vtx));
                vtx_ref++;
            }

            in_mesh = (BKMesh *) &in_mesh->vertices[in_mesh->vtx_count];
            out_mesh = (BKModelMesh *) ((BKModelVtxRef *) out_mesh->data + out_mesh->vtx_count);
    }

    return model;
}

void func_8033F738(ActorMarker *this) {
    BKModelBin *model_bin;
    BKMeshList *mesh_list;

    model_bin = marker_loadModelBin(this);
    mesh_list = modelbin_getMeshList(model_bin);
    this->unk48 = meshList_createModel(mesh_list, modelbin_getVtxList(model_bin));
}


void func_8033F784(ActorMarker *this) {
    model_free(this->unk48);
}

void func_8033F7A4(ActorMarker *this, BKVertexList *bk_vtx_list) {
    this->unk48->mesh_list = modelbin_getMeshList(func_80330DE4(this));
    this->unk48->vtx_list  = bk_vtx_list;
}

void func_8033F7E8(ActorMarker *this) {}
