#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* extern functions */
extern void chPortrait_break(ActorMarker *, f32);

typedef struct {
    f32 timer;
} ActorLocal_PortraitChompa;

/* public functions */
void chChompa_update(Actor *this);
Actor *chChompa_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
enum chChompa_state_e {
    CHOMPA_STATE_0_INIT,
    CHOMPA_STATE_1_IDLE,
    CHOMPA_STATE_2_GROWLING,
    CHOMPA_STATE_3_WAITING_TO_BITE,
    CHOMPA_STATE_4_BITING,
    CHOMPA_STATE_5_DYING,
    CHOMPA_STATE_6_DEAD
};

ActorInfo D_8038BAD0 = {
    MARKER_254_PORTRAIT_CHOMPA_A, ACTOR_381_PORTRAIT_CHOMPA, ASSET_521_MODEL_PORTRAIT_CHOMPA,
    0x0, NULL,
    chChompa_update, NULL, chChompa_draw,
    0, 0, 0.0f, 0
};

/* .code */
Actor *chChompa_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *actor = marker_getActor(marker);

    if (actor->state == CHOMPA_STATE_0_INIT || actor->state == CHOMPA_STATE_1_IDLE || actor->state == CHOMPA_STATE_6_DEAD || actor->state == CHOMPA_STATE_2_GROWLING) {
        return actor;
    }

    return actor_draw(marker, gfx, mtx, vtx);
}

void chChompa_setState(Actor *this, s32 next_state) {
    ActorLocal_PortraitChompa *local = (ActorLocal_PortraitChompa *) &this->local;
    f32 tmp = 2.5f;
    this->marker->id = 0x1d1;

    if (next_state == CHOMPA_STATE_1_IDLE || next_state == CHOMPA_STATE_2_GROWLING) {
        skeletalAnim_set(this->unk148, 0x23e, 0.0f, 2.5f);
        skeletalAnim_setProgress(this->unk148, 0.99f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_4_STOPPED);

        if (this->state == CHOMPA_STATE_4_BITING) {
            local->timer = randf2(0.5f, 1.0f);
        }
        else {
            local->timer = 0.0f;
        }
    }//L80387BD0

    if (this->state == CHOMPA_STATE_1_IDLE && next_state == CHOMPA_STATE_2_GROWLING) {
        FUNC_8030E624(SFX_3EF, 0.9f, 32675);
    }

    if (next_state == CHOMPA_STATE_3_WAITING_TO_BITE) {
        local->timer = 0.2f;
    }

    if (next_state == CHOMPA_STATE_4_BITING) {
        this->marker->id = MARKER_254_PORTRAIT_CHOMPA_A;
        skeletalAnim_set(this->unk148, 0x23e, 0.0f, 2.5f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);

        if (this->unk100) {
            chPortrait_break(this->unk100, tmp + 0.55);
        }

        FUNC_8030E624(SFX_3EF, 1.1f, 25000);
        FUNC_8030E624(SFX_3EF, 1.1f, 25000);
    }//L80387CAC

    if (next_state == CHOMPA_STATE_5_DYING) {
        func_8030E6D4(SFX_1E_HITTING_AN_ENEMY_2);
        actor_collisionOff(this);
    }

    this->state = next_state;
}


void __chChompa_hit(ActorMarker *this_marker, ActorMarker *other_marker) {
    func_8030E6D4(SFX_1E_HITTING_AN_ENEMY_2);
}

void __chChompa_die(ActorMarker *this_marker, ActorMarker *other_marker) {
    Actor *this = marker_getActor(this_marker);
    chChompa_setState(this, CHOMPA_STATE_5_DYING);
}

void __chChompa_spwanPortrait(ActorMarker *marker) {
    Actor *this = marker_getActor(reinterpret_cast(ActorMarker *, marker));
    enum asset_e portrait_id;
    Actor *portrait;

    switch (this->unkF4_8) {
        case 0x32:
            portrait_id = ACTOR_382_PORTRAIT_OF_GRUNTY;
            break;
        case 0x33:
            portrait_id = ACTOR_384_PORTRAIT_OF_BLACKEYE;
            break;
        case 0x34:
            portrait_id = ACTOR_385_PORTRAIT_OF_TOWER;
            break;
        case 0x35:
            portrait_id = ACTOR_386_PORTRAIT_OF_TREE_AND_MOON;
            break;
        case 0x36:
            portrait_id = ACTOR_387_PORTRAIT_OF_TEEHEE;
            break;
        case 0x37:
            portrait_id = ACTOR_388_PORTRAIT_OF_MINION;
            break;
        default:
            portrait_id = ACTOR_382_PORTRAIT_OF_GRUNTY;
            break;
    }

    portrait = spawn_child_actor(portrait_id, &this);
    portrait->yaw = this->yaw;
    this->unk100 = portrait->marker;
    portrait->unk10_1 = FALSE;
}

