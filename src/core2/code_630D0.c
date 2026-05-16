#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "animation.h"

void func_8033A5B8(BoneTransformList *this, s32 bone_id, f32 arg2[4], f32 scale[3], f32 arg4[3]);
void *defrag(void *);

void animMtxList_setBoneless(AnimMtxList **this_ptr, BKAnimationList *anim_list) {
    AnimMtxList *this;
    MtxF *start_ptr, *end_ptr, *i_ptr;
    
    this = *this_ptr;

    if (this->capacity < anim_list->count) {
        this = (AnimMtxList *) realloc(this, anim_list->count * sizeof(MtxF) + sizeof(AnimMtxList));
        this->capacity = anim_list->count;
        *this_ptr = this;
    }

    this->size = anim_list->count;
    start_ptr = this->data;
    end_ptr = &start_ptr[this->size];

    mlMtxIdent();
    for (i_ptr = start_ptr; i_ptr < end_ptr; i_ptr++) {
        mlMtxGet(i_ptr);
    }
}

MtxF *animMtxList_get(AnimMtxList *this, s32 index) {
    if (index == -1) {
        return &this->default_matrix;
    }

    return &this->data[index];
}

void animMtxList_free(AnimMtxList *this){
    free(this);
}

AnimMtxList *animMtxList_new(void) {
    AnimMtxList *this = malloc(sizeof(AnimMtxList));
    this->size = 0;
    this->capacity = 0;
    mlMtxIdent();
    mlMtxGet(&this->default_matrix);
    return this;
}

s32 animMtxList_getLength(AnimMtxList* this) {
    if (this)
        return this->size;

    return 1;
}

void animMtxList_setBoned(AnimMtxList **this_ptr, BKAnimationList *anim_list, BoneTransformList *bone_transform_list) {
    AnimMtxList *this;
    MtxF *start_ptr, *end_ptr, *i_ptr;
    BKAnimation *animation;
    f32 tmp_f0;
    s32 pad94[1];
    f32 sp88[3];
    s32 pad80[1];
    f32 sp74[4];
    f32 scale[3];
    f32 sp5C[3];
    s32 sp50[3];

    this = *this_ptr;

    if (this->capacity < anim_list->count) {
        this = (AnimMtxList *) realloc(this, anim_list->count * sizeof(MtxF) + sizeof(AnimMtxList));
        this->capacity = anim_list->count;
        *this_ptr = this;
    }

    this->size = anim_list->count;
    start_ptr = this->data;
    end_ptr = &start_ptr[this->size];

    animation = anim_list->animations;
    for (i_ptr = start_ptr; i_ptr < end_ptr; animation++, i_ptr++) {
        func_8033A5B8(bone_transform_list, animation->bone_id, sp74, scale, sp5C);
        
        if (animation->mtx_id == -1)
            mlMtxIdent();
        else if (animation->mtx_id + 1 != i_ptr - start_ptr)
            mlMtxSet(&start_ptr[animation->mtx_id]);

        tmp_f0 = anim_list->unk0;

        mlMtxTranslate(animation->translation[0] + tmp_f0 * sp5C[0], animation->translation[1] + tmp_f0 * sp5C[1], animation->translation[2] + tmp_f0 * sp5C[2]);
        
        if (!vec4f_isZero(sp74)) {
            func_80345274(sp74, sp88);
            func_802515D4(sp88);
        }

        mlMtxScale_xyz(scale[0], scale[1], scale[2]);
        mlMtxTranslate(-animation->translation[0], -animation->translation[1], -animation->translation[2]);
        mlMtxGet(i_ptr);
    }
}

AnimMtxList *animMtxList_defrag(AnimMtxList *this) {
    return defrag(this);
}
