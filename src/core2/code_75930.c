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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75930/func_802FC918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75930/func_802FC95C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75930/func_802FCA30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75930/func_802FCA54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75930/func_802FCA78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75930/func_802FCA8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75930/func_802FCAE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75930/func_802FCAF4.s")

void func_802FCD4C(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75930/func_802FCD54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75930/func_802FCD98.s")
