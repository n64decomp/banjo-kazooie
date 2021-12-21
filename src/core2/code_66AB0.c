#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .code */
//array_clear
void func_802EDA40(struct5Cs *this){
    int i;
    s32 ptr = (s32)(this + 1);
    for(i = 1; i < this->elem_cnt; i++){
        *(s16 *)ptr = i;
        ptr += this->elem_size;
    }
    *(s16 *)ptr = 0;
}

//array_at
void *func_802EDA7C(struct5Cs *this, s32 indx){
    return (void *)((s32)(this + 1) + indx*this->elem_size);
}

//array_size
s32 func_802EDA94(struct5Cs *this){
    return this->elem_cnt;
}

//array_begin
void *func_802EDA9C(struct5Cs *this){
    return (void*)(this + 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_66AB0/func_802EDAA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_66AB0/func_802EDC18.s")

//array_free
void func_802EDC64(struct5Cs *this){
    free(this);
}

//array_new
struct5Cs *func_802EDC84(s32 size, s32 cnt){
    struct5Cs *this;
    cnt++;
    this = (struct5Cs *) malloc(size*cnt + sizeof(struct5Cs));
    this->elem_size = size;
    this->elem_cnt = cnt;
    func_802EDA40(this);
    return this;
}

void func_802EDCDC(struct5Cs *this, s32 indx){
    void* *ptr_n = ((s32)(this + 1) + indx*this->elem_size);
    *(s16 *)ptr_n = *(s16 *)(this +1);
    *(s16 *)(this +1) = indx;
}

struct5Cs *func_802EDD00(struct5Cs *this){
    return func_802555DC(this);
}
