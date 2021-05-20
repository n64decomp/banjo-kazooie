#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* VARIABLE LENGTH ARRAY */

void vla_clear(VLA *this){
    this->end = this->begin;
}

void *vla_getBegin(VLA *this){
    return this->begin;
}

void *vla_at(VLA *this, u32 n){
    return (void *)((u32) this->begin + n*this->elem_size);
}

s32 vla_getIndex(VLA *this, void *elemPtr){
    return ((s32)elemPtr - (s32)this->begin)/(s32)this->elem_size;
}

s32 vla_size(VLA *this){
    return ((s32)this->end - (s32)this->begin)/this->elem_size;
}

void *vla_getEnd(VLA *this){
    return this->end;
}

void *vla_pushBackNew(VLA **thisPtr){
    void *retVal;
    VLA* this;
    s32 size;
    s32 mem_size;

    this = *thisPtr;
    if(this->end == this->mem_end){
        size = ((s32)this->end - (s32)this->begin)/this->elem_size;
        mem_size = size + 5;
        this = realloc(this,  mem_size*this->elem_size + sizeof(VLA));
        this->begin = &this->data;
        this->end = (u8 *)this->begin + size* this->elem_size;
        this->mem_end = (u8 *)this->begin + mem_size* this->elem_size;
        *thisPtr = this; 
    }
    retVal = this->end;
    this->end = (void *)((s32)this->end + this->elem_size);
    return retVal;
}

void *vla_insertNew(VLA **thisPtr, s32 indx){
    VLA *this;
    s32 i;

    vla_pushBackNew(thisPtr);
    this = *thisPtr;
    i = ((s32)this->end - (s32)this->begin)/this->elem_size;
    while(indx < --i){
        func_80254608((s32)this->begin + (i)*this->elem_size, (s32)this->begin + (i -1)*this->elem_size, this->elem_size);
    }
    return (void *)((s32)this->begin +  indx*this->elem_size);
}

void vla_free(VLA *this){
    free(this);
}

VLA *vla_new(u32 elemSize, u32 cnt){
    VLA *this = malloc(cnt*elemSize + sizeof(VLA));
    this->elem_size = elemSize;
    this->begin = &this->data;
    this->end = &this->data;
    this->mem_end = (u8*)this->end + cnt*elemSize;
    return this;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/vla/vla_remove.s")
// void vla_remove(VLA *this, u32 indx){
//     u32 elemOffset = (u32)this->begin + indx * this->elem_size;
//     u32 nextOffset = (u32)this->begin + (indx + 1) * this->elem_size;
//     u32 size = (u32)this->end - (u32)this->begin;
    
//     func_80254608( elemOffset, nextOffset, size - (indx + 1) * this->elem_size);
//     this->end = (u32)this->end - this->elem_size;
// }


void vla_popBack_n(VLA *this, u32 n){
    this->end = (void *)((u32)this->end - n * this->elem_size);
}

void vla_assign(VLA *this, s32 indx, void* value){
    func_80254608((s32)this->begin + indx * this->elem_size, value, this->elem_size);
}

VLA * vla_802ED9E0(VLA *this){
   s32 oldSize;
   s32 oldMemSize;

   oldSize = (s32) this->end - (s32)this->begin;
   oldMemSize = (s32) this->mem_end - (s32)this->begin;
   this = (VLA *)func_802555DC(this);
   this->begin = &this->data;
   this->end = (void *)((s32)this->begin + oldSize);
   this->mem_end = (void *)((s32)this->begin + oldMemSize);
   return this;
}
