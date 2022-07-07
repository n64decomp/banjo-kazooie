#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    s16 uid;
    f32 unk4[3];
    f32 unk10[3];
    f32 unk1C[3];
    f32 unk28[3];
    f32 unk34[3];
    f32 unk40;
}Struct_RBB_2E90_0;

typedef struct {
    f32 unk0[3];
    Struct_RBB_2E90_0 *unkC;
    f32 unk10[3];
    f32 unk1C[3];
    f32 unk28;
}ActorLocal_RBB_2E90;

void func_8038944C(Actor *this);


/* .data */
Struct_RBB_2E90_0 D_80390530[] = {
    { 
        0x1BB, 
        {0.0f, 641.45f, -1400.0f}, 
        {0.0f, 0.0f,  90.0f},
        {0.0f, 0.0f, 360.0f}, 
        {0.0f, 0.0f, 270.0f}, 
        {0.0f, 0.0f,  90.0f}, 
        4.0f
    },
    { 
        0x1BC, 
        {-800.0f, 641.45f, -2400.0f},
        { 95.0f, 0.0f, 0.0f},
        {380.0f, 0.0f, 0.0f}, 
        {285.0f, 0.0f, 0.0f}, 
        { 90.0f, 0.0f, 0.0f}, 
        4.25f
    },
    { 
        0x1BD, 
        {800.0f, 641.45f, -2400.0f}, 
        {100.0f, 0.0f, 0.0f},
        {400.0f, 0.0f, 0.0f}, 
        {300.0f, 0.0f, 0.0f}, 
        {90.0f, 0.0f, 0.0f}, 
        4.5f
    },
    {0}
};

ActorInfo D_80390640 = {
    0x191, 0x1BB, 0x40F, 0x0, NULL,
    func_8038944C, NULL, func_80325888,
    0, 0, 0.0f, 0
};

ActorInfo D_80390664 = {
    0x192, 0x1BC, 0x410, 0x0, NULL,
    func_8038944C, NULL, func_80325888,
    0, 0, 0.0f, 0
};

ActorInfo D_80390688 = {
    0x193, 0x1BD, 0x411, 0x0, NULL,
    func_8038944C, NULL, func_80325888,
    0, 0, 0.0f, 0
};

/* .code */
Struct_RBB_2E90_0 * func_80389280(Actor *this){
    Struct_RBB_2E90_0 * iPtr;
    for(iPtr = D_80390530; iPtr->uid != 0; iPtr++){
        if(iPtr->uid == this->modelCacheIndex)
            return iPtr;
    }
    return NULL;
}

void func_803892D8(Actor *this, s32 arg1){
    f32 pad;
    ActorLocal_RBB_2E90 *local = (ActorLocal_RBB_2E90 *)&this->local;
    this->state = arg1;

    local->unk28 = 0.0f;
    if(this->state == 1){
        local->unk0[2] = 0.0f;
        local->unk0[1] = 0.0f;
        local->unk0[0] = 0.0f;
        ml_vec3f_copy(&local->unk10, &local->unkC->unk1C);
        ml_vec3f_copy(&local->unk1C, &local->unkC->unk1C);
    }//L8038935C

    if(this->state == 2){
        ml_vec3f_copy(&local->unk0, &local->unkC->unk28);
        ml_vec3f_copy(&local->unk1C, &local->unkC->unk10);
        local->unk28 = local->unkC->unk40;
    }//L803893A8

    if(this->state == 3){
        ml_vec3f_copy(&local->unk0, &local->unkC->unk28);
        ml_vec3f_copy(&local->unk1C, &local->unkC->unk1C);
        local->unk28 = local->unkC->unk40;
    }//L803893F4

    if(this->state == 4){
        ml_vec3f_copy(&local->unk0, &local->unkC->unk34);
        ml_vec3f_copy(&local->unk10, &local->unkC->unk1C);
        local->unk1C[2] = 0.0f;
        local->unk1C[1] = 0.0f;
        local->unk1C[0] = 0.0f;
    }
}

void func_8038944C(Actor *this){
    ActorLocal_RBB_2E90 *local = (ActorLocal_RBB_2E90 *)&this->local;
    f32 tick;
    int i;
    f32 sp50[3];
    f32 sp44[3];

    tick = time_getDelta();

    if(!this->unk16C_4){
        this->marker->propPtr->unk8_3 = 1;
        this->unk16C_4 = TRUE;
        local->unkC = func_80389280(this);
        if(this->state == 0){
            ml_vec3f_copy(&this->position, &local->unkC->unk4);
            local->unk0[0]  = local->unk0[1]  = local->unk0[2]  = 0.0f;
            local->unk10[0] = local->unk10[1] = local->unk10[2] = 0.0f;
            local->unk1C[0] = local->unk1C[1] = local->unk1C[2] = 0.0f;

            local->unk28 = 0.0f;
            func_803892D8(this, 1);
        }
    }//L80389508

    if(func_8025773C(&local->unk28, tick)){
        if(this->state == 2)
            func_803892D8(this, 3);
        else if(this->state == 3)
            func_803892D8(this, 2);
    }//L80389568

    switch (this->state)
    {
    case 1:
    case 2:
    case 3:
    case 4:
        sp50[0] = this->pitch;
        sp50[1] = this->yaw;
        sp50[2] = this->roll;
        this->pitch += local->unk10[0]*tick ;
        this->yaw   += local->unk10[1]*tick ;
        this->roll  += local->unk10[2]*tick ;

        sp44[0] = this->pitch;
        sp44[1] = this->yaw;
        sp44[2] = this->roll;

        for(i = 0; i < 3; i++){
            if( (sp50[i] < 90.0f && 90.0f <= sp44[i])
                || (sp50[i] < 270.0f && 270.0f <= sp44[i])
                || (sp50[i] < 180.0f && 180.0f <= sp44[i])
                || (sp50[i] < 360.0f && 360.0f <= sp44[i])
            ){
                FUNC_8030E8B4(SFX_2_CLAW_SWIPE, 0.4f, 23000, this->position, 50, 1000);
            }
        }
        this->pitch += (360.0f <= this->pitch)? -360 : 0;
        this->yaw   += (360.0f <= this->yaw)? -360 : 0;
        this->roll  += (360.0f <= this->roll)? -360 : 0;

        for(i = 0; i < 3; i++){//L803897B8
            if( local->unk10[i] < local->unk1C[i] ){
                local->unk10[i] += local->unk0[i]*tick;
                local->unk10[i] = MIN(local->unk1C[i] , local->unk10[i]);
            }
            else if( local->unk1C[i] < local->unk10[i]){
                local->unk10[i] -= local->unk0[i]*tick;
                local->unk10[i] = MAX(local->unk1C[i] , local->unk10[i]);
            }
        }
        break;
    }//L80389860

    if(this->state == 1 && mapSpecificFlags_get(0)){
        func_803892D8(this, 2);
    }
    if(tick);
}
