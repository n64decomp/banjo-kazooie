#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"


typedef struct{
    s8 pad0[0x20];
} struct23s;

typedef struct{
    s16 x;
    s16 y;
    s16 topVertexAlpha;
    s16 bottomVertexAlpha;
    u8 fmtString[8];
    f32 scale;
    u8 *string;
    u8 rgba[4];
} PrintBuffer;

typedef struct font_letter{
    BKSpriteTextureBlock *unk0;//chunkPtr
    void *unk4;//palPtr
} FontLetter;

typedef struct map_font_texture_map{
    s16 mapID;
    s16 assetId;
} MapToBoldFontBackgroundSpriteMap;

typedef struct{
    u8 firstLetter;
    u8 secondLetter;
    s8 xOffset;
    s8 yOffset;
} BoldFontKerningData;

/* .data */
extern BoldFontKerningData boldFontKernings[] = {
    {'A', 'V',  -3,  0},
    {'W', 'A',  -3,  0},
    {'V', 'A',  -3,  0},
    {'Y', 'A',  -2,  0},
    {'M', 'O',  -1,  0},
    {'D', 'A',  -1,  0},
    {'R', 'O',  -2,  0},
    {'T', 'A',  -2,  0},
    {'S', 'T',  -1,  0},
    {'A', 'M',  -1,  0},
    {'C', 'O',  -1,  0},
    {'O', 'V',  -1,  0},
    {'L', 'O',  -1,  0},
    {'M', 'U',  -1,  0},
    {'U', 'M',  -1,  0},
    {'M', 'A',  -2,  0},
    {'M', '0',  -1,  0},
    {'N', 'S',   1,  0},
    {'H', 'I',   1,  0},
    {'I', 'P',   1,  0},
    {'I', '\'',  2,  0},
    {'A', '\'', -1,  0},
    {'N', '\'',  3,  0},
    {'E', 'E',   0, -1},
    {'Z', 'E',   0,  1},
    0
};

s32 maxCharacterWidths[] = {8, 16, 16, 0};

struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} normalTextColor = {0xFF, 0xFF, 0xFF, 0XFF};

