#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct struct_23_s{
    u16 unk0;
    s8 unk2;
    s8 unk3;
}struct23s;

typedef struct demo_input{
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u8 unk4;
    u8 unk5;
}DemoInput;

typedef struct demo_file_header{
    u8 pad0[0x4];
    DemoInput inputs[];
} DemoFileHeader;



void demo_free(void);

DemoInput D_80371EF0 = {0, 0, 0, 2, 0};

/* .bss */
DemoInput *D_803860D0; //demo_input_ptr
DemoFileHeader * D_803860D4; //demo_file_ptr
s32 D_803860D8;//current_input
s32 D_803860DC;//total_inputs

/* .code */
s32 func_80349EC0(s32 arg0){
    s32 sp1C[3];

    return nodeprop_findPositionFromActorId(arg0 + 0x1CC, &sp1C);
}

int demo_readInput(OSContPad* arg0, s32* arg1){
    DemoInput *input_ptr = &D_803860D0[D_803860D8++];
    int not_eof = D_803860D8 < D_803860DC;

    if(!not_eof)
        input_ptr = &D_80371EF0;

    arg0->stick_x = input_ptr->unk0;
    arg0->stick_y = input_ptr->unk1;
    arg0->button = input_ptr->unk2;
    *arg1 = input_ptr->unk4;

    return not_eof;
}

int demo_writeInput(OSContPad* arg0, s32* arg1){
    DemoInput *input_ptr = D_803860D0 + D_803860D8;
    input_ptr->unk0 = arg0->stick_x;
    input_ptr->unk1 = arg0->stick_y;
    input_ptr->unk2 = arg0->button;
    input_ptr->unk4 = *arg1;
    D_803860D8++;
    return D_803860D8 < D_803860DC;
}

void func_80349FB0(DemoInput *input_ptr, u32 size, int arg2){
    D_803860D0 = input_ptr;
    D_803860DC = size/sizeof(DemoInput);
    D_803860D8 = 0;
    if(input_ptr);

    func_8030AFD8(0);
    func_80321854();
    debugScoreStates();
    clearScoreStates();
    func_803216D0(map_get());
    func_8030AFA0(map_get());
    volatileFlag_set(VOLATILE_FLAG_C4_WOZZA_HIDE_IN_SNS_PARADE, 1);
    func_8024F224();
    rand_reset();
    globalTimer_reset();
}//*/

/* returns offset of current input */
u32 func_8034A054(void){
    return D_803860D8*sizeof(DemoInput);
}

void demo_load(enum map_e map, s32 demo_id){
    if(D_803860D4)
        demo_free();
    D_803860D4 = assetcache_get(0x504 + map_getLevel(map) + demo_id*0xD);
    func_80349FB0(D_803860D4->inputs, func_8033B678() - sizeof(DemoFileHeader), 0);
}

void demo_free(void){
    if(D_803860D4){
        assetcache_release(D_803860D4);
        D_803860D4 = NULL;
    }
}
