#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    s32 unk0;
    f32 unk4[3];
}ActorLocal_RBB_36A0;

void func_80389C78(Actor *this);

/* .data */
ActorInfo D_803906E0 = {
    0x185, 0x175, 0x403, 0x0, NULL,
    func_80389C78, NULL, func_80325888,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

s32 D_80390704[4] = {0x258, 0x12C, 0x12C, 0};


/*.code */
f32 func_80389A90(void){
    return (f32) D_80390704[2*levelSpecificFlags_get(0x27) + levelSpecificFlags_get(0x28)];
}

void func_80389ADC(Actor *this, s32 arg1){
    ActorLocal_RBB_36A0 * local = (ActorLocal_RBB_36A0 *)&this->local;
    if(arg1 == 1){
        local->unk4[2] = func_80389A90();
        local->unk4[0] = func_80389A90();
    }
    this->unk10_31 = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_36A0/func_80389B44.s")

void func_80389B80(Actor *this, f32 arg1){
    ActorLocal_RBB_36A0 * local = (ActorLocal_RBB_36A0 *)&this->local;
    local->unk0 = func_802F9AA8(0x400);
    func_802F9DB8(local->unk0, arg1, arg1, 0.0f);
    func_802F9F80(local->unk0, 0.0f, 8999999488.0f, 0.0f);
    func_802FA060(local->unk0, 0x4650, 0x4650, 0.0f);
    if(!levelSpecificFlags_get(3) && !levelSpecificFlags_get(4)){
        func_802F9EC4(local->unk0, &this->position, 0x1f4, 0x7d0);
        func_802FA0B0(local->unk0, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_36A0/func_80389C44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_36A0/func_80389C78.s")
