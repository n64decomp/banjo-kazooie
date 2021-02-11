#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"


f32 func_8034A754(f32, f32);
f32 func_80335684(void *);
u32 func_8025773C(f32*, f32);
void func_803253A0(Actor *);
void func_80325794(ActorMarker *);
void func_803391A4(Gfx**, Mtx**, f32*, f32*, f32, f32*, void*);
void func_8038B6D0(Actor *);
Actor *func_8038B528(ActorMarker*, Gfx **, Mtx **, u32 arg3);
void func_8030E878(u32,f32,u32,f32*, f32, f32);


extern f64 D_80391028;
extern f64 D_80391030;
extern f32 D_80391038;
extern f32 D_8039103C;

void func_8038B220(Actor*, u32);

ActorInfo D_80390A40 = {0xC7, actor_yumblie, 0x3F6, 0x00, NULL,
    func_8038B6D0, NULL, func_8038B528,
    {0,0,0,0}, 0.0f, {0,0,0,0}
};

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yumblie/func_8038B160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yumblie/func_8038B220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yumblie/func_8038B4E4.s")

Actor *func_8038B528(ActorMarker *this, Gfx **gdl, Mtx** mp, u32 arg3){
    Actor *thisActor;
    ActorLocal_Yumblie *sp40;
    f32 sp44[3];
    f32 sp38[3];
    
    thisActor = func_80329958(this);
    sp40 = &thisActor->yumblie;
    if ( thisActor->unk10_31 < 2 || thisActor->unk10_31 > 4){
        thisActor->marker->unk14_21 = 0;
        return thisActor;
    }

    func_8033A2D4(func_803253A0, thisActor, sp40);
    func_8033A2E8(func_80325794, this);
    sp44[0] = thisActor->position_x;
    sp44[1] = thisActor->position_y + sp40->unk0*75.0f;
    sp44[2] = thisActor->position_z;
    sp38[0] = thisActor->pitch;
    sp38[1] = thisActor->yaw;
    sp38[2] = thisActor->roll;
    if(sp40->unk4 && sp40->unkC){
        func_803391A4(gdl, mp, sp44, sp38, 1.0f, NULL, func_8038A994(sp40->unkC));
    }
    else{
        func_803391A4(gdl, mp, sp44, sp38, 1.0f, NULL, func_80330B1C(this));
    }
    return thisActor;
}


#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yumblie/func_8038B684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yumblie/func_8038B6D0.s")
// 99.9% matching: f32 rand(f32, f32) in case 2 saving to wrong register
// void func_8038B6D0(Actor *this){
//     ActorLocal_Yumblie *s0;
//     f32 sp50;
//     f32 sp4C;
//     void *sp48;
//     f32 tmp;
    

//     sp4C = func_8033DD9C();
//     s0 = &this->yumblie;
//     if(!this->unk16C_4){
//         this->unk16C_4 = 1;
//         s0->unk0 = 0.0f;
//         s0->unk4 = 0;
//         s0->unkC = 0;
//         func_8038B220(this, 1);
//         return;
//     }

//     if(s0->unkC == 0){
//         s0->unkC = *((u32*)func_80326D68(&this->position_x, 0x138, -1, &sp48));
//     }
//     sp50 = func_80335684(this->unk148);
//     if(this->unk10_31 == 1){
//         if(func_8025773C(&s0->unk8, sp4C)){
//             if(func_802CACF8(6) && (0xc > func_8038A9B8(s0->unkC))){
//                 func_8038B220(this,2);
//             }
//             else{
                
//                 func_8038B220(this,1);
//             }
//         }
//     }
//     if(this->unk10_31 == 2){
//         tmp = s0->unk0;
//         if(s0->unk4){
//             if((f64)sp50 <= D_80391028){
//                 s0->unk0 = sp50/D_80391028;
//             }
//         }else{
//             if((f64)sp50 <= D_80391030){
//                 s0->unk0 = sp50/D_80391030;
//             }
//         }

//         if(((f64)tmp < 0.5) && (0.5 <= (f64) s0->unk0)){
//             //!!! func_8034A754(1.0f, D_80391038) saving to wrong place in stack !!!
//             func_8030E878(0xc5, func_8034A754(1.0f, D_80391038), 30000, &this->position_x, 500.0f, D_8039103C);
//         }

//         if( 0 < func_80335794(this->unk148)){
//             s0->unk0 = 1.0f;
//             func_8038B220(this,3);
//         }

//     }
//     if(this->unk10_31 == 3){
//         if( func_8025773C(&s0->unk8,sp4C) || !func_802CACF8(6) ){
//             func_8038B220(this,4);
//         }
//     }

//     if(this->unk10_31 == 4){
//         if(sp50 >= 0.25 )
//             s0->unk0 -= 2.0f*(f64)sp4C;
        
//         if(0.0f >= s0->unk0){
//             s0->unk0 = 0.0f;
//             func_8038B220(this,1);
//         }   
//     }

//     if(this->unk10_31 == 5){
//         if( func_8025773C(&s0->unk8,sp4C)){
//             func_8038B220(this,1);
//         }
//     }
// }