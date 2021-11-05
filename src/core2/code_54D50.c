#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern int func_8024549C(f32 [3], f32);

#define _HorzDist3v(v1, v2) ((v1[0]-v2[0])*(v1[0]-v2[0]) + (v1[2]-v2[2])*(v1[2]-v2[2]))


typedef struct{
    struct30s *unk0;
}ActorLocal_Core2_53C10;

void func_802DC018(Actor *this);

/* .data */
ActorInfo D_80367F30= {
    0x1F5, 0x1E5, 0, 
    0, NULL, 
    func_802DC018, func_80326224, func_80325340,
    {0,0,0,0}, 0.0f, {0,0,0,0}
}; 

s32 D_80367F54[3] = {0xff, 0xff, 0xff};
struct40s D_80367F60 = {
    { {0.1f, 0.5f}, {1.0f, 1.5f}, {0.0f, 0.01f}, {0.5f, 1.4f}, 
      0.0f, 0.01f
    }, 
    4.0f, 1.0f
};

struct43s D_80367F90 ={
    {{0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f}},
    {{0.0f, -650.0f, 0.0f}, {0.0f, -650.0f, 0.0f}},
    {{-200.0f, 0.0f, -200.0f}, {200.0f, 0.0f, 200.0f}}
};

/* .code */
void func_802DBCE0(struct30s *pCtrl, f32 arg1[3]){
    struct30s *other = func_802F0BD0(1);
    if(func_8024549C(arg1, 4.0f)){
        arg1[1] += 2.0f;
        func_802EF950(other, ASSET_70C_SPRITE_RIPPLE);
        func_802EFA70(other, 1);
        func_802EFB54(other, arg1);
        func_802EFB70(other, 0.1f, 0.1f);
        func_802EFB84(other, 1.0f, 1.4f);
        func_802EFEC0(other, 1.0f, 1.4f);
        func_802EFA5C(other, 0.0f, 0.5f);
        func_802EF5C8(other, 1);
        func_8030E878(SFX_413_UNKNOWN, randf2(1.0f, 1.4f), 0x4e20, arg1, 0.0f, 3500.0f);
    }
    else{//L802DBDF4
        func_802EF950(other, ASSET_700_SPRITE_DUST_1);
        func_802EFA90(other, 0, 7);
        func_802EFFA8(other, D_80367F54);
        func_802EFB54(other, arg1);
        func_802EFED4(other, -230.0f, 30.0f, -230.0f, 230.0f, 110.0f, 230.0f);
        func_802EFC28(other, &D_80367F60);
        FUNC_8030E8B4(SFX_7_BANJO_LANDING_03, 0x2AF, 0x3ff, arg1, 1500, 4500);
    }//L802DBE8C
}

void func_802DBE9C(Actor *this, struct30s *pCtrl){
    func_802EFD7C(pCtrl, &D_80367F90);
    func_802EFAC8(pCtrl, 0x344);
    func_802EFB54(pCtrl, this->position);
    func_802EFA70(pCtrl, 4);
    func_802EFE24(pCtrl, -450.0f, -450.0f, -450.0f, 450.0f, 450.0f, 450.0f);
    func_802EFA18(pCtrl, 1);
    func_802EFA10(pCtrl, func_802DBCE0);
    func_802EFE5C(pCtrl, 0.0f, 0.01f);
    func_802EFEC0(pCtrl, 7.0f, 7.0f);
    func_802EFA5C(pCtrl, 0.0f, 0.3f);
    func_802F0D54(pCtrl);
}

int func_802DBF94(Actor *this, s32 arg1){
    f32 sp1C[3];

    player_getPosition(sp1C);
    if(_HorzDist3v(this->position, sp1C) < arg1*arg1)
        return 1;
    return 0;
}

void func_802DC018(Actor *this){
    ActorLocal_Core2_53C10 *local = (ActorLocal_Core2_53C10 *) &this->local;
    f32 tmp_f0;

    if(!this->unk16C_4){
        actor_collisionOff(this);
        local->unk0 = func_802F0BD0(16);
        func_802DBE9C(this, local->unk0);
        this->unk16C_4 = TRUE;
    }
    if(func_802DBF94(this, 600) && randf() < 0.2){
        tmp_f0 = randf2(0.01f, 0.06f);
        func_802EFB70(local->unk0, tmp_f0, tmp_f0);
        func_802EFB84(local->unk0, tmp_f0, tmp_f0);
        func_802EF5C8(local->unk0, 1);
    }//L802DC0F4
}
