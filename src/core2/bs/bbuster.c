#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/physics.h"

/*.data*/
const f32 D_80364990 = 400.0f;
const f32 D_80364994 = -800.0f;

const f32 D_80364998 = 730.0f;
const f32 D_8036499C = -2110.0f;

const f32 D_803649A0 = 2300.0f;
const f32 D_803649A4 = -20000.0f;
const f32 D_803649A8 = -5000.0f;

/*.bss*/
f32 D_8037D2B0;
u8 D_8037D2B4;
u8 D_8037D2B5;
u8 D_8037D2B6;
u8 D_8037D2B7;
u8 D_8037D2B8;
u8 D_8037D2B9;
u8 D_8037D2BA;
u8 D_8037D2BB;
u8 D_8037D2BC;

void func_802A02B4(s32 arg0);

/*.code*/
int func_8029FB20(Actor *arg0){
    return !arg0->unk124_0;
}

void func_8029FB30(void) {
    f32 i;

    for(i = 0.0f; i < 359.0; i += 60.0){
        func_80292974(i, 730.0f, 100.0f);
    }
    for(i = 0.0f; i < 359.0; i += 60.0){
        func_80292974(mlNormalizeAngle(i + 30.0f), 430.0f, 40.0f);
    }
}

s32 func_8029FC4C(void){
    return D_8037D2B8;
}

s32 bsbbuster_hitboxActive(void){
    return D_8037D2B7;
}

void bsbbuster_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 sp20[3];
    
    anctrl_reset(aCtrl);
    anctrl_setSmoothTransition(aCtrl, 0);
    anctrl_setIndex(aCtrl, ASSET_1D_ANIM_BSBBUSTER);
    anctrl_setDuration(aCtrl, 1.02f);
    anctrl_setSubRange(aCtrl, 0.0f, 0.35f);
    anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bsbbuster.c", 0x81);
    func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);
    baphysics_set_gravity(0.0f);
    baphysics_set_target_horizontal_velocity(0.0f);
    ml_vec3f_clear(sp20);
    baphysics_set_velocity(sp20);
    func_8029E070(1);
    func_802A02B4(0);
    D_8037D2B9 = 0;
    D_8037D2B7 = 0;
    D_8037D2B8 = 0;
    D_8037D2B0 = 0.0001f;
    D_8037D2B4 = 0;
    D_8037D2B5 = 0;
    D_8037D2B6 = 0;
    D_8037D2BC = 0;
    D_8037D2BA = 0;
}

void bsbbuster_update(void){
    enum bs_e sp44 = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    s32 sp3C;
    f32 sp30[3];
    f32 player_position[3];

    D_8037D2B8 = 0;
    if(anctrl_isAt(aCtrl, 0.24f))
        basfx_80299BD4();

    switch(D_8037D2BA){
        case 0://8029FDF0
            if(anctrl_isStopped(baanim_getAnimCtrlPtr())){
                anctrl_setDuration(aCtrl, 0.4f);
                D_8037D2BA = 1;
            }
            break;
        case 1://8029FE24
            D_8037D2B0 -= time_getDelta();
            if(D_8037D2B0 <= 0.0f){
                baphysics_reset_gravity();
                baphysics_set_terminal_velocity(D_803649A8);
                baphysics_set_gravity(D_803649A4);
                baphysics_set_vertical_velocity(D_803649A0);
                D_8037D2B7 = 1;
                D_8037D2BA = 2;
            }
            break;
        case 2://8029FEA0
            if(D_8037D2B5 == 0 && baphysics_get_vertical_velocity() < 0.0f){
                func_8030E760(SFX_45_KAZOOIE_HUGHH, 1.2f, 0x7530);
                D_8037D2B5++;
            }
            if(D_8037D2B4 == 0 && func_8028B254(0x8c)){
                func_8030E5F4(SFX_13_BEAKBUSTER_GROUND, 1.0f);
                D_8037D2B4++;
            }
            if(D_8037D2B6 == 0 && func_8028B254(0x4b)){
                baMotor_80250D94(1.0f, 0.3f, 0.4f);
                D_8037D2B6++;
            }
            D_8037D2B9 = miscFlag_isTrue(MISC_FLAG_8);
            func_8029445C(sp30);
            //L8029FF78
            if(((0.0f <= sp30[1])? sp30[1] : -sp30[1]) < 1.0){
                D_8037D2BC++;
            }else{
                D_8037D2BC = 0;
            }
            if(D_8037D2B7 == 2){
                D_8037D2B7 = 0;
            }
            if(player_isStable() || D_8037D2B9 || !(D_8037D2BC < 4)){
                func_802BB3DC( 0, 45.0f, 0.71f);
                func_8029AE74(0);
                func_8029FB30();
                baphysics_set_velocity(0);
                baphysics_set_gravity(0.0f);
                baphysics_set_target_horizontal_velocity(0.0f);
                D_8037D2B7 = 2;
                D_8037D2B8 = 1;
                D_8037D2B0 = 0.09f;
                D_8037D2BA = 3;
                _player_getPosition(player_position);
                func_8032728C(player_position, 150.0f, 2, func_8029FB20);
                if(bafalldamage_get_damage(&sp3C)){
                    sp44 = BS_SPLAT;
                }
            }
            break;
        case 3://802A00F0
            D_8037D2B7 = 0;
            if(func_80297C6C() == 1){
                func_80297CCC(0.9f);
            }
            
            D_8037D2B0 -= time_getDelta();
            if(D_8037D2B0 <= 0.0f){
                if(D_8037D2BB){
                    baphysics_set_vertical_velocity(D_80364990);
                    baphysics_set_gravity(D_80364994);
                }else{
                    baphysics_set_vertical_velocity(D_80364998);
                    baphysics_set_gravity(D_8036499C);
                }
            
                anctrl_setSubRange(aCtrl, 0.0f, 0.7299f);
                anctrl_setDuration(aCtrl, 1.9f);
                anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D2BA = 4;
            }
            break;
        
        case 4://802A01CC
            func_802B6FA8();
            if(anctrl_isStopped(aCtrl)){
                anctrl_setSubRange(aCtrl, 0.0f, 0.74f);
                anctrl_setDuration(aCtrl, 15.0f);
                anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
            }
            if(player_isStable()){
                anctrl_setSubRange(aCtrl, 0.0f, 1.0f);
                anctrl_setDuration(aCtrl, 1.9f);
                anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                sp44 = BS_20_LANDING;
            }
            break;
    }
    if(player_inWater())
        sp44 = BS_4C_LANDING_IN_WATER;

    bs_setState(sp44);
}//L802A024C

void bsbbuster_end(void){
    baphysics_reset_gravity();
    baphysics_reset_terminal_velocity();
    func_8029E070(0);
    D_8037D2B7 = 0;
    D_8037D2B8 = 0;
}

void func_802A02B4(s32 arg0){
    D_8037D2BB = arg0;
}
