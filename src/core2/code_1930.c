#include <ultra64.h>
#include "functions.h"
#include "variables.h"


int func_802878E8(AnimCtrl *, f32);

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_802888C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_8028894C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_802889C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_802889F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288AE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288B14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288B34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288B60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288B98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288C7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288C9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288D40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288DCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288E18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288E68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288EF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288F38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288F78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288FA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80288FD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80289008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80289048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_80289090.s")

void func_802890D0(VLA** arg0){
    vla_free(*arg0);
    free(arg0);
}

vector(struct2s) **func_802890FC(void){
    vector(struct2s) **ptr = (vector(struct2s) **)malloc(sizeof(vector(struct2s) **));
    *ptr = vla_new(sizeof(struct2s), 2);
    func_80288C7C(ptr);
    return ptr;
}


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_1930/func_8028913C.s")

void func_8028914C(vector(struct2s) **arg0, AnimCtrl *arg1){
    struct2s *iPtr;
    for(iPtr = vla_getBegin(*arg0); iPtr != (struct2s*)vla_getEnd(*arg0); iPtr++){
        if(func_802878E8(arg1, iPtr->unk0))
            func_80288B98(arg0, iPtr);
    }
}
