#include <ultra64.h>
#include "core1/core1.h"

#define IA8_I(ia) ((ia) >> 4)
#define IA8_A(ia) ((ia) & 0xF)
#define I4_2_RGBA16(i,a) ((i << 12) | (i << 7) | (i << 2) | (a))

#define RGBA16_R5(rgba) ((rgba) >> 11)
#define RGBA16_G5(rgba) (((rgba) >> 6) & 0x1f)
#define RGBA16_B5(rgba) (((rgba) >> 1) & 0x1f)
#define RGBA16_RED5(rgba) ((rgba) >> 11)
#define C5_TO_C8(c5) ((c5) << 3)
#define C8_TO_C5(c5) ((c5) >> 3)

static s32 sPrimColor_r;
static s32 sPrimColor_g;
static s32 sPrimColor_b;
static s32 sBufferIndex;

void framebufferdraw_draw_CI4(s32 x, s32 y, BKSprite *sprite, s32 frame, s32 alpha_enabled)
{
    BKSpriteFrame *sprite_frame;
    s32 palette_offset;
    u16 *palette;
    s32 fb_y;
    s32 fb_x;
    s32 iy;
    s32 i_chunk;
    s32 ix;
    u8 *tmem;
    BKSpriteTextureBlock *chunk;
    u16 *pxl_ptr;
    u16 *framebuffer;
    s32 indx1;
    s32 indx2;
    s32 color1;
    s32 color2;
    
    framebuffer = gFramebuffers[sBufferIndex];
    sprite_frame = sprite_getFramePtr(sprite, (u32) frame);
    if (!alpha_enabled){
        framebufferdraw_setPrimColor(0, 0, 0x80);
        framebufferdraw_drawRect(x, y, sprite_frame->w, sprite_frame->h);
    }
    
    //align palette
    for(palette_offset = (s32) (sprite_frame + 1); palette_offset % 8; palette_offset++){
        continue;
    }
    palette = (u16*)palette_offset;
    
    chunk = (BKSpriteTextureBlock *) (palette + 16);
    for (i_chunk = 0; i_chunk < sprite_frame->chunkCnt; i_chunk++) {
        //align texture
        tmem = (u8 *) (chunk + 1);
        while (((s32) tmem) % 8)
        {
            tmem = ((s32) tmem) + 1;
        }
        
        //copy texture to framebuffer
        for (iy = 0; iy < chunk->h; iy++) {
            for (ix = 0; ix < chunk->w; ix += 2) {
                indx1 = ((*tmem) >> 4) & 0xF;
                indx2 = *tmem & 0xF;
                fb_x = (chunk->x + x) + ix;
                if ((0 <= fb_x) && (fb_x < gFramebufferWidth))
                {
                    fb_y = (chunk->y + y) + iy;
                    if ((fb_y >= 0) && (fb_y < gFramebufferHeight))
                    {
                        pxl_ptr = (framebuffer + fb_x) + (fb_y * gFramebufferWidth);
                        color1 = palette[indx1];
                        if (color1 & 1) {
                          *pxl_ptr = color1;
                        } else if (!alpha_enabled) {
                          *pxl_ptr = (unsigned long) 1;
                          palette_offset = (u16 *) (sprite_frame + 1); //THIS IS GARBAGE for correct reg alloc
                        }
                        if (palette[indx2] & 1) { 
                            pxl_ptr[1] = palette[indx2];
                        } else if (!alpha_enabled) {
                            pxl_ptr[1] = 1;
                        }
                    }
                }
                tmem++;
            }
        }
        chunk = (BKSpriteTextureBlock *) tmem;
    }
}

