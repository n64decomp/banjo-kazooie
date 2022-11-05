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

/* .data */
extern u8 D_80275A50[][3];
extern s32 D_80275A68;
extern s32 D_80275A6C;
extern s32 D_80275A70;
extern u8  D_80275A74[];
extern u32 D_80275A7C[][2];

extern s16 D_80275BBC;
extern s16 D_80275BC0;
extern s16 D_80275BC4;

extern s16 D_80275BC8;

extern s16 D_80275BCC;
extern s16 D_80275BD0;
extern s16 D_80275BD4;
extern s16 D_80275BD8;
extern s16 D_80275BDC;
extern  u8 D_80275BE0;
extern s32 D_80275BE4;
extern u8 D_80275BE8[];
/* .bss */
s32 D_802806E0;
s32 D_802806E4;
s32 D_802806E8;
s32 D_802806EC;

/* .h */
void func_802484D0(void);
void func_8024856C(void);
void func_80248520(void);

/* code */
void func_80247750(s32 r, s32 g, s32 b){
    D_80275A68 = r;
    D_80275A6C = g;
    D_80275A70 = b;
}

void func_8024776C(s32 x, s32 y) {
    s32 rgba16;
    if( ((x >= 0) && (x < D_80276588))
        && ((y >= 0) && (y < D_8027658C))
    ) {
        D_803A5D00[0][x + y*D_80276588] = _SHIFTL(D_80275A68 >> 3, 11, 5) | _SHIFTL(D_80275A6C >> 3, 6, 5) | _SHIFTL(D_80275A70 >> 3, 1, 5) | _SHIFTL(1, 0, 1);
        D_803A5D00[1][x + y*D_80276588] = _SHIFTL(D_80275A68 >> 3, 11, 5) | _SHIFTL(D_80275A6C >> 3, 6, 5) | _SHIFTL(D_80275A70 >> 3, 1, 5) | _SHIFTL(1, 0, 1);
        
    }
}

void func_80247818(s32 x, s32 y, s32 w, s32 h) {
    s32 iy;
    s32 var_s1;
    s32 ix;

    for(ix = 0; ix < w; ix++){
        for(iy = 0; iy < h; iy++){
            func_8024776C(x + ix, y + iy);
        }
    }
    osWriteBackDCacheAll();
}

void func_802478C0(s32 r, s32 g, s32 b) {
    func_80247750(r, g, b);
    func_80247818((D_80276588 - 128) / 2, (D_8027658C - 100) / 2, 128, 100);
}

void func_8024792C(void){}

void func_80247934(void) {
    s32 var_s0;

    for(var_s0 = 0; var_s0 < 2000000; var_s0++){
        func_8024792C();
    }
}

void func_80247978(s32 arg0) {
    do{
        func_802478C0(D_80275A50[arg0][0], D_80275A50[arg0][1], D_80275A50[arg0][2]);
        func_80247934();
        func_802478C0(0, 0, 0);
        func_80247934();
    }
    while(1);
}

void func_802479E4(s32 arg0) {
    func_802478C0(D_80275A50[arg0][0], D_80275A50[arg0][1], D_80275A50[arg0][2]);
    func_80247934();
    func_802478C0(0, 0, 0);
    func_80247934();
}

