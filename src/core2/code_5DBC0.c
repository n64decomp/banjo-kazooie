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
    BKSprite *unk0;
    u8 unk4;
    // u8 pad5[0x3];
    BKSpriteTextureBlock **unk8;
    u8 unkC;
    u8 unkD;
    u8 padE[0x2];
}struct5DBC0_2s;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u16 unkC;
    u8  unkE;
    u8  padF[1];
    u8 unk10[0xC];
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

extern u8 D_80368830[3] = {0,0,0};

/* .bss */
struct5DBC0s * D_8037E900;

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E4C0C.s")
// s32 func_802E4C0C(struct5DBC0_3s * arg0, u32 arg1){
//     u32 i, v0;
//     for(i = arg1; i > 0; i--){
//         v0 = i - 1;
//         assetcache_release(arg0[v0].unk0);
//         free(arg0[v0].unk8);
//     }
//     free(arg0);
// }

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

extern s32 func_802E4CF8(u8);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E4CF8.s")

BKSpriteTextureBlock *func_802E4D5C(s32 arg0, char arg1){
    return D_8037E900->unk4[arg0].unk8[arg1 - 0x21];
}

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

s32 func_802E4E54(u8 arg0) {
    s32 sp24;

    sp24 = func_802E4CF8(arg0);
    if (sp24 == -1) {
        sp24 = D_8037E900->unk10++;
        if (D_8037E900->unk10 > 1) {
            D_8037E900->unk4 = (struct5DBC0_2s *)realloc(D_8037E900->unk4, (D_8037E900->unk10 + 1)*sizeof(struct5DBC0_2s));
        }
        D_8037E900->unk4[sp24].unk4 = arg0;
        D_8037E900->unk4[sp24].unk0 = (BKSprite *)assetcache_get(arg0 + 0x6E9);
        D_8037E900->unk4[sp24].unk8 = func_802E4D8C(D_8037E900->unk4[sp24].unk0);
        D_8037E900->unk4[sp24].unkC = D_8037E900->unk4[sp24].unk8[0x36]->x/2;
        D_8037E900->unk4[sp24].unkD = D_8037E900->unk4[sp24].unk8[0x36]->y;
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E502C.s")

void func_802E5188(void){
    D_8037E900->unkC = 0;
    D_8037E900->string_len = 0;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E51A4.s")
#else
s32 func_802E51A4(char *str, s32 arg1, s32 start, u32 flags) {
    s32 tab_width;
    s32 position;
    char *var_s1;
    s32 i;

    if (flags & 2) {
        return  2 * D_8037E900->unk4[arg1].unkC *strlen(str);
    }

    position = start;
    for(var_s1 = str; *var_s1 != '\0'; var_s1++){
        if (*var_s1 == ' ') {
            position += D_8037E900->unk4[arg1].unkC;
        } else if (*var_s1 == '\t') {
            position++;
            tab_width = 4*D_8037E900->unk4[arg1].unkC;
            while (position % tab_width) { position++; };
        } else {
            position += func_802E4D5C(arg1, *var_s1)->x;
        }
    }
    return position - start;
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E533C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E57E0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E5F88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E5FE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E60D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6270.s")

void func_802E632C(u8 arg0, u8 arg1, u8 arg2){
    D_8037E900->unk1C[0] = arg0;
    D_8037E900->unk1C[1] = arg1;
    D_8037E900->unk1C[2] = arg2;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E635C.s")
#else
void func_802E635C(u16 arg0){
    D_8037E900->unk1C[0] = (arg0 >> 0xb) << 3;
    D_8037E900->unk1C[1] = (arg0 >> 0x1) << 3;
    D_8037E900->unk1C[2] = (arg0 >> 0x6) << 3;
}
#endif

u8 func_802E639C(u8 arg0, f32 arg1){
    s32 var_v1;
    
    var_v1 = (s32)((f32)(s32)arg0 *arg1);
    var_v1 = (var_v1 > 0xFF) ? 0xff : var_v1;
    return var_v1;
}

void func_802E63D8(u8 arg0, u8 arg1, u8 arg2, f32 arg3){
    func_802E632C(func_802E639C(arg0, arg3),  func_802E639C(arg1, arg3), func_802E639C(arg2, arg3));

}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6558.s")

void func_802E65E8(char *str){
    func_802E51A4(str, func_802E4E54(0), 0, D_8037E900->flags);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E66F0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5DBC0/func_802E6BD0.s")
