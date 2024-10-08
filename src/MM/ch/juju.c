#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* extern functions */
int func_80353064(f32 *, f32);
void func_802BB3DC(s32, f32, f32);

typedef struct {
    s32        animation_state;
    s32        animation_countdown;
    TUPLE(f32, next_pos);
    f32        scale;
    s32        unk18;
} ActorLocal_Juju_2;

/* public functions */
void chjuju_update(Actor *this);
Actor *chjuju_draw(ActorMarker *, Gfx **, Mtx **, Vtx **);

/* .bss */
u8 MM_pad_80389C80[0x10];
s32 mm_juju_count;

/* .data */
enum chjuju_animation_state_e {
    JUJU_ANIMATION_STATE_1_YAWING = 1,
    JUJU_ANIMATION_STATE_2_DESPAWNED,
    JUJU_ANIMATION_STATE_3_WAITING_TO_FALL,
    JUJU_ANIMATION_STATE_4_FALLING,
    JUJU_ANIMATION_STATE_5_DISAPPEARING
};

ActorInfo chjujuInfo = {
    MARKER_67_JUJU, ACTOR_59_JUJU, ASSET_2E6_MODEL_JUJU,
    0, NULL,
    chjuju_update, actor_update_func_80326224, chjuju_draw,
    0, 0, 0.0f, 0
};

/* .code */
void __chjuju_initialize(Actor *this, f32 *arg1, f32 *arg2, s32 animationState) {
    ActorLocal_Juju_2 *local;

    local = (ActorLocal_Juju_2 *) &this->local;
    local->animation_state = animationState;
    local->scale = 1.0f;

    this->position_x = arg1[0];
    this->position_y = arg1[1];
    this->position_z = arg1[2];

    local->next_pos_x = arg2[0];
    local->next_pos_y = arg2[1];
    local->next_pos_z = arg2[2];
}

Actor *chjuju_draw(ActorMarker *this, Gfx **dl, Mtx **mPtr, Vtx **arg2) {
    f32 rotation[3];
    Actor *actorPtr;
    ActorLocal_Juju_2 *jujuPtr;

    actorPtr = marker_getActorAndRotation(this, rotation);
    jujuPtr = (ActorLocal_Juju_2 *) &actorPtr->local;

    if (jujuPtr->animation_state != JUJU_ANIMATION_STATE_2_DESPAWNED) {
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
        modelRender_draw(dl, mPtr, actorPtr->position, rotation, jujuPtr->scale, NULL, marker_loadModelBin(this));
    }

    return actorPtr;
}

void __chjuju_initialize_all(ActorMarker *marker, s32 count) {
    int should_spawn;
    Actor *actorPtr = marker_getActor(marker);
    f32 position[3];
    s32 i;
    Actor *jujuPtr;

    position[0] = actorPtr->position_x;
    position[1] = actorPtr->position_y;
    position[2] = actorPtr->position_z;
    for(i = 0; i < 4; i++){
        jujuPtr = actor_spawnWithYaw_f32(ACTOR_59_JUJU, actorPtr->position, actorPtr->yaw);
        jujuPtr->marker->collidable = FALSE;

        actorPtr = marker_getActor(marker);
        chjujuhitbox_setJuju(actorPtr, i, jujuPtr);

        should_spawn = (i >= count);
        __chjuju_initialize(jujuPtr, position, actorPtr->position, should_spawn ? JUJU_ANIMATION_STATE_1_YAWING : JUJU_ANIMATION_STATE_2_DESPAWNED);

        if (should_spawn) {
            position[1] += 250.0f;
        }

        if (i == count) {
            ((ActorLocal_Juju_2 *) &jujuPtr->local)->unk18 = TRUE;
        }
    }
}

void __chjuju_spawnJiggy(s32 x, s32 y, s32 z, s32 yaw) {
    f32 sp1C[3];
    sp1C[0] = x;
    sp1C[1] = y + 0x14;
    sp1C[2] = z;
    jiggy_spawn(JIGGY_4_MM_JUJU, sp1C);
}

void __chjuju_solvePuzzle(s32 x, s32 y, s32 z, s32 yaw) {
    __spawnQueue_add_4((GenFunction_4) __chjuju_spawnJiggy, x, y, z, yaw);
    func_802BB3DC(0, 10.0f, 0.8f);
    gcpausemenu_80314AC8(1);
}

