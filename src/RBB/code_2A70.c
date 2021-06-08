#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    s16 unk0;
    f32 unk4[3];
    f32 unk10;
    f32 unk14;
    f32 unk18[3];
}ActorLocal_RBB_2A70_0;

typedef struct {
    ActorLocal_RBB_2A70_0 *unk0;
    f32 unk4[3];
    f32 unk10[3];
    f32 unk1C;
    u8  pad20[0x4];
    f32 unk24;
}ActorLocal_RBB_2A70;

void func_803890BC(Actor *this);

/* .data */
ActorLocal_RBB_2A70_0 D_80390430[] = {
    {0x178, {0.0f,     -60.0f, 2450.0f},   0.0f, 6.0f, {     0.0f, -100.0f,  1900.0f}},
    {0x179, {-1600.0f, 730.0f, -700.0f}, 270.0f, 6.0f, { -1600.0f,  810.0f, -1400.0f}},
    {0x17A, {1600.0f,  730.0f, -700.0f}, 270.0f, 5.0f, {  1600.0f,  810.0f, -1400.0f}},
    0
};

ActorInfo D_803904C0 = {
    0x188, 0x178, 0x40C, 0x0, NULL,
    func_803890BC, NULL, func_80325888,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

ActorInfo D_803904E4 = {
    0x189, 0x179, 0x40D, 0x0, NULL,
    func_803890BC, NULL, func_80325888,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

ActorInfo D_80390508 = {
    0x18A, 0x17A, 0x40E, 0x0, NULL,
    func_803890BC, NULL, func_80325888,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

/* .code */
ActorLocal_RBB_2A70_0 *func_80388E60(Actor *this){
    ActorLocal_RBB_2A70_0 * iPtr;
    for(iPtr = D_80390430; iPtr->unk0 != 0; iPtr++){
        if(iPtr->unk0 == this->modelCacheIndex)
            return iPtr;
    }
    return NULL;
}

void func_80388EB8(Actor *this, s32 arg1){
    ActorLocal_RBB_2A70 *local = (ActorLocal_RBB_2A70 *)&this->local;
    s32 sp30;

    if(this->state == 2)
        func_8030E8B4(0x665f407f, &this->position, 0x08fc03e8);
    
    this->state = arg1;
    local->unk24 = 0.0f;

    if(this->state == 1)
        local->unk24 = local->unk0->unk14;

    if(this->state == 2){
        sp30 = func_802F9AA8(0x94);
        func_802F9DB8(sp30, 1.0f, 1.0f, 0.0f);
        func_802F9EC4(sp30, &local->unk0->unk18, 0x6A4, 0x9c4);
        func_802F9F80(sp30, 0.3f, 3.4f, 0.3f);
        func_802FA060(sp30, 0x61a8, 0x61a8, 0.0f);
        this->pitch += ( 360.0f <= this->pitch) ? -360 : 0;
        this->yaw += ( 360.0f <= this->yaw) ? -360 : 0;
        this->roll += ( 360.0f <= this->roll) ? -360 : 0;
        
        local->unk4[0] = this->pitch;
        local->unk4[1] = this->yaw;
        local->unk4[2] = this->roll;

        local->unk10[0] = this->pitch;
        local->unk10[1] = this->yaw;
        local->unk10[2] = this->roll + 360.0f;

        local->unk1C = 0.0f;
        func_8030E8B4(0x665f407f, &this->position, 0x07080384);
    }//L803890A8
}

void func_803890BC(Actor *this){
    ActorLocal_RBB_2A70 *local = (ActorLocal_RBB_2A70 *)&this->local;
    f32 sp38 = func_8033DD9C();
    f32 sp2C[3];
    if(!this->unk16C_4){
        actor_collisionOff(this);
        this->marker->propPtr->unk8_3 = 1;
        this->unk16C_4 = 1;
        local->unk0 = func_80388E60(this);
        this->position[0] = local->unk0->unk4[0];
        this->position[1] = local->unk0->unk4[1];
        this->position[2] = local->unk0->unk4[2];
        this->roll = local->unk0->unk10;
        if(this->state == 0)
            func_80388EB8(this, 1);
    }//L80389164

    if(func_8025773C(&local->unk24, sp38))
        func_80388EB8(this, (this->state == 1) ? 2 : 1);
    //L803891A8

    if(this->state == 2){
        local->unk1C += 0.25 * sp38;
        if(1.0f < local->unk1C)
            local->unk1C = 1.0f;
        func_80255FE4(&sp2C, &local->unk4, &local->unk10, local->unk1C);
        this->pitch = sp2C[0];
        this->yaw = sp2C[1];
        this->roll = sp2C[2];
        if(local->unk1C == 1.0f)
            func_80388EB8(this, 1);
    }//L80389264
}