#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    s16 x;
    s16 y;
    u8 pad4[0x4];
    u8 unk8;
    u8 pad9[0x7];
    f32 unk10;
    u8 *string;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
} PrintBuffer;

typedef struct font_letter{
    void *unk0;//chunkPtr
    void *unk4;//palPtr
} FontLetter;

typedef struct map_font_texture_map{
    s16 mapID;
    s16 assetId;
} MapFontTextureMap;

extern struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} D_80369078;

extern MapFontTextureMap D_8036907C[];

extern u8 D_80369200[];


extern s8 D_80380AB0;
extern BKSprite *D_80380AB8[0x5];

extern FontLetter *D_80380AD0[4];
extern PrintBuffer *D_80380AE0;
extern PrintBuffer *D_80380AE4;
extern struct {
    s32 unk0;   
}D_80380AE8;

extern s32 D_80380AEC;
extern s32 D_80380AF0;
extern s32 D_80380AF4;
extern s32 D_80380AF8;
extern s32 D_80380AFC;
extern s32 D_80380B00;
extern s32 D_80380B04;
extern s32 D_80380B08;
extern s32 D_80380B0C;
extern s32 D_80380B10;
extern s32 D_80380B14;

extern s32 D_80380B18;
extern s32 D_80380B1C;

extern s8 D_80380F20[0x80];

//returns map texture assetID for current map;
enum asset_e func_802F49C0(void){
    s32 i;
    for(i = 0; D_8036907C[i].mapID != 0 ; i++){
        if(func_803348C0() == D_8036907C[i].mapID){
            return D_8036907C[i].assetId;
        }
    }
    return 0x708;
}

// this function reassigns the referenced font mask pixel 
// using the texture @ pixel (x,y) 
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F4A24.s")
/*void func_802F4A24(BKSpriteTextureBlock *arg0, u32 *arg1, s32 arg2, s32 arg3) {
    s32 temp_lo;
    s32 temp_t0;
    u32 red;
    u32 blue;
    u32 green;
    u32 alpha;
    s32 _x = MIN(MAX(0, arg2), arg0->w - 1);
    s32 _y = MIN(MAX(0, arg3), arg0->h - 1);

    temp_t0 = ((u16 *) (arg0 + 1))[_x +  _y * arg0->w];
    
    if(temp_t0);
    blue = ((temp_t0 >> 1) & ((1<< 5)  - 1));
    green = ((temp_t0 >> 6) & ((1<< 5)  - 1));
    red = ((temp_t0 >> 11) & ((1<< 5) - 1));
    temp_lo = (s32) ((*arg1 >> 8) & 0xFF) / 0x1F;


    *arg1 = (( ((red * temp_lo) << 0x18) | ((green * temp_lo) << 0x10)) | ((blue * temp_lo) << 8)) | (*arg1 & 0xff);
}//*/

//this function applies the texture to the font alpha mask.
void func_802F4B58(BKSpriteTextureBlock *alphaMask, BKSpriteTextureBlock *texture){
    s32 y_min;
    s32 x_min;
    u32 *pxl;
    s32 x;
    s32 y;

    pxl = alphaMask + 1;
    x_min = (texture->w - alphaMask->w) >> 1;
    y_min = (texture->h - alphaMask->h) >> 1;
    
    for(y = y_min; y < alphaMask->h + y_min; y++){
        for(x = x_min; x < alphaMask->w + x_min; x++){
            func_802F4A24(texture, pxl, x, y);
            pxl++;
        }
    }
}

