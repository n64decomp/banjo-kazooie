#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"



#define AIRSCORE_COUNT (6)
#define FXAIRSCORE_SCALE (0.68f)

extern f32 func_802FB0E4(struct8s *);

/* .data */
static BKSprite *s_sprite = NULL;
static Gfx s_fxairscore_context[] ={
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPEndDisplayList(),
};

/* .bss */
s32 s_freeze;
f32 D_80381F54;
f32 D_80381F58;
static f32 s_texture_scale;
static f32 s_active_count;
f32 D_80381F68[AIRSCORE_COUNT];
struct7s D_80381F80;

/* .code */
void func_803016F0(void) {
    s32 i;

    D_80381F58 = -272.0f;
    D_80381F54 = 1.0f;
    s_freeze = 0;
    for(i = 0; i < AIRSCORE_COUNT; i++){
        D_80381F68[i] = -64.0f;
    }
}

void fxairscore_free(s32 arg0, struct7s *arg1) {
    if (s_sprite != NULL) {
        assetCache_free(s_sprite);
        s_sprite = NULL;
    }
    func_803016F0();
}

struct7s *fxairscore_new(s32 arg0) {
    func_803016F0();
    s_texture_scale = FXAIRSCORE_SCALE;
    return &D_80381F80;
}

void fxairscore_draw(enum item_e item_id, struct8s *arg1, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    f32 y;
    f32 x;
    s32 texture_width;
    s32 texture_height;
    s32 i_part;
    s32 var_s6;
    s32 v_x;
    s32 v_y;

    if (s_sprite != 0) {
        gSPDisplayList((*gfx)++, s_fxairscore_context);
        func_80347FC0(gfx, s_sprite, 0, 0, 0, 0, 0, 2, 2, &texture_width, &texture_height);
        viewport_setRenderViewportAndOrthoMatrix(gfx, mtx);
        //render all 6 air pieces
        for(i_part = 0; i_part < AIRSCORE_COUNT; i_part++){
            if ((i_part != 0) && (i_part != 5)) {
                var_s6 = (i_part & 1) ? i_part + 1 : i_part - 1;
            } else {
                var_s6 = i_part;
            }
            gDPPipeSync((*gfx)++);
            if ((f32) (5 - i_part) < s_active_count) {
                gDPSetPrimColor((*gfx)++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
            } else {
                gDPSetPrimColor((*gfx)++, 0, 0, 0x00, 0x00, 0x00, 0x78);
            }
            x = func_802FB0E4(arg1);
            x = ((-40 + x) + D_80381F68[var_s6]) - ((f32) framebuffer_width / 2);
            y = ((78 + (i_part * 15.5)) - ((f32) framebuffer_height / 2));

            //stagger x position
            x = (i_part & 1) ? x + 5.0f : x - 5.0f;
            gSPVertex((*gfx)++, *vtx, 4, 0);
            for(v_y = 0; v_y < 2; v_y++){
                for(v_x = 0; v_x < 2; v_x++){
                    (*vtx)->v.ob[0] = (x + (((texture_width * s_texture_scale) * v_x) - ((texture_width * s_texture_scale) / 2))) * 4.0f;
                    (*vtx)->v.ob[1] = (y + (((texture_height * s_texture_scale) / 2) - (texture_height * s_texture_scale) * v_y)) * 4.0f;
                    (*vtx)->v.ob[2] = -0x14;
                    (*vtx)->v.tc[0] = ((texture_width - 1) * v_x) << 6;
                    (*vtx)->v.tc[1] = ((texture_height - 1) * v_y) << 6;
                    (*vtx)++;
                }
            }
            gSP1Quadrangle((*gfx)++, 0, 1, 3, 2, 0);
        }
        gDPPipeSync((*gfx)++);
        gDPSetTextureLUT((*gfx)++, G_TT_NONE);
        gDPPipelineMode((*gfx)++, G_PM_NPRIMITIVE);
        viewport_setRenderViewportAndPerspectiveMatrix(gfx, mtx);
    }
}

bool func_80301CE0(f32 arg0, s32 arg1, s32 arg2){
    if(arg1 == 5)
        return TRUE;

    return arg0 < D_80381F68[arg1 + 1];
}

s32 fxairscore_time_to_count(s32 time) {
    s32 minutes;
    s32 var_v0;

    var_v0 = (time != 0) ? 1 : 0;
    minutes = (((s32) (6*time) / 60) / 60) + var_v0;
    return MIN(6, minutes);
}

s32 fxairscore_count_to_time(s32 count) {
    return (s32) (count * 60 * 60) / 6;
}

void fxairscore_update(enum item_e item_id, struct7s *arg1) {
    s32 temp_s0;
    s32 var_s0;

    temp_s0 = func_802FB0D4(arg1);
    if (!s_freeze) {
        s_active_count = (f32) fxairscore_time_to_count(itemPrint_getValue(item_id));
    }
    switch (temp_s0) {
        case 2:
            break;
        case 1: //load sprite
            if (s_sprite == NULL) {
                s_sprite = (BKSprite *)assetcache_get(ASSET_7E5_SPRITE_WATER_HONEYCOMB);
            }
            break;
        case 0:
            fxairscore_free(item_id, arg1);
            break;
    }
    if (temp_s0 != 0) {
        for(var_s0 = 5; var_s0 >= 0; var_s0--){
            if (func_80301CE0(-15.0f, var_s0, 6)) {
                D_80381F68[var_s0] *= 0.6;
            }
        }
    }
}
