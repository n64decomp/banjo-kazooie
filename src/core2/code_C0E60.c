#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80355C60(f32[3], f32);

void func_80348044(Gfx **gfx, BKSprite* sprite, s32 frame, s32 tmem, s32 rtile, s32 uls, s32 ult, s32 cms, s32 cmt, s32 *width, s32 *height, s32 *frame_width, s32 *frame_height, s32 *texture_x, s32 *texture_y, s32 *textureCount);

#define	rare_gDPLoadMultiBlock(pkt, timg, tmem, rtile, fmt, siz, width, height, \
    uls, ult, \
    pal, cms, cmt, masks, maskt, shifts, shiftt)	\
{									\
	gDPSetTextureImage(pkt, fmt, siz##_LOAD_BLOCK, 1, timg);	\
	gDPSetTile(pkt, fmt, siz##_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0,\
		cmt, maskt, shiftt, cms, masks, shifts);		\
	gDPLoadSync(pkt);						\
	gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, 				\
		(((width)*(height) + siz##_INCR) >> siz##_SHIFT)-1,	\
		CALC_DXT(width, siz##_BYTES)); 				\
	gDPPipeSync(pkt);						\
	gDPSetTile(pkt, fmt, siz, (((width) * siz##_LINE_BYTES)+7)>>3,	\
		tmem, rtile, pal, cmt,					\
		maskt, shiftt, cms, masks, shifts);			\
	gDPSetTileSize(pkt, rtile, \
		(uls),			\
		(ult),			\
		((width)-1) << G_TEXTURE_IMAGE_FRAC,			\
		((height)-1) << G_TEXTURE_IMAGE_FRAC)			\
}

#define	rare_gDPLoadMultiBlock_4b(pkt, timg, tmem, rtile, fmt, width, height, \
        uls, ult, \
		pal, cms, cmt, masks, maskt, shifts, shiftt)		\
{									\
	gDPSetTextureImage(pkt, fmt, G_IM_SIZ_16b, 1, timg);		\
	gDPSetTile(pkt, fmt, G_IM_SIZ_16b, 0, tmem, G_TX_LOADTILE, 0,	\
		cmt, maskt, shiftt, cms, masks, shifts);		\
	gDPLoadSync(pkt);						\
	gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0,				\
		(((width)*(height)+3)>>2)-1,				\
		CALC_DXT_4b(width));					\
	gDPPipeSync(pkt);						\
	gDPSetTile(pkt, fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), tmem,	\
		rtile, pal, cmt, maskt, shiftt, cms, masks,		\
		shifts);						\
	gDPSetTileSize(pkt, rtile, \
		(uls),			\
		(ult),			\
		((width)-1) << G_TEXTURE_IMAGE_FRAC,			\
		((height)-1) << G_TEXTURE_IMAGE_FRAC)			\
}

/* .bss */
s32 D_80386070;
s32 D_80386074;
s32 D_80386078;
s32 D_8038607C;
s32 D_80386080;
s32 D_80386084;
s32 D_80386088;
s32 D_8038608C;
s32 D_80386090;
s32 D_80386094;
s32 D_80386098;
s32 D_8038609C;
s32 D_803860A0;
s32 D_803860A4;
s32 D_803860A8;
s32 D_803860AC;
s32 spriteRenderHasPalette;
s32 spriteRender1PrimMode;

/* .code */
void func_80347DF0(Struct81s *arg0){
    Actor *actor;
    actor = func_802C937C(arg0->actor_id, arg0->position);
    actor->unk54 = 3.0f;
    func_803333DC(arg0, actor);
}

void func_80347E34(Struct81s *arg0){
    __spawnQueue_add_1((GenFunction_1) func_80347DF0, reinterpret_cast(s32, arg0));
}

void func_80347E60(Struct81s *arg0) {
    Actor *actor;
    f32 temp_f0;
    f32 temp_f26;
    f32 var_f12;
    s32 var_s0;

    actor = marker_getActor(arg0->marker);
    if (actor->unk54 > 0.0) {
        temp_f0 = sinf((actor->unk54 * M_PI) / 3.0);
        if (temp_f0 < 0.0f) {
            var_f12 = 0.0f;
        } else {
            var_f12 = temp_f0;
        }
        temp_f26 = gu_sqrtf(var_f12);
        for(var_s0 = 0; var_s0 != 2; var_s0++){
            if (((randf() * 3.0f) / 2) < temp_f26) {
                func_80355C60(actor->position, 1.0f);
            }
        }
        actor->unk54 -= time_getDelta();
    }
}

void func_80347FA4(s32 arg0, s32 arg1, s32 arg2, s32 tmem){}

void func_80347FB8(s32 arg0){}

void func_80347FC0(Gfx **gfx, BKSprite *sprite, s32 frame, s32 tmem, s32 rtile, s32 uls, s32 ult, s32 cms, s32 cmt, s32 *width, s32 *height){
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C = -1;

    func_80348044(gfx, sprite, frame, tmem, rtile, uls, ult, cms, cmt, width, height,
        &sp5C, &sp58, &sp54, &sp50, &sp4C
    );
}

void func_80348044(Gfx **gfx, BKSprite* sprite, s32 frame, s32 tmem, s32 rtile, s32 uls, s32 ult, s32 cms, s32 cmt, s32 *width, s32 *height, s32 *frame_width, s32 *frame_height, s32 *texture_x, s32 *texture_y, s32 *textureCount) {
    BKSpriteFrame *sprite_frame;
    s32 palette_addr;
    BKSpriteTextureBlock *texture_block;
    s32 timg;
    s32 sp144;
    s32 var_a0;
    s32 chunk_count;
    s32 masks;
    s32 var_v0;
    s32 maskt;

    sprite_frame = spriteGetFramePtr(sprite, frame);
    *frame_width = (s32) sprite_frame->w;
    *frame_height = (s32) sprite_frame->h;
    if (*textureCount == -1) {
        *textureCount = (s32) sprite_frame->chunkCnt;
    }
    (*textureCount)--;
    chunk_count = (*textureCount);
    if (sprite->type & SPRITE_TYPE_CI4) {
        for(palette_addr = (s32)(sprite_frame + 1); palette_addr % 8; palette_addr++);
        gDPSetTextureLUT((*gfx)++, G_TT_RGBA16);
        gDPLoadTLUT_pal16((*gfx)++, 0, palette_addr);
        spriteRenderHasPalette = TRUE;
        spriteRender1PrimMode = FALSE;
        D_80386074 = 0; 
        texture_block = (BKSpriteTextureBlock *)(palette_addr + 0x20);
        D_80386098 = D_8038607C = 0;
    } else if (sprite->type & SPRITE_TYPE_CI8) {
        gDPPipelineMode((*gfx)++, G_PM_1PRIMITIVE);
        for(palette_addr = (s32)(sprite_frame + 1); palette_addr % 8; palette_addr++);
        spriteRender1PrimMode = spriteRenderHasPalette = TRUE;
        D_80386074 = NULL;
        D_8038607C = 0;
        texture_block = (BKSpriteTextureBlock *)(palette_addr + 0x200);
        D_80386098 = 0;
        for(var_a0 = 0; var_a0 < chunk_count; var_a0++) {
            texture_block = (s32)texture_block + (texture_block->w * texture_block->h) + sizeof(BKSpriteTextureBlock);
        }
        *texture_x = texture_block->x;
        *texture_y = texture_block->y;
        gDPSetTextureLUT((*gfx)++, G_TT_RGBA16);
        gDPLoadTLUT_pal256((*gfx)++, palette_addr);
    } else {
        texture_block = (BKSpriteTextureBlock *)(sprite_frame + 1);
        spriteRenderHasPalette = FALSE;
    }

    if ((D_8038607C == 0) || (tmem == D_80386078)) {
        D_80386078 = tmem;
        D_80386070 = sprite_frame;
        D_80386080 = uls;
        D_80386084 = ult;
        D_80386088 = rtile;
        sp144 = 0;
    } else {
        D_80386094 = tmem;
        D_80386074 = sprite_frame;
        D_8038609C = uls;
        D_803860A0 = ult;
        D_803860A4 = rtile;
        sp144 = 1;
    }

    *width = (s32) texture_block->w;
    *height = (s32) texture_block->h;
    for(timg = (s32)(texture_block + 1); timg % 8; timg++);

    if (sp144 == 0) {
        D_8038608C = *width;
        D_80386090 = *height;
        D_8038607C = D_8038608C * D_80386090;
    } else {
        D_803860A8 = *width;
        D_803860AC = *height;
        D_80386098 = D_803860A8 * D_803860AC;
    }

    var_v0 = *width - 1;
    if ((*width & 7) == 0) {
        masks = 0;
        while (var_v0 != 0) {
            masks++;
            var_v0 >>= 1;
        }
    } else {
        masks = 0;
    }

    maskt = *height - 1;
    var_v0 = maskt;
    if ((*height & 7) == 0) {
        maskt = 0;
        while (var_v0 != 0) {
            maskt++;
            var_v0 >>= 1;
        }
    } else {
        maskt = 0;
    }

    if ( sprite->type & SPRITE_TYPE_I4) {
        rare_gDPLoadMultiBlock_4b((*gfx)++, timg, tmem, rtile, G_IM_FMT_I, *width, *height, uls, ult, 0, cms, cmt, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
        if (sp144 == 0) {
            D_8038607C = (s32) D_8038607C >> 4;
        } else {
            D_80386098 = (s32) D_80386098 >> 4;
        }
    } else if (sprite->type & SPRITE_TYPE_IA4) {
        rare_gDPLoadMultiBlock_4b((*gfx)++, timg, tmem, rtile, G_IM_FMT_IA, *width, *height, uls, ult, 0, cms, cmt, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
        if (sp144 == 0) {
            D_8038607C = (s32) D_8038607C >> 4;
        } else {
            D_80386098 = (s32) D_80386098 >> 4;
        }
    } else if (sprite->type & SPRITE_TYPE_I8) {
        rare_gDPLoadMultiBlock((*gfx)++, timg, tmem, rtile, G_IM_FMT_I, G_IM_SIZ_8b, *width, *height, uls, ult, 0, cms, cmt, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
        if (sp144 == 0) {
            D_8038607C = (s32) D_8038607C >> 3;
        } else {
            D_80386098 = (s32) D_80386098 >> 3;
        }
    } else if (sprite->type & SPRITE_TYPE_IA8) {
       rare_gDPLoadMultiBlock((*gfx)++, timg, tmem, rtile, G_IM_FMT_IA, G_IM_SIZ_8b, *width, *height, uls, ult, 0, cms, cmt, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
        if (sp144 == 0) {
            D_8038607C = (s32) D_8038607C >> 3;
        } else {
            D_80386098 = (s32) D_80386098 >> 3;
        }
    } else if (sprite->type & SPRITE_TYPE_RGBA16) {
        rare_gDPLoadMultiBlock((*gfx)++, timg, tmem, rtile, G_IM_FMT_RGBA, G_IM_SIZ_16b, *width, *height, uls, ult, 0, cms, cmt, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
        if (sp144 == 0) {
            D_8038607C = (s32) D_8038607C >> 2;
        } else {
            D_80386098 = (s32) D_80386098 >> 2;
        }
    } else if (sprite->type & SPRITE_TYPE_RGBA32) {
        rare_gDPLoadMultiBlock((*gfx)++, timg, tmem, rtile, G_IM_FMT_RGBA, G_IM_SIZ_32b, *width, *height, uls, ult, 0, cms, cmt, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
        if (sp144 == 0) {
            D_8038607C = (s32) D_8038607C >> 1;
        } else {
            D_80386098 = (s32) D_80386098 >> 1;
        }
    } else if (sprite->type & SPRITE_TYPE_CI4) {
        rare_gDPLoadMultiBlock_4b((*gfx)++, timg, tmem, rtile, G_IM_FMT_RGBA, *width, *height, uls, ult, 0, cms, cmt, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
        D_8038607C = D_8038607C >> 4;
    } else if (sprite->type & SPRITE_TYPE_CI8) {
        rare_gDPLoadMultiBlock((*gfx)++, timg, tmem, rtile, G_IM_FMT_CI, G_IM_SIZ_8b, *width, *height, uls, ult, 0, cms, cmt, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
        D_8038607C = (s32) D_8038607C >> 3;
    }
    if( D_8038607C != 0 
        && D_80386098 != 0
        && (D_80386094 < (D_80386078 + D_8038607C))
    ) {
        D_80386074 = NULL;
        D_80386098 = 0;
    }
}

void func_80349AD0(void){
    D_80386074 = D_80386070 = 0;
    D_80386098 = D_8038607C = 0;
    D_80386094 = D_80386078 = -1;
    spriteRenderHasPalette = FALSE;
}

void func_80349B1C(Gfx **gfx) {
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;

    if (spriteRenderHasPalette) {
        gDPPipeSync((*gfx)++);
        gDPSetTextureLUT((*gfx)++, G_TT_NONE);
        spriteRenderHasPalette = FALSE;
        if (spriteRender1PrimMode) {
            gDPPipelineMode((*gfx)++, G_PM_NPRIMITIVE);
            spriteRender1PrimMode = FALSE;
        }
    }
}