void framebufferdraw_draw_CI8(s32 x, s32 y, BKSprite *sprite, s32 frame, s32 alpha_enabled)
{
    static s32 D_80275C00 = 0;
    u16 *palette;
    s32 fb_y;
    s32 fb_x;
    s32 iy;
    s32 i_chunk;
    s32 ix;
    u8 *tmem;
    BKSpriteTextureBlock *chunk;
    u16 *pxl_ptr;
    int new_var;
    BKSpriteFrame *sprite_frame;
    u16 *framebuffer;
    s32 indx;
    s32 palette_unaligned;
    D_80275C00++;
    if (D_80275C00 == 0xA) {
        D_80275C00 = 0;
    }
    framebuffer = gFramebuffers[sBufferIndex];
    sprite_frame = sprite_getFramePtr(sprite, (u32) frame);
    if (!alpha_enabled){
        framebufferdraw_setPrimColor(0, 0, 0x80);
        framebufferdraw_drawRect(x, y, sprite_frame->w, sprite_frame->h);
    }

    palette = (u16 *) (sprite_frame + 1);
    for (palette_unaligned = palette; ((s32) palette_unaligned) % 8; palette_unaligned++){
        ;
    }
    palette = palette_unaligned;
    
    chunk = (BKSpriteTextureBlock *) (palette + 0x100);
    for (i_chunk = 0; i_chunk < sprite_frame->chunkCnt; i_chunk++){
        palette_unaligned = (u16 *) (chunk + 1);
        for (tmem = (u16 *) (chunk + 1); ((s32) tmem) % 8; tmem++){
            ;
        }

        for (iy = 0; iy < chunk->h; iy++){
            for (ix = 0; ix < chunk->w; ix++){
                fb_x = (chunk->x + x) + ix;
                if ((0 <= fb_x) && (fb_x < gFramebufferWidth))
                {
                    fb_y = (chunk->y + y) + iy;
                    if ((fb_y >= 0) && (fb_y < gFramebufferHeight))
                    {
                        pxl_ptr = (framebuffer + fb_x) + (fb_y * gFramebufferWidth);
                        if (palette[*tmem] & 1){
                            *pxl_ptr = palette[*tmem];
                        } 
                        else if (!alpha_enabled)
                        {
                            if (palette[*tmem] & 0xFFFE){
                                *pxl_ptr = (D_80275C00 < 5) ? (0xFFFF) : (palette[*tmem] | 1);
                            }
                            else{
                                *pxl_ptr = 1;
                            }
                        }
                    }
                }
                tmem++;
            }

        }

        chunk = (BKSpriteTextureBlock *) tmem;
    }

}

void framebufferdraw_draw_RGBA16(s32 x, s32 y, BKSprite *sprite, s32 frame, bool alpha_enabled) {
    BKSpriteFrame *sprite_ptr;
    BKSpriteTextureBlock *chunk_ptr;
    s16 *tmem;
    u16 *framebuffer_ptr;
    s32 fb_x;
    s32 fb_y;
    s32 i_chunk;
    s32 txtr_x;
    s32 txtr_y;
    u16 *pxl_ptr;
    u16 rgba;

    framebuffer_ptr = &gFramebuffers[sBufferIndex][0];
    sprite_ptr = sprite_getFramePtr(sprite, frame);
    if (!alpha_enabled) {
        framebufferdraw_setPrimColor(0, 0, 0x80);
        framebufferdraw_drawRect(x, y, sprite_ptr->w, sprite_ptr->h);
    }
    chunk_ptr = (BKSpriteTextureBlock *)(sprite_ptr + 1);
    for(i_chunk = 0; i_chunk < sprite_ptr->chunkCnt; i_chunk++) {
        for(tmem = (u16 *)(chunk_ptr + 1); (s32)tmem % 8; tmem++);

        for(txtr_y = 0; txtr_y < chunk_ptr->h; txtr_y++) {
            for(txtr_x = 0; txtr_x < chunk_ptr->w; txtr_x++) {
                fb_x = chunk_ptr->x + x + txtr_x;
                if ((fb_x >= 0) && (fb_x < gFramebufferWidth)) {
                    fb_y = chunk_ptr->y + y + txtr_y;
                    if ((fb_y >= 0) && (fb_y < gFramebufferHeight)) {
                        pxl_ptr = framebuffer_ptr + fb_x +  (fb_y * gFramebufferWidth);
                        rgba = *tmem;
                        if (rgba & 1) {
                            *pxl_ptr = rgba;
                        } else if (!alpha_enabled) {
                            *pxl_ptr = rgba | 1;
                        }
                    }
                }
                tmem++;
            }
        }
        chunk_ptr = (BKSpriteTextureBlock *) tmem;
    }
}

