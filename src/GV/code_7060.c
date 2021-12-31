#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

extern ActorInfo D_80390BF0;
extern ActorInfo D_80390C5C;
extern ActorInfo D_80390C80;
extern ActorInfo D_80390D30;
extern ActorInfo D_80390D60;
extern ActorInfo D_80390CB0;
extern ActorInfo D_80390D00;
extern ActorInfo D_80390D90;
extern ActorInfo D_80390DD0;
extern ActorInfo D_80390E30;
extern ActorInfo D_80390E54;
extern ActorInfo D_80390ED0;
extern ActorInfo D_80390F00;
extern ActorInfo D_80390FD0;
extern ActorInfo D_80391010;
extern ActorInfo D_80391098;
extern ActorInfo D_80391158;
extern ActorInfo D_803911C0;
extern ActorInfo D_803911F4;
extern ActorInfo D_80391218;
extern ActorInfo D_8039123C;
extern ActorInfo D_80391260;
extern ActorInfo D_80391318;
extern ActorInfo D_80391358;
extern ActorInfo D_803912B8;
extern ActorInfo D_80391390;
extern ActorInfo D_803913B4;
extern ActorInfo D_80390F40;
extern ActorInfo D_80391494;
extern ActorInfo D_803915C0;
extern ActorInfo D_80391620;
extern ActorInfo D_803914B8;
extern ActorInfo D_803914DC;
extern ActorInfo D_80391500;
extern ActorInfo D_80391524;
extern ActorInfo D_8039156C;
extern ActorInfo D_80391428;
extern ActorInfo D_8039144C;
extern ActorInfo D_80391470;
extern ActorInfo D_80391548;
extern ActorInfo D_80391590;