void __chChompa_emitDust(f32 position[3], s32 count, enum asset_e sprite_id) {
    static s32 D_8038BAF4[3] = {0xB4, 0xFF, 0x8C};
    static ParticleScaleAndLifetimeRanges D_8038BB00 = {{0.2f, 0.4f}, {1.8f, 2.8f}, {0.0f, 0.15f}, {0.7f, 1.2f}, 0.0f, 0.01f};
    static ParticleSettingsVelocityAccelerationPosition D_8038BB28 = {
        {{-150.0f,  250.0f, -150.0f}, {150.0f,  300.0f, 150.0f}},
        {{   0.0f, -600.0f,    0.0f}, {  0.0f, -600.0f,   0.0f}},
        {{ -50.0f,  -50.0f,  -50.0f}, { 50.0f,   50.0f,  50.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(count);
    particleEmitter_setRGB(pCtrl, D_8038BAF4);
    particleEmitter_setSprite(pCtrl, sprite_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_8038BB28);
    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &D_8038BB00);
    particleEmitter_emitN(pCtrl, count);
}

void __chChompa_emitBones(f32 position[3], s32 count, enum asset_e model_id) {
    static ParticleScaleAndLifetimeRanges D_8038BB70 = {{1.0f, 1.0f}, {1.0f, 1.0f}, {0.0f, 0.0f}, {3.2f, 3.2f}, 0.0f, 0.45f};
    static ParticleSettingsVelocityAccelerationPosition D_8038BB98 = {
        {{-90.0f,   300.0f, -90.0f}, {90.0f,   660.0f, 90.0f}},
        {{  0.0f, -1200.0f,   0.0f}, { 0.0f, -1200.0f,  0.0f}},
        {{-50.0f,     0.0f, -50.0f}, {50.0f,    50.0f, 50.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(count);
    particleEmitter_setModel(pCtrl, model_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_8038BB98);
    particleEmitter_setAngularVelocityRange(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_func_802EF9F8(pCtrl, 0.4f);
    particleEmitter_func_802EFA18(pCtrl, 3);
    func_802EFA20(pCtrl, 1.0f, 1.3f);
    particleEmitter_setSfx(pCtrl, SFX_2F_ORANGE_SPLAT, 16000);
    particleEmitter_setDrawMode(pCtrl, 2);
    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &D_8038BB70);
    particleEmitter_emitN(pCtrl, count);
}

void __chChompa_emitDeathEffects(Actor *this) {
    f32 sp2C[3];
    f32 sp20[3];

    if (!this->marker->unk14_21) {
        return;
    }

    func_8034A174(this->marker->unk44, 5, sp2C);
    func_8034A174(this->marker->unk44, 6, sp20);

    __chChompa_emitBones(sp2C, 1, ASSET_523_MODEL_PORTRAIT_CHOMPA_TEETH);
    __chChompa_emitBones(sp2C, 1, ASSET_524_MODEL_PORTRAIT_CHOMPA_HEAD);
    __chChompa_emitBones(sp20, 6, ASSET_525_MODEL_PORTRAIT_CHOMPA_PART);

    __chChompa_emitDust(sp2C, 2, ASSET_700_SPRITE_DUST);
    __chChompa_emitDust(sp20, 2, ASSET_700_SPRITE_DUST);
}

void chChompa_update(Actor *this) {
    ActorLocal_PortraitChompa *local = (ActorLocal_PortraitChompa *) &this->local;
    f32 tick = time_getDelta();
    f32 plyr_position[3];
    f32 plyr_dist;
    f32 anim_prev_progress;
    f32 anim_progress;

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->unk16C_0 = TRUE;
        marker_setCollisionScripts(this->marker, NULL, __chChompa_hit, __chChompa_die);
        __spawnQueue_add_1((GenFunction_1) __chChompa_spwanPortrait, reinterpret_cast(s32, this->marker));
        chChompa_setState(this, this->state < CHOMPA_STATE_5_DYING ? CHOMPA_STATE_1_IDLE : CHOMPA_STATE_6_DEAD);
    }//L803880B4

    player_getPosition(plyr_position);
    plyr_dist = ml_vec3f_distance(this->position, plyr_position);

    if (this->state == CHOMPA_STATE_4_BITING) {
        actor_collisionOn(this);
    }
    else {
        actor_collisionOff(this);
    }

    if (this->state == CHOMPA_STATE_1_IDLE && plyr_dist < this->scale * 400.0f) {
        chChompa_setState(this, CHOMPA_STATE_2_GROWLING);
    }

    if (this->state == CHOMPA_STATE_2_GROWLING) {
        if (0.0f < local->timer) {
            local->timer -= tick;
        }
        else if (plyr_dist < this->scale * 300.0f) {
            chChompa_setState(this, CHOMPA_STATE_3_WAITING_TO_BITE);
        }
        else if (this->scale * 500.0f < plyr_dist) {
            chChompa_setState(this, CHOMPA_STATE_1_IDLE);
        }
    }//L80388204

    if (this->state == CHOMPA_STATE_3_WAITING_TO_BITE) {
        if (ml_timer_update(&local->timer, tick)) {
            chChompa_setState(this, CHOMPA_STATE_4_BITING);
        }
    }

    if (this->state == CHOMPA_STATE_4_BITING) {
        skeletalAnim_getProgressRange(this->unk148, &anim_prev_progress, &anim_progress);

        if (anim_prev_progress < 0.56 && 0.56 <= anim_progress) {
            this->marker->id = 0x1d1;
        }

        if (anim_prev_progress < 0.5 && 0.5 <= anim_progress) {
            FUNC_8030E624(SFX_2_CLAW_SWIPE, 0.9f, 32000);
        }

        if ((anim_prev_progress < 0.11 && 0.11 <= anim_progress) ||
            (anim_prev_progress < 0.32 && 0.32 <= anim_progress) ||
            (anim_prev_progress < 0.53 && 0.53 <= anim_progress)
        ) {
            func_8030E6A4(SFX_6D_CROC_BITE, randf2(0.95f, 1.05f), 32000);
        }

        if (anim_prev_progress < 0.9 && 0.9 <= anim_progress) {
            func_8030E6D4(SFX_2_CLAW_SWIPE);
        }

        if (skeletalAnim_getLoopCount(this->unk148) > 0) {
            chChompa_setState(this, CHOMPA_STATE_2_GROWLING);
        }
    }

    if (this->state == CHOMPA_STATE_5_DYING) {
        func_8030E6D4(SFX_D7_GRABBA_DEATH);
        __chChompa_emitDeathEffects(this);
        chChompa_setState(this, CHOMPA_STATE_6_DEAD);
    }
}
