#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void func_80354030(f32[3], f32);
extern void func_8028FDC8(f32);
extern f32 func_8029B2D0(void);
extern void func_802921BC(f32);


/* .data */
extern u8 D_803754FC[];
extern f32 D_80375508;
extern f32 D_8037550C;
extern f32 D_80375510;
extern f32 D_80375514;
extern f32 D_80375518;
extern f32 D_8037551C;
extern f32 D_80375534;
/* .bss */
extern f32 D_8037D320;
extern f32 D_8037D324;
extern f32 D_8037D328[3];
extern f32 D_8037D338[3];
extern u8 D_8037D344;
extern u8 D_8037D345;
extern u8 D_8037D346;
extern u8 D_8037D347;

/* .code */
int func_802A3350(void){
    if(!func_8028B2E8()) 
        return 0;
    if(func_80294684() & 8){
        return 0;
    }
    return 1;
}

void func_802A339C(f32 arg0[3], f32 arg1[3], f32 arg2){
    func_8024C5A8(arg0);
    ml_vec3f_scale(arg0, arg2);
    func_8024C764(arg1);
}

void func_802A33D8(void){
    pitch_setAngVel(500.0f, D_80375508);
}

void func_802A3404(void){
    pitch_setAngVel(1000.0f, D_8037550C);
}

void func_802A3430(void){
    func_802921BC(60.0f);
    func_802991A8(3);
    func_80299234(500.0f, 2.0f);
    roll_setAngularVelocity(500.0f, 2.0f);
    func_802A33D8();
    func_80293D48(60.0f, 45.0f);
    func_80294378(4);
    func_8028FEF0();
    func_8028FFBC(1);
}

void func_802A34C8(void){
    if(!bsbfly_inSet(bs_getNextState())){
        gravity_reset();
        func_80297B94();
        func_8029E070(0);
        func_802921BC(0.0f);
        func_8029CB84();
        func_802991A8(1);
        func_80291548();
        func_80293D74();
        func_80294378(1);
        func_8028FFBC(0);
    }
}

void func_802A354C(void){
    f32 yaw_range;
    f32 roll_range;
    f32 sp2C; 

    sp2C = func_8029B2D0();
    if(button_held(BUTTON_R)){
        func_80299234(500.0f, 30.0f);
        yaw_range = 6.0f;
        roll_range = 85.0f;
    }
    else{
        func_80299234(500.0f, 2.0f);
        yaw_range = 3.0f;
        roll_range = 75.0f;
    }
    roll_setIdeal(ml_map_f(sp2C, -1.0f, 1.0f, -roll_range, roll_range));
    yaw_setIdeal(mlNormalizeAngle(yaw_getIdeal() + ml_map_f(sp2C, -1.0f, 1.0f, yaw_range, -yaw_range)));
}

void func_802A3648(void){
    f32 tmp_f0 = func_8029B2DC();

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
        || arg0 == BS_BOMB_END
        || arg0 == BS_FLY_KNOCKBACK
        || arg0 == BS_59_BFLY_UNK59
        || arg0 == BS_FLY_OW
        || arg0 == BS_BFLY_UNK76
        || arg0 == BS_24_FLY
        || arg0 == BS_BFLY_UNK99;
}

int func_802A37F8(void){
    return bsbfly_inSet(bs_getState());
}

void bsbfly_enter_init(void){
    func_8028A274(ANIM_BANJO_FLY_ENTER, 1.4f);
    func_8029C7F4(1,1,3,6);
    if(func_8029B2E8() != 0.0f)
        yaw_setIdeal(func_8029B33C());
    
    func_8029797C(yaw_getIdeal());
    func_80297A0C(0);
    func_80297970(0.0f);
    gravity_set(-1200.0f);
    func_8029E070(1);
    func_80299BD4();
    D_8037D344 = 0;
    D_8037D346 = 0;
}

