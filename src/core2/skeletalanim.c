#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "animation.h"

extern void animationFile_getBoneTransformList(void *, f32, BoneTransformList *);
extern void boneTransformList_interpolate(BoneTransformList *, BoneTransformList *, BoneTransformList *, f32);
extern BoneTransformList *boneTransformList_new(void);


/* .code */
static void skeletalAnim_clearTransition(SkeletalAnimation *self){
    if(self->bone_transform != NULL){
        boneTransformList_free(self->bone_transform);
        self->bone_transform = NULL;
    }

    if(self->animation_bin != NULL){
        assetcache_release(self->animation_bin);
        self->animation_bin = NULL;
    }

    if(self->transition_start != NULL){
        boneTransformList_free(self->transition_start);
        self->transition_start = NULL;
    }

    if(self->transition_target != NULL){
        boneTransformList_free(self->transition_target);
        self->transition_target = NULL;
    }

    self->transition_duration = 0.0f;
}

static void __perform_callback(SkeletalAnimationCallback* arg0){
    if(arg0->arg_count == 0){
        ((void(*)(void))(arg0->callback_fn))();
    }
    else if(arg0->arg_count == 1){
        ((void(*)(s32))(arg0->callback_fn))(arg0->arg);
    }
}

void skeletalAnim_clearCallbacks(SkeletalAnimation *self){
    if(self->callback_list != NULL){
        vector_clear(self->callback_list);
    }
}

enum asset_e skeletalAnim_getAnimId(SkeletalAnimation *self){
    return self->animation_id;
}

f32 skeletalAnim_getProgress(SkeletalAnimation *self){
    return self->progress;
}

void skeletalAnim_getProgressRange(SkeletalAnimation *self, f32 *prev_progress, f32 *progress){
    *prev_progress = self->prev_progress;
    *progress = self->progress;
}

BoneTransformList *skeletalAnim_getBoneTransformList(SkeletalAnimation *self){
    self->unk14 = 0;
    if(self->bone_transform == NULL){
        self->bone_transform = boneTransformList_new();
    }

    if(self->unk30 != 0){
        self->unk30 = 0;
        return self->bone_transform;
    }

    if(self->animation_id == 0){
        return self->bone_transform;
    }

    if(self->animation_bin == NULL){
        self->animation_bin = (AnimationFile *)assetcache_get(self->animation_id);
    }

    if(0.0f == self->transition_duration){
        animationFile_getBoneTransformList(self->animation_bin, self->progress, self->bone_transform);
        return self->bone_transform;
    }

    if(self->transition_target == NULL){
        self->transition_target = (BoneTransformList *) boneTransformList_new();
    }
    animationFile_getBoneTransformList(self->animation_bin, self->progress, self->transition_target);
    boneTransformList_interpolate(self->bone_transform, self->transition_start, self->transition_target, self->transition_progress);
    return self->bone_transform;
}

s32 skeletalAnim_getLoopCount(SkeletalAnimation *self){
    return self->loop_count;
}

void skeletalAnim_setCallback_0(SkeletalAnimation *self, f32 when, GenFunction_0 fn){
    SkeletalAnimationCallback *ptr;
    if(self->callback_list == NULL){
        self->callback_list = vector_new(sizeof(SkeletalAnimationCallback), 8);
    }
    ptr = (SkeletalAnimationCallback *)vector_pushBackNew(&self->callback_list);
    ptr->when = when;
    ptr->arg_count = 0;
    ptr->callback_fn = fn;
    ptr->arg = 0;
}

void skeletalAnim_setCallback_1(SkeletalAnimation *self, f32 when, GenFunction_1 fn, s32 arg){
    SkeletalAnimationCallback *ptr;
    if(self->callback_list == NULL){
        self->callback_list = vector_new(sizeof(SkeletalAnimationCallback), 8);
    }
    ptr = (SkeletalAnimationCallback *)vector_pushBackNew(&self->callback_list);
    ptr->when = when;
    ptr->arg_count = 1;
    ptr->callback_fn = fn;
    ptr->arg = (s32)arg;
}

void skeletalAnim_free(SkeletalAnimation *self){
    VLA * temp_a0;
    skeletalAnim_clearTransition(self);
    temp_a0 = self->callback_list;
    if(temp_a0 != NULL){
        vector_free(temp_a0);
    }
    free(self);
}

