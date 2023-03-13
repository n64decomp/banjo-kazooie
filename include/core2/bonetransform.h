#ifndef _BONE_TRANSFORMATION_H_
#define _BONE_TRANSFORMATION_H_
#include <ultratypes.h>

typedef struct {
    f32 unk0[4];
    f32 scale[3];
    f32 unk1C[3];
}BoneTransform;

typedef struct bone_transform_list_s{
    BoneTransform *ptr;
    s32 count;
}BoneTransformList;
#endif
