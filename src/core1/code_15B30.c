#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include <core1/viewport.h>

typedef struct {
    s32 unk0;
    s32 unk4;
    Gfx *unk8;
    Gfx *unkC;
    s32 unk10;
    s32 unk14;
}Struct_Core1_15B30;

extern u8 D_803A5D00[2][0x1ecc0];

/* .data */
Gfx *gGfxStack[2] = {NULL, NULL};
s32  framebuffer_width  = 292;
s32  framebuffer_height = 216;

/* .bss */
Mtx *gMtxStack[2];
Vtx *gVtxStack[2];
s32  gStackSelector;
s32  gTextureFilterPoint;
Struct_Core1_15B30 D_80283008[20];
s32 D_802831E8;
OSMesgQueue D_802831F0;
OSMesg D_80283208;
u16  gScissorBoxLeft;
u16  gScissorBoxRight;
u16  gScissorBoxTop;
u16  gScissorBoxBottom;
Gfx *D_80283214;

/* .h */
void scissorBox_setDefault(void);
void dummy_func_80254464(void);

/* .code */
void func_80253550(void){
    osRecvMesg(&D_802831F0, NULL, OS_MESG_BLOCK);
}

void func_8025357C(void){
    osSendMesg(&D_802831F0, NULL, OS_MESG_BLOCK);
}

void func_802535A8(Gfx **arg0, Gfx **arg1, UNK_TYPE(s32) arg2, UNK_TYPE(s32) arg3) {
    Struct_Core1_15B30 *sp1C;

    func_80253550();
    sp1C = &D_80283008[D_802831E8];
    D_802831E8 = (s32) (D_802831E8 + 1) % 20;
    func_8025357C();
    sp1C->unk0 = 0;
    sp1C->unk8 = arg0;
    sp1C->unkC = arg1;
    sp1C->unk10 = arg2;
    sp1C->unk14 = arg3;
    func_80246670(sp1C);
}


