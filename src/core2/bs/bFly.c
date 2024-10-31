#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"
#include "core2/ba/physics.h"
#include "core2/ba/flap.h"
#include "core2/ba/timer.h"

extern void baModel_setYDisplacement(f32);
extern f32 bastick_getX(void);
extern void ncDynamicCam4_func_802BFE50(f32, f32, f32);
extern void func_80354030(f32[3], f32);


/* .data */


/* .bss */
f32 D_8037D320;
f32 D_8037D324;
f32 D_8037D328[3];
f32 D_8037D338[3];
u8 D_8037D344;
u8 D_8037D345;
u8 D_8037D346;
u8 D_8037D347;

/* .code */
int func_802A3350(void){
    if(!player_isStable()) 
        return 0;
    if(func_80294684() & 8){
        return 0;
    }
    return 1;
}

void func_802A339C(f32 arg0[3], f32 arg1[3], f32 arg2){
    viewport_getLookVector(arg0);
    ml_vec3f_scale(arg0, arg2);
    viewport_getRotation_vec3f(arg1);
}

void func_802A33D8(void){
    pitch_setAngVel(500.0f, 1.2f);
}

void func_802A3404(void){
    pitch_setAngVel(1000.0f, 2.2f);
}

void func_802A3430(void){
    baModel_setYDisplacement(60.0f);
    yaw_setUpdateState(3);
    yaw_setVelocityBounded(500.0f, 2.0f);
    roll_setAngularVelocity(500.0f, 2.0f);
    func_802A33D8();
    func_80293D48(60.0f, 45.0f);
    func_80294378(4);
    baflap_reset();
    baflap_activate(1);
}

void func_802A34C8(void){
    if(!bsbfly_inSet(bs_getNextState())){
        baphysics_reset_gravity();
        baphysics_reset_terminal_velocity();
        func_8029E070(0);
        baModel_setYDisplacement(0.0f);
        func_8029CB84();
        yaw_setUpdateState(1);
        func_80291548();
        func_80293D74();
        func_80294378(1);
        baflap_activate(0);
    }
}

void func_802A354C(void){
    f32 yaw_range;
    f32 roll_range;
    f32 sp2C; 

    sp2C = bastick_getX();
    if(bakey_held(BUTTON_R)){
        yaw_setVelocityBounded(500.0f, 30.0f);
        yaw_range = 6.0f;
        roll_range = 85.0f;
    }
    else{
        yaw_setVelocityBounded(500.0f, 2.0f);
        yaw_range = 3.0f;
        roll_range = 75.0f;
    }
    roll_setIdeal(ml_map_f(sp2C, -1.0f, 1.0f, -roll_range, roll_range));
    yaw_setIdeal(mlNormalizeAngle(yaw_getIdeal() + ml_map_f(sp2C, -1.0f, 1.0f, yaw_range, -yaw_range)));
}

void func_802A3648(void){
    f32 tmp_f0 = bastick_getY();

    if(tmp_f0 < 0.0f)
        pitch_setIdeal(ml_map_f(tmp_f0, -1.0f, 0.0f, 300.0f, 360.0f));
    else
        pitch_setIdeal(ml_map_f(tmp_f0, 0.0f, 1.0f, 0.0f, 80.0f));


}

void func_802A36D0(void){
    f32 plyr_pos[3];

    _player_getPosition(plyr_pos);
    plyr_pos[0] += randf2(-30.0f, 30.0f);
    plyr_pos[1] += 50.0f + randf2(0.0f, 30.0f);
    plyr_pos[2] += randf2(-30.0f, 30.0f);
    func_803541C0(5);
    func_803541CC(0x50);
    func_80354030(plyr_pos, 0.5f);

}

int bsbfly_inSet(enum bs_e arg0){
    return arg0 == BS_BOMB
        || arg0 == BS_57_BOMB_END
        || arg0 == BS_18_FLY_KNOCKBACK
        || arg0 == BS_59_BFLY_UNK59
        || arg0 == BS_FLY_OW
        || arg0 == BS_76_BFLY_LOCKED
        || arg0 == BS_24_FLY
        || arg0 == BS_99_BFLY_DRONE;
}

