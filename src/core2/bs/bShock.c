#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/physics.h"

/* .data */
const f32 D_80364A70 = 1250.0f;
const f32 D_80364A74 = -1200.f;

/* .bss */
u8 D_8037D380;
u8 D_8037D381;
u8 D_8037D382;

/* .code */
void bsbshock_charge_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    anctrl_reset(aCtrl);
    anctrl_setIndex(aCtrl, ASSET_48_ANIM_BSBSHOCK_CHARGE);
    anctrl_setTransitionDuration(aCtrl, 0.4f);
    anctrl_setDuration(aCtrl, 4.2f);
    anctrl_setSubRange(aCtrl, 0.0f, 0.1061f);
    anctrl_setPlaybackType(aCtrl,1);
    anctrl_start(aCtrl, "bsbshock.c", 0x61);
    func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);

    if(func_8029B2E8() != 0.0f)
        yaw_setIdeal(func_8029B33C());
    
    baphysics_set_target_yaw(yaw_getIdeal());
    func_802B6FA8();
    baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
    func_8029E064(1);
    func_8029E070(1);
    func_80299BD4();
    D_8037D382 = sfxsource_createSfxsourceAndReturnIndex();
    sfxsource_setSfxId(D_8037D382, SFX_2C_PULLING_NOISE);
    func_8030E04C(D_8037D382, 1.4f, 0.4f, -1.2f);
    baModel_80292158(-50.0f);
    func_80298528(-50.0f);
    D_8037D380 = 1;
    D_8037D381 = 0;
}

void bsbshock_charge_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 sp1C[3];

    if(player_isStable()) { 
        if(globalTimer_getTime() % 2) {
            func_8029C348();
        }
    }
    else
    {//L802A6B94
        func_8029C348();
    }
    func_802B6FA8();
    baphysics_get_velocity(sp1C);
    if(button_released(BUTTON_A) && 0.0f < sp1C[1]){
        baphysics_reset_gravity();
    }
    
    switch(D_8037D381){
        case 0:
            if(player_isFallTumbling())
                sp2C = BS_3D_FALL_TUMBLING;

            if(func_8028B254(0x82)){
                anctrl_setSubRange(aCtrl, 0.0f, 1.0f);
                anctrl_setDuration(aCtrl, 2.8f);
                anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D381 = 1;
            }
            break;
        case 1:
            if(anctrl_isAt(aCtrl, 0.11f))
                func_8030E2C4(D_8037D382);
            
            if(anctrl_isAt(aCtrl, 0.4036f))
                anctrl_setDuration(aCtrl, 1.4f);
            
            if(anctrl_isStopped(aCtrl))
                sp2C = BS_1_IDLE;
            break;
    }//L802A6CAC

    if(func_8028B254(0x3C)){
        if(anctrl_getAnimTimer(aCtrl) < 0.3637 && button_released(8)){
            D_8037D380 = 0;
        }//L802A6CF4
        if(player_isStable())
            baphysics_set_target_horizontal_velocity(0.0f);
    }
    else{//L802A6D18
        if(should_feathery_flap())
            sp2C = BS_BFLAP;
        
        if(should_beak_bust())
            sp2C = BS_F_BBUSTER;
    }//L802A6D44
    if(anctrl_isAt( aCtrl, 0.3637f) && D_8037D380)
        sp2C = BS_BSHOCK_JUMP;
    
    if(anctrl_isAt(aCtrl, 0.5551f)){
        baphysics_set_vertical_velocity(180.0f);
        baModel_80292158(0.0f);
        func_80298528(50.0f);
    }

    if(sp1C[1] < 0.0f && player_inWater())
        sp2C = BS_4C_LANDING_IN_WATER;
    bs_setState(sp2C);
}

void bsbshock_charge_end(void){
    sfxsource_freeSfxsourceByIndex(D_8037D382);
    func_8029E064(0);
    func_8029E070(0);
    if(baModel_80292230() != 0.0f){
        baModel_80292158(0.0f);
        func_80298528(50.0f);
    }
}

void bsbshock_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    anctrl_reset(aCtrl);
    anctrl_setSmoothTransition(aCtrl, 0);
    anctrl_setIndex(aCtrl, ASSET_49_ANIM_BSBSHOCK_JUMP);
    anctrl_setDuration(aCtrl, 0.8f);
    anctrl_setStart(aCtrl, 0.5304f);
    anctrl_setSubRange(aCtrl, 0.0f, 1.0f);
    anctrl_setPlaybackType(aCtrl,1);
    anctrl_start(aCtrl, "bsbshock.c", 0x13a);
    func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);

    if(func_8029B2E8() != 0.0f)
        yaw_setIdeal(func_8029B33C());
    
    baphysics_set_target_yaw(yaw_getIdeal());
    func_802B6FA8();
    baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
    baphysics_set_vertical_velocity(D_80364A70);
    baphysics_set_gravity(D_80364A74);
    sfxsource_playHighPriority(SFX_E_SHOCKSPRING_BOING);
    func_8029E064(1);
    func_8029E070(1);
    ability_use(9);
    baModel_80292158(-50.0f);
    func_80298528(-50.0f);
    D_8037D381 = 0;
}

void bsbshock_update(void){
    enum bs_e sp2C = 0;
    f32 sp20[3];
    AnimCtrl * aCtrl = baanim_getAnimCtrlPtr();

    func_802B6FA8();
    baphysics_get_velocity(sp20);
    if(anctrl_isAt(aCtrl, 0.7f))
        sfxsource_playHighPriority(SFX_53_BANJO_HUIII);

    if(button_released(BUTTON_A) && 0.0f < sp20[1])
        baphysics_reset_gravity();

    if(D_8037D381 == 0){
        func_8029C348();
        if(sp20[1] < 0.0f)
            sp2C = BS_2F_FALL;
    }

    if(!player_isStable()){
        if(player_isFallTumbling())
            sp2C = BS_3D_FALL_TUMBLING;

        if(should_feathery_flap())
            sp2C = BS_BFLAP;

        if(should_beak_bust())
            sp2C =BS_F_BBUSTER;
    }

    bs_setState(sp2C);
}

void bsbshock_end(void){
    if(bs_getNextState() != BS_11_BPECK)
        baphysics_reset_gravity();

    func_8029E064(0);
    func_8029E070(0);
    baModel_80292158(0.0f);
    func_80298528(50.0f);
}
