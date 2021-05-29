#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80258A4C(f32 *, f32, f32 *, f32 *, f32 *, f32 *);
f32 func_80309724(f32 *);
void func_80324D54(f32, u32, f32, u32, f32 *, f32, f32);


extern f32 D_80390DD0;
extern f32 D_80390DD4;
extern f32 D_80390DD8;
extern f32 D_80390DDC;
extern f32 D_80390DE0;
extern f32 D_80390DE4;
extern f32 D_80390DE8;
extern f64 D_80390DF0;
extern f64 D_80390DF8;


#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/flibbit/func_803863F0.s")
// u32 func_803863F0(Actor *this, f32 * arg1, u32 arg2){

//     this->flibbit.unk1 = arg2;

//     //wrong registers in this bit
//     this->flibbit.unk2[2] = this->position_z;
//     this->flibbit.unk2[1] = this->position_y;
//     this->flibbit.unk2[0] = this->position_x;
//     this->flibbit.unk8[0] = arg1[0];
//     this->flibbit.unk8[1] = arg1[1];
//     this->flibbit.unk8[2] = arg1[2];

//     this->flibbit.unk8[1] = func_80309724(arg1);
//     func_80335924(this->unk148, 0xdb, 0.2f,(arg2) ?  randf2(D_80390DD0, D_80390DD4) :  randf2(0.75f, D_80390DD8));
//     func_80335A8C(this->unk148, 2);
//     func_80324D54(D_80390DE4, 0x3f2, randf2(D_80390DDC, D_80390DE0), randi2(0x61A8, 0x6978), this->position, 500.0f, D_80390DE8);
//     return 1;
// }


u32 func_80386564(Actor *this){
    f32 plyrPos[3]; //sp54
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C[3]; //sp3C
    f32 sp30[3]; //sp30

    player_getPosition(&plyrPos);
    func_80258A4C(this->position, this->yaw - 90.0f, plyrPos, &sp48, &sp44, &sp40);
    if(func_80329210(this, plyrPos)){
        if((D_80390DF0 <= sp40) && (sp40 <= D_80390DF8)){
            sp3C[0] = plyrPos[0] - this->position_x;
            sp3C[1] = plyrPos[1] - this->position_y;
            sp3C[2] = plyrPos[2] - this->position_z;
            ml_vec3f_set_length(sp3C,180.0f);
            sp30[0] = sp3C[0] + this->position_x;
            sp30[1] = sp3C[1] + this->position_y;
            sp30[2] = sp3C[2] + this->position_z;
            if(func_80329210(this, sp30))
                return func_803863F0(this, sp30, 1);
        }
    }
    return 0;

}

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/flibbit/func_803866A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/flibbit/func_8038686C.s")

u32 func_80386A34(Actor * this){
    f32 plyrPos[3];
    u32 out;

    if(func_803203FC(0xC1))
        return 0;
    
    player_getPosition(&plyrPos);
    if(func_80329210(this, plyrPos)){
        if(!(out = func_80386564(this)) && (0.5 < randf ())){
            return 0;
        }
    }else{
        out = func_803866A4(this);
    }

    if(!out)
        out = func_8038686C(this);
    
    return out;
}

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/flibbit/func_80386AEC.s")

void func_80386E30(ActorMarker *this, u32 arg1){
    Actor *thisActor = marker_getActor(this);
    if(thisActor->unk10_31 < 6){
        func_80386AEC(thisActor, 4);
    }
}

void func_80386E70(ActorMarker *this, u32 arg1){
    Actor *thisActor = marker_getActor(this);
    if(thisActor->unk10_31 < 6){
        func_80386AEC(thisActor, 5);
    }
}

void func_80386EB0(ActorMarker *this, u32 arg1){
    Actor *thisActor = marker_getActor(this);
    if(thisActor->unk10_31 < 6){
        func_80386AEC(thisActor, 6);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/flibbit/func_80386EF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/flibbit/func_803870B4.s")
