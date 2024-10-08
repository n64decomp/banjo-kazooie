#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

struct {
    u16 *data;
    int unk4;
} gzBuffer;

extern u8 D_8000E800;
extern u16 D_803A5D00[2][0xF660];

void func_80253208(Gfx **gdl, s32 x, s32 y, s32 w, s32 h, void *color_buffer);

void func_80253190(Gfx **gdl){
    func_80253208(gdl, 0, 0, framebuffer_width, framebuffer_height, D_803A5D00[getActiveFramebuffer()]);
}

void func_80253208(Gfx **gdl, s32 x, s32 y, s32 w, s32 h, void *color_buffer){
    if( gzBuffer.data != NULL && (getGameMode() != GAME_MODE_4_PAUSED || func_80335134())){
        //draw z_buffer
        gDPPipeSync((*gdl)++);
        gDPSetColorImage((*gdl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, framebuffer_width, OS_K0_TO_PHYSICAL(gzBuffer.data));
        gDPSetCycleType((*gdl)++, G_CYC_FILL);
        gDPSetRenderMode((*gdl)++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetFillColor((*gdl)++, 0xFFFCFFFC);
        gDPScisFillRectangle((*gdl)++, x, y, x + w - 1, y + h - 1);
        
        //draw color_buffer
        gDPPipeSync((*gdl)++);
        gDPSetColorImage((*gdl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, framebuffer_width, OS_K0_TO_PHYSICAL(color_buffer));
    }
}

int func_80253400(void){
    return gzBuffer.unk4;
}

int func_8025340C(void){
    return gzBuffer.data != NULL;
}

void dummy_func_80253420(void){}

void func_80253428(int arg0) {
    u16 *var_v0;
    int new_var;
    if (arg0) {
        var_v0 = (gzBuffer.data = &D_8000E800);
        while (((s32) gzBuffer.data) % 0x40) {\
          var_v0 = (gzBuffer.data = var_v0 + 1);
        }
        
        do { } while ((&D_8000E800 && 1) * 0); //remove this
    }else{
        gzBuffer.data = 0;
    }
    gzBuffer.unk4 = 0;
}

void func_802534A8(int arg0){
    gzBuffer.unk4 = (gzBuffer.data != NULL && arg0);
}

void zBuffer_set(Gfx **gdl){
    if(gzBuffer.data && getGameMode() != GAME_MODE_4_PAUSED){
        gDPPipeSync((*gdl)++);
        gDPSetDepthImage((*gdl)++, gzBuffer.data);
    }
}

void *zBuffer_get(void){
    return gzBuffer.data;
}
