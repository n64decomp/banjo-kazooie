#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern bool func_80259254(f32[3], f32, f32, f32);

/* .data */
ActorAnimationInfo chCrabAnimations[] ={
    {    0, 0.0f},
    { ASSET_1DA_ANIM_CRAB_IDLE, 0.8f},
    { ASSET_2C_ANIM_CRAB_WALK, 2.0f},
    { ASSET_2C_ANIM_CRAB_WALK, 1.4f},
    { ASSET_2C_ANIM_CRAB_WALK, 0.7f},
    { ASSET_96_ANIM_CRAB_UPSIDEDOWN, 0.5f},
    { ASSET_97_ANIM_CRAB_FLIP_UPSIDEDOWN, 0.8f},
    { ASSET_155_ANIM_CRAB_FLIP_UPRIGHT, 0.55f},
    { ASSET_2C_ANIM_CRAB_WALK, 1.4f},
    { ASSET_2C_ANIM_CRAB_WALK, 4.0f}
};

ActorAnimationInfo chCrabMutantAnimations[] = {
    {0x000, 0.0f},
    {ASSET_1DB_ANIM_MUTANT_CRAB_IDLE, 0.8f},
    {ASSET_156_ANIM_MUTANT_CRAB_WALK, 2.0f},
    {ASSET_156_ANIM_MUTANT_CRAB_WALK, 1.4f},
    {ASSET_156_ANIM_MUTANT_CRAB_WALK, 0.7f},
    {ASSET_158_ANIM_MUTANT_CRAB_UPSIDEDOWN, 0.5f},
    {ASSET_157_ANIM_MUTANT_CRAB_FLIP_UPSIDEDOWN, 0.8f},
    {ASSET_159_ANIM_MUTANT_CRAB_UPRIGHT, 0.55f},
    {ASSET_156_ANIM_MUTANT_CRAB_WALK, 1.4f},
    {ASSET_156_ANIM_MUTANT_CRAB_WALK, 2.0f}
};

/* .code */
void __chCrab_802CB040(Actor *this) {
    this->unk28 = randf2(1.5f, 2.3f);
}

void __chCrab_802CB078(Actor *this) {
    u32 temp_t9;

    if ((this->modelCacheIndex != ACTOR_F2_BLACK_SNIPPET) || func_8038B550()) {
        temp_t9 = (u32) this->unk38_31 >> 0x16;
        if (this->unk38_31 != 0) {
            this->unk38_31--;
            return;
        }
        else{
            if( func_80329530(this, 1500) 
                && ( (this->modelCacheIndex == ACTOR_F2_BLACK_SNIPPET) || func_803292E0(this))
            ) {
                this->unk28 = 0.0f;
                subaddie_set_state(this, 3U);
            }
        }
    }
}

void __chCrab_802CB140(Actor *this) {
    subaddie_set_state(this, 2U);
    __chCrab_802CB040(this);
    func_80328CEC(this, (s32) this->yaw_ideal, 135, 175);
    this->unk38_31 = 150;
}

void __chCrab_touch(ActorMarker *marker, ActorMarker *other){
    Actor *this;

    this = marker_getActor(marker);
    if ((this->state == 4) && func_803294F0(this, 80, func_80329784(this))) {
        FUNC_8030E8B4(SFX_1E_HITTING_AN_ENEMY_2, 1.0f, 28000, this->position, 950, 1900);
        __chCrab_802CB140(this);
        subaddie_set_state(this, 1);
    }
}

void __chCrab_ow(ActorMarker *marker, ActorMarker *other) {
    Actor *this;

    this = marker_getActor(marker);
    this->unk60 = 3.0f;
    subaddie_set_state(this, 6);
    actor_playAnimationOnce(this);
    if (marker->unk14_20 == MARKER_13_SNIPPET) {
        FUNC_8030E8B4(SFX_6E_VILE_EGH, 2.0f, 26000, this->position, 950, 1900);
        marker->unk14_20 = MARKER_16B_SNIPPET_UPSIDEDOWN;
    }
    if (marker->unk14_20 == MARKER_DD_BLACK_SNIPPET) {
        FUNC_8030E8B4(SFX_6E_VILE_EGH, 2.0f, 26000, this->position, 950, 1900);
        marker->unk14_20 = MARKER_DE_BLACK_SNIPPET_UPSIDEDOWN;
    }
}

