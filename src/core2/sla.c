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

//array_at
void *func_802EDA7C(SLA *this, s32 indx){
    return (void *)((s32)(this + 1) + indx*this->elem_size);
}

//array_size
s32 func_802EDA94(SLA *this){
    return this->elem_cnt;
}

//array_begin
void *func_802EDA9C(SLA *this){
    return (void*)(this + 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/sla/func_802EDAA4.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/sla/func_802EDC18.s")
#else
int func_802EDC18(SLA *this, s32 arg1){
    s32 tmp_v0 = this->unk4;
    s16 *v1;
    s32 offset;
    for(v1 = (s16*)tmp_v0; *v1; v1 = (s16*)(tmp_v0 + ((s32)*v1*this->elem_size))){
        if(*v1 == arg1)
            return 0;
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

SLA *func_802EDD00(SLA *this){
    return defrag(this);
}
