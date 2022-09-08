#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "animation.h"


extern void func_803458E4(f32[4], f32[4], f32[4], f32);

void func_8033A510(Struct_B1400_1 *arg0) {
    Struct_B1400 *end_ptr;
    Struct_B1400 *i_ptr;

    i_ptr = arg0->unk0;
    end_ptr = i_ptr + arg0->unk4;
    for(i_ptr = i_ptr; i_ptr < end_ptr; i_ptr++){
        i_ptr->unk0[0] = i_ptr->unk0[1] = i_ptr->unk0[2] = 0.0f;
        i_ptr->unk0[3] = 1.0f;
        i_ptr->unk10[0] = i_ptr->unk10[1] = i_ptr->unk10[2] = 1.0f;
        i_ptr->unk1C[0] = i_ptr->unk1C[1] = i_ptr->unk1C[2] = 0.0f;
    }
}

void func_8033A57C(Struct_B1400_1 *arg0, s32 arg1, f32 arg2[4]) {
    func_80345250(arg2, arg0->unk0[arg1].unk0);

}

void func_8033A5B8(Struct_B1400_1 *arg0, s32 arg1, f32 arg2[4], f32 arg3[3], f32 arg4[3]) {
    func_80345250(arg2, arg0->unk0[arg1].unk0);
    arg3[0] = arg0->unk0[arg1].unk10[0];
    arg3[1] = arg0->unk0[arg1].unk10[1];
    arg3[2] = arg0->unk0[arg1].unk10[2];
    arg4[0] = arg0->unk0[arg1].unk1C[0];
    arg4[1] = arg0->unk0[arg1].unk1C[1];
    arg4[2] = arg0->unk0[arg1].unk1C[2];
}

void func_8033A670(Struct_B1400_1 *arg0, s32 arg1, f32 arg2[3]) {
    arg2[0] = arg0->unk0[arg1].unk10[0];
    arg2[1] = arg0->unk0[arg1].unk10[1];
    arg2[2] = arg0->unk0[arg1].unk10[2];
}

void func_8033A6B0(Struct_B1400_1 *arg0, s32 arg1, f32 arg2[3]) {
    arg2[0] = arg0->unk0[arg1].unk1C[0];
    arg2[1] = arg0->unk0[arg1].unk1C[1];
    arg2[2] = arg0->unk0[arg1].unk1C[2];
}

void func_8033A6F0(Struct_B1400_1 *arg0){
    free(arg0);
}

Struct_B1400_1 *func_8033A710(void) {
    Struct_B1400_1 *sp1C;

    sp1C = (Struct_B1400_1 *)malloc(sizeof(Struct_B1400_1) + 0x6D*sizeof(Struct_B1400));
    sp1C->unk0 = (Struct_B1400 *) (sp1C + 1);
    sp1C->unk4 = 0x6D;
    func_8033A510(sp1C);
    return sp1C;
}

//interpolates animation structs?
void func_8033A750(Struct_B1400_1 *arg0, Struct_B1400_1 *arg1, Struct_B1400_1 *arg2, f32 arg3) {
    s32 i;
    s32 cnt;
    Struct_B1400 *start_ptr;
    Struct_B1400 *end_ptr;
    Struct_B1400 *i_ptr;
    Struct_B1400 *j_ptr;
    Struct_B1400 *k_ptr;

    start_ptr = arg0->unk0;
    j_ptr = arg1->unk0;
    k_ptr = arg2->unk0;
    end_ptr = start_ptr + arg0->unk4;
    for(i_ptr = start_ptr; i_ptr < end_ptr; i_ptr++, j_ptr++, k_ptr++){
        if( (j_ptr->unk0[0] == k_ptr->unk0[0])
            && (j_ptr->unk0[1] == k_ptr->unk0[1])
            && (j_ptr->unk0[2] == k_ptr->unk0[2])
            && (j_ptr->unk0[3] == k_ptr->unk0[3])
        ) {
            i_ptr->unk0[0] = j_ptr->unk0[0];
            i_ptr->unk0[1] = j_ptr->unk0[1];
            i_ptr->unk0[2] = j_ptr->unk0[2];
            i_ptr->unk0[3] = j_ptr->unk0[3];
        } else {
            func_803458E4(i_ptr, j_ptr, k_ptr, arg3);
        }
        i_ptr->unk10[0] = j_ptr->unk10[0] + ((k_ptr->unk10[0] - j_ptr->unk10[0]) * arg3);
        i_ptr->unk10[1] = j_ptr->unk10[1] + ((k_ptr->unk10[1] - j_ptr->unk10[1]) * arg3);
        i_ptr->unk10[2] = j_ptr->unk10[2] + ((k_ptr->unk10[2] - j_ptr->unk10[2]) * arg3);
        i_ptr->unk1C[0] = j_ptr->unk1C[0] + ((k_ptr->unk1C[0] - j_ptr->unk1C[0]) * arg3);
        i_ptr->unk1C[1] = j_ptr->unk1C[1] + ((k_ptr->unk1C[1] - j_ptr->unk1C[1]) * arg3);
        i_ptr->unk1C[2] = j_ptr->unk1C[2] + ((k_ptr->unk1C[2] - j_ptr->unk1C[2]) * arg3);
    }
}


void func_8033A8F0(Struct_B1400_1 *arg0, s32 arg1, f32 arg2[4]){
    func_80345250(&arg0->unk0[arg1], arg2);
}

void func_8033A928(Struct_B1400_1 *arg0, s32 arg1, f32 arg2[3]) {
    arg0->unk0[arg1].unk10[0] = arg2[0];
    arg0->unk0[arg1].unk10[1] = arg2[1];
    arg0->unk0[arg1].unk10[2] = arg2[2];
}

void func_8033A968(Struct_B1400_1 *arg0, s32 arg1, f32 arg2[3]) {
    arg0->unk0[arg1].unk1C[0] = arg2[0];
    arg0->unk0[arg1].unk1C[1] = arg2[1];
    arg0->unk0[arg1].unk1C[2] = arg2[2];
}

void func_8033A9A8(Struct_B1400_1 *arg0, s32 arg1, f32 arg2[4]){
    f32 sp18[4];
    func_80345C78(sp18, arg2);
    func_8033A8F0(arg0, arg1, sp18);
}

Struct_B1400_1 * func_8033A9E4(Struct_B1400_1 *arg0){
    Struct_B1400_1 *var_v0;
    var_v0 = (Struct_B1400_1 *)defrag(arg0);
    var_v0->unk0 = (Struct_B1400 *)(var_v0 + 1);
    return var_v0;
}
