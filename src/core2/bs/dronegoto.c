#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80297BB8(f32);

extern u8 D_8037D440;
extern u8 D_8037D441;

void func_802AEC08(void);
void func_802AEC70(void);
void func_802AEC78(void);
void func_802AEDC8(void);

void func_802AEB60(s32 arg0){
    switch(D_8037D440){
        case 1:
            func_802AEC70();
            break;
        case 2:
            func_802AEDC8();
            break;
    }
    switch(D_8037D440 = arg0){
        case 1:
            func_802AEC08();
            break;
        case 2:
            func_802AEC78();
            break;
    }
    
}

void func_802AEC08(void){
    func_802978A4();
}

void func_802AEC28(void){
    func_802978A4();
    if(func_8028B2E8() || player_inWater())
        func_802AEB60(2);
}

void func_802AEC70(void){}

void func_802AEC78(void){
    f32 sp2C;
    f32 sp20[3];
    s32 sp1C;
    func_8029BC60(&sp1C, &sp2C);
    func_8028A010(sp1C, sp2C);
    func_802925F8(&sp20, &sp2C);
    func_80297BC4(&sp20);
    func_80297BB8(sp2C);
    func_8029C7F4(1,1,3,0xC);
    func_8029436C(1);
    D_8037D441 = 0;
}

void func_802AECE4(void){
    f32 sp2C;
    f32 sp20[3];
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();

    func_80297A88(sp20);
    if(func_8025801C(sp20, &sp2C)){
        yaw_setIdeal(sp2C);
    }

    if( 250.0f <= gu_sqrtf(sp20[0]*sp20[0] + sp20[2]*sp20[2])
        && animctrl_getIndex(aCtrl) == ANIM_BANJO_WALK
    ){
        animctrl_reset(aCtrl);
        animctrl_setIndex(aCtrl, ANIM_BANJO_RUN);
        func_802875AC(aCtrl, "bsdronegoto.c", 0x9d);
    }

    if(func_80297C48() && D_8037D441 == 0){
        D_8037D441++;
        func_80292768();
    }
}

void func_802AEDC8(void){
    func_8029436C(0);
}

void func_802AEDE8(void){
    D_8037D440 = 0;
    func_8031F9F4(1);
    if( !func_8028B2E8() && func_8029BDE8()){
        func_802AEB60(1);
    }else{
        func_802AEB60(2);
    }
    
}

void func_802AEE48(void){
    switch(D_8037D440){
        case 1:
            func_802AEC28();
            break;
        case 2:
            func_802AECE4();
            break;
    }
}

void func_802AEE9C(void){
    func_802AEB60(0);
    func_8031F9F4(0);
}
