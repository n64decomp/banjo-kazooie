#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8 pad0[0x4];
    u32 unk4;
    u8 pad8[0x14];
}stuct5DBC0_1s;

typedef struct {
    stuct5DBC0_1s *unk0;
    u8 pad4[0x8];
    s32 unkC;
}stuct5DBC0s;

stuct5DBC0s * D_8037E900;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E4B50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E4C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E4C78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E4CF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E4D5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E4D8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E4E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E4F98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E502C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E5188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E51A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E533C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E57E0.s")

void func_802E5C98(Gfx **gdl){
    int i;

    gDPPipeSync((*gdl)++);
    gSPClearGeometryMode((*gdl)++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPTexture((*gdl)++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gSPSetGeometryMode((*gdl)++, G_TEXTURE_GEN_LINEAR);
    gDPSetCycleType((*gdl)++, G_CYC_1CYCLE);
    gDPPipelineMode((*gdl)++, G_PM_NPRIMITIVE);
    gDPSetTextureLOD((*gdl)++, G_TL_TILE);
    gDPSetTextureLUT((*gdl)++, G_TT_NONE);
    gDPSetTextureDetail((*gdl)++, G_TD_CLAMP);
    gDPSetTexturePersp((*gdl)++, G_TP_NONE);
    gDPSetTextureFilter((*gdl)++, G_TF_BILERP);
    gDPSetTextureConvert((*gdl)++, G_TC_FILT);
    gDPSetAlphaCompare((*gdl)++, G_AC_NONE);
    gDPSetRenderMode((*gdl)++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    for(i = 0; i < D_8037E900->unkC; i++){
        D_8037E900->unk0[i].unk4 -= 0x10;
        func_802E57E0(D_8037E900->unk0 + i, gdl);
        D_8037E900->unk0[i].unk4 += 0x10;
    }
    gDPSetTexturePersp((*gdl)++, G_TP_PERSP);
}

void func_802E5F10(Gfx **gdl){
    func_802E5C98(gdl);
    func_802E5188();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E5F38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E5F68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E5F88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E5FE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E60D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6270.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E632C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E635C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E639C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E63D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E65E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E66F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E67AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E67C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E67E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6BD0.s")
