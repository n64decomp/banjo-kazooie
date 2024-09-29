#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include <math.h>

extern f32 mapModel_getFloorY(f32[3]);
extern f32 func_80257204(f32, f32, f32, f32);

typedef enum {
    CH_BAT_STATE_ROOSTING = 1,
    CH_BAT_STATE_EXIT_ROOST = 2,
    CH_BAT_STATE_CHASE = 3,
    CH_BAT_STATE_ROAM = 4,
    CH_BAT_STATE_FLY_HOME = 5,
    CH_BAT_STATE_ENTER_ROOST = 6,
    CH_BAT_STATE_FALL = 7,
    CH_BAT_STATE_DIE = 8
} ChBatState;

typedef struct {
    f32 cooldown; //cooldown timer after attacking the player
    f32 roost_yaw;
} ChBatLocal;

void chbat_update(Actor *this);

/* .data */
ActorAnimationInfo sChBatAnimations[] = {
    {0, 0.0f},
    { ASSET_AE_ANIM_BAT_ROOST, 12.0f},
    { ASSET_AD_ANIM_BAT_TAKE_FLIGHT,  0.3f},
    { ASSET_9D_ANIM_BAT_FLY,  2.0f},
    { ASSET_9D_ANIM_BAT_FLY,  0.4f},
    { ASSET_9D_ANIM_BAT_FLY,  0.35f},
    { ASSET_AD_ANIM_BAT_TAKE_FLIGHT,  0.2f},
    { ASSET_2A9_ANIM_BAT_FALL,  0.4f},
    { ASSET_2AA_ANIM_BAT_DIE,  0.85f},
};

ActorInfo gChBat = { 
    MARKER_127_BAT, ACTOR_163_BAT, ASSET_3CA_MODEL_BAT, 
    CH_BAT_STATE_ROOSTING, sChBatAnimations, 
    chbat_update, func_80326224, actor_draw, 
    2500, 0, 0.9f, 0
};

/* .code */
void chbat_roost(Actor *this){
    subaddie_set_state(this, CH_BAT_STATE_ROOSTING);
    actor_loopAnimation(this);
}

void chbat_exitRoost(Actor *this){
    if(!volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)){
        subaddie_set_state_with_direction(this, CH_BAT_STATE_EXIT_ROOST, 0.01f, 1);
        actor_playAnimationOnce(this);
        this->actor_specific_1_f = 5.0f;
        FUNC_8030E8B4(SFX_419_UNKNOWN, 1.0f, 28000, this->position, 0x4e2, 0x9c4);
    }
}

void chbat_chase(Actor *this){
    subaddie_set_state(this, CH_BAT_STATE_CHASE);
    actor_loopAnimation(this);
    this->actor_specific_1_f = 5.0f;
}

void chbat_roam(Actor *this){
    subaddie_set_state(this, CH_BAT_STATE_ROAM);
    actor_loopAnimation(this);
}

void chbat_flyHome(Actor *this){
    ChBatLocal *local = (ChBatLocal *)&this->local;
    this->yaw_ideal = local->roost_yaw;
    subaddie_set_state(this, CH_BAT_STATE_FLY_HOME);
    actor_loopAnimation(this);
}

void chbat_enterRoost(Actor *this){
    subaddie_set_state_with_direction(this, CH_BAT_STATE_ENTER_ROOST, 0.99f, 0);
    actor_playAnimationOnce(this);
}

void chBat_fall(Actor *this){
    subaddie_set_state_with_direction(this, CH_BAT_STATE_FALL, 0.01f, 1);
    actor_loopAnimation(this);
    this->yaw += 180.0f;
    this->actor_specific_1_f = 20.0f;
    this->velocity_x = 300.0f;

}

int chbat_isWithinHorzontalRadiusOfHome(Actor * this, s32 dist){
    f32 f0 = this->position_x - this->unk1C_x;  
    f32 f2 = this->position_z - this->unk1C_z;  
    if(f0*f0 + f2*f2 < dist*dist)
        return 1;
    
    return 0;
}

bool chbat_nearHome(Actor *arg0, s32 arg1) {
    if( (arg0->position[1] < ( arg0->unk1C[1] + 0.5)) 
        && (( arg0->unk1C[1] - 0.5) < arg0->position[1])
    ) {
        return  func_80329480(arg0) != 0;
    }
    return FALSE;
}

