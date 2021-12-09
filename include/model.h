#ifndef __MODEL_H__
#define __MODEL_H__
#include <ultra64.h>

typedef struct {
    s16 uid_0;
    s16 vtxCount_2;
    s16 unk4[]; //vtx indices
} BKMesh;

typedef struct {
    s32 cmd_0;
    s32 size_4;
}BKGeoList;

typedef struct {
    s16 meshCount_0;
    BKMesh mesh_2[];
} BKMeshList;

typedef struct {
    s16 minCoord_0[3];
    s16 maxCoord_6[3];
    s16 unkC[3];
    s16 unk12;
    s16 cnt_14;
    s16 unk16;
    Vtx vtx_18[];
} BKVertexList;

typedef struct {
    u8 pad0[0];
}BKCollisionList;

typedef struct {
    u8 pad0[0];
}BKEffectsList;

typedef struct {
    f32 unk0[3];
    s16 unkC;
    s16 unkE;
}BKAnimation;

typedef struct {
    f32 unk0;
    s16 cnt_4;
    BKAnimation anim[];
}BKAnimationList;

typedef struct {
    u8 pad0[8];
    Gfx list[];
} BKGfxList;

typedef struct {
    s32 offset_0;
    s16 type_4;
    u8 pad6[2];
    u8 width_8;
    u8 height_9;
    u8 padA[6];
}BKTextureHeader;

typedef struct {
    s32 size_0;
    s16 cnt_4;
    u8 pad6[2];
}BKTextureList;

typedef struct {
    u8 pad0[0];
}BKModelUnk14List;

typedef struct {
    BKMeshList *meshList_0;
    BKVertexList *vtxList_4;
} BKModel;

typedef struct{
    u8 pad0[0x4];
    s32 geo_list_offset_4;
    s16 texture_list_offset_8;
    s16 geo_typ_A;
    s32 gfx_list_offset_C;
    s32 vtx_list_offset_10;
    s32 unk14;
    s32 animation_list_offset_18;
    s32 collision_list_offset_1C;
    s32 unk20;
    s32 effects_list_setup_24;
    s32 unk28;
    s32 unk2C;
}BKModelBin;
#endif
