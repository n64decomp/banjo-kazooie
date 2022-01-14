#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8 pad0[0x8];
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 padB[0x1];
    u8 unkC;
}ActorLocal_Skeleton;

void chskeleton_update(Actor *this);

/* .data */
extern ActorAnimationInfo D_80372D20[];
extern ActorInfo D_80372D78 = { 
    0x218, 0x34E, 0x4CC, 
    0x1, D_80372D20, 
    chskeleton_update, func_80326224, func_80325888, 
    { 0x9, 0xC4}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D5D10/func_8035CCA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D5D10/func_8035CD80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D5D10/func_8035CE50.s")

void chskeleton_update(Actor *this){
    if(!this->unk16C_4){
        func_8035CE50(this);
    }
    func_802DB5A0(this);
}
