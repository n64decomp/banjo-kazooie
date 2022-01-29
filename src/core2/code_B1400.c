#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "animation.h"

extern void func_8024128C(Mtx *, s32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_802ED52C(s32, f32[3], f32);
extern void func_80252AF0(f32[3], f32[3], f32[3], f32, f32[3]);
extern void mlMtxRotate(f32, f32, f32);
extern void func_8024C5CC(f32[3]);
extern void func_8024C764(f32[3]);
extern void func_8024CD88(f32[3]);
extern void func_8024CE18(f32[3]);
extern void func_8024CFD4(void);
extern void func_8033BD4C(BKModelBin *);
extern s32 func_8024DB50(f32[3], f32);
extern void func_80251788(f32, f32, f32);
extern void mlMtxScale(f32);
extern void mlMtxApply(Mtx* mtx);

typedef struct{
    s32 env_r;
    s32 env_g;
    s32 env_b;
    s32 unkC;
    s32 pri_r;
    s32 pri_g;
    s32 pri_b;
    s32 unk1C;
} Struct_Core2_B1400_0;

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
}GeoCmd9;

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
    f32 unkC[3];
}GeoCmdF;

typedef struct {
    s32 cmd_0;
    s32 size_4;
    s32 unk8;
}GeoCmd10;

void func_80338390(void);
void func_803384A8(Gfx **, Mtx **, void *);
void func_803385BC(Gfx **, Mtx **, void *);
void func_803387F8(Gfx **, Mtx **, void *);
void func_80338904(Gfx **, Mtx **, void *);
void func_80338498(Gfx **, Mtx **, void *);
void func_80338970(Gfx **, Mtx **, void *);
void func_80338AC4(Gfx **, Mtx **, void *);
void func_80338AE8(Gfx **, Mtx **, GeoCmd7 *cmd);
void func_80338B50(Gfx **, Mtx **, void *);
void func_80338498(Gfx **, Mtx **, void *);
void func_80338BFC(Gfx **, Mtx **, void *);
void func_80338498(Gfx **, Mtx **, void *);
void func_80338CD0(Gfx **, Mtx **, void *);
void func_80338DCC(Gfx **, Mtx **, void *);
void func_80338EB8(Gfx **, Mtx **, void *);
void func_8033909C(Gfx **, Mtx **, void *);
void func_8033878C(Gfx **, Mtx **, void *);

void func_80339124(Gfx **, Mtx **, BKGeoList *);



extern Gfx D_80370340[] = 
{
    gsDPPipeSync(),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x80),
    gsSPEndDisplayList()
};

extern Gfx D_80370368[] =
{
    gsDPPipeSync(),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0x00),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x80),
    gsSPEndDisplayList()
};

extern Gfx D_80370398[] = 
{
    gsDPPipeSync(),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x80),
    gsSPEndDisplayList()
};

extern Gfx D_803703C8[] =
{
    gsDPPipeSync(),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x80),
    gsSPEndDisplayList()
};

extern Gfx D_803703F0[] = 
{
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsSPEndDisplayList()
};

// 000E 9470: B9 00 03 1D 0C 19 20 48  B8 00 00 00 00 00 00 00  ...... H ........  
// 000E 9480: B9 00 03 1D 0C 18 42 40  B8 00 00 00 00 00 00 00  ......B@ ........  
// 000E 9490: B9 00 03 1D 0C 18 41 C8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 94A0: B9 00 03 1D 0C 18 42 40  B8 00 00 00 00 00 00 00  ......B@ ........  
// 000E 94B0: B9 00 03 1D 0C 18 41 C8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 94C0: B9 00 03 1D 0F 0A 40 00  B8 00 00 00 00 00 00 00  ......@. ........  
// 000E 94D0: B9 00 03 1D 0C 19 20 48  B8 00 00 00 00 00 00 00  ...... H ........  
// 000E 94E0: B9 00 03 1D 0C 18 42 40  B8 00 00 00 00 00 00 00  ......B@ ........  
// 000E 94F0: B9 00 03 1D 0C 18 41 C8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 9500: B9 00 03 1D 0C 18 42 40  B8 00 00 00 00 00 00 00  ......B@ ........  
// 000E 9510: B9 00 03 1D 0C 18 41 C8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 9520: B9 00 03 1D 0C 18 43 C8  B8 00 00 00 00 00 00 00  ......C. ........  


