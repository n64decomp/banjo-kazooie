#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    u8  unk0;
    u8  unk1;
    s16 unk2[3];
    s16 unk8[3];
    s16 unkE[3];
    f32 unk14;
    f32 unk18;
    f32 unk1C[2];
    // f32 unk20;
    f32 unk24;
}ActorLocal_Flibbit;


extern f32 func_80309724(f32 *);
extern void func_80256E24(f32 [3], f32, f32, f32, f32, f32);

void chflibbit_update(Actor *this);
Actor *chflibbit_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorInfo D_80390690 = {
    MARKER_C1_FLIBBIT_RED, ACTOR_133_FLIBBIT_RED, ASSET_375_MODEL_FLIBBIT_RED,
    0, NULL, 
    chflibbit_update, NULL, chflibbit_draw,
    0, 0, 1.0f, 0
};

f32 D_803906B4[3] = {0.0f, 0.0f, 0.0f};

/* .code */
bool BGS_func_803863F0(Actor *this, f32 arg1[3], s32 arg2){

    ActorLocal_Flibbit *local = (ActorLocal_Flibbit *)&this->local;

    local->unk1 = arg2;

    local->unk2[0] = this->position[0];\
    local->unk2[1] = this->position[1];\
    local->unk2[2] = this->position[2];
    local->unk8[0] = arg1[0];
    local->unk8[1] = arg1[1];
    local->unk8[2] = arg1[2];

    local->unk8[1] = func_80309724(arg1);
    func_80335924(this->unk148, 0xdb, 0.2f,(arg2) ?  randf2(0.7f, 0.8f) :  randf2(0.75f, 0.85f));
    func_80335A8C(this->unk148, 2);
    func_80324D54(0.2f, 0x3f2, randf2(0.7f, 1.3f), randi2(0x61A8, 0x6978), this->position, 500.0f, 2500.0f);
    return TRUE;
}

bool func_80386564(Actor *this){
    f32 plyrPos[3]; //sp54
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C[3]; //sp3C
    f32 sp30[3]; //sp30

    player_getPosition(plyrPos);
    func_80258A4C(this->position, this->yaw - 90.0f, plyrPos, &sp48, &sp44, &sp40);
    if(func_80329210(this, plyrPos)){
        if((-0.7 <= sp40) && (sp40 <= 0.7)){
            sp3C[0] = plyrPos[0] - this->position_x;
            sp3C[1] = plyrPos[1] - this->position_y;
            sp3C[2] = plyrPos[2] - this->position_z;
            ml_vec3f_set_length(sp3C,180.0f);
            sp30[0] = sp3C[0] + this->position_x;
            sp30[1] = sp3C[1] + this->position_y;
            sp30[2] = sp3C[2] + this->position_z;
            if(func_80329210(this, sp30))
                return BGS_func_803863F0(this, sp30, 1);
        }
    }
    return 0;

}

s32 func_803866A4(Actor *this) {
    f32 sp64[3];
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp4C[3];
    ActorLocal_Flibbit *local = (ActorLocal_Flibbit *)&this->local;
    f32 sp3C[3];


    sp64[0] = (f32) local->unkE[0];
    sp64[1] = (f32) local->unkE[1];
    sp64[2] = (f32) local->unkE[2];
    func_80258A4C(this->position, this->yaw - 90.0f, sp64, &sp60, &sp5C, &sp58);
    if ((-0.9 <= sp58) && (sp58 <= 0.9)) {
        if ((f64) sp60 > 216.0) {
            sp4C[0] = sp64[0] - this->position[0];
            sp4C[1] = sp64[1] - this->position[1];
            sp4C[2] = sp64[2] - this->position[2];
            ml_vec3f_set_length(sp4C, 180.0f);
            sp3C[0] = this->position[0] + sp4C[0];
            sp3C[1] = this->position[1] + sp4C[1];
            sp3C[2] = this->position[2] + sp4C[2];
        } else {
            sp3C[0] = (f32) local->unkE[0];
            sp3C[1] = (f32) local->unkE[1];
            sp3C[2] = (f32) local->unkE[2];
        }
        if (func_80329210(this, sp3C) != 0) {
            return BGS_func_803863F0(this, sp3C, 0);
        }
    }
    return 0;
}


