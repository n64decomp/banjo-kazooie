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
    0x4B, 0x43, 0x890, 0, NULL, 
    func_803864D4, func_80326224 , func_80325888,  
    0, 0, 0.0f, 0
};

/* .rodata */
extern f32 D_80389EB0;
extern f32 D_80389EB4;
extern f64 D_80389EB8;
extern f64 D_80389EC0;
extern f64 D_80389EC8;
extern f64 D_80389ED0;
extern f64 D_80389ED8;
extern f64 D_80389EE0;
extern f64 D_80389EE8;
extern f64 D_80389EF0;
// 0000 3AC0: 45B1F800 3D4CCCCD 3FE3333333333333
// 0000 3AD0: 4056800000000000 4066800000000000
// 0000 3AE0: 400921FB54524550 3FB999999999999A
// 0000 3AF0: 4056800000000000 4066800000000000
// 0000 3B00: 400921FB54524550 0000000000000000

/* .code */
void func_803863F0(Actor *this, s32 next_state){
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

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_0/func_803864D4.s")
#else
void func_803864D4(Actor *this){
    ActorLocal_CC_0 * local = (ActorLocal_CC_0 *)this->local;
    ActorMarker *marker = this->marker;//sp58;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp3C = time_getDelta();
    f32 sp30[3];
    f32 sp2C;
    f32 sin_result;

    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        marker->propPtr->unk8_3 = 1;
        func_803863F0(this, 1);
    }//L80386530

    func_80388B4C(&sp4C);
    TUPLE_ASSIGN(sp40, 2640.0f, 5695.0f, -10.0f);
    local->unk8 += sp3C;
    if(func_8025773C(&local->unk4, sp3C)){
        sp30[0] = sp4C[0] - sp40[0];
        sp30[1] = 0.0f;
        sp30[2] = sp4C[2] - sp40[2];
        if(!func_80388CA0()){
            local->unk4 = 2.0f;
        }
        else if(60.0f < gu_sqrtf(sp30[0]*sp30[0] + sp30[1]*sp30[1] + sp30[2]*sp30[2])){
            local->unk4 = 0.05f;
        }
        else{
            func_803863F0(this, 2);
        }
    }//L80386634

    if(func_8025773C(&local->unk0, sp3C)){
        func_803863F0(this, 4);
    }
    
    if(this->state == 2){
        if(1.0 <= local->unk8)
            func_803863F0(this, 3);
    }//L803866B4

    if(this->state == 4){
        if(1.0 <= local->unk8)
            func_803863F0(this, 1);
    }//L80386714

    if(this->state == 1){
        TUPLE_COPY(this->position, sp4C);
    }
    else if(this->state == 2)
    {//L80386734
        sp2C = local->unk8*(f64)1;
        if(local->unkC && 0.6 < sp2C){
            FUNC_8030E8B4(SFX_91_METALLIC_SOUND, 1000, 0x3FF, &this->position, 100, 6000);
            local->unkC = 0;
        }//L80386798
        sin_result = sinf(((sp2C*90.0)/180.0)*M_PI);
        this->position_x = (sp40[0] - sp4C[0])*sin_result + sp4C[0];
        this->position_y = (sp40[1] - sp4C[1])*sin_result + sp4C[1];
        this->position_z = (sp40[2] - sp4C[2])*sin_result + sp4C[2];
    }//L80386818
    else if(this->state == 3){
        TUPLE_COPY(this->position, sp40);
    }
    else if(this->state == 4){
        sp2C = 1 - local->unk8*(f64)1;
        if(local->unkC && sp2C < 0.1){
            local->unkC = 0;
        }//L8038688C
        sin_result = sinf(((sp2C*90.0)/180.0)*M_PI);
        this->position_x = (sp40[0] - sp4C[0])*sin_result + sp4C[0];
        this->position_y = (sp40[1] - sp4C[1])*sin_result + sp4C[1];
        this->position_z = (sp40[2] - sp4C[2])*sin_result + sp4C[2];
    }//L80386904
}
#endif
