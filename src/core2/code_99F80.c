#include <ultra64.h>
#include "functions.h"
#include "variables.h"

u32 func_80320FE0(s32);
void func_80321034(void);
void func_8032103C(void);
void func_80321120(s32, s32);

extern u8 D_803832C0[];
extern u8 D_803832CD[];


void func_80320F10(void){ //jiggyScore_clear
    func_80321034();
    func_8032103C();
}

void *func_80320F38(void) {
    s32 i;
    for(i = 0; i < 0x0D; i++){
        D_803832C0[i + 0xD] = 0;
    }
}

u8* func_80320F70(void){
    return D_803832C0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_99F80/func_80320F7C.s")
// s32 func_80320F7C(s32 arg0) {
//     s32 phi_return;

//     phi_return = (D_803832CD[(arg0 - 1) / 8] & (1 << (arg0 & 7))) != 0;
//     if (!phi_return)
//         phi_return =  (func_80320FE0(arg0) != 0);
//     return phi_return;
// }

u32 func_80320FE0(s32 indx){
    if( indx <= 0 || indx >= 0x65)
        return 0;
    return (D_803832C0[(indx - 1) / 8] & (1 << (indx & 7))) != 0;
}

void func_80321034(void){}

void func_8032103C(void){
    s32 i;
    for(i = 0; i < 0x0D; i++){
        D_803832C0[i] = 0;
    }
    func_80320F38();
}

void func_8032108C(s32 indx,  s32 val){
    if( 0 < indx && indx < 0x65){
        if(val)
            D_803832C0[(indx - 1) / 8] |= (1 << (indx & 7));
        else
            D_803832C0[(indx - 1) / 8] &= ~(1 << (indx & 7));
    }
}

void func_80321120(s32 indx, s32 val) {
    u8 *temp_v0;
    u8 *temp_v0_2;

    if (val) {
        temp_v0 = ((s32) (indx - 1) / 8) + 0xD;
        temp_v0 += (s32) D_803832C0;
        *temp_v0 |= (1 << (indx & 7));
        return;
    }
    temp_v0_2 = ((s32) (indx - 1) / 8) + 0xD;
    temp_v0_2 += (s32)D_803832C0;
    *temp_v0_2 &=  ~(1 << (indx & 7));
}

s32 func_803211AC(s32 lvl) {
    s32 i;
    s32 start;
    s32 end;
    s32 cnt;

    if (lvl <= 0 || lvl == 0xB || lvl >= 0xB)
        return 0;

    cnt = 0;
    start = (lvl - 1)*10 + 1;
    end = (lvl)*10 + 1;
    for(i = start; i < end; i++ ){
        if(func_80320FE0(i))
            cnt++;
    }
    return cnt;
}

s32 func_8032123C(void) {
    s32 i;
    s32 cnt;
    

    for(i = 0, cnt = 0; i < 0xC; i++){
        cnt += func_803211AC(i);
    }
    return cnt;
}

void func_8032128C(s32 *size, u8 **addr){
    *size = 0x0D;
    *addr = D_803832C0; 
}