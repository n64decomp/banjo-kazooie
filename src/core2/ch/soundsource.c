#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802D07C8(Actor *this);

typedef struct{
    s32 unk0; //enum sfx_e
    s16 unk4;
    s16 unk6;
    s32 unk8;
    f32 unkC;
    f32 unk10;
}struct49570s;

typedef struct{
    u8 unk0;
}ActorLocal_Core2_49570;

/* .data */
struct49570s D_80367340[] = {
    {0x03EC,                       400, 3200,    -1, -1.0f, -1.0f},
    {SFX_128_FIRE_CRACKING,        400, 2600,    -1, -1.0f, -1.0f},
    {SFX_12B_BOILING_AND_BUBBLING, 100, 1200, 14000, -1.0f,  2.5f},
    {-1, 0, 0, 0, 0.0f, 0.0f},
};

ActorInfo D_80367390 = {0x1A8, ACTOR_28B_SOUND_SOURCE, 0, 
    0, NULL, 
    func_802D07C8, NULL, func_80325340,
    0, 0, 0.0f, 0
}; 

/* .code */
void func_802D0500(Actor *this){
    ActorLocal_Core2_49570 *local = (ActorLocal_Core2_49570 *)this->local;
    if(D_80367340[(s32)this->yaw].unk8 != -1){
        if(this->unk1C[0] == this->unk1C[1])
            sfxsource_setSampleRate(local->unk0, D_80367340[(s32)this->yaw].unk8);
        else{
            sfxsource_setSampleRate(local->unk0, (s32)((D_80367340[(s32)this->yaw].unk8/this->unk1C[1])*this->unk1C[0]));

        }
    }
}

void func_802D05A0(Actor *this, s32 next_state){
    ActorLocal_Core2_49570 *local = (ActorLocal_Core2_49570 *)this->local;
    if(this->state == 2 && local->unk0){
        func_8030DA44(local->unk0);
        local->unk0 = 0;
    }
    if(next_state == 2){
        this->unk1C[0] = 0.0f;
        this->unk1C[1] = 0.0f;
        if(-1.0f != D_80367340[(s32)this->yaw].unk10){
            this->unk1C[1] = D_80367340[(s32)this->yaw].unk10;
        }
        local->unk0 = func_8030D90C();
        sfxsource_setSfxId(local->unk0, D_80367340[(s32)this->yaw].unk0);
        func_8030DD14(local->unk0, 3);
        func_8030DFF0(local->unk0, 1);
        sfxsource_set_position(local->unk0, this->position);
        sfxsource_set_fade_distances(local->unk0, D_80367340[(s32)this->yaw].unk4*this->scale, D_80367340[(s32)this->yaw].unk6*this->scale);
        func_8030DFB4(local->unk0, 1);
        func_802D0500(this);
        if(-1.0f != D_80367340[(s32)this->yaw].unkC)
            func_8030DBB4(local->unk0, D_80367340[(s32)this->yaw].unkC);
        func_8030E2C4(local->unk0);
    }//L802D0780
    this->state = next_state;
}

void func_802D07A8(Actor *this){
    func_802D05A0(this, 0);
}

void func_802D07C8(Actor *this){
    f32 sp2C[3];
    f32 sp28;
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        this->marker->actorFreeFunc = func_802D07A8;
        func_802D05A0(this, 1);
    }
    player_getPosition(sp2C);
    sp28 = ml_distance_vec3f(sp2C, this->position);
    if( this->state == 1){
        if(sp28 < D_80367340[(s32)this->yaw].unk6*this->scale){
            func_802D05A0(this, 2);
        }
    }//L802D08A0
    if(this->state == 2){
        if((D_80367340[(s32)this->yaw].unk6 + 100)*this->scale < sp28){
            func_802D05A0(this, 1);
        }
        if(this->unk1C[0] != this->unk1C[1]){
            this->unk1C[0] += time_getDelta();
            if(this->unk1C[1] < this->unk1C[0]){
                this->unk1C[0] = this->unk1C[1];
            }
            func_802D0500(this);
        }
    }//L802D095C
}

void func_802D096C(s32 arg0, s32 arg1, s32 arg2, s32 arg3){
    f32 sp1C[3];

    sp1C[0] = reinterpret_cast(f32, arg0);
    sp1C[1] = reinterpret_cast(f32, arg1);
    sp1C[2] = reinterpret_cast(f32, arg2);
    func_8032813C(0x28B, sp1C, arg3);

}

void func_802D09B8(Actor *this, s32 arg1){
    __spawnQueue_add_4((GenFunction_4)func_802D096C, 
        reinterpret_cast(s32, this->position[0]), 
        reinterpret_cast(s32, this->position[1]), 
        reinterpret_cast(s32, this->position[2]), 
        arg1
    );
}
