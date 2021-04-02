#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_80386FE0(Actor *this){
    if(!this->unk16C_4){
        this->unk10_14 = 0;
        this->unk38_31 = this->unk10_14;
        this->unk16C_4 = 1;
        actor_collisionOff(this);
    }

    switch(this->unk10_31){
        case 1://L80387064
            if(this->unk38_31++ == 2){
                this->unk10_14 = func_80326F58(0x16f);
                func_80328A84(this, 2);
            }
            break;
        case 2://L803870C4
            if(this->unk10_14 == 0)
                func_803282F4(this->marker);
            break;
    }//L803870DC
}

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_BF0/func_803870E8.s")
