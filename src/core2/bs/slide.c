#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/physics.h"

/* .bss */
s32 D_8037D520;
s32 D_8037D524;
f32 D_8037D528;

void func_802B40D0(void){
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp28;

    _player_getPosition(sp38);
    sp38[1] += 20.0f;
    D_8037D524++;
    if(!(D_8037D524 < 3))
        D_8037D524 = 0;

    if(D_8037D524){
        sp28 = mlNormalizeAngle(yaw_get() + 90.0f);
        func_802589E4(sp2C, sp28, randf()*10.0f + 20.0f);
        sp2C[1] = 0.0f;
    }

    switch(D_8037D524){
        case 1://L802B41A0
            ml_vec3f_scale(sp2C, -1.0f);
            sp38[0] += sp2C[0];
            sp38[1] += sp2C[1];
            sp38[2] += sp2C[2];
            break;
        case 2://L802B41DC
            sp38[0] += sp2C[0];
            sp38[1] += sp2C[1];
            sp38[2] += sp2C[2];
            break;
        case 0://L802B4208
            break;
    }
    func_802589E4(sp44, yaw_get(), 40.0f);
    sp44[1] = 50.0f;
    func_80352CF4(sp38, sp44, 10.0f, 150.0f);
}

void bsslide_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 sp30[3];
    f32 sp2C;
    f32 sp28;
    f32 tmp_f0;
    D_8037D520 = ASSET_5A_ANIM_BSSLIDE_FRONT;
    if(player_isSliding()){
        func_80294480(sp30);
        if(func_80258108(sp30, &sp28, &sp2C)){
            tmp_f0 = mlNormalizeAngle(yaw_get() - sp28);
            if(tmp_f0 < 90.0f || 270.0f < tmp_f0){
                D_8037D520 = ASSET_59_ANIM_BSSLIDE_BACK;
            }
        }
    }
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, D_8037D520);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_STOPPED);
    animctrl_setDuration(aCtrl, 1.0f);
    animctrl_start(aCtrl, "bsslide.c", 0x7f);
    func_8029C7F4(1,1,3, BA_PHYSICS_LOCKED_ROTATION);
    baphysics_set_target_yaw(yaw_getIdeal());
    baphysics_set_horizontal_velocity(yaw_getIdeal() ,baphysics_get_target_horizontal_velocity());
    pitch_setAngVel(800.0f, 8.0f);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_80299AAC();
    D_8037D524 = 0;
    D_8037D528 = 1.0f;

}

void bsslide_update(void){
    enum bs_e sp3C = 0;
    f32 sp30[3];
    f32 sp2C;
    f32 sp28;

    func_80299AAC();
    D_8037D528 = ml_max_f(D_8037D528 - time_getDelta(), 0.0f);
    if(player_isSliding()){
        func_80294480(sp30);
        if(func_80258108(sp30, &sp2C, &sp28)){
            if(D_8037D520 == 0x5A){
                yaw_setIdeal(sp2C + 180.0f);
                pitch_setIdeal(-sp28);
            }else{
                yaw_setIdeal(sp2C);
                pitch_setIdeal(sp28);
            }
            baphysics_set_target_horizontal_velocity(ml_map_f(sp28,20.0f, 60.0f, 550.0f, 700.0f));
            baphysics_set_target_yaw(sp2C);
        }else{
            baphysics_set_target_horizontal_velocity(500.0f);
        }
        func_802B40D0();
    }else{//L802B44C4
        sp3C = BS_1_IDLE;
    }//L802B44C8

    if(player_inWater())
        sp3C = BS_4C_LANDING_IN_WATER;
    
    if(D_8037D528 == 0.0f && button_pressed(BUTTON_A))
        sp3C = bs_getTypeOfJump();

    bs_setState(sp3C);
}

void bsslide_end(void){
    if(level_get() != 6)
        ability_use(6);
    pitch_setIdeal(0.0f);
}