void framebufferdraw_draw_I4(s32 x, s32 y, BKSprite *sprite, s32 frame, bool aplha_enabled) {
    BKSpriteFrame *frame_ptr;
    BKSpriteTextureBlock *chunk_ptr;
    s16 *temp_v0;
    u8 *tmem;
    s32 fb_x;
    s32 fb_y;
    s32 p1;
    s32 p2;
    u16 *framebuffer_ptr;
    s32 txtr_y;
    s32 i_chunk;
    s32 txtr_x;
    u16 *fb_pxl_ptr;

    framebuffer_ptr = &gFramebuffers[sBufferIndex][0];
    frame_ptr = sprite_getFramePtr(sprite, frame);
    if (!aplha_enabled) {
        framebufferdraw_setPrimColor(0, 0, 0x80);
        framebufferdraw_drawRect(x, y, frame_ptr->w, frame_ptr->h);
    }
    chunk_ptr = (BKSpriteTextureBlock *)(frame_ptr + 1);
    for(i_chunk = 0; i_chunk < frame_ptr->chunkCnt; i_chunk++) {
        for(tmem = (u8*)(chunk_ptr + 1); (s32)tmem % 8; tmem++);
        
        for(txtr_y = 0; txtr_y < chunk_ptr->h; txtr_y++) {
            for(txtr_x = 0; txtr_x < chunk_ptr->w; txtr_x += 2) {
                fb_x = chunk_ptr->x + x + txtr_x;
                if ((fb_x >= 0) &&  (fb_x < gFramebufferWidth)) {
                    fb_y = chunk_ptr->y + y + txtr_y;
                    if ((fb_y >= 0) && (fb_y < gFramebufferHeight)) {
                        p1 = (*tmem >> 4);
                        p2 = (*tmem & 0xF);
                        fb_pxl_ptr = framebuffer_ptr + fb_x + (fb_y * gFramebufferWidth);
                        if (p1) {
                            *fb_pxl_ptr = (p1 << 0xC) | (p1 << 0x7) | (p1 << 0x2) | 1;
                        } else if (!aplha_enabled) {
                            *fb_pxl_ptr = 1;
                        }
                        if (p2) {
                            *(fb_pxl_ptr + 1) = (p2 << 0xC) | (p2 << 7) | (p2 << 2) | 1;
                        } else if (!aplha_enabled) {
                            *(fb_pxl_ptr + 1) = 1;
                        }
                    }
                }
                tmem++;
            }
        }
        chunk_ptr = (BKSpriteTextureBlock *) tmem;
    }
}

