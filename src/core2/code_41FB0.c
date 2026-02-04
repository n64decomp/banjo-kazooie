#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern bool func_80309DBC(f32[3], f32[3], f32, f32 sp54[3], s32, s32);
extern bool func_80320C94(f32[3], f32[3], f32, f32 sp54[3], s32, s32);
extern f32 func_8033229C(ActorMarker *);
extern bool func_80309D58(f32[3], s32);

typedef struct {
    s16 flags;
    // u8 pad2[0x2];
    s32 actor_id;
    s32 count;
    s16 sfx_id;
    s16 sfx_volume;
    s16 sfx_sampleRate;
    // u8 pad12[0x2];
    f32 velocity_x;
    f32 randomVelocity_x;
    f32 velocity_y;
    f32 randomVelocity_y;
    f32 velocity_z;
    f32 randomVelocity_z;
    f32 bounce_factor;
    f32 yaw;
} BundleInfo;

typedef struct {
    s32 index;
    s16 flags;
    s16 unk6;
    f32 position[3];
    f32 velocity[3];
    f32 yaw;
    f32 yaw_speed;
    f32 elapsed_time;
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
    u8 state;
} Bundle;

/* .data */
enum bundle_state_e {
    BUNDLE_STATE_1_MOVING = 1,
    BUNDLE_STATE_2_YAWING,
    BUNDLE_STATE_3_IDLE
};

