#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_802FB0E4(struct8s *);

/* .data */
BKSprite *D_8036A960 = NULL;
Gfx D_8036A968[] ={
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
s32 D_80381F50;
f32 D_80381F54;
f32 D_80381F58;
f32 D_80381F5C;
f32 D_80381F60;
f32 D_80381F68[6];
struct7s D_80381F80;

/* .code */
void func_803016F0(void) {
    s32 i;

    D_80381F58 = -272.0f;
    D_80381F54 = 1.0f;
    D_80381F50 = 0;
    for(i = 0; i < 6; i++){
        D_80381F68[i] = -64.0f;
    }
}

void func_80301754(s32 arg0, struct8s *arg1) {
    if (D_8036A960 != NULL) {
        func_8033BD4C(D_8036A960);
        D_8036A960 = NULL;
    }
    func_803016F0();
}

struct7s *func_8030179C(s32 arg0) {
    func_803016F0();
    D_80381F5C = 0.68f;
    return &D_80381F80;
}

void func_803017D0(enum item_e item_id, struct8s *arg1, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    f32 temp_f16;
    f32 var_f14;
    s32 spD4;
    s32 spD0;
    s32 var_s4;
    s32 var_s6;
    s32 var_v0;
    s32 var_v1;

    if (D_8036A960 != 0) {
        gSPDisplayList((*gfx)++, D_8036A968);
        func_80347FC0(gfx, D_8036A960, 0, 0, 0, 0, 0, 2, 2, &spD4, &spD0);
        func_8024C7B8(gfx, mtx);
        for(var_s4 = 0; var_s4 < 6; var_s4++){
            if ((var_s4 != 0) && (var_s4 != 5)) {
                var_s6 = (var_s4 & 1) ? var_s4 + 1 : var_s4 - 1;
            } else {
                var_s6 = var_s4;
            }
            gDPPipeSync((*gfx)++);
            if ((f32) (5 - var_s4) < D_80381F60) {
                gDPSetPrimColor((*gfx)++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
            } else {
                gDPSetPrimColor((*gfx)++, 0, 0, 0x00, 0x00, 0x00, 0x78);
            }
            temp_f16 = func_802FB0E4(arg1);
            temp_f16 = (-40.0f + temp_f16);
            var_f14 = (temp_f16 + D_80381F68[var_s6]) - ((f32) D_80276588 / 2);
            temp_f16 = (((var_s4 * 15.5) + 78.0) - ((f32) D_8027658C / 2));
            var_f14 = (var_s4 & 1) ? var_f14 + 5.0f : var_f14 - 5.0f;
            gSPVertex((*gfx)++, *vtx, 4, 0);
            for(var_v1 = 0; var_v1 < 2; var_v1++){
                for(var_v0 = 0; var_v0 < 2; var_v0++){
                    (*vtx)->v.ob[0] = ((((spD4 * D_80381F5C) * (f32) var_v0) - ((spD4 * D_80381F5C) / 2)) + var_f14) * 4.0f;
                    (*vtx)->v.ob[1] = ((((spD0 * D_80381F5C) / 2) - ((spD0 * D_80381F5C) * ((f32)var_v1))) + temp_f16) * 4.0f;
                    (*vtx)->v.ob[2] = -0x14;
                    (*vtx)->v.tc[0] = ((spD4 - 1) * var_v0) << 6;
                    (*vtx)->v.tc[1] = ((spD0 - 1) * var_v1) << 6;
                    (*vtx)++;
                }
            }
            gSP1Quadrangle((*gfx)++, 0, 1, 3, 2, 0);
        }
        gDPPipeSync((*gfx)++);
        gDPSetTextureLUT((*gfx)++, G_TT_NONE);
        gDPPipelineMode((*gfx)++, G_PM_NPRIMITIVE);
        func_8024C904(gfx, mtx);
    }
}

bool func_80301CE0(f32 arg0, s32 arg1, s32 arg2){
    if(arg1 == 5)
        return TRUE;

    return arg0 < D_80381F68[arg1 + 1];
}

s32 func_80301D24(s32 time) {
    s32 minutes;
    s32 var_v0;

    var_v0 = (time != 0) ? 1 : 0;
    minutes = (((s32) (6*time) / 60) / 60) + var_v0;
    return MIN(6, minutes);
}

s32 func_80301DBC(s32 minutes) {
    return (s32) (minutes * 60 * 60) / 6;
}

void func_80301DE4(enum item_e arg0, struct7s *arg1) {
    s32 temp_s0;
    s32 var_s0;

    temp_s0 = func_802FB0D4(arg1);
    if (D_80381F50 == 0) {
        D_80381F60 = (f32) func_80301D24(itemPrint_getValue(arg0));
    }
    switch (temp_s0) {
        case 2:
            break;
        case 1:
            if (D_8036A960 == NULL) {
                D_8036A960 = (BKSprite *)assetcache_get(ASSET_7E5_SPRITE_WATER_HONEYCOMB);
            }
            break;
        case 0:
            func_80301754(arg0, arg1);
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