int func_802A37F8(void){
    return bsbfly_inSet(bs_getState());
}

void bsbfly_enter_init(void){
    baanim_playForDuration_onceSmooth(ASSET_45_ANIM_BSBFLY_ENTER, 1.4f);
    func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);
    if(bastick_distance() != 0.0f)
        yaw_setIdeal(bastick_getAngleRelativeToBanjo());
    
    baphysics_set_target_yaw(yaw_getIdeal());
    baphysics_set_velocity(0);
    baphysics_set_target_horizontal_velocity(0.0f);
    baphysics_set_gravity(-1200.0f);
    func_8029E070(1);
    basfx_80299BD4();
    D_8037D344 = 0;
    D_8037D346 = 0;
}

void bsbfly_enter_update(void){
    enum bs_e sp1C = 0;
    AnimCtrl * aCtrl = baanim_getAnimCtrlPtr();

    switch(D_8037D344){
    case 0:
        if(anctrl_isAt(aCtrl, 0.2416f)){
            anctrl_setDuration(aCtrl, 2.4f);
            baphysics_set_vertical_velocity(1600.0f);
            func_8030E58C(SFX_C_TAKING_FLIGHT_LIFTOFF, 0.7f);
            D_8037D344 = 1;
        }
        break;
    default:
        func_802A36D0();
        if(baphysics_get_vertical_velocity() < 0.0f)
            sp1C = BS_24_FLY;
        break;
    }

    bs_setState(sp1C);
}

void bsbfly_enter_end(void){
    ability_use(8);
    func_8029E070(0);
}

void bsbfly_init(void){
    baanim_playForDuration_loopSmooth(ASSET_38_ANIM_BSBFLY, 0.62f);
    func_8029C7F4(1,1,3, BA_PHYSICS_LOCKED_ROTATION);
    if(miscFlag_isTrue(MISC_FLAG_9)){
        baphysics_set_target_horizontal_velocity(0.0f);
    }else{
        baphysics_set_target_horizontal_velocity(600.0f);
    }

    baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
    baphysics_set_target_yaw(yaw_getIdeal());
    func_8029E070(1);
    baphysics_set_gravity(-300.0f);
    baphysics_set_terminal_velocity(-99.9f);
    func_802914CC(4);
    func_802A3430();
    D_8037D320 = 1.0f;
    D_8037D344 = 0;
    D_8037D347 = 0;
}