// #define 41FB0_FLAG_SET_YAW 0x0020
BundleInfo gBundle_array[] = {
    {0x0021, ACTOR_51_MUSIC_NOTE,       5, SFX_3E9_UNKNOWN,         1, 16000, 125.0f,  25.0f,  725.0f, 125.0f, 125.0f,  25.0f, 0.6f,   0.0f},
    {0x0021, ACTOR_52_BLUE_EGG,         5, SFX_21_EGG_BOUNCE_1,     1, 16000, 100.0f,  50.0f,  500.0f, 250.0f, 100.0f,  50.0f, 0.6f,   0.0f},
    {0x0021, ACTOR_6_GRUBLIN,           1, SFX_8_BANJO_LANDING_04,  1, 20000,   0.0f,   0.0f,  550.0f, 250.0f, 200.0f,   0.0f, 0.6f,   0.0f},
    {0x0021, ACTOR_62_JINJO_GREEN,      1, SFX_8_BANJO_LANDING_04,  1, 20000, 100.0f,  50.0f,  500.0f, 250.0f, 100.0f,  50.0f, 0.6f,   0.0f},
    {0x0021, ACTOR_46_JIGGY,            1, SFX_3E9_UNKNOWN,         1, 16000, 100.0f,  50.0f,  500.0f, 250.0f, 100.0f,  50.0f, 0.6f,   0.0f},
    {0x0001, ACTOR_50_HONEYCOMB,        3, SFX_3E9_UNKNOWN,         1, 16000,  50.0f, 150.0f,  500.0f, 250.0f,  50.0f, 150.0f, 0.6f,   0.0f},
    {0x0021, ACTOR_49_EXTRA_LIFE,       1, SFX_3E9_UNKNOWN,         1, 16000, 100.0f,  50.0f,  500.0f, 250.0f, 100.0f,  50.0f, 0.6f,   0.0f},
    {0x0001, ACTOR_46_JIGGY,            1, SFX_3E9_UNKNOWN,         1, 16000,   0.0f,   0.0f, 1000.0f,   0.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x0005, ACTOR_46_JIGGY,            1, SFX_3E9_UNKNOWN,         1, 16000,  90.0f,   0.0f,  930.0f,   0.0f, 100.0f,   0.0f, 0.6f,   0.0f},
    {0x0049, ACTOR_46_JIGGY,            1, SFX_3E9_UNKNOWN,         1, 16000,   0.0f,   0.0f, 1000.0f,   0.0f, 300.0f,   0.0f, 0.5f,   0.0f},
    {0x002D, ACTOR_B_SHOCKSPRING_PAD,   1, 0,                       1, 16000,   0.0f,   0.0f,  200.0f,   0.0f,   0.0f,   0.0f, 0.2f, 315.0f},
    {0x0005, ACTOR_51_MUSIC_NOTE,       5, SFX_3E9_UNKNOWN,         1, 16000,  75.0f,   0.0f,  725.0f,   0.0f,  75.0f,   0.0f, 0.6f,   0.0f},
    {0x0005, ACTOR_46_JIGGY,            1, SFX_3E9_UNKNOWN,         1, 16000,   0.0f,   0.0f, 1000.0f,   0.0f,   0.0f,   0.0f, 0.5f,   0.0f},
    {0x0009, ACTOR_47_EMPTY_HONEYCOMB,  1, SFX_3E9_UNKNOWN,         1, 16000,   0.0f,   0.0f,  200.0f,   0.0f, 300.0f,   0.0f, 0.6f,   0.0f},
    {0x0001, ACTOR_52_BLUE_EGG,         1, SFX_21_EGG_BOUNCE_1,     1, 16000,   0.0f, 350.0f,  500.0f, 500.0f,   0.0f, 350.0f, 0.6f,   0.0f},
    {0x0001, ACTOR_129_RED_FEATHER,     1, SFX_21_EGG_BOUNCE_1,     1, 16000,   0.0f, 350.0f,  500.0f, 500.0f,   0.0f, 350.0f, 0.6f,   0.0f},
    {0x0005, ACTOR_46_JIGGY,            1, 0,                       0,     0,   0.0f,   0.0f,  100.0f,   0.0f,   0.0f,   0.0f, 0.75f,  0.0f},
    {0x0005, ACTOR_6A_UNKNOWN,          1, 0,                       0,     0,   0.0f,   0.0f,  200.0f,   0.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x0009, ACTOR_46_JIGGY,            1, SFX_3E9_UNKNOWN,         1, 16000,   0.0f,   0.0f,  650.0f,   0.0f, 950.0f,   0.0f, 0.6f,   0.0f},
    {0x0001, ACTOR_51_MUSIC_NOTE,       1, SFX_21_EGG_BOUNCE_1,     1, 16000, 125.0f,  25.0f,  725.0f, 125.0f, 125.0f,  25.0f, 0.6f,   0.0f},
    {0x0001, ACTOR_50_HONEYCOMB,        1, SFX_3E9_UNKNOWN,         1, 18000,  50.0f, 150.0f,  500.0f, 250.0f,  50.0f, 150.0f, 0.6f,   0.0f},
    {0x0065, ACTOR_46_JIGGY,            1, SFX_3E9_UNKNOWN,         1, 16000,  90.0f,   0.0f,  930.0f,   0.0f, 100.0f,   0.0f, 0.7f,   0.0f},
    {0x0021, ACTOR_50_HONEYCOMB,        1, SFX_3E9_UNKNOWN,         1, 18000,   0.0f,   0.0f,  750.0f, 250.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x0021, ACTOR_50_HONEYCOMB,        2, SFX_3E9_UNKNOWN,         1, 18000,  50.0f, 150.0f,  500.0f, 250.0f,  50.0f, 150.0f, 0.6f,   0.0f},
    {0x0021, ACTOR_50_HONEYCOMB,        3, SFX_3E9_UNKNOWN,         1, 18000,  50.0f, 150.0f,  500.0f, 250.0f,  50.0f, 150.0f, 0.6f,   0.0f},
    {0x00A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 250.0f,   0.0f,  200.0f,   0.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x00A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 350.0f,   0.0f,  350.0f,   0.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x00A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 450.0f,   0.0f,  400.0f,   0.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x00A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 550.0f,   0.0f,  450.0f,   0.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x00A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 650.0f,   0.0f,  500.0f,   0.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x0021, ACTOR_46_JIGGY,            1, 0,                       0,     0,   0.0f,   0.0f,    0.0f,   0.0f,   0.0f,   0.0f, 0.0f,   0.0f},
    {0x0025, ACTOR_47_EMPTY_HONEYCOMB,  1, SFX_3E9_UNKNOWN,         1, 18000,   0.0f,   0.0f,  750.0f, 500.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x0129, ACTOR_352_UNKNOWN,          1, SFX_3F2_BOING,         1, 16000,   0.0f,   0.0f, 2500.0f,   0.0f,   0.0f,   0.0f, 0.4f,   0.0f},
    {0x0081, ACTOR_3A0_ICECUBE_B,       1, SFX_116_DEAF_RUSTLING,   1, 32000, 220.0f, 100.0f,  350.0f, 200.0f, 220.0f, 100.0f, 0.6f,   0.0f},
    {0x02A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 250.0f,   0.0f,  200.0f,   0.0f,   0.0f,   0.0f, 0.0f,   0.0f},
    {0x02A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 350.0f,   0.0f,  350.0f,   0.0f,   0.0f,   0.0f, 0.0f,   0.0f},
    {0x02A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 450.0f,   0.0f,  400.0f,   0.0f,   0.0f,   0.0f, 0.0f,   0.0f},
    {0x02A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 550.0f,   0.0f,  450.0f,   0.0f,   0.0f,   0.0f, 0.0f,   0.0f},
    {0x02A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 650.0f,   0.0f,  500.0f,   0.0f,   0.0f,   0.0f, 0.0f,   0.0f}
};

