#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

void func_803382D8(s32 arg0);
void codeAEDA0_setSpriteDrawMode(s32 arg0);
void spriteRender_set1Primative(bool boolean);
void func_803382FC(s32 arg0);
void func_80338308(s32 arg0, s32 arg1);
BKSpriteTextureBlock *func_8033EFB0(Struct84s *arg0, s32 arg1);

/* .data */
Gfx D_80370260[] = {
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPEndDisplayList()
};

Gfx D_80370290[] = {
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2),
    gsSPEndDisplayList()
};

Gfx D_803702C0[] = {
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x80),
    gsDPSetRenderMode(Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_XLU | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA), Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_XLU | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)),
    gsSPEndDisplayList()
};


Gfx D_80370308[] = {
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPEndDisplayList()
};

u8 D_80370338[4] = {1, 0, 0, 0};
u8 D_8037033C = 0;

/* .bss */
s32 sPrimColorR;
s32 sPrimColorG;
s32 sPrimColorB;
s32 D_8038361C;
s32 D_80383620;
s32 D_80383624;
s32 D_80383628;
s32 D_8038362C;
u32 D_80383630;
u32 D_80383634;
u32 D_80383638;
s32 D_8038363C;
s32 D_80383640;
s32 D_80383644;

void spriteRender_drawWithSegment(Gfx **gfx, Vtx **vtx, BKSprite *sprite, u32 frame, u32 segment);
void func_803380F8(Gfx **gfx, Mtx **mtx, f32 arg2[3]);
void func_803381B4(Gfx **gfx, Mtx **mtx, f32 arg2[3]);

