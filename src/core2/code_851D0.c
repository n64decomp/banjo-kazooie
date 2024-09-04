#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_803A5D00[2][0x1ecc0];


#define TILE_SIZE 32
#define TILE_COUNT_X 5
#define TILE_COUNT_Y 4
#define IMAGE_WIDTH (TILE_SIZE * TILE_COUNT_X)
#define IMAGE_HEIGHT (TILE_SIZE * TILE_COUNT_Y)
#define SCREEN_WIDTH 292
#define SCREEN_HEIGHT 216
#define HORIZONTAL_MARGIN (((SCREEN_WIDTH) - IMAGE_WIDTH) / 2)
#define VERTICAL_MARGIN (((SCREEN_HEIGHT) - IMAGE_HEIGHT) / 2)

/* .data */
Gfx D_8036C450[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineLERP(TEXEL0, 0, PRIMITIVE_ALPHA, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE_ALPHA, 0, 0, 0, 0, TEXEL0),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0x78),
    gsSPEndDisplayList()
};

Gfx D_8036C4A8[] = {
    gsDPPipeSync(),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsSPEndDisplayList()
};

/* .bss */
s16 *D_80382450;
void *D_80382454;


/* .code */
void func_8030C160(void){
    func_8024F150();
}

void func_8030C180(void){
    func_8024F180();
}

void func_8030C1A0(void){
    if(D_80382454 == NULL){
        D_80382454 = D_80382450 = malloc(IMAGE_WIDTH * IMAGE_HEIGHT * sizeof(u16) + 64);

        while((s32)D_80382450 & 0x3F){
            D_80382450++;
        }
    }
}

void func_8030C204(void){
    if(D_80382454){
        free(D_80382454);
        D_80382454 = NULL;
    }

    switch(getGameMode()){
        case GAME_MODE_8_BOTTLES_BONUS:
            chBottlesBonus_func_802DEA8C(0, 0);
            break;
        case GAME_MODE_A_SNS_PICTURE:
            func_802DF11C(0, 0);
            break;
    }
}

void func_8030C27C(void){
    switch(getGameMode()){
        case GAME_MODE_8_BOTTLES_BONUS:
            chBottlesBonus_spawn(0, 0);
            break;
        case GAME_MODE_A_SNS_PICTURE:
            func_802DF090(0, 0);
            break;

    }
}

void func_8030C2D4(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    func_80254348();
    func_80253640(gdl, D_803A5D00[func_8024BDA0()]);
}

// Draws a 160x128 image pointed to by D_80382450 into the center of the screen
void func_8030C33C(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    s32 x, y;

    // Set up the rendering state to draw the image
    gSPDisplayList((*gfx)++, D_8036C450);
    // Iterate over every tile in the image
    for (y = 0; y < TILE_COUNT_Y; y++) {
        for(x = 0; x < TILE_COUNT_X; x++){
            // Load the current tile from the image
            gDPLoadTextureTile((*gfx)++, osVirtualToPhysical(D_80382450), G_IM_FMT_IA, G_IM_SIZ_16b, IMAGE_WIDTH, IMAGE_HEIGHT,
                TILE_SIZE * x, TILE_SIZE * y, TILE_SIZE * (x + 1) - 1, TILE_SIZE * (y + 1) - 1,
                0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                G_TX_NOMASK, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOLOD);
            // Draw the tile to the screen at the target position
            gSPScisTextureRectangle((*gfx)++,
                (TILE_SIZE * x + HORIZONTAL_MARGIN) * 4,       (TILE_SIZE * y + VERTICAL_MARGIN) * 4,
                (TILE_SIZE * (x + 1) + HORIZONTAL_MARGIN) * 4, (TILE_SIZE * (y + 1) + VERTICAL_MARGIN) * 4,
                0,
                TILE_SIZE * x << 5, TILE_SIZE * y << 5,
                1 << 10, 1 << 10);
        }
    }
    // Reset the rendering state
    gSPDisplayList((*gfx)++, D_8036C4A8);
}


s32 func_8030C704(void){
    return D_80382450;
}

void func_8030C710(void){
    func_802542F4(0, 0xA0, 0, 0x80);
}
