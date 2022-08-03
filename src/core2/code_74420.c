#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_80369824;

/* .bss */
struct8s * D_80381530[4];

f32 func_802FB3B0(struct8s* arg0){
    int i;
    f32 f2;
    f2 = 0.0f;
    for(i = 0; i < D_80369824; i++){
        if(arg0 == (D_80381530[i])){
            return f2;
        }
        f2 += 32.5;
    }
    return 0.0f;
}

void func_802FB414(void){
    int i = 0;
    D_80369824--;
    while(i < D_80369824){
        D_80381530[i] = D_80381530[i+1];
        i++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FB458.s")

void func_802FB56C(s32 arg0, struct8s *arg1){
    func_802FB458(arg1);
}

void func_802FB590(s32 arg0, struct8s *arg1){
    func_802FB414();
}

void func_802FB5B4(s32 arg0, struct8s *arg1){
    arg1->unk18 = 0;
    arg1->unk1C = 0.0f;
}

void func_802FB5C8(s32 arg0, struct8s *arg1){
    s32 tmp;
    struct8s *ptr = D_80381530[0];
    if(D_80369824){
        arg1->unkC = func_802FB3B0(arg1) + ptr->unk1C;
    }
}

void func_802FB61C(s32 arg0, struct8s *arg1){
    D_80369824 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FB630.s")
