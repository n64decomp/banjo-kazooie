#ifndef BANJO_KAZOOIE_CORE2_MODEL_H
#define BANJO_KAZOOIE_CORE2_MODEL_H

#include <ultra64.h>
#include "bool.h"

/* Model header
 * Contains offsets relative to the start of the file to the various sections
 * If a section is not present in the file, the offset will be zero
 * 
 */

typedef struct bk_model_header_s {
    u32 magic_number;
    s32 geo_list_offset;
    s16 texture_list_offset;
    s16 geo_type;
    s32 gfx_list_offset;
    s32 vtx_list_offset;
    s32 unk14_list_offset;
    s32 animation_list_offset;
    s32 collision_list_offset;
    s32 camera_area_list_offset;
    s32 mesh_list_offset;
    s32 anim_vertices_list_offset;
    s32 animated_texture_list_offset;
    u16 unk30;
    u16 vertex_count;
    f32 unk34;
} BKModelBin;

/* Geometry Setup structs and typedefs
 * Geometry Setup contains list of commands that control the rendering (called in modelRender_draw)
 *
 * Command overview:
 * - UNK0       0x00        Calls a sublist, ...
 * - SORT       0x01        Call sublist based on points distance
 * - BONE       0x02        Applies an animation matrix and then calls a sublist
 * - LOADDL     0x03        Draw Display List
 * - NOP        0x04        No operation
 * - SKINNING   0x05        Draw multiple Display Lists and with pre-applying matrices
 * - CALL       0x06        Calls a sublist
 * - LOADDL2    0x07        Draw Display List
 * - LOD        0x08        Call sublist if Level of Detail matches
 * - NOP2       0x09        No operation
 * - REFPOINT   0x0A        Transforms a point relative to the camera and feedbacks it back to the object
 * - NOP3       0x0B        No operation
 * - SELECTOR   0x0C        ???
 * - DRAWDIST   0x0D        Draw with Frustum Culling
 * - UNKE       0x0E        ???
 * - CAMERA     0x0F        Calls a sublist if the camera is inside or outside a bounding box, depending on the flag
 * - TEXWRAP    0x10        Sets the texture wrapping mode
 * 
 */

struct geo_cmd_0_s {
    u32 cmd;
    s32 next_offset;
    s16 branch_offset;
    s16 do_pitch_rotate;
    f32 position[3];
};

struct geo_cmd_sort_s {
    u32 cmd;
    s32 next_offset;
    f32 point_1[3];
    f32 point_2[3];
    s16 flags;
    s16 branch_offset_1;
    s32 branch_offset_2;
};

#define BK_GEO_CMD_SORT_RUN_BOTH_BIT    0x01

struct geo_cmd_bone_s {
    u32 cmd;
    s32 next_offset;
    u8 branch_offset;
    s8 anim_matrix_id;
};

struct geo_cmd_load_dl_s {
    u32 cmd;
    s32 next_offset;
    s16 gfx_index;
};

struct geo_cmd_skinning_s {
    u32 cmd;
    s32 next_offset;
    s16 gfx_index[];
};

struct geo_cmd_call_s {
    u32 cmd;
    s32 next_offset;
    s32 branch_offset;
};

struct geo_cmd_load_dl_2_s {
    u32 cmd;
    s32 next_offset;
    s16 pad;
    s16 gfx_index;
};

struct geo_cmd_lod_s {
    u32 cmd;
    s32 next_offset;
    f32 max;
    f32 min;
    f32 position[3];
    s32 branch_offset;
};

struct geo_cmd_reference_point_s {
    u32 cmd;
    s32 next_offset;
    s16 index;
    s16 anim_mtx_id;
    f32 point[3];
};

struct geo_cmd_selector_s {
    u32 cmd;
    s32 next_offset;
    s16 branch_offset_count;
    s16 index;
    s32 branch_offsets[];
};

struct geo_cmd_draw_distance_s {
    u32 cmd;
    s32 next_offset;
    s16 min[3];
    s16 max[3];
    s16 branch_offset;
};

struct geo_cmd_E_s {
    u32 cmd;
    s32 next_offset;
    s16 position[3];
    s16 distance;
    s16 branch_offset;
    s16 anim_mtx_id;
};

