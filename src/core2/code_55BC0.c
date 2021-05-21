#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern ActorAnimationInfo D_80368118[];

extern u32 D_8037DE80;
extern u32 D_8037DE84;

void func_80328B8C(Actor *, s32, f32, s32);
void func_803253A0(Actor *);
void func_80325794(ActorMarker *);
void func_803391A4(Gfx **, Mtx **, f32*, s32, f32, f32 *, void *);
Actor *func_8032813C(s32 id, s32, s32);

extern f32 D_80376F10;

Actor *func_802DCB50(ActorMarker *marker, Gfx **gdl, Mtx **mptr, s32* vptr){
    Actor * actor;
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    

    actor = marker_getActor(marker);
    if(D_8037DE84)
        return actor;

    func_8033A2D4(func_803253A0, actor);
    func_8033A2E8(func_80325794, marker);
    func_8024E258();
    {sp58[0] = 0.0f; sp58[1] = 0.0f; sp58[2] = D_80376F10;};
    {sp4C[0] = 0.0f; sp4C[1] = 0.0f; sp4C[2] = 0.0f;};
    func_8024CD88(sp58);
    func_8024CE18(sp4C);
    func_8024CFD4();
    func_8024C904(gdl, mptr);
    {sp40[0] = 0.0f; sp40[1] = 0.0f; sp40[2] = 0.0f;};
    {sp34[0] = 0.0f; sp34[1] = 400.0f; sp34[2] = 0.0f;};
    func_803391A4(gdl, mptr, sp40, 0, 1.0f, sp34, func_80330B1C(marker));
    func_8024E2FC();
    func_8024C904(gdl, mptr);
    return actor;
}  

void func_802DCC78(ActorMarker *this){
    D_8037DE80 = 0;
    D_8037DE84 = 0;
}

void func_802DCC90(Actor *this){
    if(!this->initialized){
        this->initialized = 1;
        this->unk124_9 = 0;
        actor_collisionOff(this);
        func_80328B8C(this, 1, 0.0f, 1);
        actor_playAnimationOnce(this);
        func_803300D8(this->marker, func_802DCC78);
    }

    if(animctrl_isStopped(this->animctrl)){
        func_80328B8C(this, 2, 0.0f, 1);
        actor_loopAnimation(this);
    }
}

void func_802DCD34(void){
    if(D_8037DE80 == NULL){
        D_8037DE80 = func_8032813C(0x1de, D_80368118, 0)->marker;
    }
}

void func_802DCD78(s32 arg0, s32 arg1){
    if(D_8037DE80 == NULL){
        func_802C3BF8(func_802DCD34);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DCDB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DCDC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DCE00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DCF10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DCF20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DCFC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD080.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD3CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD60C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD778.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD8AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DE224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DE250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DE340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DE38C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DE41C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DE428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DE4CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DE9C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DEA18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DEA50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DEA74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DEA8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DEACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DEAF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DEB18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DEB80.s")
