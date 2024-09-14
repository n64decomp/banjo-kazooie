#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include <core2/file.h>

typedef struct{
    f32 unk0[3];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24[3];
    s32 unk30;
}Struct_core2_33310;


void func_802BA3E8(Struct_core2_33310 *arg0, f32 arg1[3]);
void func_802BA414(Struct_core2_33310 *arg0, f32 arg1);
void func_802BA428(Struct_core2_33310 *arg0, f32 arg1);
void func_802BA460(Struct_core2_33310 *arg0, f32 arg1[3]);
void func_802BA494(Struct_core2_33310 *arg0, f32 arg1, f32 arg2);
void func_802BA4BC(Struct_core2_33310 *arg0, f32 arg1, f32 arg2);
void func_802BA510(Struct_core2_33310 *arg0, bool arg1);
void func_802BA530(Struct_core2_33310 *arg0, bool arg1);

/* .code */
void func_802BA2A0(Struct_core2_33310 *arg0, bool arg1, s32 arg2){
    if(arg1){
        arg0->unk30 |= arg2;
    }
    else{
        arg0->unk30 &= ~arg2;
    }
}

bool func_802BA2D0(Struct_core2_33310 *arg0, s32 arg1){
    if(arg0->unk30 & arg1)
        return TRUE;
    return FALSE;
}

Struct_core2_33310 *func_802BA2F4(void){
    Struct_core2_33310 * this;
    f32 sp20[3];

    this = (Struct_core2_33310 *)malloc(sizeof(Struct_core2_33310));
    ml_vec3f_clear(sp20);
    func_802BA460(this, sp20);
    func_802BA3E8(this, sp20);
    func_802BA494(this, 2.84f, 5.68f);
    func_802BA4BC(this, 4.0f, 16.0f);
    func_802BA428(this, 1000.0f);
    func_802BA414(this, 1000.0f);
    func_802BA530(this, FALSE);
    func_802BA510(this, FALSE);
    return this;
}

void func_802BA398(Struct_core2_33310 *arg0){
    free(arg0);
}

void func_802BA3B8(Struct_core2_33310 *arg0, f32 arg1[3]){
    ml_vec3f_add(arg1, arg0->unk0, arg0->unk24);
}

void func_802BA3E8(Struct_core2_33310 *arg0, f32 arg1[3]){
    ml_vec3f_diff_copy(arg0->unk24, arg1, arg0->unk0);
}

f32 func_802BA40C(Struct_core2_33310 *arg0){
    return arg0->unk20;
}

void func_802BA414(Struct_core2_33310 *arg0, f32 arg1){
    arg0->unk20 = arg1;
}

f32 func_802BA420(Struct_core2_33310 *arg0){
    return arg0->unk1C;
}

void func_802BA428(Struct_core2_33310 *arg0, f32 arg1){
    arg0->unk1C = arg1;
}

void func_802BA434(Struct_core2_33310 *arg0, f32 arg1[3]){
    ml_vec3f_copy(arg1, arg0->unk0);
}

void func_802BA460(Struct_core2_33310 *arg0, f32 arg1[3]){
    ml_vec3f_copy(arg0->unk0, arg1);
}

void func_802BA480(Struct_core2_33310 *arg0, f32 *arg1, f32 *arg2){
    *arg1 = arg0->unkC;
    *arg2 = arg0->unk10;
}

void func_802BA494(Struct_core2_33310 *arg0, f32 arg1, f32 arg2){
    arg0->unkC = arg1;
    arg0->unk10 = arg2;
}

void func_802BA4A8(Struct_core2_33310 *arg0, f32 *arg1, f32 *arg2){
    *arg1 = arg0->unk14;
    *arg2 = arg0->unk18;
}

void func_802BA4BC(Struct_core2_33310 *arg0, f32 arg1, f32 arg2){
    arg0->unk14 = arg1;
    arg0->unk18 = arg2;
}

bool func_802BA4D0(Struct_core2_33310 *arg0){
    return func_802BA2D0(arg0, 4);
}

bool func_802BA4F0(Struct_core2_33310 *arg0){
    return func_802BA2D0(arg0, 1);
}

void func_802BA510(Struct_core2_33310 *arg0, bool arg1){
    func_802BA2A0(arg0, arg1, 4);
}

void func_802BA530(Struct_core2_33310 *arg0, bool arg1){
    func_802BA2A0(arg0, arg1, 1);
}

void func_802BA550(File *file_ptr, Struct_core2_33310 *arg1){
    while(!file_isNextByteExpected(file_ptr, 0)){
        if(!file_getNFloats_ifExpected(file_ptr, 1, arg1->unk0, 3)){
            if(file_isNextByteExpected(file_ptr, 2)){
                file_getFloat(file_ptr, &arg1->unkC);
                file_getFloat(file_ptr, &arg1->unk10);
            }
            else if(file_isNextByteExpected(file_ptr, 3)){
                file_getFloat(file_ptr, &arg1->unk14);
                file_getFloat(file_ptr, &arg1->unk18);
            }
            else if(file_isNextByteExpected(file_ptr, 6)){
                file_getFloat(file_ptr, &arg1->unk1C);
                file_getFloat(file_ptr, &arg1->unk20);
            }
            else{
                if(!file_getNFloats_ifExpected(file_ptr, 4, arg1->unk24, 3)){
                    file_getWord_ifExpected(file_ptr, 5, &arg1->unk30);
                }
            }
        }//L802BA654
    }
}
