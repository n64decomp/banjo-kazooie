#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"
#include "animation.h"

extern f64 D_80373DF0;
extern f64 D_80373DF8;
extern f32 D_80373E00;
extern f32 D_80373E18;

extern u32 D_A0000238;


f32 func_80258904(f32 arg0, f32 arg1);

Animation *func_80287464(Movement *this);

void func_80287674(Movement *this, s32 arg1);
void func_8028767C(Movement *this, s32 arg1);
void func_80287684(Movement *this, s32 arg1);
void func_8028768C(Movement *this, f32 arg1);
void func_802876C0(Movement *this, f32 arg1);
void func_802876CC(Movement *this, f32 arg1, f32 arg2);
void func_80287784(Movement *this, s32 arg1);
f32  func_802877C8(Movement *this);
f32  func_802877D0(Movement *this);





static enum playback_type_e{
    playback_loop = 2
};

void func_80286F90(Movement *this){
    Animation *anim;
    f32 duration;

    if(this->unk22){
        anim = func_80287464(this);
        duration = func_80289698(anim);
        if( duration < 1.0f ){
            func_802897C8(anim, func_80258904(1.0f, func_8033DD9C()/func_802877D0(this) + duration));
        }
    }
}

void func_80287020(Movement *this){
    Animation *anim;
    f32 delta;
    f32 tmp;

     anim = func_80287464(this);
     func_80286F90(this);
     this->timer = func_80289690(anim);
     delta = func_8033DD9C() / func_802877C8(this);
     if(this->playback_direction == 0){
         delta = -delta;
     }
     tmp = this->timer + delta; 
     if(tmp < 0.0f){
         tmp += 1.0f;
     }
     tmp -= (f32)(s32)tmp;
     func_80289784(anim, tmp);
}

void func_802870E0(Movement *this){
    Animation *anim;
    f32 delta;
    f32 tmpf14;
    f32 f_range;
    f32 f_percent;

     anim = func_80287464(this);
     func_80286F90(this);
     this->timer = func_80289690(anim);;
     delta =  func_8033DD9C() / func_802877C8(this);
     if(this->playback_direction == 0){
         delta = -delta;
     }
     tmpf14 = this->timer + delta; 
     if(this->duration_max <= tmpf14){
         f_range = this->duration_max - this->duration_min;
         f_percent = (tmpf14 - this->duration_min)/f_range;
         tmpf14 = this->duration_min + (f_percent - (f32)(s32)f_percent)*f_range;
     }
     func_80289784(anim, tmpf14);
}


void func_802871A4(Movement *this){
    Animation *anim;
    f32 phi_f0;
    f32 phi_f2;
    

    anim = func_80287464(this);
    func_80286F90(this);
    this->timer = func_80289690(anim);
    phi_f2 = func_8033DD9C() / func_802877C8(this);
    if (this->playback_direction == 0) {
        phi_f2 = -phi_f2;
    }
    phi_f0 = this->timer + phi_f2;


    if (phi_f0 < 0.0f) {
        phi_f0 = 0.0f;
        func_80287674(this, 3);
        
    } else {
        if ((this->duration_max < phi_f0) || (D_80373DF0 < (f64) phi_f0)) {
            if(this->duration_max < phi_f0)
                phi_f0 = this->duration_max;
            if(D_80373DF8 < (f64) phi_f0)
                phi_f0 =  D_80373E00;
            func_80287674(this, 3);
        } else {
            phi_f0 = phi_f0 - (f32) (s32) phi_f0;
        }
    }
    func_80289784(anim, phi_f0);
}

Movement *func_802872E0(s32 arg0){ //new
    ActorMovement *this;

    this = (ActorMovement *)malloc( func_80289680() + 0x28);
    this->movement.animation = &this->animation;
    func_802896EC(&this->animation, 1);
    this->movement.playback_type = 0;
    this->movement.index = 0;
    this->movement.unk25 = 1;
    this->movement.timer = 0.0f;
    this->movement.unk18 = 0.0f;
    func_80287784(&this->movement, func_8030C77C());
    func_802876CC(&this->movement, 0.0f, 1.0f);
    func_8028768C(&this->movement, 2.0f);
    func_802876C0(&this->movement, 0.2f);
    func_80287684(&this->movement, 1);
    func_8028767C(&this->movement, 1);
    return &this->movement;
}

