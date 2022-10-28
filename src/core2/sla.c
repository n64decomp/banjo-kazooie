#include <ultra64.h>
#include "functions.h"
#include "variables.h"

// Static Length Array

/* .code */
void array_clear(SLA *this){
    int i;
    s32 ptr = (s32)(this + 1);
    for(i = 1; i < this->elem_cnt; i++){
        *(s16 *)ptr = i;
        ptr += this->elem_size;
    }
    *(s16 *)ptr = 0;
}

void *array_at(SLA *this, s32 indx){
    return (void *)((s32)(this + 1) + indx*this->elem_size);
}

s32 array_size(SLA *this){
    return this->elem_cnt;
}

void *array_begin(SLA *this){
    return (void*)(this + 1);
}

void *func_802EDAA4(SLA **this, s32 *arg1) {
    s32 new_cnt;
    SLA *var_s0;
    s16 *first_ptr;
    s16 *i_ptr;
    s32 prev_cnt;
    s32 i;

    var_s0 = *this;
    first_ptr = (s16*)var_s0->unk4;
    if (*first_ptr == 0) {
        prev_cnt = var_s0->elem_cnt;
        new_cnt = prev_cnt + 10;
        var_s0 = realloc(var_s0, (var_s0->elem_size * new_cnt) + sizeof(SLA));
        first_ptr = (s16*)var_s0->unk4;
        var_s0->elem_cnt = new_cnt;
        *this = var_s0;
        for(i = new_cnt - 1, i_ptr = &var_s0->unk4[i * var_s0->elem_size]; i >= prev_cnt; i--){
            *i_ptr = *first_ptr;
            *first_ptr = i;
            i_ptr = (s32)i_ptr - var_s0->elem_size;
        }
    }
    i = *first_ptr;
    i_ptr = (s32)first_ptr + (i * var_s0->elem_size);
    *arg1 = i;
    *first_ptr = *i_ptr;
    return (s32) i_ptr;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/sla/func_802EDC18.s")
#else
int func_802EDC18(SLA *this, s32 arg1){
    s32 tmp_v0 = this->unk4;
    s16 *v1;
    s32 offset;
    for(v1 = (s16*)tmp_v0; *v1; ){
        if(*v1 == arg1)
            return 0;
        v1 = (s16*)(tmp_v0 + ((s32)*v1*this->elem_size));
    }
    return 1;
}
#endif

void array_free(SLA *this){
    free(this);
}

SLA *array_new(s32 size, s32 cnt){
    SLA *this;
    cnt++;
    this = (SLA *) malloc(size*cnt + sizeof(SLA));
    this->elem_size = size;
    this->elem_cnt = cnt;
    array_clear(this);
    return this;
}

void func_802EDCDC(SLA *this, s32 indx){
    void* *ptr_n = ((s32)(this + 1) + indx*this->elem_size);
    *(s16 *)ptr_n = *(s16 *)(this +1);
    *(s16 *)(this +1) = indx;
}

SLA *array_defrag(SLA *this){
    return defrag(this);
}
