#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

/* extern functions */
extern void sfxsource_setSampleRate(u8, s32);

/* data */
enum chTumblar_state_e {
    TUMBLAR_STATE_0_IDLE,
    TUMBLAR_STATE_1_CONGRATULATING,
    TUMBLAR_STATE_2_BREAKING,
    TUMBLAR_STATE_3_DISAPPEARED
};

typedef struct {
    ActorMarker *jiggy_marker;
    u8 state;
    u8 unused[3];
    f32 timer;
    f32 velocity[3];
} Struct_MMM_47D0_0;

/* .code */
void MMM_func_8038ABC0(s32 arg0) {
    if (getGameMode() != GAME_MODE_7_ATTRACT_DEMO) {
        ability_setAllLearned(ability_getAllLearned() & ~arg0);
    }
}

void func_8038AC04(void) {
    if ((*(u32 *) PHYS_TO_K1(0x1D0)) - 0x356BAAAE) {
        MMM_func_8038ABC0(0x820);
    }
}

void chTumblar_draw(Struct_MMM_47D0_0 *arg0, struct struct_68_s *arg1, f32 position[3], f32 rotation[3], f32 scale, BKModelBin *model_bin, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    if (arg0->state != TUMBLAR_STATE_3_DISAPPEARED) {
        if (arg0->state == TUMBLAR_STATE_0_IDLE || arg0->state == TUMBLAR_STATE_1_CONGRATULATING) {
            modelRender_setAlpha(0xFF);
        }
        else if (arg0->state == TUMBLAR_STATE_2_BREAKING) {
            modelRender_setAlpha((s32)((1 - ((f64) arg0->timer * 1)) * 255.0));
        }

        modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
        modelRender_draw(gfx, mtx, position, rotation, scale, NULL, model_bin);
    }
}

void chTumblar_copyPosition(s32 arg0, Struct68s *arg1, f32 arg2[3]) {
    func_8035179C_copyPosition(arg1, arg2);
}

bool chTumblar_isDisappeared(Struct_MMM_47D0_0 *arg0, s32 arg1) {
    return arg0->state == TUMBLAR_STATE_3_DISAPPEARED;
}

bool chTumblar_isBanjoAbove(Struct_MMM_47D0_0 *arg0, Struct68s *arg1) {
    f32 plyr_pos[3];
    f32 position[3];

    player_getPosition(plyr_pos);
    func_8035179C_copyPosition(arg1, position);

    return func_803518D4(arg1) &&
           ml_vec3f_horizontal_distance_zero_likely(position, plyr_pos) < 40.0f &&
           player_getTransformation() == TRANSFORM_1_BANJO &&
           player_movementGroup() == BSGROUP_0_NONE;
}

void chTumblar_init(Struct_MMM_47D0_0 *arg0, Struct68s *arg1) {
    u8 sfxsource_index;
    f32 distance_to_jiggy;
    Actor *jiggy;
    f32 position[3];

    arg0->state = TUMBLAR_STATE_0_IDLE;
    arg0->timer = 0.0f;

    arg0->velocity[0] = 0.0f;
    arg0->velocity[1] = 0.0f;
    arg0->velocity[2] = 0.0f;

    func_8038AA30(arg0, arg1);
    func_80351A14(arg1, (Struct68DrawMethod) chTumblar_draw);

    sfxsource_index = func_80351758_getSfxsourceIndex(arg1);
    sfxsource_setSfxId(sfxsource_index, SFX_3EC_CCW_DOOR_OPENING);
    sfxSource_setunk43_7ByIndex(sfxsource_index, 3);
    sfxsource_playSfxAtVolume(sfxsource_index, 0.6f);
    sfxsource_setSampleRate(sfxsource_index, 0);
    sfxSource_func_8030E2C4(sfxsource_index);

    func_8035179C_copyPosition(arg1, position);
    distance_to_jiggy = 500.0f;
    jiggy = actorArray_findClosestActorFromActorId(position, ACTOR_46_JIGGY, -1, &distance_to_jiggy);

    if (jiggy != NULL) {
        arg0->jiggy_marker = jiggy->marker;
    }
    else {
        arg0->jiggy_marker = NULL;
    }

    if (arg0->jiggy_marker != NULL) {
        arg0->jiggy_marker->collidable = FALSE;
    }

    if (jiggyscore_isCollected(JIGGY_62_MMM_TUMBLAR)) {
        func_80351A04(arg1, 1);
        arg0->state = TUMBLAR_STATE_3_DISAPPEARED;
    }
}

void __chTumblar_congratulationTextCallback(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    mapSpecificFlags_set(MMM_SPECIFIC_FLAG_TUMBLAR_BROKEN, TRUE);
}

