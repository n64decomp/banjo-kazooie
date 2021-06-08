#include <ultra64.h>
#include "functions.h"
#include "variables.h"

//D_80390AB0
// 0000 A690: 00 2F 01 C7 04 1B 00 00  00 00 00 00 80 38 B7 E8  ./...... .....8..  
// 0000 A6A0: 00 00 00 00 80 32 58 88  00 00 00 00 00 00 00 00  .....2X. ........  
// 0000 A6B0: 00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  ........ ........  

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_52F0/func_8038B6E0.s")

void func_8038B7BC(ActorMarker *marker, s32 arg1);
#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_52F0/func_8038B7BC.s")

void func_8038B7E8(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        this->marker->propPtr->unk8_3 = 1;
        func_803300A8(this->marker, NULL, func_8038B7BC, NULL);
        if(jiggyscore_80320F7C(JIGGY_RBB_SNORKEL))
            func_8038B6E0(this, 2);
        else
            func_8038B6E0(this, 1);
    }
}