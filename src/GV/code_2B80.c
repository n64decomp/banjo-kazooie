#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80335A74(void *, f32);

void func_80389144(Actor *this);
Actor *func_80389050(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorInfo D_80390D90 = { 
    MARKER_C0_TRUNKER, ACTOR_132_TRUNKER, ASSET_3DF_MODEL_TRUNKER, 
    0, NULL, 
    func_80389144, NULL, func_80389050, 
    { 0x0, 0x0}, 0x599, 2.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
void func_80388F70(Actor *this, s32 next_state){
    this->state = next_state;
    if(this->state == 1){
        func_80335924(this->unk148, ASSET_FE_ANIM_TRUCKER_SHORT, 0.1f, 2.5f);
    }

    if(this->state == 2){
        func_80335924(this->unk148, ASSET_FF_ANIM_TRUCKER_GROW, 0.1f, 2.5f);
        func_80335A8C(this->unk148, 2);
    }

    if(this->state == 3){
        func_80335924(this->unk148, ASSET_FF_ANIM_TRUCKER_GROW, 0.0f, 2.5f);
        func_80335A74(this->unk148, 0.999f);
        func_80335A8C(this->unk148, 2);
    }
}

Actor *func_80389050(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(this_marker);
    f32 sp38[3];
    f32 sp2C[3];
    
    if(this->state == 0) return this;

    this = func_80325888(this_marker, gfx, mtx, vtx);
    sp38[0] = this->position_x - 150.0f;
    sp38[1] = this->position_y + 2.0f;
    sp38[2] = this->position_z - 170.0f;
    sp2C[0] = this->pitch;
    sp2C[1] = this->yaw + 220.0f;
    sp2C[2] = this->roll;
    func_8033A4CC(2);
    func_803391A4(gfx, mtx, sp38, sp2C, 1.0f, NULL, func_8030A428(3));
    return this;
}


void func_80389144(Actor *this){
    ActorMarker *marker = this->marker;
    s32 sp28 = 0;
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        marker->propPtr->unk8_3 = TRUE;
        actor_collisionOff(this);
        mapSpecificFlags_set(0xC, FALSE);
        if(jiggyscore_isSpawned(JIGGY_45_GV_GOBI_2) && !func_803203FC(1)){
            func_80388F70(this, 3);
        }
        else{//L803891CC
            func_80388F70(this, 1);
        }
    }//L803891D8
    if( this->state == 1
        && !this->unk138_24
        && func_80329530(this, 250)
        && !func_80329530(this, 80)
        && func_8028F2A0()
    ){
        func_80311480(ASSET_A71_TEXT_TRUNKER_MEET, 0xe, this->position, NULL, NULL, NULL);
        this->unk138_24 = 1;
    }//L80389254

    if(this->state == 1 && mapSpecificFlags_get(0xC)){
        sp28 = 2;
    }

    if(this->state == 2 && func_80335794(this->unk148) > 0){
        sp28 = 3;
    }

    if(sp28)
        func_80388F70(this, sp28);
}