void chBat_updateHeight(Actor *this, f32 target_height, f32 velocity){
    if(this->position[1] < target_height){
        this->position[1] += velocity;
        if(target_height < this->position[1]){
            this->position[1] = target_height;
        }
    }
    else if(target_height < this->position[1]){
        this->position[1] -= velocity;
        if(this->position[1] < target_height){
            this->position[1] = target_height;
        }
    }
}

bool func_8035FC98(Actor *this, f32 arg1){
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    if(this->unk38_0)
        return FALSE;

    TUPLE_COPY(sp28, this->position);
    TUPLE_COPY(sp1C, sp28);
    sp1C[1] += arg1;

    if (func_80309B48(sp28, sp1C, sp34, 0x5E0000) != NULL)
        return TRUE;
    return FALSE;

}

bool func_8035FD28(Actor *this){
    this->velocity[0] -= 2.5;
    if(func_8035FC98(this, this->velocity[0]*2)){
        return FALSE;
    }
    this->position[1] += this->velocity[0];
    return TRUE;
}

bool chbat_nearPlayer(Actor *this) {
    f32 sp24[3];

    player_getPosition(sp24);
    sp24[1] += 50.0f;
    if (this->unk38_0){
        if(!func_80329260(this, sp24)){
            return FALSE;
        }
    } else{
        if(!func_80329210(this, sp24)){
            return FALSE;
        }
    }

    if (this->unk38_31 != 0) {
        if (func_80329530(this, 0) && (sp24[1] <= (this->unk1C[1] - 40.0f))) {
            return TRUE;
        }
        this->unk38_31--;
        return FALSE;
    }
    if (func_80329530(this, 800) && (sp24[1] <= (this->unk1C[1] - 40.0f))) {
        return TRUE;
    }

    return FALSE;
}

bool func_8035FEDC(Actor *this){
    if(func_8032CA80(this, this->unk38_0?0x13:4)){
        if(this->unk38_0){
            return FALSE;
        }
        
        if(func_80329480(this)){
            this->actor_specific_1_f = 0.0f;
            return FALSE;
        }
    }
    return TRUE;
}

bool func_8035FF5C(Actor *this){
    if(func_8032CA80(this, 5) && func_80329480(this)){
        this->actor_specific_1_f = 0.0f;
        return FALSE;
    }
    return TRUE;
}

void func_8035FFAC(Actor *this, f32 arg1){
    if(arg1 < 0.0f && randf() < 0.82){
        this->velocity_y = 0.0f;
    }
    else if(randf() < 0.92){
        this->velocity_y = 1.0f;
    }
}

void chbat_updateFlyingRoll(Actor *this) {
    f32 d_yaw;

    d_yaw = this->yaw_ideal - this->yaw;
    if (d_yaw >= 180.0f) {
        d_yaw -= 360.0f;
    }
    if (d_yaw < -180.0f) {
        d_yaw += 360.0f;
    }
    this->velocity[2] = -d_yaw;
    if (( this->roll <  this->velocity[2]) && ( this->roll < 55.0f)) {
        this->roll += 2.0f;
    }
    if ((this->velocity[2] < this->roll) && (this->roll > -55.0f)) {
        this->roll -= 2.0f;
    }
}

void chbat_updateRollTowardsZero(Actor *this){
    if(0.0f < this->roll){
        this->roll -= 2.0;
    }
    else if(this->roll < 0.0f){
        this->roll += 2.0;
    }
}

bool func_80360198(Actor *this) {
    f32 var_f16;
    f64 temp_f0;
    f64 d_yaw;
    f64 d_yaw_2;

    func_80328FB0(this, 5.0f);
    chbat_updateFlyingRoll(this);
    this->actor_specific_1_f += (this->velocity[1] * 0.45) - (0.001 * this->actor_specific_1_f);
    if (this->actor_specific_1_f > 13.0) {
        this->actor_specific_1_f = 13.0f;
    }
    if (this->actor_specific_1_f < -13.0) {
        this->actor_specific_1_f = -13.0f;
    }

    this->velocity[0] += ((this->velocity[1] * 0.9) - 0.6);
    if (this->velocity[0] > 6.0) {
        this->velocity[0] = 6.0f;
    }
    if (this->velocity[0] < -6.0) {
        this->velocity[0] = -6.0f;
    }

    if (func_8035FC98(this, 2 * this->velocity[0]) == 0) {
        this->position[1] += this->velocity[0];
    } else {
        this->velocity[0] *= -3.0f;
        this->position[1] += this->velocity[0];
    }

    if (this->state == 4) {
        if (func_8035FF5C(this) == 0) {
            return FALSE;
        }
    } else if (func_8035FEDC(this) == 0) {
        return FALSE;
    }
    return TRUE;
}

