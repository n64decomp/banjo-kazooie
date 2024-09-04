#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/timedfunc.h"

void ncStaticCamera_exit(void);
void ncStaticCamera_setToNode(s32);

typedef struct timed_function_queue_s{
    f32 time;
    u8  arg_cnt;
    u8  pad5[3];
    union {
        GenFunction_0 func0;
        GenFunction_1 func1;
        GenFunction_2 func2;
        GenFunction_3 func3;
        GenFunction_4 func4;
        GenFunction_5 func5;
        GenFunction_6 func6;
    };
    s32  arg[25];
    
}TimedFunction;

typedef struct tfq_struct_2_s{
    u32 unk0;
    f32 unk4;
    u32 unk8;
    f32 unkC[3];
    f32 unk18;
    f32 unk1C;
}timefuncqueue_Struct2;

typedef struct timed_func_array_s{
    VLA *ptr;
    f32 time;
}TimedFunctionArray;

typedef struct delayed_jiggy_s{
    u32 id;
    f32 pos[3];
} DelayedJiggyInfo;

typedef struct {
    enum asset_e text_id;
    s32 unk4;
    f32 position[3];
    ActorMarker *caller;
    void (*callback_method_1)(ActorMarker *, enum asset_e, s32);
    void (*callback_method_2)(ActorMarker *, enum asset_e, s32);
}DelayedTextCallback;

//void __spawnjiggy(DelayedJiggyInfo *);
TimedFunction* __timedFuncQueue_insert(f32, s32, void *funcPtr, s32, s32, s32, s32, s32);
void func_80324BA0(s32);

void func_802BE720(void);

/* .bss */
TimedFunctionArray D_80383380;

/* .code */
TimedFunction* __timedFuncQueue_insert(f32 time, s32 cnt, void *funcPtr, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4){
    TimedFunction * startPtr;
    TimedFunction *retVal;
    TimedFunction * iPtr;
    TimedFunction * endPtr;

    startPtr = (TimedFunction * )vector_getBegin(D_80383380.ptr);
    endPtr = (TimedFunction * )vector_getEnd(D_80383380.ptr);
    if(endPtr == startPtr){
        D_80383380.time = 0.0f; 
    }
    else{
        time += D_80383380.time;
    }
    for(iPtr = startPtr; iPtr < endPtr; iPtr++){
        if(iPtr->time > time)
            break;
    }
    retVal = (TimedFunction * )vector_insertNew((vector(TimedFunction)**)&D_80383380, ((s32)iPtr - (s32)startPtr)/(s32)sizeof(TimedFunction));
    retVal->time = time;
    retVal->arg_cnt = cnt;
    retVal->func5 = (GenFunction_5) funcPtr;
    retVal->arg[0] = arg0;
    retVal->arg[1] = arg1;
    retVal->arg[2] = arg2;
    retVal->arg[3] = arg3;
    retVal->arg[4] = arg4;
    return retVal;
}

void __timedFunc_execute(TimedFunction *arg0){
    if(arg0->arg_cnt == 0)
        arg0->func0();
    else if(arg0->arg_cnt == 1)
        arg0->func1(arg0->arg[0]);
    else if(arg0->arg_cnt == 2)
        arg0->func2(arg0->arg[0], arg0->arg[1]);
    else if(arg0->arg_cnt == 3)
        arg0->func3(arg0->arg[0], arg0->arg[1], arg0->arg[2]);
    else if(arg0->arg_cnt == 4)
        arg0->func4(arg0->arg[0], arg0->arg[1], arg0->arg[2], arg0->arg[3]);
    else if(arg0->arg_cnt == 5)
        arg0->func5(arg0->arg[0], arg0->arg[1], arg0->arg[2], arg0->arg[3], arg0->arg[4]);
    else if(arg0->arg_cnt == 6)
        arg0->func6(&arg0->arg[5]);
}

void func_80324A28(s32 soundId, s32 volume){
    func_8025A6EC(soundId, volume);
}

void func_80324A48(enum comusic_e arg0){
    func_8025A7DC(arg0);
}

