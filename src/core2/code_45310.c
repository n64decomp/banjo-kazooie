#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

extern f32 func_8025715C(f32, f32);
extern f32 func_802575BC(f32);
extern f32 func_80309B24(f32[3]);
extern void sfxsource_playSfxAtVolume(u8, f32);
extern void func_802CC340(Actor *, f32[3]);
extern bool func_80320DB0(f32[3], f32, f32[3], u32);

typedef struct {
    u8 unk0;
    f32 unk4;
    f32 unk8[3];
    f32 unk14;
    f32 unk18[3];
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    s16 unk30[3];
    s16 unk36;
    u8 unk38;
    u8 unk39;
    u8 unk3A;
}ActorLocal_Core2_45310;

Actor *func_802CCA7C(ActorMarker *, Gfx **, Mtx **, Vtx **);
void func_802CCC5C(Actor *this);

/* .data */
ActorInfo D_80367130 = { 
    MARKER_C2_BUZZBOMB, ACTOR_134_BUZZBOMB, ASSET_3ED_MODEL_BUZZBOMB, 
    0, NULL, 
    func_802CCC5C, NULL, func_802CCA7C, 
    0, 0, 1.0f, 0
}; 


/* .code */
bool func_802CC2A0(Actor *this) {
    ActorLocal_Core2_45310 * local;
    s32 pad30;
    f32 sp2C[3];
    f32 sp20[3];

    local = (ActorLocal_Core2_45310 *)&this->local;
    if (!this->marker->unk14_21) {
        return TRUE;
    }
    ml_interpolate_vec3f(sp20, local->unk8, local->unk18, func_802575BC(local->unk4 + 0.05));
    sp20[1] += 60.0f;
    return func_80320DB0(sp20, 50.0f, sp2C, 0) == 0;
}

void func_802CC340(Actor *this, f32 arg1[3]) {
    ActorLocal_Core2_45310 * local;
    f32 phi_f2;
    f32 sp1C[3];

    local = (ActorLocal_Core2_45310 *)&this->local;
    local->unk3A = 2;
    local->unk4 = 0.0f;
    local->unk8[0] = this->position[0];\
    local->unk8[1] = this->position[1];\
    local->unk8[2] = this->position[2];
    local->unk18[0] = arg1[0];
    local->unk18[1] = arg1[1];
    local->unk18[2] = arg1[2];
    local->unk14 = this->yaw;
    local->unk14 =(local->unk14 >= 360.0f) ? local->unk14 - 360.0f : local->unk14;
    local->unk14 =(local->unk14 <= -360.0f) ? local->unk14 + 360.0f : local->unk14;
    local->unk24 = local->unk14;
    sp1C[0] = local->unk18[0] - local->unk8[0];
    sp1C[1] = local->unk18[1] - local->unk8[1];
    sp1C[2] = local->unk18[2] - local->unk8[2];
    phi_f2 = func_8025715C(sp1C[0], sp1C[2]);
    if ((phi_f2 - local->unk14) > 180.0f) {
        phi_f2 = phi_f2 - 360.0f;
    }
    if ((phi_f2 - local->unk14) < -180.0f) {
        phi_f2 = phi_f2 + 360.0f;
    }
    local->unk24 = phi_f2;
}


void func_802CC4A4(Actor *this, f32 arg1[3]) {
    ActorLocal_Core2_45310 * local;
    f32 sp28;
    f32 sp1C[3];
    f32 phi_f2;
    f32 phi_f12;

    local = (ActorLocal_Core2_45310 *)&this->local;
    local->unk18[0] = arg1[0];
    local->unk18[1] = arg1[1];
    local->unk18[2] = arg1[2];
    sp1C[0] = local->unk18[0] - local->unk8[0];
    sp1C[1] = local->unk18[1] - local->unk8[1];
    sp1C[2] = local->unk18[2] - local->unk8[2];
    phi_f2 = func_8025715C(sp1C[0], sp1C[2]);
    phi_f12 = phi_f2 - local->unk14;
    if(phi_f12 > 180.0f){
        phi_f2 = phi_f2 - 360.0f;
    }
    else if(phi_f12 < -180.0f){
        phi_f2 = phi_f2 + 360.0f;
    }
    local->unk24 = phi_f2;
}


bool func_802CC57C(Actor *this, f32 arg1[3]) {
    ActorLocal_Core2_45310 * local;
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];
    s32 sp24;

    local = (ActorLocal_Core2_45310 *)&this->local;
    sp40[0] = arg1[0];
    sp40[1] = arg1[1];
    sp40[2] = arg1[2];
    sp28[0] = this->position[0];
    sp28[1] = this->position[1] + 30.0f;
    sp28[2] = this->position[2];
    if (local->unk39 > 0) {
        local->unk39--;
        return 0;
    }
    sp24 = func_80309B48(sp28, sp40, sp34, 0);
    if (sp24 != 0) {
        local->unk39 = randi2(5, 0xA);
    } else {
        local->unk39 = 0;
    }
    return sp24 == 0;
}


