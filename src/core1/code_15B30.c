#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_80283004;
extern u16 D_8028320C;
extern u16 D_8028320E;
extern u16 D_80283210;
extern u16 D_80283212;
extern Gfx *D_80283214;

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

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_802539AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253A58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253DC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253DE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253E14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253EC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253F94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253FB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80253FE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80254008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80254028.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80254084.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_802541E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_8025425C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_802542F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80254348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80254374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_802543EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15B30/func_80254404.s")


void func_80254464(void){}
