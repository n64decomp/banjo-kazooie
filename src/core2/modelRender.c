#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core1/core1.h"
#include "core2/core2.h"
#include "animation.h"

#define ARRAYLEN(x) (sizeof(x) / sizeof((x)[0]))

extern void assetCache_free(BKModelBin *);

void modelRender_geoCmd_Unk0(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data);
void modelRender_geoCmd_SORT(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data);
void modelRender_geoCmd_BONE(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data);
void modelRender_geoCmd_LOADDL(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data);
void modelRender_geoCmd_NOP(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data);
void modelRender_geoCmd_SKINNING(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data);
void modelRender_geoCmd_CALL(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data);
void modelRender_geoCmd_LOADDL2(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data);
void modelRender_geoCmd_TEXWRAP(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data);
void modelRender_geoCmd_LOD(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data);
void modelRender_geoCmd_REFPOINT(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data);
void modelRender_geoCmd_SELECTOR(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data);
void modelRender_geoCmd_DRAWDIST(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data);
void modelRender_geoCmd_UnkE(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data);
void modelRender_geoCmd_CAMERA(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data);
void modelRender_executeGeoCmds(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data);

// Sets up 2 cycle mode
Gfx setup2CycleDL[] =
{
    gsDPPipeSync(),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x80),
    gsSPEndDisplayList()
};

// Sets up 2 cycle mode with black prim color
Gfx setup2CycleBlackPrimDL[] =
{
    gsDPPipeSync(),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0x00),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x80),
    gsSPEndDisplayList()
};

// Sets up 2 cycle mode with white env color
Gfx setup2CycleWhiteEnvDL[] =
{
    gsDPPipeSync(),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x80),
    gsSPEndDisplayList()
};

// Sets up 2 cycle mode (duplicate of setup2CycleDL)
Gfx setup2CycleDL_copy[] =
{
    gsDPPipeSync(),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x80),
    gsSPEndDisplayList()
};

// List of render modes
Gfx renderModesNoDepthOpa[][2] = {
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_OPA_SURF2),
        gsSPEndDisplayList()
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_AA_OPA_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_OPA_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_AA_OPA_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, CVG_DST_SAVE | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    }
};

// Same as renderModesNoDepthOpa but with Z_CMP | Z_UPD added to the first 6 and Z_CMP added to the next 7
Gfx renderModesFullDepthOpa[][2] = {
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | Z_UPD | G_RM_OPA_SURF2),
        gsSPEndDisplayList()
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | Z_UPD | G_RM_AA_OPA_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | Z_UPD | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | Z_UPD | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | Z_UPD | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | Z_UPD | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_OPA_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_OPA_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList()
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | CVG_DST_SAVE | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList()
    }
};

// Same as renderModesNoDepthOpa but with Z_CMP added to all entries
Gfx renderModesDepthCompareOpa[][2] = {
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_OPA_SURF2),
        gsSPEndDisplayList()
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_OPA_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_OPA_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_OPA_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | CVG_DST_SAVE | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    }
};

// Same as renderModesNoDepthOpa but with OPA replaced by XLU
Gfx renderModesNoDepthXlu[][2] = {
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, CVG_DST_SAVE | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    }
};

// Same as renderModesFullDepthOpa but with OPA replaced by XLU
Gfx renderModesFullDepthXlu[][2] = {
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | Z_UPD | G_RM_XLU_SURF2),
        gsSPEndDisplayList()
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | Z_UPD | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | Z_UPD | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | Z_UPD | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | Z_UPD | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | Z_UPD | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList()
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | CVG_DST_SAVE | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList()
    }
};

// Same as renderModesDepthCompareOpa but with OPA replaced by XLU
Gfx renderModesDepthCompareXlu[][2] = {
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_XLU_SURF2),
        gsSPEndDisplayList()
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    },
    {
        gsDPSetRenderMode(G_RM_PASS, Z_CMP | CVG_DST_SAVE | G_RM_AA_XLU_SURF2),
        gsSPEndDisplayList(),
    }
};

// Mipmap tile configuration with no wrapping (G_TX_NOMASK disables wrap)
Gfx mipMapClampDL[] = 
{
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, 2, 0, G_TX_NOMIRROR, G_TX_NOMASK, 0, G_TX_NOMIRROR, G_TX_NOMASK, 0),
    gsDPSetTileSize(2, 0, 0, (32 - 1) << 2, (32 - 1) << 2),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0100, 3, 0, G_TX_NOMIRROR, G_TX_NOMASK, 1, G_TX_NOMIRROR, G_TX_NOMASK, 1),
    gsDPSetTileSize(3, 0, 0, (16 - 1) << 2, (16 - 1) << 2),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0104, 4, 0, G_TX_NOMIRROR, G_TX_NOMASK, 2, G_TX_NOMIRROR, G_TX_NOMASK, 2),
    gsDPSetTileSize(4, 0, 0, (8 - 1) << 2, (8 - 1) << 2),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0106, 5, 0, G_TX_NOMIRROR, G_TX_NOMASK, 3, G_TX_NOMIRROR, G_TX_NOMASK, 3),
    gsDPSetTileSize(5, 0, 0, (4 - 1) << 2, (4 - 1) << 2),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0107, 6, 0, G_TX_NOMIRROR, G_TX_NOMASK, 4, G_TX_NOMIRROR, G_TX_NOMASK, 4),
    gsDPSetTileSize(6, 0, 0, (2 - 1) << 2, (2 - 1) << 2),
    gsSPEndDisplayList()
};

