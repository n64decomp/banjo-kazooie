#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 func_80309724(f32[3]);
extern f32 func_80257204(f32, f32, f32, f32);

typedef struct {
    f32 unk0;
    f32 unk4;
} ActorLocal_Core2_D89E0;

void func_80360828(Actor *this);

/* .data */
extern ActorAnimationInfo D_80373090[];
extern ActorInfo D_803730D8 = { 
    MARKER_127_BAT, ACTOR_163_BAT, ASSET_3CA_MODEL_BAT, 
    0x1, D_80373090, 
    func_80360828, func_80326224, func_80325888, 
    2500, 0, 0.9f, 0
};

/* .code */
void func_8035F970(Actor *this){
    func_80328A84(this, 1);
    actor_loopAnimation(this);
}

void func_8035F99C(Actor *this){
    if(!func_803203FC(UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE)){
        func_80328B8C(this, 2, 0.01f, 1);
        actor_playAnimationOnce(this);
        this->unk28 = 5.0f;
        FUNC_8030E8B4(SFX_419_UNKNOWN, 1.0f, 28000, this->position, 0x4e2, 0x9c4);
    }
}

void func_8035FA0C(Actor *this){
    func_80328A84(this, 3);
    actor_loopAnimation(this);
    this->unk28 = 5.0f;
}

void func_8035FA48(Actor *this){
    func_80328A84(this, 4);
    actor_loopAnimation(this);
}

void func_8035FA74(Actor *this){
    ActorLocal_Core2_D89E0 *local = (ActorLocal_Core2_D89E0 *)&this->local;
    this->yaw_moving = local->unk4;
    func_80328A84(this, 5);
    actor_loopAnimation(this);
}

void func_8035FAA8(Actor *this){
    func_80328B8C(this, 6, 0.99f, 0);
    actor_playAnimationOnce(this);
}

void func_8035FAE0(Actor *this){
    func_80328B8C(this, 7, 0.01f, 1);
    actor_loopAnimation(this);
    this->yaw += 180.0f;
    this->unk28 = 20.0f;
    this->velocity_x = 300.0f;

}

int func_8035FB48(Actor * this, s32 dist){
    f32 f0 = this->position_x - this->unk1C_x;  
    f32 f2 = this->position_z - this->unk1C_z;  
    if(f0*f0 + f2*f2 < dist*dist)
        return 1;
    
    return 0;
}

bool func_8035FBA8(Actor *arg0, s32 arg1) {
    if( (arg0->position[1] < ( arg0->unk1C[1] + 0.5)) 
        && (( arg0->unk1C[1] - 0.5) < arg0->position[1])
    ) {
        return  func_80329480(arg0) != 0;
    }
    return FALSE;
}

void func_8035FC20(Actor *this, f32 arg1, f32 arg2){
    if(this->position[1] < arg1){
        this->position[1] += arg2;
        if(arg1 < this->position[1]){
            this->position[1] = arg1;
        }
    }
    else if(arg1 < this->position[1]){
        this->position[1] -= arg2;
        if(this->position[1] < arg1){
            this->position[1] = arg1;
        }
    }
}

bool func_8035FC98(Actor *this, f32 arg1){
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    if(this->unk38_0)
        return FALSE;

    sp28[0] = this->position[0];
    sp28[1] = this->position[1];
    sp28[2] = this->position[2];

    sp1C[0] = sp28[0];
    sp1C[1] = sp28[1];
    sp1C[2] = sp28[2];
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

bool func_8035FDA4(Actor *this) {
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
            this->unk28 = 0.0f;
            return FALSE;
        }
    }
    return TRUE;
}

