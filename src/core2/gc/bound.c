#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "gc/gcbound.h"


extern s32 D_803688E0; //_gcBoundAlpha
extern s32 D_803688E8; //_gcBoundDisplayList
extern u8 _gcbound_red; //D_80380900
extern u8 _gcbound_green; //D_80380901
extern u8 _gcbound_blue; //D_80380902

void  _gcbound_draw(Gfx** dl, s32 a, s32 r, s32 g, s32 b){
    gSPDisplayList((*dl)++, &D_803688E8);
    gDPSetFogColor((*dl)++, r, g, b, a);
    gSPTextureRectangle((*dl)++, 0,  0, (D_80276588-1)<<2, (D_8027658C-1)<<2, 0, 0, 0, 0x100, 0x100);
}

void gcbound_draw(Gfx** dl){
    _gcbound_draw(dl, D_803688E0, _gcbound_red, _gcbound_green, _gcbound_blue);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/bound/gcbound_alpha.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/bound/gcbound_color.s")
// void gcbound_color(u8 r, u8 g, u8 b){
//     _gcbound_red = r;
//     _gcbound_green = g;
//     _gcbound_blue = b;

// }

void gcbound_reset(void){
    gcbound_alpha(0);
    gcbound_color(0,0,0);
}