void func_80247A40(s32 arg0) {
    func_802478C0(D_80275A50[arg0][0], D_80275A50[arg0][1], D_80275A50[arg0][2]);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247A7C.s")
#else
void func_80247A7C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 r, s32 g, s32 b) {
    s32 var_s3;
    s32 sp48;
    u32 sp44;
    u32 sp40;
    s32 temp_lo;
    s32 temp_s1;
    s32 temp_t8;
    s32 var_s0;
    u32 temp_t4;
    u32 var_s4;

    var_s4 = 0x10000000;
    sp44 = D_80275A7C[arg1][0];
    sp40 = D_80275A7C[arg1][1];
    for(sp48 = 0; sp48 != 5; sp48++){
        temp_lo = sp48 * arg2;
        temp_s1 = arg2 + arg3 + arg3;
        for(var_s3 = 0; var_s3 != sp44; var_s3++){
            var_s4 >>= 1;
            if (sp40 & var_s4) {
                func_80247750(r, g, b);
                func_80247818((D_80275BC4 + arg2*var_s3) - arg3, (D_80275BC8 + temp_lo) - arg3, temp_s1, temp_s1);
            } else {
                if (arg4 != 0) {
                    func_80247750(0, 0, 0);
                }
                func_80247818((D_80275BC4 + arg2*var_s3) - arg3, (D_80275BC8 + temp_lo) - arg3, temp_s1, temp_s1);
            }
        }
    }
    if (arg3 == 0) {
        D_80275BC4 += (sp44 * arg2) + 2;
    }
}
#endif


void func_80247C20(void) {
    s16 *var_v0;
    s16 *var_v1;
    s32 temp_lo;
    void *temp_a0;
    s32 i;

    if (D_80275BE4 == 0) {
        D_80275BE4 = func_8023DB5C();
        return;
    }
    if (func_8023DB5C() != D_80275BE4) {
        D_80275BE0 = FALSE;
        D_80275BE4 = func_8023DB5C();
    }

    if (D_80275BE0) {
        for(i = 0; i < D_80276588 * D_8027658C; i++){
                D_803A5D00[0][i] = 0;
                D_803A5D00[1][i] = 0;
        }
        osWriteBackDCacheAll();
    }
}

void func_80247CEC(s32 arg0, s32 arg1, s32 arg2) {
    func_80247A7C(arg0, arg1, arg2, 1, 1, 0, 0, 0);
    func_80247A7C(arg0, arg1, arg2, 0, 1, D_80275A50[D_80275A74[arg0]][0], D_80275A50[D_80275A74[arg0]][1], D_80275A50[D_80275A74[arg0]][2]);
}

void func_80247D80(s32 arg0, s32 arg1, s32 arg2) {
    s16 temp_v0;
    s32 var_a1;
    s32 var_s0;
    s32 var_s1;

    D_80275BC4 = D_80275BBC;
    D_80275BD4 = arg2;
    if (arg1 < 0) {
        func_80247CEC(arg0, 0x26, arg2);
        arg1 *= -1;
    }
    
    for(var_s0 = 1000000000; var_s0 >= 10 && arg1 < var_s0; var_s0 /= 10){
        continue;
    }

    for(var_s0 = var_s0; var_s0 >= 10; var_s0 /= 10){
        for(var_a1 = 0; arg1 >= var_s0; var_a1++){
            arg1 -= var_s0;
        }
        func_80247CEC(arg0, var_a1, arg2);
    }

    func_80247CEC(arg0, arg1, arg2);
    func_8024856C();
    if (arg2 == 7) {
        D_80275BD8 = D_80275BC4;
        D_80275BDC = 0;
    }
    else if (D_80275BC4 >= D_80275BDC) {
        D_80275BDC = D_80275BC4;
    }
}

void func_80247F24(s32 arg0, s32 arg1) {
    D_80275BD0 = 0;
    D_80275BCC = arg0;
    D_80275BBC = 0xE;
    D_80275BC8 = 0xA;
    func_80247D80(arg0, arg1, 7);
    func_802484D0();
    D_80275BC0 = D_80275BC8;
    D_80275BDC = D_80275BBC;
    D_80275BE0 = 1;
}


void func_80247F9C(s32 arg0){
    func_80247D80(D_80275BCC, arg0, 2);
    func_802484D0();
}

void func_80247FD0(u32 arg0) {
    s32 var_s0;

    D_80275BC4 = D_80275BBC;
    D_80275BD4 = 2;
    func_80247CEC(D_80275BCC, 0x25, 2);
     var_s0 = (arg0 >= 0x01000000U) ? 0x1C
            : (arg0 >= 0x10000U) ? 0x14
            :0xC;
    if (var_s0 >= 0) {
        do {
            func_80247CEC(D_80275BCC, ((s32) arg0 >> var_s0) & 0xF, 2);
            var_s0 -= 4;
        } while (var_s0 >= 0);
    }
    func_80248520();
}

