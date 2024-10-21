#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void rumbleManager_80250E6C(f32, f32);
extern void func_802BB360(s32, f32);
extern void func_802BB378(s32, f32, f32);
extern void func_802BB3AC(s32, f32);
extern void func_8031B908(s32, s32, s32, f32);


/* .bss */
s32 s_activationFrameDelay;

/* .code */
void __anSeq_func_802888C0(s32 arg0, s32 arg1)
{
  u8 sp1C[3];
  f32 f0;
  sp1C[0] = (arg0 >> 16) & 0xFF;
  sp1C[1] = (arg0 >> 8) & 0xFF;
  sp1C[2] = (arg0 >> 0) & 0xFF;
  f0 = reinterpret_cast(f32, arg1);
  func_8031B908(sp1C[0], sp1C[1], sp1C[2], f0);
}

void __anSeq_func_80288914(s32 arg0, s32 arg1, s32 arg2){
    f32 f0 = reinterpret_cast(f32, arg1);
    f32 f2 = reinterpret_cast(f32, arg2);
    func_802BB378(arg0, f0, f2);
}

void __anSeq_func_8028894C(s32 arg0, s32 arg1, s32 arg2){
    f32 f0 = reinterpret_cast(f32, arg1);
    f32 f2 = reinterpret_cast(f32, arg2);
    func_802BB3DC(arg0, f0, f2);
}

void __anSeq_func_8028984(s32 arg0, s32 arg1){
    f32 f0 = reinterpret_cast(f32, arg1);
    func_802BB360(arg0, f0);
    func_802BB3AC(arg0, 1.0f);
    func_802BB3C4(arg0);
}

void __anSeq_func_80289C8(s32 arg0, s32 arg1){
    f32 f0 = reinterpret_cast(f32, arg1);
    func_802BB3AC(arg0, f0);
}

void __anSeq_func_80289F4(s32 arg0) {
    s32 sp18;
    s32 temp_t6;
    s32 phi_a3;

    phi_a3 = arg0 >> 0x10;
    if( !(phi_a3 == 0xF2 && map_get() == MAP_91_FILE_SELECT && func_802C5A30() != 0) 
        && !((phi_a3 == 0x21 || phi_a3 == 0x3ED) && map_get() == MAP_91_FILE_SELECT && (func_802C5A30() == 1))
    ){
        func_8030E6A4(phi_a3, (f32) ((f64) ((arg0 >> 8) & 0xFF) * 0.0078125), (s32) ((f64) (arg0 & 0xFF) * 128.0));
    }
}


void __anSeq_func_8028AE0(s32 arg0){
    func_8025A6EC((u16) (arg0 >> 16), (u16)arg0 - 1);
}

void __anSeq_func_8028B14(enum sfx_e arg0){
    func_8025A7DC(arg0);
}

void __anSeq_func_80288B34(s32 arg0, s32 arg1){
    f32 f12 = reinterpret_cast(f32, arg0);
    f32 f14 = reinterpret_cast(f32, arg1);
    rumbleManager_80250E6C(f12, f14);
}

void __anSeq_func_80288B60(s32 arg0, s32 arg1, s32 arg2){
    f32 f12 = reinterpret_cast(f32, arg0);
    f32 f14 = reinterpret_cast(f32, arg1);
    f32 f0 = reinterpret_cast(f32, arg2);
    rumbleManager_80250D94(f12, f14, f0);
}

void __anSeq_updateStep(vector(AnSeqElement) **ppAnSeq, AnSeqElement *pStep){
    if(pStep->activationFrameDelay){
        if(pStep->activationFrameDelay == 0xFF)
            return;

        pStep->activationFrameDelay -= 1;
        if(pStep->activationFrameDelay)
            return;

        pStep->activationFrameDelay = 0xFF;
    }

     switch(pStep->argCount){
        case 0:// 80288BF8
            ((void (*)(void)) pStep->funcPtr)();
            break;
        case 1:// 80288C0C
            ((void (*)(s32)) pStep->funcPtr)(pStep->arg0);
            break;
        case 2:// 80288C24
            ((void (*)(s32, s32)) pStep->funcPtr)(pStep->arg0, pStep->arg1);
            break;
        case 3:// 80288C40
            ((void (*)(s32, s32, s32)) pStep->funcPtr)(pStep->arg0, pStep->arg1, pStep->arg2);
            break;
        case 4:// 80288C5C
            ((void (*)(void*)) pStep->funcPtr)(&pStep->arg0);
            break;
     }
}

void anSeq_clear(vector(AnSeqElement) **ppAnSeq){
    vector_clear(*ppAnSeq);
}

AnSeqElement * __anSeq_pushStep( vector(AnSeqElement) **ppAnSeq, f32 duration, s32 arg_cnt, void *funcPtr, s32 arg0, s32 arg1, s32 arg2){
    AnSeqElement *ptr = (AnSeqElement *) vector_pushBackNew(ppAnSeq);
    ptr->duration = duration;
    ptr->argCount = arg_cnt;
    ptr->funcPtr = funcPtr;
    ptr->arg0 = arg0;
    ptr->arg1 = arg1;
    ptr->arg2 = arg2;
    ptr->activationFrameDelay = s_activationFrameDelay;
    s_activationFrameDelay = 0;
    return ptr;
}

