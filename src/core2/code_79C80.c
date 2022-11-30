#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_802FB0E4(struct8s*);

extern s32 framebuffer_width;
extern s32 framebuffer_height;

/* .data */
BKSprite * D_8036A910 = NULL;
BKSprite * D_8036A914 = NULL;
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
s32 D_80381F00;
f32 D_80381F04;
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

void func_80300C70(enum item_e item_id, struct8s *arg1){
    s32 temp_a0;
    s32 temp_a0_2;

    if (D_8036A910 != 0) {
        func_8033BD4C(D_8036A910);
        D_8036A910 = 0;
    }
    if (D_8036A914 != 0) {
        func_8033BD4C(D_8036A914);
        D_8036A914 = 0;
    }
    func_80300C10();
}

struct7s *func_80300CD8(enum item_e item_id){
    func_80300C10();
    D_80381EFC = 0.68f;
    return &D_80381F30;
}

void func_80300D0C(enum item_e item_id, struct8s *arg1, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    int i; 
    int tmp_v1;
    s32 spEC;
    s32 spE8;
    int tmp_v0;
    f32 f18;
    f32 f14;
    f32 f20;
    s32 spD4 = 0;
    s32 s6;

    if(D_8036A910 == NULL) return;

    gSPDisplayList((*gfx)++, D_8036A918);
    func_80347FC0(gfx, D_8036A910, 0, 0, 0, 0, 0, 2, 2, &spEC, &spE8);
    func_8024C7B8(gfx, mtx);
    //loop over each honeycomb piece
    for(i = D_80381F00-1; i >= 0; i--){//L80300E40
        if(i != 0 && (i + 1 != D_80381F00 || D_80381F00 & 1)
        ){
            s6 = (i & 1) ? i + 1 : i - 1;
        }
        else{//L80300E84
            s6 = i;
        }
        gDPPipeSync((*gfx)++);
        if(D_80381F04 > i){
            if((0 < D_80381F04 - 8.0f) &&  ((D_80381F04 - 8.0f) > i)){
                if(!spD4){
                    func_80347FC0(gfx, D_8036A914, 0, 0, 0, 0, 0, 2, 2, &spEC, &spE8);
                    spD4 = TRUE;
                }
            }//L80300F38
            gDPSetPrimColor((*gfx)++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        }
        else{//L80300F58
           gDPSetPrimColor((*gfx)++, 0, 0, 0xFF, 0xFF, 0xFF, 0x78); 
        }
        f20 = 96.0f - (f32)framebuffer_width/2 + (i*13);
        f14 = (f32)framebuffer_height/2 - func_802FB0E4(arg1) - D_80381F08[s6] - -48.0f;
        f14 = (i & 1) ? f14 + 5.75 : f14 - 5.75;
        gSPVertex((*gfx)++, *vtx, 4, 0);
        for(tmp_v1 = 0; tmp_v1 < 2; tmp_v1++){//L8030101C
            for(tmp_v0 = 0; tmp_v0 < 2; tmp_v0++){//L80301030
                (*vtx)->v.ob[0] = (((spEC * D_80381EFC)*tmp_v0 - (spEC * D_80381EFC)/2) + f20)*4.0f;
                (*vtx)->v.ob[1] = (((spE8 * D_80381EFC)/2 - (spE8 * D_80381EFC)*tmp_v1) + f14) * 4.0f;
                (*vtx)->v.ob[2] = -0x14;
                (*vtx)->v.tc[0] =  ((spEC - 1) *tmp_v0) << 6;
                (*vtx)->v.tc[1] =  ((spE8 - 1) *tmp_v1) << 6;
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

bool func_803012B8(f32 arg0, s32 arg1, s32 arg2){
    if(arg1 == 0)
        return TRUE;
    
    return (arg0 < D_80381F08[arg1 - 1]);
}

void func_803012F8(void) {
    D_80381EF0 = 1;
    D_80381F28 = 0.0f;
    func_803463D4(ITEM_14_HEALTH, 0);
    D_80381F04 = (f32) item_getCount(ITEM_14_HEALTH);
}


void func_80301348(enum item_e item_id, struct8s *arg1) {
    f32 temp_f20;
    s32 var_s0;
    s32 sp2C;


    temp_f20 = time_getDelta();
    sp2C = func_802FB0D4(arg1);
    if (item_getCount(ITEM_15_HEALTH_TOTAL) >= 9) {
        D_80381F00 = 8;
    } else {
        D_80381F00 = item_getCount(ITEM_15_HEALTH_TOTAL);
    }

    switch (D_80381EF0) {
        case 0:
            D_80381F04 = (f32) itemPrint_getValue(item_id);
            break;

        case 1:
            D_80381F04 += temp_f20 * 10.0f;
            if (D_80381F00 <= D_80381F04) {
                D_80381F04 = D_80381F04 - D_80381F00;
            }
            D_80381F28 += temp_f20;
            if (D_80381F28 > 2.5) {
                D_80381EF0 = 2;
            }
            func_803463D4(ITEM_14_HEALTH, 0);
            break;

        case 2:
            if (sp2C != 1) {
                D_80381F04 += temp_f20 * 10.0f;
                if (D_80381F00 <= D_80381F04) {
                    D_80381F04 = D_80381F04 - D_80381F00;
                }
            }
            if (randf2(0.0f, 1.0f) < (1.0 / D_80381F00)) {
                if (D_80381F04 < 1.0f) {
                    D_80381F04 =D_80381F04 + 1.0;
                }
                if (item_getCount(ITEM_14_HEALTH) < D_80381F04) {
                    func_8025A6EC(COMUSIC_2B_DING_B, 22000);
                }
                if (D_80381F04 < (f32) item_getCount(ITEM_14_HEALTH)) {
                    func_8025A6EC(COMUSIC_2C_BUZZER, 22000);
                }
                item_set(ITEM_14_HEALTH, (s32) D_80381F04);
                D_80381EF0 = 0;
            }
            break;
    }
    switch (sp2C) {
        case 2:
            break;

        case 1:
            if (D_8036A910 == NULL) {
                D_8036A910 = assetcache_get(ASSET_7DD_SPRITE_HEALTH);
            }
            if (D_8036A914 == NULL) {
                D_8036A914 = assetcache_get(0x7EA);
            }
            break;

        case 0:
            func_80300C70(item_id, arg1);
            break;
    }
    if (sp2C) {
        for(var_s0 = 0; var_s0 < D_80381F00; var_s0++){
            if (func_803012B8(-15.0f, var_s0, D_80381F00)) {
                D_80381F08[var_s0] = D_80381F08[var_s0] * 0.6;
            }
        }
    }
}
