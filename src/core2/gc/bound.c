#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "gc/gcbound.h"

/* .data */
extern s32 D_803688E0 = 0; //_gcBoundAlpha
extern Gfx D_803688E8[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPPipelineMode(G_PM_NPRIMITIVE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetCombineLERP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetRenderMode(IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c1(G_BL_CLR_FOG, G_BL_A_FOG, G_BL_CLR_MEM, G_BL_1MA), IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | G_RM_NOOP2),
    gsSPEndDisplayList(),
}; //_gcBoundDisplayList

/* .bss */
u8 _gcbound_red; //D_80380900
u8 _gcbound_green; //D_80380901
u8 _gcbound_blue; //D_80380902

/* .code */
void  _gcbound_draw(Gfx** dl, s32 a, s32 r, s32 g, s32 b){
    gSPDisplayList((*dl)++, &D_803688E8);
    gDPSetFogColor((*dl)++, r, g, b, a);
    gSPTextureRectangle((*dl)++, 0,  0, (framebuffer_width-1)<<2, (framebuffer_height-1)<<2, 0, 0, 0, 0x100, 0x100);
}

void gcbound_draw(Gfx** dl){
    _gcbound_draw(dl, D_803688E0, _gcbound_red, _gcbound_green, _gcbound_blue);
}

void gcbound_alpha(s32 a){
    D_803688E0 = a;
    D_803688E0 = (D_803688E0 < 0) ? 0 : D_803688E0;
    D_803688E0 = (D_803688E0 > 0xff) ? 0xff : D_803688E0;
}

void gcbound_color(s32 r, s32 g, s32 b){
    _gcbound_red = r;
    _gcbound_green = g;
    _gcbound_blue = b;

}

void gcbound_reset(void){
    gcbound_alpha(0);
    gcbound_color(0,0,0);
}