void func_802CC640(Actor *this, s32 next_state) {
    ActorLocal_Core2_45310 * local;
    s32 phi_s0;
    f32 sp54[3];
    f32 sp48[3];

    local = (ActorLocal_Core2_45310 *)&this->local;
    if (this->state == 0) {
        skeletalAnim_set(this->unk148, 0xF9, 0.0f, 0.45f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
    }
    this->state = next_state;
    local->unk36 = 0;
    local->unk28 = 0.0f;

    if (this->state == 1) {
        local->unk28 = randf2(0.0f, 2.0f);
    }

    if (this->state == 2) {
        skeletalAnim_set(this->unk148, 0xF9, 0.3f, 0.45f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        for(phi_s0 = 0; phi_s0 < 10; phi_s0++){
            sp54[0] = this->position[0];
            sp54[1] = (f32) local->unk30[1];
            sp54[2] = this->position[2];
            sp54[0] += randf2(-300.0f, 300.0f);
            sp54[1] += randf2(100.0f, 300.0f);
            sp54[2] += randf2(-300.0f, 300.0f);
            if(func_80329210(this, sp54)){
                break;
            }
        }
        if (phi_s0 == 0xA) {
            sp54[0] = (f32) local->unk30[0];
            sp54[1] = (f32) local->unk30[1];
            sp54[2] = (f32) local->unk30[2];
            sp54[1] += 200.0f;
        }
        func_802CC340(this, sp54);
    }
    if (this->state == 3) {
        player_getPosition(sp48);
        sp48[1] += 90.0f;
        func_802CC340(this, sp48);
    }

    if (this->state == 5) {
        func_8028F55C(1, this->marker);
        FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 1.2f, 32200);
        skeletalAnim_set(this->unk148, 0xF9, 0.4f, 1.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        timed_playSfx(0.8f, 0x3FC, randf2(0.97f, 1.05f), 32000);
        local->unk3A = 0;
        local->unk28 = 2.0f;
    }

    if (this->state == 4) {
        local->unk28 = 3.5f;
    }

    if (this->state == 6) {
        this->unk138_27 = 1;
        this->marker->collidable = FALSE;
        this->unk10_1 = FALSE;
        FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 1.2f, 32200);
        skeletalAnim_set(this->unk148, 0x110, 0.3f, 0.45f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        local->unk36 = 0x3E8;
        local->unk3A = 0;
    }

    if (this->state == 7) {
        local->unk2C = 0.0f;
    }

    if (this->state == 8) {
        marker_despawn(this->marker);
    }
}

void func_802CC9FC(ActorMarker *marker, ActorMarker *other){
    Actor *this;

    this = marker_getActor(marker);
    if (this->state < 5) {
        func_802CC640(this, 5);
    }
}

void func_802CCA3C(ActorMarker *marker, ActorMarker *other){
    Actor *this;

    this = marker_getActor(marker);
    if (this->state < 6U) {
        func_802CC640(this, 6);
    }
}

Actor *func_802CCA7C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;
    ActorLocal_Core2_45310 * local;

    this = marker_getActor(marker);
    local = (ActorLocal_Core2_45310 *)&this->local;
    if (this->state == 0) {
        return this;
    }
    this->unk124_11 = 1;
    if (this->state == 7) {
        this->alpha_124_19 = (1.0f - local->unk2C) * 255.0f;
    } else {
        this->alpha_124_19 = 0xff;
    }
    return actor_draw(marker, gfx, mtx, vtx);
}

void func_802CCBC8(Actor *this) {
    ActorLocal_Core2_45310 * local;

    local = (ActorLocal_Core2_45310 * )&this->local;
    if(local->unk0 != 0){
        func_8030DA44(local->unk0);
    }
}

void func_802CCBF4(Actor *this) {
    ActorLocal_Core2_45310 * local;

    local = (ActorLocal_Core2_45310 * )&this->local;
    local->unk0 = sfxsource_createSfxsourceAndReturnIndex();
    sfxsource_playSfxAtVolume(local->unk0, 0.9f);
    sfxsource_setSfxId(local->unk0, 0x3FA);
    func_8030DD14(local->unk0, 2);
    sfxsource_setSampleRate(local->unk0, 0);
}

void func_802CCC5C(Actor *this) {
    f32 spC4[3];
    ActorLocal_Core2_45310 * local;
    s32 spBC;
    f32 spB8;
    f32 temp_f0;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 phi_f12;
    f32 phi_f2;
    f32 sp9C;
    f32 sp30;
    f32 sp8C[3];
    f32 sp80[3];
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp58;
    f32 sp4C[3];
    f32 sp40[3];
    

    spBC = 0;
    spB8 = time_getDelta();
    local = (ActorLocal_Core2_45310 * )&this->local;
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->marker->actorFreeFunc = func_802CCBC8;
        local->unk38 = 0;
        local->unk39 = 0;
        local->unk3A = 0;
        local->unk28 = 0.0f;
        marker_setCollisionScripts(this->marker, func_802CC9FC, NULL, func_802CCA3C);
        local->unk30[0] = (s16) this->position[0];
        local->unk30[1] = (s16) this->position[1];
        local->unk30[2] = (s16) this->position[2];
        local->unk30[1] = (s16) mapModel_getFloorY(this->position);
        temp_f0 = func_80309B24(this->position);
        if (local->unk30[1] < temp_f0) {
            local->unk30[1] = (s16) (s32) temp_f0;
        }
        local->unk0 = 0;
        func_802CC640(this, 1);
    }
    if (!subaddie_playerIsWithinSphere(this, 4000)) {
        if (local->unk0 != 0) {
            func_8030DA44(local->unk0);
            local->unk0 = 0;
        }
    } else {
        if (local->unk0 == 0) {
            func_802CCBF4(this);
        }
        player_getPosition(spC4);
        if(this->state != 0){
            if (this->state < 6) {
                spB0 =  func_8030E200(local->unk0);
                if (local->unk3A == 1) {
                    spAC = 0.9f;
                    spA8 = 1.0f;
                } else {
                    spAC = 0.8f;
                    spA8 = 0.9f;
                }
                if (spB0 < spAC) {
                    spB0 = spB0 + 0.02;
                } else if (spA8 < spB0) {
                    spB0 = spB0 - 0.02;
                } else {
                    spB0 += randf2(-0.05, 0.05);
                    spB0 = (spB0 < spAC) ? spAC : MIN(spA8 , spB0);
                }
                sfxsource_playSfxAtVolume(local->unk0, spB0);
                phi_f12 = 1.0f - ml_distance_vec3f(spC4, this->position) / 2000.0f;
                if(0.0f > phi_f12){
                    phi_f12 = 0.0f;
                }
                if (phi_f12 > 0.0f) {
                    sfxsource_setSampleRate(local->unk0, (s32) (phi_f12 * 10000.0f));
                    func_8030E2C4(local->unk0);
                }
            }
        }
        if (this->unk10_25 != 0) {
            if (ml_timer_update(&local->unk28, spB8) != 0) {
                spBC = 2;
            }
            if (local->unk3A == 2) {
                if (this->state == 3) {
                    local->unk4 += 2 * spB8;
                } else {
                    local->unk4 += 1 * spB8;
                }
                if (local->unk4 >= 1.0f) {
                    local->unk4 = 1.0f;
                    if (volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)) {
                        local->unk3A = 0;
                    } else {
                        if (this->state == 2) {
                            local->unk3A = 1;
                        } else if (this->state == 3) {
                            if (skeletalAnim_getAnimId(this->unk148) != 0x10E) {
                                skeletalAnim_set(this->unk148, 0x10E, 0.2f, 0.75f);
                                skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
                            } else if (0.575 <= skeletalAnim_getProgress(this->unk148)) {
                                local->unk3A = 1;
                            }
                        }
                    }
                }
                if (local->unk3A == 2) {
                    sp9C = func_802575BC(local->unk4);
                    this->yaw = local->unk14 + (sp9C*(local->unk24 - local->unk14));
                } else {
                    local->unk4 = 0.0f;
                    local->unk14 = (f32) local->unk24;
                }
            }
            if (local->unk3A == 1) {
                sp30 = 1 * spB8;
                if ( !func_802CC2A0(this) 
                     || ((this->state == 3) && !func_80329210(this, this->position))) {
                    local->unk18[0] = this->position[0];
                    local->unk18[1] = this->position[1];
                    local->unk18[2] = this->position[2];
                    local->unk4 = 1.0f;
                }
                local->unk4 += sp30;
                if (local->unk4 >= 1.0f) {
                    local->unk3A = 0;
                    local->unk4 = 1.0f;
                }
                sp9C = func_802575BC(local->unk4);
                ml_interpolate_vec3f(this->position, local->unk8, local->unk18, sp9C);
                this->yaw = local->unk14 + (sp9C * (local->unk24 - local->unk14));
                if ((skeletalAnim_getAnimId(this->unk148) == 0x10E) && (skeletalAnim_getLoopCount(this->unk148) > 0)) {
                    skeletalAnim_set(this->unk148, 0x10F, 0.1f, 0.45f);
                    skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
                }
                if( (local->unk3A == 0) 
                    || ((skeletalAnim_getAnimId(this->unk148) == 0x10F) && (0.7 <= local->unk4))) {
                    skeletalAnim_set(this->unk148, 0xF9, 0.3f, 0.45f);
                    skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
                }
                if (this->state == 3) {
                    if (0.2 <= local->unk4) {
                        if (0.8 < local->unk4) {
                            phi_f2 = 0.0f;
                        } else {
                            phi_f2 = 1.0 - ((local->unk4 - 0.2) / 0.6);
                        }
                        sfxsource_playSfxAtVolume(local->unk0, phi_f2 * 0.3999999999999999 + 1.0);
                    }
                }
            }
            if (this->state == 1) {
                player_getPosition(sp8C);
                viewport_getPosition_vec3f(sp80);
                viewport_getLookVector(sp74);
                sp5C[0] = this->position[0] - sp80[0];
                sp5C[1] = this->position[1] - sp80[1];
                sp5C[2] = this->position[2] - sp80[2];
                sp58 = sp74[0] * sp5C[0] + sp74[1] * sp5C[1] + sp74[2] * sp5C[2];
                sp8C[1] += 90.0f;
                if( func_80329210(this, sp8C) 
                    && (sp8C[1] < (local->unk30[1] + 0x12C)) 
                    && !func_8028F25C()
                    && (sp58 > 800.0f) 
                    && (this->marker->unk14_21) 
                    && (player_getWaterState() != BSWATERGROUP_2_UNDERWATER) 
                    && func_802CC57C(this, sp8C)
                ) {
                    sp8C[0] = 0.0f;
                    sp68[0] = this->position[0];
                    sp68[1] = this->position[1];
                    sp68[2] = this->position[2];
                    sp68[0] = 0.0f;
                    if (ml_distance_vec3f(sp8C, sp68) < 800.0f) {
                        spBC = 3;
                    }
                }
            }
            if ((this->state == 2) && (local->unk3A == 0)) {
                spBC = 1;
            }
            if (this->state == 3) {
                if (func_8028F25C() || (player_getWaterState() == BSWATERGROUP_2_UNDERWATER)) {
                    func_802CC640(this, 4);
                } else {
                    if (local->unk3A == 0) {
                        local->unk38++;
                        if (local->unk38 == 3) {
                            spBC = 4;
                            local->unk38 = 0;
                        } else {
                            spBC = 1;
                        }
                    } else if ((local->unk3A == 2) || (local->unk4 < 0.5)) {
                        sp4C[0] = spC4[0];
                        sp4C[1] = spC4[1];
                        sp4C[2] = spC4[2];
                        sp4C[1] += 50.0f;
                        func_802CC4A4(this, sp4C);
                    }
                }
            }

            if ((this->state == 5) || (this->state == 4)) {
                this->position[1] += 50.0f * spB8;
                this->yaw += 10.0f * spB8;
            }
            if (this->state == 6) {
                if (skeletalAnim_getAnimId(this->unk148) == 0x110) {
                    sp40[0] = this->position[0] - spC4[0];
                    sp40[1] = this->position[1] - spC4[1];
                    sp40[2] = this->position[2] - spC4[2];
                    sp40[1] = 0.0f;
                    ml_vec3f_set_length(sp40, 200.0f * spB8);
                    this->position[0] = this->position[0] + sp40[0];
                    this->position[1] = this->position[1] + sp40[1];
                    this->position[2] = this->position[2] + sp40[2];
                    this->position[1] += local->unk36 * spB8;
                    local->unk36 -= 3000.0f * spB8;
                    if (this->position[1] < mapModel_getFloorY(this->position)) {
                        this->position[1] = mapModel_getFloorY(this->position);
                        skeletalAnim_set(this->unk148, 0x111, 0.1f, 1.0f);
                        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
                        FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 1.2f, 32200);
                        timed_playSfx(0.1f, SFX_66_BIRD_AUUGHH, 1.6f, 32000);
                    }
                } else if (skeletalAnim_getLoopCount(this->unk148) > 0) {
                    spBC = 7;
                }
            }
            if (this->state == 7) {
                local->unk2C += 0.5 * spB8;
                if (local->unk2C >= 1.0f) {
                    spBC = 8;
                }
            }
            if (spBC != 0) {
                func_802CC640(this, spBC);
            }
        }
    }
}
