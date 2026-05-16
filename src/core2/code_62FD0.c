#include <ultra64.h>
#include "functions.h"
#include "variables.h"

s32 meshList_getVtxCount(BKMeshList *this) {
    int i;
    s32 vertex_count = 0;
    BKMesh *mesh = this->data;

    for (i = 0; i < this->count; ++i) {
        vertex_count += mesh->vtx_count;
        mesh = (BKMesh *) &mesh->vertices[mesh->vtx_count];
    }

    return vertex_count;
}

BKMesh *meshList_getMesh(BKMeshList *this, s32 mesh_id) {
    int i;
    BKMesh *mesh = this->data;

    for (i = 0; i < this->count; i++) {
        if (mesh->uid == mesh_id) {
            return mesh;
        }
        mesh = (BKMesh *) &mesh->vertices[mesh->vtx_count];
    }

    return NULL;
}

bool meshList_meshContainsVtx(BKMeshList *this, s32 mesh_id, s16 *vtx_id) {
    int i;
    BKMesh *mesh = meshList_getMesh(this, mesh_id);

    if (mesh) {
        for (i = 0; i < mesh->vtx_count; i++) {
            if (mesh->vertices[i] == *vtx_id) {
                return TRUE;
            }
        }
    }

    return FALSE;
}
