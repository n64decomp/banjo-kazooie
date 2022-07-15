#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028F710(s32, f32);

/* .data */
u8 D_80390F30[] = {
    0x00, 0x27, 0x45, 0x30, 
    0xAA, 0x18, 0xBB, 0xF3, 
    0x00, 0x03, 0x03, 0x1C, 
    0x00, 0x00, 0x00, 0x00
};

/* .code */
void func_80389F00(void){
    if(getGameMode() != GAME_MODE_7_ATTRACT_DEMO && 2.0f < func_8028E80C(3)){
        func_8028F710(3, 2.0f);
    }
}

void func_80389F5C(void){
    u32 sp1C;
    osPiReadIo(0x800, &sp1C);
    sp1C <<= 0x10;
    if(sp1C != 0x10000)
        func_80389F00();
}