// Mipmap tile configuration with wrapping
Gfx mipMapWrapDL[] =
{
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 0),
    gsDPSetTileSize(2, 0, 0, (32 - 1) << 2, (32 - 1) << 2),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0100, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1),
    gsDPSetTileSize(3, 0, 0, (16 - 1) << 2, (16 - 1) << 2),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0104, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2),
    gsDPSetTileSize(4, 0, 0, (8 - 1) << 2, (8 - 1) << 2),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0106, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, 3, G_TX_NOMIRROR | G_TX_WRAP, 2, 3),
    gsDPSetTileSize(5, 0, 0, (4 - 1) << 2, (4 - 1) << 2),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0107, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 1, 4, G_TX_NOMIRROR | G_TX_WRAP, 1, 4),
    gsDPSetTileSize(6, 0, 0, (2 - 1) << 2, (2 - 1) << 2),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_LOD),
    gsSPEndDisplayList()
};

bool D_80370990 = FALSE;

BKGeoCmdFunc sGeoCmdList[] = {
    modelRender_geoCmd_Unk0,
    modelRender_geoCmd_SORT,
    modelRender_geoCmd_BONE,
    modelRender_geoCmd_LOADDL,
    modelRender_geoCmd_NOP,
    modelRender_geoCmd_SKINNING,
    modelRender_geoCmd_CALL,
    modelRender_geoCmd_LOADDL2,
    modelRender_geoCmd_LOD,
    modelRender_geoCmd_NOP,
    modelRender_geoCmd_REFPOINT,
    modelRender_geoCmd_NOP,
    modelRender_geoCmd_SELECTOR,
    modelRender_geoCmd_DRAWDIST,
    modelRender_geoCmd_UnkE,
    modelRender_geoCmd_CAMERA,
    modelRender_geoCmd_TEXWRAP
};

enum model_render_color_mode_e{
    COLOR_MODE_DYNAMIC_PRIM_AND_ENV,
    COLOR_MODE_DYNAMIC_ENV,
    COLOR_MODE_STATIC_OPAQUE,
    COLOR_MODE_STATIC_TRANSPARENT
};

/* .bss */
Vec3fArray *modelRenderRefPoints;
s32  D_80383658[0x2A];
BoneTransformList *modelRenderBoneTransformList;
bool D_80383704;
f32  D_80383708;
f32  D_8038370C;
bool D_80383710;
enum model_render_color_mode_e  modelRenderColorMode;
BKGfxList *            modelRenderDisplayList;
AnimMtxList *            D_8038371C;
static BKTextureList * modelRenderTextureList;
s32                    modelRenderAnimatedTexturesCacheId;
static BKVertexList *  modelRendervertexList;
BKCameraAreaList *     modelRenderCameraAreaList;
AnimMtxList *            modelRenderAnimMtxList;
f32                    modelRenderScale;

struct{
    s32 env[4];
    s32 prim[4];
} modelRenderDynColors;

struct{
    f32 unk0[3];
    f32 unkC[3];
    s32 unk18;
    f32 unk1C[3];
    f32 unk28[3];
} D_80383758;

struct{
    model_render_pre_draw_callback_f pre_draw;
    void *pre_draw_arg;
    model_render_post_draw_callback_f post_draw;
    void *post_draw_arg;
} modelRenderCallback;

s32 modelRenderDynEnvColor[4];

struct {
    s32 unk0;
    f32 unk4[3];
}D_803837B0;

u8 modelRenderDynAlpha;

struct {
    enum asset_e model_id;
    f32 distance_from_center;
    f32 distance_from_origin;
    s32 padC;
} sSecondaryModelData; 

static enum model_render_depth_mode_e modelRenderDepthMode;

struct {
    LookAt lookat_buffer[32];
    LookAt *cur_lookat;
    LookAt *lookat_buffer_end;
    f32 eye_pos[3];
} D_803837E0;
MtxF D_80383BF8;

f32 modelRenderCameraPosition[3];
f32 modelRenderCameraRotation[3];
BKModelBin *modelRenderModelBin;
f32 modelRenderRotation[3];

void modelRender_reset(void){
    modelRenderBoneTransformList = NULL;
    D_80383708 = 30000.0f;
    D_80383704 = TRUE;
    D_8038370C = 1.0f;
    D_80383710 = FALSE;
    modelRenderColorMode = COLOR_MODE_STATIC_OPAQUE;
    modelRenderRefPoints = NULL;
    modelRenderDisplayList = NULL;
    D_8038371C = NULL;
    modelRenderTextureList = NULL;
    modelRenderAnimatedTexturesCacheId = 0;
    modelRendervertexList = NULL;
    modelRenderCameraAreaList = NULL;
    modelRenderCallback.pre_draw = NULL;
    modelRenderCallback.post_draw = NULL;
    D_803837B0.unk0 = 0;
    sSecondaryModelData.model_id = NULL;
    modelRenderDepthMode = MODEL_RENDER_DEPTH_NONE;
    func_8033A45C(1,1);
    func_8033A45C(2,0);
    if(D_80383758.unk18){
        viewport_setPosition_vec3f(D_80383758.unk1C);
        viewport_setRotation_vec3f(D_80383758.unk28);
        viewport_update();
    }
}

void modelRender_geoCmd_NOP(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data) {
    return;
}

void modelRender_geoCmd_Unk0(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data) {
    struct geo_cmd_0_s *cmd = (struct geo_cmd_0_s *) data;
    f32 transformed_pos[3];

    if (cmd->branch_offset) {
        mlMtx_apply_vec3f(transformed_pos, cmd->position);
        mlMtx_push_translation(transformed_pos[0], transformed_pos[1], transformed_pos[2]);
        mlMtxRotYaw(modelRenderCameraRotation[1]);
        if (!cmd->do_pitch_rotate) {
            mlMtxRotPitch(modelRenderCameraRotation[0]);
        }
        mlMtxScale(modelRenderScale);
        mlMtxTranslate(-cmd->position[0], -cmd->position[1], -cmd->position[2]);
        mlMtxApply(*mtx);
        gSPMatrix((*gfx)++, (*mtx)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        modelRender_executeGeoCmds(gfx, mtx, (struct bk_geo_cmd_s *) ((u8 *) cmd + cmd->branch_offset));
        mlMtxPop();
        gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);
    }
}