void bsbfly_enter_update(void){
    enum bs_e sp1C = 0;
    AnimCtrl * aCtrl = _player_getAnimCtrlPtr();

    switch(D_8037D344){
    case 0:
        if(animctrl_isAt(aCtrl, 0.2416f)){
            animctrl_setDuration(aCtrl, 2.4f);
            player_setYVelocity(1600.0f);
            func_8030E58C(SFX_C_TAKING_FLIGHT_LIFTOFF, 0.7f);
            D_8037D344 = 1;
        }
        break;
    default:
        func_802A36D0();
        if(func_80297AAC() < 0.0f)
            sp1C = BS_24_FLY;
        break;
    }

    bs_setState(sp1C);
}

void bsbfly_enter_end(void){
    func_80295610(8);
    func_8029E070(0);
}

void bsbfly_init(void){
    func_8028A010(ANIM_BANJO_FLY, 0.62f);
    func_8029C7F4(1,1,3,3);
    if(func_802933C0(9)){
        func_80297970(0.0f);
    }else{
        func_80297970(600.0f);
    }

    func_802979AC(yaw_getIdeal(), func_80297A64());
    func_8029797C(yaw_getIdeal());
    func_8029E070(1);
    gravity_set(-300.0f);
    func_80297BF8(D_80375510);
    func_802914CC(4);
    func_802A3430();
    D_8037D320 = 1.0f;
    D_8037D344 = 0;
    D_8037D347 = 0;
}