/* .bss */
s32 gBundle_sfxCooldown;
f32 gBundle_yaw;
f32 gBundle_randomVelocity;

/* .public */
Actor *bundle_spawn_f32(enum bundle_e bundle_id, f32 position[3]);

/* .code */
void bundle_reset(void) {
    gBundle_sfxCooldown = 0;
    gBundle_yaw = 0.0f;
    gBundle_randomVelocity = 1.0f;
}

void bundle_free(void) {}

void bundle_setYaw(f32 yaw) {
    gBundle_yaw = yaw;
}

void bundle_setRandomVelocity(f32 velocity) {
    gBundle_randomVelocity = velocity;
}

Actor *bundle_spawn_s32(enum bundle_e bundle_id, s32 position[3]) {
    f32 pos_float[3];

    TUPLE_COPY(pos_float, position)
    return bundle_spawn_f32(bundle_id, pos_float);
}

Actor *__bundle_spawnWithFirstActor(enum bundle_e bundle_id, f32 position[3], Actor *firstActor) {
    static f32 D_80366C4C = 400.0f;
    BundleInfo *bundle_info; //s2
    Actor *actor = NULL; //s3

    s32 i;
    Bundle *bundle;

    bundle_info = gBundle_array + bundle_id;
    actor = NULL;

    for (i = 0; i < bundle_info->count; i++) {//L802C90B0
        gBundle_yaw += 360.0 / bundle_info->count;

        while (360.0 <= gBundle_yaw) {
            gBundle_yaw -= 360.0;
        }

        //L802C9114
        actor = (i == 0 && firstActor) ? firstActor : actor_spawnWithYaw_f32(bundle_info->actor_id, position, 0);
        actor->is_bundle = TRUE;
        
        bundle = (Bundle *) &actor->unkBC;
        bundle->index = bundle_id;
        bundle->state = BUNDLE_STATE_1_MOVING;
        bundle->unk6 = 1;
        ml_vec3f_copy(bundle->position, actor->position);
        ml_vec3f_copy(actor->position, bundle->position);

        if (gBundle_randomVelocity != 1.0f) {
            bundle->velocity[0] = bundle_info->velocity_x * gBundle_randomVelocity;
            bundle->velocity[1] = bundle_info->velocity_y + randf2(0.0f, bundle_info->randomVelocity_y);
            bundle->velocity[2] = bundle_info->velocity_z * gBundle_randomVelocity;
            gBundle_randomVelocity = 1.0f;
        }
        else {//L802C91CC
            bundle->velocity[0] = bundle_info->velocity_x + randf2(0.0f, bundle_info->randomVelocity_x);
            bundle->velocity[1] = bundle_info->velocity_y + randf2(0.0f, bundle_info->randomVelocity_y);
            bundle->velocity[2] = bundle_info->velocity_z + randf2(0.0f, bundle_info->randomVelocity_z);
        }//L802C9210

        ml_vec3f_yaw_rotate_copy(bundle->velocity, bundle->velocity, gBundle_yaw);
        bundle->yaw_speed = D_80366C4C *= -1;
        actor->yaw = bundle->yaw = (bundle_info->flags & 0x20) ? bundle_info->yaw : randf2(0.0f, 360.0f);
        bundle->elapsed_time = 0.0f;
        bundle->unk2C = 0;
        bundle->unk2D = 1;
        bundle->flags = bundle_info->flags;
        bundle->unk2E = (bundle_info->flags & 0x1) ? (0.5 < randf()) : 0;

        if (bundle_info->flags & 0x200) {
            actor->unk5C = bundle->position[1];
        }
    }//L802C92E8

    return actor;
}

