#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    s16 a;
    s16 b;
} unkD_80372730;
// Needs to be a struct to match, s16 array doesn't work
extern unkD_80372730 D_80372730[];
extern unkD_80372730 D_80372798[];

s32 func_80356370(unkD_80372730 *arg0, s32 arg1) {
    s32 phi_v1 = 0;

    while (arg0[phi_v1].a >= 0) {
        if (arg1 == arg0[phi_v1].a) {
            return phi_v1;
        }
        phi_v1++;
    }
    return -1;
}

s32 func_803563B8(s32 arg0, s32 arg1) {
    s32 temp_v0;

    if (func_8031FF1C(arg0) != 0) {
        return 0;
    } else {
        temp_v0 = func_80356370(D_80372730, arg0);
        if (temp_v0 != -1) {
            if (func_80311480(D_80372730[temp_v0].b, arg1, 0, 0, 0, 0) != 0) {
                func_80320004(arg0, 1);
            }
            return func_8031FF1C(arg0);
        }
        return 0;
    }
}

void func_8035644C(s32 arg0){
    func_803563B8(arg0, 0);
}

void func_8035646C(s32 arg0) {
    func_803563B8(arg0, 4);
}

s32 func_8035648C(s32 arg0, s32 arg1) {
    s32 temp_v0;

    if (func_803203FC() != 0) {
        return 0;
    } else {
        temp_v0 = func_80356370(D_80372798, arg0);
        if (temp_v0 != -1) {
            if (func_80311480(D_80372798[temp_v0].b, arg1, 0, 0, 0, 0) != 0) {
                func_803204E4(arg0, 1);
            }
            return func_803203FC(arg0);
        }
        return 0;
    }
}

void func_80356520(s32 arg0) {
    func_8035648C(arg0, 0);
}

void func_80356540(s32 arg0) {
    func_8035648C(arg0, 4);
}

void func_80356560(s32 arg0) {
    func_8035648C(arg0, 0xE);
}

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
        func_80295864(0x10);
    }
}
