#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802D1724(void);

void func_80387EC0(void) {
    u32 *temp_v0;
    u32 temp_a0;

    temp_v0 = func_802D1724;
    if (getGameMode() != 7) {
        temp_a0 = (temp_v0[2] & 0x03FFFFFF)*4; //get offset
        temp_a0 += (u32)&temp_v0[3] & 0xF0000000; //get region
        ((u32 *)temp_a0)[0] = 0x03E00008; //jr $ra
        ((u32 *)temp_a0)[1] = 0x24020002; //addiu $v0, $zero, 0x2
        
        osWritebackDCache(temp_a0, 8);
        osInvalICache(temp_a0, 8);
    }
}

void func_80387F44(void) {
    s32 sp1C;

    osPiReadIo(0x578, &sp1C);
    sp1C = sp1C & (sp1C ^ 0xFFFF0000);
    if (sp1C != 0x8965){
        func_80387EC0();
    }
}