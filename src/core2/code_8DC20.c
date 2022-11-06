#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern s16 D_803A5D00[2][0xF660];

extern Gfx D_8036C630[];
extern Gfx D_8036C690[];

/* .bss */
s32 D_803830A0;


/* .code */
void func_80314BB0(Gfx **gfx, Mtx **mtx, Vtx **vtx, void * frame_buffer_1, void *frame_buffer_2) {
    s32 x;
    s32 y;

    gSPDisplayList((*gfx)++, D_8036C630);
    gDPSetColorImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_80276588, OS_PHYSICAL_TO_K0(frame_buffer_1));
    for(y = 0;  y < D_8027658C / 32 + 1; y++){
        for(x = 0; x < D_80276588 / 32 + 1; x++){
            gDPLoadTextureTile((*gfx)++, osVirtualToPhysical(frame_buffer_2), G_IM_FMT_RGBA, G_IM_SIZ_16b, D_80276588, D_8027658C,
                0x20*x, 0x20*y, 0x20*(x + 1) - 1, 0x20*(y + 1) - 1,
                NULL, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, 0, 0
            );
            gSPScisTextureRectangle((*gfx)++, (0x20*x)*4, (0x20*y)*4, 0x20*(x + 1)*4, (0x20*(y + 1)*4), 
                G_TX_RENDERTILE, (0x20*x)<<5, (0x20*y)<<5, 0x400, 0x400
            );
        }
    }
    gSPDisplayList((*gfx)++, D_8036C690);
    gDPSetColorImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_80276588, OS_PHYSICAL_TO_K0(D_803A5D00[func_8024BDA0()]));
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
