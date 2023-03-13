#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "animation.h"


extern void func_803458E4(f32[4], f32[4], f32[4], f32);

void boneTransformList_reset(BoneTransformList *this) {
    BoneTransform *end_ptr;
    BoneTransform *i_ptr;

    i_ptr = this->ptr;
    end_ptr = i_ptr + this->count;
    for(i_ptr = i_ptr; i_ptr < end_ptr; i_ptr++){
        i_ptr->unk0[0] = i_ptr->unk0[1] = i_ptr->unk0[2] = 0.0f;
        i_ptr->unk0[3] = 1.0f;
        i_ptr->scale[0] = i_ptr->scale[1] = i_ptr->scale[2] = 1.0f;
        i_ptr->unk1C[0] = i_ptr->unk1C[1] = i_ptr->unk1C[2] = 0.0f;
    }
}

void func_8033A57C(BoneTransformList *this, s32 bone_id, f32 arg2[4]) {
    vec4f_clone(arg2, this->ptr[bone_id].unk0);

}

void func_8033A5B8(BoneTransformList *this, s32 bone_id, f32 arg2[4], f32 scale[3], f32 arg4[3]) {
    vec4f_clone(arg2, this->ptr[bone_id].unk0);
    scale[0] = this->ptr[bone_id].scale[0];
    scale[1] = this->ptr[bone_id].scale[1];
    scale[2] = this->ptr[bone_id].scale[2];
    arg4[0] = this->ptr[bone_id].unk1C[0];
    arg4[1] = this->ptr[bone_id].unk1C[1];
    arg4[2] = this->ptr[bone_id].unk1C[2];
}

void boneTransformList_getBoneScale(BoneTransformList *this, s32 bone_id, f32 scale[3]) {
    scale[0] = this->ptr[bone_id].scale[0];
    scale[1] = this->ptr[bone_id].scale[1];
    scale[2] = this->ptr[bone_id].scale[2];
}

void func_8033A6B0(BoneTransformList *this, s32 bone_id, f32 arg2[3]) {
    arg2[0] = this->ptr[bone_id].unk1C[0];
    arg2[1] = this->ptr[bone_id].unk1C[1];
    arg2[2] = this->ptr[bone_id].unk1C[2];
}

void boneTransformList_free(BoneTransformList *this){
    free(this);
}

BoneTransformList *boneTransformList_new(void) {
    BoneTransformList *this;

    this = (BoneTransformList *)malloc(sizeof(BoneTransformList) + 0x6D*sizeof(BoneTransform));
    this->ptr = (BoneTransform *) (this + 1);
    this->count = 0x6D;
    boneTransformList_reset(this);
    return this;
}

void boneTransformList_interpolate(BoneTransformList *this, BoneTransformList *start_xform_list, BoneTransformList *end_xform_list, f32 arg3) {
    s32 i;
    s32 cnt;
    BoneTransform *start_ptr;
    BoneTransform *end_ptr;
    BoneTransform *i_xform;
    BoneTransform *start_xform;
    BoneTransform *end_xform;

    start_ptr = this->ptr;
    start_xform = start_xform_list->ptr;
    end_xform = end_xform_list->ptr;
    end_ptr = start_ptr + this->count;
    for(i_xform = start_ptr; i_xform < end_ptr; i_xform++, start_xform++, end_xform++){
        if( (start_xform->unk0[0] == end_xform->unk0[0])
            && (start_xform->unk0[1] == end_xform->unk0[1])
            && (start_xform->unk0[2] == end_xform->unk0[2])
            && (start_xform->unk0[3] == end_xform->unk0[3])
        ) {
            i_xform->unk0[0] = start_xform->unk0[0];
            i_xform->unk0[1] = start_xform->unk0[1];
            i_xform->unk0[2] = start_xform->unk0[2];
            i_xform->unk0[3] = start_xform->unk0[3];
        } else {
            func_803458E4(i_xform, start_xform, end_xform, arg3);
        }
        i_xform->scale[0] = start_xform->scale[0] + ((end_xform->scale[0] - start_xform->scale[0]) * arg3);
        i_xform->scale[1] = start_xform->scale[1] + ((end_xform->scale[1] - start_xform->scale[1]) * arg3);
        i_xform->scale[2] = start_xform->scale[2] + ((end_xform->scale[2] - start_xform->scale[2]) * arg3);
        i_xform->unk1C[0] = start_xform->unk1C[0] + ((end_xform->unk1C[0] - start_xform->unk1C[0]) * arg3);
        i_xform->unk1C[1] = start_xform->unk1C[1] + ((end_xform->unk1C[1] - start_xform->unk1C[1]) * arg3);
        i_xform->unk1C[2] = start_xform->unk1C[2] + ((end_xform->unk1C[2] - start_xform->unk1C[2]) * arg3);
    }
}


void func_8033A8F0(BoneTransformList *this, s32 bone_id, f32 arg2[4]){
    vec4f_clone(&this->ptr[bone_id], arg2);
}

void boneTransformList_setBoneScale(BoneTransformList *this, s32 bone_id, f32 scale[3]) {
    this->ptr[bone_id].scale[0] = scale[0];
    this->ptr[bone_id].scale[1] = scale[1];
    this->ptr[bone_id].scale[2] = scale[2];
}

void func_8033A968(BoneTransformList *this, s32 bone_id, f32 arg2[3]) {
    this->ptr[bone_id].unk1C[0] = arg2[0];
    this->ptr[bone_id].unk1C[1] = arg2[1];
    this->ptr[bone_id].unk1C[2] = arg2[2];
}

void func_8033A9A8(BoneTransformList *this, s32 bone_id, f32 arg2[4]){
    f32 sp18[4];
    func_80345C78(sp18, arg2);
    func_8033A8F0(this, bone_id, sp18);
}

BoneTransformList * boneTransformList_defrag(BoneTransformList *this){
    BoneTransformList *var_v0;
    var_v0 = (BoneTransformList *)defrag(this);
    var_v0->ptr = (BoneTransform *)(var_v0 + 1);
    return var_v0;
}
