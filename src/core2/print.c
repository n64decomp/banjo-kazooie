#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

#define PRINT_BUFFER_COUNT 0x20
#define PRINT_BUFFER_STRING_MAX_LENGTH 0x20

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
    BKSpriteTextureBlock *sprite;//chunkPtr
    void *palette;//palPtr
} FontLetter;

typedef struct map_font_texture_map{
    s16 mapID;
    s16 assetId;
} MapToBoldFontTextureMap;

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

s32 maxFontLetterWidths[FONTS_4_MAX] = {8, 16, 16, 0};

struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} normalTextColor = {0xFF, 0xFF, 0xFF, 0XFF};

MapToBoldFontTextureMap mapToBoldFontTextureMap[] ={
    {MAP_1_SM_SPIRAL_MOUNTAIN,               SPRITE_BOLD_FONT_BLUE_SPHERE_TEXTURE},
    {MAP_2_MM_MUMBOS_MOUNTAIN,               SPRITE_BOLD_FONT_ORANGE_SPHERE_TEXTURE},
    {MAP_3_UNUSED,                           SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_4_UNUSED,                           SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_5_TTC_BLUBBERS_SHIP,                SPRITE_BOLD_FONT_BLUE_SPHERE_TEXTURE},
    {MAP_6_TTC_NIPPERS_SHELL,                SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_7_TTC_TREASURE_TROVE_COVE,          SPRITE_BOLD_FONT_BLUE_SPHERE_TEXTURE},
    {MAP_8_UNUSED,                           SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_9_UNUSED,                           SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_A_TTC_SANDCASTLE,                   SPRITE_BOLD_FONT_BLUE_SPHERE_TEXTURE},
    {MAP_B_CC_CLANKERS_CAVERN,               SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_C_MM_TICKERS_TOWER,                 SPRITE_BOLD_FONT_ORANGE_SPHERE_TEXTURE},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,            SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_E_MM_MUMBOS_SKULL,                  SPRITE_BOLD_FONT_ORANGE_SPHERE_TEXTURE},
    {MAP_F_UNUSED,                           SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_10_BGS_MR_VILE,                     SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_11_BGS_TIPTUP,                      SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_12_GV_GOBIS_VALLEY,                 SPRITE_BOLD_FONT_BLUE_SPHERE_TEXTURE},
    {MAP_13_GV_MEMORY_GAME,                  SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_14_GV_SANDYBUTTS_MAZE,              SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_15_GV_WATER_PYRAMID,                SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_16_GV_RUBEES_CHAMBER,               SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_17_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_18_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_19_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_1A_GV_INSIDE_JINXY,                 SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_1B_MMM_MAD_MONSTER_MANSION,         SPRITE_BOLD_FONT_ORANGE_SPHERE_TEXTURE},
    {MAP_21_CC_WITCH_SWITCH_ROOM,            SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_22_CC_INSIDE_CLANKER,               SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_23_CC_GOLDFEATHER_ROOM,             SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_24_MMM_TUMBLARS_SHED,               SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_25_MMM_WELL,                        SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_26_MMM_NAPPERS_ROOM,                SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_28_MMM_EGG_ROOM,                    SPRITE_BOLD_FONT_ORANGE_SPHERE_TEXTURE},
    {MAP_29_MMM_NOTE_ROOM,                   SPRITE_BOLD_FONT_ORANGE_SPHERE_TEXTURE},
    {MAP_2A_MMM_FEATHER_ROOM,                SPRITE_BOLD_FONT_ORANGE_SPHERE_TEXTURE},
    {MAP_2B_MMM_SECRET_CHURCH_ROOM,          SPRITE_BOLD_FONT_ORANGE_SPHERE_TEXTURE},
    {MAP_2C_MMM_BATHROOM,                    SPRITE_BOLD_FONT_ORANGE_SPHERE_TEXTURE},
    {MAP_2D_MMM_BEDROOM,                     SPRITE_BOLD_FONT_ORANGE_SPHERE_TEXTURE},
    {MAP_2E_MMM_HONEYCOMB_ROOM,              SPRITE_BOLD_FONT_ORANGE_SPHERE_TEXTURE},
    {MAP_2F_MMM_WATERDRAIN_BARREL,           SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_30_MMM_MUMBOS_SKULL,                SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_31_RBB_RUSTY_BUCKET_BAY,            SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_32_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_33_UNUSED,                          SPRITE_BOLD_FONT_BLUE_SPHERE_TEXTURE},
    {MAP_34_RBB_ENGINE_ROOM,                 SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_35_RBB_WAREHOUSE,                   SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_36_RBB_BOATHOUSE,                   SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_37_RBB_CONTAINER_1,                 SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_38_RBB_CONTAINER_3,                 SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_39_RBB_CREW_CABIN,                  SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_3A_RBB_BOSS_BOOM_BOX,               SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_3B_RBB_STORAGE_ROOM,                SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_3C_RBB_KITCHEN,                     SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_3D_RBB_NAVIGATION_ROOM,             SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_3E_RBB_CONTAINER_2,                 SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_3F_RBB_CAPTAINS_CABIN,              SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_41_FP_BOGGYS_IGLOO,                 SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_42_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_43_CCW_SPRING,                      SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_44_CCW_SUMMER,                      SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_45_CCW_AUTUMN,                      SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_46_CCW_WINTER,                      SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_47_BGS_MUMBOS_SKULL,                SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_48_FP_MUMBOS_SKULL,                 SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_49_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_4A_CCW_SPRING_MUMBOS_SKULL,         SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_4B_CCW_SUMMER_MUMBOS_SKULL,         SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_4C_CCW_AUTUMN_MUMBOS_SKULL,         SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_4D_CCW_WINTER_MUMBOS_SKULL,         SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_4E_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_4F_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_50_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_51_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_52_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_53_FP_CHRISTMAS_TREE,               SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_54_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_55_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_56_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_57_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_58_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_59_UNUSED,                          SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_5A_CCW_SUMMER_ZUBBA_HIVE,           SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_5B_CCW_SPRING_ZUBBA_HIVE,           SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_5C_CCW_AUTUMN_ZUBBA_HIVE,           SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_5E_CCW_SPRING_NABNUTS_HOUSE,        SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_5F_CCW_SUMMER_NABNUTS_HOUSE,        SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_60_CCW_AUTUMN_NABNUTS_HOUSE,        SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_61_CCW_WINTER_NABNUTS_HOUSE,        SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_62_CCW_WINTER_HONEYCOMB_ROOM,       SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_63_CCW_AUTUMN_NABNUTS_WATER_SUPPLY, SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_64_CCW_WINTER_NABNUTS_WATER_SUPPLY, SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_65_CCW_SPRING_WHIPCRACK_ROOM,       SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_66_CCW_SUMMER_WHIPCRACK_ROOM,       SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_67_CCW_AUTUMN_WHIPCRACK_ROOM,       SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
    {MAP_68_CCW_WINTER_WHIPCRACK_ROOM,       SPRITE_BOLD_FONT_ORANGE_GRADIENT_TEXTURE},
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
BKSprite *print_sFontSpriteAssets[FONT_SPRITE_ASSETS_5_MAX];

FontLetter  *print_sFonts[FONTS_4_MAX];
PrintBuffer *print_sPrintBuffer;
PrintBuffer *print_sCurrentPtr;
enum fonts_e print_sCurrentFont;
enum fonts_e print_sPreviousFont;
s32 print_sMonospacedModeEnabled;
s32 print_sGradientModeEnabled;
s32 print_sGradient2ModeEnabled; // Related to print_dialog_gradient2(), but it just renders normally?
s32 print_sBrokenFontModeEnabled; // Tries to use a non-existing font and crashes
s32 print_sBackgroundModeEnabled;
s32 print_sUnknownMode;
bool print_sInFontFormatMode;
s32 D_80380B0C;
s32 print_sShakyModeEnabled;
s32 print_sBilinearFilterModeEnabled;
s32 print_sBoldLetterFontFreeTimer;
s32 print_sCurrentBoldFontTexture;
s8 D_80380B20[0x400]; // Some kind of framebuffer?
s8 print_sBoldFontLetterToSpriteMap[0x80];


void func_802F7A2C(s32 arg0);

//returns map texture assetID for current map;
enum asset_e print_getCurrentMapBoldFontTexture(void){
    s32 i;
    for(i = 0; mapToBoldFontTextureMap[i].mapID != 0 ; i++){
        if(gsworld_getMap() == mapToBoldFontTextureMap[i].mapID){
            return mapToBoldFontTextureMap[i].assetId;
        }
    }
    return ASSET_708_SPRITE_EGG_PROJECTILE;
}

// this function reassigns the referenced font mask pixel 
// using the texture @ pixel (x,y)
void print_setBoldFontTexturePixel(BKSpriteTextureBlock *texture, u32 *font, s32 x, s32 y) {
    u16 *pixel;
    s32 r5;
    s32 g5;
    s32 b5;
    s32 a8;
    s32 i8;
    x = MIN(MAX(0, x), texture->w - 1);
    y = MIN(MAX(0, y), texture->h - 1);
    
    pixel = ((u16*)(texture + 1)) + x + y * texture->w;

    r5 = ((*pixel >> 11) & 0x1F);
    g5 = ((*pixel >> 6) & 0x1F);
    b5 = ((*pixel >> 1) & 0x1F);
    
    a8 = (*font >> 0) & 0xff;
    i8 = (*font >> 8) & 0xff;

    r5*=(i8/ 0x1F);
    g5*=(i8/ 0x1F);
    b5*=(i8/ 0x1F);

    *font = (r5 << 0x18) | (g5 << 0x10) | (b5 << 8) | (a8 << 0);
}

//this function applies the texture to the font alpha mask.
void print_applyTextureToBoldFontLetter(BKSpriteTextureBlock *alphaMask, BKSpriteTextureBlock *texture){
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
            print_setBoldFontTexturePixel(texture, pxl, x, y);
            pxl++;
        }
    }
}