// SORT - Call sublist based on points distance
// Calculates which point is nearer, after they are transformed by the current matrix and then runs either
// the first or second sublist, if the flag is set, else it calls both sublists, the nearer first
void modelRender_geoCmd_SORT(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data) {
    struct geo_cmd_sort_s *cmd = (struct geo_cmd_sort_s *) data;
    f32 dot_prod;
    static f32 debug_var;
    static f32 dist[3];
    static f32 p1[3];
    static f32 p2[3];

    mlMtx_apply_vec3f(p1, cmd->point_1);
    mlMtx_apply_vec3f(p2, cmd->point_2);

    dist[0] = p2[0] - p1[0];
    dist[1] = p2[1] - p1[1];
    dist[2] = p2[2] - p1[2];

    dot_prod = dist[0] * p1[0] + dist[1] * p1[1] + dist[2] * p1[2];
    dot_prod = -dot_prod;

    if (cmd->flags & BK_GEO_CMD_SORT_RUN_BOTH_BIT) {
        if ((dot_prod >= 0.0f) && cmd->branch_offset_2) {
            debug_var = dot_prod;
            modelRender_executeGeoCmds(gfx, mtx, (struct bk_geo_cmd_s *) ((u8 *) cmd + cmd->branch_offset_2));
        }
        else {
            debug_var = dot_prod;

            if ((dot_prod < 0.0f) && cmd->branch_offset_1)
                modelRender_executeGeoCmds(gfx, mtx, (struct bk_geo_cmd_s *) ((u8 *) cmd + cmd->branch_offset_1));
        }
    } else {
        debug_var = dot_prod;

        if (dot_prod >= 0.0f) {
            if (cmd->branch_offset_1)
                modelRender_executeGeoCmds(gfx, mtx, (struct bk_geo_cmd_s *) ((u8 *) cmd + cmd->branch_offset_1));

            if (cmd->branch_offset_2)
                modelRender_executeGeoCmds(gfx, mtx, (struct bk_geo_cmd_s *) ((u8 *) cmd + cmd->branch_offset_2));
        } else {
            if (cmd->branch_offset_2)
                modelRender_executeGeoCmds(gfx, mtx, (struct bk_geo_cmd_s *) ((u8 *) cmd + cmd->branch_offset_2));

            if (cmd->branch_offset_1)
                modelRender_executeGeoCmds(gfx, mtx, (struct bk_geo_cmd_s *) ((u8 *) cmd + cmd->branch_offset_1));
        }
    }
}

// TEXWRAP - Sets the texture wrapping mode
void modelRender_geoCmd_TEXWRAP(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data) {
    struct geo_cmd_set_texture_wrap_mode_s *cmd = (struct geo_cmd_set_texture_wrap_mode_s *) data;

    switch(cmd->mode) {
        case 1:
            gSPDisplayList((*gfx)++, mipMapClampDL);
            break;
        case 2:
            gSPDisplayList((*gfx)++, mipMapWrapDL);
            break;
    }
}

void modelRender_geoCmd_BONE(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data) {
    struct geo_cmd_bone_s *cmd = (struct geo_cmd_bone_s *) data;

    if (D_8038371C) {
        mlMtx_push_multiplied_2(&D_80383BF8, animMtxList_get(D_8038371C, cmd->anim_matrix_id));
        if (D_80370990) {
            mlMtxApply(*mtx);
            gSPMatrix((*gfx)++, (*mtx)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        }
    }

    if (cmd->branch_offset) {
        modelRender_executeGeoCmds(gfx, mtx, (struct bk_geo_cmd_s *) ((u8 *) cmd + cmd->branch_offset));
    }

    if (D_8038371C) {
        mlMtxPop();
        if (D_80370990) {
            gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);
        }
    }
}   

void modelRender_geoCmd_LOADDL(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data) {
    struct geo_cmd_load_dl_s *cmd = (struct geo_cmd_load_dl_s *) data;
    Gfx *gfx_sub_list;

    if (D_80370990) {
        gfx_sub_list = &modelRenderDisplayList->list[cmd->gfx_index];
        gSPDisplayList((*gfx)++, osVirtualToPhysical(gfx_sub_list));
    }
}