MapToBoldFontBackgroundSpriteMap mapToBoldFontBackgroundSpriteMap[] ={
    {MAP_1_SM_SPIRAL_MOUNTAIN,               SPRITE_BOLD_FONT_BLUE_SPHERE_BACKGROUND},
    {MAP_2_MM_MUMBOS_MOUNTAIN,               SPRITE_BOLD_FONT_ORANGE_SPHERE_BACKGROUND},
    {MAP_3_UNUSED,                           SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_4_UNUSED,                           SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_5_TTC_BLUBBERS_SHIP,                SPRITE_BOLD_FONT_BLUE_SPHERE_BACKGROUND},
    {MAP_6_TTC_NIPPERS_SHELL,                SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_7_TTC_TREASURE_TROVE_COVE,          SPRITE_BOLD_FONT_BLUE_SPHERE_BACKGROUND},
    {MAP_8_UNUSED,                           SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_9_UNUSED,                           SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_A_TTC_SANDCASTLE,                   SPRITE_BOLD_FONT_BLUE_SPHERE_BACKGROUND},
    {MAP_B_CC_CLANKERS_CAVERN,               SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_C_MM_TICKERS_TOWER,                 SPRITE_BOLD_FONT_ORANGE_SPHERE_BACKGROUND},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,            SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_E_MM_MUMBOS_SKULL,                  SPRITE_BOLD_FONT_ORANGE_SPHERE_BACKGROUND},
    {MAP_F_UNUSED,                           SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_10_BGS_MR_VILE,                     SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_11_BGS_TIPTUP,                      SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_12_GV_GOBIS_VALLEY,                 SPRITE_BOLD_FONT_BLUE_SPHERE_BACKGROUND},
    {MAP_13_GV_MEMORY_GAME,                  SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_14_GV_SANDYBUTTS_MAZE,              SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_15_GV_WATER_PYRAMID,                SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_16_GV_RUBEES_CHAMBER,               SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_17_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_18_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_19_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_1A_GV_INSIDE_JINXY,                 SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_1B_MMM_MAD_MONSTER_MANSION,         SPRITE_BOLD_FONT_ORANGE_SPHERE_BACKGROUND},
    {MAP_21_CC_WITCH_SWITCH_ROOM,            SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_22_CC_INSIDE_CLANKER,               SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_23_CC_GOLDFEATHER_ROOM,             SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_24_MMM_TUMBLARS_SHED,               SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_25_MMM_WELL,                        SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_26_MMM_NAPPERS_ROOM,                SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_28_MMM_EGG_ROOM,                    SPRITE_BOLD_FONT_ORANGE_SPHERE_BACKGROUND},
    {MAP_29_MMM_NOTE_ROOM,                   SPRITE_BOLD_FONT_ORANGE_SPHERE_BACKGROUND},
    {MAP_2A_MMM_FEATHER_ROOM,                SPRITE_BOLD_FONT_ORANGE_SPHERE_BACKGROUND},
    {MAP_2B_MMM_SECRET_CHURCH_ROOM,          SPRITE_BOLD_FONT_ORANGE_SPHERE_BACKGROUND},
    {MAP_2C_MMM_BATHROOM,                    SPRITE_BOLD_FONT_ORANGE_SPHERE_BACKGROUND},
    {MAP_2D_MMM_BEDROOM,                     SPRITE_BOLD_FONT_ORANGE_SPHERE_BACKGROUND},
    {MAP_2E_MMM_HONEYCOMB_ROOM,              SPRITE_BOLD_FONT_ORANGE_SPHERE_BACKGROUND},
    {MAP_2F_MMM_WATERDRAIN_BARREL,           SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_30_MMM_MUMBOS_SKULL,                SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_31_RBB_RUSTY_BUCKET_BAY,            SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_32_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_33_UNUSED,                          SPRITE_BOLD_FONT_BLUE_SPHERE_BACKGROUND},
    {MAP_34_RBB_ENGINE_ROOM,                 SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_35_RBB_WAREHOUSE,                   SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_36_RBB_BOATHOUSE,                   SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_37_RBB_CONTAINER_1,                 SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_38_RBB_CONTAINER_3,                 SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_39_RBB_CREW_CABIN,                  SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_3A_RBB_BOSS_BOOM_BOX,               SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_3B_RBB_STORAGE_ROOM,                SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_3C_RBB_KITCHEN,                     SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_3D_RBB_NAVIGATION_ROOM,             SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_3E_RBB_CONTAINER_2,                 SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_3F_RBB_CAPTAINS_CABIN,              SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_41_FP_BOGGYS_IGLOO,                 SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_42_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_43_CCW_SPRING,                      SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_44_CCW_SUMMER,                      SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_45_CCW_AUTUMN,                      SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_46_CCW_WINTER,                      SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_47_BGS_MUMBOS_SKULL,                SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_48_FP_MUMBOS_SKULL,                 SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_49_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_4A_CCW_SPRING_MUMBOS_SKULL,         SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_4B_CCW_SUMMER_MUMBOS_SKULL,         SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_4C_CCW_AUTUMN_MUMBOS_SKULL,         SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_4D_CCW_WINTER_MUMBOS_SKULL,         SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_4E_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_4F_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_50_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_51_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_52_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_53_FP_CHRISTMAS_TREE,               SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_54_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_55_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_56_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_57_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_58_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_59_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_5A_CCW_SUMMER_ZUBBA_HIVE,           SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_5B_CCW_SPRING_ZUBBA_HIVE,           SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_5C_CCW_AUTUMN_ZUBBA_HIVE,           SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_5E_CCW_SPRING_NABNUTS_HOUSE,        SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_5F_CCW_SUMMER_NABNUTS_HOUSE,        SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_60_CCW_AUTUMN_NABNUTS_HOUSE,        SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_61_CCW_WINTER_NABNUTS_HOUSE,        SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_62_CCW_WINTER_HONEYCOMB_ROOM,       SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_63_CCW_AUTUMN_NABNUTS_WATER_SUPPLY, SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_64_CCW_WINTER_NABNUTS_WATER_SUPPLY, SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_65_CCW_SPRING_WHIPCRACK_ROOM,       SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_66_CCW_SUMMER_WHIPCRACK_ROOM,       SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_67_CCW_AUTUMN_WHIPCRACK_ROOM,       SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    {MAP_68_CCW_WINTER_WHIPCRACK_ROOM,       SPRITE_BOLD_FONT_ORANGE_GRADIENT_BACKGROUND},
    0
};

char boldFontLetters[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
    ':', 
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 
    '@', '%', '?', '(', ')', '<', '>', '"', '.', ';', '-', '!', '/', '\''
};

