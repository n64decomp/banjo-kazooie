#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include <core1/viewport.h>

f32 time_getDelta(void);
f32 func_802FB0DC(struct8s *);
f32 func_802FB0E4(struct8s *);

extern s32 framebuffer_width; //framebuffer_w
extern s32 framebuffer_height; //framebuffer_h


Gfx D_80369920[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPEndDisplayList(),
};

struct8s D_80369960[] = {
    {
        0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f,
        ITEM_C_NOTE, ASSET_7D9_SPRITE_NOTE, 0x1, 0xA,
        0.6f, 1.0f, 212.0f, -8.0f,
        1.0f, 25.0f, 0.0f, 1.0f,
        NULL, {0}, 0.0f,
    },
    {   0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f,
        ITEM_D_EGGS, ASSET_36D_SPRITE_BLUE_EGG, 0x2, 0x7, 
        0.3f, 1.0f, 212.0f, -8.0f, 
        0.8f, 25.0f, 0.0f, 1.0f, 
        NULL, {0}, 0.0f
    },
    {   0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f,
        ITEM_F_RED_FEATHER, ASSET_580_SPRITE_RED_FEATHER, 0x2, 0xA, 
        0.18f, 1.0f, 212.0f, -8.0f, 
        0.5f, 25.0f, 0.0f, 1.0f, 
        NULL, {0}, 0.0f
    },
    {   0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f, 
        ITEM_10_GOLD_FEATHER, ASSET_6D1_SPRITE_GOLDFEATHTER, 0x2, 0xA, 
        0.22f, -1.0f, 212.0f, -8.0f, 
        0.5f, 25.0f, 0.0f, 1.0f, 
        NULL, {0}, 0.0f
    },
    {   0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f, 
        ITEM_1A_PLAYER_VILE_SCORE, ASSET_7E7_SPRITE_CROC_BANJO, 0xD, 0x6, 
        0.5f, 1.0f, 28.0f, -16.0f,
        1.0f, 28.0f, 0.0f, 1.0f, 
        NULL, {0}, 0.0f
    },
    {   0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f, 
        ITEM_1B_VILE_VILE_SCORE, ASSET_7E6_SPRITE_VILE, 0xD, 0x6, 
        0.5f, 1.0f, 263.0f, -52.0f, 
        1.0f, -26.0f, 0.0f, 1.0f, 
        NULL, {0}, 0.0f
    },
    {   0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f, 
        ITEM_1C_MUMBO_TOKEN, ASSET_41A_SPRITE_MUMBO_TOKEN, 0x2, 0xC, 
        0.3f, 1.0f, 224.0f, 224.0f, 
        1.1f, 32.0f, 0.0f, -1.0f, 
        NULL, {0}, 0.0f
    },
    {   0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f, 
        ITEM_0_HOURGLASS_TIMER, ASSET_6DA_SPRITE_HOURGLASS, 0x2, 0x16, 
        0.3f, 1.0f, 24.0f, 224.0f, 
        1.0f, 20.0f, 0.0f, -1.0f, 
        NULL, {0}, 0.0f
    },
    {   0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f, 
        ITEM_1_SKULL_HOURGLASS_TIMER, ASSET_6DB_SPRITE_SKULL_HOURGLASS, 0x2, 0x16, 
        0.3f, 1.0f, 24.0f, 266.0f, 
        1.0f, 20.0f, 0.0f, -1.0f, 
        NULL, {0}, 0.0f
    },
    {   0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f, 
        ITEM_3_PROPELLOR_TIMER, ASSET_6D9_SPRITE_PROPELLOR_TIMER, 0x2, 0xC, 
        0.2f, 1.0f, 36.0f, 224.0f, 
        0.8f, 32.0f, 3.0f, -1.0f, 
        NULL, {0}, 0.0f
    },
    {   0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f, 
        ITEM_5_XMAS_TREE_TIMER, ASSET_6DC_SPRITE_XMAS_TREE_TIMER, 0x1, 0xE,
        0.5f, 1.0f, 24.0f, 256.0f, 
        1.0f, 24.0f, 2.0f, -1.0f, 
        NULL, {0}, 0.0f
    },
    {   0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f, 
        ITEM_25_MUMBO_TOKEN_TOTAL, ASSET_41A_SPRITE_MUMBO_TOKEN, 0x2, 0xC, 
        0.3f, 1.0f, 224.0f, 228.0f,
        1.1f, 32.0f, 0.0f, -1.0f, 
        NULL, {0}, 0.0f
    },
    {   0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f, 
        ITEM_27_JOKER_CARD, ASSET_7EE_JOKER_CARD, 0x2, 0x18, 
        0.3f, 1.0f, 224.0f, 224.0f, 
        0.8f, 32.0f, 0.0f, -1.0f, 
        NULL, {0}, 0.0f
    },
    {   0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f, 
        0x00000028, 0, 0x2, 0x16, 
        0.3f, 1.0f, 24.0f, 266.0f, 
        1.0f, 20.0f, 0.0f, -1.0f, 
        NULL, {0}, 0.0f
    },
    {   0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f, 
        0x0000002A, 0, 0x2, 0x0E, 
        0.3f, 1.0f, 224.0f, 224.0f, 
        0.6f, 32.0f, 0.0f, -1.0f, 
        NULL, {0}, 0.0f
    },
    {   0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f, 
        0x00000029, 0, 0x2, 0x0E, 
        0.3f, 1.0f, 224.0f, 224.0f, 
        0.6f, 32.0f, 0.0f, -1.0f, 
        NULL, {0}, 0.0f
    },
    {   0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f, 
        -1, 0, 0x0, 0x00, 
        0.0f, 0.0f, 0.0f, 0.0f, 
        0.0f, 0.0f, 0.0f, 0.0f, 
        NULL, {0}, 0.0f
    },
};

