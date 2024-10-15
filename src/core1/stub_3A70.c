#include <ultra64.h>
#include "core1/core1.h"

// all functions in this file are unsued

static Gfx sGfxSublist[] = {
    gsSPClearGeometryMode(G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0060CD00),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2),
    gsSPEndDisplayList()
};

void func_80241490(Gfx **gfx, Vtx **vtx, s32 arg2[3], s32 arg3[3], s32 arg4[3], s32 arg5[3], bool cull_front, s32 arg7) {
    s32 vp_position[3];
    s32 var_a0;
    s32 var_v0;
    s32 var_v1;
    s32 colors[3][4];
    s32 i;

    viewport_getPosition_vec3w(vp_position);

    gSPDisplayList((*gfx)++, sGfxSublist);

    if (cull_front != FALSE) {
        gSPSetGeometryMode((*gfx)++, G_ZBUFFER | G_CULL_BACK);
    } else {
        gSPSetGeometryMode((*gfx)++, G_ZBUFFER | G_CULL_FRONT);
    }

    gSPVertex((*gfx)++, *vtx, 8, 0);
    
    for(i = 0; i < 2; i++){
        for(var_a0 = 0; var_a0 < 2; var_a0++){
            for(var_v1 = 0; var_v1 < 2; var_v1++){
                var_v0 = (var_v1 == 0) ? arg2[0] : arg3[0];
                (*vtx)->v.ob[0] = (s16) (var_v0 - vp_position[0]);

                var_v0 = (i == 0) ? arg2[1] : arg3[1];
                (*vtx)->v.ob[1] = (s16) (var_v0 - vp_position[1]);

                var_v0 = (var_a0 == 0) ? arg2[2] : arg3[2];
                (*vtx)->v.ob[2] = (s16) (var_v0 - vp_position[2]);

                (*vtx)->v.flag = 0;
                (*vtx)->v.tc[0] = 0;
                (*vtx)->v.tc[1] = 0;
                (*vtx)->v.cn[0] = 0;
                (*vtx)->v.cn[1] = 0;
                (*vtx)->v.cn[2] = 0;
                (*vtx)->v.cn[3] = 0;
                (*vtx)++;
            }
        }
    }

    if (arg7 != 0) {
        for(i = 0; i < 3; i++){
            for(var_v1 = 0; var_v1 < 3; var_v1++){
                colors[i][var_v1] = (arg4[var_v1] * arg5[i]) / 255;
            }
            colors[i][3] = 0xFF;
        }
    } else {
        for(i = 0; i < 3; i++){
            for(var_v1 = 0; var_v1 < 3; var_v1++){
                colors[i][var_v1] = arg4[var_v1];
            }
            colors[i][3] = arg5[i];
        }
    }
    gDPPipeSync((*gfx)++);
    gDPSetPrimColor((*gfx)++, 0, 0, colors[0][0], colors[0][1], colors[0][2], colors[0][3]);
    gSP2Triangles((*gfx)++, 7, 3, 5, 0, 5, 3, 1, 0);
    gSP1Quadrangle((*gfx)++, 6, 4, 0, 2, 0);

    gDPPipeSync((*gfx)++);
    gDPSetPrimColor((*gfx)++, 0, 0, colors[1][0], colors[1][1], colors[1][2], colors[1][3]);
    gSP1Quadrangle((*gfx)++, 7, 6, 2, 3, 0);
    gSP2Triangles((*gfx)++, 4, 5, 0, 0, 5, 1, 0, 0);

    gDPPipeSync((*gfx)++);
    gDPSetPrimColor((*gfx)++, 0, 0, colors[2][0], colors[2][1], colors[2][2], colors[2][3]);
    gSP1Quadrangle((*gfx)++, 5, 4, 6, 7, 0);
    gSP2Triangles((*gfx)++, 0, 1, 2, 0, 1, 3, 2, 0);
}

