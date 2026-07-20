#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

struct {
    u16 *data;
    bool unk4;
} sDepthBuffer;

void depthbuffer_clear(Gfx **gfx) {
    depthbuffer_clearRegion(gfx, 0, 0, gFramebufferWidth, gFramebufferHeight, gFramebuffers[getActiveFramebuffer()]);
}

void depthbuffer_clearRegion(Gfx **gfx, s32 x, s32 y, s32 w, s32 h, void *color_buffer) {
    if ((sDepthBuffer.data != NULL) && ((getGameMode() != GAME_MODE_4_PAUSED) || gsworld_getEnableDraw())) {
        gDPPipeSync((*gfx)++);
        gDPSetColorImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, gFramebufferWidth, OS_K0_TO_PHYSICAL(sDepthBuffer.data));
        gDPSetCycleType((*gfx)++, G_CYC_FILL);
        gDPSetRenderMode((*gfx)++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetFillColor((*gfx)++, (GPACK_ZDZ(G_MAXFBZ, 0) << 16) | GPACK_ZDZ(G_MAXFBZ, 0));
        gDPScisFillRectangle((*gfx)++, x, y, x + w - 1, y + h - 1);

        gDPPipeSync((*gfx)++);
        gDPSetColorImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, gFramebufferWidth, OS_K0_TO_PHYSICAL(color_buffer));
    }
}

bool depthbuffer_getUnk4(void) {
    return sDepthBuffer.unk4;
}

bool depthbuffer_isDataPtrSet(void) {
    return sDepthBuffer.data != NULL;
}

void depthbuffer_stub(void) {}

void depthbuffer_enable(bool enable) {
    u16 *var_v0;

    if (enable) {
        sDepthBuffer.data = (u16 *) D_8000E800;

        var_v0 = sDepthBuffer.data;
        while (((s32) sDepthBuffer.data) % 64) {
            sDepthBuffer.data = var_v0 + 1;
            var_v0 = sDepthBuffer.data;
        }
        
        do { } while ((D_8000E800 && 1) * 0); //remove this
    } else {
        sDepthBuffer.data = NULL;
    }

    sDepthBuffer.unk4 = FALSE;
}

void depthbuffer_setUnk4(bool value) {
    sDepthBuffer.unk4 = sDepthBuffer.data && value;
}

void depthbuffer_set(Gfx **gfx) {
    if (sDepthBuffer.data && getGameMode() != GAME_MODE_4_PAUSED) {
        gDPPipeSync((*gfx)++);
        gDPSetDepthImage((*gfx)++, sDepthBuffer.data);
    }
}

void *depthbuffer_getDataPtr(void) {
    return sDepthBuffer.data;
}