void func_80324A68(enum sfx_e arg0, s32 arg1, s32 arg2){
    func_8030E760(arg0, arg1/1000.0f, arg2);
}

void func_80324AA4(timefuncqueue_Struct2 *arg0){
    func_8030E9C4(arg0->unk0, arg0->unk4, arg0->unk8, arg0->unkC, arg0->unk18, arg0->unk1C);
}

void func_80324AEC(DelayedTextCallback *arg0) {
    if ((arg0->position[0] == 0.0f) && (arg0->position[1] == 0.0f) && (arg0->position[2] == 0.0f)) {
        func_80311480(arg0->text_id, arg0->unk4, NULL, arg0->caller, arg0->callback_method_1, arg0->callback_method_2);
    }
    else{
        func_80311480(arg0->text_id, arg0->unk4, arg0->position, arg0->caller, arg0->callback_method_1, arg0->callback_method_2);
    }
}

void func_80324BA0(s32 arg0){
    if(arg0 == 1)
        func_8028F918(1);
    else if(arg0 == 2)
        func_8028F918(3);
    else if(arg0 == 3)
        func_8028F918(2);
    else{ 
        if(arg0 == 0)
            func_8028F918(0);
        else if (arg0 == 4)
            func_802D6114();
    }
}

void __spawnjiggy(DelayedJiggyInfo *jigInfo){
    jiggy_spawn(jigInfo->id, jigInfo->pos);
}

void func_80324C58(void){
    vector_clear(D_80383380.ptr);
}

f32 func_80324C7C(void){
    return D_80383380.time;
}

void timed_playSfx(f32 time, enum sfx_e arg0, f32 arg1, s32 arg2){
    timedFunc_set_3(time, (GenFunction_3)func_80324A68, arg0, (s32)(arg1*1000.0f), arg2);
}

void func_80324CD8(f32 time){
    timedFunc_set_0(time, func_802BE720);
}

void func_80324CFC(f32 time, s32 id, s32 volume){
    timedFunc_set_2(time, (GenFunction_2)func_80324A28, id, volume);
}

void func_80324D2C(f32 time, enum comusic_e arg0){
    timedFunc_set_1(time, (GenFunction_1) func_80324A48, arg0);
}

void func_80324D54(f32 time, enum sfx_e sfx_id, f32 arg2, s32 arg3, f32 position[3], f32 arg5, f32 arg6){
    timefuncqueue_Struct2 argStruct;
    argStruct.unk0 = sfx_id;
    argStruct.unk4 = arg2;
    argStruct.unk8 = arg3;
    argStruct.unk18 = arg5;
    argStruct.unk1C = arg6;
    argStruct.unkC[0] = position[0];
    argStruct.unkC[1] = position[1];
    argStruct.unkC[2] = position[2];
    
    timedFunc_set_6(time, (GenFunction_6) func_80324AA4, (void *) &argStruct);
}

void func_80324DBC(f32 time, enum asset_e text_id, s32 arg2, f32 position[3], ActorMarker *caller, void (*callback_method_1)(ActorMarker *, enum asset_e, s32), void (*callback_method_2)(ActorMarker *, enum asset_e, s32)) {
    DelayedTextCallback sp20;
    s32 pad;

    sp20.text_id = text_id;
    sp20.unk4 = arg2;
    sp20.caller = caller;
    sp20.callback_method_1 = callback_method_1;
    sp20.callback_method_2 = callback_method_2;
    if (position != NULL) {
        sp20.position[0] = position[0];
        sp20.position[1] = position[1];
        sp20.position[2] = position[2];
    } else {
        sp20.position[0] = sp20.position[1] = sp20.position[2] = 0.0f;
    }
    timedFunc_set_6(time, (GenFunction_6) func_80324AEC, (void *) &sp20);
}


void func_80324E38(f32 time, s32 arg0){
    timedFunc_set_1(time, (GenFunction_1) func_80324BA0, arg0);
}

void timed_setStaticCameraToNode(f32 time, s32 arg0){
    timedFunc_set_1(time, (GenFunction_1) ncStaticCamera_setToNode, arg0);
}

