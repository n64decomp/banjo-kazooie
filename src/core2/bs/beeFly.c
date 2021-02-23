#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 func_8034A754(f32, f32);
void func_80354030(f32*, f32);
void func_8028A274(s32, f32);

f32  func_8029B2E8(void);
void func_802991B4(f32);
f32 func_8029B33C(void);
void func_8029797C(f32);
f32 func_80299228(void);
void func_80297970(f32);
void func_80297BEC(f32);
s32 func_802878E8(Movement *, f32);
void func_802979A0(f32);
void func_8030E58C(s32, f32);
void func_8028A010(s32, f32);
void func_80297FB0(f32, f32);
void func_802921BC(f32);
void func_80298CE0(f32);
void func_80297F3C(f32);
void func_80298D54(f32, f32);
void func_80297BF8(f32);


extern f32 D_80375350;
extern f32 D_80375358;
extern f32 D_80375354;

extern  u8 D_8037D2C0;


void func_802A04F0(void){
    f32 plyrPos[3]; //sp1C

    player_getPosition(plyrPos);
    plyrPos[0] += func_8034A754(-30.0f, 30.0f);
    plyrPos[1] += 30.0f + func_8034A754(0.0f, 30.0f);
    plyrPos[2] += func_8034A754(-30.0f, 30.0f);
    func_803541C0(3);
    func_803541CC(0x50);
    func_80354030(plyrPos, 0.5f);

}

void func_802A0590(void){
    func_802A0340();
    func_8028A274(0x1df, 1.5f);
    func_8029C7F4(1,1,3,6);
    if(func_8029B2E8() != 0.0f){
        func_802991B4(func_8029B33C());
    }
    func_8029797C(func_80299228());
    func_80297970(0.0f);
    func_80297BEC(-1200.0f);
    D_8037D2C0 = 0;
}

void func_802A0630(void){
    s32 next_state = 0;
    Movement * mvmnt; //sp1C

    mvmnt = func_80289F64();
    switch(D_8037D2C0){
        case 0:
            if(!func_802878E8(mvmnt, 0.266f))
                break;
            func_802979A0(1600.0f);
            func_8030E58C(0xc, 0.7f);
            D_8037D2C0 = 1;
            break;
        case 1:
            func_802A04F0();
            if(func_802878C4(mvmnt))
                func_8028A010(0x1dc, 0.38f);
            if(func_80297AAC() < 0.0f)
                next_state = 0x8c;
            break;
    }
    func_8029A72C(next_state);
}

void func_802A0704(void){
    func_802A02C0();
}

void func_802A0724(void){
    func_80297FB0(500.0f, D_80375350);
}

void func_802A0750(void){
    func_80297FB0(1000.0f, D_80375354);
}

void func_802A077C(void){
    if(func_802A0F78(func_8029A7D4()))
        return;
    func_802921BC(0.0f);
    func_80298CE0(0.0f);
    func_80297F3C(0.0f);
    func_80291548();
    func_80297B70();
    func_80297B94();
    func_8028FFBC(0);
    func_8029099C();
}

// #pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A07F8.s")
void func_802A07F8(void){
    if(func_802A0F78(func_8029A7BC()))
        return;
    func_802921BC(65.0f);
    func_802991A8(3);
    func_80298D54(500.0f, 2.0f);
    func_802A0724();
    func_80297BEC(-300.0f);
    func_80297BF8(D_80375358);
    func_8028FEF0();
    func_8028FFBC(1);
    func_802909C4();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A0890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A09A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A0A2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A0B14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A0F58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A0F78.s")