//This functions seperates the fonts into letters
FontLetter *print_getLettersFromFont(BKSprite *alphaMask, BKSprite *textureSprite){
    BKSpriteFrame * font = sprite_getFramePtr(alphaMask, 0);
    BKSpriteTextureBlock *chunkPtr;
    FontLetter * letters = malloc((font->chunkCnt + 1)*sizeof(FontLetter));
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

                    letters[i].sprite = chunkPtr;
                    letters[i].palette = palDataPtr;
                    chunkSize = chunkPtr->w*chunkPtr->h;
                    chunkPtr = (BKSpriteTextureBlock *)(chunkDataPtr + chunkSize);
                }
            }
            break;
        case SPRITE_TYPE_RGBA32://L802F4D80
            {
                chunkPtr = (BKSpriteTextureBlock *)(font + 1);
                for( i = 0; i < font->chunkCnt; i++){
                    print_applyTextureToBoldFontLetter(chunkPtr, (BKSpriteTextureBlock *)(sprite_getFramePtr(textureSprite, 0) + 1));
                    letters[i].sprite = chunkPtr;
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
                    letters[i].sprite = chunkPtr;
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
                    letters[i].sprite = chunkPtr;
                    chunkSize = chunkPtr->w*chunkPtr->h;
                    while((s32)chunkDataPtr % 8)
                        chunkDataPtr++;
                    chunkPtr = (BKSpriteTextureBlock *)(chunkDataPtr + chunkSize);
                }
            }
            break;
    };
    return letters;
}

