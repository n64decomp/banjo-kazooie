#ifndef __MODEL_H__
#define __MODEL_H__
#include <ultra64.h>

typedef struct {
    Vtx v;
    s16 unk10; //vtx_indx
    u8 pad12[2];
    u8 pad14[4];
} BKVtxRef;

/* BKMesh
 * This struct is a set of Vtx that will be modified at runtime.
 * This struct is followed by an array of s16 containing the
 * Vtx index inside the model's BKVertexList.
*/
typedef struct {
    s16 uid_0;
    s16 vtxCount_2;
} BKMesh;

typedef struct {
    s32 cmd_0;
    s32 size_4;
}BKGeoList;

/* BKMeshList 
 * This struct is followed by an array of BKMesh which contain
 * lists of Vtx that are modified at runtime.
 */
typedef struct {
    s16 meshCount_0;
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
    s16 unk0; //start_tri
    s16 unk2; //tri_cnt
} BKCollisionGeo; //BKCollisionGeometry

typedef struct {
    s16 unk0[3]; //vtx_indx
    s32 unk8; //flags
} BKCollisionTri; //BKCollisionTri

typedef struct {
    s16 unk0[3]; //min
    s16 unk6[3]; //max
    s16 unkC; //y_stride
    s16 unkE; //z_stride
    s16 unk10; //geo_cnt
    s16 unk12; //scale
    s16 unk14; //tri_cnt
    u8 pad16[0x2];
    //BKCollisionGeo[]
    //BKCollisionTri[]
}BKCollisionList;

typedef struct {
    u8 pad0[0];
}BKEffectsList; //see BKMeshList

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
    s16 unk0[3];
    s16 unk6[3];
    s16 unkC[3];
    u8 unk12[3];
    u8 unk15;
    u8 pad16[2];
}BKModelUnk14_0;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4[3];
    u8 unkA[3];
    u8 unkD;
    u8 padE[2];
}BKModelUnk14_1;

typedef struct {
    s16 unk0;
    s16 unk2[3];
    u8 unk8;
    u8 pad9[3];
}BKModelUnk14_2;

typedef struct {
    s16 cnt0; //number of BKModelUnk14_0 structs
    s16 cnt2; //number of BKModelUnk14_1 structs
    s16 unk4;
    s16 unk6;
    //BKModelUnk14_0[]
    //BKModelUnk14_1[]
    //BKModelUnk14_2[]
}BKModelUnk14List;

typedef struct{
    s16 unk0[3];
    s16 unk6[3];
    u8 unkC;
    u8 padD[0x1];
}BKModelUnk20_0;

typedef struct{
    u8 unk0;
    u8 pad1[1];
    //BKModelUnk20_0[]
}BKModelUnk20List;

typedef struct{
    u8 pad0[1];
    //BKModelUnk20_0[]
}BKModelUnk2C;

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

BKVertexList *func_8033A148(BKModelBin *arg0);
Vtx *vtxList_getVertices(BKVertexList *vtxList);
void func_80333D48(BKVertexList *arg0, f32 position[3], f32 rotation[3], f32 scale, s32 arg4, BKVertexList *arg5);
#endif
