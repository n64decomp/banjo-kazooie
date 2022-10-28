#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8 pad0[0xC];
    f32 unkC[3];
}Struct_core2_72060_0;

extern f32  func_8024C788();
extern int  func_8024DD34(f32, f32, f32);
extern void func_80251B5C(f32, f32, f32);
extern void func_80251F8C(f32);
extern void func_8025208C(f32);
extern void func_80252A38(f32, f32, f32);
extern void mlMtxApply(Mtx *);
extern f32 func_802EC920(BKVertexList *);
extern bool func_8024DB50(f32[3], f32);

extern struct4Cs * D_80369280;
extern s32 D_80369284;
extern BKModelBin * D_80369288;
extern s32 D_8036928C;
extern Gfx D_80369290[];
extern Gfx D_803692B0[];

extern f32 D_80377350;
extern f32 D_80377354;

/* .bss */
f32 D_80381040[3];
f32 D_8038104C;
f32 D_80381050[3];
f32 D_80381060[3];
f32 D_80381070[3];
f32 D_80381080[3];
f32 D_8038108C;
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

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72060/func_802F919C.s")
#else
void func_802F919C(void) {
    f32 temp_f20;
    s32 sp68;
    s32 var_v1;
    s32 sp60;
    struct4Ds *sp5C;
    f32 sp58;
    f32 sp4C[3];
    f32 var_f20;
    s32 sp44;
    struct4Ds *sp40;


    if (D_80369280 != NULL) {
        if (func_802BEF64() != 0) {
            D_80369284 = 0;
            return;
        }
        temp_f20 = time_getDelta();
        sp60 = (func_8023DB5C() & 1) * 2;
        player_getPosition(D_80381040);
        
        D_80369280->unkC[0] = D_80381040[0] - D_80369280->unk0[0];
        D_80369280->unkC[1] = D_80381040[1] - D_80369280->unk0[1];
        D_80369280->unkC[2] = D_80381040[2] - D_80369280->unk0[2];
        D_80369280->unk0[0] = D_80381040[0];
        D_80369280->unk0[1] = D_80381040[1];
        D_80369280->unk0[2] = D_80381040[2];
        D_8038104C = D_80381040[1] - 300.0f;

        for(sp68 = 0; sp68 < D_80369284; sp68++){
            sp5C = D_80369280->unk1C + sp68;
            for(var_v1 = 0; var_v1 < 3; var_v1++){
                sp5C->unk0[var_v1] += sp5C->unkC[var_v1] * temp_f20;
            }
            sp5C->unkC[sp60] += ((randf() * 30.0) - 15.0);
        }

        D_8036928C++;
        if (D_8036928C < D_80369284) {
            if (ml_vec3f_distance(D_80369280[0].unk1C[D_8036928C].unk0, D_80381040) > 1300.0f) {
                func_802F9134(D_8036928C);
            }
        } else {
            D_8036928C = 0;
        }
        if (D_80369280->unk18 == 1) {
            if (D_80369284 < 100) {
                sp40 = D_80369280->unk1C + D_80369284;
                D_80369284++;
                sp58 = randf2(100.0f, 1300.0f);
                sp4C[0] = 0.0f;
                sp4C[1] = randf() * 200.0f + 200.0f;
                sp4C[2] = -sp58;
                if ((D_80369280->unkC[0]*D_80369280->unkC[0] + D_80369280->unkC[1]*D_80369280->unkC[1] + D_80369280->unkC[2]*D_80369280->unkC[2]) < 25.0f) {
                    var_f20 = 100.0f;
                } else {
                    var_f20 = 70.0f;
                }
                ml_vec3f_yaw_rotate_copy(sp4C, sp4C, func_8024C788() + randf2(-var_f20, var_f20));
                sp4C[0] += D_80381040[0];
                sp4C[1] += D_80381040[1];
                sp4C[2] += D_80381040[2];
                if (sp58 < 650.0) {
                    for(sp44 = 0; sp44 < 5 && func_8024DD34(sp4C[0], sp4C[1] - 10.0f, sp4C[2]) ; sp44++){
                        sp4C[1] += 200.0f;
                    }
                }
                sp40->unk0[0] = sp4C[0];
                sp40->unk0[1] = sp4C[1];
                sp40->unk0[2] = sp4C[2];
                sp40->unkC[0] = 0.0f;
                sp40->unkC[1] = randf2(-150.0f, -50.0f);
                sp40->unkC[2] = 0.0f;
            }
        }
    }
}
#endif

void func_802F962C(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    u32 temp_s0_3;
    u32 temp_s0_4;
    void *temp_s0;
    void *temp_s0_2;
    BKVertexList *temp_s3;
    void *temp_s3_2;
    void *temp_s4;
    void *temp_s4_2;
    BKGfxList *gfx_list;
    struct4Ds *phi_s0;
    void *phi_s0_2;

    if ((D_80369280 != NULL) && (D_80369284 != 0)) {
        func_8024C5CC(D_80381050);
        func_8024C764(D_80381060);
        D_80381090 = (s32)D_80369288 + D_80369288->gfx_list_offset_C + sizeof(BKGfxList);
        temp_s3 = (BKVertexList *)((s32)D_80369288 + D_80369288->vtx_list_offset_10);
        D_8038108C = func_802EC920(temp_s3);
        func_80349AD0();
        gSPSegment((*gfx)++, 0x01, osVirtualToPhysical(temp_s3 + 1));
        gSPSegment((*gfx)++, 0x02, osVirtualToPhysical((s32)D_80369288 + D_80369288->texture_list_offset_8 + sizeof(BKTextureList) + sizeof(BKTextureHeader)));
        gSPSetGeometryMode((*gfx)++, G_ZBUFFER);
        gSPDisplayList((*gfx)++, D_80369290);
        gSPSegment((*gfx)++, 0x03, osVirtualToPhysical(&D_803692B0));

        D_80381094 = (BKGeoList *)((s32)D_80369288 + D_80369288->geo_list_offset_4);
        
        for(phi_s0 = D_80369280->unk1C; phi_s0 < D_80369280->unk1C + D_80369284; phi_s0++) {
            if ((func_802F989C(gfx, mtx, phi_s0) == 0) && (phi_s0->unk0[1] < D_8038104C)) {
                func_802F9134(phi_s0 - D_80369280->unk1C);
                phi_s0--;
            }
        }
    }
}

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
