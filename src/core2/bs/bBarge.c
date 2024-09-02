#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/physics.h"


s32 func_8029E2E0(s32, f32);
void  func_80292864(f32, f32);
void func_8029E3C0(s32, f32);


/* .bss */
f32 D_8037D2A0;
u8  D_8037D2A4;
u8  D_8037D2A5;
u8  D_8037D2A6;

/* .code */
s32 func_8029F4E0(Actor * arg0){
    return arg0->unk138_31 == 0;
}

void func_8029F4F0(void){
    u8 val;
    f32 tmp_f;
    if(func_8029E1A8(2)){
        func_8029AE74(0);
        func_8029E3C0(2, 0.12f);
    }
    if( (++D_8037D2A4) >= 3)
        D_8037D2A4 = 0;

    switch(D_8037D2A4){
        case 0:
            tmp_f = (baphysics_get_target_yaw() + 180.0f);
            func_80292864(tmp_f - 70.0f, 20.0f);
            break;
        case 1:
            tmp_f = (baphysics_get_target_yaw() + 180.0f);
            func_80292864(tmp_f - 10.0f, 20.0f);
            break;
        case 2:
            tmp_f = (baphysics_get_target_yaw() + 180.0f);
            func_80292864(tmp_f + 50.0f, 20.0f);
            break;
    }
}

void func_8029F60C(void){
    f32 player_position[3];
    _player_getPosition(player_position);
    func_8032728C(player_position, 50.0f, 2, func_8029F4E0);
}


s32 bsbbarge_hitboxActive(void){
    return D_8037D2A6;
}

void bsbarge_init(void){
    AnimCtrl *plyrMvmnt;

    plyrMvmnt = baanim_getAnimCtrlPtr();
    animctrl_reset(plyrMvmnt);
    animctrl_setSmoothTransition(plyrMvmnt, 0);
    animctrl_setIndex(plyrMvmnt, ASSET_1C_ANIM_BSBBARGE);
    animctrl_setDuration(plyrMvmnt, 1.0f);
    animctrl_setSubRange(plyrMvmnt, 0, 0.375f);
    animctrl_setPlaybackType(plyrMvmnt,  ANIMCTRL_ONCE);
    animctrl_start(plyrMvmnt, "bsbbarge.c", 0x98);
    D_8037D2A4 = 0;
    func_8029C7F4(1,1,3, BA_PHYSICS_LOCKED_ROTATION);
    baphysics_set_target_yaw(yaw_getIdeal());
    baphysics_set_target_horizontal_velocity(baphysics_get_target_horizontal_velocity()*0.3);
    baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
    func_8029E070(1);
    D_8037D2A6 = 0;
    D_8037D2A5 = 0;
    miscflag_clear(0xA);
    miscflag_clear(0xB);
    miscflag_clear(0xC);
    func_8029E3C0(2, 0.01f);

}

void bsbarge_update(void){
    s32 sp24;
    AnimCtrl *plyrMvmnt;
    
    sp24 = 0;
    plyrMvmnt = baanim_getAnimCtrlPtr();
    if(button_released(BUTTON_B))
        miscflag_set(0xA);
    switch(D_8037D2A5){
        case 0:
            if(animctrl_isAt(plyrMvmnt, 0.1392f))
                func_80299BD4();
            
            if(!animctrl_isStopped(plyrMvmnt))
                break;

            if(miscflag_isFalse(0xA)){
                miscflag_set(0xC);
                D_8037D2A0 = 850.0f;
            }else{
                D_8037D2A0 = 500.0f;
            }
            func_8029E3C0(1, 0.01f);
            D_8037D2A5 = 1;
            break;
        case 1:
            func_8029E1A8(1);
            if(miscflag_isFalse(0xB) && func_8029E2E0(1, 0.1f)){
                if(miscflag_isTrue(0xC)){
                    func_8030E560(SFX_4_KAZOOIE_RUUUUUH, 30000);
                }else{
                    func_8030E560(SFX_43_KAZOOIE_RUH, 30000);
                }
                miscflag_set(0xB);
            }
            if(!func_8029E384(1))
                break;
            
            animctrl_setDuration(plyrMvmnt, 1.0f);
            baanim_setEnd(0.565f);
            baphysics_set_target_horizontal_velocity(D_8037D2A0);
            baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
            func_8030E760(SFX_2_CLAW_SWIPE, 0.558f, 22000);
            D_8037D2A5 = 2;
            func_8029F4F0();
            D_8037D2A6 = 1;
            break;
        case 2:
            baphysics_set_target_horizontal_velocity(D_8037D2A0);
            if(animctrl_isStopped(plyrMvmnt)){
                animctrl_setDuration(plyrMvmnt, 2.0f);
                baanim_setEnd(0.6f);
                func_8029E3C0(0, 0.1f);
                D_8037D2A5 = 3;
            }
            func_8029F4F0();
            break;
        case 3:
            func_8029E1A8(0);
            if(miscflag_isFalse(0xC) || func_8029E384(0)){
                D_8037D2A0 -= 80.0f;
            }
            baphysics_set_target_horizontal_velocity(D_8037D2A0);
            if(D_8037D2A0 < 200.0f){
                animctrl_setDuration(plyrMvmnt, 1.5f);
                baanim_setEnd(1.0f);
                D_8037D2A5 = 4;
            }
            func_8029F4F0();
            break;
        case 4:
            if(!player_isStable())
                sp24 = BS_2F_FALL;
            if(animctrl_isAt(plyrMvmnt, 0.7f)){
                D_8037D2A0 = 0.0f;
                D_8037D2A6 = 0;
            }
            baphysics_set_target_horizontal_velocity(D_8037D2A0);
            if(animctrl_isAt(plyrMvmnt, 0.9193f))
                sp24 = BS_20_LANDING;
            break;
    }
    if(D_8037D2A6)
        func_8029F60C();

    if(player_inWater())
        sp24 = BS_4C_LANDING_IN_WATER;
    bs_setState(sp24);
}

void bsbarge_end(void){
    ability_use(5);
    func_8029E070(0);
    D_8037D2A6 = 0;
}
