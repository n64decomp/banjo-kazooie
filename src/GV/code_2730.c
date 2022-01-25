#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802EF3A8(ParticleEmitter *, Gfx **, Mtx **, Vtx**);

typedef struct {
    f32 unk0[3];
    ParticleEmitter *unkC;
    ParticleEmitter *unk10;
    f32 unk14;
}ActorLocal_GV_2730;

void func_80388DC8(Actor *this);
Actor *func_80388C64(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorInfo D_80390D60 = { 0xBE, 0x130, 0x3E4, 
    0, NULL, 
    func_80388DC8, func_80326224, func_80388C64, 
    { 0x0, 0x0}, 0x533, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

f32 D_80390D84[3] = {5644.0f, 2930.0f, -3258.0f};

/*.bss */
u8 D_80391A60;

/* .code */
void func_80388B20(Actor *this, s32 next_state){
    ActorLocal_GV_2730 *local = (ActorLocal_GV_2730 *)&this->local;

    this->state = next_state;
    local->unk14 = 0.0f;
    D_80391A60 = FALSE;
    if(this->state == 2){
        this->marker->propPtr->unk8_3 = FALSE;
        local->unk14 = 2.6f;
        D_80391A60 = TRUE;
        func_8028F428(2, this->marker);
        FUNC_8030E624(SFX_9B_BOULDER_BREAKING_1, 0x119, 0x132);
        FUNC_8030E624(SFX_9B_BOULDER_BREAKING_1, 0x119, 0x1ff);
        FUNC_8030E624(SFX_9B_BOULDER_BREAKING_1, 0x119, 0x2CC);
        FUNC_8030E624(SFX_9B_BOULDER_BREAKING_1, 0x119, 0x398);
        func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
        func_802F066C(local->unkC, local->unk0);
        particleEmitter_emitN(local->unkC, 10);
        func_802F053C(local->unk10, local->unk0);
        particleEmitter_emitN(local->unk10, 10);

    }
}

void func_80388C24(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    if(this->state == 1)
        func_80388B20(this, 2);
}

Actor *func_80388C64(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(this_marker);
    ActorLocal_GV_2730 *local = (ActorLocal_GV_2730 *)&this->local;
    f32 sp3C[3];

    func_802EF3A8(local->unkC, gfx, mtx, vtx);
    func_802EF3A8(local->unk10, gfx, mtx, vtx);
    if(this->state == 0 || this->state == 2)
        return this;

    sp3C[0] = this->pitch;
    sp3C[1] = this->yaw;
    sp3C[2] = this->roll;
    func_8033A2D4(func_803253A0, this);
    func_8033A450(func_80329934());
    func_803391A4(gfx, mtx, this->position, sp3C, 1.0f, NULL,func_80330B1C(this_marker));
    func_8034A174(func_80329934(), 5, local->unk0);
    return this;
    
}

s32 func_80388D78(void){
    return D_80391A60;
}

void func_80388D84(Actor *this){
    ActorLocal_GV_2730 *local = (ActorLocal_GV_2730 *)&this->local;
    func_80388B20(this, 0);
    func_802EF684(local->unkC);
    func_802EF684(local->unk10);
}

void func_80388DC8(Actor *this){
    ActorMarker *sp34 = this->marker;
    ActorLocal_GV_2730 *local = (ActorLocal_GV_2730 *)&this->local;
    f32 sp2C;
    Actor *sp28;
    f32 sp24 = time_getDelta();

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        sp34->unk30 = func_80388D84;
        sp34->propPtr->unk8_3 = TRUE;
        func_803300A8(this->marker, NULL, NULL, func_80388C24);
        local->unkC = particleEmitter_new(20);
        local->unk10 = particleEmitter_new(30);
        D_80391A60 = FALSE;
        sp28 = func_80326D68(this->position, ACTOR_12E_GOBI_1, -1, &sp2C);
        if(sp28){
            this->position_x = sp28->position_x;
            this->position_y = sp28->position_y;
            this->position_z = sp28->position_z;
        }
        func_80388B20(this, 1);
        if(jiggyscore_isSpawned(JIGGY_44_GV_GOBI_1) && !func_803203FC(1)){
            marker_despawn(this->marker);
        }
    }
    else{//L80388ED0
        particleEmitter_update(local->unkC);
        particleEmitter_update(local->unk10);
        if(func_8025773C(&local->unk14, sp24)){
            jiggySpawn(JIGGY_44_GV_GOBI_1, D_80390D84);
            func_802BB3DC(0, 60.0f, 0.65f);
        }
        if(this->state == 2){
            if(func_802EF648(local->unkC) && func_802EF648(local->unk10)){
                marker_despawn(sp34);
            }
        }
    }
}
