#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

void func_802FEDE0(BKTextureList *texture_list, s32 indx, s32 x_offset, s32 y_offset){
    u16 *sp24;
    u16 *frame_buffer_ptr; 
    s32 y;
    s32 x;

    sp24 = (u16*)func_802EA620(texture_list) + indx*32*32;
    frame_buffer_ptr = gFramebuffers[getActiveFramebuffer()];
    for(y = 0; y < 32; y++){//L802FEE60
        for(x = 0; x < 32; x++){//L802FEE68
            sp24[32*(31 - y) + x] = frame_buffer_ptr[(y_offset + y)*gFramebufferWidth + (x_offset + x)] | 1; //framebuffer to texture???
        };
    };
}

//framebuffer_to_model_texture
void func_802FEF48(BKModelBin *model_bin){
    BKTextureList *texture_list;
    s32 x, y;

    texture_list = model_getTextureList(model_bin);
    osInvalDCache((void *)gFramebuffers[getActiveFramebuffer()], gFramebufferWidth * gFramebufferHeight*2);

    for(y = 0; y < 8; y++){//L802FEFEC
        for(x = 0; x < 10; x++){
            //get textures from framebuffer???
            func_802FEDE0(texture_list, 10*y + x, 32*x + (gFramebufferWidth - 10*32)/2, (s32)32*y + (gFramebufferHeight - 8*32)/2);
        }
    };

    osWriteBackDCacheAll();
}
