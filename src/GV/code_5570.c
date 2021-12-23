#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8025AE50(s32, f32);


void func_8038BEA0(Actor *this);

/* .data */
ActorAnimationInfo D_80391120[] ={
    {0x00, 0.0f},
    {0xC5, 8000000.0f},
    {0xC5, 1.6f},
    {0xC7, 1.8f},
    {0xC6, 0.55f},
    {0xC8, 0.8f},
    {0xC7, 1.8f}
};

ActorInfo D_80391158 = { 0xA6, 0x118, 0x371, 
    0x1, D_80391120, 
    func_8038BEA0, func_80326224, func_80325888, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

s32 D_8039117C[3] = {160, 100, 0};


/* .bss */
extern s32 D_80391A80;

/* .code */
void func_8038B960(void){
    func_8025AE50(5000, 3.19f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_5570/func_8038B988.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_5570/func_8038BA08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_5570/func_8038BAA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_5570/func_8038BB24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_5570/func_8038BB6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_5570/func_8038BBFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_5570/func_8038BC7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_5570/func_8038BD8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_5570/func_8038BEA0.s")

s32 func_8038C5BC(void){
    return D_80391A80;
}
