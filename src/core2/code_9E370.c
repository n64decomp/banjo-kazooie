#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"
void func_80254608(void *, void *, u32);
Actor *func_803056FC(s32, f32*, f32*);

ActorArray *D_8036E560; //actorArrayPtr
extern char D_80378DFC[];
extern char D_80378E08[]; // "subaddie.c"
extern char D_80378E20[];


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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/marker_despawn.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803283BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_803283D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328508.s")
/*int func_80328508(Actor * arg0, u32 arg1){
    ActorAnimationInfo *animInfo;

    arg0->unk10_31 = arg1;
    if(!arg0->unk18)
        return 0;

    animInfo = &arg0->unk18[arg1];
    if(animInfo->index){
        if(arg0->animctrl == NULL){
            animctrl_reset(arg0->animctrl = animctrl_new(0));
        }
        animctrl_setIndex(arg0->animctrl, animInfo->index);
        animctrl_setDuration(arg0->animctrl, animInfo->duration);
        animctrl_setDirection(arg0->animctrl, mvmt_dir_forwards);
    }
    else if(arg0->animctrl){
        animctrl_setPlaybackType(arg0->animctrl,  ANIMCTRL_STOPPED);
        animctrl_setDirection(arg0->animctrl, mvmt_dir_forwards);
    }
    return 1;
    
}//*/