struct geo_cmd_camera_s {
    u32 cmd;
    s32 next_offset;
    s16 branch_offset;
    u8 count;
    u8 flags;
    u8 id_list[];
};

#define BK_GEO_CMD_CAMERA_IS_OUTSIDE_BIT    0x01
#define BK_GEO_CMD_CAMERA_IS_INSIDE_BIT     0x02

struct geo_cmd_set_texture_wrap_mode_s {
    u32 cmd;
    s32 next_offset;
    s32 mode;
};

struct bk_geo_cmd_s {
    u32 cmd;
    s32 next_offset;
    u8 data[];
};

typedef struct bk_geo_cmd_s BKGeoCmd;
typedef void (*BKGeoCmdFunc)(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data);

/* Texture List and Texture Data
 *
 */

typedef struct bk_texture_info_s {
    s32 offset;
    s16 type;
    u8 pad6[2];
    u8 width;
    u8 height;
    u8 padA[6];
} BKTextureInfo;

#define BK_TEXTURE_INFO_TYPE_CI4_BIT    0x01
#define BK_TEXTURE_INFO_TYPE_CI8_BIT    0x02
#define BK_TEXTURE_INFO_TYPE_RGBA16_BIT 0x04
#define BK_TEXTURE_INFO_TYPE_RGBA32_BIT 0x08

typedef struct bk_texture_list_s {
    s32 size;
    s16 count;
    u16 pad;
    BKTextureInfo texture_infos[];
} BKTextureList;

/* Geo Type
 *
 */

typedef u32 BkGeoType;

#define BK_GEO_TYPE_MIPMAP_TRILINEAR_BIT 0x02
#define BK_GEO_TYPE_ENV_MAP_BIT 0x04

/* Gfx Display Lists
 *
 */

typedef struct bk_gfx_list_s {
    u32 size;
    u32 pad;
    Gfx list[];
} BKGfxList;

/* Vertex Lists
 *
 */

typedef struct bk_vertex_list_s {
    s16 minCoord[3];
    s16 maxCoord[3];
    s16 centerCoord[3];
    s16 local_norm;       //(distance to furthest vtx relative to model center)
    s16 count;
    s16 global_norm; //(distance to furthest vtx relative to model origin)
    Vtx vertices[];
} BKVertexList;

/* Unk14 Lists
 *
 */

typedef struct {
    s16 unk0[3];
    s16 unk6[3];
    s16 unkC[3];
    u8 unk12[3];
    u8 unk15;
    s8 unk16;
    u8 pad17[1];
}BKModelUnk14_0;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4[3];
    u8 unkA[3];
    u8 unkD;
    s8 unkE;
    u8 padF[1];
}BKModelUnk14_1;

typedef struct {
    s16 unk0;
    s16 unk2[3];
    u8 unk8;
    s8 unk9;
    u8 padA[2];
}BKModelUnk14_2;

typedef struct {
    s16 cnt0; //number of BKModelUnk14_0 structs
    s16 cnt2; //number of BKModelUnk14_1 structs
    s16 unk4; //number of BKModelUnk14_2 structs
    s16 unk6;
    u8 data[];
    //BKModelUnk14_0[]
    //BKModelUnk14_1[]
    //BKModelUnk14_2[]
}BKModelUnk14List;

/* Animation Lists
 *
 */

typedef struct bk_animation_s {
    f32 translation[3];
    s16 bone_id;
    s16 mtx_id;
} BKAnimation;

typedef struct bk_animation_list_s {
    f32 unk0; // scale factor ?
    s16 count;
    BKAnimation animations[];
} BKAnimationList;

/* Collision Lists
 *
 */

typedef struct bk_collision_geometry_s {
    s16 start_tri_index; //start_tri
    s16 tri_count; //tri_cnt
} BKCollisionGeometry;

typedef struct bk_collision_triangle_s {
    s16 unk0[3]; //vtx_indx
    s16 unk6;
    s32 flags;
} BKCollisionTriangle;