extern Gfx D_803704C0[] = {
    gsDPSetRenderMode(Z_CMP | Z_UPD | CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | G_RM_PASS, Z_CMP | Z_UPD | CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)),
    gsSPEndDisplayList()
};
// 000E 9540: B9 00 03 1D 0C 19 20 78  B8 00 00 00 00 00 00 00  ...... x ........  
// 000E 9550: B9 00 03 1D 0C 18 42 70  B8 00 00 00 00 00 00 00  ......Bp ........  
// 000E 9560: B9 00 03 1D 0C 18 41 F8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 9570: B9 00 03 1D 0C 18 42 70  B8 00 00 00 00 00 00 00  ......Bp ........  
// 000E 9580: B9 00 03 1D 0C 18 41 F8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 9590: B9 00 03 1D 0F 0A 40 10  B8 00 00 00 00 00 00 00  ......@. ........  
// 000E 95A0: B9 00 03 1D 0C 19 20 58  B8 00 00 00 00 00 00 00  ...... X ........  
// 000E 95B0: B9 00 03 1D 0C 18 42 50  B8 00 00 00 00 00 00 00  ......BP ........  
// 000E 95C0: B9 00 03 1D 0C 18 41 D8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 95D0: B9 00 03 1D 0C 18 42 50  B8 00 00 00 00 00 00 00  ......BP ........  
// 000E 95E0: B9 00 03 1D 0C 18 41 D8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 95F0: B9 00 03 1D 0C 18 43 D8  B8 00 00 00 00 00 00 00  ......C. ........  


extern Gfx D_80370590[] =
{
    gsDPSetRenderMode(Z_CMP | CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | G_RM_PASS, Z_CMP | CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)),
    gsSPEndDisplayList()
};

// 000E 9610: B9 00 03 1D 0C 19 20 58  B8 00 00 00 00 00 00 00  ...... X ........  
// 000E 9620: B9 00 03 1D 0C 18 42 50  B8 00 00 00 00 00 00 00  ......BP ........  
// 000E 9630: B9 00 03 1D 0C 18 41 D8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 9640: B9 00 03 1D 0C 18 42 50  B8 00 00 00 00 00 00 00  ......BP ........  
// 000E 9650: B9 00 03 1D 0C 18 41 D8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 9660: B9 00 03 1D 0F 0A 40 10  B8 00 00 00 00 00 00 00  ......@. ........  
// 000E 9670: B9 00 03 1D 0C 19 20 58  B8 00 00 00 00 00 00 00  ...... X ........  


extern Gfx D_80370600[] =
{
    gsDPSetRenderMode(AA_EN | Z_CMP | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | G_RM_PASS, AA_EN | Z_CMP | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsSPEndDisplayList()
};

// 000E 9680: B9 00 03 1D 0C 18 42 50  B8 00 00 00 00 00 00 00  ......BP ........  
// 000E 9690: B9 00 03 1D 0C 18 41 D8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 96A0: B9 00 03 1D 0C 18 42 50  B8 00 00 00 00 00 00 00  ......BP ........  
// 000E 96B0: B9 00 03 1D 0C 18 41 D8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 96C0: B9 00 03 1D 0C 18 43 D8  B8 00 00 00 00 00 00 00  ......C. ........  

extern Gfx D_80370660[];
// B9 00 03 1D 0C 18 42 40  B8 00 00 00 00 00 00 00  ......B@ ........  
// B9 00 03 1D 0C 18 41 C8  B8 00 00 00 00 00 00 00  ......A. ........  
// B9 00 03 1D 0C 18 42 40  B8 00 00 00 00 00 00 00  ......B@ ........  
// B9 00 03 1D 0C 18 41 C8  B8 00 00 00 00 00 00 00  ......A. ........  
// B9 00 03 1D 0C 18 42 40  B8 00 00 00 00 00 00 00  ......B@ ........  
// B9 00 03 1D 0C 18 41 C8  B8 00 00 00 00 00 00 00  ......A. ........  
// B9 00 03 1D 0C 18 42 40  B8 00 00 00 00 00 00 00  ......B@ ........  
// B9 00 03 1D 0C 18 41 C8  B8 00 00 00 00 00 00 00  ......A. ........  
// B9 00 03 1D 0C 18 42 40  B8 00 00 00 00 00 00 00  ......B@ ........  
// B9 00 03 1D 0C 18 41 C8  B8 00 00 00 00 00 00 00  ......A. ........  
// B9 00 03 1D 0C 18 42 40  B8 00 00 00 00 00 00 00  ......B@ ........  
// B9 00 03 1D 0C 18 41 C8  B8 00 00 00 00 00 00 00  ......A. ........  
// B9 00 03 1D 0C 18 43 C8  B8 00 00 00 00 00 00 00  ......C. ........  

extern u8 D_80370730;
// 000E 97A0: B9 00 03 1D 0C 18 42 70  B8 00 00 00 00 00 00 00  ......Bp ........  
// 000E 97B0: B9 00 03 1D 0C 18 41 F8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 97C0: B9 00 03 1D 0C 18 42 70  B8 00 00 00 00 00 00 00  ......Bp ........  
// 000E 97D0: B9 00 03 1D 0C 18 41 F8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 97E0: B9 00 03 1D 0C 18 42 70  B8 00 00 00 00 00 00 00  ......Bp ........  
// 000E 97F0: B9 00 03 1D 0C 18 41 F8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 9800: B9 00 03 1D 0C 18 42 50  B8 00 00 00 00 00 00 00  ......BP ........  
// 000E 9810: B9 00 03 1D 0C 18 41 D8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 9820: B9 00 03 1D 0C 18 42 50  B8 00 00 00 00 00 00 00  ......BP ........  
// 000E 9830: B9 00 03 1D 0C 18 41 D8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 9840: B9 00 03 1D 0C 18 42 50  B8 00 00 00 00 00 00 00  ......BP ........  
// 000E 9850: B9 00 03 1D 0C 18 41 D8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 9860: B9 00 03 1D 0C 18 43 D8  B8 00 00 00 00 00 00 00  ......C. ........  

extern u8 D_80370800;

// 000E 9870: B9 00 03 1D 0C 18 42 50  B8 00 00 00 00 00 00 00  ......BP ........  
// 000E 9880: B9 00 03 1D 0C 18 41 D8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 9890: B9 00 03 1D 0C 18 42 50  B8 00 00 00 00 00 00 00  ......BP ........  
// 000E 98A0: B9 00 03 1D 0C 18 41 D8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 98B0: B9 00 03 1D 0C 18 42 50  B8 00 00 00 00 00 00 00  ......BP ........  
// 000E 98C0: B9 00 03 1D 0C 18 41 D8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 98D0: B9 00 03 1D 0C 18 42 50  B8 00 00 00 00 00 00 00  ......BP ........  
// 000E 98E0: B9 00 03 1D 0C 18 41 D8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 98F0: B9 00 03 1D 0C 18 42 50  B8 00 00 00 00 00 00 00  ......BP ........  
// 000E 9900: B9 00 03 1D 0C 18 41 D8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 9910: B9 00 03 1D 0C 18 42 50  B8 00 00 00 00 00 00 00  ......BP ........  
// 000E 9920: B9 00 03 1D 0C 18 41 D8  B8 00 00 00 00 00 00 00  ......A. ........  
// 000E 9930: B9 00 03 1D 0C 18 43 D8  B8 00 00 00 00 00 00 00  ......C. ........  

extern Gfx D_803708D0[] = 
{
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(2, 0, 0, 0x007C, 0x007C),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0100, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 1, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 1),
    gsDPSetTileSize(3, 0, 0, 0x003C, 0x003C),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0104, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 2, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 2),
    gsDPSetTileSize(4, 0, 0, 0x001C, 0x001C),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0106, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 3, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 3),
    gsDPSetTileSize(5, 0, 0, 0x000C, 0x000C),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0107, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 4, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 4),
    gsDPSetTileSize(6, 0, 0, 0x0004, 0x0004),
    gsSPEndDisplayList()
};