Gfx D_80369238[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

/* .bss */
char print_sPreviousBoldLetter;
BKSprite *D_80380AB8[0x5];

FontLetter  *print_sFonts[4];
PrintBuffer *print_sPrintBuffer;
PrintBuffer *print_sCurrentPtr;
s32 print_sCurrentFontIndex;
s32 print_sPreviousFontIndex;
s32 print_sMonospacedModeEnabled;
s32 print_sGradientModeEnabled;
s32 D_80380AF8;
s32 D_80380AFC;
s32 D_80380B00;
s32 D_80380B04;
bool print_sInFontFormatMode;
s32 D_80380B0C;
s32 print_sShakyModeEnabled;
s32 print_sBilinearFilterModeEnabled;
s32 D_80380B18;
s32 D_80380B1C;
s8 D_80380B20[0x400];
s8 print_sBoldFontLetterToSpriteMap[0x80];


void func_802F7A2C(s32 arg0);

//returns map texture assetID for current map;
enum asset_e print_getCurrentMapBoldFontBackgroundSprite(void){
    s32 i;
    for(i = 0; mapToBoldFontBackgroundSpriteMap[i].mapID != 0 ; i++){
        if(gsworld_get_map() == mapToBoldFontBackgroundSpriteMap[i].mapID){
            return mapToBoldFontBackgroundSpriteMap[i].assetId;
        }
    }
    return ASSET_708_SPRITE_EGG_PROJECTILE;
}

// this function reassigns the referenced font mask pixel 
// using the texture @ pixel (x,y)
void func_802F4A24(BKSpriteTextureBlock *texture, u32 *font, s32 x, s32 y) {
    u16 *var_v0;
    s32 r5;
    s32 g5;
    s32 b5;
    s32 a8;
    s32 i8;
    x = MIN(MAX(0, x), texture->w - 1);
    y = MIN(MAX(0, y), texture->h - 1);
    
    var_v0 = ((u16*)(texture + 1)) + x + y * texture->w;

    r5 = ((*var_v0 >> 11) & 0x1F);
    g5 = ((*var_v0 >> 6) & 0x1F);
    b5 = ((*var_v0 >> 1) & 0x1F);
    
    a8 = (*font >> 0) & 0xff;
    i8 = (*font >> 8) & 0xff;

    r5*=(i8/ 0x1F);
    g5*=(i8/ 0x1F);
    b5*=(i8/ 0x1F);

    *font = (r5 << 0x18) | (g5 << 0x10) | (b5 << 8) | (a8 << 0);
}

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
    BKSpriteFrame * font = sprite_getFramePtr(alphaMask, 0);
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
                    func_802F4B58(chunkPtr, (BKSpriteTextureBlock *)(sprite_getFramePtr(textureSprite, 0) + 1));
                    sp2C[i].unk0 = chunkPtr;
                    chunkSize = chunkPtr->w*chunkPtr->h;
                    chunkDataPtr = (u8*)(chunkPtr + 1);
                    while((s32)chunkDataPtr % 8)
                        chunkDataPtr++;
                    chunkPtr = (BKSpriteTextureBlock *) (chunkDataPtr + chunkSize*4);
                }
            }
            break;
        case SPRITE_TYPE_I4://L802F4E24
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
            free(print_sFonts[i]);
            print_sFonts[i] = NULL;
        }
    }
    free(print_sPrintBuffer);
    print_sPrintBuffer = NULL;
}

void func_802F5010(void){
    s32 i;
    for(i = 0; i < 0x20; i++){
        print_sPrintBuffer[i].string = NULL;
    }
}

void func_802F5060(s32 textureId){
    s32 tmp_a2;
    tmp_a2 = func_802546E4(D_80380AB8[1]);
    if(tmp_a2 & 0xF)
        tmp_a2 += 0x10 - (tmp_a2 & 0xF);
    if(!code_B3A80_func_8033BDAC(SPRITE_BOLD_FONT_NUMBERS_ALPHAMASK, D_80380AB8[1],tmp_a2)){
        assetcache_release(D_80380AB8[1]);
        D_80380AB8[1] = assetcache_get(SPRITE_BOLD_FONT_NUMBERS_ALPHAMASK);
    }
    if(D_80380AB8[3]){
        tmp_a2 = func_802546E4(D_80380AB8[3]);
        if(tmp_a2 & 0xF)
            tmp_a2 += 0x10 - (tmp_a2 & 0xF);
        if(!code_B3A80_func_8033BDAC(SPRITE_BOLD_FONT_LETTERS_ALPHAMASK, D_80380AB8[3],tmp_a2)){
            assetcache_release(D_80380AB8[3]);
            D_80380AB8[3] = assetcache_get(SPRITE_BOLD_FONT_LETTERS_ALPHAMASK);
        }
    }//L802F510C
    D_80380AB8[4] = assetcache_get(textureId);
    free(print_sFonts[1]);
    print_sFonts[1] = func_802F4C3C(D_80380AB8[1], D_80380AB8[4]);
    if(D_80380AB8[3]){
        free(print_sFonts[3]);
        print_sFonts[3] = func_802F4C3C(D_80380AB8[3], D_80380AB8[4]);
    }
    assetcache_release(D_80380AB8[4]);
    D_80380AB8[4] = NULL;
    D_80380B1C = textureId;
}

void func_802F5188(void){
    func_802F5060(print_getCurrentMapBoldFontBackgroundSprite());
    func_802F5010();
}

