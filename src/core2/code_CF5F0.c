#include <ultra64.h>
#include "functions.h"
#include "variables.h"

//THIS VALUE 
#ifndef CORE2_CODE_CRC2
    #define CORE2_CODE_CRC2 0x9E44C2DC
#endif

// bk_boot segment start (skipping entry function)
extern u8 boot_bk_boot_ROM_START[];
// bk_boot segment end
extern u8 boot_bk_boot_ROM_END[];
extern u8 crc_ROM_START[];

// bk_boot segment crc next word
s32 D_803727F0 = 0;
s32 core2_D_803727F4 = CORE2_CODE_CRC2;
s32 D_803727F8 = 0;
s32 D_803727FC = 0;

// bk_boot segment crc values
s32 D_80372800 = 0;
s32 D_80372804 = 0;

// bk_boot segment crc remaining words
s32 D_80372808 = 0;

// init bk_boot crc
void func_80356580(void) {
    D_803727FC = (s32) boot_bk_boot_ROM_START;
    D_80372800 = 0;
    D_80372804 = -1;
    D_80372808 = (s32) (boot_bk_boot_ROM_END - boot_bk_boot_ROM_START);
}

// advance bk_boot crc by one word
s32 func_803565BC(void) {
    u32 crc1;
    u32 crc2;
    u8 romBytes[4];
    u8 curByte;

    if (D_803727FC != 0) {
        if (D_80372808 != 0) {
            crc1 = D_80372800;
            crc2 = D_80372804;
            osPiReadIo(D_803727FC, (u32*)romBytes);
            curByte = romBytes[0];
            crc1 += curByte;
            crc2 ^= curByte << (crc1 & 0x17);
            curByte = romBytes[1];
            crc1 += curByte;
            crc2 ^= curByte << (crc1 & 0x17);
            curByte = romBytes[2];
            crc1 += curByte;
            crc2 ^= curByte << (crc1 & 0x17);
            curByte = romBytes[3];
            crc1 += curByte;
            crc2 ^= curByte << (crc1 & 0x17);
            D_80372800 = crc1;
            D_80372804 = crc2;
            D_803727FC = D_803727FC + 4;
            D_80372808 = D_80372808 - 4;
        } else {
            D_803727FC = 0;
            osPiReadIo((u32)crc_ROM_START + 0, &crc1);
            if (crc1 != D_80372800)
                return 0;
            osPiReadIo((u32)crc_ROM_START + 4, &crc2);
            if (crc2 != D_80372804)
                return 0;
        }
    }
    return 1;
}

void func_80356714(void) {
    func_80356580();
}

void func_80356734(void) {
    func_803565BC();
    if (func_803565BC() == 0) {
        ability_setAllLearned(0x10);
    }
}
