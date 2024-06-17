#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/physics.h"


/* .bss */
u8 D_8037D440;
u8 D_8037D441;

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
    baphysics_reset_horizontal_velocity();
}

void func_802AEC28(void){
    baphysics_reset_horizontal_velocity();
    if(func_8028B2E8() || player_inWater())
        func_802AEB60(2);
}

void func_802AEC70(void){}

void func_802AEC78(void){
    f32 sp2C;
    f32 sp20[3];
    s32 sp1C;
    func_8029BC60(&sp1C, &sp2C);
    baanim_playForDuration_loopSmooth(sp1C, sp2C);
    func_802925F8(&sp20, &sp2C);
    baphysics_set_goto_position(&sp20);
    baphysics_set_goto_duration(sp2C);
    func_8029C7F4(1,1,3,BA_PHYSICS_GOTO);
    func_8029436C(1);
    D_8037D441 = 0;
}

void func_802AECE4(void){
    f32 sp2C;
    f32 sp20[3];
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();

    baphysics_get_velocity(sp20);
    if(func_8025801C(sp20, &sp2C)){
        yaw_setIdeal(sp2C);
    }

    if( 250.0f <= gu_sqrtf(sp20[0]*sp20[0] + sp20[2]*sp20[2])
        && animctrl_getIndex(aCtrl) == ASSET_3_ANIM_BSWALK
    ){
        animctrl_reset(aCtrl);
        animctrl_setIndex(aCtrl, ASSET_C_ANIM_BSWALK_RUN);
        animctrl_start(aCtrl, "bsdronegoto.c", 0x9d);
    }

    if(baphysics_goto_done() && D_8037D441 == 0){
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
