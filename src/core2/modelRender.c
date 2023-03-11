#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/modelRender.h"

#define ARRAYLEN(x) (sizeof(x) / sizeof((x)[0]))

extern bool func_802ED420(BKModelUnk20List *arg0, u8 *arg1, u32 arg2);
extern void func_802ED52C(BKModelUnk20List *, f32[3], f32);
extern void func_80252AF0(f32[3], f32[3], f32[3], f32, f32[3]);
extern void mlMtxRotate(f32, f32, f32);
extern void viewport_getPosition(f32[3]);
extern void viewport_getRotation(f32[3]);
extern void viewport_setPosition(f32[3]);
extern void viewport_setRotation(f32[3]);
extern void viewport_update(void);
extern void func_8033BD4C(BKModelBin *);
extern s32 func_8024DB50(f32[3], f32);
extern void func_80251788(f32, f32, f32);
extern void mlMtxScale(f32);
extern void mlMtxApply(Mtx* mtx);
extern struct58s *func_802EA154();
extern struct58s *func_802EA374(struct58s *);


typedef struct{
    void (* unk0)(Actor *);
    Actor *unk4;
} Struct_Core2_B1400_1;

typedef void (*GeoListFunc)(Gfx **, Mtx **, void *);

typedef struct {
    s32 cmd_0;
    s32 size_4;
    s16 unk8;
    s16 unkA;
    f32 unkC[3];
}GeoCmd0;

typedef struct {
    s32 cmd_0;
    s32 size_4;
    f32 unk8[3];
    f32 unk14[3];
    s16 unk20;
    s16 unk22;
    s32 unk24;
}GeoCmd1;

typedef struct {
    s32 cmd_0;
    s32 size_4;
    u8  unk8;
    s8  unk9;
}GeoCmd2;

typedef struct {
    s32 cmd_0;
    s32 size_4;
    s16 unk8;
}GeoCmd3;

typedef struct {
    s32 cmd_0;
    s32 size_4;
    s16 unk8[];
}GeoCmd5;

typedef struct {
    s32 cmd_0;
    s32 size_4;
    s32 unk8;
}GeoCmd6;

typedef struct {
    s32 cmd_0;
    s32 size_4;
    u8  pad8;
    s16 unkA;
}GeoCmd7;

typedef struct {
    s32 cmd_0;
    s32 size_4;
    f32 max_8;
    f32 min_C;
    f32 unk10[3];
    s32 subgeo_offset_1C;
}GeoCmd8;

typedef struct {
    s32 cmd_0;
    s32 size_4;
    s16 unk8;
    s16 unkA;
    f32 unkC[3];
}GeoCmdA;

typedef struct {
    s32 cmd_0;
    s32 size_4;
    s16 unk8;
    s16 unkA;
    s32 unkC[];
}GeoCmdC;

typedef struct {
    s32 cmd_0;
    s32 size_4;
    s16 unk8[3];
    s16 unkE[3];
    s16 unk14;
}GeoCmdD;

typedef struct {
    s32 cmd_0;
    s32 size_4;
    s16 unk8[3];
    s16 unkE;
    s16 unk10;
    s16 unk12;
}GeoCmdE;

typedef struct {
    s32 cmd_0;
    s32 size_4;
    s16 unk8;
    u8  unkA;
    u8  unkB;
    u8  unkC[12];
}GeoCmdF;

typedef struct {
    s32 cmd_0;
    s32 size_4;
    s32 unk8;
}GeoCmd10;



