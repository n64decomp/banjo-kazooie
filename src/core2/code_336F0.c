#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0[3];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C[3];
    s32 unk28;
} Struct_core2_336F0;

void func_802BA7B8(Struct_core2_336F0 *arg0, f32 arg1[3]);
void func_802BA808(Struct_core2_336F0 *arg0, f32 arg1[3]);
void func_802BA840(Struct_core2_336F0 *arg0, f32 arg1, f32 arg2);
void func_802BA868(Struct_core2_336F0 *arg0, f32 arg1, f32 arg2);
void func_802BA8DC(Struct_core2_336F0 *arg0, s32 arg1);
void func_802BA8FC(Struct_core2_336F0 *arg0, s32 arg1);
void func_802BA91C(Struct_core2_336F0 *arg0, s32 arg1);

void func_802BA680(Struct_core2_336F0 *arg0, s32 arg1, s32 arg2){
    if(arg1){
        arg0->unk28 |= arg2;
    }else{
        arg0->unk28 &= ~arg2;
    }
}

bool func_802BA6B0(Struct_core2_336F0 *arg0, s32 arg1){
    if (arg0->unk28 & arg1) 
        return TRUE;
    return FALSE;
}

Struct_core2_336F0 *func_802BA6D4(void){
    Struct_core2_336F0 *this;
    f32 sp20[3];

    this = (Struct_core2_336F0 *)malloc(sizeof(Struct_core2_336F0));
    ml_vec3f_clear(sp20);
    func_802BA7B8(this, sp20);
    func_802BA808(this, sp20);
    func_802BA840(this, 0.7f, 2.33f);
    func_802BA868(this, 4.0f, 16.0f);
    func_802BA8DC(this, 0);
    func_802BA91C(this, 1);
    func_802BA8FC(this, 0);
    return this;
}

void func_802BA76C(Struct_core2_336F0 *arg0){
    free(arg0);
}

void func_802BA78C(Struct_core2_336F0 *arg0, f32 arg1[3]){
    ml_vec3f_copy(arg1, arg0->unk0);
}

void func_802BA7B8(Struct_core2_336F0 *arg0, f32 arg1[3]){
    ml_vec3f_copy(arg0->unk0, arg1);
}

void func_802BA7D8(Struct_core2_336F0 *arg0, f32 arg1[3]){
    ml_vec3f_add(arg1, arg0->unk0, arg0->unk1C);
}

void func_802BA808(Struct_core2_336F0 *arg0, f32 arg1[3]){
    ml_vec3f_diff_copy(arg0->unk1C, arg1, arg0->unk0);
}

void func_802BA82C(Struct_core2_336F0 *arg0, f32 *arg1, f32 *arg2){
    *arg1 = arg0->unkC;
    *arg2 = arg0->unk10;
}

void func_802BA840(Struct_core2_336F0 *arg0, f32 arg1, f32 arg2){
    arg0->unkC = arg1;
    arg0->unk10 = arg2;
}

void func_802BA854(Struct_core2_336F0 *arg0, f32 *arg1, f32 *arg2){
    *arg1 = arg0->unk14;
    *arg2 = arg0->unk18;
}

void func_802BA868(Struct_core2_336F0 *arg0, f32 arg1, f32 arg2){
    arg0->unk14 = arg1;
    arg0->unk18 = arg2;
}

bool func_802BA87C(Struct_core2_336F0 *arg0){
    return func_802BA6B0(arg0, 1);
}

bool func_802BA89C(Struct_core2_336F0 *arg0){
    return func_802BA6B0(arg0, 4);
}

bool func_802BA8BC(Struct_core2_336F0 *arg0){
    return func_802BA6B0(arg0, 2);
}

void func_802BA8DC(Struct_core2_336F0 *arg0, s32 arg1){
    func_802BA680(arg0, arg1, 1);
}

void func_802BA8FC(Struct_core2_336F0 *arg0, s32 arg1){
    func_802BA680(arg0, arg1, 4);
}

void func_802BA91C(Struct_core2_336F0 *arg0, s32 arg1){
    func_802BA680(arg0, arg1, 2);
}

void func_802BA93C(Struct61s *file_ptr, Struct_core2_336F0 *arg1){
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
            else if(!file_getNFloats_ifExpected(file_ptr, 4, arg1->unk1C, 3)){
                file_getWord_ifExpected(file_ptr, 5, &arg1->unk28);
            }
        }//L802BAA0C
    }
}