void bsbfly_update(void){
    enum bs_e sp54 = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    BKCollisionTri *sp4C;
    f32 sp40[3];
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    int sp30;
    enum bs_e sp2C;
    

    func_802A354C();
    func_802A3648();
    sp3C = pitch_get();
    sp2C = 0;
    if(bakey_pressed(BUTTON_A))
        D_8037D347 = 1;

    if(D_8037D347 && globalTimer_getTime()%3 == 0){
        D_8037D347 = 0;
        func_80346C10(&sp2C, 0, BS_1_IDLE, ITEM_F_RED_FEATHER, 1);
    }

    if(sp2C || D_8037D346){
        if(sp2C){
            anctrl_setDuration(aCtrl, 0.3f);
            func_802D8BE4(0);
        }
        if(D_8037D346){
            D_8037D346 = 0;
            baflap_add(0.35f);
        }else{
            baflap_add(1.0f);
        }
    }//L802A3BB4

    sp30 = baflap_getCount();
    switch(D_8037D344){
        case 0:
            if(sp30)
                D_8037D344 = 1;
            break;
        case 1://L802A3BF4
            sp34 = mlNormalizeAngle(pitch_getIdeal() - 30.0f);
            if((80.0f < sp34 && sp34 < 300.0f))
                sp34 = 300.0f;
            pitch_setIdeal(sp34);
            func_802A3404();
            if(sp30){
                baphysics_set_vertical_velocity(sp30 * 400.0);
            }
            if(!sp30){
                anctrl_setDuration(aCtrl, 0.62f);
                func_802A33D8();
                D_8037D344 = 0;
            }
            break;
    }//L802A3CB8
    if(anctrl_isAt(aCtrl, 0.1358f)){
        func_8030EBC8(SFX_2_CLAW_SWIPE, 0.6f, 0.7f, 0x2710, 0x2ee0);
    }
    baphysics_set_gravity(-300.0f);
    if(miscFlag_isTrue(MISC_FLAG_9)){
        baphysics_set_terminal_velocity(0.0f);
        baphysics_set_velocity(0);
        sp38 = 0.0f;
    }
    else if(sp3C <= 80.0f){
        baphysics_set_terminal_velocity(ml_map_f(sp3C, 60.0f, 80.0f, -99.9f, -1000.33));
        baphysics_set_gravity(ml_map_f(sp3C, 60.0f, 80.0f, -300.0f, -700.0f));
        sp38 = ml_map_f(sp3C, 60.0f, 80.0f, 600.0f, 60.0f);
    }
    else{
        baphysics_set_terminal_velocity(ml_map_f(sp3C, 300.0f, 310.0f, -399.99f, -99.9f));
        sp38 = ml_map_f(sp3C, 300.0f, 340.0f, 0.0f, 600.0f);
    }//L802A3E18

    sp4C = func_802946F0();
    func_8029445C(sp40);

    if(sp4C != NULL && -1.0 < sp40[1])
        sp38 = 0.0f;

    baphysics_set_target_yaw(yaw_get());
    baphysics_set_target_horizontal_velocity(sp38);

    if(bainput_should_beak_bust())
        sp54 = BS_F_BBUSTER;

    D_8037D320 = ml_max_f(D_8037D320 - time_getDelta(), 0.0f);
    if( D_8037D320 == 0.0f
        && bakey_pressed(BUTTON_B)
        && can_beak_bomb()
    ){
        sp2C = 0;
        func_80346C10(&sp2C, 0, 1, ITEM_F_RED_FEATHER, 1);
        if(sp2C)
            sp54 = BS_BOMB;
    }

    if(player_inWater())
        sp54 = BS_2D_SWIM_IDLE;

    if(func_802A3350())
        sp54 = BS_1_IDLE;

    baflap_update();
    bs_setState(sp54);
}

void func_802A3F70(void){
    func_802A34C8();
}


int bsbfly_bombHitboxActive(void){
    return D_8037D345;
}

//bsbfly_bomb_init
void func_802A3F9C(void){
    f32 sp1C[3];
    baanim_playForDuration_once(ASSET_43_ANIM_BSBFLY_BEAKBOMB_START, 1.0f);
    func_8029C7F4(1,1,3,BA_PHYSICS_FREEZE);
    func_802A339C(D_8037D338, sp1C, 4200.0f);
    yaw_setIdeal(sp1C[1] + 180.0f);
    pitch_setIdeal(sp1C[0]);
    roll_setIdeal(0.0f);
    baphysics_set_velocity(D_8037D338);
    pitch_setIdeal(sp1C[0]);
    func_8029E070(1);
    func_802914CC(4);
    ncDynamicCam4_func_802BFE74(1);
    func_802A3430();
    FUNC_8030E624(SFX_52_BANJO_YAH_OH, 1.0f, 28000);
    D_8037D345 = 0;
    _player_getPosition(D_8037D328);
    D_8037D344 = 0;
    func_802D8BE4(0);
}

void func_802A4078(void){
    f32 plyr_pos[3];

    _player_getPosition(plyr_pos);
    plyr_pos[0] += D_8037D338[0];
    plyr_pos[1] += D_8037D338[1];
    plyr_pos[2] += D_8037D338[2];
    func_80294A64(plyr_pos);
    func_8030E6D4(SFX_13_BEAKBUSTER_GROUND);
}

