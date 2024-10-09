#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

struct {
    void *data;
    int unk4;
} sDepthBuffer;

void func_80253190(Gfx **gfx) {
    func_80253208(gfx, 0, 0, gFramebufferWidth, gFramebufferHeight, gFramebuffers[getActiveFramebuffer()]);
}

void func_80253208(Gfx **gfx, s32 x, s32 y, s32 w, s32 h, void *color_buffer){
    if( sDepthBuffer.data != NULL && (getGameMode() != GAME_MODE_4_PAUSED || func_80335134())){
        //draw z_buffer
        gDPPipeSync((*gfx)++);
        gDPSetColorImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, gFramebufferWidth, OS_K0_TO_PHYSICAL(sDepthBuffer.data));
        gDPSetCycleType((*gfx)++, G_CYC_FILL);
        gDPSetRenderMode((*gfx)++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetFillColor((*gfx)++, 0xFFFCFFFC);
        gDPScisFillRectangle((*gfx)++, x, y, x + w - 1, y + h - 1);
        
        //draw color_buffer
        gDPPipeSync((*gfx)++);
        gDPSetColorImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, gFramebufferWidth, OS_K0_TO_PHYSICAL(color_buffer));
    }
}

int func_80253400(void){
    return sDepthBuffer.unk4;
}

bool depthBuffer_isPointerSet(void) {
    return sDepthBuffer.data != NULL;
}

void depthBuffer_stub(void) {}

void func_80253428(int arg0) {
    u16 *var_v0;
    int new_var;
    if (arg0) {
        var_v0 = (sDepthBuffer.data = &D_8000E800);
        while (((s32) sDepthBuffer.data) % 0x40) {
          var_v0 = (sDepthBuffer.data = var_v0 + 1);
        }
        
        do { } while ((&D_8000E800 && 1) * 0); //remove this
    }else{
        sDepthBuffer.data = NULL;
    }
    sDepthBuffer.unk4 = FALSE;
}

void func_802534A8(int arg0) {
    sDepthBuffer.unk4 = (sDepthBuffer.data != NULL && arg0);
}

void zBuffer_set(Gfx **gfx) {
    if (sDepthBuffer.data && getGameMode() != GAME_MODE_4_PAUSED) {
        gDPPipeSync((*gfx)++);
        gDPSetDepthImage((*gfx)++, sDepthBuffer.data);
    }
}

void *zBuffer_get(void) {
    return sDepthBuffer.data;
}
