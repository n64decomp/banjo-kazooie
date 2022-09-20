#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s16 D_803A5D00[2][0xF660];


typedef struct {
    void *unk0;
    void *unk4;
    s32 unk8;
    void (*unkC)(void);
    s32 unk10;
}Struct_Core2_6A4B0_2;

typedef struct {
    s16 unk0[3];
}Struct_Core2_6A4B0_1;

typedef struct {
    u8 pad0[0x8];
    u16 *unk8;
    u8 padC[4];
    s32 unk10;
}Struct_Core2_6A4B0_0;

s32  func_802F1804(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_802F18B8(Struct_Core2_6A4B0_2 *arg0);

/* .data */
extern Gfx D_803689D0[];
extern s32 D_80368A10[2][3];
extern s32 D_80368A28[2][3];

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6A4B0/func_802F1440.s")
#else
void func_802F1440(Struct_Core2_6A4B0_0 *arg0, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Vtx *sp9C;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    Struct_Core2_6A4B0_1 *temp_v0_2;
    s32 var_s3;

    if (arg0->unk10 == 0) {
        func_8024C7B8(gfx, mtx);
    }
    gSPDisplayList((*gfx)++, D_803689D0);

    sp9C = *vtx;
    for(sp4C = 0; sp4C < 6; sp4C++){
        for(sp50 = 0; sp50 < 9; sp50++){
            for(sp54 = 0; sp54 < 2; sp54++){
                for(var_s3 = 0; var_s3 < 3; var_s3++){
                    temp_v0_2 = func_802F1804(arg0, sp50, sp4C, sp54, var_s3);
                    sp9C->v.ob[0] = temp_v0_2->unk0[0];
                    sp9C->v.ob[1] = temp_v0_2->unk0[1];
                    sp9C->v.ob[2] = temp_v0_2->unk0[2];

                    sp9C->v.flag = 0;

                    sp9C->v.tc[0] = D_80368A10[sp54][var_s3];
                    sp9C->v.tc[1] = D_80368A28[sp54][var_s3];

                    sp9C->n.n[0] = -1;
                    sp9C->n.n[1] = -1;
                    sp9C->n.n[2] = -1;
                    sp9C->n.a = 0xFF;
                    sp9C++;
                }
            }
        }
    }
    *vtx = sp9C;
    var_s3 = 0;
    gSPVertex((*gfx)++, osVirtualToPhysical(sp9C), 16, 0);
    for(sp4C = 0; sp4C < 6; sp4C++){
        for(sp50 = 0; sp50 < 9; sp50++){
            gDPLoadTextureTile((*gfx)++, osVirtualToPhysical(&arg0->unk8[(sp4C*0x20 + 0xC) * D_80276588 + (sp50*0x20 + 1)]), G_IM_FMT_RGBA, G_IM_SIZ_16b, D_80276588, 0, 0, 0, 33, 33, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            for(sp54 = 0; sp54 < 2; sp54++){
                gSP1Triangle((*gfx)++, var_s3, var_s3 + 1, var_s3 + 2, 0);
                var_s3 += 3;
                if (var_s3 == 0xF) {
                    sp9C += 0xF;
                    var_s3 = 0;
                    gSPVertex((*gfx)++, osVirtualToPhysical(sp9C), 16, 0);
                }
            }
        }
    }
    if (arg0->unk10 == 0) {
        func_8024C904(gfx, mtx);
    }
}
#endif

s32 func_802F1804(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return *arg0 + (arg1 * 0x24) + (arg2 * 0x144) + (arg3 * 0x12) + (arg4 * 6);
}

void func_802F1858(Struct_Core2_6A4B0_2 *arg0){
    if(arg0->unkC != NULL){
        arg0->unkC();
    }
}

void func_802F1884(Struct_Core2_6A4B0_2 *arg0){
    func_802F18B8(arg0);
    free(arg0->unk0);
    free(arg0);
}

void func_802F18B8(Struct_Core2_6A4B0_2 *arg0){
    if(arg0->unk4 != NULL){
        free(arg0->unk4);
        arg0->unk4 = NULL;
    }
}

Struct_Core2_6A4B0_2 *func_802F18F0(void){
    Struct_Core2_6A4B0_2 *self;

    self = (Struct_Core2_6A4B0_2 *) malloc(sizeof(Struct_Core2_6A4B0_2));
    self->unk0 = malloc(0x798);
    self->unk4 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    return self;
}

void func_802F1934(Struct_Core2_6A4B0_2 * arg0, s32 arg1){
    func_802F18B8(arg0);
    arg0->unk4 = malloc(D_80276588*D_8027658C*sizeof(u16) + 0x10);
    arg0->unk8 = arg0->unk4;
    while((arg0->unk8 & 0x10) == 0){
        (arg0->unk8)++;
    }
    func_80253010(arg0->unk8, D_803A5D00[arg1], D_80276588*D_8027658C*sizeof(u16));
    osWriteBackDCacheAll();
}

void func_802F1A08(s32 arg0) { }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6A4B0/func_802F1A10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6A4B0/func_802F1CAC.s")
// void func_802F1CAC(void *arg0) {
//     s32 sp84[3];
//     f32 sp78[3];
//     s32 sp60;
//     s32 *var_s1;
//     s32 temp_lo;
//     s32 temp_v0;
//     s32 var_fp;
//     s32 var_s0;
//     s32 var_s4;
//     s32 var_s5;
//     s32 var_s6;
//     s32 var_s7;
//     void *temp_v0_2;
//     void *var_s2;

//     func_8024C5CC(sp78);
//     var_fp = 0;
//     sp84[0] = (s32) ((1000.0f - sp78[0]) - 200.0f);
//     sp84[0] = (s32) ((0.0f - sp78[1]) + 300.0f);
//     sp84[2] = (s32) ((2000.0f - sp78[2]) + 0.0f);
//     for(var_s7 = 0; var_s7 < 6; var_s7++){
//         var_s6 = 0;
//         for(var_s5 = 0; var_s5 < 9; var_s5++){
//             sp60 = 0;
//             for(var_s4 = 0; var_s4 < 2; var_s4++){
//                 temp_v0 = sp60 * 4;
//                 var_s1 = temp_v0 + &D_80368A70;
//                 var_s2 = temp_v0 + &D_80368A88;
//                 var_s0 = 0;
//                 for(var_s0 = 0; var_s0 < 2; var_s0++){
//                     temp_v0_2 = func_802F1804(arg0, var_s5, var_s7, var_s4, var_s0);
//                     temp_lo = *var_s1 * 0x32;
//                     var_s1 += 4;
//                     var_s2 += 4;
//                     temp_v0_2->unk0 = (s16) (temp_lo + sp84 + var_s6);
//                     temp_v0_2->unk2 = (s16) ((sp88 - var_fp) - (var_s2->unk-4 * 0x32));
//                     temp_v0_2->unk4 = (s16) sp8C;
//                 }
//                 sp60 += 3;
//             }
//             var_s6 += 0x32;
//         }
//         var_fp += 0x32;
//     }
//     arg0->unkC = &func_802F1440;
//     arg0->unk10 = 1;
// }