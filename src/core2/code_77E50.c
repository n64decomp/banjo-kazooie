#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s16 D_803A5D00[2][0xF660];

void func_802FEDE0(BKTextureList *texture_list, s32 indx, s32 x_offset, s32 y_offset){
    u16 *sp24;
    u16 *frame_buffer_ptr; 
    s32 y;
    s32 x;

    sp24 = (u16*)func_802EA620(texture_list) + indx*32*32;
    frame_buffer_ptr = D_803A5D00[func_8024BDA0()];
    for(y = 0; y < 32; y++){//L802FEE60
        for(x = 0; x < 32; x++){//L802FEE68
            sp24[32*(31 - y) + x] = frame_buffer_ptr[(y_offset + y)*D_80276588 + (x_offset + x)] | 1; //framebuffer to texture???
        };
    };
}

//framebuffer_to_texture_list
void func_802FEF48(BKModelBin *model_bin){
    BKTextureList *texture_list;
    s32 x, y;

    texture_list = func_8033A104(model_bin);
    osInvalDCache((void *)D_803A5D00[func_8024BDA0()], D_80276588 * D_8027658C*2);

    for(y = 0; y < 8; y++){//L802FEFEC
        for(x = 0; x < 10; x++){
            //get textures from framebuffer???
            func_802FEDE0(texture_list, 10*y + x, 32*x + (D_80276588 - 10*32)/2, (s32)32*y + (D_8027658C - 8*32)/2);
        }
    };

    osWriteBackDCacheAll();
}