bool func_8038686C(Actor *this) {
    f32 sp84[3];
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 *temp_s2;
    f32 sp68[3];
    f32 phi_f2;
    int i;

    player_getPosition(sp84);
    func_80258A4C(this->position, this->yaw - 90.0f, sp84, &sp80, &sp7C, &sp78);
    for(i = 0; i < 0xA; i++){
        if (i < 5) {
            if (sp78 > 0.0f) {
                phi_f2 = randf2(10.0f, 90.0f) + this->yaw;
            } else {
                phi_f2 = randf2(-90.0f, -10.0f) + this->yaw;
            }
        } else {
            phi_f2 = randf2(-110.0f, 110.0f) + this->yaw;
        }
        func_80256E24(sp68, 0.0f, phi_f2, 0.0f, 0.0f, 180.0f);
        sp68[0] += this->position[0];
        sp68[1] += this->position[1];
        sp68[2] += this->position[2];
        if (func_80329210(this, sp68)) {
            return BGS_func_803863F0(this, sp68, 0);
        }
    }
    return FALSE;
}


bool func_80386A34(Actor * this){
    f32 plyrPos[3];
    bool out;

    if(func_803203FC(UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE))
        return 0;
    
    player_getPosition(plyrPos);
    if(func_80329210(this, plyrPos)){
        if(!(out = func_80386564(this)) && (0.5 < randf ())){
            return 0;
        }
    }else{
        out = func_803866A4(this);
    }

    if(!out)
        out = func_8038686C(this);
    
    return out;
}

void func_80386AEC(Actor *this, s32 next_state) {
    ActorLocal_Flibbit *local;

    local = (ActorLocal_Flibbit *) &this->local;
    local->unk1 = FALSE;
    local->unk18 = 0.0f;
    local->unk24 = 0.0f;

    if (next_state == 1) {
        func_80335924(this->unk148, ASSET_FA_ANIM_FLIBBIT_IDLE, 0.2f, randf2(1.0f, 2.0f));
        func_80335A74(this->unk148, randf2(0.0f, 0.9f));
        func_80335A8C(this->unk148, 1);
        this->position[0] = (f32) local->unkE[0];
        this->position[1] = (f32) local->unkE[1];
        this->position[2] = (f32) local->unkE[2];
        local->unk24 = randf2(1.0f, 3.0f);
    }
    
    if (next_state == 2){
        if(!func_80386A34(this)) {
            if (this->state != 3) {
                next_state = 3;
                func_80386AEC(this, next_state);
            }
            return;
        }
    } 

    if (next_state == 3) {
        func_80335924(this->unk148, ASSET_FB_ANIM_FLIBBIT_TURN, 0.2f, 1.0f);
        func_80335A74(this->unk148, randf2(0.0f, 1.0f));
        func_80335A8C(this->unk148, 1);
        local->unk24 = randf2(1.0f, 3.0f);
    }

    if (next_state == 4) {
        func_80335924(this->unk148, ASSET_FA_ANIM_FLIBBIT_IDLE, 0.2f, randf2(1.0f, 2.0f));
        func_80335A74(this->unk148, randf2(0.0f, 0.9f));
        func_80335A8C(this->unk148, 1);
        this->position[1] = func_80309724(this->position);
        local->unk18 = 1.0f;
    }

    if (next_state == 5) {
        FUNC_8030E8B4(SFX_8E_GRUNTLING_DAMAGE, 1.5f, 32200, this->position, 500, 2500);
        func_80335924(this->unk148, ASSET_288_ANIM_FLIBBIT_OW, 0.1f, 0.65f);
        func_80335A8C(this->unk148, 2);
        this->position[1] = func_80309724(this->position);
        local->unk18 = 1.0f;
    }

    if (next_state == 6) {
        func_80335924(this->unk148, ASSET_112_ANIM_FLIBBIT_DIE, 0.2f, 0.4f);
        FUNC_8030E8B4(SFX_115_BUZZBOMB_DEATH, 1.0f, 32200, this->position, 500, 2500);
        this->marker->collidable = FALSE;
        this->unk10_1 = FALSE;
        local->unk14 = 1000.0f;
    }
    if (next_state == 7) {
        func_80335924(this->unk148, ASSET_113_ANIM_FLIBBIT_DEAD, 0.2f, 1.0f);
        func_80335A8C(this->unk148, 2);
        FUNC_8030E8B4(SFX_2F_ORANGE_SPLAT, 0.8f, 32200, this->position, 500, 2500);
    }
    if (next_state == 8) {
        func_80326310(this);
    }
    this->state = next_state;

}

