#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    void *unk0;
    u8 pad4[0x4];
    s32 *unk8;
    u8 padC[0x4];
}struct5DBC0_3s;

typedef struct {
    BKSprite *font_bin;
    u8 font_id;
    // u8 pad5[0x3];
    BKSpriteTextureBlock **letter_texture;
    u8 half_width;
    u8 height;
    u8 padE[0x2];
}struct5DBC0_2s;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u16 unkC;
    u8  unkE;
    u8  unkF[3];
    u8  unk12[3];
    u8  pad15[0x3];
    s32 unk18;
}struct5DBC0_1s;

typedef struct {
    struct5DBC0_1s *    unk0;
    struct5DBC0_2s *    unk4;
    char *              string;
    s32                 unkC;
    s32                 unk10;
    s32                 string_len;
    u32                 flags;
    u8                  unk1C[3];
    u8                  pad1F[1];
}struct5DBC0s;

u8 D_80368830[3] = {0xFF, 0x8B, 0};
u8 D_80368834[3] = {0xFF, 0x8B, 0};
u8 D_80368838[3] = {0xFF, 0x8B, 0};
u8 D_8036883C[3] = {0xFF, 0x8B, 0};
u8 D_80368840[3] = {0xFF, 0xFF, 0XFF};
u8 D_80368844[3] = {0xFF, 0x00, 0X46};
u8 D_80368848[3] = {0xFF, 0x8B, 0};

/* .bss */
struct5DBC0s * D_8037E900;

/* public */
void func_802E6820(s32 arg0);

/* .code */
struct5DBC0s *func_802E4B50(void){
    u8 sp24[3] = D_80368830;
    D_8037E900 = (struct5DBC0s *)malloc(sizeof(struct5DBC0s));
    D_8037E900->unk0 = (struct5DBC0_1s *) malloc(sizeof(struct5DBC0_1s));
    D_8037E900->unkC = 0;
    D_8037E900->unk4 = (struct5DBC0_2s *) malloc(sizeof(struct5DBC0_2s));
    D_8037E900->unk10 = 0;
    D_8037E900->string = (char *) malloc(sizeof(char));
    D_8037E900->string_len = 0;
    D_8037E900->flags = 0;
    D_8037E900->unk1C[0] = sp24[0];
    D_8037E900->unk1C[1] = sp24[1];
    D_8037E900->unk1C[2] = sp24[2];
    return D_8037E900;
}

void func_802E4C0C(struct5DBC0_2s *arg0, u32 arg1)
{
    while(arg1--){
        assetcache_release(arg0[arg1].font_bin);   
        free(arg0[arg1].letter_texture);
    }
    free(arg0);
}

void func_802E4C78(void){
    if(D_8037E900->unk0 != NULL){
        free(D_8037E900->unk0);
    }
    if(D_8037E900->unk4 != NULL){
        func_802E4C0C(D_8037E900->unk4, D_8037E900->unk10);
    }
    if(D_8037E900->string != NULL){
        free(D_8037E900->string);
    }
    free(D_8037E900);
    D_8037E900 = NULL;
}

s32 func_802E4CF8(u8 arg0) {
    u32 var_v1;
    var_v1 = D_8037E900->unk10;
    while(var_v1--){
        if (arg0 == D_8037E900->unk4[var_v1].font_id) {
            return var_v1;
        }
    }
    return -1;
}

BKSpriteTextureBlock *func_802E4D5C(s32 arg0, char arg1){
    return D_8037E900->unk4[arg0].letter_texture[arg1 - 0x21];
}