/* .code */
void func_802FD360(struct8s *arg0, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    s32 tmp_s2 = 0;
    s32 tmp_s4;
    s32 texture_width;
    s32 texture_height;
    f32 tmp_f26;
    f32 f2;


    if(arg0->unk50 == NULL) return;

    gSPDisplayList((*gfx)++, &D_80369920);
    if(arg0->unk20 == ITEM_C_NOTE){
        gDPSetCombineMode((*gfx)++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    }
    viewport_setRenderViewportAndOrthoMatrix(gfx, mtx);
    gSPVertex((*gfx)++, *vtx, 4, 0);
    if(arg0->unk20 == ITEM_0_HOURGLASS_TIMER){
        tmp_s2 = 0xC;
    }
    func_80347FC0(gfx, arg0->unk50, ((s32)arg0->unk60 + tmp_s2)%arg0->unk2C, 0, 0, 0, 0, 2, 2, &texture_width, &texture_height);
    tmp_f26 = (arg0->unk20 == ITEM_0_HOURGLASS_TIMER && texture_width == 0x10) ? 1.0f : 0.0f;
    for(tmp_s4 = 0; tmp_s4 < 2; tmp_s4++){//L802FD528
        for(tmp_s2 = 0; tmp_s2 < 2; tmp_s2++){//
            (*vtx)->v.ob[0] =  ((func_802FB0DC(arg0) + (((texture_width*arg0->unk40*tmp_s2 - texture_width*arg0->unk40/2) - (f32)framebuffer_width/2) + arg0->unk38)) + tmp_f26) * 4.0f;
            (*vtx)->v.ob[1] =  ((((texture_height*arg0->unk40/2 - texture_height*arg0->unk40*tmp_s4) + (f32)framebuffer_height/2) - arg0->unk3C) - func_802FB0E4(arg0)*arg0->unk4C)*4.0f;
            (*vtx)->v.ob[2] = -0x14;
            (*vtx)->v.tc[0] =  ((texture_width -1) * tmp_s2) << 6;
            (*vtx)->v.tc[1] =  ((texture_height -1) * tmp_s4) << 6;
            if(arg0->unk20 == ITEM_C_NOTE){
                if(tmp_s4 == 0){
                    (*vtx)->v.cn[0] = 0xff;
                    (*vtx)->v.cn[1] = 0xff;
                    (*vtx)->v.cn[2] = 0x0;
                    (*vtx)->v.cn[3] = 0xff;
                }
                else if(tmp_s2 != 0){
                    (*vtx)->v.cn[0] = 0xff;
                    (*vtx)->v.cn[1] = 100;
                    (*vtx)->v.cn[2] = 0x0;
                    (*vtx)->v.cn[3] = 0xff;
                }
                else{
                    (*vtx)->v.cn[0] = 0xff;
                    (*vtx)->v.cn[1] = 200;
                    (*vtx)->v.cn[2] = 0x0;
                    (*vtx)->v.cn[3] = 0xff;
                }
            }
            (*vtx)++;
        }
    }
    gSP1Quadrangle((*gfx)++, 0, 1, 3, 2, 0);
    gDPPipeSync((*gfx)++);
    gDPSetTextureLUT((*gfx)++, G_TT_NONE);
    gDPPipelineMode((*gfx)++, G_PM_NPRIMITIVE);
    viewport_setRenderViewportAndPerspectiveMatrix(gfx, mtx);
}

struct8s *fxcommon2score_new(enum item_e item_id) {
    s32 i;
    struct8s *v1;

    for(v1 =  D_80369960; v1->unk20 != -1; v1++){
        if(item_id == v1->unk20){
             v1->unk14 =  v1->unk4C;
             return v1;
        } 
    }
    return NULL;
}

void fxcommon2score_update(s32 arg0, struct8s * arg1){
    s32 tmp;
    f32 two = 2.0f;
    f32 phi_f16;
    f32 tmpf;

    tmp = func_802FB0D4(arg1);
    phi_f16 = 1.0f;
    if(!tmp) {
        fxcommon2score_free(arg0, arg1);
    }
    else{
        if(arg1->unk50 == NULL && arg1->unk24){
            arg1->unk50 = assetcache_get(arg1->unk24);
        }
       
        if(arg0 == 0){
            if(arg1->unk60 < 1.0f || arg1->unk60 >= 12.0f)
                phi_f16 = 0.333f;
        }
        if(arg0 == 1){
            if(arg1->unk60 > 10.0f)
                phi_f16 = 0.333f;
        }
        if(arg0 < 6){
            if(item_getCount(arg0) < 30){
                arg1->unk28 |= 8;
            }
            else{
                arg1->unk28 &= ~0xC;
            }
        }
        if((arg1->unk28 & 4) == 0){
            tmpf = arg1->unk2C;
             arg1->unk60 = time_getDelta() * (arg1->unk34 * arg1->unk30) * 60.0f * phi_f16 + arg1->unk60;
             if(arg1->unk2C <= arg1->unk60){
                 if(arg1->unk28 & 1){
                       arg1->unk34 *= -1.0f;
                       arg1->unk60 -= two* arg1->unk30 * time_getDelta() * 60.0f;
                 }
                 else{
                    arg1->unk60 -= arg1->unk2C; 
                    if (arg1->unk28 & 8) {
                        arg1->unk28 |= 4;
                        arg1->unk60 = 0.0f;
                    }
                 }
             }
             else{
                if(arg1->unk60 < 0.0){
                    if(arg1->unk28 & 1){
                        arg1->unk34 *= -1.0f;
                        arg1->unk60 +=  two * arg1->unk30 * time_getDelta() * 60.0f;
                    }
                    else{
                        arg1->unk60 += arg1->unk2C;
                    }
                    if (arg1->unk28 & 8) {
                        arg1->unk28 |= 4;
                        arg1->unk60 = 0.0f;
                    }
                }
            }
        }
    }
}

void fxcommon2score_draw(enum item_e item_id, struct8s *arg1, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    f32 pad;
    s32 sp38;
    f32 sp34;


    sp38 = itemPrint_getValue(item_id);
    sp34 = 0.0f;
    if(item_id == ITEM_C_NOTE){
        if(level_get() == LEVEL_6_LAIR || level_get() == LEVEL_C_BOSS){
            sp38 = itemscore_noteScores_getTotal();
        }
    }
    if(item_id < 6){
        sp38 = ((sp38)? 1: 0) + sp38/60;
    }//L802FDBA8
    if(item_id == ITEM_1B_VILE_VILE_SCORE && 9 < sp38){
        sp34 = -16.0f;
    }
    if(item_id == ITEM_1C_MUMBO_TOKEN || item_id == ITEM_25_MUMBO_TOKEN_TOTAL){
        if(sp38 >= 100){
            sp38 = 99;
        }
    }
    arg1->string_54[0] = 0;
    //convert to string
    strIToA(arg1->string_54, sp38);
    //print text (blue egg font)
    print_bold_spaced(
        (s32)(func_802FB0DC(arg1) + arg1->unk38 + arg1->unk44 + sp34), 
        (s32)(func_802FB0E4(arg1)*arg1->unk4C + (arg1->unk3C + arg1->unk48)), 
        arg1->string_54
    );
    //draw sprite?
    func_802FD360(arg1, gfx, mtx, vtx);
}

void fxcommon2score_free(enum item_e item_id, struct8s *arg1){
    if(arg1->unk50){
        func_8033BD4C(arg1->unk50); //assetCache_free
        arg1->unk50 = NULL;
    }
}

void func_802FDCB8(enum item_e item_id) {
    s32 i;
    struct8s *var_v0;

    for(var_v0 = &D_80369960[0]; var_v0->unk20 != -1; var_v0++){
        if(item_id == var_v0->unk20){
            var_v0->unk28 &= ~4;
            return;
        }
    }
}


enum item_e func_802FDD0C(struct8s *arg0){
    return arg0->unk20;
}