void func_80241928(Gfx** gfx, Vtx** vtx, s32 arg2[3], s32 arg3, s32 arg4[3]) {
    s32 vp_position[3];
    f32 var_f26;
    s32 var_fp;
    s32 var_s0;

    viewport_getPosition_vec3w(vp_position);
    for(var_fp = 0; var_fp < 4; var_fp++){
        gSPDisplayList((*gfx)++, sGfxSublist);
        gSPSetGeometryMode((*gfx)++, G_ZBUFFER);
        gSPVertex((*gfx)++, *vtx, 10, 0);
        for(var_f26 = 0; var_f26 <= 90; var_f26 += 22.5){
            for(var_s0 = -300; var_s0 < 900; var_s0 += 600){
                (*vtx)->v.ob[0] = ((ml_sin_deg(var_fp*90 + var_f26) * arg3) + (f32) arg2[0]) - vp_position[0];
                (*vtx)->v.ob[1] = ((var_s0 / 2) + arg2[1]) - vp_position[1];
                (*vtx)->v.ob[2] = ((ml_cos_deg(var_fp*90 + var_f26) * arg3) + (f32) arg2[2]) - vp_position[2];
                (*vtx)->v.tc[0] = 0;
                (*vtx)->v.tc[1] = 0;
                (*vtx)->v.cn[0] = 0;
                (*vtx)->v.cn[1] = 0;
                (*vtx)->v.cn[2] = 0;
                (*vtx)->v.cn[3] = 0;
                (*vtx)++;
            }
        }
        gDPPipeSync((*gfx)++);
        
        for(var_f26 = 0; var_f26 < 4; var_f26++){
            gDPSetPrimColor((*gfx)++, 0, 0, arg4[0], arg4[1], arg4[2], 90.0f + (var_fp * 25.0f) + (var_f26 * 6.25f));
            gSP2Triangles((*gfx)++, var_f26*2, var_f26*2 + 3, var_f26*2 + 1, var_f26*2, var_f26*2, var_f26*2 + 2, var_f26*2 + 3, var_f26*2);
        }
    }
}

void func_802424D4(Gfx **gfx, Mtx **mtx, Vtx **vtx, f32 arg3[3], f32 arg4[3], f32 arg5, s32 arg6[4]) {
    s32 var_a0;
    s32 var_v0;
    s32 var_v1;
    f32 sp80[3];
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];

    sp50[0] = arg4[0];
    sp50[1] = arg4[1];
    sp50[2] = arg4[2];
    if ((arg3[0] != sp50[0]) || (arg3[1] != sp50[1]) || (arg3[2] != sp50[2])) {
        if ((arg3[0] == sp50[0]) && (arg3[2] == sp50[2])) {
            sp50[0] += 0.05;
        }
        sp80[0] = sp50[0] - arg3[0];
        sp80[1] = sp50[1] - arg3[1];
        sp80[2] = sp50[2] - arg3[2];
        ml_vec3f_normalize_copy(sp44, sp80);

        sp74[0] = -sp44[2];
        sp74[1] = 0.0f;
        sp74[2] = sp44[0];
        ml_vec3f_normalize(sp74);
        sp74[0] *= arg5;
        sp74[1] *= arg5;
        sp74[2] *= arg5;

        sp68[0] = (sp44[1] * sp74[2]) - (sp44[2]*sp74[1]);
        sp68[1] = (sp44[2] * sp74[0]) - (sp44[0]*sp74[2]);
        sp68[2] = (sp44[0] * sp74[1]) - (sp44[1]*sp74[0]);
        ml_vec3f_normalize(sp68);
        sp68[0] *= arg5;
        sp68[1] *= arg5;
        sp68[2] *= arg5;

        viewport_getPosition_vec3f(sp5C);
        gSPDisplayList((*gfx)++, sGfxSublist);
        gSPSetGeometryMode((*gfx)++, G_ZBUFFER);
        gSPVertex((*gfx)++, *vtx, 8, 0);
        for( var_a0 = 0; var_a0 < 2; var_a0++){
            for(var_v0 = -1; var_v0 < 3; var_v0+=2) {
                (*vtx)->v.ob[0] = (arg3[0] + (var_a0 * sp80[0]) + (var_v0 * sp74[0])) - sp5C[0];
                (*vtx)->v.ob[1] = (arg3[1] + (var_a0 * sp80[1]) + (var_v0 * sp74[1])) - sp5C[1];
                (*vtx)->v.ob[2] = (arg3[2] + (var_a0 * sp80[2]) + (var_v0 * sp74[2])) - sp5C[2];
                (*vtx)->v.tc[0] = 0;
                (*vtx)->v.tc[1] = 0;
                (*vtx)->v.cn[0] = 0;
                (*vtx)->v.cn[1] = 0;
                (*vtx)->v.cn[2] = 0;
                (*vtx)->v.cn[3] = 0;
                (*vtx)++;
            }
        }

        for( var_a0 = 0; var_a0 < 2; var_a0++){
            for(var_v0 = -1; var_v0 < 3; var_v0+=2) {
                (*vtx)->v.ob[0] = (arg3[0] + (var_a0 * sp80[0]) + (var_v0 * sp68[0])) - sp5C[0];
                (*vtx)->v.ob[1] = (arg3[1] + (var_a0 * sp80[1]) + (var_v0 * sp68[1])) - sp5C[1];
                (*vtx)->v.ob[2] = (arg3[2] + (var_a0 * sp80[2]) + (var_v0 * sp68[2])) - sp5C[2];
                (*vtx)->v.tc[0] = 0;
                (*vtx)->v.tc[1] = 0;
                (*vtx)->v.cn[0] = 0;
                (*vtx)->v.cn[1] = 0;
                (*vtx)->v.cn[2] = 0;
                (*vtx)->v.cn[3] = 0;
                (*vtx)++;
            }
        }
        gDPPipeSync((*gfx)++);
        gDPSetPrimColor((*gfx)++, 0, 0, arg6[0], arg6[1], arg6[2], arg6[3]);
        gSP1Quadrangle((*gfx)++, 0, 1, 3, 2, 0);
        gSP1Quadrangle((*gfx)++, 4, 5, 7, 6, 0);
    }
}