void func_80287394(Movement * this){ //free
    func_802896A0(this->animation);
    free(this);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_0/func_802873C0.s")
// void func_802873C0(Movement *this){//update
//     switch (this->playback_type)
//     {
//     case 1: //once
//         func_802871A4(this);
//         break;
//     case 2: //loop
//         func_80287020(this);
//         break;
//     case 4:
//         func_802870E0(this);
//         break;
//     case 3: //stopped
//         func_80286F90(this);
//         break;
//     default:
//         break;
//     }
// }

Movement *func_80287434(Movement *this){ //realloc
    ActorMovement *full_struct;
    full_struct = func_802555DC(this);
    full_struct->movement.animation = &full_struct->animation;
    return &full_struct->movement;
}

void func_8028745C(Movement *this, s32 index){
    this->index = index;
}

Animation *func_80287464(Movement *this){
    return this->animation;
}

void func_8028746C(Movement *this,  void (* arg1)(s32,s32)){
    func_80289790(this->animation, arg1);
}

void func_8028748C(Movement *this, s32 arg1){
    func_80289798(this->animation, arg1);
}

void func_802874AC(Movement *this){
    this->playback_type = playback_loop;
    this->unk25 = 1;
    this->timer = 0.0;
    this->unk18 = 0.0;
    func_80287684(this, 1);
    func_802876CC(this, 0.0, 1.0);
    func_8028768C(this, 2.0);
    func_802876C0(this, 0.2);
    func_8028767C(this, 1);
}

void func_8028752C(Movement *this){
    if(this->unk25){
        if(this->playback_direction)
            func_80289784(this->animation, 0.0f);
        else
            func_80289784(this->animation, 0.99999899f);
    }
    else
        func_80289784(this->animation, this->unk18);
    this->timer = func_80289690(this->animation);
}

void func_802875AC(Movement * this, s32 arg1, s32 arg2){
    if(this->unk22 && func_80289688(this->animation)){
        func_80289674(this->animation);
        func_8028977C(this->animation, this->index);
        func_8028752C(this);
        func_802897C8(this->animation, 0.0f);
    } else{
        func_8028980C(this->animation);
        func_8028977C(this->animation, this->index);
        func_8028752C(this);
        func_802897C8(this->animation, 1.0f);
    }
}

void func_8028764C(Movement *this, f32 timer){
    func_80289784(this->animation, timer);
}

void func_80287674(Movement *this, s32 arg1){
    this->playback_type = arg1;
}

void func_8028767C(Movement *this, s32 arg1){
    this->playback_direction = arg1;
}

void func_80287684(Movement *this, s32 arg1){
    this->unk22 = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_0/func_8028768C.s")
////NONMATCHING A0000238 reading to same reg
// void func_8028768C(Movement *this, f32 arg1){
//     if(D_A0000238 - 0x10000003){
//         arg1 += 3.0f;
//     }
//     this->animation_timer = arg1;
// }


void func_802876C0(Movement *this, f32 arg1){
    this->transition_timer = arg1;
}

void func_802876CC(Movement *this, f32 min, f32 max){
    this->duration_min = min - (f32)(s32)min;
    this->duration_max = (max != 1.0)? max - (f32)(s32)max : max;

}

void func_80287738(Movement *this, f32 *min, f32 *max){
    *min = this->duration_min;
    *max = this->duration_max;
}



void func_8028774C(Movement *this, f32 arg1){
    if(arg1 == 1.0)
        arg1 = D_80373E18;

    this->unk18 = arg1;
    this->unk25 = 0;
}

void func_80287784(Movement *this, s32 arg1){
    this->unk23 = arg1;
    this->unk24 = 0;
}

s32 func_80287790(Movement *this){
    return func_80289688(this->animation);
}

s32 func_802877B0(Movement *this){
    return this->playback_type;
}

s32 func_802877B8(Movement *this){
    return this->playback_direction;
}

s32 func_802877C0(Movement *this){
    return this->unk22;
}

f32 func_802877C8(Movement *this){
    return this->animation_timer;
}

f32 func_802877D0(Movement *this){
    return this->transition_timer;
}

f32 func_802877D8(Movement *this){
    return func_80289690(this->animation);
}

f32 func_802877F8(Movement *this){
    return this->timer;
}

void  func_80287800(Movement *this, f32 arg1){
    this->timer = arg1;
}

s32  func_8028780C(Movement *this, s32 arg1){
    return 0;
}

s32 func_8028781C(Movement *this, f32 *arg1, s32 arg2){
    s32 map;
    map = func_803348C0();
    if( map != map_cs_start_nintendo && map != map_cs_start_rarware
        && map != map_cs_end_not100 && this->unk23 !=0 && arg1 != NULL)
    {
        this->unk24 = this->unk24 -1;
        if(this->unk24 == 0xFF){
            this->unk24 = func_8028780C(arg1, arg2);
        }
        else{
            func_802897A0(this->animation);
            return;
        }
    }
    func_802895F8(this->animation);
}

s32 func_802878C4(Movement *this){
    return func_802877B0(this) == 3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_0/func_802878E8.s")


s32 func_80287A40(Movement *this){
    return (s32)this->animation - (s32) this == 0x28;
}