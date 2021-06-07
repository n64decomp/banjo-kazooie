#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"
f32 func_80335684(void *);
void func_803253A0(Actor *);
void func_80325794(ActorMarker *);
void func_8038B6D0(Actor *);
Actor *func_8038B528(ActorMarker*, Gfx **, Mtx **, u32 arg3);

f32 randf (void);

extern f64 D_80391010;
extern f32 D_80391018;
extern f32 D_8039101C;
extern f32 D_80391020;
extern f32 D_80391024;
extern f64 D_80391028;
extern f64 D_80391030;
extern f32 D_80391038;
extern f32 D_8039103C;

void func_8038B220(Actor*, u32);


ActorInfo D_80390A40 = {0xC7, actor_yumblie, 0x3F6, 0x00, NULL,
    func_8038B6D0, NULL, func_8038B528,
    {0,0,0,0}, 0.0f, {0,0,0,0}
};

u32 func_8038B160(Actor *this){
    u32 temp_v0;

    temp_v0 = func_8038A9E0(this->yumblie.unkC);
    if ((temp_v0 == 1) || (temp_v0 == 4))
        return 0;
    
    if ((temp_v0 == 2) || (temp_v0 == 5)) 
        return (D_80391010 <= (f64) randf ()) ? 1 : 0;

    return ((f64) randf () >= 0.5)? 1 : 0;


}

void func_8038B220(Actor* this, u32 state){
    ActorLocal_Yumblie *s0;
    s0 = &this->yumblie;
    s0->unk8 = 0;
    if(state == 1){
        s0->unk8 = randf2(1.0f, 10.0f);
    }
     
    if(state == 2){
        this->yaw = randf2(0.0f, 360.0f);
        s0->unk4 = func_8038B160(this);
        func_8038AC54(s0->unkC, this->marker, this->position, s0->unk4);
        func_80335924(this->unk148, (s0->unk4)? 0x128 : 0x125, 0.0f, 1.5f);
        func_80335A8C(this->unk148, 2);
    }
    if(state == 3){
        s0->unk8 = randf2(5.0f, 10.0f);
        func_80335924(this->unk148, (s0->unk4)? 0x12A : 0x127, 0.1f, randf2(0.5f, 1.0f));
        func_80335A8C(this->unk148, 1);
        if(s0->unk4){
            func_8030E6A4(0xc4,randf2(1.0f, D_80391018), 0x7530);
        }else{
            func_8030E878(0xc3,randf2(1.0f, D_8039101C), 0x7530, this->position, 500.0f, D_80391020);
        }
    }
    
    if(state == 4){
        func_8038ACFC(s0->unkC, this->marker);
        func_80335924(this->unk148, (s0->unk4)? 0x129 : 0x126, 0.1f, 0.5f);
        func_80335A8C(this->unk148, 2);
    }
    if(state == 5){
        s0->unk8 = randf2(10.0f, 20.0f);
        func_8038ACFC(s0->unkC, this->marker);
        func_8030E878((s0->unk4)? 0xc4: 0xc3, 1.4f, 0x7D00, this->position, 500.0f, D_80391024);
    }
    this->unk10_31 = state;
}

int func_8038B4E4(ActorMarker * arg0){
    volatile Actor* actPtr;

    actPtr = marker_getActor(arg0);
    return (actPtr->unk10_31 >= 2) && (actPtr->unk10_31 < 5);
}

Actor *func_8038B528(ActorMarker *this, Gfx **gdl, Mtx** mp, u32 arg3){
    Actor *thisActor;
    ActorLocal_Yumblie *sp40;
    f32 sp44[3];
    f32 sp38[3];
    
    thisActor = marker_getActor(this);
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

u32 func_8038B684(ActorMarker * arg0){
    Actor* actPtr = marker_getActor(arg0);

    if( actPtr->unk10_31 < 5){
        func_8038B220(actPtr, 5);
        return 1;
    }

    return 0;
}


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
//         s0->unkC = *((u32*)func_80326D68(this->position, 0x138, -1, &sp48));
//     }
//     sp50 = func_80335684(this->unk148);
//     if(this->unk10_31 == 1){
//         if(func_8025773C(&s0->unk8, sp4C)){
//             if(mapSpecificFlags_get(6) && (0xc > func_8038A9B8(s0->unkC))){
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
//             //!!! randf2(1.0f, D_80391038) saving to wrong place in stack !!!
//             func_8030E878(0xc5, randf2(1.0f, D_80391038), 30000, this->position, 500.0f, D_8039103C);
//         }

//         if( 0 < func_80335794(this->unk148)){
//             s0->unk0 = 1.0f;
//             func_8038B220(this,3);
//         }

//     }
//     if(this->unk10_31 == 3){
//         if( func_8025773C(&s0->unk8,sp4C) || !mapSpecificFlags_get(6) ){
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
