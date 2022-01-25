#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_8038C1F8(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038C9A0(Actor *this);

/* .data */
extern ActorAnimationInfo D_80391F50[];

extern ActorInfo D_80391F88 = { 0x200, 0x332, 0x448,
    0x1, D_80391F50,
    func_8038C9A0, func_80326224, func_8038C1F8,
    { 0x0, 0x0}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391FAC = { 0x201, 0x333, 0x449,
    0x1, D_80391F50,
    func_8038C9A0, func_80326224, func_8038C1F8,
    { 0x0, 0x0}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391FD0 = { 0x202, 0x334, 0x44A,
    0x1, D_80391F50,
    func_8038C9A0, func_80326224, func_8038C1F8,
    { 0x0, 0x0}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391FF4 = { 0x203, 0x335, 0x44B,
    0x1, D_80391F50,
    func_8038C9A0, func_80326224, func_8038C1F8,
    { 0x0, 0x0}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern UNK_TYPE(u8) D_80392018;

extern UNK_TYPE(u8) D_8039207C;

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C0B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C1F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C398.s")

void func_8038C428(Actor *this, UNK_TYPE(s32) arg1, f32 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C8F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C94C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C9A0.s")
// void func_8038C9A0(Actor *this){
//     Actor *other; //sp34
//     void * sp30;

//     if(this->marker->unk14_20 == 0x200){
//         sp30 = func_8034C2C4(this->marker, 0x190);
//     }
//     other = marker_getActor(this->unk100);

//     if(!this->unk16C_4){
//         this->unk16C_4 = TRUE;
//         this->marker->unk18 = &D_80392018;
//         this->unk38_31 = 0;
//         if(0.0f != other->velocity[0]){
//             func_80328A84(this, 4);
//             this->unk1C[1] = this->position_y + 50.0f;
//             this->unk1C[2] = this->position_y;
//         }
//         else{
//             this->velocity_x = 0.0f;
//             this->velocity_y = 0.0f;
//             this->velocity_z = 0.0f;
//             this->unk1C[0] = 0.0f;
//             func_8028764C(this->animctrl, 0.0f);
//             func_8038C428(this, &D_8039207C, 0);
//             return;
//         }
//     }//L8038CA9C

//     if(1.0f == other->unk1C[1]){
//         func_8038C398(this->position, this->marker->unk14_20);
//         FUNC_8030E8B4(SFX_7B_ICE_BREAKING_1, 1000, 0x3ff, this->position, 0x6d6, 0xdac);\
//         marker_despawn(this->marker);
//         return;
//     }//L8038CB04

//     switch(this->state){

//     }
// }
