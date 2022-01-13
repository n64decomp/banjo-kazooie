#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct {
    s32 unk0;
    u8 unk4;
    //u8 pad5[3];
    u8 *unk8;
    f32 unkC;
    u8 unk10;
    //u8 pad11[3];
    ActorMarker *unk14;
    f32 unk18[3];
    f32 unk24;
}ActorLocal_GV_6370;

void func_8038C8A0(Actor *this, s32 next_state);
void func_8038CC98(Actor *this);
Actor *func_8038CC40(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
u8 D_803911F0[3] =  {0, 1, 2};
ActorInfo D_803911F4 = { 0xBB, 0x285, 0x3E6, 
    0, NULL,
    func_8038CC98, func_80326224, func_8038CC40,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

ActorInfo D_80391218 = { 0xBB, 0x286, 0x3E6, 
    0, NULL,
    func_8038CC98, func_80326224, func_8038CC40,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

ActorInfo D_8039123C = { 0xBB, 0x287, 0x3E6, 
    0, NULL,
    func_8038CC98, func_80326224, func_8038CC40,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
void func_8038C760(Actor *this, s32 arg1){
    ActorLocal_GV_6370 *local = (ActorLocal_GV_6370 *)&this->local;
    func_8038FD50(local->unk14, arg1);
    FUNC_8030E624(SFX_3F6_UNKNOWN, 0x36B, 0x2cc);
    FUNC_8030E624(SFX_3F6_UNKNOWN, 0x38A, 0x398);
    FUNC_8030E624(SFX_3F6_UNKNOWN, 0x3A9, 0x3FF);
    timed_setCameraToNode(0.0f, 8);
    if(arg1 < 3){
        timed_setCameraToNode(3.5f, arg1 + 0x15);
        timedFunc_set_3(3.5f, (TFQM3)func_80320044, BKPROG_F8_KING_SANDYBUTT_PYRAMID_STATE, arg1, 2);
        func_80324E88(6.5f);
        func_80324E38(6.5f, 0);
    }
    else{
        timedFunc_set_2(3.5f, func_8025A6EC, COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x7fff);
        timedFunc_set_3(3.5f, (TFQM3)func_80320044, BKPROG_F8_KING_SANDYBUTT_PYRAMID_STATE, arg1, 2);
        func_80324E88(6.0f);
        func_80324E38(6.0f, 0);
    }
}

void func_8038C880(Actor *this){
    func_8038C8A0(this, 0);
}

void func_8038C8A0(Actor *this, s32 next_state){
    ActorLocal_GV_6370 *local = (ActorLocal_GV_6370 *)&this->local;
    
    local->unk0 = 0;
    local->unk24 = 0.0f;
    this->marker->propPtr->unk8_3 = (next_state == 1) ? FALSE : TRUE;
    this->marker->collidable = (next_state == 1) ? FALSE : TRUE;
    if(this->state == 4 || this->state == 5)
        func_8030DA44(local->unk4);
    
    if(next_state == 4 || next_state == 5){
        local->unk4 = func_8030D90C();
        func_8030DA80(local->unk4, SFX_3EC_CCW_DOOR_OPENING);
        func_8030DD14(local->unk4, 3);
        func_8030DBB4(local->unk4, 0.8f);
        func_8030DABC(local->unk4, 0);
        func_8030E2C4(local->unk4);
    }//L8038C9B8

    if(next_state == 2){
        func_80335924(this->unk148, ASSET_F0_ANIM_MINI_SHPYNX_EATING, 1.0f, 3.0f);
        func_80335A74(this->unk148, 0.27f);
        func_80335A8C(this->unk148, 4);
        local->unkC = 0.0f;
        local->unk18[0] = this->position_x;
        local->unk18[1] = this->position_y;
        local->unk18[2] = this->position_z;
        if(this->state == 1){
            func_80250E94(0.0f, 0.6f, 1.0f, 0, 1.3f, 0.0f);
            timed_playSfx(1.0f, SFX_3F6_UNKNOWN, 0.8f, 30000);
        }
    }//L8038CA6C

    if(next_state == 3){
        local->unk24 = 3.0f;
        func_80335924(this->unk148, ASSET_F0_ANIM_MINI_SHPYNX_EATING, 1.0f, 3.0f);
        func_80335A74(this->unk148, 0.27f);
        func_80335A8C(this->unk148, 4);
    }//L8038CAB4

    if(this->state == 3){
        func_80335924(this->unk148, ASSET_F0_ANIM_MINI_SHPYNX_EATING, 0.5f, 3.0f);
        func_80335A74(this->unk148, 0.99f);
        func_80335A8C(this->unk148, 2);
        if(next_state == 4 || next_state == 5)
            FUNC_8030E8B4(SFX_DE_WOOD_SQUEAK, 0x3FD, 0x3FF, this->position, 500, 1500);
    }//L8038CB20

    if(next_state == 6){
        func_80324E38(0.0f, 3);
        func_80335924(this->unk148, ASSET_F0_ANIM_MINI_SHPYNX_EATING, 0.0f, 3.0f);
        func_8025A6EC(COMUSIC_2B_DING_B, 28000);
    }

    if(next_state == 7){
        local->unkC = 0.0f;
        local->unk18[0] = this->position_x;
        local->unk18[1] = this->position_y;
        local->unk18[2] = this->position_z;
        func_80250D94(0.7f, 0.5f, 1.3f);
        FUNC_8030E624(SFX_3F6_UNKNOWN, 0x3A9, 0x332);
    }

    if(next_state == 8){
        if(this->state == 7){
            func_80250D94(0.8f, 0.7f, 3.0f);
            func_8038C760(this, *local->unk8 + 1);
        }
        marker_despawn(this->marker);
    }
    this->state = next_state;
}

Actor *func_8038CC40(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(this_marker);
    if(this->state == 1) return this;
    return func_80325888(this_marker, gfx, mtx, vtx);
}

void func_8038CC98(Actor *this){
    ActorLocal_GV_6370 *local = (ActorLocal_GV_6370 *)&this->local;
    f32 sp80 = time_getDelta();
    s32 sp7C;
    f32 pad70;
    f32 sp6C[3];
    f32 f12;
    f32 sp5C[3];
    f32 sp58;
    f32 sp54;
    f32 sp48[3];

    if(!this->unk16C_4){
        sp7C = func_8031FF44(BKPROG_F8_KING_SANDYBUTT_PYRAMID_STATE, 2);
        this->unk16C_4 = TRUE;
        this->marker->unk30 = func_8038C880;
        local->unk8 = &D_803911F0[this->modelCacheIndex - 0x285];
        local->unk10 = 0;
        local->unk14 = 0;
        local->unkC = 0.0f;
        local->unk18[0] = this->position_x;
        local->unk18[1] = this->position_y;
        local->unk18[2] = this->position_z;
        if(*local->unk8 < sp7C){
            func_8038C8A0(this, 8);
        }
        else if(sp7C == *local->unk8){
            func_8038C8A0(this, 2);
        }
        else{
            func_8038C8A0(this, 1);
        }
        return;
    }

    if(!local->unk14){
        local->unk14 = func_80326EEC(ACTOR_31D_SANDYBUTT_PYRAMID)->marker;
    }

    if(this->state == 1){
        if(func_8031FF44(BKPROG_F8_KING_SANDYBUTT_PYRAMID_STATE, 2) == *local->unk8){
            func_8038C8A0(this, 2);
        }
    }

    if(this->state == 2){
        local->unkC += 0.5*sp80;
        if(1.0f <= local->unkC){
            local->unkC = 1.0f;
            func_8038C8A0(this, 3);
        }
        sp6C[0] = 0.0f;
        sp6C[1] = 0.0f;
        sp6C[2] = (1.0f - local->unkC) * -600.0f;
        ml_vec3f_yaw_rotate_copy(sp6C, sp6C, this->yaw);
        this->position_x = local->unk18[0] +  sp6C[0];
        this->position_y = local->unk18[1] +  sp6C[1];
        this->position_z = local->unk18[2] +  sp6C[2];
    }//L8038CECC

    if(this->state == 3){
        if(0.0f < local->unk24){
            local->unk24 -= sp80;
        }
        else{
            if(func_8038D388())
                func_8038C8A0(this, 5);
        }
    }//L8038CF1C

    if(this->state == 4 || this->state == 5){
        local->unkC += ((this->state == 4)? -1 : 1) * sp80;
        if(1.0f < local->unkC){
            local->unkC = 1.0f;
            func_8038C8A0(this, 4);
            return;
        }
        else if(local->unkC < -1.0f){
            local->unkC = -1.0f;
            func_8038C8A0(this, 5);
            return;
        }
        sp5C[0] = local->unkC*300.0f;
        sp5C[1] = 0.0f;
        sp5C[2] = 0.0f;
        ml_vec3f_yaw_rotate_copy(sp5C, sp5C, this->yaw);
        this->position_x = local->unk18[0] + sp5C[0];
        this->position_y = local->unk18[1] + sp5C[1];
        this->position_z = local->unk18[2] + sp5C[2];
        if(0.8 <= local->unkC){
            f12 = 1.0 - (local->unkC - 0.8)/0.2;
        }
        else if(local->unkC <= -0.8){
            f12 = 1.0 - (-local->unkC - 0.8)/0.2;
        }
        else{
            f12 = 1.0f;
        }
        func_8030DB04(local->unk4, f12*24000.0f, this->position, 200.0f, 1500.0f);
        if(!func_8038D388()){
            func_8038C8A0(this, 3);
        }
    }//L8038D110

    if(this->state == 6){
        func_8033568C(this->unk148, &sp58, &sp54);
        if(sp58 < 0.28 && 0.28 <= sp54){
            FUNC_8030E624(SFX_4C_LIP_SMACK, 0x36B, 0x3ff);
        }
        if(sp58 < 0.52 && 0.52 <= sp54){
            FUNC_8030E624(SFX_4C_LIP_SMACK, 0x36B, 0x398);
        }
        if(sp58 < 0.7 && 0.7 <= sp54){
            FUNC_8030E624(SFX_4C_LIP_SMACK, 0x36B, 0x3ff);
        }
        if(0.81 <= sp54){
            FUNC_8030E624(SFX_97_BLUBBER_BURPS, 0x36B, 0x3ff);
            func_8038C8A0(this, 7);
        }
    }//L8038D228

    if(this->state == 7){
        local->unkC += 0.5*sp80;
        if(1.0f < local->unkC){
            func_8038C8A0(this, 8);
        }
        sp48[0] = 0.0f;
        sp48[1] = 0.0f;
        sp48[2] = local->unkC*-600.0f;
        ml_vec3f_yaw_rotate_copy(sp48, sp48, this->yaw);
        this->position_x = local->unk18[0] + sp48[0];
        this->position_y = local->unk18[1] + sp48[1];
        this->position_z = local->unk18[2] + sp48[2];
    }//L8038D2F0

    if(local->unk0){
        if(this->state == 4 || this->state == 5){
            local->unk0 = 0;
            local->unk10++;
            if(local->unk10 == 3){
                func_8038C8A0(this, 6);
            }
            else{
                func_8025A6EC(COMUSIC_2B_DING_B, 28000);
            }
        }
    }
}
