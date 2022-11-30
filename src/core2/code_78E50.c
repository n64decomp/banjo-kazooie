#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_802FB0E4(struct8s*);

/* .code */
enum asset_e D_8036A260[] = {0x7E0, 0x7E1, 0x7E2, 0x7E3, 0x7E4};
Gfx D_8036A278[] =
{
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPEndDisplayList(),
};


/* .bss */
void *D_80381EB0[2];
f32 D_80381EB8;
f32 D_80381EBC;
s32 D_80381EC0;
s32 D_80381EC4;
u8 D_80381EC8[8];
struct7s D_80381ED0;

/* .code */
s32 func_802FFDE0(s32 arg0){
    return D_8036A260[arg0/4];
}

s32 func_802FFE04(void){
    s32 v1;
    v1 = (5 < itemPrint_getValue(ITEM_14_HEALTH)) ? 5 : itemPrint_getValue(ITEM_14_HEALTH);
    return (5 - v1)*4;
}

struct7s *func_802FFE4C(s32 item_id){
    s32 i;

    D_80381EB8 = 1.0f;
    D_80381EBC = (f32)func_802FFE04();
    D_80381EC0 = func_802FFDE0((s32)D_80381EBC);
    D_80381EC4 = 0;
    for(i = 0; i < 2; i++){
        D_80381EB0[i] = NULL;
    }
    return &D_80381ED0;
}