void __chCrab_particleEmitterSetup(ParticleEmitter *p_ctrl, f32 position[3]) {
    particleEmitter_setPosition(p_ctrl, position);
    particleEmitter_setDrawMode(p_ctrl, 2);
    func_802EF9F8(p_ctrl, 0.7f);
    func_802EFA18(p_ctrl, 5);
    func_802EFA20(p_ctrl, 0.8f, 1.0f);
    particleEmitter_setSfx(p_ctrl, SFX_1F_HITTING_AN_ENEMY_3, 10000);
    particleEmitter_setSpawnIntervalRange(p_ctrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(p_ctrl, 3.5f, 3.5f);
    particleEmitter_setFade(p_ctrl, 0.0f, 0.65f);
}


void __chCrab_emitClawPiece(ParticleEmitter *p_ctrl, f32 position[3], enum asset_e model_id) {
    __chCrab_particleEmitterSetup(p_ctrl, position);
    particleEmitter_setParticleAccelerationRange(p_ctrl, 0.0f, -1800.0f, 0.0f, 0.0f, -1800.0f, 0.0f);
    particleEmitter_setModel(p_ctrl, model_id);
    func_802EFB70(p_ctrl, 0.5f, 0.8f);
    particleEmitter_setAngularVelocityRange(p_ctrl, -800.0f, -800.0f, -800.0f, 800.0f, 800.0f, 800.0f);
    particleEmitter_setParticleVelocityRange(p_ctrl, -200.0f, 850.0f, -200.0f, 400.0f, 1000.0f, 400.0f);
    particleEmitter_emitN(p_ctrl, 2);
}

void __chCrab_emitLegPiece(ParticleEmitter *p_ctrl, f32 position[3], enum asset_e model_id) {
    __chCrab_particleEmitterSetup(p_ctrl, position);
    particleEmitter_setParticleAccelerationRange(p_ctrl, 0.0f, -1800.0f, 0.0f, 0.0f, -1800.0f, 0.0f);
    particleEmitter_setModel(p_ctrl, model_id);
    func_802EFB70(p_ctrl, 0.5f, 0.8f);
    particleEmitter_setAngularVelocityRange(p_ctrl, -800.0f, -800.0f, -800.0f, 800.0f, 800.0f, 800.0f);
    particleEmitter_setParticleVelocityRange(p_ctrl, -200.0f, 850.0f, -200.0f, 400.0f, 1000.0f, 400.0f);
    particleEmitter_emitN(p_ctrl, 6);
}

void __chCrab_emitHeadPiece(ParticleEmitter *p_ctrl, f32 position[3], enum asset_e model_id) {
    __chCrab_particleEmitterSetup(p_ctrl, position);
    particleEmitter_setParticleAccelerationRange(p_ctrl, 0.0f, -1800.0f, 0.0f, 0.0f, -1800.0f, 0.0f);
    particleEmitter_setModel(p_ctrl, model_id);
    func_802EFB70(p_ctrl, 1.0f, 1.0f);
    particleEmitter_setAngularVelocityRange(p_ctrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(p_ctrl, -50.0f, 750.0f, -50.0f, 120.0f, 900.0f, 120.0f);
    particleEmitter_emitN(p_ctrl, 1);
}

void __chCrab_spawn_mutant_crab_jiggy(void) {
    f32 sp1C[3];

    sp1C[0] = 13814.0f;
    sp1C[1] = 3812.0f;
    sp1C[2] = 0.0f;
    jiggy_spawn(JIGGY_16_CC_SNIPPETS, sp1C);
}

void __chCrab_mutantTextCallback(ActorMarker *caller, enum asset_e text_id, s32 model_id){
    if (text_id == ASSET_D33_DIALOG_MUTANT_CRAB_DEFEAT) {
        func_80324E38(0.0f, 3);
        timed_setStaticCameraToNode(0.0f, 4);
        timedFunc_set_0(0.1f, __chCrab_spawn_mutant_crab_jiggy);
        timed_exitStaticCamera(3.0f);
        func_80324E38(3.0f, 0);
        return;
    }
    levelSpecificFlags_set(0xE, FALSE);
}

bool __chCrab_802CB76C(ActorMarker *marker, ActorMarker *other) {
    Actor *this;

    this = marker_getActor(marker);
    if ((this->modelCacheIndex == ACTOR_F2_BLACK_SNIPPET) && !func_8038B550()) {
        return FALSE;
    }
    return TRUE;
}

void __chCrab_die(ActorMarker *marker, ActorMarker *other){
    Actor *this;
    f32 jiggy_spawn_position[3];
    f32 sp44;
    bool is_mutant_snippet;
    bool is_black_snippet;
    s32 model_id;
    ParticleEmitter *p_ctrl;

    this = marker_getActor(marker);
    is_mutant_snippet = this->modelCacheIndex == ACTOR_F5_MUTIE_SNIPPET;
    is_black_snippet = this->modelCacheIndex == ACTOR_F2_BLACK_SNIPPET;
    FUNC_8030E8B4(SFX_79_TICKER_DEATH, 1.0f, 32750, this->position, 950, 1900);
    FUNC_8030E8B4(SFX_79_TICKER_DEATH, 1.0f, 28000, this->position, 950, 1900);
    __spawnQueue_add_4((GenFunction_4)func_802C4140, ACTOR_4C_STEAM, reinterpret_cast(s32, this->position[0]), reinterpret_cast(s32, this->position[1]), reinterpret_cast(s32, this->position[2]));
    this->unk60 = 5.0f;
    marker->collidable = FALSE;
    this->unk138_27 = 1;
    marker_despawn(marker);
    if( map_get() == MAP_B_CC_CLANKERS_CAVERN
        && func_80259254(this->position, 13778.0f, 0.0f, 3000.0f)
    ) {
        this->depth_mode =  MODEL_RENDER_DEPTH_COMPARE;
        if( !jiggyscore_isCollected(JIGGY_16_CC_SNIPPETS)
            && ((actorArray_findClosestActorFromActorId(this->position, ACTOR_F5_MUTIE_SNIPPET, -1, &sp44) == NULL) || (3000.0f < sp44))) {
            jiggy_spawn_position[0] = 13814.0f;
            jiggy_spawn_position[1] = 3812.0f;
            jiggy_spawn_position[2] = 0.0f;
            func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x7FFF);
            func_80324DBC(2.25f, ASSET_D33_DIALOG_MUTANT_CRAB_DEFEAT, 0xF, jiggy_spawn_position, NULL, __chCrab_mutantTextCallback, NULL);
        }
    }
    p_ctrl = partEmitMgr_newEmitter(2);
    model_id = (is_mutant_snippet) ? ASSET_392_MODEL_MUTANT_CRAB_CLAW 
             : (is_black_snippet) ? ASSET_569_MODEL_BLACK_CRAB_CLAW 
             : ASSET_38C_MODEL_CRAB_CLAW;
    __chCrab_emitClawPiece(p_ctrl, this->position, model_id);

    p_ctrl = partEmitMgr_newEmitter(6);
    model_id = (is_mutant_snippet) ? ASSET_391_MODEL_MUTANT_CRAB_LEG 
             : (is_black_snippet) ? ASSET_568_MODEL_BLACK_CRAB_LEG 
             : ASSET_38D_MODEL_CRAB_LEG;
    __chCrab_emitLegPiece(p_ctrl, this->position, model_id);

    p_ctrl = partEmitMgr_newEmitter(1);
    model_id = (is_mutant_snippet) ? ASSET_390_MODEL_MUTANT_CRAB_HEAD 
             : (is_black_snippet) ? ASSET_567_MODEL_BLACK_CRAB_HEAD 
             : ASSET_38E_MODEL_CRAB_HEAD;
    __chCrab_emitHeadPiece(p_ctrl, this->position, model_id);
}

void __chCrab_walkSfxUpdate(Actor *this) {
    if (actor_animationIsAt(this, 0.4f)) {
        FUNC_8030E8B4(SFX_3D_TICKER_WALKING, 0.85f, 15000, this->position, 950, 1900);
    }
    if (actor_animationIsAt(this, 0.9f)) {
        FUNC_8030E8B4(SFX_3D_TICKER_WALKING, 1.15f, 15000, this->position, 950, 1900);
    }
}

void chCrab_update(Actor *this) {
    s32 sp34;
    f32 sp30;
    bool is_mutant_snippet;
    static s32 D_803670B0 = 0;
    static s32 D_803670B4 = 0;

    sp34 = func_8023DB5C();
    sp30 = time_getDelta();
    is_mutant_snippet = this->modelCacheIndex == ACTOR_F5_MUTIE_SNIPPET;
    if (!this->unk16C_4) {
        marker_setCollisionScripts(this->marker, __chCrab_touch, __chCrab_ow, __chCrab_die);
        func_803300C0(this->marker, &__chCrab_802CB76C);
        this->unk124_0 = this->unk138_31 = FALSE;
        this->unk138_24 = FALSE;
        this->unk16C_4 = TRUE;
        animctrl_setTransitionDuration(this->animctrl, 0.25f);
        if (map_get() == MAP_A_TTC_SANDCASTLE) {
            if (!jiggyscore_isCollected(JIGGY_10_TTC_SANDCASTLE)) {
                mapSpecificFlags_set(1, 0);
            }
            if (func_803203FC(2)) {
                marker_despawn(this->marker);
                return;
            }
        }
    }

    if (func_803203FC(UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE) != 0) {
        if (this->unkF4_8 != 1) {
            marker_despawn(this->marker);
            return;
        }
        this->yaw_ideal = (f32) func_80329784(this);
        func_80328FB0(this, 4.0f);
        return;
    }
    if( (map_get() == MAP_B_CC_CLANKERS_CAVERN) 
        && !mapSpecificFlags_get(0) 
        && is_mutant_snippet
        && !jiggyscore_isCollected(JIGGY_16_CC_SNIPPETS)
        && func_80329530(this, 500) && !func_80329530(this, 200)
        && !func_8028ECAC()
    ) {
        if ((this->state != 6) && (this->state != 5)) {
            func_80311480(ASSET_D32_DIALOG_MUTANT_CRAB_MEET, 0xF, this->position, NULL, __chCrab_mutantTextCallback, NULL);
            mapSpecificFlags_set(0, TRUE);
            levelSpecificFlags_set(0xE, TRUE);
            this->unk138_24 = TRUE;
        }
    }
    if (map_get() == MAP_A_TTC_SANDCASTLE) {
        if( !mapSpecificFlags_get(0)
            && levelSpecificFlags_get(2)
            && !func_803203FC(2)
            && !jiggyscore_isCollected(JIGGY_10_TTC_SANDCASTLE)
            && func_80329530(this, 1600)
        ) {
            func_80311480(0xA12, 4, this->position, NULL, NULL, NULL);
            mapSpecificFlags_set(0, TRUE);
        } else if (mapSpecificFlags_get(1)) {
            func_80311480(0xA13, 4, this->position, NULL, NULL, NULL);
            mapSpecificFlags_set(1, FALSE);
        }
    }
    if (levelSpecificFlags_get(0xE)) {
        if ((this->state != 8) && (this->state != 9)) {
            subaddie_set_state_with_direction(this, (this->unk138_24) ? 8 : 9, 0.0f, 1);
            this->unk138_24 = FALSE;
        }
    }

    switch(this->state){
        case 1: //L802CBE30
            if (subaddie_maybe_set_state(this, 2, 0.03f)) {
                __chCrab_802CB040(this);
            }
            __chCrab_802CB078(this);
            break;

        case 9: //L802CBE6C
            if (!levelSpecificFlags_get(0xE)) {
                subaddie_set_state_with_direction(this, 3, 0.0f, 1);
            }
            break;

        case 2: //L802CBE9C
            func_80328FB0(this, 1.0f);
            if( func_8032CA80(this, (this->modelCacheIndex == ACTOR_F2_BLACK_SNIPPET)? 0xD: 0)
                && func_80329480(this)
            ) {
                func_80328CEC(this, (s32) this->yaw, 90, 150);
            }
            subaddie_maybe_set_state_position_direction(this, 1, 0.0f, 1, 0.0075f);
            __chCrab_802CB078(this);
            break;

        case 3: //L802CBF44
            this->yaw_ideal = (f32) func_80329784(this);
            func_80328FB0(this, 4.0f);
            if (func_80329480(this)) {
                subaddie_set_state(this, 4);
                this->unk28 = 12.0f;
            }
            break;

        case 8: //L802CBF9C
            this->yaw_ideal = func_80329784(this) + 90.0;
            func_80328FB0(this, 4.0f);
            if (func_80329480(this)) {
                subaddie_set_state(this, 9);
                this->unk28 = 12.0f;
            } else if (!levelSpecificFlags_get(0xE)) {
                subaddie_set_state_with_direction(this, 3, 0.0f, 1);
            }
            break;

        case 4: //L802CC024
            if ((func_8023DB5C() & 0xF) == 9) {
                this->yaw_ideal = (f32) func_80329784(this);
            }
            func_80328FB0(this, 7.0f);
            if (func_8032CA80(this, (this->modelCacheIndex == ACTOR_F2_BLACK_SNIPPET)? 0xD : 0)) {
                __chCrab_802CB140(this);
            }
            break;

        case 5: //L802CC0AC
            this->unk60 = MAX(0.0, this->unk60 - sp30);
            if (this->unk60 == 0.0f) {
                subaddie_set_state(this, 7);
                actor_playAnimationOnce(this);
                if (this->marker->unk14_20 == 0x16B) {
                    this->marker->unk14_20 = MARKER_13_SNIPPET;
                }
                if (this->marker->unk14_20 == 0xDE) {
                    this->marker->unk14_20 = MARKER_DD_BLACK_SNIPPET;
                }
            }
            break;

        case 6: //L802CC18C
            if (animctrl_isStopped(this->animctrl)) {
                if (this->unk60 == 0.0f) {
                    func_80326310(this);
                } else {
                    subaddie_set_state(this, 5);
                    actor_loopAnimation(this);
                }
            }
            break;

        case 7: //L802CC1E8
            if (animctrl_isStopped(this->animctrl)) {
                subaddie_set_state(this, 1);
                actor_loopAnimation(this);
            }
            break;
    }
    
    if ((this->state == 2) || (this->state == 3) || (this->state == 4)) {
        if (sp34 != D_803670B0) {
            D_803670B0 = sp34;
            D_803670B4 = 1;
            __chCrab_walkSfxUpdate(this);
        }
        else if (D_803670B4 != 0) {
            D_803670B4--;
            __chCrab_walkSfxUpdate(this);
        }
    }
}

/* .data */
ActorInfo D_803670B8 = { MARKER_13_SNIPPET,         ACTOR_67_SNIPPET,       ASSET_358_SNIPPET,             0x1, chCrabAnimations, chCrab_update, func_80326224, actor_draw, 1900, 0, 0.8f, 0};
ActorInfo D_803670DC = { MARKER_DD_BLACK_SNIPPET,   ACTOR_F2_BLACK_SNIPPET, ASSET_566_MODEL_BLACK_SNIPPET, 0x1, chCrabAnimations, chCrab_update, func_80326224, actor_draw, 1900, 0, 0.8f, 0};
ActorInfo D_80367100 = { MARKER_13_SNIPPET,         ACTOR_F5_MUTIE_SNIPPET, ASSET_38F_MODEL_MUTIE_SNIPPET, 0x1, chCrabMutantAnimations, chCrab_update, func_80326224, actor_draw, 1900, 0, 0.8f, 0};