void BGS_func_80386E30(ActorMarker *this, ActorMarker *other){
    Actor *thisActor = marker_getActor(this);
    if(thisActor->state < 6){
        func_80386AEC(thisActor, 4);
    }
}

void func_80386E70(ActorMarker *this, ActorMarker *other){
    Actor *thisActor = marker_getActor(this);
    if(thisActor->state < 6){
        func_80386AEC(thisActor, 5);
    }
}

void func_80386EB0(ActorMarker *this, ActorMarker *other){
    Actor *thisActor = marker_getActor(this);
    if(thisActor->state < 6){
        func_80386AEC(thisActor, 6);
    }
}

Actor *chflibbit_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    ActorLocal_Flibbit *local;
    s32 temp_a0;
    int i;
    f32 sp7C[3];
    f32 phi_f2;

    this = marker_getActor(marker);
    local = (ActorLocal_Flibbit *)&this->local;
    if (local->unk0){
        if(((this->state == 1)) || (this->state == 3)) {
            temp_a0 = func_803356A0(this->unk148);
            for(i = 0; i < 2; i++){
                
                if (0.1 <= local->unk1C[i]) {
                    phi_f2 = (f32) ((local->unk1C[i] - 0.1) / 0.1);
                } else if (local->unk1C[i] >= 0.0f) {
                    phi_f2 = (f32) (1.0 - (local->unk1C[i] / 0.1));
                } else {
                    phi_f2 = 1.0f;
                }
                sp7C[0] = 1.0f;
                // sp7C[1] = 1.0f;
                sp7C[2] = 1.0f;
                sp7C[1] = (f32) (((f64) phi_f2 * 0.99) + 0.01);

                func_8033A928(temp_a0, (i != 0)?0x2D :0x2E, sp7C);
            }
        }
    }
    func_80325888(marker, gfx, mtx, vtx);
    local->unk0 = marker->unk14_21;

    return this;
}

