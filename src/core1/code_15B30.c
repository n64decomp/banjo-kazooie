#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void *D_80276580;
extern void *D_80276584;
extern void *D_80282FF0;
extern void *D_80282FF4;
extern void *D_80282FF8;
extern void *D_80282FFC;
extern s32 D_80283000;
extern s32 D_80283004;
extern s32 D_802831E8;
extern OSMesgQueue D_802831F0;
extern OSMesg D_80283208;
extern u16 D_8028320C;
extern u16 D_8028320E;
extern u16 D_80283210;
extern u16 D_80283212;
extern Gfx *D_80283214;

extern u8 D_803A5D00[2][0x1ecc0];

void func_80254348(void);
void func_80254464(void);

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_8025357C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_802535A8.s")

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
    func_80253208(gdl, 0, 0,  D_80276588, D_8027658C, arg1);
    gDPSetColorImage((*gdl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_80276588, OS_K0_TO_PHYSICAL(arg1));
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

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253A58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253DC0.s")

void func_80253DE0(Gfx **gdl) {
    gDPFullSync((*gdl)++);
    gSPEndDisplayList((*gdl)++);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253E14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253EC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253F94.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80254084.s")

void func_802541E8(void){
    if(D_80276580){
        free(D_80276580);
        free(D_80276584);
        free(D_80282FF0);
        free(D_80282FF4);
        free(D_80282FF8);
        free(D_80282FFC);
        D_80276580 = NULL;
    }
}

void func_8025425C(void){
    if(D_80276580 == NULL){
        D_80276580 = malloc(29600);
        D_80276584 = malloc(29600);
        D_80282FF0 = malloc(44800);
        D_80282FF4 = malloc(44800);
        D_80282FF8 = malloc(6880);
        D_80282FFC = malloc(6880);
        func_80254464();
    }
    D_80283000 = 0;
    D_80283004 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_802542F4.s")

void func_80254348(void){
    func_802542F4(0, 0x124, 0, 0xd8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80254374.s")

void func_802543EC(void){
    u32 ret_val = D_80283004;
    D_80283004 = ret_val < 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80254404.s")


void func_80254464(void){}
