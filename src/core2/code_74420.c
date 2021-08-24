#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_80369824;

extern struct8s * D_80381530[];

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

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FB414.s")
#else
void func_802FB414(void){
    int i;
    D_80369824--;
    for(i = 0; i < D_80369824; i++){
        D_80381530[i] = D_80381530[i+1];
    }
}
#endif

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

/* ???BREAK??? */

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FB8A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FB8F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FB93C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FBA54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FBA78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FBA9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FBAB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FBB04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FBB18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FBBC0.s")

void func_802FBDFC(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FBE04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FBE48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FBE60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FBEB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FBEFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FC014.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FC038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FC05C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FC070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FC0C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FC0D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FC390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74420/func_802FC3C4.s")