void print_free(void){
    s32 i; 
    for(i = 0; i< 5; i++){
        assetcache_release(print_sFontSpriteAssets[i]);
        print_sFontSpriteAssets[i] = NULL;
        if(i < FONTS_4_MAX){
            free(print_sFonts[i]);
            print_sFonts[i] = NULL;
        }
    }
    free(print_sPrintBuffer);
    print_sPrintBuffer = NULL;
}

void print_clearPrintBufferStrings(void){
    s32 i;
    for(i = 0; i < PRINT_BUFFER_COUNT; i++){
        print_sPrintBuffer[i].string = NULL;
    }
}

void print_setBoldFontTexture(s32 textureId){
    s32 tmp_a2;
    tmp_a2 = func_802546E4(print_sFontSpriteAssets[FONT_SPRITE_ASSETS_1_BOLD_FONT_NUMBERS_ALPHAMASK]);
    if(tmp_a2 & 0xF)
        tmp_a2 += 0x10 - (tmp_a2 & 0xF);
    if(!code_B3A80_func_8033BDAC(SPRITE_BOLD_FONT_NUMBERS_ALPHAMASK, print_sFontSpriteAssets[FONT_SPRITE_ASSETS_1_BOLD_FONT_NUMBERS_ALPHAMASK],tmp_a2)){
        assetcache_release(print_sFontSpriteAssets[FONT_SPRITE_ASSETS_1_BOLD_FONT_NUMBERS_ALPHAMASK]);
        print_sFontSpriteAssets[FONT_SPRITE_ASSETS_1_BOLD_FONT_NUMBERS_ALPHAMASK] = assetcache_get(SPRITE_BOLD_FONT_NUMBERS_ALPHAMASK);
    }
    if(print_sFontSpriteAssets[FONT_SPRITE_ASSETS_3_BOLD_FONT_LETTERS_ALPHAMASK]){
        tmp_a2 = func_802546E4(print_sFontSpriteAssets[FONT_SPRITE_ASSETS_3_BOLD_FONT_LETTERS_ALPHAMASK]);
        if(tmp_a2 & 0xF)
            tmp_a2 += 0x10 - (tmp_a2 & 0xF);
        if(!code_B3A80_func_8033BDAC(SPRITE_BOLD_FONT_LETTERS_ALPHAMASK, print_sFontSpriteAssets[FONT_SPRITE_ASSETS_3_BOLD_FONT_LETTERS_ALPHAMASK],tmp_a2)){
            assetcache_release(print_sFontSpriteAssets[FONT_SPRITE_ASSETS_3_BOLD_FONT_LETTERS_ALPHAMASK]);
            print_sFontSpriteAssets[FONT_SPRITE_ASSETS_3_BOLD_FONT_LETTERS_ALPHAMASK] = assetcache_get(SPRITE_BOLD_FONT_LETTERS_ALPHAMASK);
        }
    }//L802F510C
    print_sFontSpriteAssets[FONT_SPRITE_ASSETS_4_BOLD_FONT_TEXTURE] = assetcache_get(textureId);
    free(print_sFonts[FONTS_1_BOLD_NUMBERS]);
    print_sFonts[FONTS_1_BOLD_NUMBERS] = print_getLettersFromFont(print_sFontSpriteAssets[FONT_SPRITE_ASSETS_1_BOLD_FONT_NUMBERS_ALPHAMASK], print_sFontSpriteAssets[FONT_SPRITE_ASSETS_4_BOLD_FONT_TEXTURE]);
    if(print_sFontSpriteAssets[FONT_SPRITE_ASSETS_3_BOLD_FONT_LETTERS_ALPHAMASK]){
        free(print_sFonts[FONTS_3_BOLD_LETTERS]);
        print_sFonts[FONTS_3_BOLD_LETTERS] = print_getLettersFromFont(print_sFontSpriteAssets[FONT_SPRITE_ASSETS_3_BOLD_FONT_LETTERS_ALPHAMASK], print_sFontSpriteAssets[FONT_SPRITE_ASSETS_4_BOLD_FONT_TEXTURE]);
    }
    assetcache_release(print_sFontSpriteAssets[FONT_SPRITE_ASSETS_4_BOLD_FONT_TEXTURE]);
    print_sFontSpriteAssets[FONT_SPRITE_ASSETS_4_BOLD_FONT_TEXTURE] = NULL;
    print_sCurrentBoldFontTexture = textureId;
}