void func_8038D47C(Actor *this);
/* .data */
extern ActorAnimationInfo D_80391290[];
extern ActorInfo D_803912B8 = { 0xF9, 0x1F7, 0x422, 
    0x1, D_80391290, 
    func_8038D47C, func_80326224, func_80325888, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038D450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038D47C.s")
/* BREAK */

void func_8038DBDC(Actor *this);
Actor *func_8038DA18(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorAnimationInfo D_803912E0[];
extern ActorInfo D_80391318 = { 0xAA, 0x11C, 0x3DE, 
    0x1, D_803912E0, 
    func_8038DBDC, func_80326224, func_8038DA18, 
    { 0x9, 0xC4, 0x0, 0x0}, 1.7f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038D920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038DA18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038DB0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038DB4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038DB58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038DB64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038DB70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038DB88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038DBDC.s")

void func_8038E1A0(Actor *this);
void func_8038E1A8(Actor *this);

/* .data */
extern ActorAnimationInfo D_80391340[];
extern ActorInfo D_80391358 = { 0xAE, 0x121, 0x3E6, 
    0x1, D_80391340, 
    func_8038E1A0, func_8038E1A8, func_80325888, 
    { 0x9, 0xC4, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038E140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038E178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038E184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038E18C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038E1A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038E1A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038E2FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038E344.s")

void func_8038E3B0(Actor *this);

/* .data */
extern ActorAnimationInfo D_80391380[];
extern ActorInfo D_80391390 = { 0xFA, 0x1F8, 0x423,
    0x1, D_80391380,
    func_8038E3B0, func_80326224, func_80325888,
    { 0x0, 0x0, 0x1, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_803913B4 = { 0xFB, 0x1F9, 0x424,
    0x1, D_80391380,
    func_8038E3B0, func_80326224, func_80325888,
    { 0x0, 0x0, 0x1, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038E3B0.s")

extern void func_802D3D54(Actor *this);
extern Actor *func_80325F2C(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

void func_8038E460(Actor *this);
void func_8038E4DC(Actor *this);
void func_8038E648(Actor *this);
void func_8038E914(Actor *this);
void func_8038E97C(Actor *this);
void func_8038EB40(Actor *this);
void func_8038ED54(Actor *this);
void func_8038EE10(Actor *this);
void func_8038EEC4(Actor *this);
void func_8038EF14(Actor *this);
void func_8038EF3C(Actor *this);

/* .data */
extern ActorAnimationInfo D_803913E0[];
extern ActorInfo D_80391428 = { 0xEC, 0x13F, 0x400, 
    0x1, D_803913E0, 
    func_8038ED54, func_80326224, func_80325888,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8039144C = { 0xF1, 0x144, 0x3D7, 
    0x1, D_803913E0, 
    func_8038EE10, func_80326224, func_80325888,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391470 = { 0xF2, 0x145, 0x438, 
    0x1, D_803913E0, 
    func_8038EEC4, func_80326224, func_80325888,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391494 = { 0x23C, 0x245, 0x515, 
    0x1, D_803913E0, 
    func_8038EF14, func_80326224, func_80325888,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_803914B8 = { 0xEB, 0x6D, 0x3D8, 
    0x1, 0x0, 
    func_802D3D54, func_8038E460, func_80325F2C,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_803914DC = { 0xED, 0x140, 0x3FF, 
    0x1, 0x0, 
    func_802D3D54, func_8038E4DC, func_80325F2C,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391500 = { 0xF0, 0x143, 0x3D9, 
    0x1, 0x0, 
    func_8038EB40, func_80326224, func_80325F2C,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391524 = { 0xEF, 0x142, 0x3DB, 
    0x1, 0x0, 
    func_8038E648, func_80326224, func_80325F2C,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391548 = { 0xF3, 0x146, 0x3E2, 
    0x1, 0x0, 
    func_8038EF3C, func_80326224, func_80325E78,
    { 0x0, 0x0, 0x4, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8039156C = { 0xF8, 0x1F5, 0x3D9, 
    0x1, 0x0, 
    func_8038E97C, func_80326224, func_80325F2C,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391590 = { 0x23A, 0x243, 0x514, 
    0x1, 0x0, 
    func_8038E914, func_80326224, func_80325F2C, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};



/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038E3E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038E408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038E430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038E460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038E4DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038E648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038E914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038E97C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038EB40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038ED54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038EE10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038EEC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038EF14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038EF3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038F004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038F028.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038F10C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038F130.s")

void func_8038F154(void)
{
    spawnableActorList_add(&D_80390BF0, actor_new, 0X180);
    spawnableActorList_add(&D_80390C5C, actor_new, 0X58A);
    spawnableActorList_add(&D_80390C80, actor_new, 0X9A8);
    spawnableActorList_add(&D_80390D30, actor_new, 0X880);
    spawnableActorList_add(&D_80390D60, actor_new, 0X80);
    spawnableActorList_add(&D_80390CB0, actor_new, 0XDA8);
    spawnableActorList_add(&D_80390D00, actor_new, 0X9A8);
    spawnableActorList_add(&D_80390D90, actor_new, 0XD80);
    spawnableActorList_add(&D_80390DD0, actor_new, 0X4004);
    spawnableActorList_add(&D_80390E30, actor_new, 0X448);
    spawnableActorList_add(&D_80390E54, actor_new, 0X48);
    spawnableActorList_add(&D_80390ED0, actor_new, 0X180);
    spawnableActorList_add(&D_80390F00, actor_new, 0X80);
    spawnableActorList_add(&D_80390FD0, actor_new, 0X4048);
    spawnableActorList_add(&D_80391010, actor_new, 0X4048);
    spawnableActorList_add(&D_80391098, actor_new, 0X10069);
    spawnableActorList_add(&D_80391158, actor_new, 0X48);
    spawnableActorList_add(&D_803911C0, actor_new, 8);
    spawnableActorList_add(&D_803911F4, actor_new, 0X80988);
    spawnableActorList_add(&D_80391218, actor_new, 0X80988);
    spawnableActorList_add(&D_8039123C, actor_new, 0X80988);
    spawnableActorList_add(&D_80391260, actor_new, 0X80);
    spawnableActorList_add(&D_80391318, actor_new, 0X78A);
    spawnableActorList_add(&D_80391358, actor_new, 0X518);
    spawnableActorList_add(&D_803912B8, actor_new, 0X500);
    spawnableActorList_add(&D_80391390, actor_new, 0X500);
    spawnableActorList_add(&D_803913B4, actor_new, 0X500);
    spawnableActorList_add(&D_80390F40, actor_new, 0);
    spawnableActorList_add(&D_80391494, actor_new, 0X408);
    spawnableActorList_add(&D_803915C0, actor_new, 0);
    spawnableActorList_add(&D_80391620, actor_new, 0X400);
    spawnableActorList_add(&D_803914B8, actor_new, 0X400);
    spawnableActorList_add(&D_803914DC, actor_new, 0X400);
    spawnableActorList_add(&D_80391500, actor_new, 0X400);
    spawnableActorList_add(&D_80391524, actor_new, 0X400);
    spawnableActorList_add(&D_8039156C, actor_new, 0X400);
    spawnableActorList_add(&D_80391428, actor_new, 8);
    spawnableActorList_add(&D_8039144C, actor_new, 8);
    spawnableActorList_add(&D_80391470, actor_new, 8);
    spawnableActorList_add(&D_80391548, actor_new, 0X400);
    spawnableActorList_add(&D_80391590, actor_new, 0X400);
}

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7060/func_8038F4C0.s")