void func_803384A8(Gfx **, Mtx **, void *);
void func_803385BC(Gfx **, Mtx **, void *);
void func_803387F8(Gfx **, Mtx **, void *);
void func_80338904(Gfx **, Mtx **, void *);
void func_80338498(Gfx **, Mtx **, void *);
void func_80338970(Gfx **, Mtx **, void *);
void func_80338AC4(Gfx **, Mtx **, void *);
void func_80338AE8(Gfx **, Mtx **, void *);
void func_80338498(Gfx **, Mtx **, void *);
void func_8033878C(Gfx **, Mtx **, void *);
void func_80338B50(Gfx **, Mtx **, void *);
void func_80338BFC(Gfx **, Mtx **, void *);
void func_80338CD0(Gfx **, Mtx **, void *);
void func_80338DCC(Gfx **, Mtx **, void *);
void func_80338EB8(Gfx **, Mtx **, void *);
void func_8033909C(Gfx **, Mtx **, void *);
void func_80339124(Gfx **, Mtx **, BKGeoList *);
void func_8033A45C(s32 arg0, s32 arg1);

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

s32 D_80370990 = 0;

GeoListFunc D_80370994[] = {
    func_803384A8,
    func_803385BC,
    func_803387F8,
    func_80338904,
    func_80338498, //empty_4
    func_80338970,
    func_80338AC4,
    func_80338AE8,
    func_80338B50,
    func_80338498, //empty_9
    func_80338BFC,
    func_80338498, //empty_B
    func_80338CD0,
    func_80338DCC,
    func_80338EB8,
    func_8033909C,
    func_8033878C
};

enum model_render_color_mode_e{
    COLOR_MODE_DYNAMIC_PRIM_AND_ENV,
    COLOR_MODE_DYNAMIC_ENV,
    COLOR_MODE_STATIC_OPAQUE,
    COLOR_MODE_STATIC_TRANSPARENT
};

/* .bss */
struct5Bs *D_80383650;
s32  D_80383658[0x2A];
s32  D_80383700;
bool D_80383704;
f32  D_80383708;
f32  D_8038370C;
s32  D_80383710;
enum model_render_color_mode_e  modelRenderColorMode;
BKGfxList *            modelRenderDisplayList;
struct58s *            D_8038371C;
static BKTextureList * modelRenderTextureList;
s32                    D_80383724;
static BKVertexList *  modelRendervertexList;
BKModelUnk20List *     D_8038372C;
struct58s *            D_80383730;
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
    GenMethod_1 pre_method;
    s32 pre_arg;
    GenMethod_1 post_method;
    s32 post_arg;
} modelRenderCallback;

s32 modelRenderDynEnvColor[4];

struct {
    s32 unk0;
    f32 unk4[3];
}D_803837B0;

u8 modelRenderDynAlpha;

struct {
    s32 model_id; //model_asset_index
    f32 unk4;
    f32 unk8;
    u8 padC[0x4];
} D_803837C8; 

static enum model_render_depth_mode_e modelRenderDepthMode;

struct {
    LookAt lookat_buffer[32];
    LookAt *cur_lookat;
    LookAt *lookat_buffer_end;
    f32 eye_pos[3];
} D_803837E0;
Mtx D_80383BF8;
f32 modelRenderCameraPosition[3];
f32 modelRenderCameraRotation[3];
BKModelBin *modelRenderModelBin;
f32 modelRenderRotation[3];
f32 D_80383C64;
f32 D_80383C68[3];
f32 D_80383C78[3];
f32 D_80383C88[3];
f32 D_80383C98[3];

/* .code */
void modelRender_reset(void){
    D_80383700 = 0;
    D_80383708 = 30000.0f;
    D_80383704 = TRUE;
    D_8038370C = 1.0f;
    D_80383710 = FALSE;
    modelRenderColorMode = COLOR_MODE_STATIC_OPAQUE;
    D_80383650 = 0;
    modelRenderDisplayList = NULL;
    D_8038371C = NULL;
    modelRenderTextureList = NULL;
    D_80383724 = 0;
    modelRendervertexList = NULL;
    D_8038372C = 0;
    modelRenderCallback.pre_method = NULL;
    modelRenderCallback.post_method = NULL;
    D_803837B0.unk0 = 0;
    D_803837C8.model_id = 0;
    modelRenderDepthMode = MODEL_RENDER_DEPTH_NONE;
    func_8033A45C(1,1);
    func_8033A45C(2,0);
    if(D_80383758.unk18){
        viewport_setPosition(D_80383758.unk1C);
        viewport_setRotation(D_80383758.unk28);
        viewport_update();
    }
}