void anSeq_PushStep_0Arg(vector(AnSeqElement) **ppAnSeq, f32 duration, void *func_ptr){
    __anSeq_pushStep(ppAnSeq, duration, 0, func_ptr, 0, 0, 0);
}

void anSeq_PushStep_1Arg(vector(AnSeqElement) **ppAnSeq, f32 duration, void *func_ptr, s32 arg0){
    __anSeq_pushStep(ppAnSeq, duration, 1, func_ptr, arg0, 0, 0);
}

void anSeq_PushStep_2Arg(vector(AnSeqElement) **ppAnSeq, f32 duration, void *func_ptr, s32 arg0, s32 arg4){
    __anSeq_pushStep(ppAnSeq, duration, 2, func_ptr, arg0, arg4, 0);
}

void anSeq_PushStep_3Arg(vector(AnSeqElement) **ppAnSeq, f32 duration, void *func_ptr, s32 arg0, s32 arg4, s32 arg5){
    __anSeq_pushStep(ppAnSeq, duration, 3, func_ptr, arg0, arg4, arg5);
}

void anSeq_PushStep_ManyArg(vector(AnSeqElement) **ppAnSeq, f32 duration, void *func_ptr, void* arg_ptr, s32 arg_size){
    AnSeqElement *out = __anSeq_pushStep(ppAnSeq, duration, 4, func_ptr, 0, 0, 0);
    memcpy(&out->arg0, arg_ptr, arg_size);
}

void anSeq_func_80288E68(vector(AnSeqElement) **ppAnSeq, f32 duration, s32 arg2, s32 arg3, s32 arg4){
    anSeq_PushStep_3Arg(ppAnSeq, duration, __anSeq_func_80288914, arg2, arg3, arg4);
}

void anSeq_func_80288EB0(vector(AnSeqElement) **ppAnSeq, f32 duration, s32 arg2, s32 arg3, s32 arg4){
    anSeq_PushStep_3Arg(ppAnSeq, duration, __anSeq_func_8028894C, arg2, arg3, arg4);
}

void anSeq_func_80288EF8(vector(AnSeqElement) **ppAnSeq, f32 duration, s32 arg2, s32 arg3){
    anSeq_PushStep_2Arg(ppAnSeq, duration, __anSeq_func_8028984, arg2, arg3);
}

void anSeq_func_80288F38(vector(AnSeqElement) **ppAnSeq, f32 duration, s32 arg2, s32 arg3){
    anSeq_PushStep_2Arg(ppAnSeq, duration, __anSeq_func_80289C8, arg2, arg3);
}

void anSeq_func_80288F78(vector(AnSeqElement) **ppAnSeq, f32 duration, s32 arg2){
    anSeq_PushStep_1Arg(ppAnSeq, duration, __anSeq_func_80289F4, arg2);
}

void anSeq_func_80288FA8(vector(AnSeqElement) **ppAnSeq, f32 duration, enum sfx_e sfx_id){
    anSeq_PushStep_1Arg(ppAnSeq, duration, __anSeq_func_8028B14, sfx_id);
}

void anSeq_func_80288FD8(vector(AnSeqElement) **ppAnSeq, f32 duration, s32 arg2){
    anSeq_PushStep_1Arg(ppAnSeq, duration, __anSeq_func_8028AE0, arg2);
}

void anSeq_func_80289008(vector(AnSeqElement) **ppAnSeq, f32 duration, s32 arg2, s32 arg3){
    do{
        anSeq_PushStep_2Arg(ppAnSeq, duration, __anSeq_func_80288B34, arg2, arg3);
    }while(0);
}

void anSeq_func_80289048(vector(AnSeqElement) **ppAnSeq, f32 duration, s32 arg2, s32 arg3, s32 arg4){
    do{
        anSeq_PushStep_3Arg(ppAnSeq, duration, __anSeq_func_80288B60, arg2, arg3, arg4);
    }while(0);
}

void anSeq_func_80289090(vector(AnSeqElement) **ppAnSeq, f32 duration, s32 arg2, f32 arg3){
    anSeq_PushStep_2Arg(ppAnSeq, duration, __anSeq_func_802888C0, arg2, reinterpret_cast(s32, arg3));
}

void anSeq_free(vector(AnSeqElement)** ppAnSeq){
    vector_free(*ppAnSeq);
    free(ppAnSeq);
}

vector(AnSeqElement) **anSeq_new(void){
    vector(AnSeqElement) **ptr = (vector(AnSeqElement) **)malloc(sizeof(vector(AnSeqElement) **));
    *ptr = vector_new(sizeof(AnSeqElement), 2);
    anSeq_clear(ptr);
    return ptr;
}


void anSeq_setActivationFrameDelay(vector(AnSeqElement) **ppAnSeq, s32 arg1){
    s_activationFrameDelay = arg1;
}

void anSeq_update(vector(AnSeqElement) **ppAnSeq, AnimCtrl *pAnCtl){
    AnSeqElement *iPtr;
    for(iPtr = vector_getBegin(*ppAnSeq); iPtr != (AnSeqElement*)vector_getEnd(*ppAnSeq); iPtr++){
        if(animctrl_isAt(pAnCtl, iPtr->duration))
            __anSeq_updateStep(ppAnSeq, iPtr);
    }
}