void chTumblar_congratulate(Struct_MMM_47D0_0 *arg0, s32 arg1) {
    gcdialog_showDialog(ASSET_ADB_DIALOG_UNKNOWN, 4, NULL, arg0->jiggy_marker, __chTumblar_congratulationTextCallback, NULL);
    arg0->state = TUMBLAR_STATE_1_CONGRATULATING;
}

void chTumblar_update(Struct_MMM_47D0_0 *arg0, Struct68s *arg1, f32 tick) {
    f32 viewport_position[3];
    f32 viewport_rotation[3];
    f32 direction[3];
    Actor *jiggy;
    f32 position[3];
    f32 plyr_pos[3];
    f32 joystick[2];
    s32 is_banjo_above;
    u8 sfxsource_index;

    arg0->timer += tick;

    if (arg0->state == TUMBLAR_STATE_0_IDLE) {
        func_8035179C_copyPosition(arg1, position);
        controller_getJoystick(0, joystick);
        is_banjo_above = chTumblar_isBanjoAbove(arg0, arg1);

        if (is_banjo_above) {
            func_8028F66C(BS_INTR_D_SURF);
        }

        if (is_banjo_above && (joystick[0] != 0.0f || joystick[1] != 0.0f)) {
            viewport_getRotation_vec3f(viewport_rotation);

            direction[0] = joystick[0];
            direction[1] = 0.0f;
            direction[2] = -joystick[1];

            ml_vec3f_yaw_rotate_copy(direction, direction, viewport_rotation[1]);
            arg0->velocity[0] += direction[0] * 2500.0f * tick;
            arg0->velocity[2] += direction[2] * 2500.0f * tick;
        }
        else {
            arg0->velocity[0] *= 0.7;
            arg0->velocity[2] *= 0.7;
        }

        if (LENGTH_VEC3F(arg0->velocity) > 400.0f) {
            ml_vec3f_set_length(arg0->velocity, 400.0f);
        }

        position[0] += arg0->velocity[0] * tick;
        position[2] += arg0->velocity[2] * tick;

        func_80351B28(arg1, position);
        func_8035179C_copyPosition(arg1, position);

        if (arg0->jiggy_marker != NULL) {
            viewport_getPosition_vec3f(viewport_position);

            direction[0] = position[0] - viewport_position[0];
            direction[2] = position[2] - viewport_position[2];
            direction[1] = 0.0f;
            ml_vec3f_normalize(direction);

            jiggy = marker_getActor(arg0->jiggy_marker);
            jiggy->position[0] = position[0] + (direction[0] * 20.0f);
            jiggy->position[2] = position[2] + (direction[2] * 20.0f);
        }
    }
    else if (arg0->state == TUMBLAR_STATE_2_BREAKING) {
        if (arg0->timer >= 1.0f) {
            arg0->state = TUMBLAR_STATE_3_DISAPPEARED;

            if (arg0->jiggy_marker != NULL) {
                arg0->jiggy_marker->collidable = TRUE;
            }

            func_80351A04(arg1, 1);
        }

        arg0->velocity[0] *= 0.7;
        arg0->velocity[2] *= 0.7;
    }

    if (arg0->state == TUMBLAR_STATE_1_CONGRATULATING) {
        sfxsource_index = func_80351758_getSfxsourceIndex(arg1);
        sfxsource_setSampleRate(sfxsource_index, 0);
    }
    else {
        sfxsource_index = func_80351758_getSfxsourceIndex(arg1);
        sfxsource_setSampleRate(sfxsource_index, (s32)((LENGTH_VEC3F(arg0->velocity) / 400.0) * 15000.0));
    }

    player_getPosition(plyr_pos);
    func_8035179C_copyPosition(arg1, position);

    if (!mapSpecificFlags_get(MMM_SPECIFIC_FLAG_0_UNKNOWN) && arg0->state == TUMBLAR_STATE_0_IDLE && ml_vec3f_horizontal_distance_zero_likely(position, plyr_pos) < 250.0f) {
        if (gcdialog_showDialog(ASSET_ADA_DIALOG_UNKNOWN, 0, NULL, NULL, NULL, NULL)) {
            mapSpecificFlags_set(0, TRUE);
        }
    }

    if (arg0->state == TUMBLAR_STATE_1_CONGRATULATING && mapSpecificFlags_get(MMM_SPECIFIC_FLAG_TUMBLAR_BROKEN)) {
        arg0->state = TUMBLAR_STATE_2_BREAKING;
        arg0->timer = 0.0f;
        mapSpecificFlags_set(MMM_SPECIFIC_FLAG_TUMBLAR_BROKEN, FALSE);
        sfx_playFadeShorthandDefault(SFX_11B_TUMBLAR_DISAPPEARING_1, 1.0f, 30000, position, 500, 2500);
    }
}
