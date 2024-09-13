#include <ultra64.h>
#include "functions.h"
#include "variables.h"



//external
f32 mapModel_getFloorY(f32*);
void func_802C4218(s32, f32, f32, f32);
void func_803252D0(f32, s32);
void subaddie_set_state_with_direction(Actor *, s32, f32, s32);

//typedefs
typedef struct ch_vegatable{
    TUPLE(f32, unk0);
    s32 unkC;
    u32 pad10_31: 19;
    u32 unk10_12: 4;
    u32 pad10_8: 9;
} ChVeg;

//public
Actor *func_80387DF4(ActorMarker *, Gfx**, Mtx**, Vtx **);
void func_80388080(Actor *);

/* .data */
ActorAnimationInfo chCarrotAnimations[5] = {
    {0, 0.0f},
    {0x223, 1000000.0f},
    {0x223, 1.0f},
    {0x224, 0.75f},
    {0x223, 1.0f}
};

ActorInfo D_8038AC78 = { MARKER_12A_TOPPER_A, ACTOR_166_TOPPER_A, MODEL_TOPPER, 1, chCarrotAnimations,
    func_80388080, func_80326224, func_80387DF4,
    2000, 0, 1.0f, 0
};

ActorInfo D_8038AC9C = { MARKER_1E6_TOPPER_B, ACTOR_TOPPER_B, MODEL_TOPPER, 1, chCarrotAnimations,
    func_80388080, func_80326224, func_80387DF4,
    2000, 0, 1.0f, 0
};

ActorAnimationInfo chOnionAnimations[5] = {
    {0, 0.0f},
    {0x226, 1000000.0f},
    {0x226, 1.0f},
    {0x227, 0.75f},
    {0x226, 1.0f}
};

ActorInfo D_8038ACE8 = { MARKER_129_BAWL_A, ACTOR_165_BAWL_A, MODEL_BAWL, 1, chOnionAnimations,
    func_80388080, func_80326224, func_80387DF4,
    0, 0, 1.0f, 0
};

ActorInfo D_8038AD0C = { MARKER_1E7_BAWL_B, ACTOR_BAWL_B, MODEL_BAWL, 1, chOnionAnimations,
    func_80388080, func_80326224, func_80387DF4,
    0, 0, 1.0f, 0
};

ActorAnimationInfo chCauliflowerAnimations[5] = {
    {0, 0.0f},
    {0x225, 10000000.0f},
    {0x225, 1.0f},
    {0x225, 10000000.0f},
    {0x225, 1.0f}
};

ActorInfo D_8038AD58 = { MARKER_128_COLLYWOBBLE_A, ACTOR_164_COLLYWOBBLE_A, MODEL_COLLYWOBBLE, 1, chCauliflowerAnimations,
    func_80388080, func_80326224, func_80387DF4,
    0, 0, 2.0f, 0
};

ActorInfo D_8038AD7C = { MARKER_1E8_COLLYWOBBLE_B, ACTOR_COLLYWOBBLE_B, MODEL_COLLYWOBBLE, 1, chCauliflowerAnimations,
    func_80388080, func_80326224, func_80387DF4,
    0, 0, 2.0f, 0
};

s32 D_8038ADA0[3] = {0xFF, 0xFF, 0xFF}; 

ParticleScaleAndLifetimeRanges D_8038ADAC = {
    {0.1f, 0.5f}, 
    {1.5f, 3.0f}, 
    {0.0f, 0.01f}, 
    {1.0f, 1.5f}, 
    0.0f, 0.01f,
};

struct42s D_8038ADD4 = {
    {{-100.0f, -100.0f, -100.0f}, {100.0f, 100.0f, 100.0f}},
    {{-40.0f, -40.0f, -40.0f}, {40.0f, 40.0f, 40.0f}}
};

ParticleScaleAndLifetimeRanges D_8038AE04 = {
    {0.5f, 0.75f},
    {0.4f, 0.6f}, 
    {0.0f, 0.01f},
    {4.0f, 4.0f}, 
    0.0f, 0.2f
};

struct43s D_8038AE2C = {
    {{-100.0f, 200.0f, -100.0f}, {100.0f, 400.0f, 100.0f}}, 
    {{0.0f, -600.0f, 0.0f}, {0.0f, -600.0f, 0.0f}}, 
    {{-80.0f, -80.0f, -80.0f}, {80.0f, 80.0f, 80.0f}}
};

