#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct font_letter{
    void *unk0;//chunkPtr
    void *unk4;//palPtr
} FontLetter;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F49C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F4A24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F4B58.s")

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
                
                for(i= 0; i < font->chunkCnt; ){
                    
                    chunkDataPtr = chunkPtr + 1;
                    while((s32)chunkDataPtr % 8)
                        chunkDataPtr++;

                    sp2C[i].unk0 = chunkPtr;
                    sp2C[i++].unk4 = palDataPtr;
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F5494.s")

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
