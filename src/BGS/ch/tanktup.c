#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

void func_80324E88(f32);

void timedFunc_set_2(f32, void(*)(s32, s32), s32, s32);

void func_8028E668(f32[3], f32, f32, f32);
extern void func_802C3E10(void(*arg0)(void), ActorMarker *, s32, s32);

void func_8038F6A4(Actor *);

/* .data */
ActorAnimationInfo D_80390C20[] = {
    {0, 0.0f},
    {0x101, 7.5f},
    {0x102, 1.75f},
    {0x107, 1.75f}
};

ActorInfo D_80390C40 = {0x6C, 0xE8, 0x3EE, 0x01, D_80390C20,
    func_8038F6A4, func_80326224, func_80325888,
    0, 0x80, 0.0f, 0
};

/* .code */
void func_8038F470(ActorMarker *this, s32 arg1, s32 arg2){
    Actor* thisActor;
    f32 pad;
    Actor* sp24;
    f32 sp18[3];

    thisActor = marker_getActor(this);
    sp18[0] = thisActor->position_x;
    sp18[1] = thisActor->position_y;
    sp18[2] = thisActor->position_z;
    sp18[1] += 50.0f;

    sp24 = func_8032813C(arg2 + 0xe9, sp18, (s32)thisActor->yaw);
    func_80328B8C(sp24, arg1 + 1, 0, -1);
    sp24->unk10_12 = arg2;
}

void func_8038F51C(Actor *this){
    Actor * spawnPtr;
    spawnPtr = func_80326D68(this->position, 0xe8, -1, 0);
    spawnPtr->tanktup.unk0[this->unk10_12] = 1;
    spawnPtr->tanktup.unk10 = 1;
}

s32 func_8038F570(s16 *arg0){
    f32 pos[3];
    Actor * spawnPtr;

    pos[0] = (f32)arg0[0];
    pos[1] = (f32)arg0[1];
    pos[2] = (f32)arg0[2];
    spawnPtr = func_80326D68(pos, 0xe8, -1, 0);
    return spawnPtr->state == 3;


}

void func_8038F5E4(s32 arg0, s32 arg1, s32 arg2){
    func_80324E88(0.0f);
}

void func_8038F610(Actor *this) {
    f32 sp24[3];

    func_8034A174(this->marker->unk44, 8, &sp24);
    if (func_80258368(&sp24) != 0) {
        func_8028E668(&sp24, 200.0f, -600.0f, 300.0f);
    }
    func_8034A174(this->marker->unk44, 7, &sp24);
    if (func_80258368(&sp24) != 0) {
        func_8028E668(&sp24, 200.0f, -600.0f, 200.0f);
    }
}

extern f32 D_803911B0;
extern f32 D_803911B4;

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/tanktup/func_8038F6A4.s")
#else
void func_8038F6A4(Actor *this) {
    ActorLocal_TanktupBody * local = (ActorLocal_TanktupBody *)&this->local;
    f32 sp48[3];
    s32 sp44;
    f32 sp34[3];
    Prop *temp_v0;

    if(!this->initialized){
        temp_v0 = func_80304C38(0x32B, this);
        if (temp_v0 == NULL) {
            local->unk18[0] = D_803911B0;
            local->unk18[1] = 100.0f;
            local->unk18[2] = D_803911B4;
        } else {
            func_80304D68(temp_v0, local->unk18);
        }
        this->unk138_24 = FALSE;
        this->initialized = TRUE;
    }

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        actor_collisionOff(this);
        this->scale = 1.0f;
        for(sp44 = 0; sp44 < 4; sp44++){
            if (local->unk0[sp44] == 0) {
                func_802C3E10(&func_8038F470, this->marker, local->unk0[sp44], sp44);
            }
        }
    }
    switch(this->state){
        case 1:
            func_8038F610(this);
            player_getPosition(&sp48);
            if (!this->unk138_24) {
                if( func_80256064(local->unk18, &sp48) < 250.0f
                    && func_80256064(local->unk18, &sp48) > 80.0f
                    && !func_8028ECAC()
                    && player_getTransformation() == TRANSFORM_1_BANJO
                ) {
                    func_80311480(0xC7E, 0, NULL, NULL, NULL, NULL);
                    this->unk138_24 = TRUE;
                }
            }
            if (local->unk10) {
                func_80328B8C(this, 2, 0.0f, -1);
                local->unk10 = 0;
                local->unk14 = TRUE;
                for(sp44 = 0; sp44 < 4; sp44++){
                    if(local->unk0[sp44] == 0){
                        local->unk14 = FALSE;
                    }
                }
                if(!this->unk138_23 && !local->unk14){
                    if(func_80311480(0xC80, 0, NULL, NULL, NULL, NULL))
                        this->unk138_23 = TRUE;
                }
            }
            break;

        case 2:
            func_8038F610(this);
            if (actor_animationIsAt(this, 0.6f) && local->unk14) {
                func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
                func_8028F94C(2, local->unk18);
            }
            if (actor_animationIsAt(this, 0.99f)) {
                if (!local->unk14) {
                    func_80328B8C(this, 1, 0.0f, -1);
                }
                else{
                    func_80328B8C(this, 3, 0.0f, -1);
                    actor_playAnimationOnce(this);
                }
            }
            break;

        case 3:
            if (actor_animationIsAt(this, 0.1f) != 0) {
                timed_setCameraToNode(0.0f, 0xD);
            }
            if (actor_animationIsAt(this, 0.55f) != 0) {
                func_8030E624(0x797FF885U);
            }
            if (actor_animationIsAt(this, 0.4f) != 0) {
                func_8034A174(this->marker->unk44, 6, sp34);
                func_802C8F70(this->yaw);
                sp34[1] -= 125.0f;
                jiggySpawn(JIGGY_26_BGS_TANKTUP, sp34);
            }
            if (actor_animationIsAt(this, 0.9f) != 0) {
                func_8028F918(0);
                if (jiggyscore_isCollected(JIGGY_26_BGS_TANKTUP) == 0) {
                    func_80311480(0xC7F, 0xF, this->position, this->marker, func_8038F5E4, NULL);
                }
                else{
                    func_8038F5E4(this->marker, 0xC7F, -1);
                }
            }
            break;
    }
}
#endif