void chflibbit_update(Actor *this){
    f32 player_position[3];
    f32 spB0[3];
    f32 player_distance;
    ActorLocal_Flibbit *local = (ActorLocal_Flibbit *)&this->local;
    f32 spA4 = time_getDelta();
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp84[3];
    f32 temp_f12;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp68[3];
    f32 phi_f2;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp4C[3];

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        marker_setCollisionScripts(this->marker, BGS_func_80386E30, func_80386E70, func_80386EB0);
        local->unk1C[0] = randf2(-2.0f, -1.0f);
        local->unk1C[1] = randf2(-2.0f, -1.0f);

        local->unkE[0] = (s16) this->position_x;
        local->unkE[1] = (s16) this->position_y;
        local->unkE[2] = (s16) this->position_z;
        
        local->unkE[1] = func_80309724(this->position);
        func_80386AEC(this, 1);
    }
    player_getPosition(player_position);

    spB0[0] = player_position[0] - this->position[0];
    spB0[1] = player_position[1] - this->position[1];
    spB0[2] = player_position[2] - this->position[2];
    player_distance = gu_sqrtf(spB0[0]*spB0[0] + spB0[1]*spB0[1] + spB0[2]*spB0[2]);

    if(func_8025773C(&local->unk24, spA4)){
        func_8030E878(0x3f0, randf2(0.9f, 1.1f), randi2(12000, 19000), this->position, 500.0f, 2500.0f);
        local->unk24 = randf2(1.0f, 6.0f);
    }//L80387274

    local->unk1C[0] += spA4;
    local->unk1C[0] = (0.2 < local->unk1C[0]) ? randf2(-3.0f, -1.0f) : local->unk1C[0];

    local->unk1C[1] += spA4;
    local->unk1C[1] = (0.2 < local->unk1C[1]) ? randf2(-3.0f, -1.0f) : local->unk1C[1];

    if(this->state == 1){
        if(func_80329210(this, player_position)){
            func_80386AEC(this, 2);
            return;
        }

        if(player_distance < 2000.0f){
            func_80258A4C(this->position, this->yaw - 90.0f, player_position, &spA0, &sp9C, &sp98);
            this->yaw += (sp98*90.0f) *spA4; 
        }
    }//L803873D0

    if(this->state == 2){
        func_8033568C(this->unk148, &sp94, &sp90);
        if(sp94 < 0.8 && 0.8 <= sp90){
            func_8030E878(SFX_8_BANJO_LANDING_04, randf2(0.8f, 0.9f), randi2(25000, 27000), this->position, 100.0f, 1500.0f);
        }//L8038747C
        if(func_80335794(this->unk148) > 0){
            sp84[0]  = (f32)local->unkE[0];
            sp84[1]  = (f32)local->unkE[1];
            sp84[2]  = (f32)local->unkE[2];
            if(ml_vec3f_distance(this->position, sp84) < 30.0f){
                func_80386AEC(this, 1);
            }
            else{
                func_80386AEC(this, 2);

            }
        }
        else{//L80387514
            if(0.2 <= sp90 && sp90 <= 0.8){
                temp_f12 = ((sp90 - 0.2) / 0.60000000000000009);
                this->position_x = local->unk2[0] + (local->unk8[0] - local->unk2[0])*temp_f12;
                this->position_y = local->unk2[1] + (local->unk8[1] - local->unk2[1])*temp_f12;
                this->position_z = local->unk2[2] + (local->unk8[2] - local->unk2[2])*temp_f12;
                if(local->unk1){
                    if(sp90 <= 0.5){
                        phi_f2 = ((sp90 - 0.2)/0.3) * 70.0;
                    }
                    else{
                        phi_f2 = (1.0 - (sp90 - 0.5)/ 0.30000000000000004) *70.0;
                    }
                    this->position_y += phi_f2;
                }//L80387684
                sp68[0] =  (f32)(local->unk8[0] - local->unk2[0]);
                sp68[1] =  (f32)(local->unk8[1] - local->unk2[1]);
                sp68[2] =  (f32)(local->unk8[2] - local->unk2[2]);
                func_80258A4C(D_803906B4, this->yaw - 90.0f, sp68, &sp7C, &sp78, &sp74);
                this->yaw += (sp74 * 220.0f * spA4);

            }
        }
    }//L80387734

    if (this->state == 3) {
        func_80258A4C(this->position, this->yaw - 90.0f, player_position, &sp60, &sp5C, &sp58);
        this->yaw += sp58 * 90.0f * spA4;
        if ((-0.4 <= sp58) && (sp58 <= 0.4) && ((f64) randf() > 0.5)) {
            func_80386AEC(this, 2);
        }
        if ((sp5C < 0.0f) && (randf() > 0.5)) {
            func_80386AEC(this, 2);
        }
    }


    if(this->state == 4 || this->state == 5){
        if(func_8025773C(&local->unk18, spA4)){
            func_80386AEC(this, 3);
        }
    }

    if(this->state == 6){
        sp4C[0] = this->position[0] - player_position[0];
        sp4C[1] = this->position[1] - player_position[1];
        sp4C[2] = this->position[2] - player_position[2];
        sp4C[1] = 0.0f;
        ml_vec3f_set_length(sp4C, 400.0f * spA4);

        this->position[0] = this->position[0] + sp4C[0];
        this->position[1] = this->position[1] + sp4C[1];
        this->position[2] = this->position[2] + sp4C[2];

        this->position_y += local->unk14*spA4;
        local->unk14 -= 3000.0f*spA4;
        if(this->position_y  < func_80309724(this->position)){
            this->position_y  = func_80309724(this->position);
            func_80386AEC(this, 7);
        }
    }

    if(this->state == 7){
        if(func_80335794(this->unk148) > 0)
            func_80386AEC(this, 8);
    }
}
