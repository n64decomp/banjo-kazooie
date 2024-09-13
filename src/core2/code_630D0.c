#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "animation.h"
#include "ml/mtx.h"

void *defrag(void *);

void animMtxList_setBoneless(AnimMtxList **this_ptr, BKAnimationList *anim_list){
    AnimMtxList * this;
    MtxF *end_ptr;
    MtxF *i_ptr;
    
    this = *this_ptr;
    if(this->capacity_44 < anim_list->cnt_4){
        this = (AnimMtxList *)realloc(this, anim_list->cnt_4 * sizeof(Mtx) + sizeof(AnimMtxList));
        this->capacity_44 = anim_list->cnt_4;
        (*this_ptr) = this;
    }

    this->size_40 = anim_list->cnt_4;
    end_ptr = (MtxF *)(this->size_40*sizeof(MtxF) + (s32)this +sizeof(AnimMtxList));
    mlMtxIdent();
    for(i_ptr = this->data; i_ptr < end_ptr; i_ptr++){
        mlMtxGet(i_ptr);
    }
}

MtxF *animMtxList_get(AnimMtxList *this, s32 arg1){
    if (arg1 == -1){
        return &this->mtx_0;
    }
    return &this->data[arg1];
    
}

void animMtxList_free(AnimMtxList *this){
    free(this);
}

AnimMtxList *animMtxList_new(void){
    AnimMtxList *this = malloc(sizeof(AnimMtxList));
    this->size_40 = 0;
    this->capacity_44 = 0;
    mlMtxIdent();
    mlMtxGet(&this->mtx_0);
    return this;
}

s32 animMtxList_len(AnimMtxList* this){
    if(this)
        return this->size_40;
    return 1;
}

void func_8033A5B8(BoneTransformList *this, s32 bone_id, f32 arg2[4], f32 scale[3], f32 arg4[3]);

void animMtxList_setBoned(AnimMtxList **this_ptr, BKAnimationList *anim_list, BoneTransformList *arg2){
    AnimMtxList * this;
    MtxF *start_ptr;
    MtxF *end_ptr;
    MtxF *i_ptr;
    BKAnimation *s0;
    f32 tmp_f0;
    s32 pad94[1];
    f32 sp88[3];
    s32 pad80[1];
    f32 sp74[4];
    f32 sp68[3];
    f32 sp5C[3];
    s32 sp50[3];

    //resize animation matrices
    this = *this_ptr;
    if(this->capacity_44 < anim_list->cnt_4){
        this = (AnimMtxList *)realloc(this, anim_list->cnt_4 * sizeof(Mtx) + sizeof(AnimMtxList));
        this->capacity_44 = anim_list->cnt_4;
        (*this_ptr) = this;
    }

    this->size_40 = anim_list->cnt_4;
    start_ptr = this->data;
    end_ptr = &start_ptr[this->size_40];
    s0 = anim_list->anim;
    for(i_ptr = start_ptr; i_ptr < end_ptr; s0++, i_ptr++){
        func_8033A5B8(arg2, s0->bone_id, sp74, sp68, sp5C);
        if(s0->mtx_id == -1)
            mlMtxIdent();
        else if(s0->mtx_id + 1 != i_ptr - start_ptr)
            mlMtxSet(&start_ptr[s0->mtx_id]);
        tmp_f0 = anim_list->unk0;
        mlMtxTranslate(s0->unk0[0] + tmp_f0*sp5C[0], s0->unk0[1] + tmp_f0*sp5C[1], s0->unk0[2] + tmp_f0*sp5C[2] );
        
        if(!vec4f_isZero(sp74)){
            func_80345274(sp74, sp88);
            func_802515D4(sp88);
        }

        mlMtxScale_xyz(sp68[0], sp68[1], sp68[2]);
        mlMtxTranslate(-s0->unk0[0], -s0->unk0[1], -s0->unk0[2]);
        mlMtxGet(i_ptr);
    }
}

AnimMtxList *animMtxList_defrag(AnimMtxList *this){
    return defrag(this);
}