typedef struct bk_collision_list_s {
    s16 unk0[3]; //min
    s16 unk6[3]; //max
    s16 unkC; //y_stride
    s16 unkE; //z_stride
    s16 unk10; //geo_cnt
    s16 unk12; //scale
    s16 unk14; //tri_cnt
    u8 pad16[0x2];
    //BKCollisionGeometry[]
    //BKCollisionTriangle[]
} BKCollisionList;

/* Camera Area Lists
 * Contains a list of areas with bounding boxes that control which parts of maps are rendered if
 * the camera is inside a box
 */

typedef struct bk_camera_area_s {
    s16 min[3];
    s16 max[3];
    u8 in_bounds;
    u8 pad;
}BKCameraArea;

typedef struct bk_camera_area_list_s {
    u8 count;
    u8 pad;
    BKCameraArea data[];
} BKCameraAreaList;

/* Mesh Lists
 *
 */

typedef struct bk_mesh_s {
    s16 uid;
    s16 vtx_count;
    s16 vertices[];
} BKMesh;

typedef struct bk_mesh_list_s {
    s16 count;
    BKMesh data[];
} BKMeshList;

/* Animated Vertices Lists
 * Stores a list of vertices that is affected by a specific animation
 */

typedef struct {
    s16 coord[3];
    s8 anim_index;
    u8 vtx_count;
    s16 vtx_list[1];
} BKAnimVertices;

typedef struct {
    s16 count;
    u16 pad;
    BKAnimVertices data[];
} BKAnimVerticesList;

/* Animated Texture Lists
 * There is space for four animated texture info blocks
 */

typedef struct bk_animated_texture_s {
    s16 frame_size;
    s16 frame_cnt;
    f32 frame_rate;
} BKAnimTexture;

typedef struct bk_animated_texture_list_s {
    BKAnimTexture anim_textures[4];
} BKAnimTextureList;

/* Model
 * These structs are not part of the model file, but are created at runtime.
 * They are used to transform meshes
 *
 * A Model has the following structure:
 * - 1 BKModel as header (contains pointers to BKMeshList and BKVertexList)
 * - A list of BKModelMesh, each directly followed by lists of BKModelVtxRef
 */

typedef struct bk_model_mesh_vtx_ref_s {
    Vtx v;
    s16 vtx_id;
    s16 pad12;
    s32 pad14;
} BKModelVtxRef;

typedef struct bk_model_mesh_s {
    s16 uid;
    s16 vtx_count;
    u8 data[]; // BKModelVtxRef[], but must be declared as u8[]
} BKModelMesh;

typedef struct bk_model_s {
    BKMeshList *mesh_list;
    BKVertexList *vtx_list;
    u8 data[]; // BKModelMesh[], but must be declared as u8[]
} BKModel;

typedef void (*bk_model_transform_func_s)(s32 mesh_id, BKModelVtxRef *vtx_ref, Vtx *vtx, s32 arg3);

/* Function declarations
 *
 */

BKAnimVerticesList *modelbin_getAnimVerticesList(BKModelBin *this);
BkGeoType modelbin_getGeoType(BKModelBin *this);
BKGfxList *modelbin_getGfxList(BKModelBin *this);
BKCollisionList *modelbin_getCollisionList(BKModelBin *this);
BKMeshList *modelbin_getMeshList(BKModelBin *this);
f32 modelbin_getUnk34(BKModelBin *this);
BKAnimationList *modelbin_getAnimationList(BKModelBin *this);
BKTextureList *modelbin_getTextureList(BKModelBin *this);
BKAnimTextureList *modelbin_getAnimTextureList(BKModelBin *this);
BKModelUnk14List *modelbin_getUnk14List(BKModelBin *this);
BKVertexList *modelbin_getVtxList(BKModelBin *this);
BKCameraAreaList *modelbin_getCameraAreaList(BKModelBin *this);

