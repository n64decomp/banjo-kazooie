#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_62FD0/func_802E9F60.s")

struct20s * func_802E9F9C(struct1Fs *arg0, s32 arg1){
    s32 i;
    struct20s *v1 = arg0->unk2;

    for(i=0; i < arg0->unk0; i++){
        if(v1->uid == arg1){
            return v1;
        }
        v1 = &v1->data[v1->count];
    }
    return 0;
}

int func_802E9FEC(struct1Fs * arg0, s32 arg1, void *arg2){
    s32 i;
    struct20s *v0 = func_802E9F9C(arg0, arg1);

    if(v0){
        for(i = 0; i < v0->count; i++){
            if(v0->data[i] == *(s16 *)arg2){
                return 1;
            }
        }
    }
    return 0;
}