void print_resetBoldFontTexture(void){
    print_setBoldFontTexture(print_getCurrentMapBoldFontTexture());
    print_clearPrintBufferStrings();
}

void print_init(void){
    s32 i, j;
    s32 length;
    int found;

    length = strlen(boldFontLetters);
    print_sCurrentFont = \
    print_sPreviousFont = \
    print_sMonospacedModeEnabled = \
    print_sGradientModeEnabled = \
    print_sGradient2ModeEnabled = \
    print_sBrokenFontModeEnabled = \
    print_sInFontFormatMode = \
    print_sUnknownMode = \
    print_sBackgroundModeEnabled = \
    print_sShakyModeEnabled = \
    print_sBilinearFilterModeEnabled = 0;
    print_sPreviousBoldLetter = 0;
    func_802F7A2C(3);
    print_sFontSpriteAssets[FONT_SPRITE_ASSETS_0_DIALOG_FONT_ALPHAMASK] = assetcache_get(SPRITE_DIALOG_FONT_ALPHAMASK);
    print_sFontSpriteAssets[FONT_SPRITE_ASSETS_1_BOLD_FONT_NUMBERS_ALPHAMASK] = assetcache_get(SPRITE_BOLD_FONT_NUMBERS_ALPHAMASK);
    print_sFontSpriteAssets[FONT_SPRITE_ASSETS_4_BOLD_FONT_TEXTURE] = assetcache_get(print_getCurrentMapBoldFontTexture());
    print_sFonts[FONTS_0_DIALOG] =  print_getLettersFromFont(print_sFontSpriteAssets[FONT_SPRITE_ASSETS_0_DIALOG_FONT_ALPHAMASK], print_sFontSpriteAssets[FONT_SPRITE_ASSETS_4_BOLD_FONT_TEXTURE]);
    print_sFonts[FONTS_1_BOLD_NUMBERS] =  print_getLettersFromFont(print_sFontSpriteAssets[FONT_SPRITE_ASSETS_1_BOLD_FONT_NUMBERS_ALPHAMASK], print_sFontSpriteAssets[FONT_SPRITE_ASSETS_4_BOLD_FONT_TEXTURE]);
    print_sPrintBuffer = malloc(PRINT_BUFFER_COUNT * sizeof(PrintBuffer));
    print_clearPrintBufferStrings();

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
    assetcache_release(print_sFontSpriteAssets[FONT_SPRITE_ASSETS_4_BOLD_FONT_TEXTURE]);
    print_sFontSpriteAssets[FONT_SPRITE_ASSETS_4_BOLD_FONT_TEXTURE] = NULL;
    print_sCurrentBoldFontTexture = print_getCurrentMapBoldFontTexture();
}

