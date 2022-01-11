#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80321338(void);
void func_80321340(void);

extern u8 D_803832E0[3];


void func_803212B0(void){
    func_80321338();
    func_80321340();
}

u8 *func_803212D8(void){
    return D_803832E0;
}

int func_803212E4(enum honeycomb_e indx){
    if( indx <= 0 || indx >= 0x19)
        return 0;
    return (D_803832E0[(indx - 1) / 8] & (1 << (indx & 7))) != 0;
}

void func_80321338(void){}

void func_80321340(void){
    s32 i;
    for(i = 0; i < 0x3; i++){
        D_803832E0[i] = 0;
    }
}

void func_80321364(enum honeycomb_e indx,  s32 val){
    if( 0 < indx && indx < 0x19){
        if(val)
            D_803832E0[(indx - 1) / 8] |= (1 << (indx & 7));
        else
            D_803832E0[(indx - 1) / 8] &= ~(1 << (indx & 7));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9A320/func_803213F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9A320/func_8032149C.s")

void func_803214EC(s32 *size, u8 **addr){
    *size = 0x3;
    *addr = &D_803832E0;
}
