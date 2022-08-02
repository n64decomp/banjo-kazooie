#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_802FB0E4(struct8s *);

/* .data */
extern u16 D_8036A070[0xD][0x10];
extern enum asset_e D_8036A210[5];
extern Gfx D_8036A228[];

/* .bss */
extern u16 D_80381620[0xD][5][0x10];
extern BKSprite *D_80381E40[5];
extern f32   D_80381E54;
extern u8    D_80381E58[5];
extern f32   D_80381E60[5];
extern f32   D_80381E78[5];
extern struct8s D_80381E90;


/* .code */
#ifndef nonmatching
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_78100/func_802FF090.s")
#else
struct8s *func_802FF090(s32 arg0) {
    f32 *var_s6;
    f64 temp_f20;
    f64 temp_f22;
    f64 temp_f28;
    s32 temp_t6;
    s32 temp_t8;
    s32 green;
    s32 blue;
    s32 red;
    s32 alpha;
    s32 tmp_blue;
    s32 tmp_green;
    s32 tmp_red;
    s32 tmp_alpha;
    s32 var_t2;
    s8 *var_s5;
    u16 *var_ra;
    u16 *var_t3;
    u16 rgba;
    u32 jinjo_id;
    void *var_s3;
    void *var_t4;
    s32 i;

    D_80381E54 = 1.0f;
    for(jinjo_id = 0; jinjo_id < 5; jinjo_id++){
        D_80381E60[jinjo_id] = 0.0f;
        D_80381E58[jinjo_id] = (item_getCount(ITEM_12_JINJOS) & (1 << jinjo_id)) ? 3 : 0;
        for(i = 0; i < 0xD; i++){
            for(var_t2 = 0; var_t2 < 0x10; var_t2++){
                rgba = D_8036A070[i][var_t2];
                red   = tmp_red = (rgba >> 0xB) & 0x1F;
                green = tmp_green = (rgba >> 6) & 0x1F;
                blue  = tmp_blue = (rgba >> 1) & 0x1F;
                alpha = tmp_alpha = (rgba >> 0) & 0x1;
                if ((red < 0x10) || (green < 0x10) || (blue < 0x10)) {
                    switch (jinjo_id) {
                        case 3:
                            red   = tmp_red;
                            green = tmp_green;
                            blue  = tmp_blue;
                            alpha = tmp_alpha;
                            break;
                            
                        case 0:
                            green = tmp_green * 1.5;
                            red = tmp_red * 0.25;
                            blue  = tmp_blue;
                            alpha = tmp_alpha;
                            break;

                        case 1:
                            red   = tmp_red * 0.2;
                            green = tmp_blue;
                            blue  = tmp_blue * 0.2;
                            alpha = tmp_alpha;
                            break;

                        case 2:
                            {s32 var_v1;
                            red = tmp_red;
                            blue = tmp_green * 0.4;
                            green = tmp_blue * 0.6;
                            alpha = tmp_alpha;
                            }
                            break;
                        case 4:
                            red = tmp_red;
                            green = tmp_blue;
                            blue = tmp_green * 0.4;
                            alpha = tmp_alpha;
                            break;
                    }
                }
                D_80381620[i][jinjo_id][var_t2] = ((red << 0xB) | (green << 6) | (blue << 1) | alpha);
            }
        }
    }
    return &D_80381E90;
}
#endif

