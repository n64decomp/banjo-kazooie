#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void actor_collisionOff(Actor *);
void func_80353064(f32 *, f32);


#pragma GLOBAL_ASM("asm/nonmatchings/MM/code_570/func_80386960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MM/code_570/func_803869EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MM/code_570/func_80386A2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MM/code_570/func_80386C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MM/code_570/func_80386CA0.s")

void func_80386D84(Actor *this){
    if(!this->unkF4_21){
        actor_collisionOff(this);
        this->unkF4_21 = 1;
        this->unk28 = this->position_y;
        this->position_y -= 134.0f;
        this->marker->propPtr->unk8_3 = 1;
    }
    switch (this->unk10_31)
    {
    case 1:
        if(mapSpecificFlags_get(0))
            func_80328A84(this, 2);

        func_80386CA0(this);
        break;
    case 2:
        func_80386CA0(this);
        this->position_y += 2.5;
        if(this->unk28 <= this->position_y){
            this->position_y = this->unk28;
            func_80328A84(this, 3);
            func_802BB41C(1);
            func_80244C78(0);
        }
        if((func_8023DB5C() & 3) == 2)
            func_80353064(&this->position_x, 40.0f);
        break;
    case 3:
        break;
    }
}