s32 func_802A40E0(void){
    func_802A4078();
    item_dec(ITEM_14_HEALTH);
    if(item_getCount(ITEM_14_HEALTH))
        return BS_59_BFLY_UNK59;
    else
        return BS_41_DIE;
}

void func_802A411C(void) {
    s32 next_state;
    AnimCtrl *sp58;
    BKCollisionTri *phi_v0;
    f32 sp48[3];
    s32 sp44;
    s32 sp40;
    f32 sp34[3];
    f32 sp28[3];
    f32 sp24;

    next_state = 0;
    sp58 = baanim_getAnimCtrlPtr();
    switch (D_8037D344) {
    case 0:
        if (anctrl_isAt(sp58, 0.6905f)) {
            baphysics_set_type(BA_PHYSICS_UNK8);
            func_802914CC(5);
            ncDynamicCam5_func_802BF590(&D_8037D338);
            anctrl_setDuration(sp58, 0.05f);
            basfx_80299CF4(SFX_50_KAZOOIE_RRRUH, 1.3f, 0x7FFF);
            D_8037D345 = 1;
            D_8037D324 = 0.0f;
            D_8037D344 = 1;
        }
        break;
    case 1:
        func_802A36D0();
        D_8037D324 += time_getDelta();
        sp40 = player_isStable();
        if (player_inWater()) {
            next_state = BS_4C_LANDING_IN_WATER;
        }
        if ((func_80294530()) || (sp40)) {
            if (sp40) {
                func_80294480(sp34);
                phi_v0 = func_8029463C();
            } else {
                func_802944D0(sp34);
                phi_v0 = func_802946F0();
            }
            if (phi_v0 != NULL) {
                sp44 = phi_v0->flags;
            } else {
                sp44 = 0;
            }
            ml_vec3f_copy(sp28, D_8037D338);
            ml_vec3f_normalize(sp28);
            sp24 = mlAbsF(sp34[0] * sp28[0] + sp34[1] * sp28[1] + sp34[2] * sp28[2]);
            if (miscFlag_isTrue(MISC_FLAG_8) || ((sp44 & 0x80) != 0)) {
                func_802A4078();
                next_state = BS_18_FLY_KNOCKBACK;
            } else if (0.4 < sp24) {
                if (0.65 > sp34[1]) {
                    next_state = func_802A40E0();
                } else {
                    next_state = BS_58_BEAKBOMB_CRASH;
                }
            } else if (sp40 != 0) {
                next_state = BS_58_BEAKBOMB_CRASH;
            }
        }
        _player_getPosition(sp48);
        ml_vec3f_diff(sp48, D_8037D328);
        if (sp48[0]*sp48[0] + sp48[1]*sp48[1] + sp48[2]*sp48[2] > 16000000.0f) {
            next_state = BS_57_BOMB_END;
        }
        if (anctrl_isStopped(sp58) != 0) {
            anctrl_setIndex(sp58, 0x47);
            anctrl_setDuration(sp58, 0.3f);
            anctrl_setPlaybackType(sp58, ANIMCTRL_LOOP);
            anctrl_start(sp58, "bsbfly.c", 0x361);
        }
        break;
    }
    bs_setState(next_state);
}

void func_802A4404(void){
    basfx_80299E6C();
    D_8037D345 = 0;
    func_802A34C8();
}

void func_802A4430(void){
    AnimCtrl *plyr_anctrl;

    plyr_anctrl = baanim_getAnimCtrlPtr();
    anctrl_reset(plyr_anctrl);
    anctrl_setTransitionDuration(plyr_anctrl, 0.3f);
    anctrl_setIndex(plyr_anctrl, ASSET_CC_ANIM_BSFLY_BEAKBOMB_END);
    anctrl_setDuration(plyr_anctrl, 0.38f);
    anctrl_setPlaybackType(plyr_anctrl, ANIMCTRL_LOOP);
    anctrl_start(plyr_anctrl, "bsbfly.c", 0x38a);
    func_8029C7F4(1, 1, 3, BA_PHYSICS_LOCKED_ROTATION);
    func_8029E070(1);
    func_802A3430();
    func_80293D74();
    func_80294378(1);
    roll_setIdeal(0.0f);
    pitch_setIdeal(0.0f);
    baphysics_reset_gravity();
    baphysics_reset_terminal_velocity();
    baModel_setYDisplacement(0.0f);
    basfx_80299CF4(SFX_31_BANJO_OHHWAAOOO, 1.0f, 0x7fff);
    basfx_80299D2C(SFX_61_CARTOONY_FALL, 1.0f, 0x7fff);
    D_8037D320 = 0.35f;
    D_8037D344 = 0;
}