void framebufferdraw_draw_IA4(s32 x, s32 y, BKSprite *sprite, s32 frame, bool aplha_enabled) {
    BKSpriteFrame *frame_ptr;
    BKSpriteTextureBlock *chunk_ptr;
    s16 *temp_v0;
    u8 *tmem;
    s32 fb_x;
    s32 fb_y;
    s32 p1;
    s32 p2;
    u16 *framebuffer_ptr;
    u32 p1_i;
    u32 p1_a;
    u32 p2_i;
    u32 p2_a;
    s32 txtr_y;
    s32 i_chunk;
    s32 txtr_x;
    u16 *fb_pxl_ptr;

    framebuffer_ptr = &gFramebuffers[sBufferIndex][0];
    frame_ptr = sprite_getFramePtr(sprite, frame);
    if (!aplha_enabled) {
        framebufferdraw_setPrimColor(0, 0, 0x80);
        framebufferdraw_drawRect(x, y, frame_ptr->w, frame_ptr->h);
    }
    chunk_ptr = (BKSpriteTextureBlock *)(frame_ptr + 1);
    for(i_chunk = 0; i_chunk < frame_ptr->chunkCnt; i_chunk++) {
        for(tmem = (u8*)(chunk_ptr + 1); (s32)tmem % 8; tmem++);
        
        for(txtr_y = 0; txtr_y < chunk_ptr->h; txtr_y++) {
            for(txtr_x = 0; txtr_x < chunk_ptr->w; txtr_x += 2) {
                fb_x = chunk_ptr->x + x + txtr_x;
                if ((fb_x >= 0) &&  (fb_x < gFramebufferWidth)) {
                    fb_y = chunk_ptr->y + y + txtr_y;
                    if ((fb_y >= 0) && (fb_y < gFramebufferHeight)) {
                        fb_pxl_ptr = framebuffer_ptr + fb_x + (fb_y * gFramebufferWidth);\
                        p1 = (*tmem >> 4);
                        p2 = (*tmem & 0xF);
                        p1_i = p1 & 0xE;
                        p1_a = p1 & 1;
                        p2_i = p2 & 0xE;
                        p2_a = p2 & 1;
                        if (p1_a) { \
                            *fb_pxl_ptr = ((p1_i << 0xC) | (p1_i << 0x7) | (p1_i << 0x2)) | p1_a;
                        } else if (!aplha_enabled) {
                            *fb_pxl_ptr = 1;
                        }
                        if (p2_a) {\
                            *(fb_pxl_ptr + 1) = (p2_i << 0xC) | (p2_i << 7) | (p2_i << 2) | p2_a;
                        } else if (!aplha_enabled) {
                            *(fb_pxl_ptr + 1) = 1;
                        }
                    }
                }
                tmem++;
            }
        }
        chunk_ptr = (BKSpriteTextureBlock *) tmem;
    }
}

void framebufferdraw_draw_I8(s32 x, s32 y, BKSprite *sprite, s32 frame, s32 alpha_enabled) {
    BKSpriteFrame *frame_ptr;
    BKSpriteTextureBlock *chunk_ptr;
    s16 *pixel_ptr;
    u8 *txtr_ptr;
    s32 fb_y;
    u16 *framebuffer_ptr;
    s32 intensity;
    s32 fb_x;
    s32 txtr_x;
    s32 i_chunk;
    s32 txtr_y;

    framebuffer_ptr = &gFramebuffers[sBufferIndex][0];
    frame_ptr = sprite_getFramePtr(sprite, frame);
    if (!alpha_enabled) {
        framebufferdraw_setPrimColor(0, 0, 0x80);
        framebufferdraw_drawRect(x, y, frame_ptr->w, frame_ptr->h);
    }
    chunk_ptr = (BKSpriteTextureBlock *)(frame_ptr + 1);
    for(i_chunk = 0; i_chunk < frame_ptr->chunkCnt; i_chunk++){
        //align
        for(txtr_ptr = (u8*)(chunk_ptr + 1); (s32)txtr_ptr % 8; txtr_ptr++);

        for(txtr_y = 0; txtr_y < chunk_ptr->h; txtr_y++){
            for(txtr_x = 0; txtr_x < chunk_ptr->w; txtr_x++){
                fb_x = chunk_ptr->x + x + txtr_x;
                if (fb_x >= 0) {
                    if (fb_x < gFramebufferWidth) {
                        fb_y = chunk_ptr->y + y + txtr_y;
                        if ((fb_y >= 0) && (fb_y < gFramebufferHeight)) {
                            pixel_ptr = framebuffer_ptr + fb_x + fb_y * gFramebufferWidth;
                            intensity = (s32) *txtr_ptr >> 3;
                            if (intensity != 0) {
                                *pixel_ptr = (intensity << 0xB) | (intensity << 6) | (intensity << 1) | 1;
                            } else if (!alpha_enabled) {
                                *pixel_ptr = 1;
                            }
                        }
                    }
                }
                txtr_ptr += 1;
            }
        }
        chunk_ptr = (BKSpriteFrame *) txtr_ptr;
    }
}

