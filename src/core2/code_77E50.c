#include <ultra64.h>
#include "core1/core1.h"
#include "model.h"

void model_copyFramebufferBlockToTexture(BKTextureList *texture_list, s32 index, s32 x_offset, s32 y_offset) {
    u16 *texture_data_ptr;
    u16 *framebuffer_ptr; 
    s32 y;
    s32 x;

    texture_data_ptr = (u16 *) textureList_getDataPtr(texture_list) + (32 * 32 * index);
    framebuffer_ptr = gFramebuffers[getActiveFramebuffer()];
    for (y = 0; y < 32; y++) {
        for (x = 0; x < 32; x++) {
            texture_data_ptr[32 * (31 - y) + x] = framebuffer_ptr[(y_offset + y) * gFramebufferWidth + (x_offset + x)] | 0x01;
        };
    };
}

void model_copyFramebufferToTextures(BKModelBin *this) {
    BKTextureList *texture_list;
    s32 x, y;

    texture_list = modelbin_getTextureList(this);
    osInvalDCache(gFramebuffers[getActiveFramebuffer()], gFramebufferWidth * gFramebufferHeight * sizeof(u16));

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 10; x++) {
            model_copyFramebufferBlockToTexture(texture_list, 10 * y + x, 32 * x + (gFramebufferWidth - 10 * 32) / 2, 32 * y + (gFramebufferHeight - 8 * 32) / 2);
        }
    };

    osWritebackDCacheAll();
}