void func_80248098(f32 arg0) {
    f32 var_f22;
    s32 var_s0;

    D_80275BC4 = D_80275BBC;
    D_80275BD4 = 2;
    if (arg0 < 0.0f) {
        func_80247CEC(D_80275BCC, 0x26, 2);
        arg0 *= -1.0f;
    }
    var_f22 = 1e+09;
    while((var_f22 >= 10.0f) && (arg0 < var_f22)) {
        var_f22 /= 10.0f;
    }
    while (1e-09 <= var_f22) {
            if ((0.09 < var_f22) && (var_f22 < 0.11)) {
                func_80247CEC(D_80275BCC, 0x24, 2);
            }
            
            var_s0 = 0;
            while (var_f22 <= arg0) {
                    arg0 -= var_f22;
                    var_s0 += 1;
            }
            func_80247CEC(D_80275BCC, var_s0, 2);
            var_f22 /= 10.0f;
    }
    func_80248520();
}

s32 func_8024824C(s32 arg0) {
    if ((arg0 >= (s32) D_80275BE8[0]) && ((s32) D_80275BE8[1] >= arg0)) {
        return (arg0 - D_80275BE8[0]) + 0xA;
    }

    if ((arg0 >= (s32) D_80275BE8[2]) && ((s32) D_80275BE8[3] >= arg0)) {
        return (arg0 - D_80275BE8[2]) + 0xA;
    }

    if ((arg0 >= (s32) D_80275BE8[4]) && ((s32) D_80275BE8[5] >= arg0)) {
        return (arg0 - D_80275BE8[4]);
    }

    if (arg0 == D_80275BE8[6]) {
        return 0x24;
    }
    if (arg0 == D_80275BE8[7]) {
        return 0x25;
    }
    if (arg0 == D_80275BE8[8]) {
        return 0x26;
    }
    if (arg0 == D_80275BE8[9]) {
        return 0x27;
    }
    return 0x27;
}


#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248330.s")
#else
void func_80248330(u8 *arg0){
    s32 i;
    s32 val;

    D_80275BC4 = D_80275BBC;
    D_80275BD4 = 2;
    i = 0;
    val = arg0[i];
    while(arg0[i] != 0){
        val = arg0[i];
        func_8024824C(val);
        func_80247CEC(D_80275BCC, val, 2);
        i++;
    }
    func_80248520();
}
#endif

void func_802483B8(void){
    D_80275BD0 = 1;
    do{}while(1);
}

void func_802483D8(void){
    s32 i;
    D_80275BD0 = 1;
    for(i = 30000000; i != 0; i--){}
    D_80275BD0 = 0;
}

void func_80248404(s32 arg0){
    s32 i;

    D_80275BD0 = 1;
    while(arg0 != 0){
        for(i = 30000000; i != 0; i--){}
        arg0--;
    }
    D_80275BD0 = 0;
}

void func_80248444(s32 arg0) {
    D_80275BC8 += arg0;
    if (D_80275BC8 >= 0xCD) {
        D_80275BBC = D_80275BDC + 4;
        D_80275BC4 = D_80275BBC;
        D_80275BC8 = (D_80275BD8 < D_80275BC4) ? 0xA : D_80275BC0;
        D_80275BDC = 0;
    }
}

void func_802484D0(void){
    func_80248444( D_80275BD4*5 + 2);
}

void func_80248500(void){
    func_80248444(2);
}

void func_80248520(void){
    func_8024856C();
    if(D_80275BC4 >= D_80275BDC){
        D_80275BDC = D_80275BC4;
    }
    func_802484D0();
}

void func_8024856C(void) {
    s16 sp1E;
    s16 temp_v0;

    sp1E = D_80275BC4--;
    func_80247CEC(D_80275BCC, 0x27, D_80275BD4);
    D_80275BC4 = sp1E;
}