//empty cmd, 
void func_80338498(Gfx **gfx, Mtx **mtx, void *arg2){
    return;
}

//cmd0_???
void func_803384A8(Gfx **gfx, Mtx **mtx, void *arg2){
    GeoCmd0 *cmd = (GeoCmd0 *)arg2;
    f32 sp30[3];

    if(cmd->unk8){
        func_8025235C(sp30, cmd->unkC);
        func_80251788(sp30[0], sp30[1], sp30[2]);
        mlMtxRotYaw(modelRenderCameraRotation[1]);
        if(!cmd->unkA){
            mlMtxRotPitch(modelRenderCameraRotation[0]);
        }
        mlMtxScale(modelRenderScale);
        mlMtxTranslate(-cmd->unkC[0], -cmd->unkC[1], -cmd->unkC[2]);
        mlMtxApply(*mtx);
        gSPMatrix((*gfx)++, (*mtx)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_80339124(gfx, mtx, (BKGeoList*)((s32)cmd + cmd->unk8));
        mlMtxPop();
        gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);
    }
}

//cmd1_SORT
void func_803385BC(Gfx **gfx, Mtx **mtx, void *arg2){
    GeoCmd1 *cmd = (GeoCmd1 *)arg2;
    f32 f14;
    s32 tmp_v0;

    func_8025235C(D_80383C78, cmd->unk8);
    func_8025235C(D_80383C88, cmd->unk14);

    D_80383C68[0] = D_80383C88[0] - D_80383C78[0];
    D_80383C68[1] = D_80383C88[1] - D_80383C78[1];
    D_80383C68[2] = D_80383C88[2] - D_80383C78[2];

    f14 = D_80383C68[0]*D_80383C78[0] + D_80383C68[1]*D_80383C78[1] + D_80383C68[2]*D_80383C78[2];
    f14 = -f14;
    if(cmd->unk20 & 1){
        if(0.0f <= f14 && (tmp_v0 = cmd->unk24)){
            D_80383C64 = f14;
            func_80339124(gfx, mtx, (BKGeoList*)((s32)cmd + tmp_v0));
        }
        else{
            D_80383C64 = f14;
            if(f14 < 0.0f){
                if(cmd->unk22)
                    func_80339124(gfx, mtx, (BKGeoList*)((s32)cmd + cmd->unk22));
            }
        }
    }
    else{
        D_80383C64 = f14;
        if(0.0f <= f14){
            if(cmd->unk22)
                func_80339124(gfx, mtx, (BKGeoList*)((s32)cmd + cmd->unk22));

            if(cmd->unk24)
                func_80339124(gfx, mtx, (BKGeoList*)((s32)cmd + cmd->unk24));
        }
        else{
            if(cmd->unk24)
                func_80339124(gfx, mtx, (BKGeoList*)((s32)cmd + cmd->unk24));

            if(cmd->unk22)
                func_80339124(gfx, mtx, (BKGeoList*)((s32)cmd + cmd->unk22));
        }
    }
}

//cmd10_???
void func_8033878C(Gfx **gfx, Mtx **mtx, void *arg2){
    GeoCmd10 *cmd = (GeoCmd10 *)arg2;

    switch(cmd->unk8){
        case 1:
            gSPDisplayList((*gfx)++, mipMapClampDL);
            break;
        case 2:
            gSPDisplayList((*gfx)++, mipMapWrapDL);
            break;
    }
}

//cmd2_BONE
void func_803387F8(Gfx **gfx, Mtx **mtx, void *arg2){
    GeoCmd2 *cmd = (GeoCmd2 *)arg2;

    if(D_8038371C){
        func_802519C8(&D_80383BF8, func_802EA110(D_8038371C, cmd->unk9));
        if(D_80370990){
            mlMtxApply(*mtx);
            gSPMatrix((*gfx)++, (*mtx)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        }
    }
    if(cmd->unk8){
        func_80339124(gfx, mtx, (BKGeoList*)((u8*)cmd + cmd->unk8));
    }
    if(D_8038371C){
        mlMtxPop();
        if(D_80370990){
            gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);
        }
    }
}   

