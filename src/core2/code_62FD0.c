#include <ultra64.h>
#include "functions.h"
#include "variables.h"

//BKMeshList_getVtxCount
s32 func_802E9F60(BKMeshList *arg0){
    s32 i;
    s32 v1 = 0;
    BKMesh *v0 = (BKMesh *)(arg0 + 1);

    for(i = 0; i < arg0->meshCount_0; ++i){
        v1 += v0->vtxCount_2;
        v0 = (BKMesh *)&((s16*)(v0 +1))[v0->vtxCount_2];
        
    }
    return v1;
}

BKMesh * func_802E9F9C(BKMeshList *arg0, s32 mesh_id){
    s32 i;
    BKMesh *v1 = (BKMesh *)(arg0 + 1);

    for(i=0; i < arg0->meshCount_0; i++){
        if(v1->uid_0 == mesh_id){
            return v1;
        }
        v1 = (BKMesh *)&((s16*)(v1 +1 ))[v1->vtxCount_2];
    }
    return NULL;
}

bool func_802E9FEC(BKMeshList * arg0, s32 mesh_id, void *vtx_id){
    s32 i;
    BKMesh *v0 = func_802E9F9C(arg0, mesh_id);

    if(v0){
        for(i = 0; i < v0->vtxCount_2; i++){
            if(((s16*)(v0 + 1))[i] == *(s16 *)vtx_id){
                return TRUE;
            }
        }
    }
    return FALSE;
}