f32 func_803603AC(Actor *this, s32 arg1, u8 arg2){
    f32 phi_f2;
    f32 dy;
    f32 D1, D2;
    f32 unused;
    f32 player_position[3];

    switch (arg2) {
    case 1:
        player_getPosition(player_position);
        break;

    case 2:
        TUPLE_COPY(player_position, this->unk1C);
        break;
    }

    D1 = SQ(this->position[0] - player_position[0]);
    D2 = SQ(this->position[2] - player_position[2]);
    
    dy = this->position[1] - player_position[1] - arg1;
    
    if(dy == 0.0 || D1 + D2 == 0.0)
        return 0.0f;
    
        
    phi_f2 = -(this->actor_specific_1_f*(dy))/(D1 + D2);
    if (phi_f2 >= 4.0f) {
        phi_f2 = 4.0f;
    } else  if (phi_f2 <= -4.0f) {
        phi_f2 = -4.0f;
    }
    return phi_f2;
}

int func_803604E8(Actor *this){
    f32 tmp_f0;
    this->yaw_ideal = (f32) func_80329784(this);
    tmp_f0 = func_803603AC(this, 170, 1);
    func_8035FFAC(this, tmp_f0);
    if(!func_80360198(this)){
        return 0;
    }
    return 1;
}

bool chbat_updateRoam(Actor *this) {
    s32 phi_v0;
    s32 phi_s1;
    s32 phi_s2;

    if (this->lifetime_value == 0.0f) {
        // fly towards home if lifetime is done 
        this->yaw_ideal = func_80257204(this->position[0], this->position[2], this->unk1C[0], this->unk1C[2]);
        func_8035FFAC(this, func_803603AC(this, -110, 2));
    }
    else{
        func_80328FB0(this, 5.0f); //update yaw
        chbat_updateFlyingRoll(this);
        if (func_80329480(this) != 0) {
            this->lifetime_value = 0.0f;
        } else {
            return TRUE;
        }
    }
    for(phi_s2 = 0; !func_80360198(this) && phi_s2 < 1; phi_s2++){
        this->lifetime_value = 45.0f;
        func_80328CEC(this, (s32) this->yaw, 90, 180);
        phi_s1 = 0;
        do{
            if (this->unk38_0) {
                phi_v0 = func_80329140(this, (s32) this->yaw_ideal, 200);
            } else {
                phi_v0 = func_80329078(this, (s32) this->yaw_ideal, 200);
            }

            if(phi_v0 == 0){
                phi_s1++;
                this->yaw_ideal += 30.0f;
                if (this->yaw_ideal >= 360.0f) {
                    this->yaw_ideal -= 360.0f;
                }
            }
        } while ( phi_v0 == 0 && phi_s1 < 0xC);
    }
    if (this->position[1] < (this->unk1C[1] + -110.0f)) {
        this->velocity[1] = 1.0f;
    } else {
        this->velocity[1] = (f32) randi2(0, 0);
    }
    if (this->position[1] <= mapModel_getFloorY(this->position)) {
        this->velocity[0] = 3.0f;
    }
    return TRUE;
}

void chBat_dieCollision(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    ChBatLocal *local = (ChBatLocal *)&this->local;
    chBat_fall(this);
    local->cooldown = 0.0f;
    this->marker->collidable = FALSE;
    FUNC_8030E8B4(SFX_115_BUZZBOMB_DEATH, 1.3f, 26000, this->position, 1250, 2500);
}

void chBat_attackCollision(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    ChBatLocal *local = (ChBatLocal *)&this->local;
    local->cooldown = 0.8f;
}