SkeletalAnimation *skeletalAnim_new(void){
    SkeletalAnimation *self;

    self = (SkeletalAnimation *)malloc(sizeof(SkeletalAnimation));
    self->bone_transform = NULL;
    self->animation_bin = NULL;
    self->callback_list = 0;
    self->unk14 = 0;
    self->behavior = SKELETAL_ANIM_1_LOOP;
    self->loop_count = 0;
    self->animation_id = 0;
    self->unk30 = 0;
    self->transition_start = NULL;
    self->transition_target = NULL;
    self->progress = 0.0f;
    self->duration = 0.0f;
    self->prev_progress = 0.0f;
    self->transition_progress = 0.0f;
    self->transition_duration = 0.0f;

    return self;
}

void skeletalAnim_func_80335918(SkeletalAnimation *self){
    self->unk30 = 1;
}

void skeletalAnim_set(SkeletalAnimation *self, enum asset_e anim_id, f32 transistion_duration, f32 duration){
    if(self->animation_bin != NULL && anim_id != self->animation_id){
        assetcache_release(self->animation_bin);
        self->animation_bin = NULL;
    }

    if(self->callback_list != NULL && anim_id != self->animation_id){
        vector_free(self->callback_list);
        self->callback_list = NULL;
    }

    self->progress = 0.0f;
    self->duration = duration;
    self->loop_count = 0;
    self->animation_id = anim_id;
    self->prev_progress = 0.0f;
    self->transition_progress = 0.0f;
    self->transition_duration = transistion_duration;
    if(0.0f < transistion_duration){
        if(self->bone_transform != NULL ){
            BoneTransformList *tmp;
            tmp = self->transition_start;
            self->transition_start = self->bone_transform;
            self->bone_transform = tmp;
            if(self->transition_target != 0){
                boneTransformList_reset(self->transition_target);
            }
        } else {
            self->transition_duration = 0.0f;
        }
    }
}

//sets animation, but retains current animation's progress
void skeletalAnim_swap(SkeletalAnimation *self, enum asset_e anim_id, f32 transistion_duration, f32 duration){
    f32 sp1C;
    sp1C = skeletalAnim_getProgress(self);
    skeletalAnim_set(self, anim_id, transistion_duration, duration);
    skeletalAnim_setProgress(self, sp1C);
}

void skeletalAnim_setProgress(SkeletalAnimation *self, f32 progress){
    self->progress = progress;
}

void skeletalAnim_setDuration(SkeletalAnimation *self, f32 duration){
    self->duration = duration;
}

void skeletalAnim_setBehavior(SkeletalAnimation *self, enum skeletal_anim_e behavior){
    self->behavior = behavior;
}

void skeletalAnim_update(SkeletalAnimation *self, f32 dt, s32 arg2) {
    f32 pad2C;
    SkeletalAnimationCallback *begin_ptr;
    SkeletalAnimationCallback *end_ptr;
    SkeletalAnimationCallback *i_ptr;

    if (arg2 == 0) {
        if (self->unk14 < 10) {
            self->unk14++;
            if (self->unk14 == 0xA) {
                skeletalAnim_clearTransition(self);
            }
        }
    }
    if (self->animation_id != 0) {
        self->prev_progress = self->progress;
        if ( self->duration > 0.0f) {
            if (self->behavior == SKELETAL_ANIM_1_LOOP) { //LOOP
                self->progress +=  dt /  self->duration;
                while (self->progress >= 1.0f) {
                    self->progress -= 1.0f;
                    self->loop_count++;
                }
            } else if ((self->behavior == SKELETAL_ANIM_2_ONCE) && (self->loop_count == 0)) {
                //FORWARD ONCE
                self->progress += (dt /  self->duration);
                if (self->progress >= 1.0f) {
                    self->progress = 0.99999f;
                    self->loop_count++;
                }
            } else if ((self->behavior == SKELETAL_ANIM_3_BACKWARDS) && (self->progress > 0.0f)) {
                //BACKWARDS ONCE
                self->progress -=  (dt /  self->duration);
                if (self->progress < 0.0f) {
                    self->progress = 0.0f;
                }
            }
        }

        if (self->callback_list != NULL) {
            begin_ptr = vector_getBegin(self->callback_list);
            end_ptr = vector_getEnd(self->callback_list);
            for(i_ptr = begin_ptr; i_ptr < end_ptr; i_ptr++) {
                if (((self->prev_progress <  i_ptr->when) || (self->progress < self->prev_progress)) && ( i_ptr->when <= self->progress)) {
                    __perform_callback(i_ptr);
                }
            }
        }
        if (self->transition_duration > 0.0f) {
            if (self->transition_progress < 1.0f) {
                self->transition_progress += dt / self->transition_duration;
                if (self->transition_progress >= 1.0f) {
                    self->transition_progress = 1.0f;
                }
            } else {
                self->transition_duration = 0.0f;
                if (self->bone_transform != 0) {
                    boneTransformList_reset(self->bone_transform);
                }
            }
        }
    }
}