void framebufferdraw_draw_IA8(s32 x, s32 y, BKSprite *sprite, s32 frame, bool alpha_enabled) {
    BKSpriteFrame *sprite_frame;
    BKSpriteTextureBlock *chunk_ptr;
    s16 *temp_a1;
    s16 *temp_v0;
    u8 *var_t2;
    u16 *framebuffer_ptr;
    s32 fb_x;
    s32 fb_y;
    s32 var_a3;
    s32 i_chunk;
    s32 var_t3;
    u32 temp_a2;

    framebuffer_ptr = &gFramebuffers[sBufferIndex][0];
    sprite_frame = sprite_getFramePtr(sprite, frame);
    if (!alpha_enabled) {
        //draw blue rect over display area
        framebufferdraw_setPrimColor(0, 0, 0x80);
        framebufferdraw_drawRect(x, y, sprite_frame->w, sprite_frame->h);
    }
    chunk_ptr = (BKSpriteTextureBlock *)(sprite_frame + 1);
    for(i_chunk = 0; i_chunk < sprite_frame->chunkCnt; i_chunk++) {
        for(var_t2 = (u8*)(chunk_ptr + 1); (s32)var_t2 % 8; var_t2++);//align
        
        for(var_t3 = 0; var_t3 < chunk_ptr->h; var_t3++){
            for(var_a3 = 0; var_a3 < chunk_ptr->w; var_a3++) {
                fb_x = chunk_ptr->x + x + var_a3;
                if ((fb_x >= 0) && (fb_x < gFramebufferWidth)) {
                    fb_y = chunk_ptr->y + y + var_t3;
                    if ((fb_y >= 0) && (fb_y < gFramebufferHeight)) {
                        temp_a1 = framebuffer_ptr + fb_x + fb_y * gFramebufferWidth;
                        temp_a2 = *var_t2;
                        if (IA8_A(temp_a2)) {
                            *temp_a1 = I4_2_RGBA16(IA8_I(temp_a2), 1);
                        } else if (!alpha_enabled) {
                            *temp_a1 = 1;
                        }
                    }
                }
                var_t2++;
            }
        }
        chunk_ptr = (BKSpriteFrame *) var_t2;
    }
}

