#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "fight.h"

extern ActorMarker *chfinalboss_findCollidingJinjo(Actor*, f32);
void func_80386654(f32 arg0, f32 (*arg1)[4], f32 (*arg2)[4]);

typedef struct {
    s32 unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10;
} ActorLocal_fight_8390;

void chspellbarrier_update(Actor *this);

/* .data */
ActorInfo chSpellBarrier = {
    MARKER_284_GRUNTY_SPELL_BARRIER, ACTOR_3AB_GRUNTY_SPELL_BARRIER, ASSET_546_MODEL_GRUNTY_SPELL_BARRIER,
    0x1, NULL,
    chspellbarrier_update, func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

/* .code */
void func_8038E780(ActorMarker *arg0, ActorMarker *arg1) {
    Actor *sp1C;
    ActorLocal_fight_8390 *sp18;

    sp1C = marker_getActor(arg0);
    sp18 = (ActorLocal_fight_8390 *) &sp1C->local;
    sp18->unk0 = 0xFF;
    sp18->unk4 = 0;
    if (func_8030E3FC(sp18->unk10) == 0) {
        func_8030E2C4(sp18->unk10);
    }
    if (func_8030E3FC(sp1C->unk44_31) == 0) {
        func_8030E2C4(sp1C->unk44_31);
    }
}

void func_8038E7EC(Actor *arg0) {
    ActorLocal_fight_8390 *local = (ActorLocal_fight_8390 *)&arg0->local;

    if ((u8)arg0->unk44_31) {
        func_8030DA44(arg0->unk44_31);
        arg0->unk44_31 = 0;
    }
    if (local->unk10 != 0) {
        func_8030DA44(local->unk10);
        local->unk10 = (u8)0;
    }
}

void chspellbarrier_update(Actor *this){
    ActorLocal_fight_8390 *local = (ActorLocal_fight_8390 *)&this->local;
    f32 sp38 = time_getDelta();
    ActorMarker *jinjo_marker;

    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        marker_setCollisionScripts(this->marker, NULL, func_8038E780, NULL);
        marker_setFreeMethod(this->marker, func_8038E7EC);
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOn(this);
        local->unk0 = 0;
        local->unk4 = 1;
        this->depth_mode = 0;
        this->scale = 0.0f;
        this->unk44_31 = func_8030ED2C(SFX_142_GRUNTY_LAUGH_3, 3);
        func_8030DB04(this->unk44_31, 32000, this->position, 4000.0f, 12000.0f);
        func_8030DBB4(this->unk44_31, 1.0f);
        local->unk10 = func_8030ED2C(0x415, 3);
        func_8030DB04(local->unk10, 32000, this->position, 4000.0f, 12000.0f);
        func_8030DBB4(local->unk10, 1.0f);
        FUNC_8030E8B4(SFX_416, 0.8f, 32000, this->position, 10000, 25000);
    }//L8038E97C
    jinjo_marker = chfinalboss_findCollidingJinjo(this, 600.0f);
    if(jinjo_marker){
        if(jinjo_marker->unk14_20 == MARKER_285_JINJONATOR){
            marker_despawn(this->marker);
            chfinalboss_spellBarrierInactive();
            return;
        }
        else{
            local->unk0 = 0;
            local->unk4 = 1;
            actor_setOpacity(this, 0);
            this->unk58_0 = 0;
            this->unk60 =  2.0f;
        }
    } //L8038E9F4
    if(this->state == 1){
        this->yaw += 30.0f*sp38;
        if(this->scale < 1.0){
            this->scale = MIN(1.0, this->scale + ((f64)sp38 + (f64)sp38));
        }//L8038EA68

        if(0.0 < this->unk60){
            this->unk58_0 = 0;
            this->unk60 -=  sp38;
        }
        else{ //L8038EAA4
            this->unk58_0 = 1;
            if(local->unk4){
                local->unk0 = MIN(0x64, local->unk0 + (s32)(60.0f*sp38));
                if(local->unk0 >= 0x64){
                    local->unk0 = 0x64;
                    local->unk4 = 0;
                }
            }
            else{//L8038EB20
                local->unk0 = MAX(0, local->unk0 - (s32)(60.0f*sp38));
                if(local->unk0 <= 0){
                    local->unk0 = 0;
                    local->unk4 = 1;
                    this->unk60 = 0.25f;
                }
            }//L8038EB74
            actor_setOpacity(this, local->unk0);
        }
    }
    //L8038EB80
}
