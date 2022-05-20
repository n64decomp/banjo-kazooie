#include <ultra64.h>
#include "functions.h"
#include "variables.h"


bool func_802ED420(BKModelUnk20List *arg0, u8 *arg1, u32 arg2) {
    BKModelUnk20_0 *start_ptr;

    start_ptr = (BKModelUnk20_0 *)(arg0 + 1);
    while(arg2 != 0){
        if (start_ptr[*arg1].unkC != 0) {
            return TRUE;
        }
        arg2--; 
        arg1++;
    }
    return FALSE;
}

void func_802ED52C(BKModelUnk20List *arg0, f32 arg1[3], f32 arg2) {
    BKModelUnk20_0 *start_ptr;
    BKModelUnk20_0 *end_ptr;
    BKModelUnk20_0 *i_ptr;
    s32 i;
    s16 sp18[3];

    start_ptr = ( BKModelUnk20_0 *)(arg0 + 1);
    sp18[0] = (s16) (arg1[0] * (1.0 / arg2));
    sp18[1] = (s16) (arg1[1] * (1.0 / arg2));
    sp18[2] = (s16) (arg1[2] * (1.0 / arg2));
    end_ptr = start_ptr + arg0->unk0;
    for(i_ptr = start_ptr; i_ptr < end_ptr; i_ptr++){
        for(i = 0; i < 3; i++){
            if ((sp18[i] < i_ptr->unk0[i]) || (i_ptr->unk6[i] < sp18[i])) {
               break;
            }
        }
        i_ptr->unkC = (i == 3);
    }
}
