#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s16 D_803A5D00[2][0xF660];

typedef struct Struct_Core2_6A4B0_2{
    s16 (*vtx_coord)[3];
    u16 *tmem_raw_ptr;
    u16 *tmem_ptr;
    void (*draw_method)(struct Struct_Core2_6A4B0_2 *, Gfx **, Mtx **, Vtx **);
    bool unk10;
}Struct_Core2_6A4B0_2;

s16 *func_802F1804(Struct_Core2_6A4B0_2 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_802F18B8(Struct_Core2_6A4B0_2 *arg0);

/* .data */
Gfx D_803689D0[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsSPEndDisplayList()
};




/* .code */
void func_802F1440(Struct_Core2_6A4B0_2 *arg0, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Vtx *sp9C;

    Vtx *i_vtx;
    s32 var_s3;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s16 *temp_v0_2;
    static s32 D_80368A10[6] = {0x60, 0x840,  0x60, 0x840, 0x840,  0x60};
    static s32 D_80368A28[6] = {0x60,  0x60, 0x860,  0x60, 0x860, 0x860};
    
    if (!arg0->unk10) {
        func_8024C7B8(gfx, mtx);
    }
    gSPDisplayList((*gfx)++, D_803689D0);

    i_vtx = sp9C = *vtx;
    for(sp4C = 0; sp4C < 6; sp4C++){
        for(sp50 = 0; sp50 < 9; sp50++){
            for(sp54 = 0; sp54 < 2; sp54++){
                for(var_s3 = 0; var_s3 < 3; var_s3++){
                    temp_v0_2 = func_802F1804(arg0, sp50, sp4C, sp54, var_s3);
                    i_vtx->n.ob[0] = temp_v0_2[0];
                    i_vtx->n.ob[1] = temp_v0_2[1];
                    i_vtx->n.ob[2] = temp_v0_2[2];

                    i_vtx->n.flag = 0;

                    i_vtx->n.tc[0] = D_80368A10[sp54 * 3 + var_s3];
                    i_vtx->n.tc[1] = D_80368A28[sp54 * 3 + var_s3];
                    i_vtx->n.n[0] = -1;
                    i_vtx->n.n[1] = -1;
                    i_vtx->n.n[2] = -1;
                    i_vtx->n.a = 0xFF;
                    i_vtx++;
                }
            }
        }
    }
    *vtx = i_vtx;
    i_vtx = sp9C;
    var_s3 = 0;
    gSPVertex((*gfx)++, osVirtualToPhysical(i_vtx), 16, 0);
    for(sp4C = 0; sp4C < 6; sp4C++){
        for(sp50 = 0; sp50 < 9; sp50++){
            s16 *temp_v0_2 = arg0->tmem_ptr + (0x20*sp50 + 1) + (0x20*sp4C + 0xC)*framebuffer_width;
            gDPLoadTextureTile((*gfx)++, osVirtualToPhysical(temp_v0_2), G_IM_FMT_RGBA, G_IM_SIZ_16b, framebuffer_width, 0, 0, 0, 33, 33, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            for(sp54 = 0; sp54 < 2; sp54++){
                gSP1Triangle((*gfx)++, var_s3, var_s3 + 1, var_s3 + 2, 0);
                var_s3 += 3;
                if (var_s3 == 0xF) {
                    i_vtx += 0xF;
                    var_s3 = 0;
                    gSPVertex((*gfx)++, osVirtualToPhysical(i_vtx), 16, 0);
                }
            }
        }
    }
    if (!arg0->unk10) {
        func_8024C904(gfx, mtx);
    }
}

s16 *func_802F1804(Struct_Core2_6A4B0_2 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return (s16*)(arg0->vtx_coord + (arg1 * 2*3) + (arg2 * 2*3*9) + (arg3 * 3) + (arg4));
}

void func_802F1858(Struct_Core2_6A4B0_2 *arg0, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    if(arg0->draw_method != NULL){
        arg0->draw_method(arg0, gfx, mtx, vtx);
    }
}

void func_802F1884(Struct_Core2_6A4B0_2 *arg0){
    func_802F18B8(arg0);
    free(arg0->vtx_coord);
    free(arg0);
}

void func_802F18B8(Struct_Core2_6A4B0_2 *arg0){
    if(arg0->tmem_raw_ptr != NULL){
        free(arg0->tmem_raw_ptr);
        arg0->tmem_raw_ptr = NULL;
    }
}

Struct_Core2_6A4B0_2 *func_802F18F0(void){
    Struct_Core2_6A4B0_2 *self;

    self = (Struct_Core2_6A4B0_2 *) malloc(sizeof(Struct_Core2_6A4B0_2));
    self->vtx_coord = malloc(6*9*2*3*3*sizeof(u16));
    self->tmem_raw_ptr = NULL;
    self->draw_method = 0;
    self->unk10 = 0;
    return self;
}

void func_802F1934(Struct_Core2_6A4B0_2 * arg0, s32 arg1){
    func_802F18B8(arg0);
    arg0->tmem_raw_ptr = malloc(framebuffer_width*framebuffer_height*sizeof(u16) + 0x10);
    arg0->tmem_ptr = arg0->tmem_raw_ptr;
    while(((s32)arg0->tmem_ptr & 0x10) == 0){
        arg0->tmem_ptr = (u16*)((s32)arg0->tmem_ptr + 1);
    }
    func_80253010(arg0->tmem_ptr, D_803A5D00[arg1], framebuffer_width*framebuffer_height*sizeof(u16));
    osWriteBackDCacheAll();
}

void func_802F1A08(s32 arg0) { }

void func_802F1A10(Struct_Core2_6A4B0_2 *arg0, f32 angle_degrees) {
    s32 spCC[3];
    f32 spC0[3];
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f20;
    f32 cos;
    f32 sin;
    f32 temp_f2;
    s32 *var_s1;
    s32 *var_s2;
    s32 var_s0;
    s32 var_s3;
    s32 var_s4;
    s32 sp90;
    s32 var_s6;
    s16 *temp_v0_2;
    static s32 D_80368A40[6] = {0, 1, 0, 1, 1, 0};
    static s32 D_80368A58[6] = {0, 0, 1, 0, 1, 1};

    cos = cosf(angle_degrees * 2 * BAD_PI);
    sin = sinf(angle_degrees * 2 * BAD_PI);
    func_8024C5CC(spC0);
    spCC[0] = (-(framebuffer_width / 2) * 4) + 8;
    spCC[1] = ((framebuffer_height / 2) * 4) - 0x38;
    spCC[2] = -0xA;
    for(var_s6 = 0; var_s6 < 6; var_s6++){
        for(var_s4 = 0; var_s4 < 9; var_s4++){
            for(var_s3 = 0, sp90 = 0; var_s3 < 2; var_s3++, sp90 += 3){
                var_s1 = D_80368A40 + sp90;\
                var_s2 = D_80368A58 + sp90;
                for(var_s0 = 0; var_s0 < 3; var_s0++){
                    temp_v0_2 = func_802F1804(arg0, var_s4, var_s6, var_s3, var_s0);
                    temp_f0 = (f32) (spCC[0] + var_s4 * 0x80 + (*var_s1 * 0x80));
                    temp_f2 = (f32) (spCC[1] - var_s6 * 0x80 - (*var_s2 * 0x80));
                    
                    temp_f0 = temp_f0 * (1.0f - angle_degrees);
                    temp_f2 = temp_f2 * (1.0f - angle_degrees);

                    temp_f12 = temp_f0;
                    temp_f0 = (temp_f12 * cos) - (temp_f2 * sin);
                    temp_f2 = (temp_f12 * sin) + (temp_f2 * cos);
                    
                    temp_f0 = temp_f0 + ((-560.0f - temp_f0) * angle_degrees);
                    temp_f2 = temp_f2 + ((400.0f - temp_f2) * angle_degrees);
                    
                    temp_v0_2[0] = (s16) (s32) temp_f0;
                    temp_v0_2[1] = (s16) (s32) temp_f2;
                    temp_v0_2[2] = (s16) spCC[2];
                    var_s1++;
                    var_s2++;
                }
            }
        }
    }
    arg0->draw_method = &func_802F1440;
    arg0->unk10 = FALSE;
}

void func_802F1CAC(Struct_Core2_6A4B0_2 *arg0) {
    static s32 D_80368A70[6] = {0, 1, 0, 1, 1, 0};
    static s32 D_80368A88[6] = {0, 0, 1, 0, 1, 1};

    s32 sp84[3];
    f32 sp78[3];
    s32 var_s0;
    s32 var_s4;
    s32 var_s5;
    s32 var_s7;
    s32 pad;
    s32 sp60;
    s16 *temp_v0_2;
    s32 *var_s1;
    s32 *var_s2;
    

    func_8024C5CC(sp78);
    sp84[0] = (s32) ((1000.0f - sp78[0]) - 200.0f);
    sp84[1] = (s32) ((0.0f - sp78[1]) + 300.0f);
    sp84[2] = (s32) ((2000.0f - sp78[2]) + 0.0f);
    for(var_s7 = 0; var_s7 < 6; var_s7++){
        for(var_s5 = 0; var_s5 < 9; var_s5++){
            for(var_s4 = 0, sp60 = 0; var_s4 < 2; var_s4++, sp60 += 3){
                var_s1 = D_80368A70 + sp60;\
                var_s2 = D_80368A88 + sp60;
                for(var_s0 = 0; var_s0 < 3; var_s0++){
                    temp_v0_2 = func_802F1804(arg0, var_s5, var_s7, var_s4, var_s0);
                    temp_v0_2[0] = (s16) (sp84[0] + var_s5*0x32 + *var_s1 * 0x32);
                    temp_v0_2[1] = (s16) (sp84[1] - var_s7*0x32 - *var_s2 * 0x32);
                    temp_v0_2[2] = (s16) sp84[2];
                    var_s1++;
                    var_s2++;
                }
            }
        }
    }
    arg0->draw_method = &func_802F1440;
    arg0->unk10 = TRUE;
}