//cmd3_LOAD_DL
void func_80338904(Gfx **gfx, Mtx **mtx, void *arg2){
    GeoCmd3 *cmd = (GeoCmd3 *)arg2;
    Gfx *vptr;

    if(D_80370990){
        vptr = &modelRenderDisplayList->list[cmd->unk8];
        gSPDisplayList((*gfx)++, osVirtualToPhysical(vptr));
    }
}

//Cmd5_SKINNING
void func_80338970(Gfx **gfx, Mtx **mtx, void *arg2){
    GeoCmd5 *cmd = (GeoCmd5 *)arg2;
    int i;

    if(D_80370990){
        gSPDisplayList((*gfx)++, osVirtualToPhysical(modelRenderDisplayList->list + cmd->unk8[0]));
    }

    if(D_80370990){
        for(i = 1; cmd->unk8[i]; i++){
            mlMtxApply(*mtx);
            gSPMatrix((*gfx)++, (*mtx)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList((*gfx)++, osVirtualToPhysical(modelRenderDisplayList->list + cmd->unk8[i]));
        }
    }
}

//Cmd6_???
void func_80338AC4(Gfx **gfx, Mtx **mtx, void *arg2){
    GeoCmd6 *cmd = (GeoCmd6 *)arg2;
    func_80339124(gfx, mtx, (BKGeoList*)((s32)cmd + cmd->unk8));
}

//Cmd7_LOAD_DL???
void func_80338AE8(Gfx **gfx, Mtx **mtx, void *arg2){
    if(D_80370990){
        gSPDisplayList((*gfx)++, osVirtualToPhysical(modelRenderDisplayList->list + ((GeoCmd7*)arg2)->unkA));
    }
}

//Cmd8_LOD
void func_80338B50(Gfx **gfx, Mtx **mtx, void *arg2){
    GeoCmd8 *cmd = (GeoCmd8 *)arg2;
    f32 dist;
    
    if(cmd->subgeo_offset_1C){
        func_8025235C(D_80383C98, cmd->unk10);
        dist = gu_sqrtf(D_80383C98[0]*D_80383C98[0] + D_80383C98[1]*D_80383C98[1] + D_80383C98[2]*D_80383C98[2]);
        if(cmd->min_C < dist && dist <= cmd->max_8){
            func_80339124(gfx, mtx, (BKGeoList*)((s32)cmd + cmd->subgeo_offset_1C));
        }
    }
}

//CmdA_REFERENCE_POINT
void func_80338BFC(Gfx **gfx, Mtx **mtx, void *arg2){
    GeoCmdA *cmd = (GeoCmdA *)arg2;
    f32 sp20[3];

    if(D_80383650){
        if(D_8038371C){
            func_802519C8(&D_80383BF8, func_802EA110(D_8038371C, cmd->unkA));
            func_8025235C(sp20, cmd->unkC);
            mlMtxPop();
        }
        else{
            func_8025235C(sp20, cmd->unkC);
        }
        sp20[0] += modelRenderCameraPosition[0];
        sp20[1] += modelRenderCameraPosition[1];
        sp20[2] += modelRenderCameraPosition[2];
        func_8034A308(D_80383650, cmd->unk8, sp20);
    }
}

//CmdC_SELECTOR
void func_80338CD0(Gfx **gfx, Mtx **mtx, void *arg2){
    GeoCmdC *cmd = (GeoCmdC *) arg2;
    s32 sub_cmd;
    s32 indx;
    s32 s2;
    s32 s1;
    s32 *s0;
    
    indx = D_80383658[cmd->unkA];

    if (cmd->unkA == 0)
        return;

    if (indx == 0)
        return;
    
    if (0 < indx) {
        if (indx <= cmd->unk8) {
            s0 = cmd->unkC;
            sub_cmd = cmd;
            sub_cmd += *(s32*)(s0 + (indx - 1));
            func_80339124(gfx, mtx, sub_cmd);
        }
    } else {
        s1 = indx * (-1);
        s0 = cmd->unkC;
        for (s2 = 0; s2 < cmd->unk8; s2++) {
            if (s1 & 1)
            {
                sub_cmd = cmd;
                sub_cmd += s0[0];
                func_80339124(gfx, mtx, sub_cmd);
            }
            s1 >>= 1;
            s0++;
        }
    }
}

//CmdD_DRAW_DISTANCE
void func_80338DCC(Gfx ** gfx, Mtx ** mtx, void *arg2){
    f32 sp2C[3];
    f32 sp20[3];
    GeoCmdD * cmd = (GeoCmdD *)arg2;
    if(cmd->unk14){
        sp2C[0] = (f32)cmd->unk8[0] * modelRenderScale;
        sp2C[1] = (f32)cmd->unk8[1] * modelRenderScale;
        sp2C[2] = (f32)cmd->unk8[2] * modelRenderScale;

        sp20[0] = (f32)cmd->unkE[0] * modelRenderScale;
        sp20[1] = (f32)cmd->unkE[1] * modelRenderScale;
        sp20[2] = (f32)cmd->unkE[2] * modelRenderScale;
        if(func_8024D374(sp2C, sp20)){
            func_80339124(gfx, mtx, (BKGeoList*)((s32)cmd + cmd->unk14));
        }
    }
}

//cmdE_???
void func_80338EB8(Gfx ** gfx, Mtx ** mtx, void *arg2){
    f32 sp34[3];
    f32 sp30;
    GeoCmdE * cmd = (GeoCmdE *)arg2;

    if(cmd->unk12 == -1){
        sp34[0] = (f32)cmd->unk8[0] * modelRenderScale;
        sp34[1] = (f32)cmd->unk8[1] * modelRenderScale;
        sp34[2] = (f32)cmd->unk8[2] * modelRenderScale;
        sp30 = (f32)cmd->unkE*modelRenderScale;
        if(func_8024DB50(sp34, sp30) && cmd->unk10){
            func_80339124(gfx, mtx, (BKGeoList*)((s32)cmd + cmd->unk10));
        }
    }
    else{
        sp34[0] = (f32)cmd->unk8[0];
        sp34[1] = (f32)cmd->unk8[1];
        sp34[2] = (f32)cmd->unk8[2];

        sp30 = (f32)cmd->unkE*modelRenderScale;
        if(D_8038371C){
            func_802519C8(&D_80383BF8, func_802EA110(D_8038371C, cmd->unk12));
            func_8025235C(sp34, sp34);
            mlMtxPop();
        }
        else{
            func_8025235C(sp34, sp34);
        }

        sp34[0] += modelRenderCameraPosition[0];
        sp34[1] += modelRenderCameraPosition[1];
        sp34[2] += modelRenderCameraPosition[2];
        if(func_8024DB50(sp34, sp30) && cmd->unk10){
            func_80339124(gfx, mtx, (BKGeoList*)((s32)cmd + cmd->unk10));
        }

    }

}

//cmdF_??? (processes model_setup offset_0x20)
void func_8033909C(Gfx ** gfx, Mtx ** mtx, void *arg2){
    GeoCmdF *cmd = (GeoCmdF *)arg2;
    int tmp_v0 = func_802ED420(D_8038372C, cmd->unkC, cmd->unkA);
    if( (!tmp_v0 && (cmd->unkB & 1))
        || (tmp_v0 && (cmd->unkB & 2)) 
    ){
        if(cmd->unk8 != 0)
            func_80339124(gfx, mtx, (BKGeoList*)((s32)cmd + cmd->unk8));
    }

}

//render_GeoList
void func_80339124(Gfx ** gfx, Mtx ** mtx, BKGeoList *geo_list){
    do{
        D_80370994[geo_list->cmd_0](gfx, mtx, geo_list);
        if(geo_list->size_4 == 0)
            return;
        geo_list = (BKGeoList*)((s32)geo_list + geo_list->size_4);
    }while(1);
}

BKModelBin *modelRender_draw(Gfx **gfx, Mtx **mtx, f32 position[3], f32 rotation[3], f32 scale, f32*arg5, BKModelBin* model_bin){
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
    
    if( (!model_bin && !D_803837C8.model_id)
        || (model_bin && D_803837C8.model_id)
    ){
        modelRender_reset();
        return 0;
    }

    D_80370990 = 0;
    viewport_getPosition(modelRenderCameraPosition);
    viewport_getRotation(modelRenderCameraRotation);
    if(D_80383758.unk18){
        D_80383758.unk1C[0] = modelRenderCameraPosition[0];
        D_80383758.unk1C[1] = modelRenderCameraPosition[1];
        D_80383758.unk1C[2] = modelRenderCameraPosition[2];

        D_80383758.unk28[0] = modelRenderCameraRotation[0];\
        D_80383758.unk28[1] = modelRenderCameraRotation[1];\
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
        viewport_setPosition(modelRenderCameraPosition);
        viewport_setRotation(modelRenderCameraRotation);
        viewport_update();
        camera_focus[0] = object_position[0] - modelRenderCameraPosition[0];
        camera_focus[1] = object_position[1] - modelRenderCameraPosition[1];
        camera_focus[2] = object_position[2] - modelRenderCameraPosition[2];
    }

    if(model_bin){
        verts = modelRendervertexList ? modelRendervertexList : (BKVertexList *)((s32)model_bin + model_bin->vtx_list_offset_10);
        spD0 = verts->unk16;
        spD4 = verts->unk12;
    }
    else{
        spD0 = D_803837C8.unk8;
        spD4 = D_803837C8.unk4;
    }
    camera_focus_distance = gu_sqrtf(camera_focus[0]*camera_focus[0] + camera_focus[1]*camera_focus[1] + camera_focus[2]*camera_focus[2]);
    if( 4000.0f <= camera_focus_distance && spD4*scale*D_8038370C*50.0f < D_80383708){
        D_80383708 = spD4*scale*D_8038370C*50.0f;
    }

    if(D_80383708 <= camera_focus_distance){
        modelRender_reset();
        return 0;
    }

    D_80370990 = (D_80383704) ? func_8024DB50(object_position, spD0*scale) : 1;
    if(D_80370990 == 0){
        modelRender_reset();
        return 0;
    }

    if(modelRenderCallback.pre_method != NULL){
        modelRenderCallback.pre_method(modelRenderCallback.pre_arg);
    }
    func_80349AD0();
    if(model_bin == NULL){
        model_bin = assetcache_get(D_803837C8.model_id);
    }
    modelRenderModelBin = model_bin;
    modelRenderDisplayList = modelRenderDisplayList ? modelRenderDisplayList : (BKGfxList *)((s32)modelRenderModelBin + modelRenderModelBin->gfx_list_offset_C),
    modelRenderTextureList = modelRenderTextureList ? modelRenderTextureList : (BKTextureList *)((s32)modelRenderModelBin + modelRenderModelBin->texture_list_offset_8),
    modelRendervertexList = modelRendervertexList ? modelRendervertexList : (BKVertexList *)((s32)modelRenderModelBin + modelRenderModelBin->vtx_list_offset_10),
    D_8038372C = (modelRenderModelBin->unk20 == NULL) ? NULL : (BKModelUnk20List *)((u8*)model_bin + model_bin->unk20);

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
    gSPSegment((*gfx)++, 0x01, osVirtualToPhysical(&modelRendervertexList->vtx_18));
    gSPSegment((*gfx)++, 0x02, osVirtualToPhysical(&modelRenderTextureList->tex_8[modelRenderTextureList->cnt_4]));

    if(D_80383724){
        int i_segment;
        s32 texture_offset;
        
        for(i_segment = 0; i_segment < 4; i_segment++){
            if(func_80349BB0(D_80383724, i_segment, &texture_offset))
                gSPSegment((*gfx)++, 15 - i_segment, osVirtualToPhysical((u8*)&modelRenderTextureList->tex_8[modelRenderTextureList->cnt_4] + texture_offset));
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

    if(modelRenderModelBin->geo_typ_A & 2){ //trilinear mipmapping
        gSPDisplayList((*gfx)++, mipMapWrapDL);
    }

    if(modelRenderModelBin->geo_typ_A & 4){ //env mapping
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

    if(D_8038371C && !modelRenderModelBin->animation_list_offset_18){
        D_8038371C = 0;
    }
    else if(D_8038371C == 0 && modelRenderModelBin->animation_list_offset_18){
        if(D_80383700 == 0){
            func_802EA060(&D_80383730, (u8*)model_bin + model_bin->animation_list_offset_18);
        }
        else{
            func_802EA1A8(&D_80383730, (u8*)model_bin + model_bin->animation_list_offset_18, D_80383700);
        }
        D_8038371C = D_80383730;
    }

    if(D_8038372C){
        func_802ED52C(D_8038372C, modelRenderCameraPosition, scale);
    }

    if(model_bin->unk28 != NULL && D_8038371C != NULL){
        func_802E6BD0((s32)modelRenderModelBin + modelRenderModelBin->unk28, modelRendervertexList, D_8038371C);
    }

    mlMtxIdent();
    if(D_80383758.unk18){
        func_80252AF0(D_80383758.unk1C, object_position, rotation, scale, arg5);
    }
    else{
        func_80252AF0(modelRenderCameraPosition, object_position, rotation, scale, arg5);
    }

    if(D_803837B0.unk0){
        mlMtxRotate(D_803837B0.unk4[0], D_803837B0.unk4[1], D_803837B0.unk4[2]);
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

    func_80339124(gfx, mtx, (BKGeoList *)((u8 *)model_bin + model_bin->geo_list_offset_4));
    gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);

    if(modelRenderCallback.post_method != NULL){
        modelRenderCallback.post_method(modelRenderCallback.post_arg);
    }

    if(D_803837C8.model_id){
        func_8033BD4C(model_bin); //assetCache_free
    }

    modelRender_reset();
    return model_bin;
}

BKModelUnk28List *func_8033A048(BKModelBin *arg0){
    if(arg0->unk28 == 0)
        return NULL;
    return (BKModelUnk28List *)((s32)arg0 + arg0->unk28);
}

s32 func_8033A064(void){
    return D_80383700;
}

s32 func_8033A070(BKModelBin *arg0){
    return arg0->geo_typ_A;
}

BKGfxList *func_8033A078(BKModelBin *arg0){
    return (BKGfxList *)((s32)arg0 + arg0->gfx_list_offset_C);
}

BKCollisionList *func_8033A084(BKModelBin *arg0){
    if(arg0 == NULL)
        return NULL;
    
    if(arg0->collision_list_offset_1C == 0)
        return NULL;

    return (BKCollisionList *)((s32)arg0 + arg0->collision_list_offset_1C);
}

BKEffectsList *func_8033A0B0(BKModelBin *arg0){
    if(arg0->effects_list_setup_24 == 0)
        return NULL;

    return (BKEffectsList *)((s32)arg0 + arg0->effects_list_setup_24);
}

f32 func_8033A0CC(UNK_TYPE(void *) arg0){
    return *(f32 *)((s32)arg0 + 0x34);
}

BKAnimationList *model_getAnimationList(BKModelBin *arg0){
    if(arg0->animation_list_offset_18 == 0)
        return NULL;

    return (BKAnimationList *)((s32)arg0 + arg0->animation_list_offset_18);
}

s32 func_8033A0F0(s32 arg0){
    return D_80383658[arg0];
}

BKTextureList *model_getTextureList(BKModelBin *arg0){
    return (BKTextureList *)((s32)arg0 + arg0->texture_list_offset_8);
}

void *func_8033A110(BKModelBin *arg0){
    if(arg0->unk2C == 0)
        return NULL;
    return (void*)((s32)arg0 + arg0->unk2C);
}

BKModelUnk14List *func_8033A12C(BKModelBin *this){
    if(this->unk14 == 0)
        return 0;
    return (BKModelUnk14List *)((s32)this + this->unk14);
}

BKVertexList *func_8033A148(BKModelBin *arg0){
    return (BKVertexList *)((s32)arg0 + arg0->vtx_list_offset_10);
}

BKModelUnk20List *func_8033A154(BKModelBin *arg0){
    return (arg0->unk20 == 0) ? NULL : (BKModelUnk20List *)((s32)arg0 + arg0->unk20);
}

s32 func_8033A170(void){
    return D_80370990;
}

void func_8033A17C(void){
    func_802EA134(D_80383730);
    D_80383730 = NULL;
}

void func_8033A1A4(void){
    modelRender_reset();
    D_80383758.unk18 = 0;
    D_803837E0.cur_lookat = D_803837E0.lookat_buffer;
    D_803837E0.lookat_buffer_end = D_803837E0.cur_lookat + ARRAYLEN(D_803837E0.lookat_buffer);
    D_803837E0.eye_pos[0] = D_803837E0.eye_pos[1] = D_803837E0.eye_pos[2] = 0.0f;
    D_80383730 = func_802EA154();
}

void func_8033A1FC(void){
    s32 i;
    for(i = 0; i < 0x2A; i++){
        D_80383658[i] = 0;
    }
}

void func_8033A238(s32 arg0){
    D_80383700 = arg0;
}

f32 func_8033A244(f32 arg0){
    f32 out = D_80383708;
    D_80383708 = arg0;
    return out;
}

void func_8033A25C(bool arg0){
    D_80383704 = arg0 ? TRUE : FALSE;
}  

void func_8033A280(f32 arg0){
    D_8038370C = arg0;
}

void func_8033A28C(bool arg0){
    D_80383710 = arg0;
}

void func_8033A298(bool arg0){
    D_80383758.unk18 = arg0;
    if(arg0){
        viewport_getPosition(D_80383758.unk0);
        viewport_getRotation(D_80383758.unkC);
    }
}

/* moderRender_preDraw() sets a generic 1 argument function that will
 * be called immediately prior to the model being drawn
 */
void modelRender_preDraw(GenMethod_1 func, s32 arg){
    modelRenderCallback.pre_method = func;
    modelRenderCallback.pre_arg = arg;
}

/* moderRender_postDraw() sets a generic 1 argument function that will
 * be called immediately after to the model has been drawn
 */
void modelRender_postDraw(GenMethod_1 func, s32 arg){
    modelRenderCallback.post_method = func;
    modelRenderCallback.post_arg = arg;
}

void modelRender_setDisplayList(BKGfxList *gfx_list){
    modelRenderDisplayList = gfx_list;
}

void func_8033A308(f32 arg0[3]){
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

void func_8033A444(struct58s *arg0){
    D_8038371C = arg0;
}

void func_8033A450(struct5Bs *arg0){
    D_80383650 = arg0;
}

void func_8033A45C(s32 arg0, s32 arg1){
    D_80383658[arg0] = arg1;
}

void func_8033A470(s32 arg0, s32 arg1){
    D_80383658[arg0] = -arg1;
}

void modelRender_setTextureList(BKTextureList *textureList){
    modelRenderTextureList = textureList;
}

void func_8033A494(s32 arg0){
    D_80383724 = arg0;
}

void func_8033A4A0(enum asset_e modelId, f32 arg1, f32 arg2){
    D_803837C8.model_id = modelId;
    D_803837C8.unk4 = arg1;
    D_803837C8.unk8 = arg2;
}

void modelRender_setVertexList(BKVertexList *vertexList){
    modelRendervertexList = vertexList;
}

void modelRender_setDepthMode(enum model_render_depth_mode_e renderMode){
    modelRenderDepthMode = renderMode;
}

void modelRender_defrag(void){
    if(D_80383730 != NULL){
        D_80383730 = func_802EA374(D_80383730);
    }
}
