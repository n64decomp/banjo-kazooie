#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    s16 unk0;
    s16 unk2;
    f32 unk4;
}Struct_core2_C2C20_1;

typedef struct {
    Struct_core2_C2C20_1 unk0[4];
    f32 unk20[4];
}Struct_core2_C2C20_0;

/* .bss */
array(Struct_core2_C2C20_0) *D_803860C0;

/* .code */
bool func_80349BB0(s32 arg0, s32 arg1, s32 *arg2) {
    Struct_core2_C2C20_0 * temp_v0;

    temp_v0 = (Struct_core2_C2C20_0 *)array_at(D_803860C0, arg0);
    if (temp_v0->unk0[arg1].unk0 != 0) {
        *arg2 = (s32)temp_v0->unk20[arg1] * temp_v0->unk0[arg1].unk0;
        return TRUE;
    }
    return FALSE;
}

s32 func_80349C3C(void){
    Struct_core2_C2C20_0 *phi_v0;
    s32 sp20;
    s32 i;

    phi_v0 = (Struct_core2_C2C20_0 *)func_802EDAA4(&D_803860C0, &sp20);
    for(i = 0; i < 4; i++){
        phi_v0->unk0[i].unk0 = 0;
        phi_v0->unk20[i] = 0.0f;
    }
    return sp20;
}

void func_80349C8C(void){
    array_free(D_803860C0);
}

void func_80349CB0(void){
    D_803860C0 = (array(Struct_core2_C2C20_0) *)array_new(sizeof(Struct_core2_C2C20_0), 2);
}

void func_80349CD8(s32 arg0){
    func_802EDCDC(D_803860C0, arg0);
}

void func_80349D00(s32 arg0, BKModelUnk2C *arg1){
    Struct_core2_C2C20_0 * sp1C;
    s32 i;


    sp1C = (Struct_core2_C2C20_0 *) array_at(D_803860C0, arg0);
    memcpy(sp1C, arg1, 0x20);
    for(i = 0; i < 4; i++){
        sp1C->unk20[i] = 0.0f;
    }
}

void func_80349D60(void) {
    f32 temp_f20;
    s32 phi_s1;
    Struct_core2_C2C20_0 *phi_a0;
    s32 i;

    temp_f20 = time_getDelta();
    for(phi_s1 = 1; phi_s1 <array_size(D_803860C0); phi_s1++){
        if (func_802EDC18(D_803860C0, phi_s1)) {
            phi_a0 = (Struct_core2_C2C20_0 *)array_at(D_803860C0, phi_s1);
            for(i = 0; i < 4; i++){
                if (phi_a0->unk0[i].unk0 != 0) {
                    phi_a0->unk20[i] += (phi_a0->unk0[i].unk4 * temp_f20);
                    if ((s32) phi_a0->unk20[i] >= phi_a0->unk0[i].unk2) {
                        phi_a0->unk20[i] -= phi_a0->unk0[i].unk2;
                    }
                }
            }
        }
    }
}
