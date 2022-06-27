#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern bool func_80244D94(f32[3], f32[3], f32[3], u32, f32);

typedef struct struct_core2_bd100_0_s{
    f32 unk0;
    f32 unk4[3];
    f32 unk10[3];
    f32 unk1C;
    f32 unk20;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 pad27[1];
} Struct_Core2_BD100_0;

/* .h */ 
void func_80344D70(u8 index);

/* .bss */
Struct_Core2_BD100_0 D_803858C0[42];

/* .code */
void func_80344C50(void){
    s32 i;
    for(i = 1; i < 41; i++){
        D_803858C0[i].unk26 = 0;
    }
}

void func_80344C80(void) {
    s32 i;
    for(i = 1; i < 41; i++){
        if(D_803858C0[i].unk26 != 0){
            func_80344D70(i);
        }
    }
}

u8 func_80344CDC(void) {
    s32 i;

    for(i = 1; i < 41; i++){
        if(D_803858C0[i].unk26 == 0){
            D_803858C0[i].unk0 = 0.0f;
            ml_vec3f_clear(D_803858C0[i].unk4);
            ml_vec3f_clear(D_803858C0[i].unk10);
            D_803858C0[i].unk26 = 1U;
            D_803858C0[i].unk25 = 0;
            D_803858C0[i].unk24 = 0;
            D_803858C0[i].unk1C = 0.0f;
            D_803858C0[i].unk20 = 0.0f;
            return i;
        }
    }
    return 0;
}

void func_80344D70(u8 index){
    D_803858C0[index].unk26 = 0;
}

void func_80344D94(u8 index, f32 src[3]){
    ml_vec3f_copy(D_803858C0[index].unk4, src);
}

void func_80344DD4(u8 index, f32 dst[3]){
    ml_vec3f_copy(dst, D_803858C0[index].unk4);
}

void func_80344E18(u8 index, s32 arg1){
    D_803858C0[index].unk25 = arg1;
}

void func_80344E3C(u8 index, f32 src[3]){
    ml_vec3f_copy(D_803858C0[index].unk10, src);
}

void func_80344E7C(u8 index, f32 dst[3]){
    ml_vec3f_copy(dst, D_803858C0[index].unk10);
}

s32 func_80344EC0(u8 index){\
    return D_803858C0[index].unk24;
}

void func_80344EE4(u8 index, f32 arg1, f32 arg2){
    D_803858C0[index].unk1C = arg1;
    D_803858C0[index].unk20 = arg2;
}

f32 func_80344F18(u8 index){
    return D_803858C0[index].unk4[1] - D_803858C0[index].unk0;
}

void func_80344F48(Struct_Core2_BD100_0 *self, f32 arg1[3], f32 arg2[3]) {
    f32 sp24[3];

    self->unk10[1] += self->unk1C * time_getDelta();
    if (self->unk10[1] < (time_getDelta() * self->unk20)) {
        self->unk10[1] = time_getDelta() * self->unk20;
    }
    ml_vec3f_copy(sp24, self->unk10);
    ml_vec3f_scale(sp24, time_getDelta());
    ml_vec3f_add(arg2, arg1, sp24);
}

f32 func_80344FF0(f32 self[3]){
    return -9000.0f;
}

void func_80345000(Struct_Core2_BD100_0 *self, f32 arg1[3]) {
    f32 sp3C[3];
    f32 sp30[3];
    void *temp_a0;

    self->unk24 = FALSE;
    func_80344F48(self, arg1, sp30);
    temp_a0 = self + 0x10;
    if (func_80244D94(arg1, sp30, sp3C, 0x025E0080, 15.0f)) {
        func_80257DB0(self->unk10, self->unk10, sp3C);
        self->unk10[1] = max_f(self->unk10[1], 250.0f);
        self->unk24 = TRUE;
    }
    self->unk0 = func_80344FF0(sp30);
    ml_vec3f_copy(self->unk4, sp30);
    ml_vec3f_copy(arg1, sp30);
}

void func_803450B0(Struct_Core2_BD100_0 *self, f32 arg1[3]) {
    f32 sp34[3];
    f32 sp28[3];
    s32 pad;

    func_80344F48(self, arg1, sp28);
    if (func_80244D94(arg1, sp28, sp34, 0x025E0080, 15.0f)) {
        ml_vec3f_clear(self->unk10);
    }
    ml_vec3f_copy(self->unk4, sp28);
    ml_vec3f_copy(arg1, sp28);
    self->unk0 = func_80344FF0(sp28);
}

void func_80345138(Struct_Core2_BD100_0 *self, f32 arg1[3]) {
    f32 sp1C[3];

    ml_vec3f_copy(sp1C, self->unk10);
    ml_vec3f_scale(sp1C, time_getDelta());
    arg1[0] += sp1C[0];
    arg1[1] += sp1C[1];
    arg1[2] += sp1C[2];
}

void func_803451B0(u8 index, f32 arg1[3]) {

    switch(D_803858C0[index].unk25){
        case 1: //L80345200
            func_803450B0(&D_803858C0[index], arg1);
            break;

        case 2: //L80345210
            func_80345138(&D_803858C0[index], arg1);
            break;

        case 4: //L80345220
            func_80345000(&D_803858C0[index], arg1);
            break;

        case 5: //L80345230
            func_80344F48(&D_803858C0[index], arg1, arg1);
            break;

        case 3: //L8034523C
            break;
    }
}
