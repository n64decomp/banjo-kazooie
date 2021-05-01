#include <ultra64.h>
#include "functions.h"
#include "variables.h"



typedef struct{
    s8 pad0[0x20];
} struct23s;

typedef struct{
    s16 x;
    s16 y;
    s16 unk4;
    s16 unk6;
    u8 unk8[8];
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

extern s32 D_80369068[];
extern MapFontTextureMap D_8036907C[];

extern u8 D_80369200[];

extern Gfx D_80369238[];/* = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPTexture(qu016(0.5), qu016(0.5), 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};*/

extern u8 D_80377240[4];
extern u8 D_80377244[4];
extern u8 D_80377248[4];
extern u8 D_8037724C[4];
extern u8 D_80377250[4];
extern u8 D_80377254[4];

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
extern s8 D_80380B20[0x400];
extern s8 D_80380F20[0x80];
extern f32 D_80380FA8[];

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

    pxl = (u32*)(alphaMask + 1);
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
                chunkPtr = (BKSpriteTextureBlock *) (font + 1);
                chunkDataPtr = (u8 *)chunkPtr;
                while((s32)chunkDataPtr % 8)
                    chunkDataPtr++;
                
                palDataPtr = chunkDataPtr;
                chunkPtr = (BKSpriteTextureBlock *) (palDataPtr + 2*0x100);
                
                for(i= 0; i < font->chunkCnt; i++){
                    
                    chunkDataPtr = (u8*)(chunkPtr + 1);
                    while((s32)chunkDataPtr % 8)
                        chunkDataPtr++;

                    sp2C[i].unk0 = chunkPtr;
                    sp2C[i].unk4 = palDataPtr;
                    chunkSize = chunkPtr->w*chunkPtr->h;
                    chunkPtr = (BKSpriteTextureBlock *)(chunkDataPtr + chunkSize);
                }
            }
            break;
        case SPRITE_TYPE_RGBA32://L802F4D80
            {
                chunkPtr = (BKSpriteTextureBlock *)(font + 1);
                for( i = 0; i < font->chunkCnt; i++){
                    func_802F4B58(chunkPtr, (BKSpriteTextureBlock *)(spriteGetFramePtr(textureSprite, 0) + 1));
                    sp2C[i].unk0 = chunkPtr;
                    chunkSize = chunkPtr->w*chunkPtr->h;
                    chunkDataPtr = (u8*)(chunkPtr + 1);
                    while((s32)chunkDataPtr % 8)
                        chunkDataPtr++;
                    chunkPtr = (BKSpriteTextureBlock *) (chunkDataPtr + chunkSize*4);
                }
            }
            break;
        case 0x20://L802F4E24
            {
                chunkPtr = (BKSpriteTextureBlock *) (font + 1);
                for( i = 0; i < font->chunkCnt; i++){
                    sp2C[i].unk0 = chunkPtr;
                    chunkDataPtr = (u8*)(chunkPtr + 1);
                    chunkSize = chunkPtr->w*chunkPtr->h;
                    while((s32)chunkDataPtr % 8)
                        chunkDataPtr++;
                    chunkPtr = (BKSpriteTextureBlock *) (chunkDataPtr + chunkSize/2);
                }
            }
            break;
        default://L802F4EC0
            {
                chunkPtr = (BKSpriteTextureBlock *)(font + 1);
                for( i = 0; i < font->chunkCnt; i++){
                    chunkDataPtr = (u8*)(chunkPtr + 1);
                    sp2C[i].unk0 = chunkPtr;
                    chunkSize = chunkPtr->w*chunkPtr->h;
                    while((s32)chunkDataPtr % 8)
                        chunkDataPtr++;
                    chunkPtr = (BKSpriteTextureBlock *)(chunkDataPtr + chunkSize);
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
    D_80380AD0[0] = (FontLetter *)func_802555DC(D_80380AD0[0]);
    D_80380AD0[1] = (FontLetter *)func_802555DC(D_80380AD0[1]);
    if(D_80380AD0[3]){
        D_80380AD0[3] = (FontLetter *)func_802555DC(D_80380AD0[3]);
    }
    D_80380AE0 = (PrintBuffer *)func_802555DC(D_80380AE0);
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

//returns the letter's palette
void *func_802F55A8(u8 arg0){
    return  D_80380AD0[D_80380AE8.unk0][arg0].unk4;
}

void func_802F55D8(s32 letter, f32* xPtr, f32* yPtr, f32 arg3, Gfx **gdl, Mtx **mptr, s32 vptr);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F55D8.s")
/*void func_802F55D8(s32 letter, f32* arg1, f32* arg2, f32 arg3, Gfx **gdl, Mtx **mptr, s32 vptr){

}//*/

f32 func_802F6C90(u8 letter, f32* xPtr, f32 *yPtr, f32 arg3);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F6C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6DA30/func_802F6E94.s")
/*void func_802F6E94(Gfx **arg0, Mtx **arg1, s32 arg2) {
    s32 j;
    f32 _x;
    f32 _y;
    f32 half;
    s32 length;

    gSPDisplayList((*arg0)++, D_80369238);
    for(D_80380AE4 = D_80380AE0; D_80380AE4 < D_80380AE0 + 0x20; D_80380AE4++){
        if (D_80380AE4->string != 0) {
            _x = (f32) D_80380AE4->x;
            _y = (f32) D_80380AE4->y;
            for(j = 0; D_80380AE4->unk8[j] != 0; j++) {
                func_802F55D8(0xFD, &_x, &_y, 1.0f, arg0, arg1, arg2);
                func_802F55D8(D_80380AE4->unk8[j], &_x, &_y, 1.0f, arg0, arg1, arg2);
            }
            if (D_80380B00 != 0) {
                length = strlen(D_80380AE4->string);
                gDPPipeSync((*arg0)++);
                gDPSetPrimColor((*arg0)++, 0, 0, 0x00, 0x00, 0x00, 0x64);
                gDPSetCombineMode((*arg0)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
                half = D_80369068[D_80380AE8.unk0]/2;
                gDPScisFillRectangle((*arg0)++, _x - half - 1.0f, _y - half - 1.0f, half + (_x + D_80369068[D_80380AE8.unk0] * (length - 1)), half + _y + 1.0f);
                gDPPipeSync((*arg0)++);
            }
            if ((D_80380AF8 == 0) && (D_80380AF4 == 0)) {
                if (D_80380AE8.unk0 != 0) {
                    gDPSetCombineMode((*arg0)++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                    gDPSetPrimColor((*arg0)++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                } else {
                    gDPSetCombineMode((*arg0)++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                    gDPSetPrimColor((*arg0)++, 0, 0, D_80380AE4->unk18, D_80380AE4->unk19, D_80380AE4->unk1A, D_80380AE4->unk1B);
                }
            }
            if ((D_80380AE8.unk0 == 1) && ((f64) D_80380AE4->unk10 < 0.0)) {
                for(j = 0; D_80380AE4->string[j]; j++){
                    D_80380FA8[j] = func_802F6C90(D_80380AE4->string[j], &_x, &_y, -D_80380AE4->unk10);
                }
                while(j >= 0){
                    _x = D_80380FA8[j];
                    func_802F55D8(D_80380AE4->string[j], &_x, &_y, -D_80380AE4->unk10, arg0, arg1, arg2);
                    j--;
                }
            } else {
                for(j = 0; (D_80380AE4->string[j] != 0) || (D_80380B04 != 0); j++){
                    func_802F55D8(D_80380AE4->string[j], &_x, &_y, D_80380AE4->unk10, arg0, arg1, arg2);
                }
            }
            for(j = 0; D_80380AE4->unk8[j] != 0; j++) {
                func_802F55D8(0xFD, &_x, &_y, 1.0f, arg0, arg1, arg2);
                func_802F55D8(D_80380AE4->unk8[j], &_x, &_y, 1.0f, arg0, arg1, arg2);
            }
            func_802F55D8(0, &_x, &_y, 1.0f, arg0, arg1, arg2);
            D_80380AE4->string = NULL;
        }
    }
    gDPPipeSync((*arg0)++);
    gDPSetTexturePersp((*arg0)++, G_TP_PERSP);
    gDPSetTextureFilter((*arg0)++, G_TF_BILERP);
    func_8024C904(arg0, arg1);
}//*/

//adds a new string to the print buffer and updates string buffer end ptr
void func_802F77A8(s32 x, s32 y, u8 * string) {
    for(D_80380AE4 = D_80380AE0; D_80380AE4 < D_80380AE0 + 0x20 && D_80380AE4->string; D_80380AE4++) {
    }
    if (D_80380AE4 == D_80380AE0 + 0x20) {
        D_80380AE4 = NULL;
        return;
    }
    D_80380AE4->x = x;
    D_80380AE4->y = y;
    D_80380AE4->unk8[0] = (u8)0;
    D_80380AE4->string = string;
    D_80380AE4->unk10 = 1.0f;
    D_80380AE4->unk18 = (u8) D_80369078.unk0;
    D_80380AE4->unk19 = (u8) D_80369078.unk1;
    D_80380AE4->unk1A = (u8) D_80369078.unk2;
    D_80380AE4->unk1B = (u8) D_80369078.unk3;
}

void print_bold_overlapping(s32 x, s32 y, f32 arg2, u8* string){
    func_802F77A8(x, y, string);
    if(D_80380AE4){
        strcpy(D_80380AE4->unk8, D_80377240);
        D_80380AE4->unk10 = arg2;
    }
}

void print_bold_spaced(s32 x, s32 y, u8* string){
    func_802F77A8(x, y, string);
    if(D_80380AE4){
        strcpy(D_80380AE4->unk8, D_80377244);
    }
}

void print_dialog(s32 x, s32 y, u8* string){
    func_802F77A8(x, y, string);
    if(D_80380AE4){
        strcpy(D_80380AE4->unk8, D_80377248);
    }
}

void print_dialog_w_bg(s32 x, s32 y, u8* string){
    func_802F77A8(x, y, string);
    if(D_80380AE4){
        strcpy(D_80380AE4->unk8, D_8037724C);
    }
}

void print_dialog_gradient(s32 x, s32 y, u8* string, u8 arg3, u8 arg4){
    func_802F77A8(x, y, string);
    if(D_80380AE4){
        D_80380AE4->unk4 = arg3;
        D_80380AE4->unk6 = arg4;
        strcpy(D_80380AE4->unk8, D_80377250);
    }
}

void func_802F79D0(s32 x, s32 y, u8* string, s32 arg3, s32 arg4){
    func_802F77A8(x, y, string);
    if(D_80380AE4){
        D_80380AE4->unk4 = arg3;
        D_80380AE4->unk6 = arg4;
        strcpy(D_80380AE4->unk8, D_80377254);
    }
}

void func_802F7A2C(s32 arg0) {
    s8 *phi_v0;
    s32 i;
    s32 j;
    s32 offset;

    D_80380B0C = arg0;
    
    i = 0;
    offset = 0;
    while(i < D_80380B0C){
        phi_v0 = offset + D_80380B20;
        for(j = 0; j < 0x20; j++){
            phi_v0[j] = (s8) ((i*0xff) / (s32) (D_80380B0C - 1));
        }
        i++;
        offset+=0x20;
    }
    osWritebackDCache(&D_80380B20, D_80380B0C*sizeof(struct23s));
}

void func_802F7B90(s32 arg0, s32 arg1, s32 arg2){
    D_80369078.unk0 = arg0;
    D_80369078.unk1 = arg1;
    D_80369078.unk2 = arg2;
}

void func_802F7BA8(s32 arg0){
    D_80369078.unk3 = arg0;
}
