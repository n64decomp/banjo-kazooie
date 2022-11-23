#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#define IA8_I(ia) ((ia) >> 4)
#define IA8_A(ia) ((ia) & 0xF)
#define I4_2_RGBA16(i,a) ((i << 12) | (i << 7) | (i << 2) | (a))

void func_8024A3C8(s32 x, s32 y);
void draw_prim_rect(s32 x, s32 y, s32 w, s32 h);
void set_prim_color(s32 r, s32 g, s32 b);
void func_8024A85C(s32 buffer_indx);


extern u16 D_803A5D00[2][0xF660]; //framebuffer
extern s32 D_80276588; //framebuffer width
extern s32 D_8027658C; //framebuffer height

/* .bss */
s32 D_802806E0;
s32 D_802806E4;
s32 D_802806E8;
s32 D_802806EC;

void draw_sprite_ci4(s32 x, s32 y, BKSprite *sprite, s32 frame, s32 alpha_enabled)
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
    
    framebuffer = D_803A5D00[D_802806EC];
    sprite_frame = spriteGetFramePtr(sprite, (u32) frame);
    if (!alpha_enabled){
        set_prim_color(0, 0, 0x80);
        draw_prim_rect(x, y, sprite_frame->w, sprite_frame->h);
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
                if ((0 <= fb_x) && (fb_x < D_80276588))
                {
                    fb_y = (chunk->y + y) + iy;
                    if ((fb_y >= 0) && (fb_y < D_8027658C))
                    {
                        pxl_ptr = (framebuffer + fb_x) + (fb_y * D_80276588);
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

void draw_sprite_ci8(s32 x, s32 y, BKSprite *sprite, s32 frame, s32 alpha_enabled)
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
    framebuffer = D_803A5D00[D_802806EC];
    sprite_frame = spriteGetFramePtr(sprite, (u32) frame);
    if (!alpha_enabled){
        set_prim_color(0, 0, 0x80);
        draw_prim_rect(x, y, sprite_frame->w, sprite_frame->h);
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
                if ((0 <= fb_x) && (fb_x < D_80276588))
                {
                    fb_y = (chunk->y + y) + iy;
                    if ((fb_y >= 0) && (fb_y < D_8027658C))
                    {
                        pxl_ptr = (framebuffer + fb_x) + (fb_y * D_80276588);
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

void draw_sprite_rgba16(s32 x, s32 y, BKSprite *sprite, s32 frame, bool alpha_enabled) {
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

    framebuffer_ptr = &D_803A5D00[D_802806EC][0];
    sprite_ptr = spriteGetFramePtr(sprite, frame);
    if (!alpha_enabled) {
        set_prim_color(0, 0, 0x80);
        draw_prim_rect(x, y, sprite_ptr->w, sprite_ptr->h);
    }
    chunk_ptr = (BKSpriteTextureBlock *)(sprite_ptr + 1);
    for(i_chunk = 0; i_chunk < sprite_ptr->chunkCnt; i_chunk++) {
        for(tmem = (u16 *)(chunk_ptr + 1); (s32)tmem % 8; tmem++);

        for(txtr_y = 0; txtr_y < chunk_ptr->h; txtr_y++) {
            for(txtr_x = 0; txtr_x < chunk_ptr->w; txtr_x++) {
                fb_x = chunk_ptr->x + x + txtr_x;
                if ((fb_x >= 0) && (fb_x < D_80276588)) {
                    fb_y = chunk_ptr->y + y + txtr_y;
                    if ((fb_y >= 0) && (fb_y < D_8027658C)) {
                        pxl_ptr = framebuffer_ptr + fb_x +  (fb_y * D_80276588);
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

void draw_sprite_i4(s32 x, s32 y, BKSprite *sprite, s32 frame, bool aplha_enabled) {
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

    framebuffer_ptr = &D_803A5D00[D_802806EC][0];
    frame_ptr = spriteGetFramePtr(sprite, frame);
    if (!aplha_enabled) {
        set_prim_color(0, 0, 0x80);
        draw_prim_rect(x, y, frame_ptr->w, frame_ptr->h);
    }
    chunk_ptr = (BKSpriteTextureBlock *)(frame_ptr + 1);
    for(i_chunk = 0; i_chunk < frame_ptr->chunkCnt; i_chunk++) {
        for(tmem = (u8*)(chunk_ptr + 1); (s32)tmem % 8; tmem++);
        
        for(txtr_y = 0; txtr_y < chunk_ptr->h; txtr_y++) {
            for(txtr_x = 0; txtr_x < chunk_ptr->w; txtr_x += 2) {
                fb_x = chunk_ptr->x + x + txtr_x;
                if ((fb_x >= 0) &&  (fb_x < D_80276588)) {
                    fb_y = chunk_ptr->y + y + txtr_y;
                    if ((fb_y >= 0) && (fb_y < D_8027658C)) {
                        p1 = (*tmem >> 4);
                        p2 = (*tmem & 0xF);
                        fb_pxl_ptr = framebuffer_ptr + fb_x + (fb_y * D_80276588);
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

void draw_sprite_ia4(s32 x, s32 y, BKSprite *sprite, s32 frame, bool aplha_enabled) {
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

    framebuffer_ptr = &D_803A5D00[D_802806EC][0];
    frame_ptr = spriteGetFramePtr(sprite, frame);
    if (!aplha_enabled) {
        set_prim_color(0, 0, 0x80);
        draw_prim_rect(x, y, frame_ptr->w, frame_ptr->h);
    }
    chunk_ptr = (BKSpriteTextureBlock *)(frame_ptr + 1);
    for(i_chunk = 0; i_chunk < frame_ptr->chunkCnt; i_chunk++) {
        for(tmem = (u8*)(chunk_ptr + 1); (s32)tmem % 8; tmem++);
        
        for(txtr_y = 0; txtr_y < chunk_ptr->h; txtr_y++) {
            for(txtr_x = 0; txtr_x < chunk_ptr->w; txtr_x += 2) {
                fb_x = chunk_ptr->x + x + txtr_x;
                if ((fb_x >= 0) &&  (fb_x < D_80276588)) {
                    fb_y = chunk_ptr->y + y + txtr_y;
                    if ((fb_y >= 0) && (fb_y < D_8027658C)) {
                        fb_pxl_ptr = framebuffer_ptr + fb_x + (fb_y * D_80276588);\
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

void draw_sprite_i8(s32 x, s32 y, BKSprite *sprite, s32 frame, s32 alpha_enabled) {
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

    framebuffer_ptr = &D_803A5D00[D_802806EC][0];
    frame_ptr = spriteGetFramePtr(sprite, frame);
    if (!alpha_enabled) {
        set_prim_color(0, 0, 0x80);
        draw_prim_rect(x, y, frame_ptr->w, frame_ptr->h);
    }
    chunk_ptr = (BKSpriteTextureBlock *)(frame_ptr + 1);
    for(i_chunk = 0; i_chunk < frame_ptr->chunkCnt; i_chunk++){
        //align
        for(txtr_ptr = (u8*)(chunk_ptr + 1); (s32)txtr_ptr % 8; txtr_ptr++);

        for(txtr_y = 0; txtr_y < chunk_ptr->h; txtr_y++){
            for(txtr_x = 0; txtr_x < chunk_ptr->w; txtr_x++){
                fb_x = chunk_ptr->x + x + txtr_x;
                if (fb_x >= 0) {
                    if (fb_x < D_80276588) {
                        fb_y = chunk_ptr->y + y + txtr_y;
                        if ((fb_y >= 0) && (fb_y < D_8027658C)) {
                            pixel_ptr = framebuffer_ptr + fb_x + fb_y * D_80276588;
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

void draw_sprite_ia8(s32 x, s32 y, BKSprite *sprite, s32 frame, bool alpha_enabled) {
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

    framebuffer_ptr = &D_803A5D00[D_802806EC][0];
    sprite_frame = spriteGetFramePtr(sprite, frame);
    if (!alpha_enabled) {
        //draw blue rect over display area
        set_prim_color(0, 0, 0x80);
        draw_prim_rect(x, y, sprite_frame->w, sprite_frame->h);
    }
    chunk_ptr = (BKSpriteTextureBlock *)(sprite_frame + 1);
    for(i_chunk = 0; i_chunk < sprite_frame->chunkCnt; i_chunk++) {
        for(var_t2 = (u8*)(chunk_ptr + 1); (s32)var_t2 % 8; var_t2++);//align
        
        for(var_t3 = 0; var_t3 < chunk_ptr->h; var_t3++){
            for(var_a3 = 0; var_a3 < chunk_ptr->w; var_a3++) {
                fb_x = chunk_ptr->x + x + var_a3;
                if ((fb_x >= 0) && (fb_x < D_80276588)) {
                    fb_y = chunk_ptr->y + y + var_t3;
                    if ((fb_y >= 0) && (fb_y < D_8027658C)) {
                        temp_a1 = framebuffer_ptr + fb_x + fb_y * D_80276588;
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

void draw_sprite_rgba32(s32 x, s32 y, BKSprite *sprite, s32 frame, s32 alpha_enabled){
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


    framebuffer = &D_803A5D00[D_802806EC][0];
    sprite_frame = spriteGetFramePtr(sprite, frame);
    if (!alpha_enabled) {
        set_prim_color(0, 0, 0x80);
        draw_prim_rect(x, y, sprite_frame->w, sprite_frame->h);
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
                    if ((fb_x >= 0) && (fb_x < D_80276588))
                    {
                        fb_y = (chunk_ptr->y + y) + iy;
                        if ((fb_y >= 0) && (fb_y < D_8027658C))
                        {
                            txtr_value = *tmem;
                            pxl_ptr = (framebuffer + fb_x) + (fb_y * D_80276588);
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

void func_802499BC(s32 arg0, s32 arg1, s32 arg2, s32 arg3){//signature may have more variables passed in
}

void func_802499D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3){//signature may have more variables passed in
}

void draw_texture_ci4(s32 x, s32 y, void *tmem, s32 w, s32 h, bool alpha_enabled){
    s32 ix;
    s32 iy;
    s32 icolor;
    u16 *framebuffer_ptr;
    u16 *palette_ptr;
    u8 *pixel_ptr;

    palette_ptr = (u16*)tmem;
    pixel_ptr = (u8*)&palette_ptr[0x10];
    framebuffer_ptr = &D_803A5D00[D_802806EC][x  + y * D_80276588];
    for(iy = 0; iy < h; iy++){
        for(ix = 0; ix < w; ix++){
            icolor = (ix & 1)? pixel_ptr[ix/2 + (iy*w)/2] & 0xF
                   : pixel_ptr[ix/2 + (iy*w)/2] >> 4;
            *framebuffer_ptr = palette_ptr[icolor];
            framebuffer_ptr++;
        }
        framebuffer_ptr += (D_80276588 - w);
    }
}

void func_80249CEC(s32 x, s32 y, BKSprite *sprite, s32 frame, s32 alpha_enabled) {
    s16 temp_v0;

    temp_v0 = sprite->type;
    if (temp_v0 & SPRITE_TYPE_I4) {
        draw_sprite_i4(x, y, sprite, frame, alpha_enabled);
    } else if (temp_v0 & SPRITE_TYPE_IA4) {
        draw_sprite_ia4(x, y, sprite, frame, alpha_enabled);
    } else if (temp_v0 & SPRITE_TYPE_I8) {
        draw_sprite_i8(x, y, sprite, frame, alpha_enabled);
    } else if (temp_v0 & SPRITE_TYPE_IA8) {
        draw_sprite_ia8(x, y, sprite, frame, alpha_enabled);    
    } else if (temp_v0 & SPRITE_TYPE_RGBA16) {
        draw_sprite_rgba16(x, y, sprite, frame, alpha_enabled);
    } else if (temp_v0 & SPRITE_TYPE_RGBA32) {
        draw_sprite_rgba32(x, y, sprite, frame, alpha_enabled);
    } else if (temp_v0 & SPRITE_TYPE_CI4) {
        draw_sprite_ci4(x, y, sprite, frame, alpha_enabled);
    } else if (temp_v0 & SPRITE_TYPE_CI8) {
        draw_sprite_ci8(x, y, sprite, frame, alpha_enabled);
    }
}

//arg4 = alpha enabled?
void func_80249DE0(s32 x, s32 y, s16 *arg2, s32 arg3, s32 arg4) {
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
        draw_texture_ci4(x, y, temp_v0 + 1, temp_v0->w, temp_v0->h, arg4);
        return;
    }
    //otherwise RGBA16
    framebuffer_ptr = &D_803A5D00[D_802806EC][x + y*D_80276588];
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
        framebuffer_ptr += (D_80276588 - temp_v0->w);
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_ABB0/func_80249F34.s")

//fill framebuffer with vert and horz lines
void func_8024A284(s32 x, s32 y, s32 arg2, s32 arg3, s32 horz_spacing, s32 vert_spacing) {
    s32 var_s2;
    s32 var_s3;

    for(var_s2 = 0; var_s2 < D_80276588; var_s2 += horz_spacing){
        for(var_s3 = 0; var_s3 < D_8027658C; var_s3++){
            func_8024A3C8(x + var_s2, y + var_s3);

        }
    }
    for(var_s3 = 0; var_s3 < D_8027658C; var_s3 += vert_spacing) {
        for(var_s2 = 0; var_s2 < D_80276588; var_s2++){
            func_8024A3C8(x + var_s2, y + var_s3);
        }
    }
}

//fills in pixel in frame buffer with D_802806E0 color
void func_8024A3C8(s32 x, s32 y) {
    s32 temp_v0;

    if (x >= 0) {
        if ((x < D_80276588) && (y >= 0) && (y < D_8027658C)) {
            D_803A5D00[D_802806EC][x + y * D_80276588] = _SHIFTL(D_802806E0 >> 3, 11, 5) | _SHIFTL(D_802806E4 >> 3, 6, 5) | _SHIFTL(D_802806E8 >> 3, 1, 5) | _SHIFTL(1, 0, 1);
        }
    }
}

//draw rectangular outline
void func_8024A490(s32 x, s32 y, s32 w, s32 h) {
    s32 var_s1;

    for(var_s1 = 0; var_s1 < w; var_s1++){
        func_8024A3C8(x + var_s1, y);
        func_8024A3C8(x + var_s1, y + h - 1);
    }
    for(var_s1 = 1; var_s1 < h - 1; var_s1++){
        func_8024A3C8(x, y + var_s1);
        func_8024A3C8(x + w - 1, y + var_s1);
    }
}

void func_8024A564(s32 x, s32 y, u16 *arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6)
{
  s32 temp_a2;
  s32 temp_a2_2;
  s32 temp_a2_3;
  s32 temp_f6;
  s32 temp_f6_2;
  s32 temp_lo;
  s32 temp_t5;
  s32 var_a0;
  s32 var_a2;
  s32 new_var;
  f32 new_var3;
  s32 new_var2;
  s32 var_t1;
  s32 var_t3;
  s32 var_v0;
  s32 var_v1;
  u16 temp_t8;
  s16 *var_t0;
  s16 *var_t2;
  var_v0 = 0;
  var_v1 = D_80276588;
  var_t0 = &D_803A5D00[D_802806EC][x + (y * D_80276588)];
  new_var = (s32) (((f64) (256.0f / (new_var3 = arg6))) + 0.5);
  new_var2 = (s32) (((f64) (256.0f / arg5)) + 0.5);
  for (var_t1 = (arg4 * arg6) + 0.5; var_t1 != 0; var_t1--)
  {
    temp_lo = (arg3 * arg5) + 0.5;
    var_a2 = ((var_v0 >> 8) * arg3) << 8;
    var_t2 = var_t0;
    for (var_t3 = temp_lo; var_t3 != 0; var_t3--)
    {
      *var_t2 = arg2[var_a2 >> 8];
      var_a2 += new_var2;
      var_t2++;
    }

    var_t0 += D_80276588;
    var_v0 += new_var;
  }

}

//fills in rectangle in frame buffer with D_802806E0 color
void draw_prim_rect(s32 x, s32 y, s32 w, s32 h) {
    s32 var_s0;
    s32 var_s1;
    s32 var_s4;

    var_s4 = 0;
    for(var_s4 = 0; var_s4 < w; var_s4++) {
        for(var_s0 = 0; var_s0 < h; var_s0++){
                func_8024A3C8(x + var_s4, y + var_s0);
            }
    }
}

void func_8024A810(void){
    set_prim_color(0, 0x80, 0);
    func_8024A85C(0);
}

void set_prim_color(s32 r, s32 g, s32 b){
    D_802806E0 = r;
    D_802806E4 = g;
    D_802806E8 = b;
}

void func_8024A85C(s32 buffer_indx){
    D_802806EC = buffer_indx;
}

s32 func_8024A868(void){
    return D_802806EC;
}