void func_802A4548(void){
    s32 next_state = 0;
    f32 sp20[3];
    baphysics_get_velocity(sp20);
    switch(D_8037D344){
        case 0://L802A457C
            if(func_8028B254(0x5A)){
                baanim_playForDuration_onceStartingAt(ASSET_8_ANIM_BSJUMP, 2.0f, 0.6667f);
                D_8037D344 = 1;
            }
            break;
        case 1://L802A45A8
            break;
    }//L802A45A8
    D_8037D320 -= time_getDelta();
    if(D_8037D320 < 0.0f){
        D_8037D346 = 1;
        next_state = BS_24_FLY;
    }
    if(bainput_should_peck())
        next_state = BS_11_BPECK;

    if(bainput_should_beak_bust())
        next_state = BS_F_BBUSTER;

    if(player_isStable()){
        func_8029C5E8();
        next_state = BS_20_LANDING;
    }

    if(player_inWater())
        next_state = BS_2D_SWIM_IDLE;

    bs_setState(next_state);
}

void func_802A4664(void){
    s32 next_state;
    basfx_80299E6C();
    basfx_80299E90();
    next_state = bs_getNextState();
    if(next_state == BS_20_LANDING || next_state == BS_24_FLY || next_state == BS_2D_SWIM_IDLE){
        sfxsource_playHighPriority(SFX_3EA_UNKNOWN);
    }
    func_802A34C8();
    func_8029E070(0);
}

void func_802A46C8(void) {
    f32 phi_f20;

    for(phi_f20 = 0.0f; phi_f20 < 360.0f; phi_f20 += 45.0f){
        func_80292900(phi_f20, 230.0f);
    }
}


void bsbfly_beakbomb_crash_init(void) {
    baanim_playForDuration_once(ASSET_3E_ANIM_BSBFLY_BEAKBOMB_CRASH, 1.4f);
    func_8029C7F4(1, 1, 3, BA_PHYSICS_LOCKED_ROTATION);
    func_8029E070(1);
    FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 32750);
    basfx_80299CF4(SFX_36_BANJO_DOH, 1.0f, 28000);
    baMotor_80250D94(1.0f, 0.5f, 0.5f);
    item_dec(ITEM_14_HEALTH);
    func_802A46C8();
    baMarker_collisionOff();
    D_8037D344 = 0;
}

void func_802A47E0(void) {
    AnimCtrl *sp1C;

    sp1C = baanim_getAnimCtrlPtr();
    if (anctrl_isAt(sp1C, 0.3659f)) {
        FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 1.0f, 14000);
        basfx_80299CF4(SFX_8B_KAZOOIE_RAWW, 1.0f, 28000);
    }
    if (anctrl_isAt(sp1C, 0.6862f)) {
        FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 18000);
        basfx_80299CF4(SFX_38_BANJO_AYE_1, 1.0f, 22000);
    }
    if (anctrl_isAt(sp1C, 0.92f)) {
        baphysics_set_target_horizontal_velocity(0.0f);
    }
    if (anctrl_getAnimTimer(sp1C) < 0.8) {
        func_802929F8();
    }
}

