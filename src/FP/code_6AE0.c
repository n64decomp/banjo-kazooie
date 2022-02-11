#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80324CD8(f32);
extern Actor *func_8032813C(enum actor_e, f32[3], s32);

Actor *func_8038CED0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038D6C8(Actor *this);

/* .data */
extern ActorAnimationInfo D_803920C0[];

extern ActorInfo D_803920E8 = { 0x204, 0x336, 0x442,
    0x1, D_803920C0,
    func_8038D6C8, func_80326224, func_8038CED0,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};
extern f32 D_80392354[3];
extern f32 D_80392360[3];
extern enum actor_e D_8039236C[];
extern f32 D_8039237C[3];

/* .rodata */
extern f32 D_80392E00;
extern f32 D_80392E04;
extern f32 D_80392E08;
extern f32 D_80392E0C;


// 3FD9999A 3FD9999A 40133333 3DCCCCCD
/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038CED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038CF54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D01C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D0A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D208.s")

void func_8038D294(ActorMarker *marker);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D294.s")

void func_8038D324(Actor *this);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D324.s")

void func_8038D3B0(UNK_TYPE(s32) arg0){
    item_set(ITEM_6_HOURGLASS, FALSE);
}

void func_8038D3D8(void){
    comusic_8025AB44(COMUSIC_68_TWINKLY_MINIGAME, 0, 4000);
    func_8025AABC(COMUSIC_68_TWINKLY_MINIGAME);
    func_8025A58C(-1, 4000);
    func_8024BD08(1);
}

#ifndef NONMATCHING
void func_8038D41C(ActorMarker *marker);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D41C.s")
#else
void func_8038D41C(ActorMarker *marker){
    ActorMarker *_marker = reinterpret_cast(ActorMarker *, marker);
    Actor *actor;
    
    actor = func_8032813C(ACTOR_337_TWINKLY_MUNCHER, D_80392354, 170);
    actor->unk100 = _marker;
    actor = func_8032813C(ACTOR_337_TWINKLY_MUNCHER, D_80392360, 170);
    actor->unk100 = _marker;
}
#endif

#ifndef NONMATCHING
// matches, but symbol D_8039236C conflict with `lair` overlay 
// need .data defined
void func_8038D474(ActorMarker *marker);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D474.s")
#else
void func_8038D474(ActorMarker *marker){
    Actor *actor  = marker_getActor(reinterpret_cast(ActorMarker*, marker));
    Actor *child;
    s32 pad;

    if((s32)actor->unk1C[0] >= 3){
        actor->unk1C[0] = -1.0f;
    }
    actor->unk1C[0] += 1.0;
    child = spawn_child_actor(D_8039236C[(s32)actor->unk1C[0]], &actor);
    child->unk100 = actor->marker;
}
#endif


void func_8038D51C(Actor *marker){
    Actor *this = marker_getActor(marker);
    
    item_set(ITEM_6_HOURGLASS, FALSE);
    func_80320004(BKPROG_13, TRUE);
    FUNC_8030E624(SFX_416, 1000, 0x332);
    func_8028F8F8(7, 0);
    this->unk1C[1] = 1.0f;
    func_80324E88(1.7f);
    func_80324E38(1.7f, 0);
    timedFunc_set_1(2.3f, (TFQM1)func_8038D294, (s32)this->marker);
    this->velocity[1] = 1.0f;
}

void func_8038D5C8(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);

    if(this->state == 1 || this->state == 2){
        actor_collisionOff(this);
        timed_setCameraToNode(0.0f, 0xa);
        func_80324CD8(0.1f);
        func_8028F784(1);
        func_8028F490(D_8039237C);
        func_8028F8F8(7, 1);
        this->unk1C[1] = 0.0f;
        func_8025A6EC(COMUSIC_68_TWINKLY_MINIGAME, 25000);
        func_8025A58C(0, 4000);
        func_8024BD08(0);
        this->unk1C[2] = 428571.0f;
        func_8025AEA0(0x68, (s32)this->unk1C[2]);
        func_80328B8C(this, 3, 0.001f, 1);
        actor_playAnimationOnce(this);
        this->velocity[0] = 1.0f;
    }//L8038D6B8
}

