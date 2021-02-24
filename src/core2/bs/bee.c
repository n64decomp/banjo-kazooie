#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80293D48(f32, f32);

void func_80297FB0(f32, f32);

void func_80298CE0(f32);
void func_80298D54(f32, f32);

s32 func_802A03C4(s32 move_idx);

void func_802A02C0(void){
    if(func_802A03C4(func_8029A7D4()) == 0){
        player_setIdealPitch(0.0f); //player_setIdealPitch
        func_80298CE0(0.0f);
        func_8029B0C0();
        func_8029E070(0);
        func_8029E064(0);
        func_802933FC(3);
        func_802933FC(4);
        func_80293D74();
    }
    func_80289F10(1);
}

void func_802A0340(void){
    if(func_802A03C4(func_8029A7BC()) == 0){
        func_80297FB0(1000.0f, 12.0f);
        func_80298D54(1000.0f, 12.0f);
        func_80293D48(50.0f, 25.0f);
        func_802933E8(3);
        func_802933E8(4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bee/func_802A03C4.s")
// bsBee_inSet
// s32 func_802A03C4(s32 move_idx){
//     s32 out = (move_idx == 0x85) 
//     || (move_idx == 0x86) 
//     || (move_idx == 0x87)
//     || (move_idx == 0x88)
//     || (move_idx == 0x89)
//     || (move_idx == 0x8a)
//     || (move_idx == 0x8b)
//     || (move_idx == 0x9d)
//     || (move_idx == 0x6b)
//     || bsBeeFly_inSet(move_idx); //bsBeeFly_inSet
//     return out;
// }


void func_802A0478(void){
    func_802A0340();
    func_802AE3D0();
}

void func_802A04A0(void){
    func_802AE410();
}

void func_802A04C0(void){
    func_802AE450();
    func_802A02C0();
}