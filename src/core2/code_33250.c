#include <ultra64.h>
#include "functions.h"
#include "variables.h"

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
}Struct_core2_33250_1;



void func_802BA23C(s32 *arg0, s32 arg1);

/* .code */
s32 * func_802BA1E0(void){
    s32 * sp1C = malloc(4);
    func_802BA23C(sp1C, 1);
    return sp1C;
}

void func_802BA214(s32 *arg0){
    free(arg0);
}

s32 func_802BA234(s32 *arg0){
    return *arg0;
}

void func_802BA23C(s32 *arg0, s32 arg1){
    *arg0 = arg1;
}

void func_802BA244(Struct61s *file_ptr, s32 *arg1){
    while(!func_8034AF98(file_ptr, 0)){
        func_8034B150(file_ptr, 1, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA2A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA2D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA2F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA3B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA3E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA40C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA414.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA4A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA4BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA4D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA4F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA530.s")

void func_802BA550(Struct61s *file_ptr, Struct_core2_33250_1 *arg1){
    while(!func_8034AF98(file_ptr, 0)){
        if(!func_8034B108(file_ptr, 1, arg1->unk0, 3)){
            if(func_8034AF98(file_ptr, 2)){
                func_8034AD20(file_ptr, &arg1->unkC);
                func_8034AD20(file_ptr, &arg1->unk10);
            }
            else if(func_8034AF98(file_ptr, 3)){
                func_8034AD20(file_ptr, &arg1->unk14);
                func_8034AD20(file_ptr, &arg1->unk18);
            }
            else if(func_8034AF98(file_ptr, 6)){
                func_8034AD20(file_ptr, &arg1->unk1C);
                func_8034AD20(file_ptr, &arg1->unk20);
            }
            else{
                if(!func_8034B108(file_ptr, 4, arg1->unk24, 3)){
                    func_8034B150(file_ptr, 5, &arg1->unk30);
                }
            }
        }//L802BA654
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA680.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA6B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA6D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA76C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA78C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA7B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA7D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA82C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA87C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA8BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA8DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA8FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_33250/func_802BA91C.s")

typedef struct {
    f32 unk0[3];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C[3];
    s32 unk28;
} Struct_core2_33250_2;

void func_802BA93C(Struct61s *file_ptr, Struct_core2_33250_2 *arg1){
    while(!func_8034AF98(file_ptr, 0)){
        if(!func_8034B108(file_ptr, 1, arg1->unk0, 3)){
            if(func_8034AF98(file_ptr, 2)){
                func_8034AD20(file_ptr, &arg1->unkC);
                func_8034AD20(file_ptr, &arg1->unk10);
            }
            else if(func_8034AF98(file_ptr, 3)){
                func_8034AD20(file_ptr, &arg1->unk14);
                func_8034AD20(file_ptr, &arg1->unk18);
            }
            else if(!func_8034B108(file_ptr, 4, arg1->unk1C, 3)){
                func_8034B150(file_ptr, 5, &arg1->unk28);
            }
        }//L802BAA0C
    }
}