ParticleScaleAndLifetimeRanges D_8038AE74 = {
    {1.0f, 1.0f}, 
    {1.0f, 1.0f}, 
    {0.0f, 0.01f}, 
    {2.0f, 2.0f}, 
    0.0f, 0.5f
};

struct43s D_8038AE9C = {
    {{-100.0f, 400.0f, -100.0f}, {100.0f, 600.0f, 100.0f}}, 
    {{0.0f, -600.0f, 0.0f}, {0.0f, -600.0f, 0.0f}}, 
    {{-20.0f, -20.0f, -20.0f}, {20.0f, 20.0f, 20.0f}}
};

ParticleScaleAndLifetimeRanges D_8038AEE4 = {
    {0.6f, 0.8f}, 
    {0.5f, 0.7f}, 
    {0.0f, 0.01f}, 
    {4.0f, 4.0f}, 
    0.0f, 0.5f
};

struct43s D_8038AF0C ={
    {{-200.0f, 200.0f, -200.0f}, {200.0f, 600.0f, 200.0f}}, 
    {{0.0f, -900.0f, 0.0f}, {0.0f, -900.0f, 0.0f}}, 
    {{-100.0f, -100.0f, -100.0f}, {100.0f, 100.0f, 100.0f}}, 
};

/* .code */
void func_80387910(ParticleEmitter *arg0, f32 *arg1, s32 arg2){
    s32 sp24[3] = D_8038ADA0;
    particleEmitter_setRGB(arg0, sp24);
    particleEmitter_setSprite(arg0, ASSET_700_SPRITE_DUST);
    particleEmitter_setStartingFrameRange(arg0, 0, 7);
    particleEmitter_setPosition(arg0, arg1);
    particleEmitter_setScaleAndLifetimeRanges(arg0, &D_8038ADAC);
    particleEmitter_setPositionAndVelocityRanges(arg0, &D_8038ADD4);
    particleEmitter_emitN(arg0, arg2);
}