//This functions seperates the fonts into letters
FontLetter *func_802F4C3C(BKSprite *alphaMask, BKSprite *textureSprite){
    BKSpriteFrame * font = spriteGetFramePtr(alphaMask, 0);
    BKSpriteTextureBlock *chunkPtr;
    FontLetter * sp2C = malloc((font->chunkCnt + 1)*sizeof(FontLetter));
    u8* palDataPtr;
    u8* chunkDataPtr;
    s32 chunkSize;
    s32 i;
    

    switch(alphaMask->type){
        case SPRITE_TYPE_CI8:
            {//L802F4CA8 
                chunkPtr = (font + 1);
                chunkDataPtr = chunkPtr;
                while((s32)chunkDataPtr % 8)
                    chunkDataPtr++;
                
                palDataPtr = chunkDataPtr;
                chunkPtr = palDataPtr + 2*0x100;
                
                for(i= 0; i < font->chunkCnt; i++){
                    
                    chunkDataPtr = chunkPtr + 1;
                    while((s32)chunkDataPtr % 8)
                        chunkDataPtr++;

                    sp2C[i].unk0 = chunkPtr;
                    sp2C[i].unk4 = palDataPtr;
                    chunkSize = chunkPtr->w*chunkPtr->h;
                    chunkPtr = chunkDataPtr + chunkSize;
                }
            }
            break;
        case SPRITE_TYPE_RGBA32://L802F4D80
            {
                chunkPtr = font + 1;
                for( i = 0; i < font->chunkCnt; i++){
                    func_802F4B58(chunkPtr, spriteGetFramePtr(textureSprite, 0) + 1);
                    sp2C[i].unk0 = chunkPtr;
                    chunkSize = chunkPtr->w*chunkPtr->h;
                    chunkDataPtr = chunkPtr + 1;
                    while((s32)chunkDataPtr % 8)
                        chunkDataPtr++;
                    chunkPtr = chunkDataPtr + chunkSize*4;
                }
            }
            break;
        case 0x20://L802F4E24
            {
                chunkPtr = (u32)(font + 1);
                for( i = 0; i < font->chunkCnt; i++){
                    sp2C[i].unk0 = chunkPtr;
                    chunkDataPtr = chunkPtr + 1;
                    chunkSize = chunkPtr->w*chunkPtr->h;
                    while((s32)chunkDataPtr % 8)
                        chunkDataPtr++;
                    chunkPtr = chunkDataPtr + chunkSize/2;
                }
            }
            break;
        default://L802F4EC0
            {
                chunkPtr = font + 1;
                for( i = 0; i < font->chunkCnt; i++){
                    chunkDataPtr = chunkPtr + 1;
                    sp2C[i].unk0 = chunkPtr;
                    chunkSize = chunkPtr->w*chunkPtr->h;
                    while((s32)chunkDataPtr % 8)
                        chunkDataPtr++;
                    chunkPtr = chunkDataPtr + chunkSize;
                }
            }
            break;
    };
    return sp2C;
}

void func_802F4F64(void){
    s32 i; 
    for(i = 0; i< 5; i++){
        assetcache_release(D_80380AB8[i]);
        D_80380AB8[i] = NULL;
        if(i < 4){
            free(D_80380AD0[i]);
            D_80380AD0[i] = NULL;
        }
    }
    free(D_80380AE0);
    D_80380AE0 = NULL;
}

void func_802F5010(void){
    s32 i;
    for(i = 0; i < 0x20; i++){
        D_80380AE0[i].string = NULL;
    }
}

void func_802F5060(s32 textureId){
    s32 tmp_a2;
    tmp_a2 = func_802546E4(D_80380AB8[1]);
    if(tmp_a2 & 0xF)
        tmp_a2 += 0x10 - (tmp_a2 & 0xF);
    if(!func_8033BDAC(SPRITE_BOLD_FONT_NUMBERS_ALPHAMASK, D_80380AB8[1],tmp_a2)){
        assetcache_release(D_80380AB8[1]);
        D_80380AB8[1] = assetcache_get(SPRITE_BOLD_FONT_NUMBERS_ALPHAMASK);
    }
    if(D_80380AB8[3]){
        tmp_a2 = func_802546E4(D_80380AB8[3]);
        if(tmp_a2 & 0xF)
            tmp_a2 += 0x10 - (tmp_a2 & 0xF);
        if(!func_8033BDAC(SPRITE_BOLD_FONT_LETTERS_ALPHAMASK, D_80380AB8[3],tmp_a2)){
            assetcache_release(D_80380AB8[3]);
            D_80380AB8[3] = assetcache_get(SPRITE_BOLD_FONT_LETTERS_ALPHAMASK);
        }
    }//L802F510C
    D_80380AB8[4] = assetcache_get(textureId);
    free(D_80380AD0[1]);
    D_80380AD0[1] = func_802F4C3C(D_80380AB8[1], D_80380AB8[4]);
    if(D_80380AB8[3]){
        free(D_80380AD0[3]);
        D_80380AD0[3] = func_802F4C3C(D_80380AB8[3], D_80380AB8[4]);
    }
    assetcache_release(D_80380AB8[4]);
    D_80380AB8[4] = NULL;
    D_80380B1C = textureId;
}

