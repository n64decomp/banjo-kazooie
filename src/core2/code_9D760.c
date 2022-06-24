#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_803246F0(u8* self, s32 indx){
    self[indx - 1] = 0xff;
}

void func_80324700(u8* self){
    u8* i_ptr;

    for(i_ptr = self; i_ptr < self + 0x10; i_ptr++){
        if(*i_ptr != 0xFF){
            func_8033A45C((i_ptr - self) + 1, *i_ptr);
        }
    }
}

void func_80324770(u8* self, s32 indx, s32 value){
    self[indx - 1] = value;
}

void func_8032477C(u8 *self){
    free(self);
}

u8 *func_8032479C(void){
    u8 *self;
    s32 i;

    self = (u8*)malloc(0x10);
    for(i = 0; i < 0x10; i++){
        self[i] = 0xff;
    }
    return self;
}