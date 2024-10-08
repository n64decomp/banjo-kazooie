#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8  unkC;
} ActorLocal_CC_0;

void func_803864D4(Actor *this);

/* .data */
ActorInfo D_80389AA0 = {
    MARKER_4B_CC_SCREW, ACTOR_43_CLACKER_SCREW, ASSET_890_MODEL_SCREW, 0, NULL, 
    func_803864D4, actor_update_func_80326224 , actor_draw,  
    0, 0, 0.0f, 0
};

/* .code */
void CC_func_803863F0(Actor *this, s32 next_state){
    ActorLocal_CC_0 * local = (ActorLocal_CC_0 *)this->local;
    if(this->state == 4){
        func_80388ED4(0);
    }
    this->state = next_state;
    local->unkC = 1;
    local->unk0 = 0.0f;
    local->unk4 = 0.0f;
    local->unk8 = 0.0f;
    if(1 == this->state){
        local->unk4 = 2.0f;
    }
    if(this->state == 2){
        func_80388ED4(1);
    }
    if(this->state == 3){
        local->unk0 = 1.0f;
    }

}

void func_803864D4(Actor *this){
    ActorMarker *marker = this->marker;//sp5C;
    ActorLocal_CC_0 * local = (ActorLocal_CC_0 *)this->local;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp3C = time_getDelta();
    f32 sp30[3];
    f32 sp2C;
    f32 sin_result;

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        marker->propPtr->unk8_3 = 1;
        CC_func_803863F0(this, 1);
    }//L80386530

    func_80388B4C(&sp4C);
    TUPLE_ASSIGN(sp40, 2640.0f, 5695.0f, -10.0f);
    local->unk8 += sp3C;
    if(ml_timer_update(&local->unk4, sp3C)){
        sp30[0] = sp4C[0] - sp40[0];
        sp30[1] = 0.0f;
        sp30[2] = sp4C[2] - sp40[2];
        if(!CC_func_80388CA0()){
            local->unk4 = 2.0f;
        }
        else if(60.0f < LENGTH_VEC3F(sp30)){
            local->unk4 = 0.05f;
        }
        else{
            CC_func_803863F0(this, 2);
        }
    }//L80386634

    if(ml_timer_update(&local->unk0, sp3C)){
        CC_func_803863F0(this, 4);
    }
    
    if((this->state == 2) && (1.0 <= local->unk8)){
            CC_func_803863F0(this, 3);
    }//L803866B4

    if((this->state == 4) && (1.0 <= local->unk8)){
            CC_func_803863F0(this, 1);
    }//L80386714

    if(this->state == 1){
        this->position[0] = sp4C[0];
        this->position[1] = sp4C[1];
        this->position[2] = sp4C[2];
    }
    else if(this->state == 2)
    {//L80386734
        sp2C = local->unk8/1.0;
        if(local->unkC && 0.6 < sp2C){
            FUNC_8030E8B4(SFX_91_METALLIC_SOUND, 1.0, 32000, this->position, 100, 6000);
            local->unkC = 0;
        }//L80386798
        sin_result = sinf(((sp2C*90.0)/180.0)*BAD_PI);
        this->position_x = sp4C[0] + (sp40[0] - sp4C[0])*sin_result;
        this->position_y = sp4C[1] + (sp40[1] - sp4C[1])*sin_result;
        this->position_z = sp4C[2] + (sp40[2] - sp4C[2])*sin_result;
    }//L80386818
    else if(this->state == 3){
        this->position[0] = sp40[0];
        this->position[1] = sp40[1];
        this->position[2] = sp40[2];
    }
    else if(this->state == 4){
        sp2C = 1 - local->unk8/1.0;
        if(local->unkC && sp2C < 0.1){
            local->unkC = 0;
        }//L8038688C
        sin_result = sinf(((sp2C*90.0)/180.0)*BAD_PI);
        this->position_x = sp4C[0] + (sp40[0] - sp4C[0])*sin_result;
        this->position_y = sp4C[1] + (sp40[1] - sp4C[1])*sin_result;
        this->position_z = sp4C[2] + (sp40[2] - sp4C[2])*sin_result;
    }//L80386904
}