void func_802F5188(void){
    func_802F5060(func_802F49C0());
    func_802F5010();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F51B8.s")
/*void func_802F51B8(void){
    s32 i, j;
    s32 length;
    int found;

    length = strlen(D_80369200);
    D_80380AEC = 0;
    D_80380AF0 = 0;
    D_80380AF4 = 0;
    D_80380AF8 = 0;
    D_80380AFC = 0;
    D_80380B00 = 0;
    D_80380B04 = 0;
    D_80380B08 = 0;
    D_80380B0C = 0;
    D_80380B10 = 0;
    D_80380B14 = 0;
    D_80380AE8.unk0 = 0;
    D_80380AB0 = 0;
    func_802F7A2C(3);
    D_80380AB8[0] = assetcache_get(SPRITE_DIALOG_FONT_ALPHAMASK);
    D_80380AB8[1] = assetcache_get(SPRITE_BOLD_FONT_NUMBERS_ALPHAMASK);
    D_80380AB8[4] = assetcache_get(func_802F49C0());
    D_80380AD0[0] =  func_802F4C3C(D_80380AB8[0], D_80380AB8[4]);
    D_80380AD0[1] =  func_802F4C3C(D_80380AB8[1], D_80380AB8[4]);
    D_80380AE0 = malloc(0x20*sizeof(PrintBuffer));
    func_802F5010();

    for(i = 0; i < 0x80; i++){//L802F52EC
        found = 0;
        for(j = 0; j < length && !found; j++){//L802F5304
            if(D_80369200[j] == i){
                D_80380F20[i] = j;
                found = 1;
            }//L802F531C
        }//L802F5330
        if(!found)
            D_80380F20[i] = -1;
        //L802F533C
    }
    assetcache_release(D_80380AB8[4]);
    D_80380AB8[4] = NULL;
    D_80380B1C = func_802F49C0();
}//*/

void func_802F5374(void){
    if(D_80380B18 > 0 && --D_80380B18 == 0){
        assetcache_release(D_80380AB8[3]);
        D_80380AB8[3] = 0;
        free(D_80380AD0[3]);
        D_80380AD0[3] = NULL;
    }
}

void func_802F53D0(void){
    if(D_80380AB8[3]){
        assetcache_release(D_80380AB8[3]);
        D_80380AB8[3] = NULL;
    }
    if(D_80380AD0[3]){
        free(D_80380AD0[3]);
        D_80380AD0[3] = NULL;
    }
    D_80380B18 = 0;
}

void func_802F542C(void){
    D_80380AD0[0] = func_802555DC(D_80380AD0[0]);
    D_80380AD0[1] = func_802555DC(D_80380AD0[1]);
    if(D_80380AD0[3]){
        D_80380AD0[3] = func_802555DC(D_80380AD0[3]);
    }
    D_80380AE0 = func_802555DC(D_80380AE0);
}

//returns the pixel data and type for a given letter
void *func_802F5494(s32 letterId, s32 *fontType){
    if(D_80380AE8.unk0 != 1 || (D_80380AE8.unk0 == 1 && letterId < 0xA)){
        *fontType = D_80380AB8[D_80380AE8.unk0]->type;
        return D_80380AD0[D_80380AE8.unk0][letterId].unk0;
    }
    else{//L802F5510
        if(!D_80380AB8[3]){
            D_80380AB8[3] = assetcache_get(SPRITE_BOLD_FONT_LETTERS_ALPHAMASK);
            D_80380AB8[4] = assetcache_get(D_80380B1C);
            D_80380AD0[3] = func_802F4C3C(D_80380AB8[3], D_80380AB8[4]);
            assetcache_release(D_80380AB8[4]);
            D_80380AB8[4] = NULL;
        }//L802F5568
        D_80380B18 = 5;
        *fontType  = D_80380AB8[3]->type;
        return D_80380AD0[3][letterId-10].unk0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F55A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F55D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F6C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F6E94.s")

void func_802F77A8(s32 x, s32 y, u8 * string) {
    for(D_80380AE4 = D_80380AE0; D_80380AE4 < D_80380AE0 + 0x20 && D_80380AE4->string; D_80380AE4++) {
    }
    if (D_80380AE4 == D_80380AE0 + 0x20) {
        D_80380AE4 = NULL;
        return;
    }
    D_80380AE4->x = x;
    D_80380AE4->y = y;
    D_80380AE4->unk8 = (u8)0;
    D_80380AE4->string = string;
    D_80380AE4->unk10 = 1.0f;
    D_80380AE4->unk18 = (u8) D_80369078.unk0;
    D_80380AE4->unk19 = (u8) D_80369078.unk1;
    D_80380AE4->unk1A = (u8) D_80369078.unk2;
    D_80380AE4->unk1B = (u8) D_80369078.unk3;
}


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F7870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F78C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F78FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F7938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F7974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F79D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F7A2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F7B90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F7BA8.s")
