#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/staticcamera.h"

#include "conga.h"
#include "orangepad.h"

extern void func_80329904(ActorMarker *, s32, void *);

void chOrangePad_update(Actor *);

ActorInfo chOrangePadInfo = {
    MARKER_66_ORANGE_PAD, ACTOR_57_ORANGE_PAD, ASSET_2EB_MODEL_ORANGE_PAD,
    0, NULL,
    chOrangePad_update, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

void spawnJiggy(s32 x, s32 y, s32 z) {
    f32 pos[3];

    TUPLE_ASSIGN(pos, x, y, z);
    jiggy_spawn(JIGGY_8_MM_ORANGE_PADS, pos);
}

void handleOrangeCollision(ActorMarker *marker) {
    f32 distance_to_orange_pad;
    Actor *closest_orange_pad;
    f32 position[3];
    ParticleEmitter *p_ctrl;
    s32 camera_id;

    position[0] = marker->propPtr->position_x;
    position[1] = marker->propPtr->position_y;
    position[2] = marker->propPtr->position_z;

    closest_orange_pad = actorArray_findClosestActorFromActorId(position, ACTOR_57_ORANGE_PAD, ORANGE_PAD_STATE_HIT, &distance_to_orange_pad);

    if (!closest_orange_pad || 500.0f < distance_to_orange_pad) {
        return;
    }

    closest_orange_pad->state = ORANGE_PAD_STATE_HIT;

    if (actorArray_findClosestActorFromActorId(position, ACTOR_57_ORANGE_PAD, ORANGE_PAD_STATE_HIT, &distance_to_orange_pad)) {
        // There are still other pads on the ground, play progress ding
        coMusicPlayer_playMusic(COMUSIC_2B_DING_B, 22000);
    } else { // No more pads, dispense jiggy
        camera_id = (closest_orange_pad->secondaryId == ORANGE_PAD_RIGHT) ? MM_ORANGE_PAD_JIGGY_SPAWN_RIGHT
                  : (closest_orange_pad->secondaryId == ORANGE_PAD_LEFT)  ? MM_ORANGE_PAD_JIGGY_SPAWN_LEFT
                                                                          : MM_ORANGE_PAD_JIGGY_SPAWN_TOP;

        gcStaticCamera_activate(camera_id);

        position[1] += 50.0f;
        timedFunc_set_3(0.6f, (GenFunction_3) spawnJiggy, (s32) position[0], (s32) position[1], (s32) position[2]);

        coMusicPlayer_playMusic(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x7FFF);

        if (!jiggyscore_isCollected(JIGGY_8_MM_ORANGE_PADS)) {
            gcdialog_showDialog(ASSET_B3B_DIALOG_CONGA_ORANGE_PAD_JIGGY, 4, NULL, NULL, NULL, NULL);
        }
    }

    // Spawn orange particles
    p_ctrl = partEmitMgr_newEmitter(ORANGE_PARTICLE_COUNT);

    particleEmitter_setPosition(p_ctrl, closest_orange_pad->position);
    particleEmitter_setModel(p_ctrl, ASSET_89F_MODEL_ORANGE_PARTICLE);
    particleEmitter_setStartingScaleRange(p_ctrl, 0.09f, 0.19f);
    particleEmitter_setFinalScaleRange(p_ctrl, 0.0f, 0.0f);
    particleEmitter_setParticleVelocityRange(p_ctrl, -200.0f, 500.0f, -200.0f, 200.0f, 700.0f, 200.0f);
    particleEmitter_setAccelerationRange(p_ctrl, 0.0f, -1200.0f, 0.0f, 0.0f, -1200.0f, 0.0f);
    particleEmitter_setAngularVelocityRange(p_ctrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setSpawnIntervalRange(p_ctrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(p_ctrl, 4.0f, 4.0f);
    particleEmitter_func_802EF9F8(p_ctrl, 0.01f);
    particleEmitter_func_802EFA18(p_ctrl, 3);
    particleEmitter_func_802EFA20(p_ctrl, 1.0f, 1.3f);

    particleEmitter_emitN(p_ctrl, ORANGE_PARTICLE_COUNT);
}

void chOrangePad_handleOrangeCollision(s32 _, ActorMarker *marker) {
    handleOrangeCollision(marker);
}

void chOrangePad_update(Actor *this) {
    Actor *conga;
    f32 unused;
    f32 min_distance;

    if (!this->initialized) {
        this->marker->propPtr->unk8_3 = 1;
        actor_collisionOff(this);
        this->initialized = TRUE;
    }

    if (!this->volatile_initialized) {
        this->partnerActor = actorArray_findClosestActorFromActorId(this->position, ACTOR_8_CONGA, -1, &min_distance)->marker;
        this->volatile_initialized = TRUE;
    }

    if (this->partnerActor) {
        conga = marker_getActor(this->partnerActor);
    }

    if (subaddie_playerIsWithinSphereAndActive(this, CONGA_WARN_DISTANCE)
        && !player_movementGroup()
        && !mapSpecificFlags_get(MM_SPECIFIC_FLAG_CONGA_WARNED_BLOCKS)
        && conga->state != CONGA_STATE_MOPEY) {

        if (gcdialog_showDialog(ASSET_B3D_DIALOG_CONGA_TOUCH_PAD, 0, NULL, NULL, NULL, NULL)) {
            mapSpecificFlags_set(MM_SPECIFIC_FLAG_CONGA_WARNED_BLOCKS, TRUE);
        }
    }

    if (this->state == ORANGE_PAD_STATE_HIT) {
        if (this->lifetime_value < 72.0f) {
            commonParticle_add(this->marker, 5, func_80329904);
            commonParticle_new(9, this->marker->unk14_21);
        }

        // Tick up respawn by 7 every update
        this->lifetime_value = MIN(ORANGE_PAD_HIT_LIFETIME, this->lifetime_value + ORANGE_PAD_LIFETIME_INCREMENT);

        if (ORANGE_PAD_HIT_LIFETIME == this->lifetime_value) {
            marker_despawn(this->marker);
        }
    } else { } // Can't remove the else ;.;

    // If hit, then fade out
    actor_setOpacity(this, 0xFF - (s32) this->lifetime_value);
}
