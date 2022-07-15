#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038FC48(Actor *this);

/* typedefs and declarations */
typedef struct {
    s32 unk0;
    s16 *unk4;
    ActorMarker *unk8;
}ActorLocal_RBB_9840;

/* .data */
s16 D_80390E30[2] = {0x177, 0x17F};
ActorInfo D_80390E34 = {
    0x1D2, 0x31B, 0x0, 0x0, NULL,
    func_8038FC48, NULL, func_80325340,
    0, 0, 0.0f, 0
};
ActorInfo D_80390E58 = {
    0x1D3, 0x31C, 0x0, 0x0, NULL,
    func_8038FC48, NULL, func_80325340,
    0, 0, 0.0f, 0
};

/*.code */
void func_8038FC30(Actor *this, s32 arg1){
    this->state = arg1;
}

void func_8038FC48(Actor *this){
    ActorLocal_RBB_9840 *local = (ActorLocal_RBB_9840 *)&this->local;
    f32 sp20;
    f32 tmp_f2;
    s32 tmp_a1;

    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        actor_collisionOff(this);
        local->unk4 = D_80390E30 + (this->marker->unk14_20 - 0x1d2);
        local->unk8 = NULL;
        
        local->unk0 = func_802F9AA8(0x400);
        func_802F9DB8(local->unk0, 1.0f, 1.0f, 0.0f);
        func_802F9EC4(local->unk0, &this->position, 0x1f4, 0x3e8);
        func_802F9F80(local->unk0, 0.0f, 8999999488.0f, 0.0f);
        func_802FA060(local->unk0, 22000, 22000, 0.0f);
        func_8038FC30(this, 1);
    }
    else{//L8038FD34
        if(local->unk8 == NULL)
            local->unk8 = func_80326EEC(*local->unk4)->marker;
        sp20 = func_8038A6B8(local->unk8);
        tmp_f2 = 1.5* sp20 + 0.5;
        func_802F9DB8(local->unk0, tmp_f2, tmp_f2, 0.0f);
        tmp_a1 = (s32) (sp20*32000.0f);
        func_802FA060(local->unk0, tmp_a1, tmp_a1, 0.0f);
    }
}