void func_80253640(Gfx ** gdl, void *arg1){
    D_80283214 = *gdl;
    gSPSegment((*gdl)++, 0x00, 0x00000000);
    gDPSetRenderMode((*gdl)++, G_RM_NOOP, G_RM_NOOP2);
    gSPClearGeometryMode((*gdl)++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gDPPipeSync((*gdl)++);
    gDPPipelineMode((*gdl)++, G_PM_NPRIMITIVE);
    gDPSetAlphaCompare((*gdl)++, G_AC_NONE);
    gDPSetColorDither((*gdl)++, G_CD_MAGICSQ);
    gDPSetScissor((*gdl)++, G_SC_NON_INTERLACE, gScissorBoxLeft, gScissorBoxRight, gScissorBoxTop, gScissorBoxBottom);
    func_80253208(gdl, 0, 0,  framebuffer_width, framebuffer_height, arg1);
    gDPSetColorImage((*gdl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, framebuffer_width, OS_K0_TO_PHYSICAL(arg1));
    gDPSetCycleType((*gdl)++, G_CYC_1CYCLE);
    gDPSetTextureConvert((*gdl)++, G_TC_FILT);
    gDPSetTextureDetail((*gdl)++, G_TD_CLAMP);
    if(gTextureFilterPoint){
        gDPSetTextureFilter((*gdl)++, G_TF_POINT);
    }else{
        gDPSetTextureFilter((*gdl)++, G_TF_BILERP);
    }
    gDPSetTextureLOD((*gdl)++, G_TL_TILE);
    gDPSetTextureLUT((*gdl)++, G_TT_NONE);
    gDPSetTexturePersp((*gdl)++, G_TP_PERSP);
    zBuffer_set(gdl);
}

void scissorBox_SetForGameMode(Gfx **gdl, s32 framebuffer_idx) {
    if(getGameMode() == GAME_MODE_8_BOTTLES_BONUS || getGameMode() == GAME_MODE_A_SNS_PICTURE)
    {
        scissorBox_setSmall();
        func_80253640(gdl, func_8030C704());
    }
    else{
        scissorBox_setDefault();
        func_80253640(gdl, D_803A5D00[framebuffer_idx]);
    }
}

void setupScissorBoxAndFramebuffer(Gfx **gfx, s32 framebuffer_address){
    gSPSegment((*gfx)++, 0x00, 0x00000000);
    gDPSetColorImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, framebuffer_width, OS_PHYSICAL_TO_K0(framebuffer_address));
    gSPClearGeometryMode((*gfx)++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPTexture((*gfx)++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gSPSetGeometryMode((*gfx)++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPSetCycleType((*gfx)++, G_CYC_1CYCLE);
    gDPPipelineMode((*gfx)++, G_PM_NPRIMITIVE);
    gDPSetCombineMode((*gfx)++, G_CC_SHADE, G_CC_SHADE);
    gDPSetAlphaCompare((*gfx)++, G_AC_NONE);
    gDPSetColorDither((*gfx)++, G_CD_DISABLE);
    gDPSetRenderMode((*gfx)++, G_RM_AA_ZB_XLU_LINE, G_RM_AA_ZB_XLU_LINE2);
    gSPClipRatio((*gfx)++, FRUSTRATIO_1);
    gDPSetScissor((*gfx)++, G_SC_NON_INTERLACE, gScissorBoxLeft, gScissorBoxRight, gScissorBoxTop, gScissorBoxBottom);
    gDPPipeSync((*gfx)++);
}

void setupDefaultScissorBoxAndFramebuffer(Gfx **gfx, s32 framebuffer_idx){
    scissorBox_setDefault();
    setupScissorBoxAndFramebuffer(gfx, D_803A5D00[framebuffer_idx]);
}

void func_80253DC0(Gfx **gfx){
    func_802476EC(gfx);
}

void finishFrame(Gfx **gdl) {
    gDPFullSync((*gdl)++);
    gSPEndDisplayList((*gdl)++);
}

void func_80253E14(Gfx *arg0, Gfx *arg1, s32 arg2){
    Struct_Core1_15B30 *sp1C;
    func_80253550();
    sp1C = D_80283008 + D_802831E8;
    D_802831E8 = (D_802831E8 + 1) % 0x14;
    func_8025357C();
    sp1C->unk0 = 1;
    sp1C->unk4 = arg2;
    sp1C->unk8 = arg0;
    sp1C->unkC = arg1;
    func_80246670((OSMesg) sp1C);
}

void func_80253EA4(Gfx *arg0, Gfx *arg1){
    func_80253E14(arg0, arg1, 0);
}

void func_80253EC4(Gfx *arg0, Gfx *arg1){
    func_80253E14(arg0, arg1, 0x40000000);
}

void func_80253EE4(Gfx **arg0, Gfx **arg1, s32 arg2) {
    Struct_Core1_15B30 *sp1C;

    func_80253550();
    sp1C = &D_80283008[D_802831E8];
    D_802831E8 = (s32) (D_802831E8 + 1) % 20;
    func_8025357C();
    sp1C->unk0 = 2;
    sp1C->unk4 = arg2;
    sp1C->unk8 = arg0;
    sp1C->unkC = arg1;
    func_80246670(sp1C);
}

void func_80253F74(Gfx **arg0, Gfx **arg1){
    func_80253EE4(arg0, arg1, 0);
}

void func_80253F94(Gfx **arg0, Gfx **arg1){
    func_80253EE4(arg0, arg1, 0x40000000);
}

void scissorBox_get(u32 *left, u32 *top, u32 *right, u32 *bottom){
   *left = gScissorBoxLeft;
   *top = gScissorBoxTop;
   *right = gScissorBoxRight;
   *bottom = gScissorBoxBottom;
}

void func_80253FE8(void){
    func_8024BFAC();
}

void func_80254008(void){
    func_80246670(3);
}

void func_80254028(void){
    D_802831E8 = 0;
    osCreateMesgQueue(&D_802831F0, &D_80283208, 1);
    osSendMesg(&D_802831F0, NULL, 1);
    func_80247560();
    scissorBox_setDefault();
}

void drawRectangle2D(Gfx **gfx, s32 x, s32 y, s32 w, s32 h, s32 r, s32 g, s32 b){
    gDPPipeSync((*gfx)++);
    gDPPipelineMode((*gfx)++, G_PM_NPRIMITIVE);
    gDPSetCycleType((*gfx)++, G_CYC_FILL);
    gDPSetFillColor((*gfx)++, GPACK_RGBA5551(r, g, b, 1) << 16 | GPACK_RGBA5551(r, g, b, 1));
    gDPSetRenderMode((*gfx)++, G_RM_NOOP, G_RM_NOOP2);
    gDPScisFillRectangle((*gfx)++,  x, y, x + w -1, y + h -1);
}

void graphicsCache_release(void){
    if(gGfxStack[0]){
        free(gGfxStack[0]);
        free(gGfxStack[1]);
        free(gMtxStack[0]);
        free(gMtxStack[1]);
        free(gVtxStack[0]);
        free(gVtxStack[1]);
        gGfxStack[0] = NULL;
    }
}

void graphicsCache_init(void){
    if(gGfxStack[0] == NULL){
        gGfxStack[0] = (Gfx *)malloc(29600); // 3700 dlist commands
        gGfxStack[1] = (Gfx *)malloc(29600);
        gMtxStack[0] = (Mtx *)malloc(44800); // 700 matrices
        gMtxStack[1] = (Mtx *)malloc(44800);
        gVtxStack[0] = (Vtx *)malloc(6880); // 430 vertices
        gVtxStack[1] = (Vtx *)malloc(6880);
        dummy_func_80254464();
    }
    gStackSelector = 0;
    gTextureFilterPoint = 0;
}

void scissorBox_set(s32 left, s32 top, s32 right, s32 bottom) {
    gScissorBoxLeft = left;
    gScissorBoxTop = top;
    gScissorBoxRight = right;
    gScissorBoxBottom = bottom;
    framebuffer_width = top - left;
    framebuffer_height = bottom - right;
    viewport_pushFramebufferExtendsToVpStack();
}


void scissorBox_setDefault(void){
    scissorBox_set(0, 292, 0, 216);
}

void func_80254374(s32 arg0) {
    Struct_Core1_15B30 *sp1C;

    func_80253550();
    func_8024C2A0(arg0);
    sp1C = &D_80283008[D_802831E8];
    D_802831E8 = (s32) (D_802831E8 + 1) % 20;
    func_8025357C();
    sp1C->unk0 = 7;
    func_80246670(sp1C);
}

void toggleTextureFilterPoint(void){
    u32 ret_val = gTextureFilterPoint;
    gTextureFilterPoint = ret_val < 1;
}

void getGraphicsStacks(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    gStackSelector = (1 - gStackSelector);
    *gfx = gGfxStack[gStackSelector];
    *mtx = gMtxStack[gStackSelector];
    *vtx = gVtxStack[gStackSelector];
}

void dummy_func_80254464(void){}