Actor *__bundle_spawnFromFirstActor(enum bundle_e bundle_id, Actor *actor) {
    gBundle_array[bundle_id].yaw = actor->yaw;
    return __bundle_spawnWithFirstActor(bundle_id, actor->position, actor);
}

Actor *bundle_spawn_f32(enum bundle_e bundle_id, f32 position[3]) {
    return __bundle_spawnWithFirstActor(bundle_id, position, NULL);
}

bool func_802C939C(Actor *actor, f32 arg1[3], f32 arg2[3], f32 arg3[3], bool arg4) {
    Bundle *bundle = (Bundle *)&actor->unkBC;
    f32 sp60;
    bool var_v1;
    f32 sp50[3];
    f32 sp44[3];
    s32 sp40;
    s32 sp3C;


    if (bundle->flags & 0x80) {
        if (actor->unk10_25 != 0) {
            if (func_80307258(arg2, actor->unk10_25 - 1, actor->unk10_18 - 1) == -1) {
                ml_vec3f_diff_copy(arg3, arg2, arg1);
                ml_vec3f_normalize(arg3);
                ml_vec3f_copy(arg2, arg1);
                return TRUE;
            }
        }
        else {
            if ((actor->unk10_18 != 0)){
                if(func_80309D58(arg2, actor->unk10_18) == 0) {
                    ml_vec3f_diff_copy(arg3, arg2, arg1);
                    ml_vec3f_normalize(arg3);
                    ml_vec3f_copy(arg2, arg1);
                    return TRUE;
                }
            }
        }
    }

    sp60 =  func_8033229C(actor->marker) * 0.66666666;
    ml_vec3f_copy(sp50, arg2);
    arg1[1] += sp60;
    arg2[1] += sp60;
    if (arg4) {
        var_v1 = func_80309DBC(arg1, arg2, sp60, arg3, 3, actor->unk154);
        if (!var_v1) {
            var_v1 = func_80309B48(arg1, arg2, arg3, actor->unk154);
            if (var_v1) {
                arg2[0] += arg3[0];
                arg2[1] += arg3[1];
                arg2[2] += arg3[2];
            }
        }
    } else {
        var_v1 = func_80320C94(arg1, arg2, sp60, arg3, 3, actor->unk154);
        if (!var_v1) {
            var_v1 = func_80320B98(arg1, arg2, arg3, actor->unk154);
            if (var_v1) {
                arg2[0] += arg3[0];
                arg2[1] += arg3[1];
                arg2[2] += arg3[2];
            }
        }
    }
    if (var_v1 && bundle->unk2D && (actor->marker->modelId == ASSET_363_MODEL_HONEYCOMB)) {
        ml_vec3f_scale_copy(sp44, arg3, sp60 / (f32) (1 << bundle->unk6));
        var_v1 = TRUE;
        arg2[0] += sp44[0];
        arg2[1] += sp44[1];
        arg2[2] += sp44[2];
        if (actor->marker->modelId != ASSET_363_MODEL_HONEYCOMB) {
            bundle->unk6++;
        }
        if (bundle->unk6 == 5) {
            bundle->unk2D = FALSE;
        } else {
            var_v1 = FALSE;
        }
    } else {
        bundle->unk2D = FALSE;
    }
    arg1[1] -= sp60;
    arg2[1] -= sp60;
    return var_v1;
}

