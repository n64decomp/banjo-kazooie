#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8 pad0[0xC];
    f32 unkC[3];
}Struct_core2_72060_0;

extern void func_80251B5C(f32, f32, f32);
extern void func_80251F8C(f32);
extern void func_8025208C(f32);
extern void func_80252A38(f32, f32, f32);

extern struct4Cs * D_80369280;
extern s32 D_80369284;
extern void * D_80369288;
extern s32 D_8036928C;
extern Gfx D_80369290[];

extern f32 D_80377350;
extern f32 D_80377354;

/* .bss */
f32 D_80381040[3];
f32 D_8038104C;
f32 D_80381050[3];
f32 D_80381060[3];
f32 D_80381070[3];
f32 D_80381080[3];
s32 D_8038108C;
Gfx *D_80381090;
Struct_core2_72060_0 *D_80381094;

/* .code */
void func_802F8FF0(void){
    D_80369284 = 0;
}

void func_802F8FFC(void){
    if(D_80369280){
        free(D_80369280->unk1C);
        func_8033BD20(&D_80369288);
        free(D_80369280);
        D_80369280 = NULL;
        D_80369284 = 0;
    }
}

void func_802F9054(void){
    func_802F8FFC();
    D_80369280 = (struct4Cs *) malloc(sizeof(struct4Cs));
    D_80369280->unk0[0] = D_80369280->unk0[1] = D_80369280->unk0[2] = 0.0f;
    D_80369280->unkC[0] = D_80369280->unkC[1] = D_80369280->unkC[2] = 0.0f;
    D_8036928C = 0;
    D_80369280->unk1C = malloc(100*sizeof(struct4Ds));
    D_80369280->unk18 = 0;
    D_80369288 = assetcache_get(0x8a1); //2D_light
}

void func_802F90F4(void){
    if(D_80369280)
        D_80369280->unk18 = 1;
}

void func_802F9114(void){
    if(D_80369280)
        D_80369280->unk18 = 2;
}

void func_802F9134(s32 gfx){
    D_80369284 = D_80369284 - 1;
    if(gfx < D_80369284){
        func_80254630(D_80369280->unk1C + gfx, D_80369280->unk1C + D_80369284, sizeof(struct4Ds));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72060/func_802F919C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72060/func_802F962C.s")
// void func_802F962C(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
//     u32 temp_s0_3;
//     u32 temp_s0_4;
//     void *temp_s0;
//     void *temp_s0_2;
//     void *temp_s3;
//     void *temp_s3_2;
//     void *temp_s4;
//     void *temp_s4_2;
//     void *temp_v1;
//     void *temp_v1_2;
//     void *temp_v1_3;
//     void *phi_s0;
//     void *phi_s0_2;

//     if ((D_80369280 != NULL) && (D_80369284 != 0)) {
//         func_8024C5CC(D_80381050);
//         func_8024C764(D_80381060);
//         temp_v1 = D_80369288;
//         D_80381090 = temp_v1 + temp_v1->unkC + 8;
//         temp_s3 = temp_v1 + temp_v1->unk10;
//         D_8038108C = func_802EC920(temp_s3);
//         func_80349AD0();
//         gSPSegment((*gfx)++, 0x01, osVirtualToPhysical(temp_s3 + 0x18));
//         gSPSegment((*gfx)++, 0x02, osVirtualToPhysical(temp_v1_2 + temp_v1_2->unk8 + 0x18));
//         gSPSetGeometryMode((*gfx)++, G_ZBUFFER);
//         gSPDisplayList((*gfx)++, D_80369290);
//         gSPSegment((*gfx)++, 0x03, osVirtualToPhysical(&D_803692B0));

//         temp_v1_3 = D_80369288;
//         D_80381094 = temp_v1_3 + temp_v1_3->unk4;
//         temp_s0_3 = D_80369280->unk1C;
//         phi_s0 = (void *) temp_s0_3;
//         if (temp_s0_3 < (u32) (temp_s0_3 + (D_80369284 * 0x18))) {
//             do {
//                 phi_s0_2 = phi_s0;
//                 if ((func_802F989C(gfx, mtx, phi_s0) == 0) && (phi_s0->unk4 < D_8038104C)) {
//                     func_802F9134((s32) (phi_s0 - D_80369280->unk1C) / 24);
//                     phi_s0_2 = phi_s0 - 0x18;
//                 }
//                 temp_s0_4 = phi_s0_2 + 0x18;
//                 phi_s0 = (void *) temp_s0_4;
//             } while (temp_s0_4 < (u32) (D_80369280->unk1C + (D_80369284 * 0x18)));
//         }
//     }
// }

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72060/func_802F989C.s")
#else
bool func_802F989C(Gfx **gfx, Mtx **mtx, f32 arg2[3]) {

    D_80381070[0] = arg2[0] - D_80381050[0];\
    D_80381070[1] = arg2[1] - D_80381050[1];\
    D_80381070[2] = arg2[2] - D_80381050[2];
    if( ((-17000.0f < D_80381070[0]) &&(D_80381070[0] < 17000.0f)) 
        && (arg2[1] > -200.0f)
        && ((-17000.0f < D_80381070[2]) && (D_80381070[2] < 17000.0f))
        && func_8024DB50(arg2, D_8038108C)
    ) {
        func_80251B5C(D_80381070[0], D_80381070[1], D_80381070[2]);
        mlMtxApply(*mtx);
        func_80252434(&D_80381080, D_80381094->unkC);
        func_80251B5C(D_80381080[0], D_80381080[1], D_80381080[2]);
        func_8025208C(D_80381060[1]);
        func_80251F8C(D_80381060[0]);
        func_80252A38(-(D_80381094->unkC[0]), -(D_80381094->unkC[1]), -(D_80381094->unkC[2]));
        mlMtxApply(*mtx);
        gSPMatrix((*gfx)++, (*mtx)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList((*gfx)++, osVirtualToPhysical(D_80381090));
        gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);
        return TRUE;
    }
    return FALSE;
}
#endif
