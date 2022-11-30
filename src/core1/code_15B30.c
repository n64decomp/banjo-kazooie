#include <ultra64.h>
#include "functions.h"
#include "variables.h"

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
Gfx *D_80276580[2] = {NULL, NULL};
s32  framebuffer_width  = 292;
s32  framebuffer_height = 216;

/* .bss */
Mtx *D_80282FF0[2];
Vtx *D_80282FF8[2];
s32  D_80283000;
s32  D_80283004;
Struct_Core1_15B30 D_80283008[20];
s32 D_802831E8;
OSMesgQueue D_802831F0;
OSMesg D_80283208;
u16  D_8028320C;
u16  D_8028320E;
u16  D_80283210;
u16  D_80283212;
Gfx *D_80283214;

/* .h */
void func_80254348(void);
void func_80254464(void);

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
    gDPSetScissor((*gdl)++, G_SC_NON_INTERLACE, D_8028320C, D_8028320E, D_80283210, D_80283212);
    func_80253208(gdl, 0, 0,  framebuffer_width, framebuffer_height, arg1);
    gDPSetColorImage((*gdl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, framebuffer_width, OS_K0_TO_PHYSICAL(arg1));
    gDPSetCycleType((*gdl)++, G_CYC_1CYCLE);
    gDPSetTextureConvert((*gdl)++, G_TC_FILT);
    gDPSetTextureDetail((*gdl)++, G_TD_CLAMP);
    if(D_80283004){
        gDPSetTextureFilter((*gdl)++, G_TF_POINT);
    }else{
        gDPSetTextureFilter((*gdl)++, G_TF_BILERP);
    }
    gDPSetTextureLOD((*gdl)++, G_TL_TILE);
    gDPSetTextureLUT((*gdl)++, G_TT_NONE);
    gDPSetTexturePersp((*gdl)++, G_TP_PERSP);
    func_802534CC(gdl);
}

void func_802539AC(Gfx **gdl, s32 arg1){
    if(getGameMode() == GAME_MODE_8_BOTTLES_BONUS || getGameMode() == GAME_MODE_A_SNS_PICTURE)
    {
        func_8030C710();
        func_80253640(gdl, func_8030C704());
    }
    else{
        func_80254348();
        func_80253640(gdl, D_803A5D00[arg1]);
    }
}

void func_80253A58(Gfx **gfx, s32 arg1){
    gSPSegment((*gfx)++, 0x00, 0x00000000);
    gDPSetColorImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, framebuffer_width, OS_PHYSICAL_TO_K0(arg1));
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
    gDPSetScissor((*gfx)++, G_SC_NON_INTERLACE, D_8028320C, D_8028320E, D_80283210, D_80283212);
    gDPPipeSync((*gfx)++);
}

void func_80253D60(Gfx **gfx, s32 arg1){
    func_80254348();
    func_80253A58(gfx, D_803A5D00[arg1]);
}

void func_80253DC0(Gfx **gfx){
    func_802476EC(gfx);
}

void func_80253DE0(Gfx **gdl) {
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

void func_80253FB4(u32 *arg0, u32 *arg1, u32 *arg2, u32 *arg3){
   *arg0 = D_8028320C;
   *arg1 = D_80283210;
   *arg2 = D_8028320E;
   *arg3 = D_80283212;
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
    func_80254348();
}

void func_80254084(Gfx **gfx, s32 x, s32 y, s32 w, s32 h, s32 r, s32 g, s32 b){
    gDPPipeSync((*gfx)++);
    gDPPipelineMode((*gfx)++, G_PM_NPRIMITIVE);
    gDPSetCycleType((*gfx)++, G_CYC_FILL);
    gDPSetFillColor((*gfx)++, GPACK_RGBA5551(r, g, b, 1) << 16 | GPACK_RGBA5551(r, g, b, 1));
    gDPSetRenderMode((*gfx)++, G_RM_NOOP, G_RM_NOOP2);
    gDPScisFillRectangle((*gfx)++,  x, y, x + w -1, y + h -1);
}

void func_802541E8(void){
    if(D_80276580[0]){
        free(D_80276580[0]);
        free(D_80276580[1]);
        free(D_80282FF0[0]);
        free(D_80282FF0[1]);
        free(D_80282FF8[0]);
        free(D_80282FF8[1]);
        D_80276580[0] = NULL;
    }
}

void func_8025425C(void){
    if(D_80276580[0] == NULL){
        D_80276580[0] = (Gfx *)malloc(29600);
        D_80276580[1] = (Gfx *)malloc(29600);
        D_80282FF0[0] = (Mtx *)malloc(44800);
        D_80282FF0[1] = (Mtx *)malloc(44800);
        D_80282FF8[0] = (Vtx *)malloc(6880);
        D_80282FF8[1] = (Vtx *)malloc(6880);
        func_80254464();
    }
    D_80283000 = 0;
    D_80283004 = 0;
}

void func_802542F4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_8028320C = arg0;
    D_80283210 = arg1;
    D_8028320E = arg2;
    D_80283212 = arg3;
    framebuffer_width = arg1 - arg0;
    framebuffer_height = arg3 - arg2;
    func_8024CC5C();
}


void func_80254348(void){
    func_802542F4(0, 0x124, 0, 0xd8);
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

void func_802543EC(void){
    u32 ret_val = D_80283004;
    D_80283004 = ret_val < 1;
}

void func_80254404(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    D_80283000 = (1 - D_80283000);
    *gfx = D_80276580[D_80283000];
    *mtx = D_80282FF0[D_80283000];
    *vtx = D_80282FF8[D_80283000];
}

void func_80254464(void){}
