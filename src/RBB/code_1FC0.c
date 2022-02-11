#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    f32 unk0;
    u8 unk4;
    u8 unk5;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
}ActorLocal_RBB_1FC0;

Actor *func_8038846C(ActorMarker * marker, Gfx **gdl, Mtx **mptr, s32 arg3);
void func_80388620(Actor *this);

/* .data */ 
ActorInfo D_80390380 = {
    0x2E, 0x1C6, 0x419, 0x0, NULL,
    func_80388620, NULL, func_8038846C,
    {0, 0}, 0, 0.0f, {0,0,0,0}
};

/* .code */
void func_803883B0(Actor *this, s32 arg1){
    ActorLocal_RBB_1FC0 *local = (ActorLocal_RBB_1FC0 *)&this->local;
    
    local->unk5 = 0;
    if(arg1 == 2){
        func_8030E624(0x4cbfe866);
        func_80335924(this->unk148, 0x137, 0.0f, 0.8f);
        func_80335A8C(this->unk148, 2);
    }
    this->state = arg1;
}

void func_80388430(ActorMarker * marker, s32 arg1){
    Actor * actor = marker_getActor(marker);
    ActorLocal_RBB_1FC0 *local = (ActorLocal_RBB_1FC0 *) &actor->local;
    func_8030E6D4(SFX_111_WHIPCRACK_DEATH);
    local->unk5 = 1;
}

Actor *func_8038846C(ActorMarker * marker, Gfx **gdl, Mtx **mptr, s32 arg3){
    Actor *actor = marker_getActor(marker);
    ActorLocal_RBB_1FC0 *local = (ActorLocal_RBB_1FC0 *) &actor->local;
    s32 sp5C;
    f32 pad58;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    
    if(actor->state == 0){
        return actor;
    }

    if(local->unk4){
        sp5C = func_803356A0(actor->unk148);
        sp40[0] = 0.0f;
        sp40[1] = local->unk0;
        sp40[2] = 0.0f;
        func_80345C78(&sp4C, &sp40);
        func_8033A8F0(sp5C, 1, &sp4C);

        sp34[0] = 0.0f;
        sp34[1] = 0.0f;
        sp34[2] = (local->unkC*0.5)/200.0;
        ml_vec3f_yaw_rotate_copy(&sp34, &sp34, local->unk0);
        func_8033A968(sp5C, 1, &sp34);

        sp34[0] = 0.0f;
        sp34[1] = 0.0f;
        sp34[2] = local->unkC/200.0f;
        func_8033A968(sp5C, 0x12, &sp34);
        func_80335918(actor->unk148);
    }
    func_8033A45C(3, (0.0f < local->unk8)? 1 : 0);
    func_8033A45C(4, (0.0f < local->unk8)? 1 : 0);
    func_80325888(marker, gdl, mptr, arg3);
    local->unk4 = actor->marker->unk14_21;
    return actor;
}

void func_80388620(Actor *this){
    f32 sp64[3];
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    ActorLocal_RBB_1FC0 *local = (ActorLocal_RBB_1FC0 *)&this->local;
    f32 sp50 = time_getDelta();
    f32 sp4C;
    f32 sp48;
    f32 tmp_f2;

    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        this->marker->propPtr->unk8_3 = 1;
        marker_setCollisionScripts(this->marker, func_80388430, NULL, NULL);
        local->unk4 = 0;
        local->unk0 = 0.0f;
        local->unk8 = 0.0f;
        local->unkC = 0.0f;
        local->unk10 = 0.0f;
        local->unk14 = 0.0f;
        func_803883B0(this, 1);
    }
    player_getPosition(&sp64);
    func_80258A4C(&this->position, this->yaw + -90.0f, &sp64, &sp60, &sp5C, &sp58);
    if(sp60 < 600.0f)
        local->unk8 = 1.0f;
    else{
        local->unk8 -=  sp50;
        local->unk8 = MAX(0.0f, local->unk8);
    }

    if( 500.0f <= local->unk10
        && sp60 < 500.0f
        && (sp58 < -0.2 || 0.2 < sp58)
    ){
        func_8030E624(0x665fe8c4);
    }

    local->unk10 = sp60;
    local->unk14 = local->unk14 + sp50;

    if( sp60 < 600.0f 
        && -1.0f < sp58
        && sp58 < 1.0f
        && sp64[1] < this->position_y + this->scale*200.0f
    ){
        func_80258A4C(&this->position, (this->yaw + -90.0f) + local->unk0, &sp64, &sp60, &sp5C, &sp58);
        local->unk0 += (sp58*200.0f)*sp50;
        if(1.0f < local->unk14 && (sp58 < -0.1 || 0.1 < sp58)){
                func_8030E6A4(SFX_D0_GRIMLET_SQUEAK, mlAbsF(sp58) * 0.1 + 0.9, 0x4e20);
                local->unk14 = 0.0f;
        }
    }
    else{//L80388964
        if(0.0f < local->unk0){
            local->unk0 -=  30.0f*sp50;
            local->unk0 = MAX(0.0f, local->unk0);
        }//L803889B4
        else{
            if(local->unk0 < 0.0f){
                local->unk0 +=  30.0f*sp50;
                local->unk0 = MIN(0.0f, local->unk0);
            }
        }
    }//L803889F8

    if(this->state == 1){
        if( sp60 < 400.0f
            && -0.8 <= sp58
            && sp58  <= 0.8
            && (sp64[1] - this->position_y) < 100.0f
            && -100.0f < (sp64[1] - this->position_y)
        ){
            func_803883B0(this, 2);
        }
    }//L80388AB8

    if(this->state == 2){
        func_8033568C(this->unk148, &sp4C, &sp48);
        if(0.6 <= sp48)
            tmp_f2 = 1.0 - 2*(sp48 - 0.6);
        else
            tmp_f2 = sp48*1.6666666666666667;
        //L80388B34
        local->unkC = tmp_f2*sp60;
        
        if( sp4C < 0.55
            && 0.55 <= sp48
            && !local->unk5
        ){
            func_8030E8B4(0x7fff4020, &this->position, 0x09c401f4);
        }

        if(func_80335794(this->unk148) > 0)
            func_803883B0(this, 1);
    }//L80388BB0
}
