#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

extern ActorInfo D_80390D20;
extern ActorInfo D_80390050;
extern ActorInfo D_80390200;
extern ActorInfo D_80390270;
extern ActorInfo D_80390D50;
extern ActorInfo D_803906E0;
extern ActorInfo D_80390738;
extern ActorInfo D_803907D0;
extern ActorInfo D_803907F4;
extern ActorInfo D_80390818;
extern ActorInfo D_8039083C;
extern ActorInfo D_803904C0;
extern ActorInfo D_803904E4;
extern ActorInfo D_80390508;
extern ActorInfo D_803903B0;
extern ActorInfo D_803903D4;
extern ActorInfo D_803903F8;
extern ActorInfo D_80390640;
extern ActorInfo D_80390664;
extern ActorInfo D_80390688;
extern ActorInfo D_803906B0;
extern ActorInfo D_803908C0;
extern ActorInfo D_803908E4;
extern ActorInfo D_80390908;
extern ActorInfo D_803909B0;
extern ActorInfo D_803909D4;
extern ActorInfo D_803909F8;
extern ActorInfo D_80390A50;
extern ActorInfo D_80390380;
extern ActorInfo D_80390A80; //anchorswitch
extern ActorInfo D_80390AB0; //dolphin
extern ActorInfo D_80390AE0; //anchor
extern ActorInfo D_80390B10;
extern ActorInfo D_80390B40; //rarewareflag
extern ActorInfo D_80390BD0;
extern ActorInfo D_80390BF4;
extern ActorInfo D_80390C18;
extern ActorInfo D_80390C3C;
extern ActorInfo D_80390CF0;
extern ActorInfo D_80390D88;
extern ActorInfo D_80390DAC; //TNTpart_IDStruct;
extern ActorInfo D_80390E00;
extern ActorInfo D_80390E34;
extern ActorInfo D_80390E58;
extern ActorInfo D_803900E0;
extern ActorInfo D_80390104; //captcabinwooddoor
extern ActorInfo D_80390128;
extern ActorInfo D_8039014C;
extern ActorInfo D_803901B8;
extern ActorInfo D_803901DC;
extern ActorInfo D_80390170;//skylight
extern ActorInfo D_80390194;//honeycombswitch


#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_0/func_803863F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_0/func_803865A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_0/func_803865D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_0/func_803866F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_0/func_8038685C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_0/func_803868F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_0/func_80386A30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_0/func_80386A7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_0/func_80386B9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_0/func_80386BF8.s")

void rbb_func_80386C48(void){
    func_803053E8(&D_80390D20, func_803272F8, 0x4880);
    func_803053E8(&D_80390050, func_803272F8, 0);
    func_803053E8(&D_80390200, func_803272F8, 0x80);
    func_803053E8(&D_80390270, func_803272F8, 0x80);
    func_803053E8(&D_80390D50, func_803272F8, 0x8004480);
    func_803053E8(&D_803906E0, func_803272F8, 0x80);
    func_803053E8(&D_80390738, func_803272F8, 0x80);
    func_803053E8(&D_803907D0, func_803272F8, 0x6488);
    func_803053E8(&D_803907F4, func_803272F8, 0x6488);
    func_803053E8(&D_80390818, func_803272F8, 0x6488);
    func_803053E8(&D_8039083C, func_803272F8, 0x6488);
    func_803053E8(&D_803904C0, func_803272F8, 0x6408);
    func_803053E8(&D_803904E4, func_803272F8, 0x6408);
    func_803053E8(&D_80390508, func_803272F8, 0x6408);
    func_803053E8(&D_803903B0, func_803272F8, 0x6408);
    func_803053E8(&D_803903D4, func_803272F8, 0x6408);
    func_803053E8(&D_803903F8, func_803272F8, 0x6408);
    func_803053E8(&D_80390640, func_803272F8, 0x400);
    func_803053E8(&D_80390664, func_803272F8, 0x400);
    func_803053E8(&D_80390688, func_803272F8, 0x400);
    func_803053E8(&D_803906B0, func_803272F8, 0);
    func_803053E8(&D_803908C0, func_803272F8, 0x80);
    func_803053E8(&D_803908E4, func_803272F8, 0x80);
    func_803053E8(&D_80390908, func_803272F8, 0x80);
    func_803053E8(&D_803909B0, func_803272F8, 0x880);
    func_803053E8(&D_803909D4, func_803272F8, 0x880);
    func_803053E8(&D_803909F8, func_803272F8, 0x880);
    func_803053E8(&D_80390A50, func_803272F8, 0x80);
    func_803053E8(&D_80390380, func_803272F8, 0x9aa);
    func_803053E8(&D_80390A80, func_803272F8, 0x80); //anchorswitch
    func_803053E8(&D_80390AB0, func_803272F8, 0x8C8); //dolphin
    func_803053E8(&D_80390AE0, func_803272F8, 0xC80); //anchor
    func_803053E8(&D_80390B10, func_803272F8, 0x80);
    func_803053E8(&D_80390B40, func_803272F8, 0x880); //rarewareflag
    func_803053E8(&D_80390BD0, func_803272F8, 0xc2c);
    func_803053E8(&D_80390BF4, func_803272F8, 0xc2c);
    func_803053E8(&D_80390C18, func_803272F8, 0xc2c);
    func_803053E8(&D_80390C3C, func_803272F8, 0xc2c);
    func_803053E8(&D_80390CF0, func_803272F8, 0x80);
    func_803053E8(&D_80390D88, func_803272F8, 0x2000889);
    func_803053E8(&D_80390DAC, func_803272F8, 0x2000889);
    func_803053E8(&D_80390E00, func_803272F8, 0x80);
    func_803053E8(&D_80390E34, func_803272F8, 0x80);
    func_803053E8(&D_80390E58, func_803272F8, 0x80);
    func_803053E8(&D_803900E0, func_803272F8, 0);
    func_803053E8(&D_80390104, func_803272F8, 0x8600); //captcabinwooddoor
    func_803053E8(&D_80390128, func_803272F8, 0);
    func_803053E8(&D_8039014C, func_803272F8, 0);
    func_803053E8(&D_803901B8, func_803272F8, 0x8600);
    func_803053E8(&D_803901DC, func_803272F8, 0x8600);
    func_803053E8(&D_80390170, func_803272F8, 0x8600); //skylight
    func_803053E8(&D_80390194, func_803272F8, 0x8); //honeycombswitch
}
