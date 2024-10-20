#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"


extern f32 func_802FB0E4(struct8s*);

/* .data */
BKSprite * gSpriteHealth = NULL;
BKSprite * gSpriteRedHealth = NULL;
Gfx D_8036A918[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPEndDisplayList(),
};

/* .bss */
s32 D_80381EF0;
f32 D_80381EF4;
f32 D_80381EF8;
f32 D_80381EFC;
s32 gTotalHealth;
f32 gHealth;
f32 D_80381F08[8];
f32 D_80381F28;
f32 D_80381F2C;
struct7s D_80381F30;

/* .code */
void func_80300C10(void) {
    s32 i;

    D_80381EF8 = -272.0f;
    D_80381EF4 = 1.0f;
    D_80381EF0 = 0;
    for(i = 0; i < 8; i++){
        D_80381F08[i] = -64.0f;
    }
}

void fxhealthscore_free(enum item_e item_id, struct8s *arg1){
    if (gSpriteHealth != NULL) {
        assetCache_free(gSpriteHealth);
        gSpriteHealth = NULL;
    }

    if (gSpriteRedHealth != NULL) {
        assetCache_free(gSpriteRedHealth);
        gSpriteRedHealth = NULL;
    }

    func_80300C10();
}

struct7s *fxhealthscore_new(enum item_e item_id){
    func_80300C10();
    D_80381EFC = 0.68f;
    return &D_80381F30;
}

void fxhealthscore_draw(enum item_e item_id, struct8s *arg1, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    int i;
    int tmp_v1;
    s32 honeycomb_width;
    s32 honeycomb_height;
    int tmp_v0;
    f32 f18;
    f32 f14;
    f32 f20;
    s32 is_red_health_initialized = FALSE;
    s32 s6;

    if (gSpriteHealth == NULL) {
        return;
    }

    gSPDisplayList((*gfx)++, D_8036A918);
    func_80347FC0(gfx, gSpriteHealth, 0, 0, 0, 0, 0, 2, 2, &honeycomb_width, &honeycomb_height);
    viewport_setRenderViewportAndOrthoMatrix(gfx, mtx);

    //loop over each honeycomb piece
    for (i = gTotalHealth - 1; i >= 0; i--) {//L80300E40
        if (i != 0 && (i + 1 != gTotalHealth || gTotalHealth & 1)) {
            s6 = (i & 1) ? i + 1 : i - 1;
        }
        else {//L80300E84
            s6 = i;
        }

        gDPPipeSync((*gfx)++);

        if (gHealth > i) {
            if (0 < (gHealth - 8.0f) && (gHealth - 8.0f) > i) {
                if (!is_red_health_initialized) {
                    func_80347FC0(gfx, gSpriteRedHealth, 0, 0, 0, 0, 0, 2, 2, &honeycomb_width, &honeycomb_height);
                    is_red_health_initialized = TRUE;
                }
            }//L80300F38

            gDPSetPrimColor((*gfx)++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        }
        else {//L80300F58
            gDPSetPrimColor((*gfx)++, 0, 0, 0xFF, 0xFF, 0xFF, 0x78);
        }

        f20 = 96.0f - (f32) gFramebufferWidth / 2 + (i * 13);
        f14 = (f32) gFramebufferHeight / 2 - func_802FB0E4(arg1) - D_80381F08[s6] - -48.0f;
        f14 = (i & 1) ? f14 + 5.75 : f14 - 5.75;

        gSPVertex((*gfx)++, *vtx, 4, 0);

        for (tmp_v1 = 0; tmp_v1 < 2; tmp_v1++) {//L8030101C
            for (tmp_v0 = 0; tmp_v0 < 2; tmp_v0++) {//L80301030
                (*vtx)->v.ob[0] = (((honeycomb_width * D_80381EFC) * tmp_v0 - (honeycomb_width * D_80381EFC) / 2) + f20) * 4.0f;
                (*vtx)->v.ob[1] = (((honeycomb_height * D_80381EFC) / 2 - (honeycomb_height * D_80381EFC) * tmp_v1) + f14) * 4.0f;
                (*vtx)->v.ob[2] = -0x14;

                (*vtx)->v.tc[0] = ((honeycomb_width - 1) * tmp_v0) << 6;
                (*vtx)->v.tc[1] = ((honeycomb_height - 1) * tmp_v1) << 6;
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

bool func_803012B8(f32 arg0, s32 arg1, s32 arg2){
    if(arg1 == 0)
        return TRUE;
    
    return (arg0 < D_80381F08[arg1 - 1]);
}

void func_803012F8(void) {
    D_80381EF0 = 1;
    D_80381F28 = 0.0f;
    item_adjustByDiffWithHud(ITEM_14_HEALTH, 0);
    gHealth = (f32) item_getCount(ITEM_14_HEALTH);
}


void fxhealthscore_update(enum item_e item_id, struct8s *arg1) {
    f32 temp_f20;
    s32 var_s0;
    s32 sp2C;


    temp_f20 = time_getDelta();
    sp2C = func_802FB0D4(arg1);
    if (item_getCount(ITEM_15_HEALTH_TOTAL) >= 9) {
        gTotalHealth = 8;
    } else {
        gTotalHealth = item_getCount(ITEM_15_HEALTH_TOTAL);
    }

    switch (D_80381EF0) {
        case 0:
            gHealth = (f32) itemPrint_getValue(item_id);
            break;

        case 1:
            gHealth += temp_f20 * 10.0f;
            if (gTotalHealth <= gHealth) {
                gHealth = gHealth - gTotalHealth;
            }
            D_80381F28 += temp_f20;
            if (D_80381F28 > 2.5) {
                D_80381EF0 = 2;
            }
            item_adjustByDiffWithHud(ITEM_14_HEALTH, 0);
            break;

        case 2:
            if (sp2C != 1) {
                gHealth += temp_f20 * 10.0f;
                if (gTotalHealth <= gHealth) {
                    gHealth = gHealth - gTotalHealth;
                }
            }
            if (randf2(0.0f, 1.0f) < (1.0 / gTotalHealth)) {
                if (gHealth < 1.0f) {
                    gHealth =gHealth + 1.0;
                }
                if (item_getCount(ITEM_14_HEALTH) < gHealth) {
                    func_8025A6EC(COMUSIC_2B_DING_B, 22000);
                }
                if (gHealth < (f32) item_getCount(ITEM_14_HEALTH)) {
                    func_8025A6EC(COMUSIC_2C_BUZZER, 22000);
                }
                item_set(ITEM_14_HEALTH, (s32) gHealth);
                D_80381EF0 = 0;
            }
            break;
    }

    switch (sp2C) {
        case 2:
            break;

        case 1:
            if (gSpriteHealth == NULL) {
                gSpriteHealth = assetcache_get(ASSET_7DD_SPRITE_HEALTH);
            }

            if (gSpriteRedHealth == NULL) {
                gSpriteRedHealth = assetcache_get(ASSET_7EA_SPRITE_RED_HEALTH);
            }
            break;

        case 0:
            fxhealthscore_free(item_id, arg1);
            break;
    }
    if (sp2C) {
        for(var_s0 = 0; var_s0 < gTotalHealth; var_s0++){
            if (func_803012B8(-15.0f, var_s0, gTotalHealth)) {
                D_80381F08[var_s0] = D_80381F08[var_s0] * 0.6;
            }
        }
    }
}
