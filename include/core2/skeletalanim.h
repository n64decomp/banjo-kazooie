#ifndef _SKELETAL_ANIMATION_H_
#define _SKELETAL_ANIMATION_H_
#include "core2/vla.h"
#include "generic.h"
#include "bonetransform.h"

enum skeletal_anim_e {
    SKELETAL_ANIM_1_LOOP = 1,
    SKELETAL_ANIM_2_ONCE,
    SKELETAL_ANIM_3_BACKWARDS,
    SKELETAL_ANIM_4_STOPPED
};

typedef struct {
    f32 when;
    u8 arg_count;
    //u8 pad5[0x3];
    void * callback_fn;
    s32 arg;
}SkeletalAnimationCallback;

typedef struct {
    BoneTransformList *bone_transform;
    struct animation_file_s *animation_bin;
    f32 progress;
    f32 duration;
    vector(SkeletalAnimationCallback) *callback_list;
    u8 unk14;
    u8 behavior;
    s16 animation_id;
    s32 loop_count;
    f32 prev_progress;
    f32 transition_progress;
    BoneTransformList *transition_start;
    BoneTransformList *transition_target;
    f32 transition_duration;
    u8 unk30;
    // u8 pad31[3];
}SkeletalAnimation;

void               skeletalAnim_clearCallbacks(SkeletalAnimation *self);
enum asset_e       skeletalAnim_getAnimId(SkeletalAnimation *self);
f32                skeletalAnim_getProgress(SkeletalAnimation *self);
void               skeletalAnim_getProgressRange(SkeletalAnimation *self, f32 *prev_progress, f32 *progress);
BoneTransformList *skeletalAnim_getBoneTransformList(SkeletalAnimation *self);
s32                skeletalAnim_getLoopCount(SkeletalAnimation *self);
void               skeletalAnim_setCallback_0(SkeletalAnimation *self, f32 when, GenFunction_0 fn);
void               skeletalAnim_setCallback_1(SkeletalAnimation *self, f32 when, GenFunction_1 fn, s32 arg);
void               skeletalAnim_free(SkeletalAnimation *self);
SkeletalAnimation *skeletalAnim_new(void);
void               skeletalAnim_func_80335918(SkeletalAnimation *self);
void               skeletalAnim_set(SkeletalAnimation *self, enum asset_e anim_id, f32 transistion_duration, f32 duration);
void               skeletalAnim_swap(SkeletalAnimation *self, enum asset_e anim_id, f32 transistion_duration, f32 duration);
void               skeletalAnim_setProgress(SkeletalAnimation *self, f32 progress);
void               skeletalAnim_setDuration(SkeletalAnimation *self, f32 duration);
void               skeletalAnim_setBehavior(SkeletalAnimation *self, enum skeletal_anim_e behavior);
void               skeletalAnim_update(SkeletalAnimation *self, f32 dt, s32 arg2);
#endif