/* font_bin to char texture blocks */
BKSpriteTextureBlock **func_802E4D8C(BKSprite *sprite) {
    BKSpriteFrame *frame;
    BKSpriteTextureBlock **chunkPtrArray;
    BKSpriteTextureBlock *chunk;
    s32 var_v1;
    s32 i;
    s32 chunk_size;

    frame = spriteGetFramePtr(sprite, 0);
    chunkPtrArray = (BKSpriteTextureBlock **)malloc((frame->chunkCnt + 1)*4);
    chunk = (BKSpriteTextureBlock *)(frame + 1);
    for (i = 0; i < frame->chunkCnt; i++) {
        chunkPtrArray[i] = chunk;
        chunk_size = (chunk->w * chunk->h);
        var_v1 = (s32)(chunk + 1);
        while ((var_v1 % 8)) {var_v1++;}
        chunk = (BKSpriteTextureBlock *)(var_v1 + chunk_size);
    }
    return chunkPtrArray;
}

/* get index  from font_id */
s32 func_802E4E54(u8 font_id) {
    s32 sp24;

    sp24 = func_802E4CF8(font_id);
    if (sp24 == -1) { //font not loaded
        sp24 = D_8037E900->unk10++;
        if (D_8037E900->unk10 > 1) {
            D_8037E900->unk4 = (struct5DBC0_2s *)realloc(D_8037E900->unk4, (D_8037E900->unk10 + 1)*sizeof(struct5DBC0_2s));
        }
        D_8037E900->unk4[sp24].font_id = font_id;
        D_8037E900->unk4[sp24].font_bin = (BKSprite *)assetcache_get(font_id + 0x6E9);
        D_8037E900->unk4[sp24].letter_texture = func_802E4D8C(D_8037E900->unk4[sp24].font_bin);
        D_8037E900->unk4[sp24].half_width = D_8037E900->unk4[sp24].letter_texture['W' - 0x21]->x/2;
        D_8037E900->unk4[sp24].height = D_8037E900->unk4[sp24].letter_texture['W' - 0x21]->y;
    }
    func_802E6820(5);
    return sp24;
}

s32 func_802E4F98(char *arg0) {
    s32 sp1C;
    s32 temp_a2;


    sp1C = D_8037E900->string_len;
    D_8037E900->string_len += strlen(arg0) + 1;
    if (D_8037E900->string_len >= 2) {
        D_8037E900->string = (char *)realloc(D_8037E900->string, D_8037E900->string_len + 1);
    }
    strcpy(D_8037E900->string + sp1C, arg0);
    return sp1C;
}

void func_802E502C(s32 arg0, s32 arg1, s32 arg2, char *arg3, u8 rgb[3]) {
    s32 sp24;

    sp24 = D_8037E900->unkC++;
    if (D_8037E900->unkC >= 2) {
        D_8037E900->unk0 = realloc(D_8037E900->unk0, (D_8037E900->unkC * 0x1C) + 0x1C);
    }
    D_8037E900->unk0[sp24].unk0 = arg0;
    D_8037E900->unk0[sp24].unk4 = arg1;
    D_8037E900->unk0[sp24].unkE = arg2;
    D_8037E900->unk0[sp24].unkC = func_802E4F98(arg3);
    D_8037E900->unk0[sp24].unk8 = D_8037E900->flags;
    D_8037E900->unk0[sp24].unkF[0] = rgb[0];
    D_8037E900->unk0[sp24].unkF[1] = rgb[1];
    D_8037E900->unk0[sp24].unkF[2] = rgb[2];
    D_8037E900->unk0[sp24].unk18 = -1;
}

void func_802E5188(void){
    D_8037E900->unkC = 0;
    D_8037E900->string_len = 0;
}

s32 func_802E51A4(char *str, s32 arg1, s32 start, u32 flags) {
    s32 tab_width;
    s32 position;
    char *var_s1;
    s32 i;

    if (flags & 2) {
        return  2 * D_8037E900->unk4[arg1].half_width *strlen(str);
    }

    position = start;
    for(var_s1 = str; *var_s1; var_s1++){
        if (*var_s1 == ' ') {
            position += D_8037E900->unk4[arg1].half_width;
        } else if (*var_s1 == '\t') {
            position++;
            tab_width = 4*D_8037E900->unk4[arg1].half_width;
            while (position % tab_width) { position++; };
        } else {
            position += func_802E4D5C(arg1, *var_s1)->x;
        }
    }
    return position - start;
}

