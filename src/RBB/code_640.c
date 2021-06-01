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


#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_640/func_80386A30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_640/func_80386A7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_640/func_80386B9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_640/func_80386BF8.s")

void rbb_func_80386C48(void){
    func_803053E8(&D_80390D20, actor_new, 0x4880);
    func_803053E8(&D_80390050, actor_new, 0);
    func_803053E8(&D_80390200, actor_new, 0x80);
    func_803053E8(&D_80390270, actor_new, 0x80);
    func_803053E8(&D_80390D50, actor_new, 0x8004480);
    func_803053E8(&D_803906E0, actor_new, 0x80);
    func_803053E8(&D_80390738, actor_new, 0x80);
    func_803053E8(&D_803907D0, actor_new, 0x6488);
    func_803053E8(&D_803907F4, actor_new, 0x6488);
    func_803053E8(&D_80390818, actor_new, 0x6488);
    func_803053E8(&D_8039083C, actor_new, 0x6488);
    func_803053E8(&D_803904C0, actor_new, 0x6408);
    func_803053E8(&D_803904E4, actor_new, 0x6408);
    func_803053E8(&D_80390508, actor_new, 0x6408);
    func_803053E8(&D_803903B0, actor_new, 0x6408);
    func_803053E8(&D_803903D4, actor_new, 0x6408);
    func_803053E8(&D_803903F8, actor_new, 0x6408);
    func_803053E8(&D_80390640, actor_new, 0x400);
    func_803053E8(&D_80390664, actor_new, 0x400);
    func_803053E8(&D_80390688, actor_new, 0x400);
    func_803053E8(&D_803906B0, actor_new, 0);
    func_803053E8(&D_803908C0, actor_new, 0x80);
    func_803053E8(&D_803908E4, actor_new, 0x80);
    func_803053E8(&D_80390908, actor_new, 0x80);
    func_803053E8(&D_803909B0, actor_new, 0x880);
    func_803053E8(&D_803909D4, actor_new, 0x880);
    func_803053E8(&D_803909F8, actor_new, 0x880);
    func_803053E8(&D_80390A50, actor_new, 0x80);
    func_803053E8(&D_80390380, actor_new, 0x9aa);
    func_803053E8(&D_80390A80, actor_new, 0x80); //anchorswitch
    func_803053E8(&D_80390AB0, actor_new, 0x8C8); //dolphin
    func_803053E8(&D_80390AE0, actor_new, 0xC80); //anchor
    func_803053E8(&D_80390B10, actor_new, 0x80);
    func_803053E8(&D_80390B40, actor_new, 0x880); //rarewareflag
    func_803053E8(&D_80390BD0, actor_new, 0xc2c);
    func_803053E8(&D_80390BF4, actor_new, 0xc2c);
    func_803053E8(&D_80390C18, actor_new, 0xc2c);
    func_803053E8(&D_80390C3C, actor_new, 0xc2c);
    func_803053E8(&D_80390CF0, actor_new, 0x80);
    func_803053E8(&D_80390D88, actor_new, 0x2000889);
    func_803053E8(&D_80390DAC, actor_new, 0x2000889);
    func_803053E8(&D_80390E00, actor_new, 0x80);
    func_803053E8(&D_80390E34, actor_new, 0x80);
    func_803053E8(&D_80390E58, actor_new, 0x80);
    func_803053E8(&D_803900E0, actor_new, 0);
    func_803053E8(&D_80390104, actor_new, 0x8600); //captcabinwooddoor
    func_803053E8(&D_80390128, actor_new, 0);
    func_803053E8(&D_8039014C, actor_new, 0);
    func_803053E8(&D_803901B8, actor_new, 0x8600);
    func_803053E8(&D_803901DC, actor_new, 0x8600);
    func_803053E8(&D_80390170, actor_new, 0x8600); //skylight
    func_803053E8(&D_80390194, actor_new, 0x8); //honeycombswitch
}