void func_802FF358(enum item_e item_id, struct8s * arg1){
    s32 i;

    for(i = 0; i < 5; i++){
        if(D_80381E40[i] != NULL){
            func_8033BD4C(D_80381E40[i]);
            D_80381E40[i] = NULL;
        }
    }

}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_78100/func_802FF3B8.s")
#else
void func_802FF3B8(s32 arg0, struct8s *arg1, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    s32 sp11C;
    s32 sp118;
    s32 sp114;
    s32 spF0;
    f32 temp_f14;
    f32 temp_f20;
    f32 var_f28;
    f32 var_f30;
    BKSprite *temp_a1;
    s32 var_s5;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;

    gSPDisplayList((*gfx)++, D_8036A228);
    func_8024C7B8(gfx, mtx);
    var_f30 = 44.0f;
    for(sp114 = 0; sp114 < 5; sp114++){
        temp_a1 = D_80381E40[sp114];
        spF0 = (D_80381E58[sp114] != 0) ? 1 : 0;
        if (temp_a1 != NULL) {
            var_f28 = 0.0f;
            func_80347FC0(gfx, temp_a1, (s32) D_80381E60[sp114], 0, 0, 0, 0, 2, 2, &sp11C, &sp118);
            gDPSetTextureImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_80381620[(s32)D_80381E60[sp114]][sp114]);
            // gDPSetTextureImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0);
            gDPTileSync((*gfx)++);
            gDPSetTile((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPLoadSync((*gfx)++);
            gDPLoadTLUTCmd((*gfx)++, G_TX_LOADTILE, 15);
            gDPPipeSync((*gfx)++);
            for (var_s5 = spF0; var_s5 >= 0; var_s5--){
                gDPPipeSync((*gfx)++);
                if (spF0) {
                    gDPSetCombineLERP((*gfx)++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
                    gDPSetPrimColor((*gfx)++, 0, 0, 0x00, 0x00, 0x00, 0x8C);
                } else {
                    gDPSetCombineLERP((*gfx)++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
                    gDPSetPrimColor((*gfx)++, 0, 0, 0x00, 0x00, 0x00, spF0 ? 0xFF : 0x6E);
                }
                temp_f20 = (var_f30 - ((f32) D_80276588 / 2)) - var_f28;
                temp_f14 = ((((f32) D_8027658C / 2) + func_802FB0E4(arg1)) - 266.0f + 40.0f + var_f28) - D_80381E78[sp114];
                gSPVertex((*gfx)++, *vtx, 4, 0);
                for(var_v1 = 0; var_v1 < 2; var_v1++){
                    for(var_v0_2 = 0; var_v0_2  < 2; var_v0_2++){
                        (*vtx)->v.ob[0] = (s16) (s32) (((((sp11C * D_80381E54) * (f32) var_v0_2) - ((sp11C * D_80381E54) / 2)) + temp_f20) * 4);
                        (*vtx)->v.ob[1] = (s16) (s32) (((((sp118 * D_80381E54) / 2) - ((sp118 * D_80381E54) * var_v1)) + temp_f14) * 4);
                        (*vtx)->v.ob[2] = -0x14;
                        (*vtx)->v.tc[0] = (s16) (((sp11C - 1) * var_v0_2) << 6);
                        (*vtx)->v.tc[1] = (s16) (((sp118 - 1) * var_v1) << 6);
                        (*vtx)++;
                    }
                }
                gSP1Quadrangle((*gfx)++, 0, 1, 3, 2, 0);
                var_f28 += 2.0f;
            }
        }
        var_f30 += 32.0f;
    }
    gDPPipeSync((*gfx)++);
    gDPSetTextureLUT((*gfx)++, G_TT_NONE);
    gDPPipelineMode((*gfx)++, G_PM_NPRIMITIVE);
    func_8024C904(gfx, mtx);
}
#endif;

bool func_802FFA10(f32 arg0, s32 arg1, s32 arg2){
    if(arg1 == 0){
        return TRUE;
    }

    return (D_80381E78[arg1 - 1] < arg0);
}

void func_802FFA50(enum item_e item_id, struct8s *arg1) {
    f32 var_f24;
    s32 temp_s3;
    s32 jinjo_id;
    s32 sp78;

    var_f24 = time_getDelta();
    temp_s3 = func_802FB0D4(arg1);
    sp78 = item_getCount(item_id);
    switch(temp_s3){
        case 1:
            for(jinjo_id = 0; jinjo_id < 5; jinjo_id++){
                if (D_80381E40[jinjo_id] == NULL) {
                    D_80381E40[jinjo_id] = assetcache_get(D_8036A210[jinjo_id]);
                    D_80381E78[jinjo_id] = 64.0f;
                }
            }
            break;

        case 0:
            func_802FF358(item_id, arg1);
            break;
        
        default:
            break;
    }

    if (temp_s3 != 0) {
        for(jinjo_id = 0; jinjo_id < 5; jinjo_id++){
            switch (D_80381E58[jinjo_id]) {
                case 0:
                    if (((1 << jinjo_id) & sp78) && (temp_s3 == 2) && (D_80381E78[jinjo_id] < 1.0f)) {
                        D_80381E58[jinjo_id] = 2;
                        func_8030E560(SFX_3EE, 26000);
                    }
                    break;
                case 2:
                    D_80381E60[jinjo_id] += var_f24 * 15.0;
                    if ((s32) D_80381E60[jinjo_id] >= 9) {
                        D_80381E60[jinjo_id] = 9.0f;
                        D_80381E58[jinjo_id] = 3;
                    }
                    break;
                case 1:
                    if (0.95 < randf2(0.0f, 1.0f)) {
                        D_80381E58[jinjo_id] = 4;
                    }
                    break;
                case 4:
                    D_80381E60[jinjo_id] += var_f24 * 30.0;
                    if ((s32) D_80381E60[jinjo_id] >= 12) {
                        D_80381E58[jinjo_id] = 3;
                        D_80381E60[jinjo_id] = 12.0f;
                    }
                    break;
                case 3:
                    D_80381E60[jinjo_id] -= var_f24 * 30.0;
                    if ((s32) D_80381E60[jinjo_id] < 10) {
                        D_80381E60[jinjo_id] = 9.0f;
                        D_80381E58[jinjo_id] = 1;
                    }
                    break;
            }

            switch (temp_s3) {                      /* switch 1; irregular */
                case 3:                                 /* switch 1 */
                    break;
                case 1:                                 /* switch 1 */
                case 2:                                 /* switch 1 */
                    if (func_802FFA10(15.0f, jinjo_id, 5)) {
                        if (D_80381E78[jinjo_id] >= 1.0f) {
                            D_80381E78[jinjo_id] *= 0.6;
                        }
                    }
                    break;
            }
        }
    }
}