void func_802A48B4(void) {
    s32 next_state;
    AnimCtrl *sp18;

    next_state = 0;
    sp18 = baanim_getAnimCtrlPtr();
    func_80299628(0);
    switch (D_8037D344) {
    case 0:
        func_802A47E0();
        if (anctrl_isAt(sp18, 0.2f) != 0) {
            if (item_getCount(ITEM_14_HEALTH) == 0) {
                func_8029C984();
                func_8029151C(0xD);
                ncDynamicCamD_func_802BF2C0(30.0f);
                func_8029B930();
                batimer_set(0, 2.5f);
                D_8037D344 = 2;
            }
        } else if (anctrl_isAt(sp18, 0.92f)) {
            baanim_playForDuration_once(ASSET_D2_ANIM_BSSPLAT, 2.25f);
            D_8037D344 = 1;
        }
        break;
    case 1:
        if (anctrl_isAt(sp18, 0.219f)) {
            basfx_80299CF4(SFX_36_BANJO_DOH, 1.0f, 16000);
        }
        if (anctrl_isAt(sp18, 0.63f)) {
            next_state = BS_20_LANDING;
        }
        if (anctrl_isStopped(sp18)) {
            next_state = BS_1_IDLE;
        }
        if (func_8028B094()) {
            next_state = BS_2F_FALL;
        }
        break;
    case 2:
        func_802A47E0();
        if (batimer_decrement(0)) {
            func_8029B890();
        }
        break;
    }
    bs_setState(next_state);
}


void func_802A4A40(void) {
    func_80291548();
    func_8029CB84();
    func_8029E070(0);
    baMarker_collisionOn();
}

void func_802A4A78(s32 arg0) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp2C;
    f32 sp28;
    f32 pad24;
    f32 sp20;

    if (arg0 == 0) {
        sp2C = -2200.0f;
        sp20 = 800.0f;
    } else {
        sp2C = -1200.0f;
        sp20 = 400.0f;
    }
    func_802BB3DC(2, 100.0f, 0.85f);
    baanim_playForDuration_onceSmooth(ASSET_D3_ANIM_BSBFLY_BEAKBOMB_REBOUND, 1.2f);
    basfx_playOwSfx(1.0f);
    baMotor_80250D94(1.0f, 0.5f, 0.5f);
    _player_getPosition(sp3C);
    func_80294980(sp30);
    func_80257F18(sp30, sp3C, &sp28);
    yaw_setIdeal(mlNormalizeAngle(sp28 + 180.0f));
    yaw_applyIdeal();
    baphysics_set_target_horizontal_velocity(sp20);
    baphysics_set_target_yaw(sp28);
    baphysics_set_horizontal_velocity(sp28, baphysics_get_target_horizontal_velocity());
    if ((arg0 == 1) && (map_get() == MAP_90_GL_BATTLEMENTS)) {
        yaw_setIdeal(mlNormalizeAngle(sp28));
        yaw_applyIdeal();
    }
    func_8029C7F4(1, 1, 2, BA_PHYSICS_LOCKED_ROTATION);
    baphysics_set_vertical_velocity(800.0f);
    baphysics_set_gravity(sp2C);
    baphysics_set_terminal_velocity(-4000.0f);
    func_8029E070(1);
    func_802914CC(4);
    ncDynamicCam4_func_802BFE50(12.0f, 10000.0f, 800.0f);
    baMarker_collisionOff();
    func_802A3430();
}

void func_802A4C34(s32 arg0) {
    s32 next_state;

    next_state = 0;
    if (anctrl_isStopped(baanim_getAnimCtrlPtr())) {
        next_state = BS_24_FLY;
    }
    if (player_isStable()) {
        next_state = BS_2_WALK_SLOW;
    }
    bs_setState(next_state);
}

void func_802A4C88(s32 arg0) {
    baphysics_reset();
    baMarker_collisionOn();
    func_80297CA8();
    func_8029E070(0);
    func_80291548();
    func_802A34C8();
}

void func_802A4CD0(void){
    func_802A4A78(0);
}

void func_802A4CF0(void){
    func_802A4C34(0);
}

void func_802A4D10(void){
    func_802A4C88(0);
}

void func_802A4D30(void){
    func_802A4A78(1);
}

