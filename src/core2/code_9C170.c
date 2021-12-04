#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_80378DD8;
extern f32 D_80378DDC;
extern f32 D_80378DE0;

extern f32 func_80256280(f32 [3], f32 [3]);
extern void func_80341180(f32, s32, s32, f32 *, f32 [3]);

/* .code */
void func_80323100(void){
    func_8024AED8();
}

void func_80323120(void){
    func_8024AE74();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_80323140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_80323170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_80323190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_803231E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_8032320C.s")

void func_80323230(void){}

void func_80323238(void){}

void func_80323240(struct56s *arg0, f32 arg1, f32 arg2[3]){
    if(arg1 < 0.0f)
        arg1 = 0.0f;
    else if(1.0f < arg1)
        arg1 = 1.0f;

    func_80341180(arg1, arg0->unk0, 3, &arg0->unk8, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_803232AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_803233F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_803234FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_80323540.s")

f32 func_8032358C(struct56s *arg0, f32[3]);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_8032358C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_803237E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_80323A48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_80323F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_80323FDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_80324078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_803240E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_8032417C.s")

f32 func_8032429C(struct56s *this, f32 arg1[3], f32 min, f32 max, f32 step){
    f32 sp74[3];
    f32 sp68[3];
    f32 f22;
    f32 f28;
    f32 f20;
    f32 f24;
    f32 f2;
    
    min = max_f(0.0f, min);
    max = min_f(1.0f, max);
    f24 = D_80378DD8;
    f28 = min;
    f20 = min;
    do{
        func_80323240(this, f20, sp68);
        ml_vec3f_diff_copy(sp74, arg1, sp68);
        f2 = sp74[0]*sp74[0] + sp74[1]*sp74[1] + sp74[2]*sp74[2];
        if(f2 < f24){
            f24 = f2;
            f28 = f20;
        }

        if(f20 == max)
            break;
        else{
            f20 += step;
            if(f20 > max)
                f20 = max;
        }
    }while(1);
    return f28;
}

#ifndef NONMATCHING //needs .rodata defined ?
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_803243D0.s")
#else
f32 func_803243D0(struct56s *arg0, f32 arg1[3]){
    f32 sp64[3];
    f32 sp58[3];
    f32 tmp_f0;
    f32 tmp_f20;
    tmp_f0 = func_8032358C(arg0, arg1);
    if(0.0f <= tmp_f0){
        return tmp_f0;
    }
    else{
        tmp_f20 = D_80378DE0;
        tmp_f0 = func_8032429C(arg0, arg1, 0.0f, 1.0f, D_80378DDC);
        tmp_f0 = func_8032429C(arg0, arg1, tmp_f0 - tmp_f20, tmp_f0 + tmp_f20, tmp_f20 = (tmp_f20/10.0)*2);
        tmp_f0 = func_8032429C(arg0, arg1, tmp_f0 - tmp_f20, tmp_f0 + tmp_f20, tmp_f20 = (tmp_f20/10.0)*2);
        tmp_f0 = func_8032429C(arg0, arg1, tmp_f0 - tmp_f20, tmp_f0 + tmp_f20, tmp_f20 = (tmp_f20/10.0)*2);
        tmp_f0 = func_8032429C(arg0, arg1, tmp_f0 - tmp_f20, tmp_f0 + tmp_f20, tmp_f20 = (tmp_f20/10.0)*2);
        tmp_f0 = func_8032429C(arg0, arg1, tmp_f0 - tmp_f20, tmp_f0 + tmp_f20, tmp_f20 = (tmp_f20/10.0)*2);
        tmp_f20 = tmp_f0;
        func_80323240(arg0, tmp_f0, sp64);
        func_80323240(arg0, 1.0f, sp58);
        if(func_80256280(arg1, sp64) < func_80256280(arg1, sp58)){
            return tmp_f20;
        }
        return 1.0f;
    }
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_803245D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_80324624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9C170/func_803246B4.s")
