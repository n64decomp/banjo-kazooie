#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_8033A244(f32);
void func_8033A280(f32);

extern f32 D_803762FC;



u32 func_802C8088(Actor *this);
Actor *func_802C41D8(f23, f32, f32);

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/jiggy/func_802C7A30.s")

void func_802C7AB0(ActorMarker * arg0, u32 arg1){
    func_8030E6D4(0x30);
    func_8025A6EC(0x3c, 0x7FF8);
    func_802CADC0(arg1, 1);
    func_803282F4(arg0);
}

void func_802C7AF8(u32 x, u32 y, u32 z, u32 arg3){
    func_802C3F04(func_802C41D8, 0x4c, x, y, z); //spawn steam
    func_802C3F04(func_802C41D8, 0x14f, x, y, z); //spawn destroyed jiggy
    func_802CADC0(arg3, 1);
}

void func_802C7B6C(u32 arg0){
    func_802CADC0(arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/jiggy/func_802C7B8C.s")

//chjiggy_updateRotate
void func_802C7CA4(Actor *this){
    f32 delta = func_8033DD9C();
    this->yaw += delta * 230.0f;
    if(360.0f <= this->yaw){
        this->yaw -= 360.0f;
    }
    this->yaw_moving = this->yaw;
}

//chjiggy_draw
Actor *func_802C7D0C(ActorMarker *this, Gfx **gdl, Mtx **mptr, u32 arg3){
    Actor * thisActor;
    u32 jiggyId;
    thisActor = func_80329958(this);
    if(!thisActor->jiggy.unk0){
        jiggyId = func_802C8088(thisActor);
        if((jiggyId == 0x1c) || (jiggyId == 0x1d)){
            func_8033A280(10.0f);
            func_8033A244(D_803762FC);
        }
        thisActor = func_80325888(this, gdl, mptr, arg3);
    }
    return thisActor;
}

void func_802C7D98(Actor * arg0){
    func_80343DEC(arg0);
    func_802C7CA4(arg0);
}

//chjiggy_update
#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/jiggy/func_802C7DC0.s")

//chjiggy_getId
u32 func_802C8088(Actor *this){
    return this->jiggy.index;
}


void func_802C8090(Actor * arg0){
    arg0->jiggy.unk0 = 1;
    actor_collisionOff(arg0);
}

//chjiggy_setId
void func_802C80B4(Actor *this, u32 id){
    this->jiggy.index = id;
}
