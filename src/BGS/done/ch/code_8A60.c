#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_802C4140(s32, f32, f32, f32);
void func_802C3F04(Actor (*)(s32, f32, f32, f32), s32, u32, u32, u32);
void timedFuncAdd_0(f32, void (*)(void));


void func_8038EE50(void){
    f32 sp24[3];

    if(func_80304E24(0x14d, sp24)){
        jiggySpawn(jiggy_bgs_elevated_walkway, sp24);
        func_802C3F04(func_802C4140, 0x4C, *((u32 *) &sp24[0]), *((u32 *) &sp24[1]), *((u32 *) &sp24[2]));
    }
}

void func_8038EEA4(Actor *this){
    func_8038EA90();
    if(func_802CACF8(7)){
        func_802CADC0(7, 0);
        if(!func_802CACF8(3) || (func_80345FA0(0) > 0)){
            func_802D68F0(0x2D);
        }
    }
    if(!func_802CACF8(5)){
        func_802D4928(this, 1, 6, 7);
    }
    if(func_802CACF8(2)){
        this->unk2C = 0.0f;
        func_802CADC0(3,0);
        func_802CADC0(4,0);
        func_802CADC0(1,0);
        func_802CADC0(2,0);
    }
    if( this->unk2C == 0.0f && func_802CACF8(1)){
        this->unk2C = 1.0f;
        func_802BAFE4(0xc);
        timedFuncAdd_0(1.2f, func_8038EE50);
    } //L8038EFB4
    if( this->unk2C != 0.0f && !func_802CACF8(3) && func_802BB270()){
        func_802CADC0(3,1);
        func_802D68F0(0x2D);
        func_80346414(6,1);
    } //L8038EFB4
}

void func_8038F018(void){
    f32 sp24[3];

    if(func_80304E24(0x1fc, sp24)){
        jiggySpawn(jiggy_bgs_maze, sp24);
        func_802C3F04(func_802C4140, 0x4C, *((u32 *) &sp24[0]), *((u32 *) &sp24[1]), *((u32 *) &sp24[2]));
    }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/code_8A60/func_8038F06C.s")
void func_8038F06C(Actor *this){
    func_8038EA90();
    if(func_802CACF8(8)){
        func_802CADC0(8, 0);
        if(!func_802CACF8(0xC) || (func_80345FA0(0) > 0)){
            func_802D68F0(0xA);
        }
    }
    if(!func_802CACF8(9)){
        func_802D4928(this, 0xA, 6, 7);
    }
    if(func_802CACF8(0xB)){
        this->unk2C = 0.0f;
        func_802CADC0(0xC,0);
        func_802CADC0(0xD,0);
        func_802CADC0(0xA,0);
        func_802CADC0(0xB,0);
    }
    if( this->unk2C == 0.0f && func_802CACF8(0xA)){
        this->unk2C = 1.0f;
        func_802BAFE4(0x1D);
        timedFuncAdd_0(1.2f, func_8038F018);
    } //L8038EFB4
    if( this->unk2C != 0.0f && !func_802CACF8(0xC) && func_802BB270()){
        func_802CADC0(0xC,1);
        func_802D68F0(0xA);
        func_80346414(6,1);
    } //L8038EFB4
}