void chbat_update(Actor *this){
    f32 dt = time_getDelta();
    ChBatLocal *local = (ChBatLocal *)&this->local;
    f32 sp34;

    if(!this->initialized){
        this->initialized = TRUE;
        marker_setCollisionScripts(this->marker, NULL, chBat_attackCollision, chBat_dieCollision);
        this->unk38_0 = FALSE;
        this->actor_specific_1_f = 0.0f;
        this->velocity_x = 0.0f;
        TUPLE_COPY(this->unk1C, this->position); // set roost position
        local->roost_yaw = this->yaw;
    }
    if(local->cooldown <= 0.0){
        local->cooldown = 0.0f;
    }else{//L80360910
        local->cooldown -= dt;
        return;
    }

    switch(this->state){
        case CH_BAT_STATE_ROOSTING: //L80360918
            if(chbat_nearPlayer(this)){
                chbat_exitRoost(this);
            }
            break;
        case CH_BAT_STATE_EXIT_ROOST: //L80360938
            if( 0.98 <  animctrl_getAnimTimer(this->animctrl)
                || !func_8035FD28(this)
            ){
                chbat_chase(this);
            }
            break;
        case CH_BAT_STATE_CHASE: //L8036097C
            animctrl_setDuration(this->animctrl, 1.2 - this->velocity_y);
            if(!chbat_nearPlayer(this)){
                chbat_roam(this);
            }
            else if(!func_803604E8(this)){
                chbat_roam(this);
                this->unk38_31 = 0x3C;
            }
            else{
                if(!(globalTimer_getTime() & 0xf)){
                    if(randf() < 0.35){
                        FUNC_8030E8B4(SFX_419_UNKNOWN, 1.0f, 28000, this->position, 1250, 2500);
                    }
                }
            }//L80360A40
            if(actor_animationIsAt(this, 0.5f)){
                func_8030E878(SFX_2_CLAW_SWIPE, randf2(1.0f, 1.2f), 10000, this->position, 833.0f, 2500.0f);
            }
            break;
        case CH_BAT_STATE_ROAM: //L80360A9C
            if(chbat_nearPlayer(this)){
                chbat_chase(this);
            } else if(chbat_isWithinHorzontalRadiusOfHome(this, 20)){
                chbat_flyHome(this);
            } else{
                chbat_updateRoam(this);
            }//L80360AE8

            if(actor_animationIsAt(this, 0.5f)){
                func_8030E878(SFX_2_CLAW_SWIPE, randf2(1.0f, 1.2f), 10000, this->position, 833.0f, 2500.0f);
            }
            break;
        case CH_BAT_STATE_FLY_HOME: //L80360B3C
            if(chbat_nearPlayer(this)){
                chbat_chase(this);
            } else if(chbat_nearHome(this, 1)){
                chbat_enterRoost(this);
            } else{
                func_80328FB0(this, 5.0f);
                chBat_updateHeight(this, this->unk1C_y, 2.0f);
                chbat_updateRollTowardsZero(this);
            }

            if(actor_animationIsAt(this, 0.5f)){
                func_8030E878(SFX_2_CLAW_SWIPE, randf2(1.0f, 1.2f), 10000, this->position, 833.0f, 2500.0f);
            }
            break;
        case CH_BAT_STATE_ENTER_ROOST:
            if(animctrl_getAnimTimer(this->animctrl) < 0.01){
                chbat_roost(this);
            }
            break;
        case CH_BAT_STATE_FALL: //L80360C28
            sp34 = time_getDelta();
            func_8032CA80(this, this->unk38_0 ? 0x13 : 0x4);
            if(func_8035FC98(this, this->velocity_x * sp34)){
                this->position_y =  mapModel_getFloorY(this->position);
                subaddie_set_state_with_direction(this, CH_BAT_STATE_DIE, 0.01f, 1);
                actor_playAnimationOnce(this);
                func_8030E6A4(SFX_1F_HITTING_AN_ENEMY_3, 1.2f, 32200);
            }
            else{//L80360CC4
                this->position_y += this->velocity_x * sp34;
                this->velocity_x -=  1600.0f * sp34;
            }
            break;
        case CH_BAT_STATE_DIE: //L80360CF0
            if(actor_animationIsAt(this, 0.3f)){
                func_80326310(this);
            }
            break;
    }
}
