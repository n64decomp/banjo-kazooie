#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_803A5D00[2][0x1ecc0];

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
        D_80382454 = D_80382450 = malloc(0xA040);

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
            func_802DEA8C(0, 0);
            break;
        case GAME_MODE_A_SNS_PICTURE:
            func_802DF11C(0, 0);
            break;
    }
}

void func_8030C27C(void){
    switch(getGameMode()){
        case GAME_MODE_8_BOTTLES_BONUS:
            func_802DEA18(0, 0);
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

void func_8030C33C(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    s32 x, y;
 
    gSPDisplayList((*gfx)++, D_8036C450);
    for (y = 0; y < 4; y++) {
        for(x = 0; x < 5; x++){
            gDPLoadTextureTile((*gfx)++, osVirtualToPhysical(D_80382450), G_IM_FMT_IA, G_IM_SIZ_16b, 160, 128,
                0x20*x, 0x20*y, 0x20*(x + 1) - 1, 0x20*(y + 1) - 1,
                0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                G_TX_NOMASK, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOLOD);
            gSPScisTextureRectangle((*gfx)++,
                (0x20*x + 0x42)*4,       (0x20*y + 0x2C)*4,
                (0x20*(x + 1) + 0x42)*4, (0x20*(y + 1) + 0x2C)*4,
                0,
                0x20*x << 5, 0x20*y << 5,
                1 << 10, 1 << 10);
        }
    }
    gSPDisplayList((*gfx)++, D_8036C4A8);
}


s32 func_8030C704(void){
    return D_80382450;
}

void func_8030C710(void){
    func_802542F4(0, 0xA0, 0, 0x80);
}