void func_803285E8(Actor *this, f32 arg1, int arg2){
    func_8028774C(this->animctrl, arg1);
    if(arg2 != -1){
        animctrl_setDirection(this->animctrl, arg2);
    }
    this->sound_timer = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032863C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032881C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032886C.s")

void func_803289EC(Actor *this , f32 arg1, int arg2){
    func_803285E8(this, arg1, arg2);
    func_802875AC(this->animctrl, D_80378DFC, 0x6b1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328A2C.s")

void func_80328A84(Actor * arg0, u32 arg1){
    if(func_80328508(arg0, arg1) && arg0->animctrl){
        func_802875AC(arg0->animctrl, D_80378E08, 0X6CA);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328AC8.s")

void func_80328AEC(Actor * arg0, u32 arg1){
    if(func_80328508(arg0, arg1) && arg0->animctrl){
        animctrl_setPlaybackType(arg0->animctrl,  ANIMCTRL_LOOP);
        func_803289EC(arg0, 0.0f, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328B38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328B8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328BD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328C64.s")

void func_80328CA8(Actor *arg0, s32 angle) {
    s32 fixedAngle = angle;
    while (fixedAngle < 0) {
        fixedAngle += 360;
    }
    while (fixedAngle >= 360) {
        fixedAngle -= 360;
    }
    arg0->unk6C = fixedAngle;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328CEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328DAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328DCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328FB0.s")

f32 func_80328DCC(Actor *, f32, f32, s32);

void func_80328FF0(Actor *arg0, f32 arg1) {
    arg0->pitch = func_80328DCC(arg0, arg0->pitch, arg0->unk6C, (s32) arg1);
}

s32 func_80329030(s32 arg0, s32 arg1) {
    return !func_8032CA80(arg0, arg1);
}

s32 func_80329054(s32 arg0, s32 arg1) {
    return !func_8032CA80(arg0, arg1 + 4);
}

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

void actor_playAnimationOnce(Actor *this){
    if(this->animctrl)
        animctrl_setPlaybackType(this->animctrl, ANIMCTRL_ONCE);
}

void actor_loopAnimation(Actor *this){
    if(this->animctrl)
        animctrl_setPlaybackType(this->animctrl,  ANIMCTRL_LOOP);
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

void func_80329B68(Actor *this){
    if(this->animctrl == NULL)
        return;

    if(this->unk38_3){
        animctrl_setPlaybackType(this->animctrl, this->unk38_3);
    }
    animctrl_setIndex(this->animctrl, this->unk58_16);
    animctrl_setDirection(this->animctrl, this->unk78_1);
    animctrl_setSmoothTransition(this->animctrl, this->unk78_0);
    animctrl_setDuration(this->animctrl, this->unkF0);
    func_8028774C(this->animctrl, this->unkEC);
    animctrl_setSubRange(this->animctrl, this->unkF8, this->unkFC);
    func_802875AC(this->animctrl, D_80378E20, 0x8fd);
    func_80287800(this->animctrl, this->sound_timer);
}

void actor_copy(Actor *dst, Actor *src){
    dst->marker = src->marker;
    dst->animctrl = src->animctrl;
    dst->unk44_4 = src->unk44_4;
    dst->unk148 = src->unk148;
    dst->unk14C = src->unk14C;
    dst->unk150 = src->unk150;
    func_80254608(src, dst, sizeof(Actor));
}


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/actors_appendToSavestate.s")
/*void *actors_appendToSavestate(void * begin, u32 end){
    void *sp3C = begin;
    Actor* s0;
    Actor* s1;
    u32 sp30; //SavedActorDataSize
    u32 sp2C; //SavedActorDataOffset
    u32 tmp;
   
    if(D_8036E560){
        sp30 = 0;
        for(s1 = (u32)D_8036E560 + 8; (u32)s1 < (u32)D_8036E560 + D_8036E560->cnt*sizeof(Actor) + 8; s1++){
            if( s1->marker
                && s1->unk10_1 == 1
                && s1->despawn_flag == 0
                && s1->unk40 == 0
            ){
                sp30++;
            }
        }
        sp2C = end - (u32)sp3C;
        sp3C = realloc(sp3C, sp2C + sizeof(u32) + sp30*sizeof(Actor));

        end = (u32)sp3C + sp2C;
        *(u32 *)end = sp30;
        s0 = (Actor *)((u8*)end + sizeof(u32));
        for(s1 = D_8036E560->data; s1 < &D_8036E560->data[D_8036E560->cnt]; s1++){
            if( s1->marker
                && s1->unk10_1 == 1
                && s1->despawn_flag == 0
                && s1->unk40 == 0
            ){
                func_80254608(s0, s1, 0x180);
                s0->unk40 = 0;
                s0->unk138_28 = 1;
                s0->unk150 = NULL;
                s0->unk14C = NULL;
                s0->unk148 = NULL;
                s0->unk16C_4 = 0;
                s0->unk44_31 = 0;
                s0->unk104 = NULL;
                s0->unk100 = NULL;
                s0->unk158 = NULL;
                s0->unk15C = NULL;
                s0->unk138_19 = s1->marker->unk14_20;
                s0->unk108 = s1->marker->unkC;
                s0->unk10C = s1->marker->unk10;
                s0->unk134 = s1->marker->unk1C;
                s0->unk160 = s1->marker->unk54;
                s0->unk168 = s1->marker->unk58;
                s0->unk13C = s1->marker->unk30;
                s0->unk16C_31 = s1->marker->unk5C;
                s0->unkF4_26 = s1->marker->unk2C_1;
                s0->unkF4_25 = s1->marker->collidable;
                s0->unkF4_28 = s1->marker->propPtr->unk8_3;
                s0->unkF4_27 = s1->marker->propPtr->unk8_2;
                //80329F94
                if(s0->animctrl){
                    s0->unk58_16 = animctrl_getIndex(s0->animctrl);
                    s0->unk38_3 = animctrl_getPlaybackType(s0->animctrl);
                    s0->unk78_1 = animctrl_isPlayedForwards(s0->animctrl);
                    s0->unk78_0 = animctrl_isSmoothTransistion(s0->animctrl);
                    s0->unkF0 = animctrl_getDuration(s0->animctrl);
                    s0->unkEC = func_802877D8(s0->animctrl);
                    animctrl_getSubRange(s0->animctrl, &s0->unkF8, &s0->unkFC);
                }
                s0->animctrl = NULL;
                s0->marker = NULL;
                s0++;
            }
        }
    }
    return sp3C;
}//*/

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