extern Gfx D_80370928[] =
{
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(2, 0, 0, 0x007C, 0x007C),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0100, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1),
    gsDPSetTileSize(3, 0, 0, 0x003C, 0x003C),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0104, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2),
    gsDPSetTileSize(4, 0, 0, 0x001C, 0x001C),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0106, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, 3, G_TX_NOMIRROR | G_TX_WRAP, 2, 3),
    gsDPSetTileSize(5, 0, 0, 0x000C, 0x000C),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0107, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 1, 4, G_TX_NOMIRROR | G_TX_WRAP, 1, 4),
    gsDPSetTileSize(6, 0, 0, 0x0004, 0x0004),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_LOD),
    gsSPEndDisplayList()
};

extern s32 D_80370990 = 0;

extern GeoListFunc D_80370994[] = {
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

/* .rodata */
extern f32 D_80378F40;
extern f32 D_80378F44;
extern f32 D_80378F48;
extern f32 D_80378F4C;

/* .bss */
extern s32 D_80383650;
extern s32 D_80383658[];
extern s32 D_80383700;
extern s32 D_80383704;
extern f32 D_80383708;
extern f32 D_8038370C;
extern s32 D_80383710;
extern s32 D_80383714;
extern BKGfxList *D_80383718;
extern struct58s *D_8038371C;
extern BKTextureList *D_80383720;
extern s32 D_80383724;
extern BKVertexList *D_80383728;
extern s32 D_8038372C;
extern struct58s *D_80383730;
extern f32 D_80383734;
extern Struct_Core2_B1400_0 D_80383738;
extern s32 D_80383754;
extern struct{
    f32 unk0[3];
    f32 unkC[3];
    s32 unk18;
    f32 unk1C[3];
    f32 unk28[3];
}D_80383758;
extern s32 D_80383770;
extern f32 D_80383774[3];
extern f32 D_80383780[3];
extern struct{
    void (* unk0)(Actor *);
    Actor *unk4;
    void (* unk8)(ActorMarker *);
    ActorMarker *unkC;
} D_80383790;
extern Struct_Core2_B1400_0 D_803837A0;
extern struct {
    s32 unk0;
    f32 unk4[3];
}D_803837B0;
extern u8 D_803837C0;
extern s32 D_803837C8; //model_asset_index
extern f32 D_803837CC;
extern f32 D_803837D0;
extern s32 D_803837D8;
extern struct {
    LookAt unk0;
    u8 pad20[0x3E0];
    LookAt *unk400;
    s32 unk404;
    f32 unk408;
    f32 unk40C;
    f32 unk410;
} D_803837E0;
extern Mtx D_80383BF8;
extern f32 D_80383C38[3];
extern f32 D_80383C48[3];
extern BKModelBin *D_80383C54;
extern f32 D_80383C58[3];
extern f32 D_80383C64;
extern f32 D_80383C68[3];
extern f32 D_80383C78[3];
extern f32 D_80383C88[3];
extern f32 D_80383C98[3];

void func_80338390(void){
    D_80383700 = 0;
    D_80383708 = D_80378F40;
    D_80383704 = 1;
    D_8038370C = 1.0f;
    D_80383710 = 0;
    D_80383714 = 2;
    D_80383650 = 0;
    D_80383718 = NULL;
    D_8038371C = NULL;
    D_80383720 = 0;
    D_80383724 = 0;
    D_80383728 = 0;
    D_8038372C = 0;
    D_80383790.unk0 = NULL;
    D_80383790.unk8 = NULL;
    D_803837B0.unk0 = 0;
    D_803837C8 = 0;
    D_803837D8 = 0;
    func_8033A45C(1,1);
    func_8033A45C(2,0);
    if(D_80383770){
        func_8024CD88(D_80383774);
        func_8024CE18(D_80383780);
        func_8024CFD4();
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
        mlMtxRotYaw(D_80383C48[1]);
        if(!cmd->unkA){
            mlMtxRotPitch(D_80383C48[0]);
        }
        mlMtxScale(D_80383734);
        mlMtxTranslate(-cmd->unkC[0], -cmd->unkC[1], -cmd->unkC[2]);
        mlMtxApply(*mtx);
        gSPMatrix((*gfx)++, (*mtx)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_80339124(gfx, mtx, (s32)cmd + cmd->unk8);
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
            func_80339124(gfx, mtx, (s32)cmd + tmp_v0);
        }
        else{
            D_80383C64 = f14;
            if(f14 < 0.0f){
                if(cmd->unk22)
                    func_80339124(gfx, mtx, (s32)cmd + cmd->unk22);
            }
        }
    }
    else{
        D_80383C64 = f14;
        if(0.0f <= f14){
            if(cmd->unk22)
                func_80339124(gfx, mtx, (s32)cmd + cmd->unk22);

            if(cmd->unk24)
                func_80339124(gfx, mtx, (s32)cmd + cmd->unk24);
        }
        else{
            if(cmd->unk24)
                func_80339124(gfx, mtx, (s32)cmd + cmd->unk24);

            if(cmd->unk22)
                func_80339124(gfx, mtx, (s32)cmd + cmd->unk22);
        }
    }
}

//cmd10_???
void func_8033878C(Gfx **gfx, Mtx **mtx, void *arg2){
    GeoCmd10 *cmd = (GeoCmd10 *)arg2;

    switch(cmd->unk8){
        case 1:
            gSPDisplayList((*gfx)++, &D_803708D0);
            break;
        case 2:
            gSPDisplayList((*gfx)++, &D_80370928);
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
    }//L80338890
    if(cmd->unk8){
        func_80339124(gfx, mtx, (u8*)cmd + cmd->unk8);
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
    s32 vptr;

    if(D_80370990){
        vptr = (s32)D_80383718  + sizeof(Gfx)*cmd->unk8 + sizeof(BKGfxList);
        gSPDisplayList((*gfx)++, osVirtualToPhysical(vptr));
    }
}

//Cmd5_SKINNING
void func_80338970(Gfx **gfx, Mtx **mtx, void *arg2){
    GeoCmd5 *cmd = (GeoCmd5 *)arg2;
    int i;

    if(D_80370990){
        gSPDisplayList((*gfx)++, osVirtualToPhysical((s32)D_80383718  + sizeof(Gfx)*cmd->unk8[0] + sizeof(BKGfxList)));
    }

    if(D_80370990){
        for(i = 1; cmd->unk8[i]; i++){
            mlMtxApply(*mtx);
            gSPMatrix((*gfx)++, (*mtx)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList((*gfx)++, osVirtualToPhysical((s32)D_80383718  + sizeof(Gfx)*cmd->unk8[i] + sizeof(BKGfxList)));
        }
    }
}

//Cmd6_???
void func_80338AC4(Gfx **gfx, Mtx **mtx, void *arg2){
    GeoCmd6 *cmd = (GeoCmd6 *)arg2;
    func_80339124(gfx, mtx, (s32)cmd + cmd->unk8);
}

//Cmd7_LOAD_DL???
void func_80338AE8(Gfx **gfx, Mtx **mtx, GeoCmd7 *cmd){
    if(D_80370990){
        gSPDisplayList((*gfx)++, osVirtualToPhysical((s32)D_80383718  + sizeof(Gfx)*cmd->unkA + sizeof(BKGfxList)));
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
            func_80339124(gfx, mtx, (s32)cmd + cmd->subgeo_offset_1C);
        }
    }
}

//CmdA_REFERENCE_POINT
void func_80338BFC(Gfx **gfx, Mtx **mtx, void *arg2){
    GeoCmd9 *cmd = (GeoCmd9 *)arg2;
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
        sp20[0] += D_80383C38[0];
        sp20[1] += D_80383C38[1];
        sp20[2] += D_80383C38[2];
        func_8034A308(D_80383650, cmd->unk8, sp20);
    }
}

//CmdC_SELECTOR
#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_80338CD0.s")
#else
void func_80338CD0(Gfx **gfx, Mtx **mtx, void *arg2){
    GeoCmdC *cmd = (GeoCmdC *)arg2;
    s32 tmp_v0;
    s32 indx;
    s32 s2;
    s32 s1;
    s32* s0;
    
    tmp_v0 = cmd->unkA;
    indx = D_80383658[tmp_v0];
    if(tmp_v0){
        if(indx == 0){
            
        }else if(indx > 0){
            if(cmd->unk8 >= indx){
                func_80339124(gfx, mtx, (s32)cmd + cmd->unkC[--indx]);
            }
            
        }else{//L80338D5C
            s1 = -indx;
            s0 = cmd->unkC;
            for(s2 = 0; s2 < cmd->unk8; s2++){//L80338D6C
                if(s1 & 1){
                    func_80339124(gfx, mtx, (s32)cmd + *s0);
                }
                s1 >>= 1;
                s0++;
            }
        }
    }//L80338DA8
}
#endif

//CmdD_DRAW_DISTANCE
void func_80338DCC(Gfx ** gfx, Mtx ** mtx, void *arg2){
    f32 sp2C[3];
    f32 sp20[3];
    GeoCmdD * cmd = (GeoCmdD *)arg2;
    if(cmd->unk14){
        sp2C[0] = (f32)cmd->unk8[0] * D_80383734;
        sp2C[1] = (f32)cmd->unk8[1] * D_80383734;
        sp2C[2] = (f32)cmd->unk8[2] * D_80383734;

        sp20[0] = (f32)cmd->unkE[0] * D_80383734;
        sp20[1] = (f32)cmd->unkE[1] * D_80383734;
        sp20[2] = (f32)cmd->unkE[2] * D_80383734;
        if(func_8024D374(sp2C, sp20)){
            func_80339124(gfx, mtx, (s32)cmd + cmd->unk14);
        }
    }
}

//cmdE_???
void func_80338EB8(Gfx ** gfx, Mtx ** mtx, void *arg2){
    f32 sp34[3];
    f32 sp30;
    GeoCmdE * cmd = (GeoCmdE *)arg2;

    if(cmd->unk12 == -1){
        sp34[0] = (f32)cmd->unk8[0] * D_80383734;
        sp34[1] = (f32)cmd->unk8[1] * D_80383734;
        sp34[2] = (f32)cmd->unk8[2] * D_80383734;
        sp30 = (f32)cmd->unkE*D_80383734;
        if(func_8024DB50(sp34, sp30) && cmd->unk10){
            func_80339124(gfx, mtx, (s32)cmd + cmd->unk10);
        }
    }
    else{
        sp34[0] = (f32)cmd->unk8[0];
        sp34[1] = (f32)cmd->unk8[1];
        sp34[2] = (f32)cmd->unk8[2];

        sp30 = (f32)cmd->unkE*D_80383734;
        if(D_8038371C){
            func_802519C8(&D_80383BF8, func_802EA110(D_8038371C, cmd->unk12));
            func_8025235C(sp34, sp34);
            mlMtxPop();
        }
        else{
            func_8025235C(sp34, sp34);
        }

        sp34[0] += D_80383C38[0];
        sp34[1] += D_80383C38[1];
        sp34[2] += D_80383C38[2];
        if(func_8024DB50(sp34, sp30) && cmd->unk10){
            func_80339124(gfx, mtx, (s32)cmd + cmd->unk10);
        }

    }//L8033908C

}

//cmdF_??? (processes model_setup offset_0x20)
void func_8033909C(Gfx ** gfx, Mtx ** mtx, void *arg2){
    GeoCmdF *cmd = (GeoCmdF *)arg2;
    int tmp_v0 = func_802ED420(D_8038372C, cmd->unkC, cmd->unkA);
    if( (!tmp_v0 && (cmd->unkB & 1))
        || (tmp_v0 && (cmd->unkB & 2)) 
    ){
        if(cmd->unk8 != 0)
            func_80339124(gfx, mtx, (s32)cmd + cmd->unk8);
    }

}

//render_GeoList
void func_80339124(Gfx ** gfx, Mtx ** mtx, BKGeoList *geo_list){
    do{
        D_80370994[geo_list->cmd_0](gfx, mtx, geo_list);
        if(geo_list->size_4 == 0)
            return;
        geo_list = ((s32)geo_list + geo_list->size_4);
    }while(1);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_803391A4.s")
#else
int func_803391A4(Gfx **gfx, Mtx **mtx, f32 arg2[3], f32 arg3[3], f32 arg4, f32*arg5, BKModelBin* model_bin){
    f32 spF4[3];
    f32 spF0;
    f32 padEC;
    f32 spE0[3];
    s32 spDC;
    s32 spD8;
    f32 spD4;
    f32 spD0;
    BKVertexList *tmp_v1;
    f32 tmp_f0;
    s32 tmp_v1_1;
    s32 alpha; 
    f32 padB8;
    int i; //spB4
    s32 spB0;
    
    if( (!model_bin && !D_803837C8)
        || (model_bin && D_803837C8)
    ){
        func_80338390();
        return 0;
    }

    D_80370990 = 0;
    func_8024C5CC(D_80383C38);
    func_8024C764(D_80383C48);
    if(D_80383758.unk18){
        D_80383758.unk1C[0] = D_80383C38[0];
        D_80383758.unk1C[1] = D_80383C38[1];
        D_80383758.unk1C[2] = D_80383C38[2];

        D_80383758.unk28[0] = D_80383C48[0];\
        D_80383758.unk28[1] = D_80383C48[1];\
        D_80383758.unk28[2] = D_80383C48[2];
    }//L80339274

    if(arg2){
        spE0[0] = arg2[0];
        spE0[1] = arg2[1];
        spE0[2] = arg2[2];
    }
    else{//L803392A8
        spE0[0] = spE0[1] = spE0[2] = 0.0f;
    }//L803392BC

    spF4[0] = spE0[0] - D_80383C38[0];
    spF4[1] = spE0[1] - D_80383C38[1];
    spF4[2] = spE0[2] - D_80383C38[2];

    if( ((spF4[0] < D_80378F44) || (D_80378F48 < spF4[0]))
        || ((spF4[1] < D_80378F44) || (D_80378F48 < spF4[1]))
        || ((spF4[2] < D_80378F44) || (D_80378F48 < spF4[2]))
    ){
        func_80338390();
        return 0;
    }

    if(D_80383758.unk18){
        D_80383C38[0] = D_80383758.unk0[0];
        D_80383C38[1] = D_80383758.unk0[1];
        D_80383C38[2] = D_80383758.unk0[2];

        D_80383C48[0] = D_80383758.unkC[0];\
        D_80383C48[1] = D_80383758.unkC[1];\
        D_80383C48[2] = D_80383758.unkC[2];
        func_8024CD88(D_80383C38);
        func_8024CE18(D_80383C48);
        func_8024CFD4();
        spF4[0] = spE0[0] - D_80383C38[0];
        spF4[1] = spE0[1] - D_80383C38[1];
        spF4[2] = spE0[2] - D_80383C38[2];
    }//L803393E8

    if(model_bin){
        tmp_v1 = D_80383728 ? D_80383728 : (BKVertexList *)((s32)model_bin + model_bin->vtx_list_offset_10);
        spD0 = tmp_v1->unk16;
        spD4 = tmp_v1->unk12;
    }
    else{//L80339434
        spD0 = D_803837D0;
        spD4 = D_803837CC;
    }//L80339440
    spF0 = gu_sqrtf(spF4[0]*spF4[0] + spF4[1]*spF4[1] + spF4[2]*spF4[2]);
    if( 4000.0f <= spF0 && spD4*arg4*D_8038370C*50.0f < D_80383708){
        D_80383708 = spD4*arg4*D_8038370C*50.0f;
    }//L803394C8

    if(D_80383708 <= spF0){
        func_80338390();
        return 0;
    }

    D_80370990 = (D_80383704) ? func_8024DB50(spE0, spD0*arg4) : 1;
    if(D_80370990 == 0){
        func_80338390();
        return 0;
    }

    if(D_80383790.unk0){
        D_80383790.unk0(D_80383790.unk4);
    }
    func_80349AD0();
    if(model_bin == NULL){
        model_bin = assetcache_get(D_803837C8);
    }
    D_80383C54 = model_bin;
    D_80383718 = D_80383718 ? D_80383718 : (BKGfxList *)((s32)D_80383C54 + D_80383C54->gfx_list_offset_C);
    D_80383720 = D_80383720 ? D_80383720 : (BKTextureList *)((s32)D_80383C54 + D_80383C54->texture_list_offset_8);
    D_80383728 = D_80383728 ? D_80383728 : (BKVertexList *)((s32)D_80383C54 + D_80383C54->vtx_list_offset_10);
    D_8038372C = !D_80383C54->unk20 ? NULL : (s32)model_bin + model_bin->unk20;
    if(D_80383710){
        tmp_f0 = D_80383708 - 500.0f;
        if(tmp_f0 < spF0){
            tmp_v1_1 = (s32)((1.0f - (spF0 - tmp_f0)/500.0f)*255.0f);
            if(D_80383714 == 0){
                D_80383738.unk1C = (D_80383738.unk1C * tmp_v1_1) / 0xff;
            }
            else if(D_80383714 == 1){//L803396DC
                D_803837A0.unkC = (D_803837A0.unkC * tmp_v1_1)/0xff;
            }
            else if(D_80383714 == 2){//L80339710
                func_8033A410(tmp_v1_1);
            }
            else if(D_80383714 == 3){
                D_803837C0 = (D_803837C0 *tmp_v1_1)/0xff;
            }
        }////L80339764
    }//L80339764

    gSPSegment((*gfx)++, 0x01, osVirtualToPhysical((void*)((s32)D_80383728 + sizeof(BKVertexList))));
    gSPSegment((*gfx)++, 0x02, osVirtualToPhysical((void*)((s32)D_80383720 + D_80383720->cnt_4*sizeof(BKTextureHeader) + sizeof(BKTextureList))));

    if(D_80383724){
        for(i = 0; i < 4; i++){
            if(func_80349BB0(D_80383724, i, &spB0))
                gSPSegment((*gfx)++, 15-i, osVirtualToPhysical((void*)((s32) D_80383720 + D_80383720->cnt_4*sizeof(BKTextureHeader) + spB0 + sizeof(BKTextureList))));
        }
    }

    if(D_803837D8){
        gSPSetGeometryMode((*gfx)++, G_ZBUFFER);
    }
    else{//L803398C0
        gSPClearGeometryMode((*gfx)++, G_ZBUFFER);
    }

    if(D_803837D8 == 0){
        spDC = &D_803703F0;
        spD8 = &D_80370660;
    }
    else if(D_803837D8 == 1){
        spDC = &D_803704C0;
        spD8 = &D_80370730;
    }
    else if(D_803837D8 == 2){
        spDC = &D_80370590;
        spD8 = &D_80370800;
    }//L80339948

    if(D_80383714 == 0){
        
        gSPDisplayList((*gfx)++, D_80370340);
         alpha = ((0xFF - D_80383738.unk1C)*D_80383738.unkC)/0xff + D_80383738.unk1C;
        gDPSetEnvColor((*gfx)++, D_80383738.env_r, D_80383738.env_g, D_80383738.env_b, alpha);
        gDPSetPrimColor((*gfx)++, 0, 0, D_80383738.pri_r, D_80383738.pri_g, D_80383738.pri_b, 0);
        if(alpha == 0xFF){
            gSPSegment((*gfx)++, 0x03, osVirtualToPhysical(spDC));
        }
        else{
            gSPSegment((*gfx)++, 0x03, osVirtualToPhysical(spD8));
        }
        //TODO
    }
    else if(D_80383714 == 1){//L80339AC0
        gSPDisplayList((*gfx)++, D_80370368);
        gDPSetEnvColor((*gfx)++, D_803837A0.env_r, D_803837A0.env_g, D_803837A0.env_b, D_803837A0.unkC);
        if(D_803837A0.unkC == 0xFF){
            gSPSegment((*gfx)++, 0x03, osVirtualToPhysical(spDC));
        }
        else{
            gSPSegment((*gfx)++, 0x03, osVirtualToPhysical(spD8));
        }
    }
    else if(D_80383714 == 2){
        gSPDisplayList((*gfx)++, D_80370398);
        gSPSegment((*gfx)++, 0x03, osVirtualToPhysical(spDC));
    }
    else if(D_80383714 == 3){
        gSPDisplayList((*gfx)++, D_803703C8);
        gDPSetEnvColor((*gfx)++, 0xFF, 0xFF, 0xFF, D_803837C0);
        gSPSegment((*gfx)++, 0x03, osVirtualToPhysical(spDC));
    }//L80339C80

    if(D_80383C54->geo_typ_A & 2){ //trilinear mipmapping
        gSPDisplayList((*gfx)++, D_80370928);
    }//L80339CC8

    if(D_80383C54->geo_typ_A & 4){ //env mapping
        if(0.0f == spF4[2]){
            spF4[2] = D_80378F4C;
        }
        func_8024128C(*mtx, D_803837E0.unk400, D_803837E0.unk408, D_803837E0.unk40C, D_803837E0.unk410, spF4[0], spF4[1], spF4[2], 0.0f, 1.0f, 0.0f);
        gSPLookAt((*gfx)++, D_803837E0.unk400);
        osWritebackDCache(D_803837E0.unk400, sizeof(LookAt));
        D_803837E0.unk400++;
        if((s32)D_803837E0.unk400 == D_803837E0.unk404)
            D_803837E0.unk400 = &D_803837E0.unk0;
    }//L80339DBC

    if(D_8038371C && !D_80383C54->animation_list_offset_18){
        D_8038371C = 0;
    }
    else if(D_8038371C == 0 && D_80383C54->animation_list_offset_18){
        if(D_80383700 == 0){
            func_802EA060(&D_80383730, (s32)model_bin + model_bin->animation_list_offset_18);
        }
        else{//L80339E38
            func_802EA1A8(&D_80383730, (s32)model_bin + model_bin->animation_list_offset_18, D_80383700);
        }//L80339E48
        D_8038371C = D_80383730;
    }//L80339E58

    if(D_8038372C){
        func_802ED52C(D_8038372C, D_80383C38, arg4);
    }//L80339E74

    if(model_bin->unk28 && D_8038371C){
        func_802E6BD0((s32)D_80383C54 + D_80383C54->unk28, D_80383728);
    }//L80339EAC

    mlMtxIdent();
    if(D_80383770){
        func_80252AF0(&D_80383774, spE0, arg3, arg4, arg5);
    }
    else{
        func_80252AF0(D_80383C38, spE0, arg3, arg4, arg5);
    }//L80339F08

    if(D_803837B0.unk0){
        mlMtxRotate(D_803837B0.unk4[0], D_803837B0.unk4[1], D_803837B0.unk4[2]);
    }//L80339F2C

    func_802513B0(&D_80383BF8);
    mlMtxApply(*mtx);
    gSPMatrix((*gfx)++, (*mtx)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    D_80383734 = arg4;
    
    if(arg3){
        D_80383C58[0] = arg3[0];
        D_80383C58[1] = arg3[1];
        D_80383C58[2] = arg3[2];
    }
    else{
        D_80383C58[0] = D_80383C58[1] = D_80383C58[2] = 0.0f;
    }

    func_80339124(gfx, mtx, (s32)model_bin + model_bin->geo_list_offset_4);
    gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);

    if(D_80383790.unk8){
        D_80383790.unk8(D_80383790.unkC);
    }

    if(D_803837C8){
        func_8033BD4C(model_bin);
    }

    func_80338390();
    return model_bin;
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A048.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A0CC.s")

BKAnimationList *func_8033A0D4(BKModelBin *arg0){
    if(arg0->animation_list_offset_18 == 0)
        return NULL;

    return (BKAnimationList *)((s32)arg0 + arg0->animation_list_offset_18);
}

s32 func_8033A0F0(s32 arg0){
    return D_80383658[arg0];
}

BKTextureList *func_8033A104(BKModelBin *arg0){
    return (BKTextureList *)((s32)arg0 + arg0->texture_list_offset_8);
}

void *func_8033A110(BKModelBin *arg0){
    if(arg0->unk2C == 0)
        return NULL;
    return (s32)arg0 + arg0->unk2C;
}

BKModelUnk14List *func_8033A12C(BKModelBin *this){
    if(this->unk14 == 0)
        return 0;
    return (BKModelUnk14List *)((s32)this + this->unk14);
}

BKVertexList *func_8033A148(BKModelBin *arg0){
    return (BKVertexList *)((s32)arg0 + arg0->vtx_list_offset_10);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A154.s")

s32 func_8033A170(void){
    return D_80370990;
}

void func_8033A17C(void){
    func_802EA134(D_80383730);
    D_80383730 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A1A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A1FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A244.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A25C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A28C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A298.s")

void func_8033A2D4(void(*func)(Actor *), Actor* actor){
    D_80383790.unk0 = func;
    D_80383790.unk4 = actor;
}

void func_8033A2E8(void(*func)(ActorMarker *), ActorMarker* marker){
    D_80383790.unk8 = func;
    D_80383790.unkC = marker;
}

void func_8033A2FC(BKGfxList *gfx_list){
    D_80383718 = gfx_list;
}

void func_8033A308(f32 arg0[3]){
    D_803837B0.unk0 = TRUE;
    D_803837B0.unk4[0] = arg0[0];
    D_803837B0.unk4[1] = arg0[1];
    D_803837B0.unk4[2] = arg0[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A334.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A45C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A4A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A4C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A4CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A4D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A57C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A5B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A6B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A6F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A750.s")

void func_8033A8F0(Struct_B1400 **arg0, s32 arg1, f32 arg2[4]){
    func_80345250(*arg0 + arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A9A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B1400/func_8033A9E4.s")
