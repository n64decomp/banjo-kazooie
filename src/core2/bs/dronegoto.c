#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/physics.h"


/* .bss */
u8 bsdronetogo_substate;
u8 D_8037D441;

void func_802AEC08(void);
void func_802AEC70(void);
void func_802AEC78(void);
void func_802AEDC8(void);

static void __bsDroneGoTo_set_substate(s32 arg0){
    switch(bsdronetogo_substate){
        case 1:
            func_802AEC70();
            break;
        case 2:
            func_802AEDC8();
            break;
    }
    switch(bsdronetogo_substate = arg0){
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
        __bsDroneGoTo_set_substate(2);
}

void func_802AEC70(void){}

void func_802AEC78(void){
    f32 duration_s;
    f32 target_position[3];
    s32 anim_id;
    func_8029BC60(&anim_id, &duration_s);
    baanim_playForDuration_loopSmooth(anim_id, duration_s);
    badrone_get_position_and_duration(target_position, &duration_s);
    baphysics_set_goto_position(target_position);
    baphysics_set_goto_duration(duration_s);
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
        badrone_goto_end();
    }
}

void func_802AEDC8(void){
    func_8029436C(0);
}

void bsDroneGoTo_init(void){
    bsdronetogo_substate = 0;
    func_8031F9F4(1);
    if( !func_8028B2E8() && func_8029BDE8()){
        __bsDroneGoTo_set_substate(1);
    }else{
        __bsDroneGoTo_set_substate(2);
    }
    
}

void bsDroneGoTo_update(void){
    switch(bsdronetogo_substate){
        case 1:
            func_802AEC28();
            break;
        case 2:
            func_802AECE4();
            break;
    }
}

void bsDroneGoTo_end(void){
    __bsDroneGoTo_set_substate(0);
    func_8031F9F4(0);
}