void func_8038D6C8(Actor *this){
    f32 sp24;
    bool sp20;
    
    sp24 = time_getDelta();
    mapSpecificFlags_set(0xd, (this->state != 1 && this->state != 2) ? TRUE : FALSE);
    
    if(func_8038BFA0() || func_8031FF1C(BKPROG_13)){
        this->marker->propPtr->unk8_3 = FALSE;
        actor_collisionOff(this);
        func_8028F8F8(7, FALSE);
        return;
    }


    this->marker->propPtr->unk8_3 = TRUE;
    actor_collisionOn(this);

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        func_803300D8(this->marker, func_8038D3B0);
        marker_setCollisionScripts(this->marker, NULL, func_8038D5C8, NULL);
        this->unk38_31 = 0;
        this->unk1C[1] = 0.0f;
        this->velocity[0] = 0.0f;
        this->velocity[1] = 0.0f;
        this->unk1C[0] = -1.0f;
        func_8028F8F8(7, FALSE);
        if(func_803203FC(0xC1) && func_8031B4F4() == -1){
            func_80328B8C(this, 3, 0.001f, 1);
            actor_playAnimationOnce(this);
            this->velocity[0] = 1.0f;
        }
    }//L8038D844

    if(func_803203FC(0xc1)){
        this->velocity[0] = 1.0f;
    }

    switch (this->state)
    {
    case 1: //L8038D89C
        if(!func_80329530(this, 800))
            break;

        if(!(func_8023DB5C() & 1))
            func_80328B8C(this, 2, 0.001f, 1);
        else
            func_80328B8C(this, 2, 0.999f, 0);

        actor_playAnimationOnce(this);
        this->velocity[2] = randf2(1.4f, 2.0f);

        break;
    
    case 2: //L8038D91C
        sp20 = animctrl_isPlayedForwards(this->animctrl);
        animctrl_setDuration(this->animctrl, this->velocity[2]);
        if( ( sp20 == TRUE && actor_animationIsAt(this, 0.999f) )
            || ( sp20 == FALSE && actor_animationIsAt(this, 0.001f) )
        ){
            func_80328B8C(this, 1, 0.001f, 0);
            actor_playAnimationOnce(this);
            break;
        }

        if( actor_animationIsAt(this, 0.02f)
            || actor_animationIsAt(this, 0.15f)
            || actor_animationIsAt(this, 0.28f)
            || actor_animationIsAt(this, 0.63f)
            || actor_animationIsAt(this, 0.81f)
        ){
            FUNC_8030E8B4(SFX_98_DEAF_THUD, 1000, 0x3ff, this->position, 400, 2000);
        }
        break;

    case 3: //L8038DA24
        if(actor_animationIsAt(this, 0.3f))
            func_8038D324(this);
        
        if(actor_animationIsAt(this, 0.999f))
            func_802C3C88(func_8038D474, this->marker);
        
        if(this->velocity[0] != 0.0f)
            break;

        func_80324E88(0.0f);
        func_8028F784(0);
        func_80328B8C(this, 4, 0.999f, 1);
        actor_playAnimationOnce(this);
        item_set(ITEM_0_HOURGLASS_TIMER, 80*60 - 1);
        item_set(ITEM_6_HOURGLASS, TRUE);
        this->unk38_31 = 0xA;
        item_set(ITEM_24_TWINKLY_SCORE, this->unk38_31);
        func_802C3C88(func_8038D41C, this->marker);
        this->unk60 = 0.0f;
        func_80347A14(0);
        func_802FAD64(ITEM_14_HEALTH);
        break;
    
    case 4: //L8038DB18
        this->unk1C[2] += (sp24*-195238.0f)/80.0f;
        if(this->unk1C[2] < 233333.0f)
            this->unk1C[2] = 233333.0f;

        func_8025AEA0(COMUSIC_68_TWINKLY_MINIGAME, (s32)this->unk1C[2]);
        if(item_getCount(ITEM_24_TWINKLY_SCORE) == 0){
            func_80328B8C(this, 1, 0.001f, 1);
            func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
            func_8038D3D8();
            func_80324E38(0.0f, 3);
            timedFunc_set_1(1.3f, (TFQM1)func_8038D51C, this->marker);
            timed_setCameraToNode(0.9f, 0xC);
            item_set(ITEM_24_TWINKLY_SCORE, this->unk38_31);
            func_80347A14(1);
            break;
        }

        if(item_empty(ITEM_6_HOURGLASS)){
            func_80328B8C(this, 1, 0.001f, 0);
            actor_playAnimationOnce(this);
            this->unk38_31 = 0;
            item_set(ITEM_6_HOURGLASS, FALSE);
            func_8025A6EC(COMUSIC_3C_MINIGAME_LOSS, 28000);
            func_8028F8F8(7, FALSE);
            this->unk1C[1] = 1.0f;
            func_8038D3D8();
            func_80347A14(1);
            break;
        }


        if(0.96 < func_802877D8(this->animctrl)){
            if(this->unk60 <= 0.0){
                func_802C3C88(func_8038D474, this->marker);
                this->unk60 = 2.9f;
            }
            else{
                this->unk60 -= sp24;
            }
            item_set(ITEM_24_TWINKLY_SCORE, this->unk38_31);
        }
        break;
    }
}

bool func_8038DD14(void){
    return mapSpecificFlags_get(0xD);
}

bool func_8038DD34(ActorMarker *marker){
    Actor *this = marker_getActor(marker);
    if(func_80329530(this, 800))
        return TRUE;
    return FALSE;
}