void func_802A4D50(void){
    func_802A4C34(1);
}

void func_802A4D70(void){
    func_802A4C88(1);
}

void func_802A4D90(void) {
    f32 sp34;
    f32 player_position[3];
    f32 sp1C[3];

    func_802BB3DC(2, 100.0f, 0.85f);
    baanim_playForDuration_onceSmooth(0x10D, 1.0f);
    func_8030E58C(SFX_56_BANJO_HUI, 1.0f);
    _player_getPosition(player_position);
    func_80294980(sp1C);
    func_80257F18(sp1C, player_position, &sp34);
    yaw_setIdeal(mlNormalizeAngle(sp34 + 180.0f));
    yaw_applyIdeal();
    baphysics_set_target_horizontal_velocity(1300.0f);
    baphysics_set_target_yaw(sp34);
    baphysics_set_horizontal_velocity(sp34, baphysics_get_target_horizontal_velocity());
    if (map_get() == MAP_90_GL_BATTLEMENTS) {
        yaw_setIdeal(mlNormalizeAngle(sp34));
        yaw_applyIdeal();
    }
    func_8029C7F4(1, 1, 2, BA_PHYSICS_LOCKED_ROTATION);
    baphysics_set_vertical_velocity(400.0f);
    baphysics_set_gravity(-1800.0f);
    baMarker_collisionOff();
    func_802914CC(4);
    ncDynamicCam4_func_802BFE50(12.0f, 10000.0f, 800.0f);
}

void func_802A4EC8(void) {
    s32 next_state;
    AnimCtrl *sp18;

    next_state = 0;
    sp18 = baanim_getAnimCtrlPtr();
    if (player_isStable()) {
        next_state = BS_20_LANDING;
    }
    if (anctrl_isStopped(sp18) && (func_8028B094() || func_80294530())) {
        D_8037D346 = 1;
        next_state = BS_24_FLY;
    }
    bs_setState(next_state);
}

void func_802A4F44(void){
    baphysics_reset_gravity();
    baMarker_collisionOn();
    func_802A34C8();
}

void func_802A4F74(void) {
    baanim_playForDuration_loopSmooth(ASSET_38_ANIM_BSBFLY, 0.62f);
    func_8029C7F4(1, 1, 3, BA_PHYSICS_FREEZE);
    func_8029E070(1);
    func_802914CC(4);
    func_802A3430();
}

void func_802A4FC8(void) {
    s32 next_state;

    next_state = 0;
    if (anctrl_isAt(baanim_getAnimCtrlPtr(), 0.1358f) != 0) {
        func_8030EBC8(SFX_2_CLAW_SWIPE, 0.6f, 0.7f, 10000, 12000);
    }
    if (func_80298850() == 0) {
        next_state = BS_24_FLY;
    }
    bs_setState(next_state);
}

void func_802A503C(void){
    func_802A34C8();
}

void func_802A505C(void){
    if(bs_getInterruptType() == BS_INTR_9){
        func_8029A86C(2);
        miscFlag_set(MISC_FLAG_7);
        func_8029CCC4();
    }else{
        func_80296608();
    }
}

/* BREAK??? */
extern void baanim_playForDuration_loop(s32, f32);

/* .code */
void func_802A50B0(void){
    func_802A3430();
    bsdrone_init();
}

void func_802A50D8(void){
    bsdrone_update();
}

void func_802A50F8(void){
    bsdrone_end();
    func_802A34C8();
}

void func_802A5120(void){
    baanim_playForDuration_loop(ASSET_68_ANIM_BSJUMP_TUMBLE, 0.35f);
    func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);
    baphysics_set_target_horizontal_velocity(0.0f);
    baphysics_set_velocity(0);
    baphysics_set_vertical_velocity(2000.0f);
    basfx_80299CF4(SFX_63_BANJO_UWAAAAOOH, 1.0f, 32000);
}

void func_802A5190(void){
    baphysics_set_vertical_velocity(2000.0f);
    bs_setState(0);
}

void func_802A51C0(void){}