void framebufferdraw_draw_RGBA32(s32 x, s32 y, BKSprite *sprite, s32 frame, s32 alpha_enabled){
    BKSpriteTextureBlock *chunk_ptr;
    u32 *tmem;
    u32 fb_value;
    s16 var_v1;
    s32 fb_x;
    s32 fb_y;
    u16 *framebuffer;
    s32 temp_t1;
    s32 alpha;
    s32 i_chunk;
    s32 iy;
    s32 ix;
    u16 *pxl_ptr;
    BKSpriteFrame *sprite_frame;
    u16 p1_a;
    u32 txtr_value;
    s32 red8;
    s32 green8;
    s32 blue8;


    framebuffer = &gFramebuffers[sBufferIndex][0];
    sprite_frame = sprite_getFramePtr(sprite, frame);
    if (!alpha_enabled) {
        framebufferdraw_setPrimColor(0, 0, 0x80);
        framebufferdraw_drawRect(x, y, sprite_frame->w, sprite_frame->h);
    }
    chunk_ptr = (BKSpriteTextureBlock *) (sprite_frame + 1);
    for (i_chunk = 0; i_chunk < sprite_frame->chunkCnt; i_chunk++) {
        if( (((chunk_ptr->x >= (-5)) && (chunk_ptr->x < 0x29)) 
            && (chunk_ptr->y >= (-5))) && (chunk_ptr->y < 0x29)
        ) {
            tmem = (u32 *) (1 + chunk_ptr);
            while (((s32) tmem) % 8)
            {
                tmem++;
            }

            for (iy = 0; iy < chunk_ptr->h; iy++)
            {
                for (ix = 0; ix < chunk_ptr->w; ix++)
                {
                    fb_x = (chunk_ptr->x + x) + ix;
                    if ((fb_x >= 0) && (fb_x < gFramebufferWidth))
                    {
                        fb_y = (chunk_ptr->y + y) + iy;
                        if ((fb_y >= 0) && (fb_y < gFramebufferHeight))
                        {
                            txtr_value = *tmem;
                            pxl_ptr = (framebuffer + fb_x) + (fb_y * gFramebufferWidth);
                            fb_value = (unsigned int) (*pxl_ptr);
                            alpha = _SHIFTR(txtr_value, 0, 8);
                            if (alpha) {//blend texture with existing pixel color
                                red8 = ((_SHIFTR(txtr_value, 24, 8) * alpha)   + (((((fb_value >> 11) )) *8) * (0xFF - alpha))) / 0xFF;
                                green8 = ((_SHIFTR(txtr_value, 16, 8) * alpha) + ((_SHIFTR(fb_value, 6, 5) * 8) * (0xFF - alpha))) / 0xFF;
                                blue8 = ((_SHIFTR(txtr_value, 8, 8) * alpha)   + ((_SHIFTR(fb_value, 1, 5) * 8) * (0xFF - alpha))) / 0xFF;
                                    
                                *pxl_ptr = ((_SHIFTL((red8 >> 3), 11, 5) | _SHIFTL((green8 >> 3), 6, 5)) | _SHIFTL((blue8 >> 3), 1, 5)) | 1;
                            }
                            else if (!alpha_enabled) {
                                *pxl_ptr = 0x0001;
                            }
                        }
                    }
                    tmem++;
                }

            }
            chunk_ptr = (BKSpriteFrame *) tmem;
        }
    }
}

