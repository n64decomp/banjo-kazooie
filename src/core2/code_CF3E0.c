#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    s16 a;
    s16 b;
} unkD_80372730;
// Needs to be a struct to match, s16 array doesn't work
extern unkD_80372730 D_80372730[];
// 0104 1100: 00 AB 0B A1 00 AC 0B A2  00 AA 0C E6 00 0F 0C 85  ........ ........  
// 0104 1110: 00 A9 0B A0 00 10 0A 7E  00 14 0C 11 00 0F 0C 85  .......~ ........  
// 0104 1120: 00 86 0A E1 00 DD 0C E7  00 03 0D 9C 00 04 0D 9D  ........ ........  
// 0104 1130: 00 05 0D 9E 00 06 0D 9F  00 07 0D A0 00 08 0B 46  ........ .......F  
// 0104 1140: 00 09 0A 21 00 0A 0D A1  00 0B 0D A2 00 0C 0D A3  ...!.... ........  
// 0104 1150: 00 BE 0F A8 00 BF 0F A9  00 C0 0F AA 00 95 0B 50  ........ .......P  
// 0104 1160: 00 A7 0F 7B FF FF FF FF  


extern unkD_80372730 D_80372798[];
// 00 9E 0B A3 00 9F 0C E8  ...{.... ........  
// 0104 1170: 00 A0 10 32 00 A1 10 33  00 A2 10 34 00 A3 10 35  ...2...3 ...4...5  
// 0104 1180: 00 A4 10 36 00 A5 10 37  00 A6 10 38 00 A7 10 39  ...6...7 ...8...9  
// 0104 1190: 00 A8 10 3A 00 A9 10 3B  00 AA 10 3C 00 AB 10 3D  ...:...; ...<...=  
// 0104 11A0: 00 AC 0A 88 00 AD 0A E2  00 AE 0C 8B 00 AF 0C 8C  ........ ........  
// 0104 11B0: 00 B0 0F BD 00 C2 0E 36  00 C5 0D B6 FF FF FF FF  .......6 ........  

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

/* BREAK */

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