void func_80242BE8(Gfx **gfx, Vtx **vtx, f32 arg2[2][2][2][3], s32 color[3], s32 alpha_values[3], s32 cull_back)
{
    f32 vp_position[3];
    #define var_v0 ((f32*)((u8*)arg2 + (i << 2) * sizeof(f32[3]) + (j << 1) * sizeof(f32[3]) + k * sizeof(f32[3])))
    s32 i;
    s32 j;
    s32 k;
    
    viewport_getPosition_vec3f(vp_position);

    gSPDisplayList((*gfx)++, sGfxSublist);

    if (cull_back){
        gSPSetGeometryMode((*gfx)++, G_CULL_BACK);
    }  else  {
        gSPSetGeometryMode((*gfx)++, G_CULL_FRONT);
    }

    gSPVertex((*gfx)++, *vtx, 8, 0);

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                (*vtx)->v.ob[0] = var_v0[0] - vp_position[0];
                (*vtx)->v.ob[1] = var_v0[1] - vp_position[1];
                (*vtx)->v.ob[2] = var_v0[2] - vp_position[2];
                (*vtx)->v.flag  = 0;
                (*vtx)->v.tc[0] = 0;
                (*vtx)->v.tc[1] = 0;
                (*vtx)->v.cn[0] = 0;
                (*vtx)->v.cn[1] = 0;
                (*vtx)->v.cn[2] = 0;
                (*vtx)->v.cn[3] = 0;
                (*vtx)++;
            }
        }
    }

    #undef var_v0

    gDPPipeSync((*gfx)++);
    gDPSetPrimColor((*gfx)++, 0, 0, color[0], color[1], color[2], alpha_values[0]);
    gSP2Triangles((*gfx)++, 7, 3, 5, 0, 5, 3, 1, 0);
    gSP1Quadrangle((*gfx)++, 6, 4, 0, 2, 0);
    
    gDPPipeSync((*gfx)++);
    gDPSetPrimColor((*gfx)++, 0, 0, color[0], color[1], color[2], alpha_values[1]);
    gSP1Quadrangle((*gfx)++, 7, 6, 2, 3, 0);
    gSP2Triangles((*gfx)++, 4, 5, 0, 0, 5, 1, 0, 0);
    
    gDPPipeSync((*gfx)++);
    gDPSetPrimColor((*gfx)++, 0, 0, color[0], color[1], color[2], alpha_values[2]);
    gSP1Quadrangle((*gfx)++, 5, 4, 6, 7, 0);
    gSP2Triangles((*gfx)++, 0, 1, 2, 0, 1, 3, 2, 0);
}