void func_802FFED4(s32 item_id, struct8s *arg1){
    s32 i;
    for(i = 0; i < 2; i++){
        if(D_80381EB0[i] != NULL){
           func_8033BD4C(D_80381EB0[i]);
           D_80381EB0[i] = NULL;
        }
    };
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_78E50/func_802FFF34.s")
// void func_802FFF34(enum item_e item_id, struct8s *arg1, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
//     s32 sp10C;
//     Vtx *sp108;
//     s32 sp104;
//     s32 spF0;
//     s32 spEC;
//     s32 spE8;
//     s32 spE4;
//     s32 spE0;
//     s32 spDC;
//     Gfx *temp_a0;
//     Gfx *temp_v0;
//     Gfx *temp_v0_2;
//     Gfx *temp_v0_3;
//     Gfx *temp_v0_4;
//     Gfx *temp_v0_6;
//     Gfx *temp_v0_7;
//     Gfx *temp_v0_8;
//     Gfx *temp_v0_9;
//     f32 temp_f12;
//     f32 temp_f14;
//     f32 temp_f18;
//     f32 temp_f18_2;
//     f32 temp_f18_3;
//     f32 temp_f18_4;
//     f32 temp_f2;
//     s32 temp_a1;
//     s32 temp_lo;
//     s32 temp_s2;
//     s32 temp_s5;
//     s32 temp_t4;
//     s32 temp_t6;
//     s32 temp_v0_5;
//     s32 var_a1;
//     s32 var_a1_2;
//     s32 var_fp;
//     s32 var_s2;
//     s32 var_s4;
//     s32 var_s6;
//     s32 var_s7;
//     s32 var_v0;
//     s32 var_v0_2;
//     s32 var_v1;

//     sp10C = -1;
//     sp108 = *vtx;
//     D_80381EC8[0] = 0;
//     if (itemPrint_getValue() >= 10) {
//         var_a1 = 9;
//     } else {
//         var_a1 = itemPrint_getValue(item_id);
//     }
//     strIToA(&D_80381EC8, var_a1);
//     print_bold_spaced(0x4E, (s32) (func_802FB0E4(arg1) + -16.0f + 4.0f), D_80381EC8);
//     if (*(&D_80381EB0 + (D_80381EC4 * 4)) != 0) {
//         gSPDisplayList((*gfx)++, D_8036A278);
//         func_8024C7B8(gfx, mtx);
//         gDPPipeSync((*gfx)++);
//         gDPSetCombineLERP((*gfx)++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
//         gDPSetPrimColor((*gfx)++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
//         var_s2 = 2;
//         do {
//             func_80348044(gfx, D_80381EB0[D_80381EC4], (s32) D_80381EBC % 4, 0, 0, 0, 0, var_s2, var_s2, &spF0, &spEC, &spE8, &spE4, &spE0, &spDC, &sp10C);
//             temp_v0_5 = sp104 + 4;
//             if (((*vtx - sp108) & 0xF) == 0) {
//                 var_s4 = 0;
//                 var_s6 = 2;
//                 sp104 = 0;
//                 var_s7 = 6;
//                 temp_t4 = (sp10C + 1) * 4;
//                 if (temp_t4 >= 0x11) {
//                     var_v0 = 0x10;
//                 } else {
//                     var_v0 = temp_t4;
//                 }
//                 if (temp_t4 >= 0x11) {
//                     var_a1_2 = 0x10;
//                 } else {
//                     var_a1_2 = temp_t4;
//                 }
//                 //var_a1_2 = n
//                 // temp_a0->words.w0 = ((((var_a1_2 * 0x10) - 1) | (var_v0 << 0xA)) & 0xFFFF) | 0x04000000;
//                 // temp_a0->words.w1 = *vtx;
//                 gSPVertex((*gfx)++, *vtx, var_a1_2, var_v0);
//                 var_fp = 4;
//             } else {
//                 var_s4 = temp_v0_5 * 2;
//                 var_s6 = var_s4 + 2;
//                 var_s7 = var_s4 + 6;
//                 var_fp = var_s4 + 4;
//                 sp104 = temp_v0_5;
//             }
//             temp_s5 = (s32) ((40.0f - ((f32) framebuffer_width / 2.0f)) + (f32) spE0);
//             temp_f12 = (f32) temp_s5;
//             temp_f14 = (f32) (s32) (((((f32) framebuffer_height / 2.0f) - func_802FB0E4(arg1)) - -16.0f) - (f32) spDC);
//             for(var_v1 = 0; var_v1 != var_s2; var_v1++){
//                 temp_f2 = (f32) var_v1;
//                 temp_s2 = var_s2 - 1;
//                 for(var_v0_2 = 0; var_v0_2 != temp_s2; var_v0_2++) {
//                     (*vtx)->v.ob[0] = ((((f32) spF0 * D_80381EB8 * (f32) var_v0_2) - (((f32) spE8 * D_80381EB8) / 2.0f)) + temp_f12) * 4.0f;
//                     (*vtx)->v.ob[1] = (((((f32) spE4 * D_80381EB8) / 2.0f) - ((f32) spEC * D_80381EB8 * temp_f2)) + temp_f14) * 4.0f;
//                     (*vtx)->v.ob[2] = -20;
//                     (*vtx)->v.tc[0] = (s16) (((spF0 - 1) * var_v0_2) << 6);
//                     (*vtx)->v.tc[1] = (s16) (((spEC - 1) * var_v1) << 6);
//                     (*vtx)++;
//                 }
//                 temp_f18_3 = D_80381EB8;
//                 var_s2 = temp_s2 + 1;
//                 (*vtx)->v.ob[0] = (s16) (s32) (((((f32) spF0 * D_80381EB8 * (f32) var_v0_2) - (((f32) spE8 * D_80381EB8) / 2.0f)) + temp_f12) * 4.0f);
//                 (*vtx)->v.ob[1] = (s16) (s32) ((((((f32) spE4 * D_80381EB8) / 2.0f) - ((f32) spEC * D_80381EB8 * temp_f2)) + temp_f14) * 4.0f);
//                 (*vtx)->v.ob[2] = -20;
//                 (*vtx)->v.tc[0] = (s16) (((spF0 - 1) * var_v0_2) << 6);
//                 (*vtx)->v.tc[1] = (s16) (((spEC - 1) * var_v1) << 6);
//                 (*vtx)++;
//             }
            //    gSP2Triangles((*gfx)++, var_s4/2, var_fp/2, var_s7/2, 0, var_s4/2, var_s7/2, var_fp/2, 0);
//         } while (sp10C != 0);
//         gDPPipeSync((*gfx)++);
//         gDPSetTextureLUT((*gfx)++, G_TT_NONE);
//         gDPPipelineMode((*gfx)++, G_PM_NPRIMITIVE);
//         func_8024C904(gfx, mtx);
//     }
// }

void func_803005BC(enum item_e item_id, struct8s *arg1) {
    s32 var_v0;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    sp20 = (s32) ((f32) func_802FFE04() - D_80381EBC);
    switch (func_802FB0D4(arg1)) {
        case 1:
            if (D_80381EB0[D_80381EC4] == NULL) {
                D_80381EB0[D_80381EC4] = assetcache_get(D_8036A260[(s32) D_80381EBC / 5]);
            }
            break;

        case 0:
            func_802FFED4(item_id, arg1);
            break;

        case 2:
            if (sp20 != 0) {
                var_v0 = (sp20 >= 0) ? sp20 : -sp20;
                D_80381EBC = D_80381EBC + (0.5 * (sp20 / var_v0));
            }
            sp18 = func_802FFDE0((s32)D_80381EBC);
            if (sp18 != D_80381EC0) {
                D_80381EC4 = NOT(D_80381EC4);
                if (D_80381EB0[D_80381EC4] != 0) {
                    func_8033BD4C(D_80381EB0[D_80381EC4]);
                }
                D_80381EB0[D_80381EC4] = assetcache_get(sp18);
                D_80381EC0 = sp18;
            }
            break;
    }
}