void print_updateBoldLetterFontDelayedFreeing(void){
    if(print_sBoldLetterFontFreeTimer > 0 && --print_sBoldLetterFontFreeTimer == 0){
        assetcache_release(print_sFontSpriteAssets[FONT_SPRITE_ASSETS_3_BOLD_FONT_LETTERS_ALPHAMASK]);
        print_sFontSpriteAssets[FONT_SPRITE_ASSETS_3_BOLD_FONT_LETTERS_ALPHAMASK] = 0;
        free(print_sFonts[FONTS_3_BOLD_LETTERS]);
        print_sFonts[FONTS_3_BOLD_LETTERS] = NULL;
    }
}

void print_freeBoldLetterFont(void){
    if(print_sFontSpriteAssets[FONT_SPRITE_ASSETS_3_BOLD_FONT_LETTERS_ALPHAMASK]){
        assetcache_release(print_sFontSpriteAssets[FONT_SPRITE_ASSETS_3_BOLD_FONT_LETTERS_ALPHAMASK]);
        print_sFontSpriteAssets[FONT_SPRITE_ASSETS_3_BOLD_FONT_LETTERS_ALPHAMASK] = NULL;
    }
    if(print_sFonts[FONTS_3_BOLD_LETTERS]){
        free(print_sFonts[FONTS_3_BOLD_LETTERS]);
        print_sFonts[FONTS_3_BOLD_LETTERS] = NULL;
    }
    print_sBoldLetterFontFreeTimer = 0;
}

void printbuffer_defrag(void){
    print_sFonts[FONTS_0_DIALOG] = (FontLetter *)defrag(print_sFonts[FONTS_0_DIALOG]);
    print_sFonts[FONTS_1_BOLD_NUMBERS] = (FontLetter *)defrag(print_sFonts[FONTS_1_BOLD_NUMBERS]);
    if(print_sFonts[FONTS_3_BOLD_LETTERS]){
        print_sFonts[FONTS_3_BOLD_LETTERS] = (FontLetter *)defrag(print_sFonts[FONTS_3_BOLD_LETTERS]);
    }
    print_sPrintBuffer = (PrintBuffer *)defrag(print_sPrintBuffer);
}

//returns the pixel data and type for a given letter
BKSpriteTextureBlock *print_getBoldFontLetterSprite(s32 letterId, s32 *fontType){
    if(print_sCurrentFont != FONTS_1_BOLD_NUMBERS || (print_sCurrentFont == FONTS_1_BOLD_NUMBERS && letterId < 0xA)){
        *fontType = print_sFontSpriteAssets[print_sCurrentFont]->type;
        return print_sFonts[print_sCurrentFont][letterId].sprite;
    }
    else{//L802F5510
        if(!print_sFontSpriteAssets[FONT_SPRITE_ASSETS_3_BOLD_FONT_LETTERS_ALPHAMASK]){
            print_sFontSpriteAssets[FONT_SPRITE_ASSETS_3_BOLD_FONT_LETTERS_ALPHAMASK] = assetcache_get(SPRITE_BOLD_FONT_LETTERS_ALPHAMASK);
            print_sFontSpriteAssets[FONT_SPRITE_ASSETS_4_BOLD_FONT_TEXTURE] = assetcache_get(print_sCurrentBoldFontTexture);
            print_sFonts[FONTS_3_BOLD_LETTERS] = print_getLettersFromFont(print_sFontSpriteAssets[FONT_SPRITE_ASSETS_3_BOLD_FONT_LETTERS_ALPHAMASK], print_sFontSpriteAssets[FONT_SPRITE_ASSETS_4_BOLD_FONT_TEXTURE]);
            assetcache_release(print_sFontSpriteAssets[FONT_SPRITE_ASSETS_4_BOLD_FONT_TEXTURE]);
            print_sFontSpriteAssets[FONT_SPRITE_ASSETS_4_BOLD_FONT_TEXTURE] = NULL;
        }//L802F5568
        print_sBoldLetterFontFreeTimer = 5;
        *fontType  = print_sFontSpriteAssets[FONT_SPRITE_ASSETS_3_BOLD_FONT_LETTERS_ALPHAMASK]->type;
        return print_sFonts[FONTS_3_BOLD_LETTERS][letterId-10].sprite;
    }
}

//returns the letter's palette
void *print_getCurrentFontPalette(u8 letterId){
    return  print_sFonts[print_sCurrentFont][letterId].palette;
}

