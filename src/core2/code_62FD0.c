#include <ultra64.h>
#include "functions.h"
#include "variables.h"

s32 meshList_getVtxCount(BKMeshList *meshList){
    s32 i;
    s32 v1 = 0;
    BKMesh *v0 = (BKMesh *)(meshList + 1);

    for(i = 0; i < meshList->meshCount_0; ++i){
        v1 += v0->vtxCount_2;
        v0 = (BKMesh *)&((s16*)(v0 +1))[v0->vtxCount_2];
        
    }
    return v1;
}

BKMesh * meshList_getMesh(BKMeshList *meshList, s32 mesh_id){
    s32 i;
    BKMesh *v1 = (BKMesh *)(meshList + 1);

    for(i=0; i < meshList->meshCount_0; i++){
        if(v1->uid_0 == mesh_id){
            return v1;
        }
        v1 = (BKMesh *)&((s16*)(v1 +1 ))[v1->vtxCount_2];
    }
    return NULL;
}

bool meshList_meshContainsVtx(BKMeshList * meshList, s32 mesh_id, void *vtx_id){
    s32 i;
    BKMesh *v0 = meshList_getMesh(meshList, mesh_id);

    if(v0){
        for(i = 0; i < v0->vtxCount_2; i++){
            if(((s16*)(v0 + 1))[i] == *(s16 *)vtx_id){
                return TRUE;
            }
        }
    }
    return FALSE;
}