void func_802E533C(struct5DBC0_1s *arg0, char arg1, s32 *arg2, s32 *arg3, Gfx **gfx) {
    s32 timg;
    BKSpriteTextureBlock *chunk;

    if (arg1 == ' ') {
        *arg2 += D_8037E900->unk4[arg0->unkE].half_width;
    } else if (arg1 == '\t') { 
        (*arg2)++;
        while ((*arg2 % (s32) (D_8037E900->unk4[arg0->unkE].half_width * 4)) != 0) {
            (*arg2)++;
        }
    } else{
        chunk = func_802E4D5C(arg0->unkE, arg1);
        timg = (s32)(chunk + 1);
        while ((timg % 8)) {
            timg++;
        }

        gDPSetTextureImage((*gfx)++, G_IM_FMT_I, G_IM_SIZ_8b, chunk->w, timg);
        gDPSetTile((*gfx)++, G_IM_FMT_I, G_IM_SIZ_8b, (((((chunk->w - 0) + 1)*1) + 7) >> 3), 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
        gDPLoadSync((*gfx)++);
        gDPLoadTile((*gfx)++, G_TX_LOADTILE, 0, 0, (chunk->w << 2), (chunk->h << 2));
        gDPPipeSync((*gfx)++);
        gDPSetTile((*gfx)++, G_IM_FMT_I, G_IM_SIZ_8b, (((((chunk->w - 0) + 1)*1) + 7) >> 3), 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
        gDPSetTileSize((*gfx)++, G_TX_RENDERTILE, 0, 0, chunk->w << 2, chunk->h << 2);
        gSPScisTextureRectangle((*gfx)++, (*arg2 << 2), (*arg3 << 2), ((*arg2 + chunk->w) << 2), ((*arg3 + chunk->h) << 2), G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
        if (arg0->unk8 & 2) {
            *arg2 += D_8037E900->unk4[arg0->unkE].half_width * 2;
        }
        else{
            *arg2 += chunk->x;
        }
    }
}

void func_802E57E0(struct5DBC0_1s *arg0, Gfx **gfx) {
    s32 temp_v0;
    s32 spA8;
    s32 spA4;
    s32 var_s3;
    char var_s2;
    u32 var_a3;

    var_a3 = arg0->unk8;
    if (!(var_a3 & 4)) { //draw transparent grey background
        temp_v0 = func_802E51A4(&D_8037E900->string[arg0->unkC], arg0->unkE, arg0->unk0, var_a3);
        gDPPipeSync((*gfx)++);
        gDPSetPrimColor((*gfx)++, 0, 0, 0x28, 0x28, 0x28, 0x96);
        gDPSetCombineMode((*gfx)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gDPScisFillRectangle((*gfx)++, 
            (arg0->unk0 - 2),
            arg0->unk4,
            (arg0->unk0 + temp_v0 + 2),
            (D_8037E900->unk4[arg0->unkE].height + arg0->unk4)
        );
        gDPPipeSync((*gfx)++);
    }
    gDPSetCombineLERP((*gfx)++, PRIMITIVE, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, TEXEL0, PRIMITIVE, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, TEXEL0);

    if (arg0->unk18 == -1) {
        gDPSetPrimColor((*gfx)++, 0, 0, arg0->unkF[0], arg0->unkF[1], arg0->unkF[2], 0);
        gDPSetEnvColor((*gfx)++, arg0->unkF[0], arg0->unkF[1], arg0->unkF[2], 0);
        spA8 = arg0->unk0;
        spA4 = arg0->unk4;
        for(var_s3 = 0; (var_s2 = D_8037E900->string[var_s3 + arg0->unkC]) != 0; var_s3++) {
            func_802E533C(arg0, var_s2, &spA8, &spA4, gfx);
        }
    } else {
        spA8 = arg0->unk0;
        spA4 = arg0->unk4;
        for(var_s3 = 0; (var_s2 = D_8037E900->string[var_s3 + arg0->unkC]); var_s3++) {
            if (var_s3 == arg0->unk18) {
                gDPSetPrimColor((*gfx)++, 0, 0, arg0->unk12[0], arg0->unk12[1], arg0->unk12[2], 0x00);
                gDPSetEnvColor((*gfx)++, arg0->unk12[0], arg0->unk12[1], arg0->unk12[2], 0);
                if (var_s2 == ' ') {
                    s32 sp6C, sp68;
                    s32 sp64, sp60;
                    sp64 = spA4 - 5;\
                    sp60 = spA4 + 5;
                    sp68 = sp6C = spA8;
                    func_802E533C(arg0, '-', &sp6C, &sp64, gfx);
                    func_802E533C(arg0, '-', &sp68, &sp60, gfx);
                }
            } else {
                gDPSetPrimColor((*gfx)++, 0, 0, arg0->unkF[0], arg0->unkF[1], arg0->unkF[2], 0);
                gDPSetEnvColor((*gfx)++, arg0->unkF[0], arg0->unkF[1], arg0->unkF[2], 0);
            }
            func_802E533C(arg0, var_s2, &spA8, &spA4, gfx);
        }
    }
}

void func_802E5C98(Gfx **gdl){
    int i;

    gDPPipeSync((*gdl)++);
    gSPClearGeometryMode((*gdl)++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPTexture((*gdl)++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gSPSetGeometryMode((*gdl)++, G_TEXTURE_GEN_LINEAR);
    gDPSetCycleType((*gdl)++, G_CYC_1CYCLE);
    gDPPipelineMode((*gdl)++, G_PM_NPRIMITIVE);
    gDPSetTextureLOD((*gdl)++, G_TL_TILE);
    gDPSetTextureLUT((*gdl)++, G_TT_NONE);
    gDPSetTextureDetail((*gdl)++, G_TD_CLAMP);
    gDPSetTexturePersp((*gdl)++, G_TP_NONE);
    gDPSetTextureFilter((*gdl)++, G_TF_BILERP);
    gDPSetTextureConvert((*gdl)++, G_TC_FILT);
    gDPSetAlphaCompare((*gdl)++, G_AC_NONE);
    gDPSetRenderMode((*gdl)++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    for(i = 0; i < D_8037E900->unkC; i++){
        D_8037E900->unk0[i].unk4 -= 0x10;
        func_802E57E0(D_8037E900->unk0 + i, gdl);
        D_8037E900->unk0[i].unk4 += 0x10;
    }
    gDPSetTexturePersp((*gdl)++, G_TP_PERSP);
}

void func_802E5F10(Gfx **gdl){
    func_802E5C98(gdl);
    func_802E5188();
}

void func_802E5F38(void){
    D_8037E900 = func_802E4B50();
    func_802E4E54(0);
}

void func_802E5F68(void){
    func_802E4C78();
}

void func_802E5F88(s32 arg0, s32 arg1, char *arg2) {
    s32 sp24;
    u8 sp20[3] = D_80368834;
    
    sp24 =  func_802E4E54(0);
    func_802E502C(arg0, arg1, sp24, arg2, sp20);
}

void func_802E5FE4(s32 arg0, s32 arg1, char *arg2) {
    s32 sp24;
    u8 sp20[3] = D_80368838;
    
    sp24 =  func_802E4E54(0);
    func_802E502C(arg0, arg1, sp24, arg2, sp20);
}

void func_802E6040(s32 arg0, s32 arg1, char *arg2) {
    s32 sp2C;
    u8 sp28[3] = D_8036883C;

    sp2C = func_802E4E54(0);
    arg0 *= D_8037E900->unk4[sp2C].half_width;
    arg1 *= D_8037E900->unk4[sp2C].height;
    func_802E502C(arg0, arg1, sp2C, arg2, sp28);
}

void func_802E60D4(s32 arg0, s32 arg1, s32 arg2, char *arg3, u8 arg4[3], u8 arg5[3], s32 arg6) {
    s32 sp24;

    sp24 = D_8037E900->unkC++;
    if (D_8037E900->unkC >= 2) {
        D_8037E900->unk0 = (struct5DBC0_1s *)realloc(D_8037E900->unk0, (D_8037E900->unkC + 1)* sizeof(struct5DBC0_1s));
    }
    D_8037E900->unk0[sp24].unk0 = arg0;
    D_8037E900->unk0[sp24].unk4 = arg1;
    D_8037E900->unk0[sp24].unkE = arg2;
    D_8037E900->unk0[sp24].unkC = func_802E4F98(arg3);
    D_8037E900->unk0[sp24].unk8 = D_8037E900->flags;
    \
    D_8037E900->unk0[sp24].unkF[0] = arg4[0];
    D_8037E900->unk0[sp24].unkF[1] = arg4[1];
    D_8037E900->unk0[sp24].unkF[2] = arg4[2];

    D_8037E900->unk0[sp24].unk12[0] = arg5[0];
    D_8037E900->unk0[sp24].unk12[1] = arg5[1];
    D_8037E900->unk0[sp24].unk12[2] = arg5[2];

    D_8037E900->unk0[sp24].unk18 = arg6;
}

void func_802E6270(s32 arg0, s32 arg1, char *arg2, s32 arg3) {
    s32 temp_v0;
    u8 sp30[3] = D_80368840;
    u8 sp2C[3] = D_80368844;

    temp_v0 = func_802E4E54(0);
    arg0 *= D_8037E900->unk4[temp_v0].half_width;
    arg1 *= D_8037E900->unk4[temp_v0].height;
    func_802E60D4(arg0, arg1, temp_v0, arg2, sp30, sp2C, arg3);
}

void func_802E632C(u8 arg0, u8 arg1, u8 arg2){
    D_8037E900->unk1C[0] = arg0;
    D_8037E900->unk1C[1] = arg1;
    D_8037E900->unk1C[2] = arg2;
}

void func_802E635C(u16 arg0){
    D_8037E900->unk1C[0] = (u8)(arg0 >> 0xb) << 3;
    D_8037E900->unk1C[1] = (u8)(arg0 >> 0x1) << 3;
    D_8037E900->unk1C[2] = (u8)(arg0 >> 0x6) << 3;
}

u8 func_802E639C(u8 arg0, f32 arg1){
    s32 var_v1;
    
    var_v1 = (s32)((f32)(s32)arg0 *arg1);
    var_v1 = (var_v1 > 0xFF) ? 0xff : var_v1;
    return var_v1;
}

void func_802E63D8(u8 arg0, u8 arg1, u8 arg2, f32 arg3){
    func_802E632C(func_802E639C(arg0, arg3),  func_802E639C(arg1, arg3), func_802E639C(arg2, arg3));

}

u16 func_802E6440(void) {
    return (((((s32) D_8037E900->unk1C[0] >> 3) & 0x1F) << 11)
        | ((((s32) D_8037E900->unk1C[1] >> 3) & 0x1F) << 6)
        | ((((s32) D_8037E900->unk1C[2] >> 3) & 0x1F) << 1)
        | 1);
}

void func_802E6488(s32 arg0, s32 arg1, char *arg2) {
    s32 temp_v0;

    temp_v0 = func_802E4E54(0);
    arg0 *= D_8037E900->unk4[temp_v0].half_width;
    arg1 *= D_8037E900->unk4[temp_v0].height;
    func_802E502C(arg0, arg1, temp_v0, arg2, D_8037E900->unk1C);
}


void func_802E6508(s32 arg0, s32 arg1, char *arg2) {
    func_802E502C(arg0, arg1, func_802E4E54(0), arg2, D_8037E900->unk1C);
}


void func_802E6558(s32 arg0, s32 arg1, char *arg2) {
    u8 sp1C[3];
    void *temp_v0;

    temp_v0 = D_8037E900;
    sp1C[0] = D_8037E900->unk1C[0];
    sp1C[1] = D_8037E900->unk1C[1];
    sp1C[2] = D_8037E900->unk1C[2];
    func_802E632C(0xC8, 0xEB, 0xD2);
    func_802E6488(arg0, arg1, arg2);
    D_8037E900->unk1C[0] = sp1C[0];
    D_8037E900->unk1C[1] = sp1C[1];
    D_8037E900->unk1C[2] = sp1C[2];
}


void func_802E65E8(char *str){
    func_802E51A4(str, func_802E4E54(0), 0, D_8037E900->flags);
}

void func_802E6628(s32 arg0, char *arg1) {
    s32 sp2C;
    u8 sp28[3] = D_80368848;

    sp2C = func_802E4E54(0);
    arg0 *= D_8037E900->unk4[sp2C].height;
    func_802E502C((s32) (((f32) gFramebufferWidth - (f32) func_802E51A4(arg1, sp2C, 0, D_8037E900->flags)) / 2), arg0, sp2C, arg1, sp28);
}

void func_802E66F0(s32 arg0, char *arg1) {
    s32 sp24;
    s32 temp_v0;
    void *temp_v1;

    sp24 = func_802E4E54(0);
    arg0 *= D_8037E900->unk4[sp24].height;
    func_802E502C((s32) (((f32) gFramebufferWidth - (f32) func_802E51A4(arg1, sp24, 0, D_8037E900->flags)) / 2), arg0, sp24, arg1, D_8037E900->unk1C);
}

void func_802E67AC(void){
    D_8037E900->flags |= 1;
}

void func_802E67C4(void){
    D_8037E900->flags &= ~(0x1);
}

void func_802E67E0(s32 arg0){
    D_8037E900->flags |= arg0  & ~(0x1);
}

void func_802E6800(s32 arg0){
    D_8037E900->flags &= ~arg0 | 0x1;
}

void func_802E6820(s32 arg0) {
    BKSprite *prev_sprite_ptr;
    s32 chunk_count;
    s32 i_chunk;
    s32 var_s5;
    s32 var_s6;

    if (D_8037E900 != NULL) {
        for(var_s6 = 0; var_s6 < arg0; var_s6++){
            D_8037E900 = (struct5DBC0s *) defrag(D_8037E900);
            D_8037E900->unk0 = (struct5DBC0_1s *)defrag(D_8037E900->unk0);
            D_8037E900->unk4 = (struct5DBC0_2s *)defrag(D_8037E900->unk4);
            D_8037E900->string = (char *)defrag(D_8037E900->string);
            for(var_s5 = 0; var_s5 < D_8037E900->unk10; var_s5++) {
                if (D_8037E900->unk4[var_s5].letter_texture != NULL) {
                    D_8037E900->unk4[var_s5].letter_texture = (BKSpriteTextureBlock **)defrag(D_8037E900->unk4[var_s5].letter_texture);
                }
                
                prev_sprite_ptr = D_8037E900->unk4[var_s5].font_bin;
                if (D_8037E900->unk4[var_s5].font_bin != NULL) {
                    chunk_count = spriteGetFramePtr(prev_sprite_ptr, 0U)->chunkCnt;
                    D_8037E900->unk4[var_s5].font_bin = (BKSprite *)defrag_asset(D_8037E900->unk4[var_s5].font_bin);
                    for(i_chunk = 0; i_chunk < chunk_count; i_chunk++){
                        D_8037E900->unk4[var_s5].letter_texture[i_chunk] = ((u32)(((s32)D_8037E900->unk4[var_s5].letter_texture[i_chunk] - (s32)prev_sprite_ptr)) + (u32)D_8037E900->unk4[var_s5].font_bin);
                    }
                }
            }
        }
    }
}
