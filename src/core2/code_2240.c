#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "animation.h"

//function declarations
void anim_setIndex(Animation *this, enum asset_e arg1);
s32  func_802897A0(Animation *this);
s32  func_802892FC(Animation *this);
void func_8033AA50(s32, f32, s32);
void func_8033A750(s32, s32, s32, f32);

//function definitions
void func_802891D0(Animation *this, s32 arg1){
    s32 *tmp;
    if(func_80288400((&this->unkA)[arg1], &tmp) == 0){
        func_8033A510(tmp);
    }; 
}

void func_8028920C(Animation *this){
    func_802891D0(this, this->unk8);
}

void func_8028922C(Animation *this){
    func_802891D0(this, 2);
}

s32 func_8028924C(Animation *this, s32 arg1){
    return func_80288374((&this->unkA)[arg1]);
}

s32 func_80289274(Animation *this){
    return func_8028924C(this, this->unk8);
}

s32 func_80289294(Animation *this){
    return func_8028924C(this, (this->unk8 != 0)? 0: 1);
}

s32 func_802892CC(Animation *this, s32 arg1){
    s32 tmp;
    func_80288400((&this->unkA)[arg1], &tmp);
    return tmp;
}

s32 func_802892FC(Animation *this){
    return func_802892CC(this, this->unk8);
}

s32 func_8028931C(Animation *this){
    return func_802892CC(this, (this->unk8 != 0)? 0: 1);
}

s32 func_80289354(Animation *this){
    return func_802892CC(this, 2);
}

void func_80289374(Animation *this){
    if(this->unk1C == 1 && func_80289274(this)){
        this->unk8 = (this->unk8)? 0 : 1;
    }
    this->unk1C = 0;
    if( this->duration < 1.0f && func_80289294(this)){
        func_8033AA50(func_80288590(this->index), this->timer, func_802892FC(this));
        func_8033A750(func_802892FC(this), func_8028931C(this), func_802892FC(this), this->duration);
    }
    else{
        func_8033AA50(func_80288590(this->index), this->timer, func_802892FC(this));
    }

}

void func_8028948C(Animation *this){
    if(this->unk1C == 1 && this->unk1E == 0){
        if(func_80289274(this)){
            this->unk8 = (this->unk8)? 0 : 1;
            func_8028922C(this);
        }
    }
    else{
        if(this->unk1C == 2)
            func_8028920C(this);
    }
    this->unk1C = 0;
    if( this->duration < 1.0f && func_80289294(this) && !this->unk1E){
        func_8033AA50(func_80288590(this->index), this->timer, func_80289354(this));
        func_8033A750(func_802892FC(this), func_8028931C(this), func_80289354(this), this->duration);
    }
    else{
        func_8033AA50(func_80288590(this->index), this->timer, func_802892FC(this));
        if(this->unk1E && this->index)
            this->unk1E = 0;
    }

}

void func_802895F8(Animation *this){
    if(this->unk1D == 1){
        func_8028948C(this);
    }
    else{
        func_80289374(this);
    }
    if(this->matrices){
        (*(this->matrices))(func_802892FC(this), this->unk4);
    }
    func_802897A0(this);
}


void func_80289674(Animation *this){
    this->unk1C = 1;
}

s32 func_80289680(void){
    return 0x20;
}

enum asset_e anim_getIndex(Animation *this){
    return this->index;
}

f32  func_80289690(Animation *this){
    return this->timer;
}

f32  func_80289698(Animation *this){
    return this->duration;
}

void func_802896A0(Animation *this){
    func_802883AC(this->unkA);
    func_802883AC(this->unkC);
    if(this->unk1D == 1){
        func_802883AC(this->unkE);
    }
}

void func_802896EC(Animation *this, s32 arg1){
    this->unk1D = arg1;
    anim_setIndex(this,0);
    anim_setTimer(this, 0.0f);
    func_802897C8(this, 1.0f);
    func_80289790(this, NULL);
    this->unk1C = 0;
    this->unk1E = 1;
    this->unk8 = 0;
    this->unkA = func_80288330();
    this->unkC = func_80288330();
    if(this->unk1D == 1){
        this->unkE = func_80288330();
    }
}

void anim_setIndex(Animation *this, enum asset_e arg1){
    this->index = arg1;
}

void anim_setTimer(Animation *this, f32 arg1){
    this->timer = arg1;
}

void func_80289790(Animation *this, void (*arg1)(s32, s32)){
    this->matrices = arg1;
}

void func_80289798(Animation *this, s32 arg1){
    this->unk4 = arg1;
}

s32 func_802897A0(Animation *this){
    return func_8033A238(func_802892FC(this));
}

void func_802897C8(Animation *this, f32 arg1){
    this->duration = arg1;
}

void func_802897D4(Animation *this, void *arg0, Animation *dst){
    func_802EA1A8(this, arg0, func_802892FC(dst));
}

void func_8028980C(Animation *this){
    this->unk1C = 2;
}