#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
u8 D_80283280[0x100];
s32 D_80283380;
s32 D_80283384;
s32 D_80283388;

void func_80255C30(void) {
    D_80283384 = *(s32 *)0xA4000000 ^ -1;
    D_80283388 = (D_80283384) ? 1 :0;
    D_80283380 = *(s32 *)0xA4001000 ^ 0x17D7;
    D_80283388 |= (D_80283380) ? 2 :0;
    if (D_80283388 == 0) {
        func_802405F0(&D_80283280, 0xB0000B70, 0x100);
    }
}

void func_80255CD8(void){}

void func_80255CE0(void){
    osPiReadIo(0, NULL);
}

s32 func_80255D04(void){return 0;}

void func_80255D0C(u64 **ucode_ptr, u32 *ucode_size){
    *ucode_ptr = &D_80283280;
    *ucode_size = 0x100;
}
