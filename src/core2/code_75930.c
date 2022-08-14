#include <ultra64.h>
#include "functions.h"
#include "variables.h"


/* .data */
extern s32 D_803698E4;

/* .bss */
struct8s *D_80381580[4];

/* .code */
f32 func_802FC8C0(struct8s * arg0) {
    f32 var_f2;
    s32 var_v0;

    var_f2 = 0.0f;
    for(var_v0 = 0; var_v0 < D_803698E4; var_v0++){
        if (arg0 == D_80381580[var_v0]) {
            return var_f2;
        }
        var_f2 += 48.0f;
    }
    return 0.0f;
}

void func_802FC918(void){
    s32 i = 0;

    D_803698E4--;
    while(i < D_803698E4){
        D_80381580[i] = D_80381580[i + 1];
        i++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75930/func_802FC95C.s")

void func_802FCA30(s32 arg0, struct8s *arg1){
    func_802FC95C(arg1);
}

void func_802FCA54(s32 arg0, struct8s *arg1){
    func_802FC918();
}

void func_802FCA78(s32 arg0, struct8s *arg1){
    arg1->unk18 = 0;
    arg1->unk1C = 0.0f;
}

void func_802FCA8C(s32 arg0, struct8s *arg1){
    s32 sp1C;
    struct8s *var_v0 = D_80381580[0];

    if(D_803698E4 != 0){
        arg1->unkC = func_802FC8C0(arg1) + var_v0->unk1C;
    }
}

void func_802FCAE0(s32 arg0, struct8s *arg1){
    D_803698E4 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75930/func_802FCAF4.s")

void func_802FCD4C(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75930/func_802FCD54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75930/func_802FCD98.s")
