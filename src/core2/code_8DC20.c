#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern s16 D_803A5D00[2][0xF660];

Gfx D_8036C630[] =
{
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineLERP(TEXEL0, 0, PRIMITIVE_ALPHA, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE_ALPHA, 0, 0, 0, 0, TEXEL0),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsDPSetColorDither(G_CD_DISABLE),
    gsSPEndDisplayList()
};

Gfx D_8036C690[] = 
{
    gsDPPipeSync(),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetColorDither(G_CD_MAGICSQ),
    gsSPEndDisplayList(),
};

/* .bss */
s32 D_803830A0;


/* .code */
void func_80314BB0(Gfx **gfx, Mtx **mtx, Vtx **vtx, void * frame_buffer_1, void *frame_buffer_2) {
    s32 x;
    s32 y;

    gSPDisplayList((*gfx)++, D_8036C630);
    gDPSetColorImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, framebuffer_width, OS_PHYSICAL_TO_K0(frame_buffer_1));
    for(y = 0;  y < framebuffer_height / 32 + 1; y++){
        for(x = 0; x < framebuffer_width / 32 + 1; x++){
            gDPLoadTextureTile((*gfx)++, osVirtualToPhysical(frame_buffer_2), G_IM_FMT_RGBA, G_IM_SIZ_16b, framebuffer_width, framebuffer_height,
                0x20*x, 0x20*y, 0x20*(x + 1) - 1, 0x20*(y + 1) - 1,
                NULL, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, 0, 0
            );
            gSPScisTextureRectangle((*gfx)++, (0x20*x)*4, (0x20*y)*4, 0x20*(x + 1)*4, (0x20*(y + 1)*4), 
                G_TX_RENDERTILE, (0x20*x)<<5, (0x20*y)<<5, 0x400, 0x400
            );
        }
    }
    gSPDisplayList((*gfx)++, D_8036C690);
    gDPSetColorImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, framebuffer_width, OS_PHYSICAL_TO_K0(D_803A5D00[func_8024BDA0()]));
}

void func_80315084(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    func_80335128(0);
    D_803830A0 = 2;
    func_80314BB0(gfx, mtx, vtx, func_80253540(), D_803A5D00[func_8024BDA0()]);
}

void func_80315110(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    if(!D_803830A0){
        if(map_get() != MAP_90_GL_BATTLEMENTS){
            func_803306C8(2);
            func_8032AD7C(2);
        }
    }
    else{
        D_803830A0--;
    }
    func_80314BB0(gfx, mtx, vtx, D_803A5D00[func_8024BDA0()], func_80253540());
}

void func_803151D0(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    func_80335128(1);
}
