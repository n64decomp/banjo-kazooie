#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

Actor *func_803056FC(s32, f32*, f32*);

ActorArray *D_8036E560;
extern u32 D_80378E08;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80325300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80325340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803253A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803255FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80325760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80325794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803257A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803257B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80325888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80325934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80325AE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80325CAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80325E78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80325F2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80325F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80325F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80325FE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80326124.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80326218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80326224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80326244.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032627C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032628C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803262B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803262E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80326310.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80326324.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80326894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803268B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80326C18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80326C24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80326C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80326CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80326D68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80326EEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80326F58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80326FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803270B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032728C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803272D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803272F8.s")

//actor_free
void func_80328028(ActorMarker *arg0, Actor *arg1){
    s32 arrayEnd;

    arrayEnd = &D_8036E560->data[D_8036E560->cnt - 1];
    func_80325FE8(arg1);
    if((s32)arg1 != arrayEnd)
        func_80254608(arg1, arrayEnd, 0x180); //memcpy
    arg1->marker->actrArrayIdx = arg0->actrArrayIdx;
    D_8036E560->cnt--;
    if(D_8036E560->cnt + 8 <= D_8036E560->unk4){
        D_8036E560->unk4 = D_8036E560->cnt + 4;
        D_8036E560 = (ActorArray *)realloc(D_8036E560, D_8036E560->unk4*sizeof(Actor) + sizeof(ActorArray));
    }
    func_8032F430(arg0);//marker_free
}

Actor *func_8032811C(s32 id, f32 *pos, f32* rot){
    return func_803056FC(id, pos, rot);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032813C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032818C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803282AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803282F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803283BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803283D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328478.s")

u32 func_80328508(Actor * arg0, u32 arg1){
    ActorAnimationInfo *animInfo;

    arg0->unk10_31 = arg1;
    if(!arg0->unk18)
        return 0;

    if((animInfo = &arg0->unk18[arg1])->index){
        if(arg0->movement == NULL){
            arg0->movement = movement_new(0);
            func_802874AC(arg0->movement);
        }
        movement_setIndex(arg0->movement, animInfo->index);
        movement_setDuration(arg0->movement, animInfo->duration);
        movement_setDirection(arg0->movement, mvmt_dir_forwards);
    }
    else{
        if(arg0->movement){
            func_80287674(arg0->movement, 3);
            movement_setDirection(arg0->movement, mvmt_dir_forwards);
        }
    }
    return 1;
    
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803285E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032863C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032881C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032886C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803289EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328A2C.s")



void func_80328A84(Actor * arg0, u32 arg1){
    if(func_80328508(arg0, arg1) && arg0->movement){
        func_802875AC(arg0->movement, &D_80378E08, 0X6CA);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328AC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328AEC.s")
// void func_80328AEC(Actor * arg0, u32 arg1){
//     if(func_80328508(arg0, arg1) && arg0->movement){
//         func_80287674(arg0->movement, 2);
//         func_803289EC(arg0, NULL, 1); //li zero instead of move?
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328B38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328B8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328BD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328C64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328CA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328CEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328DAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328DCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328FB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328FF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329030.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329054.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803292E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032944C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803294B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803294F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329588.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803296B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803296D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032970C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803297C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803297FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803298AC.s")

//actor_loopAnimation
void func_803298D8(Actor *this){
    if(this->movement)
        func_80287674(this->movement, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329940.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032994C.s")

//marker_getActorPtr
Actor *marker_getActor(ActorMarker *this){
    return &(D_8036E560->data[this->actrArrayIdx]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803299B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329B68.s")

void actor_copy(Actor *dst, Actor *src){
    dst->marker = src->marker;
    dst->movement = src->movement;
    dst->unk44_4 = src->unk44_4;
    dst->unk148 = src->unk148;
    dst->unk14C = src->unk14C;
    dst->unk150 = src->unk150;
    func_80254608(src, dst, sizeof(Actor));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80329CBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032A09C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032A5F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032A6A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032A7AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032A82C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032A88C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032A95C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032A9E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032AA58.s")

void actor_collisionOff(Actor* this){
    this->marker->collidable = 0;
}

void actor_collisionOn(Actor* this){
    this->marker->collidable = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032AA9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032AABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032AB84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032ACA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032AD7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032AEB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032AF94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032B16C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032B258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032B38C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032B3A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032B4DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032B5C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032BB88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032BBE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032BC18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032BC3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032BC60.s")