void timed_exitStaticCamera(f32 time){
    timedFunc_set_0(time, (GenFunction_0) ncStaticCamera_exit);
}

void timedFunc_set_0(f32 time, GenFunction_0 funcPtr){
    __timedFuncQueue_insert(time, 0, (void *) funcPtr, 0, 0, 0, 0, 0);
}

void timedFunc_set_1(f32 time, GenFunction_1 funcPtr, s32 arg0){
    __timedFuncQueue_insert(time, 1, (void *) funcPtr, arg0, 0, 0, 0, 0);
}

void timedFunc_set_2(f32 time, GenFunction_2 funcPtr, s32 arg0, s32 arg1){
    __timedFuncQueue_insert(time, 2, (void *) funcPtr, arg0, arg1, 0, 0, 0);
}

void timedFunc_set_3(f32 time, GenFunction_3 funcPtr, s32 arg0, s32 arg1, s32 arg2){
    __timedFuncQueue_insert(time, 3, (void *) funcPtr, arg0, arg1, arg2, 0, 0);
}

void timedFunc_set_4(f32 time, GenFunction_4 funcPtr, s32 arg0, s32 arg1, s32 arg2, s32 arg3){
    __timedFuncQueue_insert(time, 4, (void *) funcPtr, arg0, arg1, arg2, arg3, 0);
}

void timedFunc_set_5(f32 time, GenFunction_5 funcPtr, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4){
    __timedFuncQueue_insert(time, 5, (void *) funcPtr, arg0, arg1, arg2, arg3, arg4);
}

void timedFunc_set_6(f32 time, GenFunction_6 funcPtr, void* argPtr ){
    TimedFunction *q = __timedFuncQueue_insert(time, 6, funcPtr, 0, 0, 0, 0, 0);
    memcpy(&q->arg[5], argPtr, 0x50);
}

//timedJiggySpawn
void timedJiggySpawn(f32 time, s32 jiggyId, f32 *position){
    DelayedJiggyInfo jiggyInfo;
    jiggyInfo.id = jiggyId;
    jiggyInfo.pos[0] = position[0];
    jiggyInfo.pos[1] = position[1];
    jiggyInfo.pos[2] = position[2];

    timedFunc_set_6(time, (GenFunction_6) __spawnjiggy, (void*) &jiggyInfo);
}

bool timedFuncQueue_is_empty(void){
    return !vector_size(D_80383380.ptr);
}

/* 
 * Executes all the functions in the timed
 * function queue and clears the queue
 */
void timedFuncQueue_flush(void){
    TimedFunction *iPtr;
    TimedFunction iFunc;

    while(vector_size(D_80383380.ptr) > 0){
        iPtr = vector_getBegin(D_80383380.ptr);
        memcpy(&iFunc, iPtr, sizeof(TimedFunction));
        vector_remove(D_80383380.ptr, 0);
        __timedFunc_execute(&iFunc);
    }
}

void timedFuncQueue_free(void){
    vector_free(D_80383380.ptr);
}

void timedFuncQueue_init(void){
    D_80383380.ptr = vector_new(0x70, 0x10);
    D_80383380.time = 0.0f;
}

/* 
 * Executed any methods in timed function queue
 * ready to be executed.
 */
void timedFuncQueue_update(void){
    TimedFunction *iPtr;
    TimedFunction iFunc;

    if(vector_size(D_80383380.ptr) == 0)
        return;

    D_80383380.time += time_getDelta();

    while(vector_size(D_80383380.ptr) > 0){
        iPtr = vector_getBegin(D_80383380.ptr);
        if(D_80383380.time < iPtr->time)
            break;
        memcpy(&iFunc, iPtr, sizeof(TimedFunction));
        vector_remove(D_80383380.ptr, 0);
        __timedFunc_execute(&iFunc);
    }
}

void timedFuncQueue_defrag(void){
    D_80383380.ptr = vector_defrag(D_80383380.ptr);
}

void func_803252B0(s32 arg0){
    mapSpecificFlags_set(arg0, 1);
}

void func_803252D0(f32 time, s32 arg0){
    timedFunc_set_1(time, func_803252B0, arg0);
}
