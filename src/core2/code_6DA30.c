#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct font_letter{
    void *unk0;//chunkPtr
    void *unk4;//palPtr
} FontLetter;

extern struct {
    BKSprite *unk0[0x3];
    BKSprite *unkC;
    BKSprite *unk10;
} D_80380AB8;

extern FontLetter *D_80380AD0[3];
extern FontLetter *D_80380ADC;

extern struct {
    s32 unk0;   
}D_80380AE8;

extern s32 D_80380B18;
extern s32 D_80380B1C;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F49C0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F4F64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F5010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F5060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F5188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F51B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F5374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F53D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F542C.s")

void *func_802F5494(s32 letterId, s32 *fontType){
    if(D_80380AE8.unk0 != 1 || (D_80380AE8.unk0 == 1 && letterId < 0xA)){
//L802F54C8
        *fontType = D_80380AB8.unk0[D_80380AE8.unk0]->type;
        return D_80380AD0[D_80380AE8.unk0][letterId].unk0;
    }
    else{//L802F5510
        if(!D_80380AB8.unkC){
            D_80380AB8.unkC = assetcache_get(SPRITE_BOLD_FONT_NUMBERS_ALPHAMASK);
            D_80380AB8.unk10 = assetcache_get(D_80380B1C);
            D_80380ADC = func_802F4C3C(D_80380AB8.unkC, D_80380AB8.unk10);
            func_8033B3D8(D_80380AB8.unk10);
            D_80380AB8.unk10 = NULL;
        }//L802F5568
        D_80380B18 = 5;
        *fontType  = D_80380AB8.unkC->type;
        return D_80380ADC[letterId-10].unk0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F55A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F55D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F6C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F6E94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F77A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F7870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F78C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F78FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F7938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F7974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F79D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F7A2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F7B90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F7BA8.s")