s32 func_802485BC(void){
    return D_80275BD0;
}

void func_802485C8(UNK_TYPE(s32) arg0){

}

//BREAK?
#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/draw_sprite_ci4.s")
#else
void draw_sprite_ci4(s32 x, s32 y, BKSprite *sprite, s32 frame, s32 alpha_enabled) {
    BKSpriteFrame *sprite_frame;
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
    if (alpha_enabled == 0) {
        set_prim_color(0, 0, 0x80);
        draw_prim_rect(x, y, sprite_frame->w, sprite_frame->h);
    }

    palette = (u16 *)(sprite_frame + 1);
    for(tmem = palette; (s32)tmem % 8; tmem++);
    palette = tmem;
    chunk = (BKSpriteTextureBlock *)(palette + 0x10);
    for(i_chunk = 0; i_chunk < sprite_frame->chunkCnt; i_chunk++){
        for(tmem = (u16 *)(chunk + 1); (s32)tmem % 8; tmem++);

        for(iy = 0; iy < chunk->h; iy++){
            for(ix = 0; ix < chunk->w; ix += 2){
                indx1 = (*tmem >> 4) & 0xF;
                indx2 = (*tmem >> 0) & 0xF;
                fb_x = chunk->x + x + ix;
                if (0 <= fb_x && fb_x < D_80276588) {
                    fb_y = chunk->y + y + iy;
                    if ((fb_y >= 0) && (fb_y < D_8027658C)) {
                        pxl_ptr = framebuffer + fb_x + (fb_y * D_80276588);
                        color1 = palette[indx1];
                        if (color1 & 1) {
                            *pxl_ptr = color1;
                        } else if (!alpha_enabled) {
                            *pxl_ptr = 1U;
                        }
                        color2 = palette[indx2];
                        if (color2 & 1) {
                            *(pxl_ptr + 1) = color2;
                        } else if (!alpha_enabled) {
                            *(pxl_ptr + 1) = 1U;
                        }
                    }
                }
                tmem++;
            }
        }
        chunk = (BKSpriteTextureBlock *) tmem;
    }
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/draw_sprite_ci8.s")

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

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/draw_sprite_i4.s")
#else
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
                        fb_pxl_ptr = framebuffer_ptr + fb_x + (fb_y * D_80276588);
                        p1 = (*tmem >> 4);
                        p2 = (*tmem & 0xF);
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
#endif

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/draw_sprite_ia4.s")
#else
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
                        fb_pxl_ptr = framebuffer_ptr + fb_x + (fb_y * D_80276588);
                        p1 = (*tmem >> 4);
                        p2 = (*tmem & 0xF);
                        p1_i = p1 & 0xE;
                        p1_a = p1 & 1;
                        p2_i = p2 & 0xE;
                        p2_a = p2 & 1;
                        if (p1 & 1) {
                            *fb_pxl_ptr = (p1_i << 0xC) | (p1_i << 0x7) | (p1_i << 0x2) | (p1 & 1);
                        } else if (!aplha_enabled) {
                            *fb_pxl_ptr = 1;
                        }
                        if (p2_a) {
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
#endif

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

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/draw_sprite_rgba32.s")
#else
void draw_sprite_rgba32(s32 x, s32 y, BKSprite *sprite, s32 frame, s32 alpha_enabled) {
    s32 i_chunk;
    BKSpriteFrame *sprite_frame;
    BKSpriteTextureBlock *chunk_ptr;
    u32 *var_t4;
    s16 temp_v0;
    s16 var_v1;
    s32 temp_a1;
    s32 temp_a2;
    u16 *temp_s5;
    s32 temp_t1;
    s32 alpha;
    s32 temp_v0_5;
    s32 var_s0;
    s32 var_t2;
    u16 *temp_a3;
    u16 p1_a;
    u32 temp_v1;
    s32 red8;
    s32 green8;
    s32 blue8;

    temp_s5 = &D_803A5D00[D_802806EC][0];
    sprite_frame = spriteGetFramePtr(sprite, frame);
    if (!alpha_enabled) {
        set_prim_color(0, 0, 0x80);
        draw_prim_rect(x, y, sprite_frame->w, sprite_frame->h);
    }
    chunk_ptr = (BKSpriteTextureBlock *)(sprite_frame + 1);
    for(i_chunk = 0; i_chunk < sprite_frame->chunkCnt; i_chunk++){
        if( ((chunk_ptr->x >= -5) && (chunk_ptr->x < 0x29))
            && (chunk_ptr->y >= -5) && (chunk_ptr->y < 0x29)
        ) {
            //align
            var_t4 = (u32 *)(chunk_ptr + 1);
            while((s32)var_t4 % 8){var_t4++;}

            for(var_s0 = 0; var_s0 < chunk_ptr->h; var_s0++){
                for(var_t2 = 0; var_t2 < chunk_ptr->w; var_t2++) {
                    temp_a1 = chunk_ptr->x + x + var_t2;
                    if ((temp_a1 >= 0) && (temp_a1 < D_80276588)) {
                        temp_a2 = chunk_ptr->y + y + var_s0;
                        if ((temp_a2 >= 0) && (temp_a2 < D_8027658C)) {
                            temp_v1 = *var_t4;
                            temp_a3 = temp_s5 + temp_a1 + temp_a2 * D_80276588;
                            alpha = _SHIFTR(temp_v1, 0, 8);
                            temp_t0 = *temp_a3;
                            if (alpha != 0) {

                                temp_v0_5 = 0xFF - alpha;
                                red8    = (((_SHIFTR(temp_v1, 24, 8) * alpha) + ((_SHIFTR(temp_t0,  11, 5) << 3) * temp_v0_5)) / 0xFF);
                                green8  = (((_SHIFTR(temp_v1, 16, 8) * alpha) + ((_SHIFTR(temp_t0,  6, 5) << 3)  * temp_v0_5)) / 0xFF);
                                blue8   = (((_SHIFTR(temp_v1, 8, 8) * alpha)  + ((_SHIFTR(temp_t0,  1, 5) << 3)  * temp_v0_5)) / 0xFF);
                                *temp_a3 = _SHIFTL((red8 >> 3), 11, 5)
                                         | _SHIFTL((green8 >> 3), 6, 5)
                                         | _SHIFTL((blue8 >> 3), 1, 5)
                                         | 1;
                            } else if (!alpha_enabled) {
                                *temp_a3 = 0x0001;
                            }
                        }
                    }
                    var_t4++;
                }
            }
            chunk_ptr = (BKSpriteFrame *) var_t4;
        }
    }
}
#endif


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


#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80249F34.s")

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

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_8024A564.s")
#else
void func_8024A564(s32 x, s32 y, u16 *arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6) {
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_a2_3;
    s32 temp_f6;
    s32 temp_f6_2;
    s32 temp_lo;
    s32 temp_t5;
    s32 var_a0;
    s32 var_a2;
    s32 var_t1;
    s32 var_t3;
    s32 var_v0;
    s32 var_v1;
    u16 temp_t8;
    s16 *var_t0;
    s16 *var_t2;

    var_v0 = 0;
    var_v1 = D_80276588;
    var_t0 = &D_803A5D00[D_802806EC][x + y * D_80276588];
    for( var_t1 = (arg4 * arg6) + 0.5; var_t1 != 0; var_t1--){
        var_a2 = ((var_v0 >> 8) * arg3) << 8;
        var_t2 = var_t0;
        var_v0 += (s32) ((f64) (256.0f / arg6) + 0.5);
        for(var_t3 = (arg3 * arg5) + 0.5; var_t3 != 0; var_t3--){
            *var_t2 = arg2[var_a2 >> 8];
            var_a2 += (s32) ((f64) (256.0f / arg5) + 0.5);
            var_t2++;
        }
        var_t0 += D_80276588;
    }
}
#endif

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
