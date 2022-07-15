#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802EA060(struct58s **arg0, BKAnimationList *anim_list){
    struct58s * sp24;
    Mtx *end_ptr;
    Mtx *i_ptr;
    
    sp24 = *arg0;
    if(sp24->capacity_44 < anim_list->cnt_4){
        sp24 = (struct58s *)realloc(sp24, anim_list->cnt_4 * sizeof(Mtx) + sizeof(struct58s));
        sp24->capacity_44 = anim_list->cnt_4;
        (*arg0) = sp24;
    }

    sp24->size_40 = anim_list->cnt_4;
    end_ptr = (Mtx *)(sp24->size_40*sizeof(Mtx) + (s32)sp24 +sizeof(struct58s));
    mlMtxIdent();
    for(i_ptr = sp24->data; i_ptr < end_ptr; i_ptr++){
        func_802513B0(i_ptr);
    }
}

Mtx *func_802EA110(struct58s *this, s32 arg1){
    if (arg1 == -1){
        return &this->mtx_0;
    }
    return &this->data[arg1];
    
}

void func_802EA134(struct58s *this){
    free(this);
}

struct58s *func_802EA154(void){
    struct58s *this = malloc(sizeof(struct58s));
    this->size_40 = 0;
    this->capacity_44 = 0;
    mlMtxIdent();
    func_802513B0(this);
    return this;
}

s32 func_802EA190(struct58s* this){
    if(this)
        return this->size_40;
    return 1;
}

void func_80251BCC(Mtx*);
void func_8033A5B8(s32, s32, f32[3],f32[3], f32[3]);

void func_802EA1A8(struct58s **arg0, BKAnimationList *anim_list, s32 arg2){
    struct58s * this;
    Mtx *start_ptr;
    Mtx *end_ptr;
    Mtx *i_ptr;
    BKAnimation *s0;
    f32 tmp_f0;
    s32 pad94[1];
    f32 sp88[3];
    s32 pad80[2];
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    s32 sp50[3];

    //resize animation matrices
    this = *arg0;
    if(this->capacity_44 < anim_list->cnt_4){
        this = (struct58s *)realloc(this, anim_list->cnt_4 * sizeof(Mtx) + sizeof(struct58s));
        this->capacity_44 = anim_list->cnt_4;
        (*arg0) = this;
    }

    this->size_40 = anim_list->cnt_4;
    start_ptr = this->data;
    end_ptr = &start_ptr[this->size_40];
    s0 = anim_list->anim;
    for(i_ptr = start_ptr; i_ptr < end_ptr; s0++, i_ptr++){
        func_8033A5B8(arg2, s0->unkC, sp74, sp68, sp5C);
        if(s0->unkE == -1)
            mlMtxIdent();
        else if(s0->unkE + 1 != i_ptr - start_ptr)
            func_80251BCC(&start_ptr[s0->unkE]);
        tmp_f0 = anim_list->unk0;
        mlMtxTranslate(s0->unk0[0] + tmp_f0*sp5C[0], s0->unk0[1] + tmp_f0*sp5C[1], s0->unk0[2] + tmp_f0*sp5C[2] );
        
        if(!func_80345434(sp74)){
            func_80345274(sp74, sp88);
            func_802515D4(sp88);
        }

        mlMtxScale_xyz(sp68[0], sp68[1], sp68[2]);
        mlMtxTranslate(-s0->unk0[0], -s0->unk0[1], -s0->unk0[2]);
        func_802513B0(i_ptr);
    }
}

struct58s *func_802EA374(struct58s *this){
    return defrag(this);
}