#define modelbin_getGeoCmdList_MACRO(this)          ((BKGeoCmd *)            (((u8 *) (this)) + ((BKModelBin *) (this))->geo_list_offset))
#define modelbin_getTextureList_MACRO(this)         ((BKTextureList *)       (((u8 *) (this)) + ((BKModelBin *) (this))->texture_list_offset))
#define modelbin_getGfxList_MACRO(this)             ((BKGfxList *)           (((u8 *) (this)) + ((BKModelBin *) (this))->gfx_list_offset))
#define modelbin_getVtxList_MACRO(this)             ((BKVertexList *)        (((u8 *) (this)) + ((BKModelBin *) (this))->vtx_list_offset))
#define modelbin_getUnk14List_MACRO(this)           ((BKModelUnk14List *)    (((u8 *) (this)) + ((BKModelBin *) (this))->unk14_list_offset))
#define modelbin_getAnimationList_MACRO(this)       ((BKAnimationList *)     (((u8 *) (this)) + ((BKModelBin *) (this))->animation_list_offset))
#define modelbin_getCollisionList_MACRO(this)       ((BKCollisionList *)     (((u8 *) (this)) + ((BKModelBin *) (this))->collision_list_offset))
#define modelbin_getCameraAreaList_MACRO(this)      ((BKCameraAreaList *)    (((u8 *) (this)) + ((BKModelBin *) (this))->camera_area_list_offset))
#define modelbin_getMeshList_MACRO(this)            ((BKMeshList *)          (((u8 *) (this)) + ((BKModelBin *) (this))->mesh_list_offset))
#define modelbin_getAnimVerticesList_MACRO(this)    ((BKAnimVerticesList *)  (((u8 *) (this)) + ((BKModelBin *) (this))->anim_vertices_list_offset))
#define modelbin_getAnimTextureList_MACRO(this)     ((BKAnimTextureList *)   (((u8 *) (this)) + ((BKModelBin *) (this))->animated_texture_list_offset))

void model_copyFramebufferToTextures(BKModelBin *this);

void *textureList_getDataPtr(BKTextureList *this);
BKTextureInfo *textureList_getTextureInfo(BKTextureList *this, s32 index);
s32 textureInfo_getBitDepth(BKTextureInfo *this);
s32 textureInfo_getType(BKTextureInfo *this);
s32 textureInfo_getPaletteSize(BKTextureInfo *this);
s32 textureInfo_getOffset(BKTextureInfo *this);
s32 textureInfo_getTextureSize(BKTextureInfo *this);

f32 core2_C3A40_getIntensity(f32 curve_values[4], f32 position);
void core2_C3A40_getDefaultValues(f32 dst[4]);

Vtx *vtxList_getVertices(BKVertexList *this);
void vtxList_getBounds_s32(BKVertexList *this, s32 min[3], s32 max[3]);
void vtxList_getBounds_f32(BKVertexList *this, f32 min[3], f32 max[3]);
void vtxList_getBoundsTransformed(BKVertexList *this, f32 min[3], f32 max[3]);
void vtxList_func_802EC680(BKVertexList *this, s32 arg1, f32 arg2[3], f32 arg3[3]);
void vtxList_getVtxRange(BKVertexList *this, Vtx **begin_ptr, Vtx **end_ptr);
s32 vtxList_getVtxCount(BKVertexList *this);
f32 vtxList_getGlobalNorm(BKVertexList *this);
void vtxList_getCenterAndNorm(BKVertexList *this, f32 center[3], f32 *norm);
f32 vtxList_getLocalNorm(BKVertexList *this);
void vtxList_free(BKVertexList *this);
BKVertexList *vtxList_clone(BKVertexList *this);
void vtxList_copyColorsFrom(BKVertexList *this, BKVertexList *src);
void vtxList_tintColorsFrom(BKVertexList *this, s32 target_color[3], f32 intensity, BKVertexList *src);
void vtxList_recolor(BKVertexList *this, s32 color[3]);

