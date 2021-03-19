#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* extern functions */
void func_80326224(Actor *);
void func_803391A4(Gfx **, Mtx **, f32*, f32*, f32, f32*, s32);
void func_80256900(f32*, f32*, f32);

/* public functions */
void    func_80389598(Actor *this);
Actor*  func_80389014(ActorMarker *, Gfx **, Mtx**, u32);

/* .data */
ActorInfo chjujuInfo = { 0x67, actor_juju, model_juju, 0, NULL,
    func_80389598, func_80326224, func_80389014,
    {0,0,0,0}, 0.0f, {0,0,0,0}
};


extern f64 D_80389C78;

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/juju/func_80388FD0.s")

Actor*  func_80389014(ActorMarker *this, Gfx **dl, Mtx **mPtr, u32 arg2){
    f32 sp34[3];
    Actor * actorPtr;
    ActorLocal_Juju *jujuPtr;

    actorPtr = func_80325300(this, sp34);
    jujuPtr = &actorPtr->juju;
    if(jujuPtr->unk0 != 2){
        func_8033A4CC(1);
        func_803391A4(dl, mPtr, actorPtr->position, sp34, jujuPtr->unk14, NULL, func_80330B1C(this));
    }
    return actorPtr;
}

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/juju/func_803890A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/juju/func_803891E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/juju/func_80389244.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/juju/func_803892A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/juju/func_8038941C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/juju/func_8038948C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/juju/func_80389514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/juju/func_80389598.s")
// void    func_80389598(Actor *this){
//     ActorLocal_Juju *jujuPtr = &this->juju;
//     f32 sp28[3];
//     // if(jujuPtr == 2){

//     // }
//     switch(jujuPtr->unk0){
//         case 1: //L80389624
//             func_8033DD9C();
//             break;
//         case 3: //L80389700
//             if(--jujuPtr->unk4 == 0){
//                 jujuPtr->unk0 = 4;
//                 jujuPtr->unkC = this->position_y - 250.0f;
//             }
//             break;
//         case 5: //L80389738
//             sp28[0] = 100.0f;
//             sp28[1] = 0.0f;
//             sp28[2] = 0.0f;
//             func_80256900(sp28, sp28, this->yaw + D_80389C78);
//             break;
//         case 4: //L803897F8
//             break;
        
//     }//L8038987C
// }

