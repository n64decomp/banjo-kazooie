#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern ActorInfo D_80390FD0;

typedef struct {
    u8 pad0[2];
    s16 unk2;
    ActorInfo *unk4;
}ActorLocal_RBB_5060;

void func_8038B654(Actor * this);

/* .data */
ActorInfo D_80390A50 = {
    0x2D, 0x1C5, 0x0, 0x0, NULL,
    func_8038B654, NULL, func_80325340,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

f32 D_80390A74[3]  = {-3820.0f,   850.0f, 0.0f};


/* .code */
void func_8038B450(Actor *actor, s32 arg1){
    actor->state = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_5060/func_8038B468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_5060/func_8038B4A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_5060/func_8038B4C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_5060/func_8038B4F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_5060/func_8038B56C.s")

void func_8038B654(Actor *this){
    ActorLocal_RBB_5060 *local = (ActorLocal_RBB_5060 *)&this->local;

    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        local->unk2 = 1;
        local->unk4 = &D_80390FD0;
        if(jiggyscore_80320F7C(JIGGY_RBB_WHISTLE))
            func_8038B450(this, 2);
        else
            func_8038B450(this, 1);
    }
}