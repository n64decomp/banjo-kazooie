#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    s16 unk0;
    f32 unk4[3];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8  pad16[2];
}Struct_RBB_4C70;

Actor *func_8038B230(ActorMarker *marker, Gfx** gdl, Mtx** mptr, s32 arg3);
void func_8038B340(Actor *this);

/* .data */
/* Struct_RBB_4C70 D_80390950[4] = {
    0000 A560: 01 C2 00 00 C5 68 80 00  44 48 00 00 C3 AF 00 00
    0000 A570: 00 01 01 36 03 FF 00 00  
                                        01 C3 00 00 C5 68 80 00
    0000 A580: 44 48 00 00 00 00 00 00  00 02 01 35 03 FE 00 00

    0000 A590: 01 C4 00 00 C5 68 80 00  44 48 00 00 43 AF 00 00
    0000 A5A0: 00 03 01 34 03 FD 00 00  
                                        00 00 00 00 00 00 00 00
    0000 A5B0: 00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
}; */

/* ActorInfo D_803909B0 = {
    0000 A5C0: 00 2A 01 C2 04 16 00 00  00 00 00 00 80 38 B3 40
    0000 A5D0: 00 00 00 00 80 38 B2 30  00 00 00 00 00 00 00 00
    0000 A5E0: 00 00 00 00
}; */

/* ActorInfo D_803909D4 = {
                           00 2B 01 C3  04 16 00 00 00 00 00 00
    0000 A5F0: 80 38 B3 40 00 00 00 00  80 38 B2 30 00 00 00 00
    0000 A600: 00 00 00 00 00 00 00 00  
}; */

/* ActorInfo D_803909F8 = {
                                        00 2C 01 C4 04 16 00 00
    0000 A610: 00 00 00 00 80 38 B3 40  00 00 00 00 80 38 B2 30
    0000 A620: 00 00 00 00 00 00 00 00  00 00 00 00 
}; */

/* D_80390A1C = {
    3F 80 00 00
    0000 A630: 40 00 00 00 40 40 00 00  40 A0 00 00 3D 4C CC CD
    0000 A640: 3D CC CC CD 3F C0 00 00  40 20 00 00 00 00 00 00
    0000 A650: 3F 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
}*/

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_4C70/func_8038B060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_4C70/func_8038B0B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_4C70/func_8038B230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_4C70/func_8038B340.s")