void modelRender_geoCmd_SKINNING(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data) {
    struct geo_cmd_skinning_s *cmd = (struct geo_cmd_skinning_s *) data;
    int i;

    if (D_80370990) {
        gSPDisplayList((*gfx)++, osVirtualToPhysical(modelRenderDisplayList->list + cmd->gfx_index[0]));
    }

    if (D_80370990) {
        for (i = 1; cmd->gfx_index[i] != 0; i++) {
            mlMtxApply(*mtx);
            gSPMatrix((*gfx)++, (*mtx)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList((*gfx)++, osVirtualToPhysical(modelRenderDisplayList->list + cmd->gfx_index[i]));
        }
    }
}

void modelRender_geoCmd_CALL(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data) {
    struct geo_cmd_call_s *cmd = (struct geo_cmd_call_s *) data;

    modelRender_executeGeoCmds(gfx, mtx, (struct bk_geo_cmd_s *) ((u8 *) cmd + cmd->branch_offset));
}

void modelRender_geoCmd_LOADDL2(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data) {
    if (D_80370990) {
        gSPDisplayList((*gfx)++, osVirtualToPhysical(&modelRenderDisplayList->list[((struct geo_cmd_load_dl_2_s *) data)->gfx_index]));
    }
}

void modelRender_geoCmd_LOD(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data) {
    struct geo_cmd_lod_s *cmd = (struct geo_cmd_lod_s *) data;
    f32 dist;
    static f32 transformed_pos[3];
    
    if (cmd->branch_offset) {
        mlMtx_apply_vec3f(transformed_pos, cmd->position);
        dist = LENGTH_VEC3F(transformed_pos);
        if ((cmd->min < dist) && (dist <= cmd->max)) {
            modelRender_executeGeoCmds(gfx, mtx, (struct bk_geo_cmd_s *) ((u8 *) cmd + cmd->branch_offset));
        }
    }
}

void modelRender_geoCmd_REFPOINT(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data) {
    struct geo_cmd_reference_point_s *cmd = (struct geo_cmd_reference_point_s *) data;
    f32 transformed_point[3];

    if (modelRenderRefPoints) {
        if (D_8038371C) {
            mlMtx_push_multiplied_2(&D_80383BF8, animMtxList_get(D_8038371C, cmd->anim_mtx_id));
            mlMtx_apply_vec3f(transformed_point, cmd->point);
            mlMtxPop();
        } else {
            mlMtx_apply_vec3f(transformed_point, cmd->point);
        }
        transformed_point[0] += modelRenderCameraPosition[0];
        transformed_point[1] += modelRenderCameraPosition[1];
        transformed_point[2] += modelRenderCameraPosition[2];
        vec3fArray_set_vec3f(modelRenderRefPoints, cmd->index, transformed_point);
    }
}

void modelRender_geoCmd_SELECTOR(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data) {
    struct geo_cmd_selector_s *cmd = (struct geo_cmd_selector_s *) data;
    s32 sub_cmd_addr;
    s32 selection;
    int i;
    s32 s1;
    s32 *offset;
    
    selection = D_80383658[cmd->index];

    if (cmd->index == 0)
        return;

    if (selection == 0)
        return;
    
    if (selection > 0) {
        if (selection <= cmd->branch_offset_count) {
            offset = cmd->branch_offsets;
            sub_cmd_addr = (s32) cmd;
            sub_cmd_addr += *(s32*)(offset + (selection - 1));
            modelRender_executeGeoCmds(gfx, mtx, (struct bk_geo_cmd_s* ) sub_cmd_addr);
        }
    } else {
        s1 = -selection;
        offset = cmd->branch_offsets;
        for (i = 0; i < cmd->branch_offset_count; i++) {
            if (s1 & 0x01)
            {
                sub_cmd_addr = (s32)cmd;
                sub_cmd_addr += *offset;
                modelRender_executeGeoCmds(gfx, mtx, (struct bk_geo_cmd_s* ) sub_cmd_addr);
            }
            s1 >>= 1;
            offset++;
        }
    }
}

void modelRender_geoCmd_DRAWDIST(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data) {
    f32 scaled_min[3], scaled_max[3];
    struct geo_cmd_draw_distance_s *cmd = (struct geo_cmd_draw_distance_s *) data;

    if (cmd->branch_offset) {
        scaled_min[0] = cmd->min[0] * modelRenderScale;
        scaled_min[1] = cmd->min[1] * modelRenderScale;
        scaled_min[2] = cmd->min[2] * modelRenderScale;

        scaled_max[0] = cmd->max[0] * modelRenderScale;
        scaled_max[1] = cmd->max[1] * modelRenderScale;
        scaled_max[2] = cmd->max[2] * modelRenderScale;

        if (viewport_isBoundingBoxInFrustum(scaled_min, scaled_max)) {
            modelRender_executeGeoCmds(gfx, mtx, (struct bk_geo_cmd_s *) ((u8 *) cmd + cmd->branch_offset));
        }
    }
}

void modelRender_geoCmd_UnkE(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data) {
    f32 pos_scaled[3];
    f32 dist_scaled;
    struct geo_cmd_E_s *cmd = (struct geo_cmd_E_s *) data;

    if (cmd->anim_mtx_id == -1) {
        pos_scaled[0] = cmd->position[0] * modelRenderScale;
        pos_scaled[1] = cmd->position[1] * modelRenderScale;
        pos_scaled[2] = cmd->position[2] * modelRenderScale;
        dist_scaled = cmd->distance * modelRenderScale;

        if (viewport_func_8024DB50(pos_scaled, dist_scaled) && cmd->branch_offset) {
            modelRender_executeGeoCmds(gfx, mtx, (struct bk_geo_cmd_s *) ((u8 *) cmd + cmd->branch_offset));
        }
    } else {
        pos_scaled[0] = cmd->position[0];
        pos_scaled[1] = cmd->position[1];
        pos_scaled[2] = cmd->position[2];
        dist_scaled = cmd->distance * modelRenderScale;

        if (D_8038371C) {
            mlMtx_push_multiplied_2(&D_80383BF8, animMtxList_get(D_8038371C, cmd->anim_mtx_id));
            mlMtx_apply_vec3f(pos_scaled, pos_scaled);
            mlMtxPop();
        } else {
            mlMtx_apply_vec3f(pos_scaled, pos_scaled);
        }

        pos_scaled[0] += modelRenderCameraPosition[0];
        pos_scaled[1] += modelRenderCameraPosition[1];
        pos_scaled[2] += modelRenderCameraPosition[2];
        if (viewport_func_8024DB50(pos_scaled, dist_scaled) && cmd->branch_offset) {
            modelRender_executeGeoCmds(gfx, mtx, (struct bk_geo_cmd_s *) ((u8 *) cmd + cmd->branch_offset));
        }
    }
}

void modelRender_geoCmd_CAMERA(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data) {
    struct geo_cmd_camera_s *cmd = (struct geo_cmd_camera_s *) data;
    bool found = cameraAreaList_searchForEntryInBounds(modelRenderCameraAreaList, cmd->id_list, cmd->count);

    if ((!found && (cmd->flags & BK_GEO_CMD_CAMERA_IS_OUTSIDE_BIT)) || (found && (cmd->flags & BK_GEO_CMD_CAMERA_IS_INSIDE_BIT))) {
        if (cmd->branch_offset)
            modelRender_executeGeoCmds(gfx, mtx, (struct bk_geo_cmd_s *) ((u8 *) cmd + cmd->branch_offset));
    }

}

void modelRender_executeGeoCmds(Gfx **gfx, Mtx **mtx, struct bk_geo_cmd_s *data) {
    while (TRUE) {
        sGeoCmdList[data->cmd](gfx, mtx, data);
        if (data->next_offset == 0)
            return;
        data = (struct bk_geo_cmd_s *) ((u8 *) data + data->next_offset);
    };
}

BKModelBin *modelRender_draw(Gfx **gfx, Mtx **mtx, f32 position[3], f32 rotation[3], f32 scale, f32*arg5, BKModelBin* model_bin) {
    f32 camera_focus[3];
    f32 camera_focus_distance;
    f32 padEC;
    f32 object_position[3];
    void *rendermode_table_opa; // Table of render modes to use for opaque rendering
    void *rendermode_table_xlu; // Table of render modes to use for translucent rendering
    f32 spD4;
    f32 spD0;
    BKVertexList *verts;
    s32 alpha; 
    f32 tmp_f0;
    f32 padB8;
    
    if ((!model_bin && !sSecondaryModelData.model_id) || (model_bin && sSecondaryModelData.model_id)) {
        modelRender_reset();
        return NULL;
    }

    D_80370990 = FALSE;

    viewport_getPosition_vec3f(modelRenderCameraPosition);
    viewport_getRotation_vec3f(modelRenderCameraRotation);

    if(D_80383758.unk18){
        D_80383758.unk1C[0] = modelRenderCameraPosition[0],
        D_80383758.unk1C[1] = modelRenderCameraPosition[1],
        D_80383758.unk1C[2] = modelRenderCameraPosition[2];
    
        D_80383758.unk28[0] = modelRenderCameraRotation[0],
        D_80383758.unk28[1] = modelRenderCameraRotation[1],
        D_80383758.unk28[2] = modelRenderCameraRotation[2];
    }

    if(position){
        object_position[0] = position[0];
        object_position[1] = position[1];
        object_position[2] = position[2];
    }
    else{
        object_position[0] = object_position[1] = object_position[2] = 0.0f;
    }

    camera_focus[0] = object_position[0] - modelRenderCameraPosition[0];
    camera_focus[1] = object_position[1] - modelRenderCameraPosition[1];
    camera_focus[2] = object_position[2] - modelRenderCameraPosition[2];

    if( ((camera_focus[0] < -17000.0f) || (17000.0f < camera_focus[0]))
        || ((camera_focus[1] < -17000.0f) || (17000.0f < camera_focus[1]))
        || ((camera_focus[2] < -17000.0f) || (17000.0f < camera_focus[2]))
    ){
        modelRender_reset();
        return 0;
    }

    if(D_80383758.unk18){
        modelRenderCameraPosition[0] = D_80383758.unk0[0];
        modelRenderCameraPosition[1] = D_80383758.unk0[1];
        modelRenderCameraPosition[2] = D_80383758.unk0[2];

        modelRenderCameraRotation[0] = D_80383758.unkC[0],
        modelRenderCameraRotation[1] = D_80383758.unkC[1],
        modelRenderCameraRotation[2] = D_80383758.unkC[2];
        viewport_setPosition_vec3f(modelRenderCameraPosition);
        viewport_setRotation_vec3f(modelRenderCameraRotation);
        viewport_update();
        camera_focus[0] = object_position[0] - modelRenderCameraPosition[0];
        camera_focus[1] = object_position[1] - modelRenderCameraPosition[1];
        camera_focus[2] = object_position[2] - modelRenderCameraPosition[2];
    }

    if(model_bin){
        verts = modelRendervertexList ? modelRendervertexList : modelbin_getVtxList_MACRO(model_bin);
        spD0 = verts->global_norm;
        spD4 = verts->local_norm;
    }
    else{
        spD0 = sSecondaryModelData.distance_from_origin;
        spD4 = sSecondaryModelData.distance_from_center;
    }
    camera_focus_distance = sqrtf(camera_focus[0]*camera_focus[0] + camera_focus[1]*camera_focus[1] + camera_focus[2]*camera_focus[2]);
    if( 4000.0f <= camera_focus_distance && spD4*scale*D_8038370C*50.0f < D_80383708){
        D_80383708 = spD4*scale*D_8038370C*50.0f;
    }

    if(D_80383708 <= camera_focus_distance){
        modelRender_reset();
        return 0;
    }

    D_80370990 = (D_80383704) ? viewport_func_8024DB50(object_position, spD0*scale) : TRUE;
    if (!D_80370990) {
        modelRender_reset();
        return 0;
    }

    if (modelRenderCallback.pre_draw != NULL) {
        modelRenderCallback.pre_draw(modelRenderCallback.pre_draw_arg);
    }
    func_80349AD0();
    if(model_bin == NULL){
        model_bin = assetcache_get(sSecondaryModelData.model_id);
    }
    modelRenderModelBin = model_bin;
    modelRenderDisplayList = modelRenderDisplayList ? modelRenderDisplayList : modelbin_getGfxList_MACRO(modelRenderModelBin),
    modelRenderTextureList = modelRenderTextureList ? modelRenderTextureList : modelbin_getTextureList_MACRO(modelRenderModelBin),
    modelRendervertexList = modelRendervertexList ? modelRendervertexList : modelbin_getVtxList_MACRO(modelRenderModelBin),
    modelRenderCameraAreaList = (modelRenderModelBin->camera_area_list_offset == NULL) ? NULL : modelbin_getCameraAreaList_MACRO(model_bin);

    if(D_80383710){
        tmp_f0 = D_80383708 - 500.0f;
        if(tmp_f0 < camera_focus_distance){
            alpha = (s32)((1.0f - (camera_focus_distance - tmp_f0)/500.0f)*255.0f);
            if(modelRenderColorMode == COLOR_MODE_DYNAMIC_PRIM_AND_ENV){
                modelRenderDynColors.prim[3] = (modelRenderDynColors.prim[3] * alpha) / 0xff;
            }
            else if(modelRenderColorMode == COLOR_MODE_DYNAMIC_ENV){
                modelRenderDynEnvColor[3] = (modelRenderDynEnvColor[3] * alpha)/0xff;
            }
            else if(modelRenderColorMode == COLOR_MODE_STATIC_OPAQUE){
                modelRender_setAlpha(alpha);
            }
            else if(modelRenderColorMode == COLOR_MODE_STATIC_TRANSPARENT){
                modelRenderDynAlpha = (modelRenderDynAlpha *alpha)/0xff;
            }
        }
    }

    // Set up segments 1 and 2 to point to vertices and textures respectively
    gSPSegment((*gfx)++, 0x01, osVirtualToPhysical(&modelRendervertexList->vertices));
    gSPSegment((*gfx)++, 0x02, osVirtualToPhysical(&modelRenderTextureList->texture_infos[modelRenderTextureList->count]));

    //segments 11 to 15 contain animated textures
    if(modelRenderAnimatedTexturesCacheId){
        int i_segment;
        s32 texture_offset;
        
        for(i_segment = 0; i_segment < 4; i_segment++){
            if(AnimTextureListCache_tryGetTextureOffset(modelRenderAnimatedTexturesCacheId, i_segment, &texture_offset))
                gSPSegment((*gfx)++, 15 - i_segment, osVirtualToPhysical((u8*)&modelRenderTextureList->texture_infos[modelRenderTextureList->count] + texture_offset));
        }
    }

    if(modelRenderDepthMode != MODEL_RENDER_DEPTH_NONE){
        gSPSetGeometryMode((*gfx)++, G_ZBUFFER);
    }
    else{
        gSPClearGeometryMode((*gfx)++, G_ZBUFFER);
    }

    // Pick a table of render modes for opaque and translucent rendering
    if(modelRenderDepthMode == MODEL_RENDER_DEPTH_NONE){ // No depth buffering
        rendermode_table_opa = renderModesNoDepthOpa;
        rendermode_table_xlu = renderModesNoDepthXlu;
    }
    else if(modelRenderDepthMode == MODEL_RENDER_DEPTH_FULL){ // Full depth buffering
        rendermode_table_opa = renderModesFullDepthOpa;
        rendermode_table_xlu = renderModesFullDepthXlu;
    }
    else if(modelRenderDepthMode == MODEL_RENDER_DEPTH_COMPARE){ // Depth compare but no depth write
        rendermode_table_opa = renderModesDepthCompareOpa;
        rendermode_table_xlu = renderModesDepthCompareXlu;
    }

    if(modelRenderColorMode == COLOR_MODE_DYNAMIC_PRIM_AND_ENV){
        s32 alpha;
        
        alpha = modelRenderDynColors.prim[3] + (modelRenderDynColors.env[3]*(0xFF - modelRenderDynColors.prim[3]))/0xff;
        gSPDisplayList((*gfx)++, setup2CycleDL);
        gDPSetEnvColor((*gfx)++, modelRenderDynColors.env[0], modelRenderDynColors.env[1], modelRenderDynColors.env[2], alpha);
        gDPSetPrimColor((*gfx)++, 0, 0, modelRenderDynColors.prim[0], modelRenderDynColors.prim[1], modelRenderDynColors.prim[2], 0);

        // Set up segment 3 to point to the right render mode table based on the alpha value
        if(alpha == 0xFF){
            gSPSegment((*gfx)++, 0x03, osVirtualToPhysical(rendermode_table_opa));
        }
        else{
            gSPSegment((*gfx)++, 0x03, osVirtualToPhysical(rendermode_table_xlu));
        }
        //TODO
    }
    else if(modelRenderColorMode == COLOR_MODE_DYNAMIC_ENV){
        gSPDisplayList((*gfx)++, setup2CycleBlackPrimDL);
        gDPSetEnvColor((*gfx)++, modelRenderDynEnvColor[0], modelRenderDynEnvColor[1], modelRenderDynEnvColor[2], modelRenderDynEnvColor[3]);

        // Set up segment 3 to point to the right render mode table based on the alpha value
        if(modelRenderDynEnvColor[3] == 0xFF){
            gSPSegment((*gfx)++, 0x03, osVirtualToPhysical(rendermode_table_opa));
        }
        else{
            gSPSegment((*gfx)++, 0x03, osVirtualToPhysical(rendermode_table_xlu));
        }
    }
    else if(modelRenderColorMode == COLOR_MODE_STATIC_OPAQUE){
        gSPDisplayList((*gfx)++, setup2CycleWhiteEnvDL);
        gSPSegment((*gfx)++, 0x03, osVirtualToPhysical(rendermode_table_opa));
    }
    else if(modelRenderColorMode == COLOR_MODE_STATIC_TRANSPARENT){
        gSPDisplayList((*gfx)++, setup2CycleDL_copy);
        gDPSetEnvColor((*gfx)++, 0xFF, 0xFF, 0xFF, modelRenderDynAlpha);
        gSPSegment((*gfx)++, 0x03, osVirtualToPhysical(rendermode_table_xlu));
    }

    if(modelRenderModelBin->geo_type & BK_GEO_TYPE_MIPMAP_TRILINEAR_BIT){ //trilinear mipmapping
        gSPDisplayList((*gfx)++, mipMapWrapDL);
    }

    if(modelRenderModelBin->geo_type & BK_GEO_TYPE_ENV_MAP_BIT){ //env mapping
        if(0.0f == camera_focus[2]){
            camera_focus[2] = -0.1f;
        }
        guLookAtReflect(*mtx, D_803837E0.cur_lookat,
            D_803837E0.eye_pos[0], D_803837E0.eye_pos[1], D_803837E0.eye_pos[2],
            camera_focus[0], camera_focus[1], camera_focus[2],
            0.0f, 1.0f, 0.0f);
        gSPLookAt((*gfx)++, D_803837E0.cur_lookat);
        osWritebackDCache(D_803837E0.cur_lookat, sizeof(LookAt));
        D_803837E0.cur_lookat++;
        if(D_803837E0.cur_lookat == D_803837E0.lookat_buffer_end)
            D_803837E0.cur_lookat = D_803837E0.lookat_buffer;
    }

    if(D_8038371C && !modelRenderModelBin->animation_list_offset){
        D_8038371C = 0;
    }
    else if(D_8038371C == 0 && modelRenderModelBin->animation_list_offset){
        if(modelRenderBoneTransformList == NULL){
            animMtxList_setBoneless(&modelRenderAnimMtxList, modelbin_getAnimationList_MACRO(model_bin));
        }
        else{
            animMtxList_setBoned(&modelRenderAnimMtxList, modelbin_getAnimationList_MACRO(model_bin), modelRenderBoneTransformList);
        }
        D_8038371C = modelRenderAnimMtxList;
    }

    if(modelRenderCameraAreaList){
        cameraAreaList_updateInBoundsFlag(modelRenderCameraAreaList, modelRenderCameraPosition, scale);
    }

    if(model_bin->anim_vertices_list_offset != NULL && D_8038371C != NULL){
        animVerticesList_transform(modelbin_getAnimVerticesList_MACRO(modelRenderModelBin), modelRendervertexList, D_8038371C);
    }

    mlMtxIdent();
    if(D_80383758.unk18){
        func_80252AF0(D_80383758.unk1C, object_position, rotation, scale, arg5);
    }
    else{
        func_80252AF0(modelRenderCameraPosition, object_position, rotation, scale, arg5);
    }

    if(D_803837B0.unk0){
        mlMtxRotatePYR(D_803837B0.unk4[0], D_803837B0.unk4[1], D_803837B0.unk4[2]);
    }
    mlMtxGet(&D_80383BF8);

    mlMtxApply(*mtx);
    gSPMatrix((*gfx)++, (*mtx)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
    modelRenderScale = scale;
    if(rotation){
        modelRenderRotation[0] = rotation[0];
        modelRenderRotation[1] = rotation[1];
        modelRenderRotation[2] = rotation[2];
    }
    else{
        modelRenderRotation[0] = modelRenderRotation[1] = modelRenderRotation[2] = 0.0f;
    }

    modelRender_executeGeoCmds(gfx, mtx, modelbin_getGeoCmdList_MACRO(model_bin));
    gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);

    if (modelRenderCallback.post_draw != NULL) {
        modelRenderCallback.post_draw(modelRenderCallback.post_draw_arg);
    }

    if(sSecondaryModelData.model_id){
        assetCache_free(model_bin);
    }

    modelRender_reset();
    return model_bin;
}

BKAnimVerticesList *modelbin_getAnimVerticesList(BKModelBin *this) {
    if (this->anim_vertices_list_offset == 0)
        return NULL;

    return modelbin_getAnimVerticesList_MACRO(this);
}

BoneTransformList *modelRender_getBoneTransformList(void) {
    return modelRenderBoneTransformList;
}

BkGeoType modelbin_getGeoType(BKModelBin *this) {
    return this->geo_type;
}

BKGfxList *modelbin_getGfxList(BKModelBin *this) {
    return modelbin_getGfxList_MACRO(this);
}

BKCollisionList *modelbin_getCollisionList(BKModelBin *this) {
    if (this == NULL)
        return NULL;
    
    if (this->collision_list_offset == 0)
        return NULL;

    return modelbin_getCollisionList_MACRO(this);
}

BKMeshList *modelbin_getMeshList(BKModelBin *this) {
    if (this->mesh_list_offset == 0)
        return NULL;

    return modelbin_getMeshList_MACRO(this);
}

f32 modelbin_getUnk34(BKModelBin *this) {
    return this->unk34;
}

BKAnimationList *modelbin_getAnimationList(BKModelBin *this) {
    if (this->animation_list_offset == 0)
        return NULL;

    return modelbin_getAnimationList_MACRO(this);
}

s32 modelRender_func_8033A0F0(s32 arg0) {
    return D_80383658[arg0];
}

BKTextureList *modelbin_getTextureList(BKModelBin *this) {
    return modelbin_getTextureList_MACRO(this);
}

BKAnimTextureList *modelbin_getAnimTextureList(BKModelBin *this) {
    if (this->animated_texture_list_offset == 0)
        return NULL;

    return modelbin_getAnimTextureList_MACRO(this);
}

BKModelUnk14List *modelbin_getUnk14List(BKModelBin *this) {
    if (this->unk14_list_offset == 0)
        return NULL;

    return modelbin_getUnk14List_MACRO(this);
}

BKVertexList *modelbin_getVtxList(BKModelBin *this) {
    return modelbin_getVtxList_MACRO(this);
}

BKCameraAreaList *modelbin_getCameraAreaList(BKModelBin *this) {
    return (this->camera_area_list_offset == 0) ? NULL : modelbin_getCameraAreaList_MACRO(this);
}

bool modelRender_func_8033A170(void) {
    return D_80370990;
}

void modelRender_free(void) {
    animMtxList_free(modelRenderAnimMtxList);
    modelRenderAnimMtxList = NULL;
}

void modelRender_init(void) {
    modelRender_reset();
    D_80383758.unk18 = 0;
    D_803837E0.cur_lookat = D_803837E0.lookat_buffer;
    D_803837E0.lookat_buffer_end = D_803837E0.cur_lookat + ARRAYLEN(D_803837E0.lookat_buffer);
    D_803837E0.eye_pos[0] = D_803837E0.eye_pos[1] = D_803837E0.eye_pos[2] = 0.0f;
    modelRenderAnimMtxList = animMtxList_new();
}

void modelRender_func_8033A1FC(void) {
    s32 i;
    for(i = 0; i < 0x2A; i++){
        D_80383658[i] = 0;
    }
}

void modelRender_setBoneTransformList(BoneTransformList *arg0) {
    modelRenderBoneTransformList = arg0;
}

f32 modelRender_func_8033A244(f32 arg0){
    f32 out = D_80383708;
    D_80383708 = arg0;
    return out;
}

void modelRender_func_8033A25C(bool arg0){
    D_80383704 = BOOL(arg0);
}  

void modelRender_func_8033A280(f32 arg0){
    D_8038370C = arg0;
}

void modelRender_func_8033A28C(bool arg0){
    D_80383710 = arg0;
}

void modelRender_func_8033A298(bool arg0) {
    D_80383758.unk18 = arg0;
    if(arg0){
        viewport_getPosition_vec3f(D_80383758.unk0);
        viewport_getRotation_vec3f(D_80383758.unkC);
    }
}

/* moderRender_preDraw() sets a generic 1 argument function that will
 * be called immediately prior to the model being drawn
 */
void modelRender_setPreDrawCallback(model_render_pre_draw_callback_f func, void *arg) {
    modelRenderCallback.pre_draw = func;
    modelRenderCallback.pre_draw_arg = arg;
}

/* moderRender_postDraw() sets a generic 1 argument function that will
 * be called immediately after to the model has been drawn
 */
void modelRender_setPostDrawCallback(model_render_post_draw_callback_f func, void *arg) {
    modelRenderCallback.post_draw = func;
    modelRenderCallback.post_draw_arg = arg;
}

void modelRender_setDisplayList(BKGfxList *gfx_list){
    modelRenderDisplayList = gfx_list;
}

void modelRender_func_8033A308(f32 arg0[3]){
    D_803837B0.unk0 = TRUE;
    D_803837B0.unk4[0] = arg0[0];
    D_803837B0.unk4[1] = arg0[1];
    D_803837B0.unk4[2] = arg0[2];
}

void modelRender_setPrimAndEnvColors(s32 env[4], s32 prim[4]){
    modelRenderColorMode = COLOR_MODE_DYNAMIC_PRIM_AND_ENV;

    modelRenderDynColors.env[0] = env[0];
    modelRenderDynColors.env[1] = env[1];
    modelRenderDynColors.env[2] = env[2];
    modelRenderDynColors.env[3] = env[3];

    modelRenderDynColors.prim[0] = prim[0];
    modelRenderDynColors.prim[1] = prim[1];
    modelRenderDynColors.prim[2] = prim[2];
    modelRenderDynColors.prim[3] = prim[3];
}

void modelRender_setEnvColor(s32 r, s32 g, s32 b, s32 a){
    modelRenderColorMode = COLOR_MODE_DYNAMIC_ENV;

    modelRenderDynEnvColor[0] = MIN(0xFF, r);
    modelRenderDynEnvColor[1] = MIN(0xFF, g);
    modelRenderDynEnvColor[2] = MIN(0xFF, b);
    modelRenderDynEnvColor[3] = MIN(0xFF, a);
}

void modelRender_setAlpha(s32 a){
    if(a == 0xff){
        modelRenderColorMode = COLOR_MODE_STATIC_OPAQUE;
    }
    else{
        modelRenderColorMode = COLOR_MODE_STATIC_TRANSPARENT;
        modelRenderDynAlpha = a;
    }
}

void modelRender_func_8033A444(AnimMtxList *arg0){
    D_8038371C = arg0;
}

void modelRender_setRefPoints(Vec3fArray *ref_points) {
    modelRenderRefPoints = ref_points;
}

void func_8033A45C(s32 arg0, s32 arg1){
    D_80383658[arg0] = arg1;
}

void modelRender_func_8033A470(s32 arg0, s32 arg1){
    D_80383658[arg0] = -arg1;
}

void modelRender_setTextureList(BKTextureList *texture_list) {
    modelRenderTextureList = texture_list;
}

void modelRender_setAnimatedTexturesCacheId(s32 arg0){
    modelRenderAnimatedTexturesCacheId = arg0;
}

void modelRender_setSecondaryModel(enum asset_e model_id, f32 distance_from_center, f32 distance_from_origin) {
    sSecondaryModelData.model_id = model_id;
    sSecondaryModelData.distance_from_center = distance_from_center;
    sSecondaryModelData.distance_from_origin = distance_from_origin;
}

void modelRender_setVertexList(BKVertexList *vertex_list) {
    modelRendervertexList = vertex_list;
}

void modelRender_setDepthMode(enum model_render_depth_mode_e mode) {
    modelRenderDepthMode = mode;
}

void modelRender_defrag(void) {
    if (modelRenderAnimMtxList != NULL) {
        modelRenderAnimMtxList = animMtxList_defrag(modelRenderAnimMtxList);
    }
}
