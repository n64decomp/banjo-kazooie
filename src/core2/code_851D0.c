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

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_851D0/func_8030C33C.s")
#else
void func_8030C33C(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    s32 sp80;
    s32 sp74;
    s32 sp70;
    s32 sp64;
    s32 sp60;
    s32 sp54;
    s32 sp50;
    s32 sp48;
    s32 sp40;
    s16 temp_s4;
    s16 temp_t4;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a3;
    s32 temp_t6;
    s32 temp_t8;
    void *temp_a1_2;
    void *temp_a2;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s0_3;
    void *temp_s0_4;
    void *temp_s0_5;
    void *temp_s0_6;
    void *temp_s0_7;
    void *temp_s0_8;
    void *temp_s0_9;
    void *temp_s2;
    s32 phi_ra;
    s32 phi_t5;
    s32 phi_t4;
    s32 phi_t3;
    s32 phi_t2;
    s32 phi_t1;
    s32 phi_s3;
    s32 phi_s5;
    s16 phi_s6;
    s32 phi_v0;
    s16 phi_v1;
    s16 phi_s4;
    s16 phi_t4_2;
    s16 phi_v0_2;
    s16 phi_v1_2;
    s32 phi_v0_3;
    s32 phi_a0;
    s32 phi_s7;

    gSPDisplayList((*gfx)++, D_8036C450);
    sp64 = 0x1F;
    sp54 = 0x130;
    sp74 = 0;
    phi_t4_2 = 0xB0;
    do {
        phi_ra = sp74 << 5;
        phi_t5 = (0x40 + 7);
        phi_t4 = (s32) phi_t4_2;
        phi_t3 = (s32) sp56;
        phi_t2 = (sp64 << 2) & 0xFFF;
        phi_t1 = (sp74 << 2) & 0xFFF;
        phi_s3 = 0;
        phi_s5 = 0x1F;
        phi_s6 = 0x188;
        phi_s4 = 0x108;
        phi_s7 = 0;
loop_2:
        sp40 = phi_ra;
        sp80 = phi_t5;
        sp48 = phi_t4;
        sp50 = phi_t3;
        sp60 = phi_t2;
        sp70 = phi_t1;

        // gDPLoadTextureTile((*gfx)++, &D_80382450, G_IM_FMT_IA, G_IM_SIZ_16b, 160, height, uls, ult, lrs, lrt, pal, cms, cmt, masks, maskt, shifts, shiftt)

        gDPSetTextureImage((*gfx)++, G_IM_FMT_IA, G_IM_SIZ_16b, 160, D_80382450);
        // temp_a1 = (((0x40 + 7 >> 3) & 0x1FF) << 9) | 0xF5700000;
        // temp_s0_2->unk0 = temp_a1;
        // temp_s0_2->unk4 = 0x07080200;
        gDPSetTile((*gfx)++, G_IM_FMT_IA, G_IM_SIZ_32b, 427, 0x0101, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 1, 12, G_TX_NOMIRROR | G_TX_WRAP, 8, 7);
        gDPLoadSync((*gfx)++);
        // temp_a3 = ((phi_s3 * 4) & 0xFFF) << 0xC;
        // temp_a0 = ((phi_s5 * 4) & 0xFFF) << 0xC;
        // temp_s0_4->unk0 = (s32) (temp_a3 | 0xF4000000 | phi_t1);
        // temp_s0_4->unk4 = (s32) (temp_a0 | 0x07000000 | phi_t2);
        gDPLoadTile((*gfx)++, G_TX_LOADTILE, 0, 0, 0, 0);
        gDPPipeSync((*gfx)++);

        // temp_s0_6->unk0 = temp_a1;
        // temp_s0_6->unk4 = 0x00080200;
        gDPSetTile((*gfx)++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0100, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
        // temp_s0_7->unk4 = (s32) (temp_a0 | phi_t2);
        // temp_s0_7->unk0 = (s32) (temp_a3 | 0xF2000000 | phi_t1);
        gDPSetTileSize((*gfx)++, G_TX_RENDERTILE, 0, 0, 0, 0);
        temp_a1_2 = *gfx;
        *gfx = temp_a1_2 + 8;
        if ((s32) phi_s6 > 0) {
            phi_v1 = (s16) (phi_s7 + 0x188);
        } else {
            phi_v1 = 0;
        }
        if (phi_t3 > 0) {
            phi_v0 = phi_t3;
        } else {
            phi_v0 = 0;
        }
        temp_a1_2->unk0 = (s32) ((phi_v0 & 0xFFF) | 0xE4000000 | ((phi_v1 & 0xFFF) << 0xC));
        if ((s32) phi_s4 > 0) {
            phi_v1_2 = phi_s4;
        } else {
            phi_v1_2 = 0;
        }
        if ((s32) phi_t4_2 > 0) {
            phi_v0_2 = phi_t4_2;
        } else {
            phi_v0_2 = 0;
        }
        temp_a1_2->unk4 = (s32) ((phi_v0_2 & 0xFFF) | ((phi_v1_2 & 0xFFF) << 0xC));
        temp_a2 = *gfx;
        *gfx = temp_a2 + 8;
        temp_a2->unk0 = 0xB4000000;
        phi_s5 += 0x20;
        if ((s32) phi_s4 < 0) {
            temp_t6 = (s32) (phi_s4 << 0xA) >> 7;
            if (temp_t6 < 0) {
                phi_a0 = temp_t6;
            } else {
                phi_a0 = 0;
            }
        } else {
            phi_a0 = 0;
        }
        if (phi_t4 < 0) {
            temp_t8 = (s32) (phi_t4_2 << 0xA) >> 7;
            if (temp_t8 < 0) {
                phi_v0_3 = temp_t8;
            } else {
                phi_v0_3 = 0;
            }
        } else {
            phi_v0_3 = 0;
        }
        temp_a2->unk4 = (s32) (((phi_ra - phi_v0_3) & 0xFFFF) | (((phi_s3 << 5) - phi_a0) << 0x10));
        temp_s0_8 = *gfx;
        temp_s4 = phi_s4 + 0x80;
        *gfx = temp_s0_8 + 8;
        temp_s0_8->unk0 = 0xB3000000;
        temp_s0_8->unk4 = 0x04000400;
        phi_s3 += 0x20;
        phi_s6 += 0x80;
        phi_s4 = temp_s4;
        phi_s7 += 0x80;
        if (temp_s4 != 0x388) {
            goto loop_2;
        }
        temp_t4 = phi_t4 + 0x80;
        sp74 += 0x20;
        sp54 += 0x80;
        sp64 += 0x20;
        phi_t4_2 = temp_t4;
    } while (temp_t4 != 0x2B0);
    gSPDisplayList((*gfx)++, D_8036C4A8);
}
#endif


s32 func_8030C704(void){
    return D_80382450;
}

void func_8030C710(void){
    func_802542F4(0, 0xA0, 0, 0x80);
}
