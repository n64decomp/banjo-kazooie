#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8 unk0;
}ActorLocal_fight_6E90;

void func_8038D568(Actor *this);

/* .data */
ActorInfo D_80391990 = {
    0x27A, 0x3A2, 0x543, 0x1, NULL,
    func_8038D568, func_80326224, func_80325888,
    {0, 0}, 0x800, 0.0f, {0,0,0,0}
};

s32 D_803919B4[3] = {0xC8, 0xC8, 0xA0};

struct31s D_803919C0 = {
    {1.0f, 1.0f},
    {1.7f, 2.7f},
    {0.0f, 0.05f},
    {2.6f, 3.4f},
    0.0f, 0.1f
};

/* .code */
void func_8038D280(ActorMarker *arg0) {
    Actor *sp1C = marker_getActor(arg0);
    Actor *temp_v0 = spawn_child_actor(0x3A1, &sp1C);

    temp_v0->unkF4_8 = sp1C->unkF4_8;
    temp_v0->position_y = temp_v0->position_y + 172.0f;
    sp1C->unk100 = temp_v0->marker;
}

void func_8038D2EC(f32 (*arg0)[3], s32 arg1) {
    ParticleEmitter *temp_v0 = func_802F0BD0(arg1);
    
    particleEmitter_setSprite(temp_v0, ASSET_70E_SPRITE_SMOKE_2);
    func_802EFFA8(temp_v0, &D_803919B4);
    particleEmitter_setStartingFrameRange(temp_v0, 0, 7);
    particleEmitter_setPosition(temp_v0, arg0);
    particleEmitter_setParticleSpawnPositionRange(temp_v0, -90.0f, 0.0f, -80.0f, 80.0f, 60.0f, 80.0f);
    particleEmitter_setParticleVelocityRange(temp_v0, -170.0f, 0.0f, -170.0f, 170.0f, 100.0f, 170.0f);
    func_802EFB98(temp_v0, &D_803919C0);
    particleEmitter_emitN(temp_v0, arg1);
}

void func_8038D3DC(Actor* this, s32 arg1, f32 arg2, f32 arg3, f32 arg4){
    s32 tmp = func_8034C2C4(this->marker, arg1);
    
    if(tmp){
        func_8034DE60(tmp, arg2, arg3, arg4, 1);
    }
}

void func_8038D428(ActorMarker *arg0, s32 arg1) {
    Actor *temp_v0;
    Actor *s0;

    temp_v0 = marker_getActor(arg0);
    if (temp_v0->state != 3) {
        func_8025A70C(COMUSIC_2B_DING_B);
        temp_v0->unk38_31++;
        if (temp_v0->unk38_31 >= 3) {
            func_80328A84(temp_v0, 3);
            func_8038DE98(temp_v0->unk100);
            func_8038D3DC(temp_v0, 0x19A, -100.0f, 0.0f, 1.2f);
            func_80324D54(1.2f, SFX_90_SWITCH_PRESS, 1.0f, 0x7D00, &temp_v0->position, 1000.0f, 2000.0f);
        }
    }
}

void func_8038D510(Actor *arg0) {
    ActorLocal_fight_6E90 *sp18 = (ActorLocal_fight_6E90 *)&arg0->local;

    if ((u8)arg0->unk44_31 != 0) {
        func_8030DA44(arg0->unk44_31);
        arg0->unk44_31 = 0;
    }
    if (sp18->unk0 != 0) {
        func_8030DA44(sp18->unk0);
        sp18->unk0 = 0;
    }
}

void func_8038D568(Actor *this){
    ActorLocal_fight_6E90 *local = (ActorLocal_fight_6E90 *)&this->local;

    f32 sp48 = time_getDelta();
    u32 sp44 = func_8023DB5C() & 0xF;
    Actor *other; //sp40
    f32 sp3C;
    f32 sp30[3];

    this->unkF4_29 = 0;
    func_80330B1C(this->marker);

    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        func_803300A8(this->marker, NULL, func_8038D428, NULL);
        func_803300D8(this->marker, func_8038D510);
        this->marker->propPtr->unk8_3 = 1;
        actor_collisionOn(this);
        this->unk38_31 = 0;
        this->unk44_31 = func_8030D90C();
        func_8030DA80(this->unk44_31, 0x3f9);
        func_8030DD14(this->unk44_31, 2);
        func_8030DBB4(this->unk44_31, 1.4f);
        func_8030DABC(this->unk44_31, 32000);
        
        local->unk0 = func_8030D90C();
        func_8030DA80(local->unk0, 0x405);
        func_8030DD14(local->unk0, 2);
        func_8030DBB4(local->unk0, 0.7f);
        func_8030DABC(local->unk0, 12000);
        func_8030E624(0x4cb38bf6);
        func_8038D3DC(this, 0x19a, 0.0f, -200.0f, 0.0f);
        TUPLE_COPY(this->unk1C, this->position);
        this->position_y = -400.0f;
        if(0.0f != this->unk60)
            this->velocity_y = 400.0f/this->unk60;
        else
            this->velocity_y = 100.0f;
        
        func_802BB3DC(0, 8.0f, 0.92f);
        func_802C3F04(func_802C4140, 0x3ad, *(s32*)&this->unk1C[0], *(s32*)&this->unk1C[1], *(s32*)&this->unk1C[2]);
        func_8038D2EC(&this->unk1C, 0x10);
        func_802C3C88(func_8038D280, this->marker);
    }
    else{//L8038D774
        if(this->state == 1){
            other = marker_getActor(this->unk100);
            sp3C = this->velocity_y * sp48;
            if(this->position_y + sp3C < this->unk1C[1]){
                if(!func_8031FF1C(0xd2) || this->unkF4_8 == 1){
                    func_8030E2C4(this->unk44_31);
                    func_8030E2C4(local->unk0);
                }
                sp30[0] = (sp44 & 1) ? 3.0f : -3.0f; 
                sp30[1] = sp3C;
                sp30[2] = (sp44 & 2) ? 3.0f : -3.0f; 

                this->position_x = this->unk1C[0];
                this->position_z = this->unk1C[2];
                this->position_x = sp30[0] + this->position_x;
                this->position_y = sp30[1] + this->position_y;
                this->position_z = sp30[2] + this->position_z;

                other->position_x = this->unk1C[0];
                other->position_z = this->unk1C[2];
                other->position_x = sp30[0] + other->position_x;
                other->position_y = sp30[1] + other->position_y;
                other->position_z = sp30[2] + other->position_z;

            }
            else{//L8038D8E0
                func_80328A84(this, 2);
                func_8030DA44(this->unk44_31);
                this->unk44_31 = 0;
                func_8030DA44(local->unk0);
                local->unk0 = 0;
                TUPLE_COPY(this->position, this->unk1C);
                TUPLE_COPY(other->position, this->unk1C);
                other->position_y += 172.0f;
            }
        }
    }//L8038D954
}