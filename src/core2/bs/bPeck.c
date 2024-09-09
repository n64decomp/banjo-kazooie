#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/yaw.h"

#include "core2/ba/physics.h"

void baModel_80292048(s32, f32, f32, f32);
void animctrl_start(AnimCtrl *, char *, s32);

/* .data */
f32 D_80364A60 = -1400.0f;
f32 D_80364A64 = 120.0f;

/* .bss */
f32 D_8037D370;
u8 D_8037D374;
u8 D_8037D375;
u8 D_8037D376;
u8 D_8037D377;

/* .code */
s32 func_802A6510(void){
    return D_8037D376;
}

void bsbpeck_init(void){
    D_8037D377 = 0;
    switch(bs_getPrevState()){
        case BS_8_BTROT_JUMP://L802A656C
            D_8037D377++;
            break;
        case BS_5_JUMP:
        case BS_2F_FALL:
        case BS_3D_FALL_TUMBLING:
        case BS_57_BOMB_END:
            break;
    }
    if(bafalldamage_get_state() == 1)
        bafalldamage_set_state(2);

    baanim_playForDuration_onceSmooth(ASSET_1A_ANIM_BSBPECK, 0.2f);
    func_8029C7F4(1,YAW_STATE_3_BOUNDED, 1, BA_PHYSICS_AIRBORN);
    yaw_setVelocityBounded(1200.0f, 10.0f);
    func_8029E070(1);
    baphysics_set_gravity(D_80364A60);
    baphysics_set_vertical_velocity(D_80364A64);
    baModel_80292048(1, -38.0f, 0.0f, 105.0f);
    baModel_80292048(0, -38.0f, 0.0f, -7.0f);
    baMarker_8028D638(0x23, 0x2A);
    D_8037D375 = 0;
    D_8037D374 = 0;
    D_8037D376 = 1;
}

void func_802A664C(void){
    f32 sp1C = 1.0f;
    switch(D_8037D375){
        case 0:
            sp1C = 1.13f;
            break;
        case 1:
            sp1C = 1.1f;
            break;
        case 2:
            sp1C = 1.32f;
            break;
    }
    miscFlag_set(MISC_FLAG_5_HAS_PECKED);
    func_8030E58C(SFX_42_KAZOOIE_RAH, sp1C);
    baphysics_set_vertical_velocity(D_80364A64);
    D_8037D375++;
}

void bsbpeck_update(void){
    enum bs_e sp24 = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();

    func_802B6FA8();
    if(D_8037D377){
        baphysics_set_target_horizontal_velocity(baphysics_get_target_horizontal_velocity() * 0.1);
    }

    switch(D_8037D374){
        case 0://L802A6770
            if(animctrl_isAt(aCtrl, 0.9126f)){
                animctrl_setIndex(aCtrl, ASSET_19_ANIM_BSBPECK_ENTER);
                animctrl_setStart(aCtrl, 0.0f);
                animctrl_setDuration(aCtrl, 0.35f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_LOOP);
                animctrl_start(aCtrl, "bsbpeck.c", 0xbd);
                D_8037D370 = 0.5f;
                D_8037D374 = 1;
            }
            break;
        case 1://L802A67E8
            if(animctrl_isAt(aCtrl, 0.1621f))
                func_802A664C();
            
            if(animctrl_isAt(aCtrl, 0.7f))
                func_802A664C();

            D_8037D370 -= time_getDelta();
            if(D_8037D370 < 0.0f){
                animctrl_reset(aCtrl);
                animctrl_setSmoothTransition(aCtrl, 0);
                animctrl_setIndex(aCtrl, ASSET_1A_ANIM_BSBPECK);
                animctrl_setDirection(aCtrl, 0);
                animctrl_setDuration(aCtrl, 0.2f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                animctrl_start(aCtrl, "bsbpeck.c", 0xd4);
                D_8037D374 = 2;
            }
            break;
        case 2://L802A68C4
            if(animctrl_isStopped(aCtrl))
                sp24 = BS_2F_FALL;
            break;
    }//L802A68D8

    if(player_isStable()){
        func_8029C5E8();
        sp24 = BS_1_IDLE;
    }

    if(player_inWater())
        sp24 = BS_4C_LANDING_IN_WATER;

    bs_setState(sp24);
}

void bsbpeck_end(void){
    D_8037D376 = 0;
    ability_use(0xa);
    baModel_80292048(1, 0.0f, 0.0f, 0.0f);
    baModel_80292048(0, 0.0f, 0.0f, 0.0f);
    baMarker_8028D638(0, 0);
    func_8029E070(0);
    baphysics_reset_gravity();
}
