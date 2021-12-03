#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern ActorMarker *func_8038A4E8(Actor*, f32);
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

void func_8038E844(Actor *this);

/* .data */
ActorInfo D_80391AD0 = {
    0x284, 0x3AB, 0x546, 0x1, NULL,
    func_8038E844, func_80326224, func_80325888,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

/* .code */
void func_8038E780(ActorMarker *arg0, s32 arg1) {
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
    ActorLocal_fight_8390 *temp_v0 = (ActorLocal_fight_8390 *)&arg0->local;

    if ((u8)arg0->unk44_31) {
        func_8030DA44(arg0->unk44_31);
        arg0->unk44_31 = 0;
    }
    if (temp_v0->unk10 != 0) {
        func_8030DA44(temp_v0->unk10);
        temp_v0->unk10 = (u8)0;
    }
}

void func_8038E844(Actor *this){
    ActorLocal_fight_8390 *local = (ActorLocal_fight_8390 *)&this->local;
    f32 sp38 = time_getDelta();
    ActorMarker *temp_v0;

    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        func_803300A8(this->marker, NULL, func_8038E780, NULL);
        func_803300D8(this->marker, func_8038E7EC);
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOn(this);
        local->unk0 = 0;
        local->unk4 = 1;
        this->unk124_9 = 0;
        this->scale = 0.0f;
        this->unk44_31 = func_8030ED2C(SFX_142_GRUNTY_LAUGH_3, 3);
        func_8030DB04(this->unk44_31, 32000, &this->position, 4000.0f, 12000.0f);
        func_8030DBB4(this->unk44_31, 1.0f);
        local->unk10 = func_8030ED2C(0x415, 3);
        func_8030DB04(local->unk10, 32000, &this->position, 4000.0f, 12000.0f);
        func_8030DBB4(local->unk10, 1.0f);
        func_8030E8B4(0x665f4416, &this->position, 0x61a82710);
    }//L8038E97C
    temp_v0 = func_8038A4E8(this, 600.0f);
    if(temp_v0){
        if(temp_v0->unk14_20 == 0x285){
            marker_despawn(this->marker);
            func_8038C100();
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
