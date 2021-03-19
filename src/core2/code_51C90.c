#include <ultra64.h>
#include "functions.h"
#include "variables.h"

u32 func_802D8D48(Actor*, u32, u32, u32, u32, f32);
void func_8032628C(Actor*,s32);
void func_8035644C(u32);

void func_802D8C20(Actor *arg0, u32 arg1){
    switch(arg1){
        default:
            break;
        case 1:
            arg0->unk28 = 0.0f; 
            //fall-through
        case 3:
            actor_collisionOff(arg0);
            break;
        case 2:
            actor_collisionOn(arg0);
            break;
    }
    func_80328A84(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D8C98.s")

//collectItem
u32 func_802D8D48(Actor* actor, u32 arg1, u32 dialogId, u32 sfxId, u32 itemId, f32 arg5){
    func_8025A6EC(sfxId,32000);
    timedFunc_set_1(0.75f, func_8035644C, arg1);
    if(!func_802FADD4(0x1b)){
        func_80345F24(itemId);
    } else {
        func_803463F4(itemId,1);   
    }

    if(!actor || !actor->unk38_0)
        return 1;
            
    actor->unk60 = arg5;
    func_802D8C20(actor, 1);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D8DF0.s")
//egg_collision
// void func_802D8DF0(ActorProp *arg0){
//     volatile Actor *actPtr = NULL;
//     if(!arg0)
//         return;

//     func_802F3808(&arg0->x);
//     if(arg0->unk8_0)
//         actPtr = marker_getActor(arg0->marker);
//     func_802D8D48(actPtr, 5, 0xD9E, 0xC, 0xD, 2.0f);
// }

//readFeather_collision
void func_802D8E68(ActorProp *arg0){
    Actor *actPtr = NULL;
    func_802F38F0(&arg0->x);
    if(arg0->unk8_0)
        actPtr = marker_getActor(arg0->marker);
    func_802D8D48(actPtr, 6, 0xD9F, 0xB, 0xF, 4.0f);
}

//goldFeather_collision
void func_802D8EDC(ActorProp *arg0){
    Actor *actPtr = NULL;
    func_802F39D8(&arg0->x);
    if(arg0->unk8_0)
        actPtr = marker_getActor(arg0->marker);
    func_802D8D48(actPtr, 7, 0xDA0, 0x14, 0x10, 6.0f);
}

Actor *func_802D8F50(ActorMarker *this, Gfx **gdl, Mtx **mptr, u32 arg3){
    Actor *thisActor = marker_getActor(this);

    if(thisActor->unk28 != 0.0f){
        if(thisActor->unk38_0){
            func_80344C2C(1);
            if(thisActor->unk28 == 255.0f){
                func_803262B8(thisActor);
            } else{
                func_8032628C(thisActor, thisActor->unk28);
            }
        }
        return func_80325934(this, gdl, mptr, arg3);
    }
    return thisActor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D9018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D9220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D9304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D93EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D94B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D9530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D9600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D9658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D9698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D9830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D997C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D9ADC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D9BD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D9C1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D9C54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D9C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D9CBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802D9D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802DA498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802DA560.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802DA634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51C90/func_802DA740.s")