void func_803892A8(ActorMarker **ptr) {
    s32 i;
    s32 j;
    s32 s2;
    s32 s6;
    Actor *actorPtr;
    ActorLocal_Juju_2 *jujuPtr;

    for (i = 0; i < 4; i++) {
        actorPtr = marker_getActor(ptr[i]);
        jujuPtr = (ActorLocal_Juju_2 *) &actorPtr->local;

        if (jujuPtr->animation_state != JUJU_ANIMATION_STATE_2_DESPAWNED) {
            jujuPtr->animation_state = JUJU_ANIMATION_STATE_5_DISAPPEARING;
            jujuPtr->animation_countdown = 12;
            sfxsource_playHighPriority(0x3f6);

            if (i == 3) {
                gcpausemenu_80314AC8(0);
                timedFunc_set_4(1.25f, __chjuju_solvePuzzle, jujuPtr->next_pos_x, jujuPtr->next_pos_y, jujuPtr->next_pos_z, actorPtr->yaw);
                func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x6d60);
            }
            else {//L80389384
                func_8025A6EC(COMUSIC_2B_DING_B, 0x7fff);
            }

            for (s2 = 3, j = i + 1; j < 4; s2 += 5, j++) {
                actorPtr = marker_getActor(ptr[j]);
                jujuPtr = (ActorLocal_Juju_2 *) &actorPtr->local;

                if (j == i + 1) {
                    jujuPtr->unk18 = TRUE;
                }

                jujuPtr->animation_countdown = s2;
                jujuPtr->animation_state = JUJU_ANIMATION_STATE_3_WAITING_TO_FALL;
            }
            return;
        }
    }
}

bool __chjuju_isEveryJujuDespawned(ActorMarker **ptr) {
    s32 i;
    ActorLocal_Juju_2 *jujuPtr;

    for (i = 0; i < 4; i++) {
        jujuPtr = (ActorLocal_Juju_2 *) &marker_getActor(ptr[i])->local;

        if (jujuPtr->animation_state != JUJU_ANIMATION_STATE_2_DESPAWNED) {
            return FALSE;
        }
    }

    return TRUE;
}

bool __chjuju_isEveryJujuStable(ActorMarker **ptr) {
    s32 i;
    ActorLocal_Juju_2 *jujuPtr;

    for (i = 0; i < 4; i++) {
        jujuPtr = (ActorLocal_Juju_2 *) &marker_getActor(ptr[i])->local;

        if (jujuPtr->animation_state != JUJU_ANIMATION_STATE_1_YAWING && jujuPtr->animation_state != JUJU_ANIMATION_STATE_2_DESPAWNED) {
            return FALSE;
        }
    }

    return TRUE;
}

void __chjuju_updateCount(ActorMarker **ptr) {
    s32 i;
    mm_juju_count = 0;

    for (i = 0; i < 4; i++) {
        if (((ActorLocal_Juju_2 *) &marker_getActor(ptr[i])->local)->animation_state != JUJU_ANIMATION_STATE_2_DESPAWNED) {
            mm_juju_count++;
        }
    }
}

void chjuju_update(Actor *this) {
    ActorLocal_Juju_2 *jujuPtr = (ActorLocal_Juju_2 *) &this->local;
    s32 has_completed_full_turn = FALSE;
    f32 previous_yaw;
    f32 pos_offset[3];

    this->marker->propPtr->unk8_3 = (jujuPtr->animation_state != JUJU_ANIMATION_STATE_2_DESPAWNED) && (jujuPtr->animation_state != JUJU_ANIMATION_STATE_5_DISAPPEARING);

    switch (jujuPtr->animation_state) {
        case JUJU_ANIMATION_STATE_1_YAWING: //L80389624
            previous_yaw = this->yaw;
            this->yaw += ((11 - mm_juju_count * 2) * time_getDelta() * 60.0f) / 2;

            if (360.0f < this->yaw) {
                has_completed_full_turn = TRUE;
                this->yaw -= 360.0f;
            }//L803896B4

            if (jujuPtr->unk18 && (has_completed_full_turn || (previous_yaw < 180.0f && 180.0f <= this->yaw))) {
                mapSpecificFlags_set(MM_SPECIFIC_FLAG_9_JUJU_HAS_HALF_TURNED, TRUE);
            }
            break;

        case JUJU_ANIMATION_STATE_3_WAITING_TO_FALL: //L80389700
            if (--jujuPtr->animation_countdown == 0) {
                jujuPtr->animation_state = JUJU_ANIMATION_STATE_4_FALLING;
                jujuPtr->next_pos_y = this->position_y - 250.0f;
            }
            break;

        case JUJU_ANIMATION_STATE_5_DISAPPEARING: //L80389738
            jujuPtr->animation_countdown--;
            jujuPtr->scale *= 0.85;

            pos_offset[0] = 100.0f;
            pos_offset[1] = 0.0f;
            pos_offset[2] = 0.0f;
            ml_vec3f_yaw_rotate_copy(pos_offset, pos_offset, this->yaw + 90.0);

            this->position_x += pos_offset[0];
            this->position_y += pos_offset[1];
            this->position_z += pos_offset[2];

            if (!jujuPtr->animation_countdown) {
                jujuPtr->animation_state = JUJU_ANIMATION_STATE_2_DESPAWNED;
            }
            break;

        case JUJU_ANIMATION_STATE_4_FALLING: //L803897F8
            this->position_y -= 25.0;

            if (jujuPtr->next_pos_y == this->position_y) {
                jujuPtr->animation_state = JUJU_ANIMATION_STATE_1_YAWING;
                sfxsource_playHighPriority(SFX_3_DULL_CANNON_SHOT);
                func_802BB3DC(0, 10.0f, 0.8f);

                if (jujuPtr->unk18) {
                    func_80353064(this->position, 24.0f);
                }
            }
            break;
    }//L8038987C
}