void func_803879B8(ParticleEmitter *arg0, f32 *arg1, s32 arg2, enum asset_e model_id){
    func_802EF9F8(arg0, 0.6f);
    func_802EFA18(arg0, 2);
    particleEmitter_setModel(arg0, model_id);
    particleEmitter_setPosition(arg0, arg1);
    particleEmitter_setDrawMode(arg0, 2);
    particleEmitter_setAngularVelocityRange(arg0, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    particleEmitter_setScaleAndLifetimeRanges(arg0, &D_8038AE04);
    particleEmitter_setPositionVelocityAndAccelerationRanges(arg0, &D_8038AE2C);
    particleEmitter_emitN(arg0, arg2);
}

void func_80387A80(ParticleEmitter *arg0, f32 *arg1, s32 arg2, enum asset_e model_id){
    func_802EF9F8(arg0, 0.6f);
    func_802EFA18(arg0, 3);
    particleEmitter_setModel(arg0, model_id);
    particleEmitter_setPosition(arg0, arg1);
    particleEmitter_setDrawMode(arg0, 2);
    particleEmitter_setAngularVelocityRange(arg0, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    particleEmitter_setScaleAndLifetimeRanges(arg0, &D_8038AE74);
    particleEmitter_setPositionVelocityAndAccelerationRanges(arg0, &D_8038AE9C);
    particleEmitter_emitN(arg0, arg2);
}

void func_80387B48(ParticleEmitter *arg0, f32 arg1[3], s32 arg2, enum asset_e model_id){
    func_802EF9F8(arg0, 0.7f);
    func_802EFA18(arg0, 4);
    particleEmitter_setModel(arg0, model_id);
    particleEmitter_setPosition(arg0, arg1);
    particleEmitter_setDrawMode(arg0, 2);
    particleEmitter_setAngularVelocityRange(arg0, 150.0f, -300.0f, -300.0f, 300.0f, 300.0f, -150.0f);
    particleEmitter_setSfx(arg0, SFX_1F_HITTING_AN_ENEMY_3, 8000);
    particleEmitter_setScaleAndLifetimeRanges(arg0, &D_8038AEE4);
    particleEmitter_setPositionVelocityAndAccelerationRanges(arg0, &D_8038AF0C);
    particleEmitter_emitN(arg0, arg2);
}

void func_80387C28(Actor * this){
    ChVeg * local = (ChVeg *)&this->local;
    f32 sp30[3];

    FUNC_8030E8B4(SFX_111_WHIPCRACK_DEATH, 1.0f, 32000, this->position, 1000, 2000);
    if(local->unkC == 3){
        sp30[0] = this->position_x;
        sp30[1] = this->position_y;
        sp30[2] = this->position_z;
        sp30[1] += 50.0f;
        func_80387B48(partEmitMgr_newEmitter(0xC), sp30, 0xC, 0x4F4);
        func_803879B8(partEmitMgr_newEmitter(4), sp30, 0x4, 0x4F2);
        func_803879B8(partEmitMgr_newEmitter(4), sp30, 0x4, 0x4F3);
        sp30[1] += 50.0f;
        func_80387910(partEmitMgr_newEmitter(8), sp30, 8);
    }//L80387D18
    if(this->unk38_31){
        this->position_y += 100.0f;
        func_802CA1CC(HONEYCOMB_17_SM_COLIWOBBLE);
        __spawnQueue_add_4((GenFunction_4)func_802C4218, 0x1f, reinterpret_cast(s32, this->position_x), reinterpret_cast(s32, this->position_y), reinterpret_cast(s32, this->position_z));
    }//L80387D64
    func_803252D0(1.5f, 7);
    actor_collisionOff(this);
    if(local->unkC != 3){
        subaddie_set_state_with_direction(this, 3, 0.0f, 1);
        actor_playAnimationOnce(this);
    }
    else{
        marker_despawn(this->marker);
    }
}

void func_80387DCC(ActorMarker *marker, ActorMarker *other_marker){
    func_80387C28(marker_getActor(marker));
}

Actor *func_80387DF4(ActorMarker *marker, Gfx **gdl, Mtx **mptr, Vtx **arg3){
    Actor *actor = marker_getActor(marker);

    if(actor->is_first_encounter)
        func_8033A470(3, 7);
    else
        func_8033A45C(3, 0);

    return actor_draw(marker, gdl, mptr, arg3);
}

void func_80387E64(Actor *this){
    ChVeg *local = (ChVeg *)&this->local;

    this->unk1C_x = randf2(-50.0f, 50.0f);
    this->unk1C_y = randf2(-50.0f, 50.0f);
    this->unk1C_z = randf2(-50.0f, 50.0f);

    this->unk1C_x = local->unk0_x + this->unk1C_x;
    this->unk1C_y = local->unk0_y + this->unk1C_y;
    this->unk1C_z = local->unk0_z + this->unk1C_z;
}

void func_80387F00(Actor *this){
    ChVeg *local = (ChVeg *)&this->local;
    
    this->position_y += (mapSpecificFlags_get(0xC) || volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)) ? 120.0 : 180.0;
    local->unk0_x = this->position_x;
    local->unk0_y = this->position_y;
    local->unk0_z = this->position_z;
    this->velocity_x = 0.0f;
    this->velocity_y = 0.0f;
    this->velocity_z = 0.0f;
    func_80387E64(this);
}

int func_80387FA8(Actor *this, ChVeg *local, s32 yaw, s32 arg3){
    f32 sp24[3];
    f32 sp18[3];
    
    sp18[0] = arg3;
    sp18[1] = 0.0f;
    sp18[2] = 0.0f;
    ml_vec3f_yaw_rotate_copy(sp18, sp18, yaw - 90.0);
    sp24[0] = sp18[0] + local->unk0_x;
    sp24[1] = sp18[1] + local->unk0_y;
    sp24[2] = sp18[2] + local->unk0_z;
    if(func_80307258(sp24, this->unk10_25 - 1, this->unk10_18 - 1) == -1)
        return 0;
    else
        return 1;
}

void func_80388080(Actor *this){
    f32 temp_velZ;
    f32 temp_velX;
    f32 temp_f0;
    f32 sp78;
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    ChVeg *local = (ChVeg *)&this->local; //sp38
    f32 sp30;

    

    if(!this->initialized){
        switch(this->marker->id){
            default:
                local->unkC = 3; //cauliflower
                break;
            case 0x12A: //L803880F0
            case 0x1E6: //L803880F0
                local->unkC = 1; //carrot
                break;
            case 0x129: //L80388100
            case 0x1E7: //L80388100
                local->unkC = 2; //onion
                break;
        }
        actor_collisionOff(this);
        marker_setCollisionScripts(this->marker, NULL, NULL, func_80387DCC);
        this->unk1C_x = this->position_x;
        this->unk1C_y = this->position_y;
        this->unk1C_z = this->position_z;
        this->position_y -= 200.f;

        do{//L80388154
            temp_velX = randf2(-10.0f, 10.0f);
            temp_f0 =(0.0f <= temp_velX) ? temp_velX : -temp_velX;
        }while(temp_f0 < 5.0);

        do{//L803881AC
            temp_velZ = randf2(-10.0f, 10.0f);
            temp_f0 =(0.0f <= temp_velZ) ? temp_velZ : -temp_velZ;
        }while(temp_f0 < 5.0);

        this->velocity_x = temp_velX;
        this->velocity_y = (local->unkC == 3) ? 90.0f : 70.0f;
        this->velocity_z = temp_velZ;
        this->is_first_encounter = TRUE;
        this->unk138_23 = 0;
        this->unk38_0 = 0;
        this->initialized = TRUE;
        this->scale = 0.5;
    }//L80388278
    switch (this->state)
    {
    case 1: //L803882B0
        if(mapSpecificFlags_get(0xC) || volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE) || this->unk10_12){
            //L803882E4
            if(mapSpecificFlags_get(0xC) || volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)){ //L8038830C
                this->unk1C_y += (local->unkC == 3)? 120.0 : 0.0;
            }else{//L80388350
                this->unk1C_y += (local->unkC == 3)? 270.0 : 85.0;
            }
            //L80388384
            subaddie_set_state(this, 4);
        }
        break;
    case 4: //L8038839C
        this->position_x = this->velocity_x + this->position_x;
        this->position_y = this->velocity_y + this->position_y;
        this->position_z = this->velocity_z + this->position_z;
        this->velocity_y -= 5.0f;
        this->scale = MIN(this->scale + 0.05, 1.0);
        if(this->velocity_y < 0.0f && this->position_y < this->unk1C_y){
            this->position_y = mapModel_getFloorY(this->position);
            if(local->unkC == 3)
                func_80387F00(this);

            actor_collisionOn(this);
            subaddie_set_state(this, 2);
        }//L80388494

        if(!this->unk138_23){
            if(0.0f < this->position_y){
                FUNC_8030E8B4(SFX_C5_TWINKLY_POP, 1.0f, 32000, this->position, 1000, 2000);
                this->unk138_23 = 1;
                this->scale = 1.0f;
            }
        }

        break;
    case 2: //L803884E4
        if(this->unk38_0){
            if(func_80329480(this)){
                this->unk38_0 = 0;
            }
        }else{//L80388520
            if(local->unkC == 1){
                this->unk28 = 3.0f;
                if(mapSpecificFlags_get(0xC) || volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)){//L80388554
                    if(!func_80329030(this, 0) && func_80329480(this)){
                        func_80328CEC(this, (s32)this->yaw, 0x78, 0xb4);
                        this->unk38_0 = 1;
                    }//L803885A0
                    if(func_803292E0(this)){
                        this->yaw_ideal = func_80329784(this);
                    }
                    else{//L803885CC
                        if(randf() < 0.02){
                            func_80328CEC(this, (s32)this->yaw, 0x1E, 0x5A);
                        }
                    }//L80388B68
                }
                else{//L80388618
                    this->yaw_ideal = func_80329784(this);
                }
            }
            else if(local->unkC == 2){//L80388634
                this->unk28 = 4.0f;
                if(!func_80329030(this, 0) && func_80329480(this)){
                    func_80328CEC(this, (s32)this->yaw, 0x78, 0xB4);
                    this->unk38_0 = 1;
                }//L80388698
                if(mapSpecificFlags_get(0xC) || (volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE) && func_803292E0(this))){
                    this->yaw_ideal = func_80329784(this);
                }else{//L803886E4
                    if(randf() < 0.02){//D_8038B1D0){
                        func_80328CEC(this, (s32)this->yaw, 0x1E, 0x5A);
                    }
                }
            }else{//L80388730
                sp78 = time_getDelta();
                sp6C[0] = this->unk1C_x - this->position_x;
                sp6C[1] = this->unk1C_y - this->position_y;
                sp6C[2] = this->unk1C_z - this->position_z;
                if( gu_sqrtf(sp6C[0]*sp6C[0] + sp6C[1]*sp6C[1] + sp6C[2]*sp6C[2] ) < 40.0f){
                    ml_vec3f_set_length(sp6C, 400.0f);
                }
                else{
                    ml_vec3f_set_length(sp6C, 100.0f);
                }
                this->position_x += this->velocity_x*sp78 + sp6C[0]*sp78*sp78;
                this->position_y += this->velocity_y*sp78 + sp6C[1]*sp78*sp78;
                this->position_z += this->velocity_z*sp78 + sp6C[2]*sp78*sp78;
                this->velocity_x += sp6C[0]*sp78;
                this->velocity_y += sp6C[1]*sp78;
                this->velocity_z += sp6C[2]*sp78;
                if(gu_sqrtf(this->velocity_z*this->velocity_z + (this->velocity_x*this->velocity_x + this->velocity_y*this->velocity_y)) > 50.0f){
                    ml_vec3f_set_length(this->velocity, 50.0f);
                }
                if(ml_distance_vec3f(this->position, this->unk1C) < 20.0f){
                    func_80387E64(this);
                }
                this->unk28 = 5.0f;
                if(mapSpecificFlags_get(0xC) || (volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE))){ //L8038892C
                    if(!func_80387FA8(this, local, (s32)this->yaw, (s32)this->unk28)){
                        if(func_80329480(this)){
                            func_80328CEC(this, (s32)this->yaw, 0x78, 0xb4);
                            this->unk38_0 = 1;
                        }//L80388994
                    }else{ //L803889A0

                        this->position_x -= local->unk0_x;
                        this->position_y -= local->unk0_y; 
                        this->position_z -= local->unk0_z; 
                        this->unk1C_x -= local->unk0_x;
                        this->unk1C_y -= local->unk0_y;
                        this->unk1C_z -= local->unk0_z;
                        TUPLE_ASSIGN(sp60, this->unk28, 0.0f, 0.0f);
                        ml_vec3f_yaw_rotate_copy(sp60, sp60, this->yaw - 90.0);
                        local->unk0_x = sp60[0] + local->unk0_x;
                        local->unk0_y = sp60[1] + local->unk0_y;
                        local->unk0_z = sp60[2] + local->unk0_z;
                        this->position_x = local->unk0_x + this->position_x;
                        this->position_y = local->unk0_y + this->position_y;
                        this->position_z = local->unk0_z + this->position_z;
                        this->unk1C_x = local->unk0_x + this->unk1C_x;
                        this->unk1C_y = local->unk0_y + this->unk1C_y;
                        this->unk1C_z = local->unk0_z + this->unk1C_z;
                    }//L80388AD8
                    if(func_803292E0(this)){
                        this->yaw_ideal = func_80329784(this);
                    }else{//L80388B04
                        if(randf() < 0.01){
                            func_80328CEC(this, (s32)this->yaw, 0x1e, 0x5A);
                        }
                    }
                }else{
                    //L80388B50
                    this->yaw_ideal = func_80329784(this);
                }

            }
        }//L80388B68
        func_80328FB0(this, 2.0f);
        
        if(local->unkC != 3 && actor_animationIsAt(this, 0.3f))
            FUNC_8030E8B4(SFX_3F2_UNKNOWN, 1.0f, 22000, this->position, 1000, 2000);
        
        if(local->unkC == 3 && actor_animationIsAt(this, 0.4f)){
            FUNC_8030E8B4(SFX_2_CLAW_SWIPE, 0.9f, 8000, this->position, 1000, 2000);
        }
        break;
    case 3: //L80388BFC
        if(actor_animationIsAt(this, (local->unkC == 2) ? 0.4 : 0.05)){
            sp54[0] = this->position_x;
            sp54[1] = this->position_y;
            sp54[2] = this->position_z;
            if(local->unkC == 1)
                sp54[1] += 150.0f;
            this->is_first_encounter = FALSE;
            func_80387A80(partEmitMgr_newEmitter(3), sp54, 3, (local->unkC == 1)? 0x4f0: 0x4f1);
        }//L80388CC4
        
        if(actor_animationIsAt(this, 0.75f))
            func_80326310(this);
        break;
    }//L80388CE0
}//*/
