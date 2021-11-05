#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define _HorzDist3v(v1, v2) ((v1[0]-v2[0])*(v1[0]-v2[0]) + (v1[2]-v2[2])*(v1[2]-v2[2]))
extern int func_8024549C(f32[3], f32);

typedef struct{
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
}struct_core2_D2AB0;

void func_80359C40(Actor *this);

/* .data */
ActorInfo D_80372AC0 = {
    0x246, 0x354, 0, 
    0, NULL, 
    func_80359C40, func_80326224, func_80325340,
    {0x13,0x88,0,0}, 0.0f, {0,0,0,0}
}; 

s32 D_80372AE4[3] = {0xff, 0xff, 0xfe};

struct_core2_D2AB0 D_80372AF0 = {0.0f, 0.0f, 1.0f, 1.4f};

struct43s D_80372B00 = {
    {{0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f}},
    {{0.0f, -650.0f, 0.0f}, {0.0f, -650.0f, 0.0f}},
    {{-400.0f, 0.0f, -400.0f}, {400.0f, 0.0f, 400.0f}}
};


/* .code */
void func_80359A40(f32 position[3], struct_core2_D2AB0 *arg1, s32 cnt){
    struct30s *pCtrl = func_802F0BD0(cnt);
    func_802EF950(pCtrl, ASSET_70C_SPRITE_RIPPLE);
    func_802EFA70(pCtrl, 1);
    func_802EFFA8(pCtrl, D_80372AE4);
    func_802EFB54(pCtrl, position);
    func_802EFB70(pCtrl, 0.1f, 0.1f);
    func_802EFB84(pCtrl, 1.0f, 1.4f);
    func_802EFE5C(pCtrl, arg1->unk0, arg1->unk4);
    func_802EFEC0(pCtrl, arg1->unk8, arg1->unkC);
    func_802EFA5C(pCtrl, 0.0f, 0.5f);
    func_802EF5C8(pCtrl, cnt);
}

void func_80359B20(struct31s *pCtrl, f32 position[3]){
    if(func_8024549C(position, 4.0f)){
        position[1] += 2.0f;
        func_80359A40(position, &D_80372AF0, 1);
        func_8030E878(SFX_413_UNKNOWN, randf2(1.0f, 1.4f), 20000, position, 0.0f, 3500.0f);
    }
}

int func_80359BBC(Actor *this, s32 arg1){
    f32 sp1C[3];

    player_getPosition(sp1C);
    if(_HorzDist3v(this->position, sp1C) < arg1*arg1)
        return 1;
    return 0;
}

void func_80359C40(Actor *this){
    struct30s *pCtrl;

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        actor_collisionOff(this);
        this->unk60 = this->yaw/360.0;
    }
    if(func_80359BBC(this, 5000) && randf() < this->unk60){
        pCtrl = func_802F0BD0(1);
        func_802EFAC8(pCtrl, ASSET_8A0_SPRITE_WATER_DROP);
        func_802EFB54(pCtrl, this->position);
        func_802EFD7C(pCtrl, &D_80372B00);
        func_802EFA18(pCtrl, 1);
        func_802EFA10(pCtrl, func_80359B20);
        func_802EFE5C(pCtrl, 0.0f, 0.01f);
        func_802EFEC0(pCtrl, 7.0f, 7.0f);
        func_802EFB70(pCtrl, 0.1f, 0.1f);
        func_802EFB84(pCtrl, 0.1f, 0.1f);
        func_802EF5C8(pCtrl, 1);
    }
}  