bool func_8035FF5C(Actor *this){
    if(func_8032CA80(this, 5) && func_80329480(this)){
        this->unk28 = 0.0f;
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

void func_80360044(Actor *this) {
    f32 var_f0;

    var_f0 = this->yaw_moving - this->yaw;
    if (var_f0 >= 180.0f) {
        var_f0 -= 360.0f;
    }
    if (var_f0 < -180.0f) {
        var_f0 += 360.0f;
    }
    this->velocity[2] = -var_f0;
    if (( this->roll <  this->velocity[2]) && ( this->roll < 55.0f)) {
        this->roll += 2.0f;
    }
    if ((this->velocity[2] < this->roll) && (this->roll > -55.0f)) {
        this->roll -= 2.0f;
    }
}

void func_80360130(Actor *this){
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
    f64 var_f0;
    f64 var_f0_2;

    func_80328FB0(this, 5.0f);
    func_80360044(this);
    this->unk28 += (this->velocity[1] * 0.45) - (0.001 * this->unk28);
    if (this->unk28 > 13.0) {
        this->unk28 = 13.0f;
    }
    if (this->unk28 < -13.0) {
        this->unk28 = -13.0f;
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

#ifndef NONMATCHING
f32 func_803603AC(Actor *this, s32 arg1, u8 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D89E0/func_803603AC.s")
#else
f32 func_803603AC(Actor *this, s32 arg1, u8 arg2){
    f32 num;
    f32 den;
    f32 phi_f2;
    f32 sp2C[3];
    f32 sp20[3];

    switch (arg2) {
    case 1:
        player_getPosition(sp20);
        break;

    case 2:
        sp20[0] = this->unk1C[0];
        sp20[1] = this->unk1C[1];
        sp20[2] = this->unk1C[2];
        break;
    }

    sp2C[0] = (this->position[0] - sp20[0]);
    sp2C[1] = (this->position[1] - sp20[1]);
    sp2C[2] = (this->position[2] - sp20[2]);

    den =(sp2C[0]*sp2C[0] + sp2C[2]*sp2C[2]);
    // if(den);
    num = (sp2C[1] - arg1);
    if(num == 0.0 || den == 0.0)
        return 0.0f;
        
    phi_f2 = -(this->unk28*num)/den;
    if (phi_f2 >= 4.0f) {
        return 4.0f;
    }
    if(-4.0f >= phi_f2) 
        phi_f2 = -4.0f; 
    return phi_f2;
}
#endif

int func_803604E8(Actor *this){
    f32 tmp_f0;
    this->yaw_moving = (f32) func_80329784(this);
    tmp_f0 = func_803603AC(this, 170, 1);
    func_8035FFAC(this, tmp_f0);
    if(!func_80360198(this)){
        return 0;
    }
    return 1;
}

bool func_8036054C(Actor *this) {
    s32 phi_v0;
    s32 phi_s1;
    s32 phi_s2;

    if (this->unk60 == 0.0f) {
        this->yaw_moving = func_80257204(this->position[0], this->position[2], this->unk1C[0], this->unk1C[2]);
        func_8035FFAC(this, func_803603AC(this, -110, 2));
    }
    else{
        func_80328FB0(this, 5.0f);
        func_80360044(this);
        if (func_80329480(this) != 0) {
            this->unk60 = 0.0f;
        } else {
            return TRUE;
        }
    }
    for(phi_s2 = 0; !func_80360198(this) && phi_s2 < 1; phi_s2++){
        this->unk60 = 45.0f;
        func_80328CEC(this, (s32) this->yaw, 90, 180);
        phi_s1 = 0;
        do{
            if (this->unk38_0) {
                phi_v0 = func_80329140(this, (s32) this->yaw_moving, 0xC8);
            } else {
                phi_v0 = func_80329078(this, (s32) this->yaw_moving, 0xC8);
            }

            if(phi_v0 == 0){
                phi_s1++;
                this->yaw_moving += 30.0f;
                if (this->yaw_moving >= 360.0f) {
                    this->yaw_moving -= 360.0f;
                }
            }
        } while ( phi_v0 == 0 && phi_s1 < 0xC);
    }
    if (this->position[1] < (this->unk1C[1] + -110.0f)) {
        this->velocity[1] = 1.0f;
    } else {
        this->velocity[1] = (f32) randi2(0, 0);
    }
    if (this->position[1] <= func_80309724(this->position)) {
        this->velocity[0] = 3.0f;
    }
    return TRUE;
}

void func_80360790(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    ActorLocal_Core2_D89E0 *local = (ActorLocal_Core2_D89E0 *)&this->local;
    func_8035FAE0(this);
    local->unk0 = 0.0f;
    this->marker->collidable = FALSE;
    FUNC_8030E8B4(SFX_115_BUZZBOMB_DEATH, 1.3f, 26000, this->position, 1250, 2500);
}

void func_803607FC(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    ActorLocal_Core2_D89E0 *local = (ActorLocal_Core2_D89E0 *)&this->local;
    local->unk0 = 0.8f;
}

void func_80360828(Actor *this){
    f32 sp3C = time_getDelta();
    ActorLocal_Core2_D89E0 *local = (ActorLocal_Core2_D89E0 *)&this->local;
    f32 sp34;

    if(!this->initialized){
        this->initialized = TRUE;
        marker_setCollisionScripts(this->marker, NULL, func_803607FC, func_80360790);
        this->unk38_0 = FALSE;
        this->unk28 = 0.0f;
        this->velocity_x = 0.0f;
        this->unk1C_x = this->position_x;
        this->unk1C_y = this->position_y;
        this->unk1C_z = this->position_z;
        local->unk4 = this->yaw;
    }
    if(local->unk0 <= 0.0){
        local->unk0 = 0.0f;
    }else{//L80360910
        local->unk0 -= sp3C;
        return;
    }

    switch(this->state){
        case 1: //L80360918
            if(func_8035FDA4(this)){
                func_8035F99C(this);
            }
            break;
        case 2: //L80360938
            if( 0.98 <  animctrl_getAnimTimer(this->animctrl)
                || !func_8035FD28(this)
            ){
                func_8035FA0C(this);
            }
            break;
        case 3: //L8036097C
            animctrl_setDuration(this->animctrl, 1.2 - this->velocity_y);
            if(!func_8035FDA4(this)){
                func_8035FA48(this);
            }
            else if(!func_803604E8(this)){
                func_8035FA48(this);
                this->unk38_31 = 0x3C;
            }
            else{
                if(!(func_8023DB5C() & 0xf)){
                    if(randf() < 0.35){
                        FUNC_8030E8B4(SFX_419_UNKNOWN, 1.0f, 28000, this->position, 1250, 2500);
                    }
                }
            }//L80360A40
            if(actor_animationIsAt(this, 0.5f)){
                func_8030E878(SFX_2_CLAW_SWIPE, randf2(1.0f, 1.2f), 10000, this->position, 833.0f, 2500.0f);
            }
            break;
        case 4: //L80360A9C
            if(func_8035FDA4(this)){
                func_8035FA0C(this);
            } else if(func_8035FB48(this, 0x14)){
                func_8035FA74(this);
            } else{
                func_8036054C(this);
            }//L80360AE8

            if(actor_animationIsAt(this, 0.5f)){
                func_8030E878(SFX_2_CLAW_SWIPE, randf2(1.0f, 1.2f), 10000, this->position, 833.0f, 2500.0f);
            }
            break;
        case 5: //L80360B3C
            if(func_8035FDA4(this)){
                func_8035FA0C(this);
            } else if(func_8035FBA8(this, 1)){
                func_8035FAA8(this);
            } else{
                func_80328FB0(this, 5.0f);
                func_8035FC20(this, this->unk1C_y, 2.0f);
                func_80360130(this);
            }//L80360BA0

            if(actor_animationIsAt(this, 0.5f)){
                func_8030E878(SFX_2_CLAW_SWIPE, randf2(1.0f, 1.2f), 10000, this->position, 833.0f, 2500.0f);
            }
            break;
        case 6: //L80360BF4
            if(animctrl_getAnimTimer(this->animctrl) < 0.01){
                func_8035F970(this);
            }
            break;
        case 7: //L80360C28
            sp34 = time_getDelta();
            func_8032CA80(this, this->unk38_0 ? 0x13 : 0x4);
            if(func_8035FC98(this, this->velocity_x * sp34)){
                this->position_y =  func_80309724(this->position);
                func_80328B8C(this, 8, 0.01f, 1);
                actor_playAnimationOnce(this);
                func_8030E6A4(SFX_1F_HITTING_AN_ENEMY_3, 1.2f, 32200);
            }
            else{//L80360CC4
                this->position_y += this->velocity_x * sp34;
                this->velocity_x -=  1600.0f * sp34;
            }
            break;
        case 8: //L80360CF0
            if(actor_animationIsAt(this, 0.3f)){
                func_80326310(this);
            }
            break;
    }
}
