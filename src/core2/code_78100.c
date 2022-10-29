#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_802FB0E4(struct8s *);

/* .data */
extern u16 D_8036A070[0xD][0x10];
extern enum asset_e D_8036A210[5];
extern Gfx D_8036A228[];

/* .bss */
u16 D_80381620[0xD][5][0x10];
BKSprite *D_80381E40[5];
f32   D_80381E54;
u8    D_80381E58[5];
f32   D_80381E60[5];
f32   D_80381E78[5];
struct7s D_80381E90;


/* .code */
#ifndef nonmatching
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_78100/func_802FF090.s")
#else
struct7s *func_802FF090(s32 arg0) {
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

void fxjinjoscore_free(enum item_e item_id, struct8s * arg1){
    s32 i;

    for(i = 0; i < 5; i++){
        if(D_80381E40[i] != NULL){
            func_8033BD4C(D_80381E40[i]);
            D_80381E40[i] = NULL;
        }
    }

}

//fxjinjoscore_draw
void fxjinjoscore_draw(s32 arg0, struct8s *arg1, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    BKSprite *sprite; // s1
    s32 draw_index; // s5
    s32 texture_width; // sp11C
    s32 texture_height; // sp118
    s32 jinjo_id; // sp114
    f32 center_y; // f14 (sp110)
    f32 center_x; // f20 (sp10C)
    f32 x_offset; // f26 (sp108)
    f32 y_offset; // f28 (sp104)
    f32 pos_x; // f30 (sp100)
    s32 i; // v1 (spFC)
    s32 j; // v0_2 (spF8)

    gSPDisplayList((*gfx)++, D_8036A228);
    func_8024C7B8(gfx, mtx);
    pos_x = 44.0f;
    // Draw all jinjo heads
    for(jinjo_id = 0; jinjo_id < 5; jinjo_id++){
        s32 jinjo_collected; // spF0 <----
        sprite = D_80381E40[jinjo_id];
        jinjo_collected = (D_80381E58[jinjo_id] != 0) ? 1 : 0;
        if (sprite != NULL) {
            func_80347FC0(gfx, sprite, (s32) D_80381E60[jinjo_id], 0, 0, 0, 0, 2, 2, &texture_width, &texture_height);
            // Load the palette for the corresponding jinjo color
            gDPLoadTLUT_pal16((*gfx)++, 0, D_80381620[(s32)D_80381E60[jinjo_id]][jinjo_id]);
            x_offset = 0.0f;
            y_offset = 0.0f;
            // Draw the jinjo head, once if uncollected and twice if collected
            // If the head is drawn twice then the first draw will be the drop shadow
            for (draw_index = jinjo_collected; draw_index >= 0; draw_index--){
                gDPPipeSync((*gfx)++);
                // Draw 0 is the jinjo's head, anything else is a shadow
                if (draw_index != 0) {
                    // Use only primitive color as the color input in order to make a solid color shadow
                    gDPSetCombineLERP((*gfx)++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
                    // Set up a translucent black for primitive color to draw the shadow
                    gDPSetPrimColor((*gfx)++, 0, 0, 0x00, 0x00, 0x00, 0x8C);
                } else {
                    // Use the texture as the color input
                    gDPSetCombineLERP((*gfx)++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
                    // If the jinjo is collected then it's drawn fully opaque, otherwise it's drawn with partial alpha
                    gDPSetPrimColor((*gfx)++, 0, 0, 0x00, 0x00, 0x00, jinjo_collected ? 0xFF : 0x6E);
                }
                center_x = pos_x - (f32) D_80276588 / 2 + x_offset;
                center_y = (f32) D_8027658C / 2 + func_802FB0E4(arg1) - 266.0f + 40.0f + y_offset - D_80381E78[jinjo_id];
                gSPVertex((*gfx)++, *vtx, 4, 0);
                // Set up the positions of the four vertices
                for(i = 0; i < 2; i++){
                    for(j = 0; j  < 2; j++){
                        (*vtx)->v.ob[0] = ((texture_width  * D_80381E54 * j) - (texture_width  * D_80381E54 / 2) + center_x) * 4;
                        (*vtx)->v.ob[1] = ((texture_height * D_80381E54 / 2) - (texture_height * D_80381E54 * i) + center_y) * 4;
                        (*vtx)->v.ob[2] = -20;
                        (*vtx)->v.tc[0] = ((texture_width  - 1) * j) << 6;
                        (*vtx)->v.tc[1] = ((texture_height - 1) * i) << 6;
                        (*vtx)++;
                    }
                }
                // Draw a quad made of the four vertices
                gSP1Quadrangle((*gfx)++, 0, 1, 3, 2, 0);
                x_offset += -2;
                y_offset += 2;
            }
        }
        // Move the next jinjo head over by 32 pixels
        pos_x += 32.0f;
    }
    gDPPipeSync((*gfx)++);
    gDPSetTextureLUT((*gfx)++, G_TT_NONE);
    gDPPipelineMode((*gfx)++, G_PM_NPRIMITIVE);
    func_8024C904(gfx, mtx);
}

bool func_802FFA10(f32 arg0, s32 arg1, s32 arg2){
    if(arg1 == 0){
        return TRUE;
    }

    return (D_80381E78[arg1 - 1] < arg0);
}

void fxjinjoscore_update(enum item_e item_id, struct8s *arg1) {
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
            fxjinjoscore_free(item_id, arg1);
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

