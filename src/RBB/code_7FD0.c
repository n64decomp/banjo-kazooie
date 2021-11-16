#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    f32 unk0;
    f32 unk4[3];
    f32 unk10[3];
    f32 unk1C[3];
    f32 unk28;
    f32 unk2C;
}ActorLocal_RBB_7FD0;

void func_8038E3D8(Actor *this);

/* .data */
ActorInfo D_80390D50 = {
    0x1ab, 0x297, 0x43C, 0x0, NULL,
    func_8038E3D8, NULL, func_80325888,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};


/* .code */
void func_8038E3C0(Actor *this, s32 arg1){
    this->state = arg1;
}

void func_8038E3D8(Actor *this){
    f32 sp74[3];
    f32 sp68[3];
    ActorLocal_RBB_7FD0 *local = (ActorLocal_RBB_7FD0 *) &this->local;
    int i;
    f32 sp5C = time_getDelta();
    f32 sp50[3];
    f32 sp44[3];
    
    if(!this->unk16C_4){
        this->marker->propPtr->unk8_3 = 1;
        this->unk16C_4 = 1;
        local->unk0 = randf2(80.0f, 100.0f);
        local->unk28 = 0.0f;
        local->unk2C = 0.5f;
        this->position_y -= 10.0f;
        local->unk4[0] = 0.0f;
        local->unk4[1] = 0.0f;
        local->unk4[2] = 0.0f;
        local->unk10[0] = this->position_x;
        local->unk10[1] = this->position_y;
        local->unk10[2] = this->position_z;
        local->unk1C[0] = this->pitch;
        local->unk1C[1] = this->yaw;
        local->unk1C[2] = this->roll;
        func_8038E3C0(this, 1);
    }//L8038E4C8

    if(func_8025773C(&local->unk2C, sp5C)){
        local->unk2C = randf2(3.5f, 5.5f);
        func_8030E878(0x69, randf2(1.1f, 1.2f), 22000, &this->position, 500.0f, 1500.0f);
    }//L8038E544

    if(func_8032DCAC() == (int)this->marker && func_8028F20C()){
        player_getPosition(&sp44);
        if(sp44[0] < this->position_x - 10.0f && local->unk4[2] < 3.0f)
            local->unk4[2] += 5.0f*sp5C;

        if(this->position_x + 10.0f < sp44[0] && -3.0f < local->unk4[2])
            local->unk4[2] -= 5.0f*sp5C;

        if(this->position_z + 10.0f < sp44[2] &&  local->unk4[0] < 5.0f)
            local->unk4[0] += 5.0f*sp5C;
        
        if(sp44[2] < this->position_z - 10.0f &&  -5.0f < local->unk4[0])
            local->unk4[0] -= 5.0f*sp5C;
    }
    else{ 
        for(i= 0; i< 3; i++){
            if(0.0f < local->unk4[i]){
                local->unk4[i] -= 2.5*sp5C;
                if(local->unk4[i] < 0.0f)
                    local->unk4[i] = 0.0f;
            } else if(local->unk4[i] < 0.0f) { //L8038E710
                local->unk4[i] += 2.5*sp5C;
                if(0.0f < local->unk4[i])
                    local->unk4[i] = 0.0f;
            }//L8038E74C
        }
    }//L8038E754

    local->unk28 += sp5C;
    sp68[0] = 0.0f;
    sp68[1] = 5.0f * sinf((((local->unk28*0.8)*local->unk0)/180.0)*3.141592654);
    sp68[2] = 0.0f;
    sp74[0] = 4.5 * cosf(((local->unk28*local->unk0)/180.0) * 3.141592654);
    sp74[1] = 1.5 * sinf((((local->unk28*0.9)*local->unk0)/180.0)*3.141592654);
    sp74[2] = 0.0f;

    this->position_x = local->unk10[0] + sp68[0];
    this->position_y = local->unk10[1] + sp68[1];
    this->position_z = local->unk10[2] + sp68[2];

    sp50[0] = local->unk1C[0] + sp74[0];
    sp50[1] = local->unk1C[1] + sp74[1];
    sp50[2] = local->unk1C[2] + sp74[2];

    this->pitch = sp50[0] + local->unk4[0];
    this->yaw = sp50[1] + local->unk4[1];
    this->roll = sp50[2] + local->unk4[2];
}