void _printbuffer_draw_letter(char letter, f32* xPtr, f32* yPtr, f32 scale, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    static f32 left_margin;

    BKSpriteTextureBlock *letter_sprite;
    s32 sp210;
    s32 letter_id;
    s32 valid_letter;
    s8 y_offset;
    f32 x;
    f32 y;
    f32 letter_width;
    s32 font_type;

    int i;

    valid_letter = 0;
    x = *xPtr;
    y = *yPtr;
    y_offset = 0;

    if(!print_sUnknownMode && !letter){
        left_margin = 0.0f;
    }//L802F563C

    switch(print_sCurrentFont){
        case FONTS_0_DIALOG: //L802F5678
            if(letter >= '\x21' && letter < '\x5f'){
                letter_id = letter - '\x21';
                valid_letter = 1;
            }
            break;
        case FONTS_1_BOLD_NUMBERS: //L802F56A0
            // This is also used with the bold letters font
            if(letter < '\x80' && print_sBoldFontLetterToSpriteMap[letter] >= 0){
                for(i = 0; boldFontKernings[i].firstLetter != 0; i++){
                    if(letter == boldFontKernings[i].secondLetter && print_sPreviousBoldLetter == boldFontKernings[i].firstLetter){
                        y_offset = boldFontKernings[i].yOffset;
                        break;
                    }
                }//L802F5710
                letter_id = print_sBoldFontLetterToSpriteMap[letter];
                valid_letter = 1;
                print_sPreviousBoldLetter = letter;
                y += (f32)y_offset*scale;
            }//L802F5738
            break;
        case FONTS_2_UNUSED: //L802F5740
            letter_id = letter;
            if(print_sUnknownMode){
                valid_letter = 1;
                letter_id += (print_sUnknownMode << 8) - 0x100;
                print_sUnknownMode = 0;
            }
            else{//L802F5764
                if(letter_id > 0 && letter_id < 0xfD)
                    valid_letter = 1;
            }
            break;
    }//L802F5778

    if(!valid_letter || print_sInFontFormatMode){
        print_sInFontFormatMode = FALSE;
        switch(letter){
            case ' '://802F5818
                *xPtr += ((print_sMonospacedModeEnabled) ? maxFontLetterWidths[print_sCurrentFont]: maxFontLetterWidths[print_sCurrentFont]*0.8) * scale;
                break;

            case 'b': //L802F5890
                //toggle background
                print_sBackgroundModeEnabled = print_sBackgroundModeEnabled ^ 1;
                break;

            case 'f': //L802F58A8
                print_sPreviousFont = print_sCurrentFont = print_sCurrentFont ^ 1;
                break;

            case 'l': //L802F58BC
                print_sShakyModeEnabled = 0;
                break;

            case 'h': //L802F58C8
                print_sShakyModeEnabled = 1;
                break;

            case 'j': //L802F58D4
                if(print_sBrokenFontModeEnabled == 0){
                    print_sBrokenFontModeEnabled = 1;
                    print_sPreviousFont = print_sCurrentFont;
                    print_sCurrentFont = FONTS_2_UNUSED;
                }
                break;

            case 'e': //L802F58FC
                if(print_sBrokenFontModeEnabled){
                    print_sBrokenFontModeEnabled = 0;
                    print_sCurrentFont = print_sPreviousFont;
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
                print_sGradient2ModeEnabled ^= 1;
                if(print_sGradient2ModeEnabled){
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
                print_sUnknownMode = 1;
                break;

            case 0xff://L802F5BFC
                print_sUnknownMode = 2;
                break;
            default:
                break;
        }
    }
    else{//L802F5C08
        letter_sprite = print_getBoldFontLetterSprite(letter_id, &font_type);
        if (print_sShakyModeEnabled != 0) {
               x += randf2(-2.0f, 2.0f);
               y += randf2(-2.0f, 2.0f);
        }
        letter_width = (print_sMonospacedModeEnabled != 0) ? maxFontLetterWidths[print_sCurrentFont] : letter_sprite->x;

        if (left_margin == 0.0f) {
            left_margin = -letter_width * 0.5;
        }

        x += (left_margin + (letter_width - letter_sprite->x) * 0.5);
        y -= letter_sprite->h*0.5;
        sp210 = (s32)(letter_sprite + 1);
        while(sp210 % 8){
            sp210++;
        }
        if (font_type == SPRITE_TYPE_RGBA32) { 
            gDPLoadTextureTile((*gfx)++, sp210, G_IM_FMT_RGBA, G_IM_SIZ_32b, letter_sprite->w, letter_sprite->h, 0, 0, letter_sprite->x-1, letter_sprite->y - 1, NULL, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        } else if (font_type == SPRITE_TYPE_IA8) {
            gDPLoadTextureTile((*gfx)++, sp210, G_IM_FMT_IA, G_IM_SIZ_8b, letter_sprite->w, letter_sprite->h, 0, 0, letter_sprite->x-1, letter_sprite->y - 1, NULL, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        } else if (font_type == SPRITE_TYPE_I8) {
            gDPLoadTextureTile((*gfx)++, sp210, G_IM_FMT_I, G_IM_SIZ_8b, letter_sprite->w, letter_sprite->h, 0, 0, letter_sprite->x-1, letter_sprite->y - 1, NULL, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        } else if (font_type == SPRITE_TYPE_I4) {
            gDPLoadTextureTile_4b((*gfx)++, sp210, G_IM_FMT_I, letter_sprite->w, letter_sprite->h, 0, 0, letter_sprite->x-1, letter_sprite->y-1, NULL, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        } else if (font_type == SPRITE_TYPE_CI8) {
            void * pal = print_getCurrentFontPalette(letter_id);
            gDPLoadTLUT_pal256((*gfx)++, pal);
            gDPLoadTextureTile((*gfx)++, sp210, G_IM_FMT_CI, G_IM_SIZ_8b, letter_sprite->w, letter_sprite->h, 0, 0, letter_sprite->x-1, letter_sprite->y-1, NULL, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gDPSetTextureLUT((*gfx)++, G_TT_RGBA16);
        }//L802F6570
        if (print_sGradient2ModeEnabled != 0) {
            s32 temp_t1;
            s32 phi_a0;
            temp_t1 = ((print_sCurrentPtr->topVertexAlpha - print_sCurrentPtr->y) - D_80380B0C) + 1;
            phi_a0 =  - MAX(1 - D_80380B0C, MIN(0, temp_t1));
            
            gDPSetTextureImage((*gfx)++, G_IM_FMT_I, G_IM_SIZ_8b, 32, &D_80380B20);
            gDPSetTile((*gfx)++, G_IM_FMT_I, G_IM_SIZ_8b, (letter_sprite->x + 8) >> 3, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
            gDPLoadSync((*gfx)++);
            gDPLoadTile((*gfx)++, G_TX_LOADTILE, 0 << G_TEXTURE_IMAGE_FRAC, (phi_a0) << G_TEXTURE_IMAGE_FRAC, (letter_sprite->x) << G_TEXTURE_IMAGE_FRAC, (D_80380B0C - 1) << G_TEXTURE_IMAGE_FRAC);
            gDPPipeSync((*gfx)++);
            gDPSetTile((*gfx)++, G_IM_FMT_I, G_IM_SIZ_8b, ((letter_sprite->x - 0 + 1)*G_IM_SIZ_8b_LINE_BYTES + 7) >> 3, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
            gDPSetTileSize((*gfx)++, 1, 0 << G_TEXTURE_IMAGE_FRAC, (MAX(0, temp_t1) + phi_a0) << G_TEXTURE_IMAGE_FRAC, (letter_sprite->x) << G_TEXTURE_IMAGE_FRAC, (MAX(0, temp_t1) - (1 - D_80380B0C))<<G_TEXTURE_IMAGE_FRAC);
            
            // gDPLoadMultiTile((*gfx)++, &D_80380B20,)
            
        }//L802F677C
        if (print_sGradientModeEnabled != 0) {
            f32 temp_f24;
            f32 spD0;
            f32 ix;
            f32 iy;
            f32 temp_f26;
            f32 spC0;

            temp_f24 = (letter_sprite->x - 1.0);
            spD0 = letter_sprite->y - 1.0;
            temp_f26 = (f64) x - (f32) gFramebufferWidth * 0.5;
            spC0 = (f64)y - (f32)gFramebufferHeight*0.5 -0.5f;
            gSPVertex((*gfx)++, *vtx, 4, 0);
            for(iy = 0.0f; iy < 2.0; iy+= 1.0){
                for(ix = 0.0f; ix < 2.0; ix += 1.0){
                    s32 s = (ix * temp_f24 * 64.0f);
                    (*vtx)->v.ob[0] = (s16)(s32)((f64) (temp_f26 + (temp_f24 *  scale  * ix)) * 4.0);
                    {
                        s32 t = (iy * spD0 * 64.0f);
                        (*vtx)->v.ob[1] = (s16) (s32) ((f64) (spC0 + (spD0 * scale * iy)) * -4.0);
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
            gSPScisTextureRectangle((*gfx)++, (s32)(x*4.0f), (s32)(y*4.0f), (s32)((x + letter_sprite->x*scale)*4.0f), (s32)((y + letter_sprite->y*scale)*4.0f), 0, 0, 0, (s32)(1024.0f / scale), (s32)(1024.0f / scale));
        }
        *xPtr += letter_width * scale;
    }
}

f32 print_calculateLetterXPos(u8 letter, f32* xPtr, f32 *yPtr, f32 scale){
    s32 letter_id;
    s32 i;
    bool valid_letter;
    f32 x;
    s32 x_offset;
    f32 width;
    s32 font_type;

    x = *xPtr;
    valid_letter = FALSE;
    x_offset = 0;
    if (print_sCurrentFont == FONTS_1_BOLD_NUMBERS) {
        if (letter < 0x80) {
            if (print_sBoldFontLetterToSpriteMap[letter] >= 0) {
                for(i = 0; boldFontKernings[i].firstLetter != 0; i++) {
                    if ((boldFontKernings[i].secondLetter == letter) && (boldFontKernings[i].firstLetter == print_sPreviousBoldLetter)) {
                        x_offset = boldFontKernings[i].xOffset;
                        break;
                    }
                }
                print_sPreviousBoldLetter = letter;
                letter_id = print_sBoldFontLetterToSpriteMap[letter];
                valid_letter = TRUE;
                x += x_offset * scale;
            }
        }
    }
    else{
        return *xPtr;
    }
    if (!valid_letter || print_sInFontFormatMode) {
        if (letter == ' ') {
            width = (print_sMonospacedModeEnabled) ? maxFontLetterWidths[print_sCurrentFont] : 0.8*maxFontLetterWidths[print_sCurrentFont];
        }
        else{
            return *xPtr;
        }
    }
    else {
        if(print_sMonospacedModeEnabled){
            width = maxFontLetterWidths[print_sCurrentFont];
        }
        else{
            width = print_getBoldFontLetterSprite(letter_id, &font_type)->x;
        }
    }
    width += (x_offset - 4);
    *xPtr += width * scale;

    return x;
}

void printbuffer_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    static f32 letter_x_coords[PRINT_BUFFER_STRING_MAX_LENGTH];

    s32 j;
    f32 _x;
    f32 _y;
    f32 width;

    gSPDisplayList((*gfx)++, D_80369238);
    for(print_sCurrentPtr = print_sPrintBuffer; print_sCurrentPtr < print_sPrintBuffer + PRINT_BUFFER_COUNT; print_sCurrentPtr++){
        if (print_sCurrentPtr->string != 0) {
            _x = (f32) print_sCurrentPtr->x;
            _y = (f32) print_sCurrentPtr->y;
            //toggle on string format modifiers
            for(j = 0; print_sCurrentPtr->fmtString[j] != 0; j++) {
                _printbuffer_draw_letter(0xFD, &_x, &_y, 1.0f, gfx, mtx, vtx);
                _printbuffer_draw_letter(print_sCurrentPtr->fmtString[j], &_x, &_y, 1.0f, gfx, mtx, vtx);
            }
            if (print_sBackgroundModeEnabled != 0) {
                width = (strlen(print_sCurrentPtr->string) -1)*maxFontLetterWidths[print_sCurrentFont];
                gDPPipeSync((*gfx)++);
                gDPSetPrimColor((*gfx)++, 0, 0, 0x00, 0x00, 0x00, 0x64);
                gDPSetCombineMode((*gfx)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
                gDPScisFillRectangle((*gfx)++, _x - maxFontLetterWidths[print_sCurrentFont]/2 - 1.0f, _y - maxFontLetterWidths[print_sCurrentFont]/2 - 1.0f, _x + width + maxFontLetterWidths[print_sCurrentFont]/2, _y + maxFontLetterWidths[print_sCurrentFont]/2 + 1.0f);
                gDPPipeSync((*gfx)++);

            }//L802F73E8
            if ((print_sGradient2ModeEnabled == 0) && (print_sGradientModeEnabled == 0)) {
                if (print_sCurrentFont != FONTS_0_DIALOG) {
                    gDPSetCombineMode((*gfx)++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                    gDPSetPrimColor((*gfx)++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                } else {
                    gDPSetCombineMode((*gfx)++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                    gDPSetPrimColor((*gfx)++, 0, 0, print_sCurrentPtr->rgba[0], print_sCurrentPtr->rgba[1], print_sCurrentPtr->rgba[2], print_sCurrentPtr->rgba[3]);
                }
            }
            if ((print_sCurrentFont == FONTS_1_BOLD_NUMBERS) && ((f64) print_sCurrentPtr->scale < 0.0)) {
                for(j = 0; print_sCurrentPtr->string[j]; j++){
                    letter_x_coords[j] = print_calculateLetterXPos(print_sCurrentPtr->string[j], &_x, &_y, -print_sCurrentPtr->scale);
                }
                while(j >= 0){
                    _x = letter_x_coords[j];
                    _printbuffer_draw_letter(print_sCurrentPtr->string[j], &_x, &_y, -print_sCurrentPtr->scale, gfx, mtx, vtx);
                    j--;
                }
            } else {
                for(j = 0; (print_sCurrentPtr->string[j] != 0) || (print_sUnknownMode != 0); j++){
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
    for(print_sCurrentPtr = print_sPrintBuffer; print_sCurrentPtr < print_sPrintBuffer + PRINT_BUFFER_COUNT && print_sCurrentPtr->string; print_sCurrentPtr++) {
    }
    if (print_sCurrentPtr == print_sPrintBuffer + PRINT_BUFFER_COUNT) {
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

void print_dialog_gradient2(s32 x, s32 y, u8* string, s32 topVertexAlpha, s32 bottomVertexAlpha){
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