void func_802F51B8(void){
    s32 i, j;
    s32 length;
    int found;

    length = strlen(boldFontLetters);
    print_sCurrentFontIndex = \
    print_sPreviousFontIndex = \
    print_sMonospacedModeEnabled = \
    print_sGradientModeEnabled = \
    D_80380AF8 = \
    D_80380AFC = \
    print_sInFontFormatMode = \
    D_80380B04 = \
    D_80380B00 = \
    print_sShakyModeEnabled = \
    print_sBilinearFilterModeEnabled = 0;
    print_sPreviousBoldLetter = 0;
    func_802F7A2C(3);
    D_80380AB8[0] = assetcache_get(SPRITE_DIALOG_FONT_ALPHAMASK);
    D_80380AB8[1] = assetcache_get(SPRITE_BOLD_FONT_NUMBERS_ALPHAMASK);
    D_80380AB8[4] = assetcache_get(print_getCurrentMapBoldFontBackgroundSprite());
    print_sFonts[0] =  func_802F4C3C(D_80380AB8[0], D_80380AB8[4]);
    print_sFonts[1] =  func_802F4C3C(D_80380AB8[1], D_80380AB8[4]);
    print_sPrintBuffer = malloc(0x20*sizeof(PrintBuffer));
    func_802F5010();

    for(i = 0; i < 0x80; i++){//L802F52EC
        found = 0;
        for(j = 0; j < length && !found; j++){//L802F5304
            if(boldFontLetters[j] == i){
                print_sBoldFontLetterToSpriteMap[i] = j;
                found = 1;
            }//L802F531C
        }//L802F5330
        if(!found)
            print_sBoldFontLetterToSpriteMap[i] = -1;
    }
    assetcache_release(D_80380AB8[4]);
    D_80380AB8[4] = NULL;
    D_80380B1C = print_getCurrentMapBoldFontBackgroundSprite();
}

void func_802F5374(void){
    if(D_80380B18 > 0 && --D_80380B18 == 0){
        assetcache_release(D_80380AB8[3]);
        D_80380AB8[3] = 0;
        free(print_sFonts[3]);
        print_sFonts[3] = NULL;
    }
}

void func_802F53D0(void){
    if(D_80380AB8[3]){
        assetcache_release(D_80380AB8[3]);
        D_80380AB8[3] = NULL;
    }
    if(print_sFonts[3]){
        free(print_sFonts[3]);
        print_sFonts[3] = NULL;
    }
    D_80380B18 = 0;
}

void printbuffer_defrag(void){
    print_sFonts[0] = (FontLetter *)defrag(print_sFonts[0]);
    print_sFonts[1] = (FontLetter *)defrag(print_sFonts[1]);
    if(print_sFonts[3]){
        print_sFonts[3] = (FontLetter *)defrag(print_sFonts[3]);
    }
    print_sPrintBuffer = (PrintBuffer *)defrag(print_sPrintBuffer);
}

//returns the pixel data and type for a given letter
BKSpriteTextureBlock *func_802F5494(s32 letterId, s32 *fontType){
    if(print_sCurrentFontIndex != 1 || (print_sCurrentFontIndex == 1 && letterId < 0xA)){
        *fontType = D_80380AB8[print_sCurrentFontIndex]->type;
        return print_sFonts[print_sCurrentFontIndex][letterId].unk0;
    }
    else{//L802F5510
        if(!D_80380AB8[3]){
            D_80380AB8[3] = assetcache_get(SPRITE_BOLD_FONT_LETTERS_ALPHAMASK);
            D_80380AB8[4] = assetcache_get(D_80380B1C);
            print_sFonts[3] = func_802F4C3C(D_80380AB8[3], D_80380AB8[4]);
            assetcache_release(D_80380AB8[4]);
            D_80380AB8[4] = NULL;
        }//L802F5568
        D_80380B18 = 5;
        *fontType  = D_80380AB8[3]->type;
        return print_sFonts[3][letterId-10].unk0;
    }
}

//returns the letter's palette
void *func_802F55A8(u8 arg0){
    return  print_sFonts[print_sCurrentFontIndex][arg0].unk4;
}

