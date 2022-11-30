#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Gfx D_80275880[] = {
    gsSPClearGeometryMode(G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0060CD00),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2),
    gsSPEndDisplayList()
};

/* .code */
void func_80241490(Gfx **gfx, Vtx **vtx, s32 *arg2[3], s32 arg3[3], s32 arg4[3], s32 arg5[3], s32 arg6, s32 arg7) {
    s32 spB4[3];
    s32 var_a0;
    s32 var_v0;
    s32 var_v1;
    s32 sp78[3][4];
    s32 i;

    func_8024C5F0(&spB4);
    gSPDisplayList((*gfx)++, D_80275880);
    if (arg6 != 0) {
        gSPSetGeometryMode((*gfx)++, G_ZBUFFER | G_CULL_BACK);
    } else {
        gSPSetGeometryMode((*gfx)++, G_ZBUFFER | G_CULL_FRONT);
    }
    gSPVertex((*gfx)++, *vtx, 8, 0);
    for(i = 0; i < 2; i++){
        for(var_a0 = 0; var_a0 < 2; var_a0++){
            for(var_v1 = 0; var_v1 < 2; var_v1++){
                var_v0 = (var_v1 == 0) ? arg2[0] : arg3[0];
                (*vtx)->v.ob[0] = (s16) (var_v0 - spB4[0]);

                var_v0 = (i == 0) ? arg2[1] : arg3[1];
                (*vtx)->v.ob[1] = (s16) (var_v0 - spB4[1]);

                var_v0 = (var_a0 == 0) ? arg2[2] : arg3[2];
                (*vtx)->v.ob[2] = (s16) (var_v0 - spB4[2]);

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
                sp78[i][var_v1] = (arg4[var_v1] * arg5[i]) / 255;
            }
            sp78[i][3] = 0xFF;
        }
    } else {
        for(i = 0; i < 3; i++){
            for(var_v1 = 0; var_v1 < 3; var_v1++){
                sp78[i][var_v1] = arg4[var_v1];
            }
            sp78[i][3] = arg5[i];
        }
    }
    gDPPipeSync((*gfx)++);
    gDPSetPrimColor((*gfx)++, 0, 0, sp78[0][0], sp78[0][1], sp78[0][2], sp78[0][3]);
    gSP2Triangles((*gfx)++, 7, 3, 5, 0, 5, 3, 1, 0);
    gSP1Quadrangle((*gfx)++, 6, 4, 0, 2, 0);

    gDPPipeSync((*gfx)++);
    gDPSetPrimColor((*gfx)++, 0, 0, sp78[1][0], sp78[1][1], sp78[1][2], sp78[1][3]);
    gSP1Quadrangle((*gfx)++, 7, 6, 2, 3, 0);
    gSP2Triangles((*gfx)++, 4, 5, 0, 0, 5, 1, 0, 0);

    gDPPipeSync((*gfx)++);
    gDPSetPrimColor((*gfx)++, 0, 0, sp78[2][0], sp78[2][1], sp78[2][2], sp78[2][3]);
    gSP1Quadrangle((*gfx)++, 5, 4, 6, 7, 0);
    gSP2Triangles((*gfx)++, 0, 1, 2, 0, 1, 3, 2, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80241928.s")

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

        func_8024C5CC(sp5C);
        gSPDisplayList((*gfx)++, D_80275880);
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

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80242BE8.s")
#else
void func_80242BE8(Gfx **gfx, Vtx **arg1, f32 arg2[2][2][2][3], s32 arg3[3], s32 *arg4, s32 arg5) {
    f32 sp84[3];
    f32 *temp_a0;
    f32 *var_v0;
    f32 temp_f12;
    f32 var_f18;
    s32 temp_a2;
    s32 var_a2;
    s32 var_a3;
    s32 var_t2;
    s32 var_v1;
    void *temp_v0;
    void *temp_v0_10;
    void *temp_v0_11;
    void *temp_v0_12;
    void *temp_v0_13;
    void *temp_v0_14;
    void *temp_v0_15;
    void *temp_v0_16;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v0_9;

    func_8024C5CC(sp84);
    gSPDisplayList((*gfx)++, D_80275880);
    var_t2 = 0;
    if(arg5){
        gSPSetGeometryMode((*gfx)++, G_CULL_BACK);
    }
    else{
        gSPSetGeometryMode((*gfx)++, G_CULL_FRONT);
    }
    gSPVertex((*gfx)++, *arg1, 8, 0);
    for(var_t2 = 0; var_t2 < 2; var_t2++){
        for(var_a3 = 0; var_a3 < 2; var_a3++){
            for(var_v1 = 0; var_v1 < 2; var_v1++){
                (*arg1)->v.ob[0] = arg2[var_t2][var_a3][var_v1][0] - sp84[0];
                (*arg1)->v.ob[1] = arg2[var_t2][var_a3][var_v1][1] - sp84[1];
                (*arg1)->v.ob[2] = arg2[var_t2][var_a3][var_v1][2] - sp84[2];
                (*arg1)->v.flag  = 0;
                (*arg1)->v.tc[0] = 0;
                (*arg1)->v.tc[1] = 0;
                (*arg1)->v.cn[0] = 0;
                (*arg1)->v.cn[1] = 0;
                (*arg1)->v.cn[2] = 0;
                (*arg1)->v.cn[3] = 0;
                (*arg1)++;
            }
        }
    }
    gDPPipeSync((*gfx)++);
    gDPSetPrimColor((*gfx)++, 0, 0, arg3[0], arg3[1], arg3[2], *arg4);
    gSP2Triangles((*gfx)++, 7, 3, 5, 0, 5, 3, 1, 0);
    gSP1Quadrangle((*gfx)++, 6, 4, 0, 2, 0);

    gDPPipeSync((*gfx)++);
    gDPSetPrimColor((*gfx)++, 0, 0, arg3[0], arg3[1], arg3[2], *arg4);
    gSP1Quadrangle((*gfx)++, 7, 6, 2, 3, 0);
    gSP2Triangles((*gfx)++, 4, 5, 0, 0, 5, 1, 0, 0);

    gDPPipeSync((*gfx)++);
    gDPSetPrimColor((*gfx)++, 0, 0, arg3[0], arg3[1], arg3[2], *arg4);
    gSP1Quadrangle((*gfx)++, 5, 4, 6, 7, 0);
    gSP2Triangles((*gfx)++, 0, 1, 2, 0, 1, 3, 2, 0);
}
#endif
