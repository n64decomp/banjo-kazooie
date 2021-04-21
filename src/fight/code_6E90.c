#include <ultra64.h>
#include "functions.h"
#include "variables.h"
void func_8034DE60(s32, f32, f32, f32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_6E90/func_8038D280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_6E90/func_8038D2EC.s")

void func_8038D3DC(Actor* this, s32 arg1, f32 arg2, f32 arg3, f32 arg4){
    void * tmp;
    
    if(tmp = func_8034C2C4(this->marker, arg1)){
        func_8034DE60(tmp, arg2, arg3, arg4, 1);
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_6E90/func_8038D428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_6E90/func_8038D510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_6E90/func_8038D568.s")
