#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern bool func_8028F170(f32, f32);
extern void func_8024C5CC(f32[3]);

typedef struct {
    f32 unk0;
    s32 unk4[4];
    f32 unk14;
}Struct_core2_C97F0_2;

typedef struct {
    u8 unk0;
    u8 pad1[3];
    Struct_core2_C97F0_2 unk4[15];
}Struct_core2_C97F0_1;

typedef struct {
    s16 unk0;
    u8 pad2[0x2];
    f32 unk4[3];
    u8 unk10;
    u8 pad11[0x3];
}Struct_core2_C97F0_0;

/* .data */
extern Struct_core2_C97F0_1 D_803720B0[];
extern Struct_core2_C97F0_0 D_803724F4[];
extern s32 D_803725A8[4];

/* .rodata */
extern f64 D_80379340;
extern f64 D_80379348;

/* .bss */
extern struct{
    Struct_core2_C97F0_1 *unk0;
    Struct_core2_C97F0_0 *unk4;
    void *unk8;
} D_80386170;
extern struct {
    u8 unk0;
    u8 unk1;
}D_8038617C;

/* .code */
Struct_core2_C97F0_1 *func_80350780(s32 arg0) {
    Struct_core2_C97F0_1 *i_ptr;

    for(i_ptr = D_803720B0; i_ptr->unk0 != 0; i_ptr++){
        if(arg0 == i_ptr->unk0){
            return i_ptr;
        }
    }
    return i_ptr;
}

Struct_core2_C97F0_0 *func_803507CC(enum map_e map_id) {
    Struct_core2_C97F0_0 *i_ptr;

    for(i_ptr = D_803724F4; i_ptr->unk0 != 0; i_ptr++){
        if(map_id == i_ptr->unk0){
            return i_ptr;
        }
    }
    return NULL;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C97F0/func_80350818.s")
#else
void func_80350818(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    f32 spDC[3];
    f32 spD0[3];
    f32 spC4[3];
    f32 spB8[3];
    Struct_core2_C97F0_0 *temp_s1;
    Struct_core2_C97F0_1 *temp_s2;
    f32 var_f22;
    s32 i;
    f32 sp9C[3];
    f32 sp90[3];
    s32 sp80[4];

    if(D_80386170.unk8);
    temp_s1 = D_80386170.unk4;
    temp_s2 = D_80386170.unk0;
    if (( temp_s1 != NULL) && D_8038617C.unk0) {
        func_8024C5CC(spDC);
        func_8024C764(spD0);
        sp9C[0] = temp_s1->unk4[0];
        sp9C[1] = temp_s1->unk4[1];
        sp9C[2] = temp_s1->unk4[2];
        ml_vec3f_yaw_rotate_copy(sp9C, sp9C, -spD0[1]);
        ml_vec3f_pitch_rotate_copy(sp9C, sp9C, -spD0[0]);
        if (!(((1.2 * (f32)D_80276588) / 2) < sp9C[0]) && !(sp9C[0] < ((-1.2 * (f32)D_80276588) / 2))) {
            if (!(((1.2 * (f32)D_8027658C) / 2) < sp9C[1]) && !(sp9C[1] < ((-1.2 * (f32)D_8027658C) / 2))) {
                sp90[0] = -sp9C[0];
                sp90[1] = -sp9C[1];
                sp90[2] =  sp9C[2];
                ml_vec3f_pitch_rotate_copy(sp90, sp90, spD0[0]);
                ml_vec3f_yaw_rotate_copy(sp90, sp90, spD0[1]);
                var_f22 = 1.0f - (((sp9C[0] * sp9C[0]) + (sp9C[1] * sp9C[1])) / ((f32)D_8027658C * (f32)D_8027658C));
                if (var_f22 < 0.0f) {
                    var_f22 = 0.0f;
                }
                if (var_f22 > 1.0f) {
                    var_f22 = 1.0f;
                }
                spC4[0] = sp90[0] - temp_s1->unk4[0];
                spC4[1] = sp90[1] - temp_s1->unk4[1];
                spC4[2] = sp90[2] - temp_s1->unk4[2];
                for(i = 0; temp_s2->unk4[i].unk0 != 0.0f; i++){
                    spB8[0] = (spDC[0] + temp_s1->unk4[0]) + (temp_s2->unk4[i].unk0 * spC4[0]);
                    spB8[1] = (spDC[1] + temp_s1->unk4[1]) + (temp_s2->unk4[i].unk0 * spC4[1]);
                    spB8[2] = (spDC[2] + temp_s1->unk4[2]) + (temp_s2->unk4[i].unk0 * spC4[2]);
                    sp80[0] = temp_s2->unk4[i].unk4[0];
                    sp80[1] = temp_s2->unk4[i].unk4[1];
                    sp80[2] = temp_s2->unk4[i].unk4[2];
                    sp80[3] = temp_s2->unk4[i].unk4[3];
                    sp80[3] *= var_f22;
                    func_8033A334(sp80, D_803725A8);
                    func_803391A4(gfx, mtx, spB8, spD0, temp_s2->unk4[i].unk14*0.25, NULL, D_80386170.unk8);
                }
            }
        }
    }
}
#endif

void func_80350BC8(void){
    if(D_80386170.unk4 != NULL){
        assetcache_release(D_80386170.unk8);
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C97F0/func_80350BFC.s")
#else
void func_80350BFC(void) {
    D_80386170.unk4 = func_803507CC(map_get());
    if (D_80386170.unk4 != NULL) {
        D_80386170.unk0 = func_80350780(D_80386170.unk4->unk10);
        D_80386170.unk8 = assetcache_get(0x882);
        ml_vec3f_set_length(D_80386170.unk4->unk4, (2.0f*D_80276588) / 2.0f);
        D_8038617C.unk0 = 1;
        D_8038617C.unk1 = 0;
    }
}
#endif


void func_80350CA4(void) {
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];
    s32 var_v0;

    if (D_80386170.unk4 != NULL) {
        func_8024C5CC(sp54);
        sp48[0] = D_80386170.unk4->unk4[0];
        sp48[1] = D_80386170.unk4->unk4[1];
        sp48[2] = D_80386170.unk4->unk4[2];
        ml_vec3f_set_length(sp48, 1000.0f);
        sp30[0] = sp54[0] + (sp48[0] * D_8038617C.unk1);
        sp30[1] = sp54[1] + (sp48[1] * D_8038617C.unk1);
        sp30[2] = sp54[2] + (sp48[2] * D_8038617C.unk1);
        sp24[0] = sp30[0] + sp48[0];
        sp24[1] = sp30[1] + sp48[1];
        sp24[2] = sp30[2] + sp48[2];
        if (func_8028F170(sp48[1], sp48[2])) {
            var_v0 = func_80320B98(&sp30, &sp24, &sp3C, 0x01000000);
        } else {
            var_v0 = func_80309B48(&sp30, &sp24, &sp3C, 0x01000000);
        }
        if (var_v0 != 0) {
            D_8038617C.unk0 = 0;
            D_8038617C.unk1 = 0;
        } else {
            D_8038617C.unk1++;
            if (D_8038617C.unk1 >= 0xB) {
                D_8038617C.unk0 = 1;
                D_8038617C.unk1 = 0;
            }
        }
    }
}