void framebufferdraw_stub1(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {} //signature may have more variables passed in
void framebufferdraw_stub2(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {} //signature may have more variables passed in

void framebufferdraw_drawTexture_CI4(s32 x, s32 y, void *tmem, s32 w, s32 h, bool alpha_enabled) {
    s32 ix;
    s32 iy;
    s32 icolor;
    u16 *framebuffer_ptr;
    u16 *palette_ptr;
    u8 *pixel_ptr;

    palette_ptr = (u16*)tmem;
    pixel_ptr = (u8*)&palette_ptr[0x10];
    framebuffer_ptr = &gFramebuffers[sBufferIndex][x  + y * gFramebufferWidth];
    for(iy = 0; iy < h; iy++){
        for(ix = 0; ix < w; ix++){
            icolor = (ix & 1)? pixel_ptr[ix/2 + (iy*w)/2] & 0xF
                   : pixel_ptr[ix/2 + (iy*w)/2] >> 4;
            *framebuffer_ptr = palette_ptr[icolor];
            framebuffer_ptr++;
        }
        framebuffer_ptr += (gFramebufferWidth - w);
    }
}

void framebufferdraw_draw(s32 x, s32 y, BKSprite *sprite, s32 frame, s32 alpha_enabled) {
    s16 type;

    type = sprite->type;
    if (type & SPRITE_TYPE_I4) {
        framebufferdraw_draw_I4(x, y, sprite, frame, alpha_enabled);
    } else if (type & SPRITE_TYPE_IA4) {
        framebufferdraw_draw_IA4(x, y, sprite, frame, alpha_enabled);
    } else if (type & SPRITE_TYPE_I8) {
        framebufferdraw_draw_I8(x, y, sprite, frame, alpha_enabled);
    } else if (type & SPRITE_TYPE_IA8) {
        framebufferdraw_draw_IA8(x, y, sprite, frame, alpha_enabled);    
    } else if (type & SPRITE_TYPE_RGBA16) {
        framebufferdraw_draw_RGBA16(x, y, sprite, frame, alpha_enabled);
    } else if (type & SPRITE_TYPE_RGBA32) {
        framebufferdraw_draw_RGBA32(x, y, sprite, frame, alpha_enabled);
    } else if (type & SPRITE_TYPE_CI4) {
        framebufferdraw_draw_CI4(x, y, sprite, frame, alpha_enabled);
    } else if (type & SPRITE_TYPE_CI8) {
        framebufferdraw_draw_CI8(x, y, sprite, frame, alpha_enabled);
    }
}

//arg4 = alpha enabled?
void framebufferdraw_func_80249DE0(s32 x, s32 y, s16 *arg2, s32 arg3, s32 arg4) {
    s32 ix;
    s32 var_t2;
    s32 iy;
    u16 *framebuffer_ptr;
    u16 *texture_ptr;
    u16 temp_v1;
    BKSpriteTextureBlock *temp_v0;

    temp_v0 = func_8033EFB0(arg2, arg3);
    texture_ptr = (u16*)(temp_v0 + 1);
    if (*arg2 == SPRITE_TYPE_CI4) {
        framebufferdraw_drawTexture_CI4(x, y, temp_v0 + 1, temp_v0->w, temp_v0->h, arg4);
        return;
    }
    //otherwise RGBA16
    framebuffer_ptr = &gFramebuffers[sBufferIndex][x + y*gFramebufferWidth];
    for(iy = 0; iy < temp_v0->h; iy++){
        for(ix = 0; ix < temp_v0->w; ix++){
                temp_v1 = *texture_ptr;
                if (temp_v1 & 1) { //if visible
                    *framebuffer_ptr = temp_v1;
                } else if (arg4 == 0) {
                    *framebuffer_ptr = 1;
                }
                texture_ptr++;
                framebuffer_ptr++;
        }
        framebuffer_ptr += (gFramebufferWidth - temp_v0->w);
    }
}

void framebufferdraw_func_80249F34(s32 x, s32 y, Struct84s* maskList, s32 maskIndex, s32 mX, s32 mY, s32 mW, s32 mH, s32 maskColor, s32 mStride, bool dim, s32 replacementColor) {
    BKSpriteTextureBlock* mask_texture;
    s32 ix;
    s32 iy;
    u16* color_ptr;
    u16* mask_ptr;

    mask_texture = func_8033EFB0(maskList, maskIndex);
    mask_ptr = (u16*)(mask_texture + 1) + mX + mY * mask_texture->w;
    color_ptr = &gFramebuffers[sBufferIndex][x + y * gFramebufferWidth];
    for(iy = 0; iy < mH; iy += mStride){
        for(ix = 0; ix < mW; ix++){

            if(maskColor != *mask_ptr){
                *color_ptr = (replacementColor != 0)? replacementColor : *mask_ptr;
            }
            else if(dim){
                *color_ptr = _SHIFTL(C8_TO_C5(C5_TO_C8(RGBA16_R5(*color_ptr)) / 2), 11, 5) 
                        | _SHIFTL(C8_TO_C5(C5_TO_C8(RGBA16_G5(*color_ptr)) / 2), 6, 5) 
                        | _SHIFTL(C8_TO_C5(C5_TO_C8(RGBA16_B5(*color_ptr)) / 2), 1, 5) 
                        | 1;
            }

            color_ptr++;
            mask_ptr++;
        }
        mask_ptr += ((mStride * mask_texture->w) - mW);
        color_ptr += (gFramebufferWidth - mW);
    }
}

void framebufferdraw_drawGrid(s32 x, s32 y, s32 arg2, s32 arg3, s32 horz_spacing, s32 vert_spacing) {
    s32 x1;
    s32 y1;

    for (x1 = 0; x1 < gFramebufferWidth; x1 += horz_spacing) {
        for (y1 = 0; y1 < gFramebufferHeight; y1++) {
            framebufferdraw_setPixel(x + x1, y + y1);

        }
    }
    for (y1 = 0; y1 < gFramebufferHeight; y1 += vert_spacing) {
        for (x1 = 0; x1 < gFramebufferWidth; x1++) {
            framebufferdraw_setPixel(x + x1, y + y1);
        }
    }
}

void framebufferdraw_setPixel(s32 x, s32 y) {
    if ((x >= 0) && (x < gFramebufferWidth) && (y >= 0) && (y < gFramebufferHeight)) {
        gFramebuffers[sBufferIndex][x + y * gFramebufferWidth] = _SHIFTL(sPrimColor_r >> 3, 11, 5) | _SHIFTL(sPrimColor_g >> 3, 6, 5) | _SHIFTL(sPrimColor_b >> 3, 1, 5) | _SHIFTL(1, 0, 1);
    }
}

void framebufferdraw_drawOutline(s32 x, s32 y, s32 w, s32 h) {
    s32 x1;

    for (x1 = 0; x1 < w; x1++) {
        framebufferdraw_setPixel(x + x1, y);
        framebufferdraw_setPixel(x + x1, y + h - 1);
    }

    for (x1 = 1; x1 < h - 1; x1++) {
        framebufferdraw_setPixel(x, y + x1);
        framebufferdraw_setPixel(x + w - 1, y + x1);
    }
}

void framebufferdraw_func_8024A564(s32 x, s32 y, u16 *arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6) {
    s32 temp_lo;
    s32 var_a2;
    s32 new_var;
    f32 new_var3;
    s32 new_var2;
    s32 var_t1;
    s32 var_t3;
    s32 var_v0;
    s32 fb_width;
    s16 *pixel;
    s16 *var_t2;
    
    var_v0 = 0;
    fb_width = gFramebufferWidth;
    pixel = &gFramebuffers[sBufferIndex][x + (y * gFramebufferWidth)];
    new_var = (s32) (((f64) (256.0f / (new_var3 = arg6))) + 0.5);
    new_var2 = (s32) (((f64) (256.0f / arg5)) + 0.5);

    for (var_t1 = (arg4 * arg6) + 0.5; var_t1 != 0; var_t1--)
    {
        temp_lo = (arg3 * arg5) + 0.5;
        var_a2 = ((var_v0 >> 8) * arg3) << 8;
        var_t2 = pixel;

        for (var_t3 = temp_lo; var_t3 != 0; var_t3--) {
            *var_t2 = arg2[var_a2 >> 8];
            var_a2 += new_var2;
            var_t2++;
        }

        pixel += gFramebufferWidth;
        var_v0 += new_var;
    }
}

void framebufferdraw_drawRect(s32 x, s32 y, s32 w, s32 h) {
    s32 y1, x1;

    for (x1 = 0; x1 < w; x1++) {
        for (y1 = 0; y1 < h; y1++) {
                framebufferdraw_setPixel(x + x1, y + y1);
            }
    }
}

void framebufferdraw_resetPrimColorAndBuffer(void) {
    framebufferdraw_setPrimColor(0, 128, 0);
    framebufferdraw_setBufferIndex(0);
}

void framebufferdraw_setPrimColor(s32 r, s32 g, s32 b) {
    sPrimColor_r = r;
    sPrimColor_g = g;
    sPrimColor_b = b;
}

void framebufferdraw_setBufferIndex(s32 buffer_indx) {
    sBufferIndex = buffer_indx;
}

s32 framebufferdraw_getBufferIndex(void) {
    return sBufferIndex;
}
