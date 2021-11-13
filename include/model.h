#ifndef __MODEL_H__
#define __MODEL_H__
#include <ultra64.h>

typedef struct {
    s16 uid_0;
    s16 vtxCount_2;
    s16 unk4[]; //vtx indices
} BKMesh;


typedef struct {
    s16 meshCount_0;
    BKMesh mesh_2[];
} BKMeshList;

typedef struct {
    s16 minCoord_0[3];
    s16 maxCoord_6[3];
    u8 padC[0xC];
    BKMesh vtx_18[];
} BKVertexList;

typedef struct {
    BKMeshList *meshList_0;
    BKVertexList *vtxList_4;
} BKModel;

typedef struct{
    u8 pad0[0x2C];
    s32 unk2C;
}BKModelBin;
#endif
