#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/abilityprogress.h"

#include "core2/ba/anim.h"
#include "core2/ba/physics.h"

/* .bss */
u8  D_8037D3D0;
f32 D_8037D3D4;
u8  D_8037D3D8;

/* .code */
void func_802AB5C0(void){
    f32 sp2C[3];
    f32 sp28;
    f32 f2;

    sp28 = bastick_getY();
    if(mlAbsF(sp28) < 0.03){
        f2 = 0.0f; 
    }
    else{
        f2 = ml_mapAbsRange_f(sp28, 0.03f, 1.0f, 100.0f, 300.0f);
    }
    sp2C[0] = 0.0f;
    sp2C[1] = f2;
    sp2C[2] = 0.0f;
    baphysics_set_target_velocity(sp2C);
}

void func_802AB654(void){
    func_8029957C(6);
    yaw_setUpdateState(3);
    yaw_setVelocityBounded(500.0f, 15.0f);
    bastick_setZoneMax(0, 0.03f);
    bastick_setZoneMax(1, 1.0f);
    baphysics_set_type(BA_PHYSICS_CLIMB);
    baphysics_set_acceleration(10.0f);
    func_80294378(5);
    func_80293D48(80.0f, 10.0f);
    func_802914CC(0x10);
}

void func_802AB6F0(void){
    if(!bsclimb_inSet(bs_getNextState())){
        func_80291548();
        bastick_resetZones();
        baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
        baphysics_set_type(BA_PHYSICS_NORMAL);
        func_80294378(1);
        func_80293D74();
    }
}

void func_802AB750(f32 arg0, f32 arg1){
    D_8037D3D4 = randf()*arg1 + arg0;
}

int func_802AB788(void){    
    return (0.0f < mlAbsF(baphysics_get_target_vertical_velocity())) || (yaw_get() != yaw_getIdeal());
}

int bsclimb_inSet(s32 move_indx){
    return (move_indx == BS_4F_CLIMB_IDLE)
    || (move_indx == BS_50_CLIMB_MOVE)
    || (move_indx == 0x9e);
}

void bsclimb_idle_init(void){
    f32 angle_towards_pole;
    f32 plyr_pos[3];
    f32 pole_pos[3];

    player_getPosition(plyr_pos);
    climbGetBottom(pole_pos);
    if(!bsclimb_inSet(bs_getPrevState())){
        func_80257F18(plyr_pos, pole_pos, &angle_towards_pole);
        yaw_setIdeal(angle_towards_pole);
        yaw_applyIdeal();
    }
    ability_use(ABILITY_USED_CLIMB);
    baanim_playForDuration_loopSmooth(ASSET_B2_ANIM_BSCLIMB_IDLE_2, 2.64f);
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
    func_802AB654();
    
    D_8037D3D8 = 1;
    func_802AB750(1.0f, 0.5f);
    D_8037D3D0 = 0;
}

void bsclimb_idle_update(void){
    s32 next_state = 0;
    AnimCtrl *anim_ctrl = baanim_getAnimCtrlPtr();
    bafalldamage_start();
    switch(D_8037D3D0){
        case 0:
            D_8037D3D4 -= time_getDelta();
            if(D_8037D3D4 <= 0.0f){
                baanim_playForDuration_once(ASSET_B1_ANIM_BSCLIMB_IDLE_1, 2.96f);
                D_8037D3D0 = 1;
            }
            break;
        case 1:
            if(anctrl_isStopped(anim_ctrl)){
                baanim_playForDuration_loopSmooth(ASSET_B2_ANIM_BSCLIMB_IDLE_2, 2.64f);
                func_802AB750(3.0f, 4.0f);
                D_8037D3D0 = 0;
            }
            break;
    }
    func_802AB5C0();
    if(func_802AB788())
        next_state = BS_50_CLIMB_MOVE;
    

    if(bakey_pressed(BUTTON_A))
        next_state = BS_5_JUMP;

    if(D_8037D3D8 == 0)
        next_state = BS_1_IDLE;
    D_8037D3D8 = 0;
    bs_setState(next_state);
}

void bsclimb_idle_end(void){
    func_802AB6F0();
}

void bsclimb_move_init(void){
    baanim_playForDuration_loopSmooth(ASSET_A_ANIM_BSCLIMB_MOVE, 0.9f);
    baanim_setUpdateType(BAANIM_UPDATE_3_SCALE_VERT);
    baanim_setDurationRange(0.3f, 1.5f);
    baanim_setVelocityMapRanges(100.0f, 300.0f, 0.6f, 0.4f);
    func_802AB654();
}

void bsclimb_move_update(void){
    s32 next_state = 0;
    f32 plyr_pos[3];
    s32 map;

    bafalldamage_start();
    func_802AB5C0();
    map = gsworld_get_map();

    if( map == MAP_B_CC_CLANKERS_CAVERN
        || map == MAP_1B_MMM_MAD_MONSTER_MANSION
        || map == MAP_31_RBB_RUSTY_BUCKET_BAY
    ){
        if(baanim_isAt(0.25f))
            basfx_80299D2C(SFX_D2_QUIET_METALLIC, 1.1f, 32000);
        
        if(baanim_isAt(0.75f))
            basfx_80299D2C(SFX_D2_QUIET_METALLIC, 1.2f, 32000);
    }
    else{//L802ABB34
        if(baanim_isAt(0.25f))
            basfx_80299D2C(SFX_D3_JINXIE_SNIFFLING_1, 0.77f, 22000);

        if(baanim_isAt(0.75f))
            basfx_80299D2C(SFX_D3_JINXIE_SNIFFLING_1, 0.87f, 22000);
    }//L802ABB84

    if(!func_802AB788() && baphysics_get_vertical_velocity() < 30.0f)
        next_state = BS_4F_CLIMB_IDLE;

    _player_getPosition(plyr_pos);
    if(baphysics_get_target_vertical_velocity() < 0.0f && climbGetBottomY() == plyr_pos[1])
        next_state = BS_1_IDLE;

    if( func_8029825C() == 2
        && 0.0f < baphysics_get_target_vertical_velocity()
        && climbGetTopY() == plyr_pos[1]
    ){
        next_state = BS_51_CLIMB_EXIT;
    }

    if(bakey_pressed(BUTTON_A))
        next_state = BS_5_JUMP;

    if(!D_8037D3D8)
        next_state = BS_1_IDLE;
    
    D_8037D3D8 = FALSE;

    bs_setState(next_state);
}

void bsclimb_move_end(void){
    func_802AB6F0();
}

//bsclimb_unknown_9E_init
void func_802ABCCC(void){
    baanim_playForDuration_loopSmooth(ASSET_B2_ANIM_BSCLIMB_IDLE_2, 2.64f);
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
    func_802AB654();
    baphysics_set_type(BA_PHYSICS_FREEZE);
}

//bsclimb_unknown_9E_update
void func_802ABD0C(void){
    s32 next_state = 0;
    if(!balookat_getState())
        next_state = BS_4F_CLIMB_IDLE;

    bs_setState(next_state);
}

//bsclimb_unknown_9E_end
void func_802ABD40(void){
    func_802AB6F0();
}

//bsclimb_interrupt
void func_802ABD60(void){
    s32 next_state = 0;
    if(bs_getInterruptType() == BS_INTR_C_CLIMB){
        D_8037D3D8 = TRUE;
    }
    else{
        func_80296608();
        return;
    }
    bs_setInterruptResponse(1);
    bs_setState(next_state);
}
