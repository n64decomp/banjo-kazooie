#ifndef BANJO_KAZOOIE_CORE2_SPAWNQUEUE_H
#define BANJO_KAZOOIE_CORE2_SPAWNQUEUE_H

#include <ultra64.h>
#include "enums.h"

typedef Actor *(*spawnqueue_add_0_callback_f)(void);
typedef Actor *(*spawnqueue_add_1_callback_f)(s32);
typedef Actor *(*spawnqueue_add_2_callback_f)(s32, s32);
typedef Actor *(*spawnqueue_add_3_callback_f)(s32, s32, s32);
typedef Actor *(*spawnqueue_add_4_callback_f)(s32, s32, s32, s32);
typedef Actor *(*spawnqueue_add_5_callback_f)(s32, s32, s32, s32, s32);

typedef struct spawnqueue_function_s {
    union { 
        spawnqueue_add_0_callback_f func0;
        spawnqueue_add_1_callback_f func1;
        spawnqueue_add_2_callback_f func2;
        spawnqueue_add_3_callback_f func3;
        spawnqueue_add_4_callback_f func4;
        spawnqueue_add_5_callback_f func5;
    };
    s32 args[5];
    s32 arg_count;
} SpawnQueueFunction;

void spawnQueue_init(void);
void spawnQueue_reset(void);
void spawnQueue_free(void);
void spawnQueue_func_802C39D4(void);
void spawnQueue_func_802C3A18(void);
void spawnQueue_flush(void);
void spawnQueue_unlock(void);
void spawnQueue_lock(void);

void spawnQueue_add_0(spawnqueue_add_0_callback_f func);
void spawnQueue_add_1(spawnqueue_add_1_callback_f func, s32 arg1);
void spawnQueue_add_2(spawnqueue_add_2_callback_f func, s32 arg1, s32 arg2);
void spawnQueue_add_3(spawnqueue_add_3_callback_f func, s32 arg1, s32 arg2, s32 arg3);
void spawnQueue_add_4(spawnqueue_add_4_callback_f func, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void spawnQueue_add_5(spawnqueue_add_5_callback_f func, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

Actor *spawnQueue_actor_f32(s32 actor_id, s32 x, s32 y, s32 z);
Actor *spawnQueue_actor_s16(s32 actor_id, s32 x, s32 y, s32 z);
Actor *spawnQueue_actor_s32(s32 actor_id, s32 x, s32 y, s32 z);
Actor *spawnQueue_bundle_f32(s32 bundle_id, s32 x, s32 y, s32 z);
Actor *spawnQueue_bundleWithYaw_f32(s32 bundle_id, s32 x, s32 y, s32 z, s32 yaw);
Actor *spawnQueue_bundle_s32(s32 bundle_id, s32 x, s32 y, s32 z);
Actor *spawnQueue_bundle_s32_2(enum bundle_e bundle_id, s32 x, s32 y, s32 z); // unused

void spawnQueue_defrag(void);

#define SPAWNQUEUE_ADD_0(func)                                          spawnQueue_add_0((spawnqueue_add_0_callback_f) (func))
#define SPAWNQUEUE_ADD_1(func, arg1)                                    spawnQueue_add_1((spawnqueue_add_1_callback_f) (func), (arg1))
#define SPAWNQUEUE_ADD_2(func, arg1, arg2)                              spawnQueue_add_2((spawnqueue_add_2_callback_f) (func), (arg1), (arg2))
#define SPAWNQUEUE_ADD_3(func, arg1, arg2, arg3)                        spawnQueue_add_3((spawnqueue_add_3_callback_f) (func), (arg1), (arg2), (arg3))
#define SPAWNQUEUE_ADD_4(func, arg1, arg2, arg3, arg4)                  spawnQueue_add_4((spawnqueue_add_4_callback_f) (func), (arg1), (arg2), (arg3), (arg4))
#define SPAWNQUEUE_ADD_5(func, arg1, arg2, arg3, arg4, arg5)            spawnQueue_add_5((spawnqueue_add_5_callback_f) (func), (arg1), (arg2), (arg3), (arg4), (arg5))

#define SPAWNQUEUE_ADD_ACTOR_F32(actor_id, x, y, z)                     spawnQueue_add_4((spawnqueue_add_4_callback_f) spawnQueue_actor_f32, (actor_id), *((s32 *) (&(x))), *((s32 *) (&(y))), *((s32 *) (&(z))))
#define SPAWNQUEUE_ADD_ACTOR_S16(actor_id, x, y, z)                     spawnQueue_add_4((spawnqueue_add_4_callback_f) spawnQueue_actor_s16, (actor_id), *((s32 *) (&(x))), *((s32 *) (&(y))), *((s32 *) (&(z))))
#define SPAWNQUEUE_ADD_ACTOR_S32(actor_id, x, y, z)                     spawnQueue_add_4((spawnqueue_add_4_callback_f) spawnQueue_actor_s32, (actor_id), (x), (y), (z))
#define SPAWNQUEUE_ADD_BUNDLE_F32(bundle_id, x, y, z)                   spawnQueue_add_4((spawnqueue_add_4_callback_f) spawnQueue_bundle_f32, (bundle_id), *((s32 *) (&(x))), *((s32 *) (&(y))), *((s32 *) (&(z))))
#define SPAWNQUEUE_ADD_BUNDLE_WITH_YAW_F32(bundle_id, x, y, z, yaw)     spawnQueue_add_5((spawnqueue_add_5_callback_f) spawnQueue_bundleWithYaw_f32, (bundle_id), *((s32 *) (&(x))), *((s32 *) (&(y))), *((s32 *) (&(z))), *((s32 *) (&(yaw))))

void lair_addSpawnableActors(void);
void fight_addSpawnableActors(void);
void cutscene_addSpawnableActors(void);
void SM_addSpawnableActors(void);
void MMM_addSpawnableActors(void);
void CC_addSpawnableActors(void);
void GV_addSpawnableActors(void);
void TTC_addSpawnableActors(void);
void MM_addSpawnableActors(void);
void BGS_addSpawnableActors(void);
void RBB_addSpawnableActors(void);
void FP_addSpawnableActors(void);
void CCW_addSpawnableActors(void);

#endif
