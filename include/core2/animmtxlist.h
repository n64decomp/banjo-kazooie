#ifndef BANJO_KAZOOIE_CORE2_ANIMMTXLIST_H
#define BANJO_KAZOOIE_CORE2_ANIMMTXLIST_H

#include <ultra64.h>
#include "core1/mlmtx.h"
#include "core2/bonetransform.h"

typedef struct anim_mtx_list_s {
    MtxF default_matrix;
    s32 size;
    s32 capacity;
    MtxF data[];
}AnimMtxList;

void animMtxList_setBoneless(AnimMtxList **this_ptr, BKAnimationList *anim_list);
MtxF *animMtxList_get(AnimMtxList *this, s32 index);
void animMtxList_free(AnimMtxList *this);
AnimMtxList *animMtxList_new(void);
s32 animMtxList_getLength(AnimMtxList* this);
void animMtxList_setBoned(AnimMtxList **this_ptr, BKAnimationList *anim_list, BoneTransformList *bone_transform_list);
AnimMtxList *animMtxList_defrag(AnimMtxList *this);


#endif