void bsbfly_update(void){
    enum bs_e sp54 = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    int sp4C;
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
    if(button_pressed(BUTTON_A))
        D_8037D347 = 1;

    if(D_8037D347 && func_8023DB5C()%3 == 0){
        D_8037D347 = 0;
        func_80346C10(&sp2C, 0, BS_1_IDLE, ITEM_F_RED_FEATHER, 1);
    }

    if(sp2C || D_8037D346){
        if(sp2C){
            animctrl_setDuration(aCtrl, 0.3f);
            func_802D8BE4(0);
        }
        if(D_8037D346){
            D_8037D346 = 0;
            func_8028FDC8(D_80375514);
        }else{
            func_8028FDC8(1.0f);
        }
    }//L802A3BB4

    sp30 = func_8028FD30();
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
                player_setYVelocity(sp30 * 400.0);
            }
            if(!sp30){
                animctrl_setDuration(aCtrl, 0.62f);
                func_802A33D8();
                D_8037D344 = 0;
            }
            break;
    }//L802A3CB8
    if(animctrl_isAt(aCtrl, 0.1358f)){
        func_8030EBC8(SFX_2_CLAW_SWIPE, 0.6f, 0.7f, 0x2710, 0x2ee0);
    }
    gravity_set(-300.0f);
    if(func_802933C0(9)){
        func_80297BF8(0.0f);
        func_80297A0C(0);
        sp38 = 0.0f;
    }
    else if(sp3C <= 80.0f){
        func_80297BF8(ml_map_f(sp3C, 60.0f, 80.0f, -99.9f, D_80375518));
        gravity_set(ml_map_f(sp3C, 60.0f, 80.0f, -300.0f, -700.0f));
        sp38 = ml_map_f(sp3C, 60.0f, 80.0f, 600.0f, 60.0f);
    }
    else{
        func_80297BF8(ml_map_f(sp3C, 300.0f, 310.0f, -399.99f, D_8037551C));
        sp38 = ml_map_f(sp3C, 300.0f, 340.0f, 0.0f, 600.0f);
    }//L802A3E18

    sp4C = func_802946F0();
    func_8029445C(sp40);

    if(sp4C && -1.0 < sp40[1])
        sp38 = 0.0f;

    func_8029797C(yaw_get());
    func_80297970(sp38);

    if(should_beak_bust())
        sp54 = BS_F_BBUSTER;

    D_8037D320 = max_f(D_8037D320 - time_getDelta(), 0.0f);
    if( D_8037D320 == 0.0f
        && button_pressed(BUTTON_B)
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

    func_8028FFF0();
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
    func_8028A180(ASSET_43_ANIM_BANJO_BEAKBOMB_START, 1.0f);
    func_8029C7F4(1,1,3,7);
    func_802A339C(D_8037D338, sp1C, 4200.0f);
    yaw_setIdeal(sp1C[1] + 180.0f);
    pitch_setIdeal(sp1C[0]);
    roll_setIdeal(0.0f);
    func_80297A0C(D_8037D338);
    pitch_setIdeal(sp1C[0]);
    func_8029E070(1);
    func_802914CC(4);
    func_802BFE74(1);
    func_802A3430();
    FUNC_8030E624(SFX_52_BANJO_YAH_OH, 0x36B, 0x3ff);
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
    func_80345F44(ITEM_14_HEALTH);
    if(item_getCount(ITEM_14_HEALTH))
        return BS_59_BFLY_UNK59;
    else
        return BS_41_DIE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A411C.s")

void func_802A4404(void){
    func_80299E6C();
    D_8037D345 = 0;
    func_802A34C8();
}

void func_802A4430(void){
    AnimCtrl *plyr_animctrl;

    plyr_animctrl = _player_getAnimCtrlPtr();
    animctrl_reset(plyr_animctrl);
    animctrl_setTransitionDuration(plyr_animctrl, 0.3f);
    animctrl_setIndex(plyr_animctrl, ASSET_CC_ANIM_BANJO_BEAKBOMB_END);
    animctrl_setDuration(plyr_animctrl, 0.38f);
    animctrl_setPlaybackType(plyr_animctrl, ANIMCTRL_LOOP);
    func_802875AC(plyr_animctrl, D_803754FC, 0x38a);
    func_8029C7F4(1, 1, 3, 3);
    func_8029E070(1);
    func_802A3430();
    func_80293D74();
    func_80294378(1);
    roll_setIdeal(0.0f);
    pitch_setIdeal(0.0f);
    gravity_reset();
    func_80297B94();
    func_802921BC(0.0f);
    func_80299CF4(SFX_31_BANJO_OHHWAAOOO, 1.0f, 0x7fff);
    func_80299D2C(SFX_61_CARTOONY_FALL, 1.0f, 0x7fff);
    D_8037D320 = D_80375534;
    D_8037D344 = 0;
}

void func_802A4548(void){
    s32 next_state = 0;
    f32 sp20[3];
    _get_velocity(sp20);
    switch(D_8037D344){
        case 0://L802A457C
            if(func_8028B254(0x5A)){
                func_8028A1F4(8, 2.0f, 0.6667f);
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
    if(should_peck())
        next_state = BS_11_BPECK;

    if(should_beak_bust())
        next_state = BS_F_BBUSTER;

    if(func_8028B2E8()){
        func_8029C5E8();
        next_state = BS_20_LANDING;
    }

    if(player_inWater())
        next_state = BS_2D_SWIM_IDLE;

    bs_setState(next_state);
}

void func_802A4664(void){
    s32 next_state;
    func_80299E6C();
    func_80299E90();
    next_state = bs_getNextState();
    if(next_state == BS_20_LANDING || next_state == BS_24_FLY || next_state == BS_2D_SWIM_IDLE){
        func_8030E484(SFX_3EA_UNKNOWN);
    }
    func_802A34C8();
    func_8029E070(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A46C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A47E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A48B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4A40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4A78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4CD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4CF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4D10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4D30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4D50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4D90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4F44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4FC8.s")

void func_802A503C(void){
    func_802A34C8();
}

void func_802A505C(void){
    if(bs_getInterruptType() == 9){
        func_8029A86C(2);
        func_802933E8(7);
        func_8029CCC4();
    }else{
        func_80296608();
    }
}

/* BREAK??? */
extern void func_8028A084(s32, f32);

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
    func_8028A084(0x68, 0.35f);
    func_8029C7F4(1,1,3,6);
    func_80297970(0.0f);
    func_80297A0C(0);
    player_setYVelocity(2000.0f);
    func_80299CF4(SFX_63_BANJO_UWAAAAOOH, 1.0f, 32000);
}

void func_802A5190(void){
    player_setYVelocity(2000.0f);
    bs_setState(0);
}

void func_802A51C0(void){}