void _printbuffer_draw_letter(char letter, f32* xPtr, f32* yPtr, f32 arg3, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    static f32 D_80380FA0;
    
    // u8 letter = arg0;
    BKSpriteTextureBlock *sp214;
    s32 sp210;
    s32 sp20C;
    s32 t0;
    s8 t1;
    f32 x;
    f32 y;
    f32 sp1F8;
    s32 sp1F4; //font_type;

    int i;



    t0 = 0;
    x = *xPtr;
    y = *yPtr;
    t1 = 0;

    if(!D_80380B04 && !letter){
        D_80380FA0 = 0.0f;
    }//L802F563C

    switch(print_sCurrentFontIndex){
        case 0: //L802F5678
            if(letter >= '\x21' && letter < '\x5f'){
                sp20C = letter - '\x21';
                t0 = 1;
            }
            break;
        case 1: //L802F56A0
            if(letter < '\x80' && print_sBoldFontLetterToSpriteMap[letter] >= 0){
                for(i = 0; boldFontKernings[i].firstLetter != 0; i++){
                    if(letter == boldFontKernings[i].secondLetter && print_sPreviousBoldLetter == boldFontKernings[i].firstLetter){
                        t1 = boldFontKernings[i].yOffset;
                        break;
                    }
                }//L802F5710
                sp20C = print_sBoldFontLetterToSpriteMap[letter];
                t0 = 1;
                print_sPreviousBoldLetter = letter;
                y += (f32)t1*arg3;
            }//L802F5738
            break;
        case 2: //L802F5740
            sp20C = letter;
            if(D_80380B04){
                t0 = 1;
                sp20C += (D_80380B04 << 8) - 0x100;
                D_80380B04 = 0;
            }
            else{//L802F5764
                if(sp20C > 0 && sp20C < 0xfD)
                    t0 = 1;
            }
            break;
    }//L802F5778

    if(!t0 || print_sInFontFormatMode){
        print_sInFontFormatMode = FALSE;
        switch(letter){
            case ' '://802F5818
                *xPtr += ((print_sMonospacedModeEnabled) ? maxCharacterWidths[print_sCurrentFontIndex]: maxCharacterWidths[print_sCurrentFontIndex]*0.8) * arg3;
                break;

            case 'b': //L802F5890
                //toggle background
                D_80380B00  = D_80380B00 ^ 1;
                break;

            case 'f': //L802F58A8
                print_sPreviousFontIndex = print_sCurrentFontIndex = print_sCurrentFontIndex ^ 1;
                break;

            case 'l': //L802F58BC
                print_sShakyModeEnabled = 0;
                break;

            case 'h': //L802F58C8
                print_sShakyModeEnabled = 1;
                break;

            case 'j': //L802F58D4
                if(D_80380AFC == 0){
                    D_80380AFC = 1;
                    print_sPreviousFontIndex = print_sCurrentFontIndex;
                    print_sCurrentFontIndex = 2;
                    // print_sCurrentFontIndex = 2;
                }
                break;

            case 'e': //L802F58FC
                if(D_80380AFC){
                    D_80380AFC = 0;
                    print_sCurrentFontIndex = print_sPreviousFontIndex;
                }
                break;

            case 'p': //L802F5924
                print_sMonospacedModeEnabled = print_sMonospacedModeEnabled ^1;
                break;

            case 'q': //L802F593C
                print_sBilinearFilterModeEnabled = print_sBilinearFilterModeEnabled^1;
                if(print_sBilinearFilterModeEnabled){
                    gDPSetTextureFilter((*gfx)++, G_TF_POINT);
                }
                else{//L802F5978
                    gDPSetTextureFilter((*gfx)++, G_TF_BILERP);
                }
                break;

            case 'v': //L802F59A0 
                //toggle letter gradient
                print_sGradientModeEnabled ^= 1;
                if(print_sGradientModeEnabled){
                    viewport_setRenderViewportAndOrthoMatrix(gfx, mtx);
                    gDPPipeSync((*gfx)++);
                    gDPSetTexturePersp((*gfx)++, G_TP_PERSP);
                    gDPSetPrimColor((*gfx)++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
                    gDPSetCombineLERP((*gfx)++, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0);
                }
                else{//L802F5A44
                    gDPSetCombineMode((*gfx)++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                    gDPSetTexturePersp((*gfx)++, G_TP_NONE);
                }
                break;

            case 'd': //L802F5A8C
                D_80380AF8 ^= 1;
                if(D_80380AF8){
                    gDPPipeSync((*gfx)++);
                    gDPSetCycleType((*gfx)++, G_CYC_2CYCLE);
                    gDPSetRenderMode((*gfx)++, G_RM_PASS, G_RM_XLU_SURF2);
                    gDPSetTextureLOD((*gfx)++, G_TL_TILE);
                    gDPSetCombineLERP((*gfx)++, 0, 0, 0, TEXEL0, TEXEL0, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
                }
                else{//L802F5B48
                    gDPPipeSync((*gfx)++);
                    gDPSetCombineMode((*gfx)++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                    gDPSetCycleType((*gfx)++, G_CYC_1CYCLE);
                    gDPSetTextureLOD((*gfx)++, G_TL_LOD);
                    gDPSetRenderMode((*gfx)++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
                }
                break;

            case 0xfd: //L802F5BEC
                print_sInFontFormatMode = TRUE;
                break;

            case 0xfe://L802F5BF4
                D_80380B04 = 1;
                break;

            case 0xff://L802F5BFC
                D_80380B04 = 2;
                break;
            default:
                break;
        }
    }
    else{//L802F5C08
        sp214 = func_802F5494(sp20C, &sp1F4);
        if (print_sShakyModeEnabled != 0) {
               x += randf2(-2.0f, 2.0f);
               y += randf2(-2.0f, 2.0f);
        }
        sp1F8 = (print_sMonospacedModeEnabled != 0) ? maxCharacterWidths[print_sCurrentFontIndex] : sp214->x;

        // temp_f2 = D_80380FA0;
        // phi_f2 = temp_f2;
        if (D_80380FA0 == 0.0f) {
            D_80380FA0 = -sp1F8 * 0.5;
        }
        
        x += (D_80380FA0 + (sp1F8 - sp214->x) * 0.5);
        y -= sp214->h*0.5;
        sp210 = (sp214 + 1);
        while(sp210 % 8){
            sp210++;
        }
        if (sp1F4 == SPRITE_TYPE_RGBA32) { 
            gDPLoadTextureTile((*gfx)++, sp210, G_IM_FMT_RGBA, G_IM_SIZ_32b, sp214->w, sp214->h, 0, 0, sp214->x-1, sp214->y - 1, NULL, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        } else if (sp1F4 == SPRITE_TYPE_IA8) {
            gDPLoadTextureTile((*gfx)++, sp210, G_IM_FMT_IA, G_IM_SIZ_8b, sp214->w, sp214->h, 0, 0, sp214->x-1, sp214->y - 1, NULL, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        } else if (sp1F4 == SPRITE_TYPE_I8) {
            gDPLoadTextureTile((*gfx)++, sp210, G_IM_FMT_I, G_IM_SIZ_8b, sp214->w, sp214->h, 0, 0, sp214->x-1, sp214->y - 1, NULL, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        } else if (sp1F4 == SPRITE_TYPE_I4) {
            gDPLoadTextureTile_4b((*gfx)++, sp210, G_IM_FMT_I, sp214->w, sp214->h, 0, 0, sp214->x-1, sp214->y-1, NULL, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        } else if (sp1F4 == SPRITE_TYPE_CI8) {
            void * pal = func_802F55A8(sp20C);
            gDPLoadTLUT_pal256((*gfx)++, pal);
            gDPLoadTextureTile((*gfx)++, sp210, G_IM_FMT_CI, G_IM_SIZ_8b, sp214->w, sp214->h, 0, 0, sp214->x-1, sp214->y-1, NULL, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gDPSetTextureLUT((*gfx)++, G_TT_RGBA16);
        }//L802F6570
        if (D_80380AF8 != 0) {
            s32 temp_t1;
            s32 phi_a0;
            temp_t1 = ((print_sCurrentPtr->topVertexAlpha - print_sCurrentPtr->y) - D_80380B0C) + 1;
            phi_a0 =  - MAX(1 - D_80380B0C, MIN(0, temp_t1));
            
            gDPSetTextureImage((*gfx)++, G_IM_FMT_I, G_IM_SIZ_8b, 32, &D_80380B20);
            gDPSetTile((*gfx)++, G_IM_FMT_I, G_IM_SIZ_8b, (sp214->x + 8) >> 3, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
            gDPLoadSync((*gfx)++);
            gDPLoadTile((*gfx)++, G_TX_LOADTILE, 0 << G_TEXTURE_IMAGE_FRAC, (phi_a0) << G_TEXTURE_IMAGE_FRAC, (sp214->x) << G_TEXTURE_IMAGE_FRAC, (D_80380B0C - 1) << G_TEXTURE_IMAGE_FRAC);
            gDPPipeSync((*gfx)++);
            gDPSetTile((*gfx)++, G_IM_FMT_I, G_IM_SIZ_8b, ((sp214->x - 0 + 1)*G_IM_SIZ_8b_LINE_BYTES + 7) >> 3, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
            gDPSetTileSize((*gfx)++, 1, 0 << G_TEXTURE_IMAGE_FRAC, (MAX(0, temp_t1) + phi_a0) << G_TEXTURE_IMAGE_FRAC, (sp214->x) << G_TEXTURE_IMAGE_FRAC, (MAX(0, temp_t1) - (1 - D_80380B0C))<<G_TEXTURE_IMAGE_FRAC);
            
            // gDPLoadMultiTile((*gfx)++, &D_80380B20,)
            
        }//L802F677C
        if (print_sGradientModeEnabled != 0) {
            f32 temp_f24;
            f32 spD0;
            f32 ix;
            f32 iy;
            f32 temp_f26;
            f32 spC0;

            temp_f24 = (sp214->x - 1.0);
            spD0 = sp214->y - 1.0;
            temp_f26 = (f64) x - (f32) gFramebufferWidth * 0.5;
            spC0 = (f64)y - (f32)gFramebufferHeight*0.5 -0.5f;
            gSPVertex((*gfx)++, *vtx, 4, 0);
            for(iy = 0.0f; iy < 2.0; iy+= 1.0){
                for(ix = 0.0f; ix < 2.0; ix += 1.0){
                    s32 s = (ix * temp_f24 * 64.0f);
                    (*vtx)->v.ob[0] = (s16)(s32)((f64) (temp_f26 + (temp_f24 *  arg3  * ix)) * 4.0);
                    {
                        s32 t = (iy * spD0 * 64.0f);
                        (*vtx)->v.ob[1] = (s16) (s32) ((f64) (spC0 + (spD0 * arg3 * iy)) * -4.0);
                        (*vtx)->v.ob[2] = -0x14;
                        (*vtx)->v.tc[0] = s;
                        (*vtx)->v.tc[1] = t;
                    }
                    (*vtx)->v.cn[3] =(iy != 0.0f) ? print_sCurrentPtr->bottomVertexAlpha : print_sCurrentPtr->topVertexAlpha;
                    
                    (*vtx)++;
                }    
            }
            
            gSP1Quadrangle((*gfx)++, 0, 1, 3, 2, 0);
        }
        else{
            gSPScisTextureRectangle((*gfx)++, (s32)(x*4.0f), (s32)(y*4.0f), (s32)((x + sp214->x*arg3)*4.0f), (s32)((y + sp214->y*arg3)*4.0f), 0, 0, 0, (s32)(1024.0f / arg3), (s32)(1024.0f / arg3));
        }
        *xPtr += sp1F8 * arg3;
    }
}

f32 func_802F6C90(u8 letter, f32* xPtr, f32 *yPtr, f32 arg3){
    s32 sp44;
    s32 i;
    bool var_v0;
    f32 sp38;
    s32 sp34;
    f32 var_f2;
    s32 sp2C;

    sp38 = *xPtr;
    var_v0 = FALSE;
    sp34 = 0;
    if (print_sCurrentFontIndex == 1) {
        if (letter < 0x80) {
            if (print_sBoldFontLetterToSpriteMap[letter] >= 0) {
                for(i = 0; boldFontKernings[i].firstLetter != 0; i++) {
                    if ((boldFontKernings[i].secondLetter == letter) && (boldFontKernings[i].firstLetter == print_sPreviousBoldLetter)) {
                        sp34 = boldFontKernings[i].xOffset;
                        break;
                    }
                }
                print_sPreviousBoldLetter = letter;
                sp44 = print_sBoldFontLetterToSpriteMap[letter];
                var_v0 = TRUE;
                sp38 += sp34 * arg3;
            }
        }
    }
    else{
        return *xPtr;
    }
    if (!var_v0 || print_sInFontFormatMode) {
        if (letter == ' ') {
            var_f2 = (print_sMonospacedModeEnabled) ? maxCharacterWidths[print_sCurrentFontIndex] : 0.8*maxCharacterWidths[print_sCurrentFontIndex];
        }
        else{
            return *xPtr;
        }
    }
    else {
        if(print_sMonospacedModeEnabled){
            var_f2 = maxCharacterWidths[print_sCurrentFontIndex];
        }
        else{
            var_f2 = func_802F5494(sp44, &sp2C)->x;
        }
    }
    var_f2 += (sp34 - 4);
    *xPtr += var_f2 * arg3;
    
    return sp38;
}

void printbuffer_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    static f32 D_80380FA8[0x20];

    s32 j;
    f32 _x;
    f32 _y;
    f32 width;

    gSPDisplayList((*gfx)++, D_80369238);
    for(print_sCurrentPtr = print_sPrintBuffer; print_sCurrentPtr < print_sPrintBuffer + 0x20; print_sCurrentPtr++){
        if (print_sCurrentPtr->string != 0) {
            _x = (f32) print_sCurrentPtr->x;
            _y = (f32) print_sCurrentPtr->y;
            //toggle on string format modifiers
            for(j = 0; print_sCurrentPtr->fmtString[j] != 0; j++) {
                _printbuffer_draw_letter(0xFD, &_x, &_y, 1.0f, gfx, mtx, vtx);
                _printbuffer_draw_letter(print_sCurrentPtr->fmtString[j], &_x, &_y, 1.0f, gfx, mtx, vtx);
            }
            if (D_80380B00 != 0) {
                width = (strlen(print_sCurrentPtr->string) -1)*maxCharacterWidths[print_sCurrentFontIndex];
                gDPPipeSync((*gfx)++);
                gDPSetPrimColor((*gfx)++, 0, 0, 0x00, 0x00, 0x00, 0x64);
                gDPSetCombineMode((*gfx)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
                gDPScisFillRectangle((*gfx)++, _x - maxCharacterWidths[print_sCurrentFontIndex]/2 - 1.0f, _y - maxCharacterWidths[print_sCurrentFontIndex]/2 - 1.0f, _x + width + maxCharacterWidths[print_sCurrentFontIndex]/2, _y + maxCharacterWidths[print_sCurrentFontIndex]/2 + 1.0f);
                gDPPipeSync((*gfx)++);

            }//L802F73E8
            if ((D_80380AF8 == 0) && (print_sGradientModeEnabled == 0)) {
                if (print_sCurrentFontIndex != 0) {
                    gDPSetCombineMode((*gfx)++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                    gDPSetPrimColor((*gfx)++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                } else {
                    gDPSetCombineMode((*gfx)++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                    gDPSetPrimColor((*gfx)++, 0, 0, print_sCurrentPtr->rgba[0], print_sCurrentPtr->rgba[1], print_sCurrentPtr->rgba[2], print_sCurrentPtr->rgba[3]);
                }
            }
            if ((print_sCurrentFontIndex == 1) && ((f64) print_sCurrentPtr->scale < 0.0)) {
                for(j = 0; print_sCurrentPtr->string[j]; j++){
                    D_80380FA8[j] = func_802F6C90(print_sCurrentPtr->string[j], &_x, &_y, -print_sCurrentPtr->scale);
                }
                while(j >= 0){
                    _x = D_80380FA8[j];
                    _printbuffer_draw_letter(print_sCurrentPtr->string[j], &_x, &_y, -print_sCurrentPtr->scale, gfx, mtx, vtx);
                    j--;
                }
            } else {
                for(j = 0; (print_sCurrentPtr->string[j] != 0) || (D_80380B04 != 0); j++){
                    _printbuffer_draw_letter(print_sCurrentPtr->string[j], &_x, &_y, print_sCurrentPtr->scale, gfx, mtx, vtx);
                }
            }
            //toggle off string format modifiers
            for(j = 0; print_sCurrentPtr->fmtString[j] != 0; j++) {
                _printbuffer_draw_letter(0xFD, &_x, &_y, 1.0f, gfx, mtx, vtx);
                _printbuffer_draw_letter(print_sCurrentPtr->fmtString[j], &_x, &_y, 1.0f, gfx, mtx, vtx);
            }
            _printbuffer_draw_letter(0, &_x, &_y, 1.0f, gfx, mtx, vtx);
            print_sCurrentPtr->string = NULL;
        }
    }
    gDPPipeSync((*gfx)++);
    gDPSetTexturePersp((*gfx)++, G_TP_PERSP);
    gDPSetTextureFilter((*gfx)++, G_TF_BILERP);
    viewport_setRenderViewportAndPerspectiveMatrix(gfx, mtx);
}//*/

//adds a new string to the print buffer and updates string buffer end ptr
void _printbuffer_push_new(s32 x, s32 y, u8 * string) {
    for(print_sCurrentPtr = print_sPrintBuffer; print_sCurrentPtr < print_sPrintBuffer + 0x20 && print_sCurrentPtr->string; print_sCurrentPtr++) {
    }
    if (print_sCurrentPtr == print_sPrintBuffer + 0x20) {
        print_sCurrentPtr = NULL;
        return;
    }
    print_sCurrentPtr->x = x;
    print_sCurrentPtr->y = y;
    print_sCurrentPtr->fmtString[0] = (u8)0;
    print_sCurrentPtr->string = string;
    print_sCurrentPtr->scale = 1.0f;
    print_sCurrentPtr->rgba[0] = (u8) normalTextColor.r;
    print_sCurrentPtr->rgba[1] = (u8) normalTextColor.g;
    print_sCurrentPtr->rgba[2] = (u8) normalTextColor.b;
    print_sCurrentPtr->rgba[3] = (u8) normalTextColor.a;
}

void print_bold_overlapping(s32 x, s32 y, f32 scale, u8* string){
    _printbuffer_push_new(x, y, string);
    if(print_sCurrentPtr){
        strcpy(print_sCurrentPtr->fmtString, "fl");
        print_sCurrentPtr->scale = scale;
    }
}

void print_bold_spaced(s32 x, s32 y, u8* string){
    _printbuffer_push_new(x, y, string);
    if(print_sCurrentPtr){
        strcpy(print_sCurrentPtr->fmtString, "f");
    }
}

void print_dialog(s32 x, s32 y, u8* string){
    _printbuffer_push_new(x, y, string);
    if(print_sCurrentPtr){
        strcpy(print_sCurrentPtr->fmtString, "elq");
    }
}

void print_dialog_w_bg(s32 x, s32 y, u8* string){
    _printbuffer_push_new(x, y, string);
    if(print_sCurrentPtr){
        strcpy(print_sCurrentPtr->fmtString, "pb");
    }
}

void print_dialog_gradient(s32 x, s32 y, u8* string, u8 topVertexAlpha, u8 bottomVertexAlpha){
    _printbuffer_push_new(x, y, string);
    if(print_sCurrentPtr){
        print_sCurrentPtr->topVertexAlpha = topVertexAlpha;
        print_sCurrentPtr->bottomVertexAlpha = bottomVertexAlpha;
        strcpy(print_sCurrentPtr->fmtString, "v");
    }
}

void func_802F79D0(s32 x, s32 y, u8* string, s32 topVertexAlpha, s32 bottomVertexAlpha){
    _printbuffer_push_new(x, y, string);
    if(print_sCurrentPtr){
        print_sCurrentPtr->topVertexAlpha = topVertexAlpha;
        print_sCurrentPtr->bottomVertexAlpha = bottomVertexAlpha;
        strcpy(print_sCurrentPtr->fmtString, "delq");
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

void text_setNormalTextColor(s32 r, s32 g, s32 b){
    normalTextColor.r = r;
    normalTextColor.g = g;
    normalTextColor.b = b;
}

void text_setNormalTextAlpha(s32 a){
    normalTextColor.a = a;
}