/* .code */
void codeAEDA0_drawSprite(Gfx **gfx){
    gDPPipeSync((*gfx)++);
    if (D_80370338[0] == 0) {
        gDPSetColorDither((*gfx)++, G_CD_DISABLE);
    }//L80335D7C
    switch(D_80383634 + 1){
    case 0:
        return;
        
    case 15:
        gSPDisplayList((*gfx)++, D_803702C0);
        gDPSetPrimColor((*gfx)++, 0, 0, sPrimColorR, sPrimColorG, sPrimColorB, 0xFF);
        return;

    case 12:
        gSPDisplayList((*gfx)++, D_80370290);
        gDPSetCombineMode((*gfx)++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor((*gfx)++, 0, 0, sPrimColorR, sPrimColorG, sPrimColorB, 0xFF);
        return;

    case 10:
        gSPDisplayList((*gfx)++, D_80370260);
        gDPSetCombineLERP((*gfx)++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor((*gfx)++, 0, 0, sPrimColorR, sPrimColorG, sPrimColorB, D_8038363C);
        gDPSetEnvColor((*gfx)++, D_80383620, D_80383624, D_80383628, 0xFF);
        return;

    case 16:
        gSPDisplayList((*gfx)++, D_80370290);
        gDPSetCombineLERP((*gfx)++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor((*gfx)++, 0, 0, sPrimColorR, sPrimColorG, sPrimColorB, D_8038363C);
        gDPSetEnvColor((*gfx)++, D_80383620, D_80383624, D_80383628, 0xFF);
        return;

    case 8:
        if (D_8038361C != 0) {
            gSPDisplayList((*gfx)++, D_80370308);
            gDPSetCombineLERP((*gfx)++, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, COMBINED, ENVIRONMENT, COMBINED, 0, 0, 0, COMBINED);
            gDPSetEnvColor((*gfx)++, D_8038361C, D_8038361C, D_8038361C, 0xFF);
        } else {
            gSPDisplayList((*gfx)++, D_80370260);
            gDPSetCombineMode((*gfx)++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        }
        gDPSetPrimColor((*gfx)++, 0, 0, sPrimColorR, sPrimColorG, sPrimColorB, D_8038363C);
        return;

    case 7:
        if (D_8038361C != 0) {
            gSPDisplayList((*gfx)++, D_80370308);
            gDPSetCombineLERP((*gfx)++, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, COMBINED, PRIMITIVE_ALPHA, COMBINED, 0, 0, 0, COMBINED);
            gDPSetPrimColor((*gfx)++, 0, 0, sPrimColorR, sPrimColorG, sPrimColorB, D_8038361C);
        } else {
            gSPDisplayList((*gfx)++, D_80370260);
            gDPSetCombineMode((*gfx)++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
            gDPSetPrimColor((*gfx)++, 0, 0, sPrimColorR, sPrimColorG, sPrimColorB, 0xFF);
        }
        return;

    case 6:
        gSPDisplayList((*gfx)++, D_80370260);
        gDPSetCombineMode((*gfx)++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor((*gfx)++, 0, 0, sPrimColorR, sPrimColorG, sPrimColorB, D_8038363C);
        return;

    case 13:
        gSPDisplayList((*gfx)++, D_80370290);
        gDPSetCombineMode((*gfx)++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor((*gfx)++, 0, 0, sPrimColorR, sPrimColorG, sPrimColorB, D_8038363C);
        return;

    case 5:
        gSPDisplayList((*gfx)++, D_80370260);
        gDPSetCombineMode((*gfx)++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor((*gfx)++, 0, 0, sPrimColorR, sPrimColorG, sPrimColorB, 0xFF);
        return;

    case 9:
        gSPDisplayList((*gfx)++, D_80370260);
        gDPSetCombineMode((*gfx)++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor((*gfx)++, 0, 0, D_80383630, D_80383630, D_80383630, D_8038363C);
        return;

    case 14:
        gSPDisplayList((*gfx)++, D_80370290);
        gDPSetCombineMode((*gfx)++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor((*gfx)++, 0, 0, D_80383630, D_80383630, D_80383630, D_8038363C);
        return;

    case 1:
        gSPDisplayList((*gfx)++, D_80370260);
        gDPSetCombineMode((*gfx)++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor((*gfx)++, 0, 0, D_80383630, D_80383630, D_80383630, 0xFF);
        return;

    case 2:
        gSPDisplayList((*gfx)++, D_80370260);
        gDPSetCombineLERP((*gfx)++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor((*gfx)++, 0, 0, 0, 0, 0, D_8038363C);
        return;

    case 11:
        gSPDisplayList((*gfx)++, D_80370290);
        gDPSetCombineLERP((*gfx)++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor((*gfx)++, 0, 0, 0, 0, 0, D_8038363C);
        return;

    case 4:
        gSPDisplayList((*gfx)++, D_80370260);
        gDPSetCombineMode((*gfx)++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor((*gfx)++, 0, 0, D_80383620, D_80383624, D_80383628, D_8038362C);
        return;

    default://L80336814
        gSPDisplayList((*gfx)++, D_80370260);
        gDPSetCombineLERP((*gfx)++, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE);
        gDPSetPrimColor((*gfx)++, 0, 0, 0, 0, 0, 0xFF);
        return;
    }
}

void codeAEDA0_postDrawSprite( Gfx **gfx )
 {
     /* Turn off texturing */
     gDPPipeSync((*gfx)++);
     if (D_80370338[0] == 0) {
        gDPSetColorDither((*gfx)++, G_CD_MAGICSQ);
        D_80370338[0] = 1;
     }

     if(D_80383634 == 0x0E){
         gDPSetAlphaCompare((*gfx)++, G_AC_NONE);
     }
 }

void spriteRender_draw(Gfx **gfx, Vtx **vtx, BKSprite *sp, u32 frame){
    spriteRender_drawWithSegment(gfx, vtx, sp, frame, 0);
}

void spriteRender_drawWithSegment(Gfx **gfx, Vtx **vtx, BKSprite *sprite, u32 frame, u32 segment) {
    s32 ix;
    s32 pixel_size_nibbles; //sp1C0
    s32 sp1BC;
    Vtx *var_a3;
    Gfx *sp1B4;
    Vtx *sp1B0;
    u32 palette_mem;
    u8 *tmem;
    BKSpriteTextureBlock *var_t2;
    f32 temp_f0;
    f32 temp_f2;
    Gfx *var_a2;
    s32 temp_a2_2;
    s32 i_vtx;
    BKSpriteFrame *frame_ptr; //sp18c
    s32 var_t1_8;
    Vtx *vtx_start; //sp184
    s32 temp_ra;
    s32 iy;
    
    vtx_start = *vtx;

    //get pize size in nibs
    func_80349AD0();
    if (sprite->type & SPRITE_TYPE_CI4) {
        pixel_size_nibbles = 1;
    } else if (sprite->type & SPRITE_TYPE_CI8) {
        pixel_size_nibbles = 2;
    } else if (sprite->type & SPRITE_TYPE_I8){
        pixel_size_nibbles = 2;
    } else if (sprite->type & SPRITE_TYPE_IA8){
        pixel_size_nibbles = 2;
    } else if (sprite->type & SPRITE_TYPE_RGBA16) {
        pixel_size_nibbles = 4;
    } else if (sprite->type & SPRITE_TYPE_RGBA32){
        pixel_size_nibbles = 8;
    }
    codeAEDA0_drawSprite(gfx);

    //set to 1Prim if using
    if(D_80383638 || (sprite->type & SPRITE_TYPE_CI8)){
        gDPPipelineMode((*gfx)++, G_PM_1PRIMITIVE);
    }
    
    frame_ptr = sprite_getFramePtr(sprite, frame);
    
    //load palette in indexed pixels
    var_t2 = (BKSpriteTextureBlock *)(frame_ptr + 1);
    if (sprite->type & SPRITE_TYPE_CI4) {
        gDPSetTextureLUT((*gfx)++, G_TT_RGBA16);
        palette_mem = ALIGN(frame_ptr + 1, 8);
        gDPLoadTLUT_pal16((*gfx)++, 0, palette_mem);
        var_t2 = (BKSpriteTextureBlock *)(palette_mem + 0x20);
    } else if (sprite->type & SPRITE_TYPE_CI8) {
        gDPSetTextureLUT((*gfx)++, G_TT_RGBA16);
        palette_mem = ALIGN(frame_ptr + 1, 8);
        gDPLoadTLUT_pal256((*gfx)++, palette_mem);
        var_t2 = (BKSpriteTextureBlock *)(palette_mem + 0x200);
    }
    
//start new vtx seg
    i_vtx = 0;
    var_a3 = *vtx;
    sp1B4 = *gfx;
    sp1B0 = var_a3;
    if(segment != 0){
        gSPVertex((*gfx)++, SEGMENT_ADDR(segment, (s32)sp1B0 - (s32)vtx_start), 0, 0);
    }else{
        gSPVertex((*gfx)++, sp1B0, 0, 0);
    }
    //for each texture (chunk) in frame
    // sp1B4 = sp1B4;
    for(sp1BC = 0; sp1BC < frame_ptr->chunkCnt; sp1BC++){
        temp_ra = var_t2->h;
        tmem = (u8*)ALIGN(var_t2 + 1, 8); //align

        //load texture block
        if (sprite->type & SPRITE_TYPE_RGBA16) {
            gDPLoadTextureBlock((*gfx)++, tmem, G_IM_FMT_RGBA, G_IM_SIZ_16b, var_t2->w, temp_ra, NULL, 0, 0, 0, 0, 0, 0);
        } else if (sprite->type & SPRITE_TYPE_RGBA32) {
            gDPLoadTextureBlock((*gfx)++, tmem, G_IM_FMT_RGBA, G_IM_SIZ_32b, var_t2->w, temp_ra, NULL, 0, 0, 0, 0, 0, 0);
        } else if (sprite->type & SPRITE_TYPE_CI4) {
            gDPLoadTextureBlock_4b((*gfx)++, tmem, G_IM_FMT_CI, var_t2->w, temp_ra, NULL, 0, 0, 0, 0, 0, 0);
        } else if (sprite->type & SPRITE_TYPE_CI8) {
            gDPLoadTextureBlock((*gfx)++, tmem, G_IM_FMT_CI, G_IM_SIZ_8b, var_t2->w, temp_ra, NULL, 0, 0, 0, 0, 0, 0);
        }else if (sprite->type & SPRITE_TYPE_IA8) {
            gDPLoadTextureBlock((*gfx)++, tmem, G_IM_FMT_CI, G_IM_SIZ_8b, var_t2->w, temp_ra, NULL, 0, 0, 0, 0, 0, 0);
        } else if (sprite->type & SPRITE_TYPE_I8) {
            gDPLoadTextureBlock((*gfx)++, tmem, G_IM_FMT_I, G_IM_SIZ_8b, var_t2->w, temp_ra, NULL, 0, 0, 0, 0, 0, 0);
        }

        //generate vtx coords for texture
        gSP2Triangles((*gfx)++, i_vtx, i_vtx + 1, i_vtx + 3, i_vtx, i_vtx, i_vtx + 3, i_vtx + 2, i_vtx);
         temp_f0 = ((f32) D_80383640 / (f32) frame_ptr->w);
         temp_f2 = ((f32) D_80383644 / (f32) frame_ptr->h);
        temp_a2_2 = var_t2->x - frame_ptr->unk0;
        var_t1_8 = (frame_ptr->unk2 - var_t2->y);
        for(iy = 0; iy < 2; iy++){
            for(ix = 0; ix < 2; ix++){
                var_a3->v.ob[0] = (s32)((temp_a2_2 + (var_t2->w - 1) * ix) * temp_f0);
                var_a3->v.ob[1] = (s32)((var_t1_8 +  -(temp_ra - 1) * iy) * temp_f2);
                var_a3->v.ob[2] = 0;
                var_a3->v.tc[0] = 0x20*(2*var_t2->w * ix  - 1);
                var_a3->v.tc[1] = 0x20*(2*temp_ra * (iy^0) - 1);
                *(u32*)&var_a3->v.cn = 0x7F80;
                var_a3++;
            }
        }
        i_vtx += 4;
        //rewrite vtx seg start with correct vtx count
        if (i_vtx == 0x10) {
            i_vtx = 0;
            if(segment != 0){
                gSPVertex(sp1B4, SEGMENT_ADDR(segment, (s32)sp1B0 - (s32)vtx_start), 16, 0);
            }else{
                gSPVertex(sp1B4, sp1B0, 16, 0);
            }
            //start new vtx seg
            sp1B4 = *gfx;
            sp1B0 = var_a3;
            if (segment) {
                gSPVertex((*gfx)++, SEGMENT_ADDR(segment, (s32)sp1B0 - (s32)vtx_start), 0, 0);
            } else {
                gSPVertex((*gfx)++, sp1B0, 0, 0);
            }
        }
        var_t2 = (BKSpriteTextureBlock *)(tmem + ((s32) (var_t2->w * var_t2->h) * pixel_size_nibbles / 2));
    }
    // sp1B4 = reinterpret_cast(Gfx *,sp1B4);
    *vtx = var_a3;
    
    
    //rewrite vtx seg start with correct vtx count
    if (i_vtx > 0) {
        if(segment != 0){
            gSPVertex(sp1B4, SEGMENT_ADDR(segment, (s32)sp1B0 - (s32)vtx_start), i_vtx, 0);
        }else{
            if(1); 
            gSPVertex(sp1B4, sp1B0, i_vtx, 0);
        }
    }
    else {
        //no vtx, overwrite gSPVertex() command;
        *gfx = sp1B4;
    }

    gDPPipeSync((*gfx)++);

    //clear palette if used
    if (( sprite->type & SPRITE_TYPE_CI4) || ( sprite->type & SPRITE_TYPE_CI8)) {
        gDPSetTextureLUT((*gfx)++, G_TT_NONE);
    }

    //restore pipeline to NPrim mode if set to 1Prim
    if ((D_80383638 != 0) || (sprite->type & SPRITE_TYPE_CI8)) {
        gDPPipelineMode((*gfx)++, G_PM_NPRIMITIVE);
    }
    if(sp1B4);
    codeAEDA0_postDrawSprite(gfx);
}

void func_80337B68(Gfx **gfx, Vtx **vtx, Struct84s *texture_list, s32 texture_index) {
    s32 var_s1;
    s32 var_t2;
    s32 var_v1;
    Vtx *start_vtx;
    BKSpriteTextureBlock *txtr_ptr;
    s32 temp_lo;
    s32 var_a0;
    s32 var_a2;
    u16 *tmem;
    s32 i_vtx0;
    s32 size; 

    codeAEDA0_drawSprite(gfx);
    txtr_ptr = func_8033EFB0(texture_list, texture_index);
    start_vtx = *vtx;
    temp_lo = (s32) D_80383644 / 3;
    var_a2 = -((f32) txtr_ptr->x / (f32) txtr_ptr->w) * D_80383640;
    var_a0 = ((f32) txtr_ptr->y / (f32) txtr_ptr->h) * D_80383644;
    
    for(var_s1 = 0,  size = 3; var_s1 < size; var_s1++){
        for(var_t2 = 0; var_t2 < 2; var_t2++){
            for(var_v1 = 0; var_v1 < 2; var_v1++){
                (*vtx)->v.ob[0] = (var_v1 * D_80383640) + var_a2;
                (*vtx)->v.ob[1] =  var_a0 - (var_t2*temp_lo) ;
                (*vtx)->v.ob[2] = 0;
                (*vtx)->v.tc[0] = ((txtr_ptr->w - 1) * var_v1) << 6;
                (*vtx)->v.tc[1] = ((0x1A)*var_t2) << 6;
                *(u32*)((*vtx)->v.cn) = 0x7F80;
                (*vtx)++;
            }
        }
        var_a0 -= temp_lo;
    } 
    
    tmem = (u16*)(txtr_ptr + 1);
    gSPVertex((*gfx)++, start_vtx, 12, 0);

    i_vtx0 = 0;
    for(var_s1 = 0; var_s1 < size; var_s1++){
        gDPLoadTextureBlock((*gfx)++, tmem , G_IM_FMT_RGBA, G_IM_SIZ_16b, txtr_ptr->w, 0x1A + ((var_s1 < 2) ? 1 : 0) , NULL, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSP2Triangles((*gfx)++, 
            i_vtx0 + 0, i_vtx0 + 1, i_vtx0 + 3, i_vtx0, 
            i_vtx0 + 0, i_vtx0 + 3, i_vtx0 + 2, i_vtx0);
        tmem += txtr_ptr->w * 0x1A;
        i_vtx0 += 4;
    }
    codeAEDA0_postDrawSprite(gfx);
}

void func_80338048(Gfx **gfx, Mtx **mtx, Vtx **vtx, f32 arg3[3], Struct84s *arg4, s32 arg5) {
    func_803380F8(gfx, mtx, arg3);
    func_80337B68(gfx, vtx, arg4, arg5);
    gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);
}

void func_803380A0(Gfx **gfx, Mtx **mtx, Vtx **vtx, f32 arg3[3], Struct84s *arg4, s32 arg5) {
    func_803381B4(gfx, mtx, arg3);
    func_80337B68(gfx, vtx, arg4, arg5);
    gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);
}

void func_803380F8(Gfx **gfx, Mtx **mtx, f32 arg2[3]) {
    f32 sp2C[3];
    f32 sp20[3];

    viewport_getPosition_vec3f(sp2C);
    sp20[0] = arg2[0] - sp2C[0];
    sp20[1] = arg2[1] - sp2C[1];
    sp20[2] = arg2[2] - sp2C[2];
    mlMtxSet(viewport_getMatrix());
    func_80252330(sp20[0], sp20[1], sp20[2]);
    mlMtxApply(*mtx);
    gSPMatrix((*gfx)++, (*mtx)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

void func_803381B4(Gfx **gfx, Mtx **mtx, f32 arg2[3]) {
    f32 sp2C[3];
    f32 sp20[3];

    viewport_getPosition_vec3f(sp2C);
    sp20[0] = arg2[0] - sp2C[0];
    sp20[1] = arg2[1] - sp2C[1];
    sp20[2] = arg2[2] - sp2C[2];
    mlMtxSet(viewport_getDefaultMatrix());
    func_80252330(sp20[0], sp20[1], sp20[2]);
    mlMtxApply(*mtx);
    gSPMatrix((*gfx)++, (*mtx)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

void func_80338270(){
    func_803382D8(0xFF);
    codeAEDA0_setSpriteDrawMode(0);
    spriteRender_set1Primative(0);
    func_803382FC(0xFF);
    func_80338308(100, 100);

}

void func_803382B4(s32 arg0, s32 arg1, s32 arg2, s32 arg3){
    D_80383620 = arg0;
    D_80383624 = arg1;
    D_80383628 = arg2;
    D_8038362C = arg3;
}

void func_803382D8(s32 arg0){
    D_80383630 = arg0;
}

void codeAEDA0_setSpriteDrawMode(s32 arg0){
    D_80383634 = arg0;
}

void spriteRender_set1Primative(bool boolean){
    D_80383638 = boolean;
}

void func_803382FC(s32 arg0){
    D_8038363C = arg0;
}

void func_80338308(s32 arg0, s32 arg1){
    D_80383640 = arg0;
    D_80383644 = arg1;
}

void func_8033831C(s32 *arg0, s32 *arg1){
    *arg0 = D_80383640;
    *arg1 = D_80383644;
}

void codeAEDA0_setPrimaryColorRGB(s32 rgb_red, s32 rgb_green, s32 rgb_blue){
    sPrimColorR = rgb_red;
    sPrimColorG = rgb_green;
    sPrimColorB = rgb_blue;
}

void func_80338354(s32 arg0){
    D_8038361C = arg0 / 8 ;
}

void func_80338370(void){
    D_80370338[0] = 0;
}

void func_8033837C(s32 arg0){
    D_8037033C = arg0;
}