void bundle_update(Actor *actor) {
    f32 tick;
    Bundle *bundle;
    BundleInfo *bundle_info;
    f32 previous_position[3];
    f32 sp4C[3];
    f32 sp40[3];
    s32 pad;
    s32 pad2;
    f32 speed;

    tick = time_getDelta();
    bundle = (Bundle *) &actor->unkBC;
    bundle_info = &gBundle_array[bundle->index];

    if (gBundle_sfxCooldown > 0) {
        gBundle_sfxCooldown--;
    }

    switch (bundle->state) {
        case BUNDLE_STATE_3_IDLE:
            break;

        case BUNDLE_STATE_1_MOVING:
            bundle->elapsed_time += tick;
            ml_vec3f_copy(previous_position, bundle->position);
            ml_vec3f_scale_copy(sp4C, bundle->velocity, tick);
            bundle->position[0] += sp4C[0];
            bundle->position[1] += sp4C[1];
            bundle->position[2] += sp4C[2];

            if (1.2 < bundle->elapsed_time) {
                bundle->unk2C = 1;
            }

            if (!((bundle_info->flags & 0x40) && (bundle->elapsed_time < 1.2))
                && ((func_802C939C(actor, previous_position, bundle->position, sp40, bundle_info->flags & 8))
                    || ((bundle_info->flags & 0x200) && (bundle->velocity[1] < -((bundle_info->randomVelocity_y / 2) + bundle_info->velocity_y))))
            ) {
                if (bundle_info->flags & 0x204) {
                    sp40[0] = 0.0f;
                    sp40[1] = 1.0f;
                    sp40[2] = 0.0f;
                }

                ml_vec3f_scale(bundle->velocity, -1.0f);
                speed = ((bundle->velocity[0] * sp40[0]) + (bundle->velocity[1] * sp40[1]) + (bundle->velocity[2] * sp40[2]));
                ml_vec3f_scale(sp40, 2 * speed);
                ml_vec3f_diff_copy(bundle->velocity, sp40, bundle->velocity);

                if (gBundle_sfxCooldown == 0) {
                    if (bundle_info->sfx_id != 0) {
                        func_8030E878(bundle_info->sfx_id, (f32) bundle_info->sfx_volume, bundle_info->sfx_sampleRate, bundle->position, 300.0f, 3000.0f);
                    }
                    gBundle_sfxCooldown = bundle_info->count * 8;
                }

                ml_vec3f_scale(bundle->velocity, bundle_info->bounce_factor);
                speed = gu_sqrtf((bundle->velocity[0] * bundle->velocity[0]) + (bundle->velocity[1] * bundle->velocity[1]) + (bundle->velocity[2] * bundle->velocity[2]));

                if (((speed < 200.0f) && (sp40[1] > 0.75)) || (speed < 10.0f)) {
                    bundle->state = BUNDLE_STATE_2_YAWING;
                    bundle->unk2C = 1;

                    if (bundle_info->flags & 0x10) {
                        actor->marker->propPtr->unk8_3 = TRUE;
                    }
                }
                else {

                }

                if (bundle_info->flags & 0x200) {
                    bundle->position[1] = actor->unk5C;
                }
            }
            else {
                if (bundle_info->flags & 0x100) {
                    bundle->velocity[1] -= 4000.0 * tick;
                }
                else {
                    bundle->velocity[1] -= 1500.0 * tick;
                }
            }

            ml_vec3f_copy(actor->position, bundle->position);
            break;

        case BUNDLE_STATE_2_YAWING:
            if (bundle_info->flags & 2) {
                bundle->yaw += (bundle->yaw_speed * tick);
                while (bundle->yaw >= 360.0f) { bundle->yaw -= 360.0f; }
                while (bundle->yaw < 0.0f) { bundle->yaw += 360.0f; }

                actor->yaw = bundle->yaw;
            }

            speed = (bundle->yaw_speed >= 0.0f) ? bundle->yaw_speed : -bundle->yaw_speed;

            if (speed < 0.1) {
                bundle->state = BUNDLE_STATE_3_IDLE;
            }
            break;
    }

    if (actor->position[1] < -5000.0f) {
        marker_despawn(actor->marker);
    }
}

f32 *bundle_getVelocity(Actor *actor){
    Bundle *ptr = (Bundle *)&actor->unkBC;
    return ptr->velocity;
}

bool func_802C9C14(Actor *actor){
    Bundle *ptr = (Bundle *)&actor->unkBC;
    return ptr->unk2C < 1U;
}