// bool bkmodelunk14list_func_802EA760(BKModelUnk14List *this, s32 arg1, f32 arg2[3], f32 rotation[3], f32 scale, f32 arg5[3], f32 arg6[3], f32 *arg7);
// s32 bkmodelunk14list_func_802EA864(BKModelUnk14List *this, f32 position[3], f32 rotation[3], f32 scale, f32 arg4[3], f32 arg5[3], f32 arg6);
// s32 bkmodelunk14list_func_802EAB34(BKModelUnk14List *this, f32 position[3], f32 rotation[3], f32 scale, f32 arg4[3], f32 arg5[3], f32 arg6);
// s32 bkmodelunk14list_func_802EAD5C(BKModelUnk14List *this, f32 position[3], f32 rotation[3], f32 scale, f32 arg4[3], f32 arg5[3], f32 arg6);
// s32 bkmodelunk14list_func_802EAED4(BKModelUnk14List *this, f32 position[3], f32 rotation[3], f32 scale, f32 arg4[3], AnimMtxList *arg5, f32 arg6[3], f32 arg7);
// s32 bkmodelunk14list_func_802EB458(BKModelUnk14List *this, f32 position[3], f32 rotation[3], f32 scale, f32 arg4[3], AnimMtxList* arg5, f32 arg6[3], f32 arg7);
// s32 bkmodelunk14list_func_802EB8A0(BKModelUnk14List *this, f32 *position, f32 *rotation, f32 scale, f32 arg4[3], AnimMtxList* arg5, f32 *arg6, f32 arg7);
// bool bkmodelunk14list_func_802EBA98(BKModelUnk14List *this, f32 arg1[3], f32 rotation[3], f32 scale, f32 arg4[3], f32 arg5[3], f32 arg6, f32 arg7[3]);
// s32 bkmodelunk14list_func_802EBAE0(BKModelUnk14List *this, f32 position[3], f32 rotation[3], f32 scale, f32 arg4[3], AnimMtxList* arg5, f32 arg6[3], f32 arg7, f32 arg8[3]);
// s32 bkmodelunk14list_func_802EBD3C(BKModelUnk14List *this, f32 arg1[3], f32 rotation[3], f32 scale, f32 arg4[3], f32 arg5[3], s32 arg6);
// s32 bkmodelunk14list_func_802EC000(BKModelUnk14List *this, f32 arg1[3], f32 rotation[3], f32 scale, f32 arg4[3], f32 arg5[3], s32 arg6);
// s32 bkmodelunk14list_func_802EC238(BKModelUnk14List *this, f32 arg1[3], f32 rotation[3], f32 scale, f32 arg4[3], f32 arg5[3], s32 arg6);
// s32 bkmodelunk14list_func_802EC394(BKModelUnk14List *this, f32 position[3], f32 rotation[3], f32 scale, f32 arg4[3], f32 arg5[3], s32 arg6);


bool cameraAreaList_searchForEntryInBounds(BKCameraAreaList *this, u8 *id, u32 count);
void cameraAreaList_updateInBoundsFlag(BKCameraAreaList *this, f32 camera_position[3], f32 scale);

s32 meshList_getVtxCount(BKMeshList *this);
BKMesh *meshList_getMesh(BKMeshList *this, s32 mesh_id);
bool meshList_meshContainsVtx(BKMeshList *this, s32 mesh_id, s16 *vtx_id);
BKModel *meshList_createModel(BKMeshList *this, BKVertexList *bk_vtx_list);



void model_transformMeshes(BKModel *this, bk_model_transform_func_s fn, s32 transform_func_arg);
void model_transformMesh(BKModel *this, s32 mesh_id, bk_model_transform_func_s fn, s32 transform_func_arg);
void model_getMeshCenter(BKModel *this, s32 mesh_id, s16 dst[3]);
BKMeshList *model_getMeshList(BKModel *this);
void model_getMeshCoordRange(BKModel *this, s32 mesh_id, s16 min[3], s16 max[3]);
s32 model_func_8033F3C0(BKModel *this, f32 position[3]);
s32 model_func_8033F3E8(BKModel *this, f32 position[3], s32 min_id, s32 max_id);
void model_free(BKModel *this);


//void animVerticesList_setCoords(BKAnimVerticesList *this, BKVertexList *bk_vtx_list, s32 index, f32 coords[3]);
//void animVerticesList_transform(BKAnimVerticesList *this, BKVertexList *bk_vtx_list, AnimMtxList *mtx_list);


void gclights_recolor_vertices(BKVertexList *arg0, f32 position[3], f32 rotation[3], f32 scale, f32 arg4[3], BKVertexList *arg5);

#endif
