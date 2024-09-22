#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/physics.h"

extern f32 ml_sin_deg(f32);
extern f32 ml_dotProduct_vec3f(f32[3], f32[3]);
extern void func_80256D0C(f32, f32, f32, f32, f32, f32 *, f32 *, f32 *);
extern void func_80256E24(f32[3], f32, f32, f32, f32, f32);
extern f32 climbGetRadius(void);
extern f32 func_8029CED0(void);

/* .data */
f32 baphysics_default_gravity = -2700.0f; //defaultGravity
f32 baphysics_default_terminal_velocity = -4000.0f;

/* .bss */
s32 baphysics_type;
f32 s_next_position[3];
f32 s_player_velocity[3]; //velocity?
f32 baphysics_target_velocity[3];
f32 s_delta_position[3];
f32 D_8037C4E4;
f32 s_gravity; //gravity
f32 s_terminal_velocity;
f32 baphysics_target_horizontal_velocity;
f32 baphysics_target_yaw; //angle
f32 baphysics_acceleration;
f32 D_8037C4FC;
f32 D_8037C500;

struct {
    u8 state;
    //u8 pad1[0x3];
    f32 start_position[3];
    f32 end_position[3];
    f32 duration;
    f32 elapsed_time; 
} baphysics_goto;

/* .code */
void __baphysics_update_normal(void){
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp44;
    f32 sp40;


    func_80256D0C(0.0f, baphysics_target_yaw, 0.0f, 0.0f, baphysics_target_horizontal_velocity, &baphysics_target_velocity[0], &baphysics_target_velocity[1], &baphysics_target_velocity[2]);
    sp6C[0] = s_player_velocity[0];\
    sp6C[1] = 0.0f;\
    sp6C[2] = s_player_velocity[2];
    // sp6C[1] = s_player_velocity[1];

    ml_vec3f_copy(sp60, baphysics_target_velocity);
    sp60[1] = 0.0f;
    if(func_80294548()){
        func_80294480(sp54);
        ml_vec3f_normalize_copy(sp48, sp60);
        sp44 = ml_dotProduct_vec3f(sp48, sp54);
        sp40 = get_slope_timer();
        if(sp44 != 0.0f){
            if(sp44 < 0){
                //sp44 = 0.0f;
                if(func_8028B3B4()){
                    sp40 = ml_map_f(sp40, 0.0f, 1.0f, sp44*0.5, -1.0f);
                }
                else{//L80296E3C
                    sp40 = 0.5*sp44;
                }//L80296E54
                ml_vec3f_scale(sp60, 1.0 + sp40);
            }
            else{//L80296E84
                sp40 = sp44*0.2;
                ml_vec3f_scale(sp60, sp40 + 1.0);
            }
        }//L80296EBC
    }//L80296EBC

    ml_vec3f_scale_copy(sp84, sp60, func_8029CED0());
    ml_vec3f_scale_copy(sp78, sp6C, func_8029CED0());
    ml_vec3f_diff(sp84, sp78);
    ml_vec3f_scale(sp84, time_getDelta()/0.0333333);
    s_player_velocity[0] += sp84[0];\
    s_player_velocity[1] += sp84[1];\
    s_player_velocity[2] += sp84[2];

    sp6C[0] = s_player_velocity[0];
    sp6C[2] = s_player_velocity[2];
    ml_vec3f_scale_copy(s_delta_position, sp6C, 1.0f);
    if(mlAbsF(s_player_velocity[0]) < 0.0001)
        s_player_velocity[0] = 0;

    if(mlAbsF(s_player_velocity[2]) < 0.0001)
        s_player_velocity[2] = 0;

    //update velocity for gravity
    s_player_velocity[1] = s_player_velocity[1] + time_getDelta()*s_gravity ;
    if(s_player_velocity[1] < s_terminal_velocity)
        s_player_velocity[1] = s_terminal_velocity;

    //update position
    s_delta_position[1] = s_delta_position[1] + s_player_velocity[1];
    ml_vec3f_scale(s_delta_position, time_getDelta());
    s_next_position[0] += s_delta_position[0];\
    s_next_position[1] += s_delta_position[1];\
    s_next_position[2] += s_delta_position[2]; 
}

void __baphysics_update_no_gravity(void){
    f32 sp24[3];
    //update velocity
    ml_vec3f_diff_copy(sp24, baphysics_target_velocity, s_player_velocity);
    ml_vec3f_scale(sp24, time_getDelta()*baphysics_acceleration);

    if (LENGTH_SQ_VEC3F(sp24) < 0.02) {
        ml_vec3f_copy(s_player_velocity, baphysics_target_velocity);
    }
    else{
        s_player_velocity[0] += sp24[0];\
        s_player_velocity[1] += sp24[1];\
        s_player_velocity[2] += sp24[2];
    }
    //update position
    s_delta_position[0] = s_player_velocity[0];\
    s_delta_position[1] = s_player_velocity[1];\
    s_delta_position[2] = s_player_velocity[2];
    ml_vec3f_scale( s_delta_position, time_getDelta());

    s_next_position[0] += s_delta_position[0];\
    s_next_position[1] += s_delta_position[1];\
    s_next_position[2] += s_delta_position[2];
}

void func_802971DC(void){
    s_player_velocity[1] = s_player_velocity[1] + time_getDelta()*s_gravity;
    if(s_player_velocity[1] < s_terminal_velocity)
        s_player_velocity[1] = s_terminal_velocity;
    
    s_delta_position[0] = s_player_velocity[0];\
    s_delta_position[1] = s_player_velocity[1];\
    s_delta_position[2] = s_player_velocity[2];
    ml_vec3f_scale(s_delta_position, time_getDelta());

    s_next_position[0] += s_delta_position[0];\
    s_next_position[1] += s_delta_position[1];\
    s_next_position[2] += s_delta_position[2];
}

void __baphysics_update_climb(void){
    f32 sp34[3];
    f32 sp28[3];

    climbGetBottom(sp28);
    s_next_position[0] = sp28[0];
    s_next_position[2] = sp28[2];
    func_80256E24(sp34, 0.0f, yaw_get(), 0.0f, 0.0f, -climbGetRadius());

    s_player_velocity[2] = 0.0f;
    s_next_position[0] += sp34[0];\
    s_next_position[1] += sp34[1];\
    s_next_position[2] += sp34[2];

    
    s_player_velocity[0] = baphysics_target_velocity[0] = baphysics_target_velocity[2] =  s_player_velocity[2];
    __baphysics_update_no_gravity();
}

void func_8029737C(void){
    s_delta_position[0] = s_player_velocity[0];
    s_delta_position[1] = s_player_velocity[1];
    s_delta_position[2] = s_player_velocity[2];
    ml_vec3f_scale(s_delta_position, time_getDelta());
    s_next_position[0] += s_delta_position[0];
    s_next_position[1] += s_delta_position[1];
    s_next_position[2] += s_delta_position[2];
}

void func_8029740C(void){
    s_delta_position[0] = s_player_velocity[0];
    s_delta_position[1] = s_player_velocity[1];
    s_delta_position[2] = s_player_velocity[2];
    ml_vec3f_clear(s_player_velocity);
    ml_vec3f_scale(s_delta_position, time_getDelta());
    s_next_position[0] += s_delta_position[0];
    s_next_position[1] += s_delta_position[1];
    s_next_position[2] += s_delta_position[2];
}

void __baphysics_update_goto(void){
    f32 sp2C;

    switch(baphysics_goto.state){
        case 0: //L80297628
            break;
        case 1: //L802974E8
            baphysics_goto.state = 2;
            _player_getPosition(baphysics_goto.start_position);
            baphysics_goto.elapsed_time = 0.0f;
            baphysics_set_velocity(0);
            break;
        case 2: //L80297510
            baphysics_goto.elapsed_time += time_getDelta();
            sp2C = ml_map_f(baphysics_goto.elapsed_time, 0.0f, baphysics_goto.duration, 0.0f, 1.0f);
            ml_vec3f_copy(s_player_velocity, s_next_position);
            s_next_position[0] = ml_interpolate_f(sp2C, baphysics_goto.start_position[0], baphysics_goto.end_position[0]);
            s_next_position[1] = ml_interpolate_f(sp2C, baphysics_goto.start_position[1], baphysics_goto.end_position[1]);
            s_next_position[2] = ml_interpolate_f(sp2C, baphysics_goto.start_position[2], baphysics_goto.end_position[2]);
            ml_vec3f_diff_copy(s_player_velocity, s_next_position, s_player_velocity);
            ml_vec3f_scale(s_player_velocity, 1.0/time_getDelta());
            if(1.0 == sp2C){
                baphysics_set_velocity(0);
                baphysics_goto.state = 3;
            }
            break;
        case 3: //L80297628
            break;    
    }
}

void __baphysics_update_transform(void){
    f32 temp_f0;

    D_8037C500 += time_getDelta();
    temp_f0 = func_80257A44(D_8037C500, 1.2f);
    temp_f0 = ml_sin_deg(temp_f0*360.0f);
    s_next_position[1] = 5.0*temp_f0 + D_8037C4FC;
}

void baphysics_get_position_change(f32 arg0[3]){
    ml_vec3f_copy(arg0, s_delta_position);
}

void baphysics_init(void){
    baphysics_type = 0;
    ml_vec3f_clear(s_player_velocity);
    ml_vec3f_clear(baphysics_target_velocity);
    ml_vec3f_clear(s_delta_position);
    ml_vec3f_clear(s_next_position);
    D_8037C4E4 = 0.0f;
    baphysics_reset();
}

void baphysics_update(void){
    _player_getPosition(s_next_position);
    switch(baphysics_type){
        case BA_PHYSICS_GOTO: //L80297780
            __baphysics_update_goto();
            break;
        case BA_PHYSICS_TRANSFORM: //L80297790
            __baphysics_update_transform();
            break;
        case BA_PHYSICS_UNK8: //L802977A0 
            func_8029737C();
            break;
        case BA_PHYSICS_UNK1: //L802977B0 
            func_802971DC();
            break;
        case BA_PHYSICS_NO_GRAVITY: //L802977C0 
            __baphysics_update_no_gravity();
            break;
        case BA_PHYSICS_NORMAL: //L802977D0 //bear
            baphysics_set_target_yaw(yaw_getIdeal());
            __baphysics_update_normal();
            break;
        case BA_PHYSICS_INVERTED_YAW: //L802977F0 //bird
            baphysics_set_target_yaw(mlNormalizeAngle(yaw_getIdeal() + 180.0f));
            __baphysics_update_normal();
            break;
        case BA_PHYSICS_LOCKED_ROTATION: //L80297820  
            __baphysics_update_normal();
            break;
        case BA_PHYSICS_UNK4: //L80297830 
            func_8029740C();
            break;
        case BA_PHYSICS_AIRBORN: //L80297840 
            if(0.0f < func_8029B2E8()){
                baphysics_set_target_yaw(func_8029B33C());
            }
            __baphysics_update_normal();
            break;
        case BA_PHYSICS_CLIMB: //L80297880
            __baphysics_update_climb();
            break;
        case BA_PHYSICS_NONE:
        case BA_PHYSICS_FREEZE:
        default:
            break;
    }
    player_setPosition(s_next_position);
}

void baphysics_reset_horizontal_velocity(void){
    baphysics_set_target_horizontal_velocity(0.0f);
    s_player_velocity[0] = s_player_velocity[2] = 0.0f;
}

void baphysics_set_type(BaPhysicsType arg0){
    if((arg0 == BA_PHYSICS_TRANSFORM) && (arg0 != baphysics_type)){
        D_8037C4FC = s_next_position[1];
        D_8037C500 = 0.0f;
    }
    if(arg0 == BA_PHYSICS_GOTO){
        baphysics_goto.state = 1;
    }
    baphysics_type = arg0;
}

void baphysics_set_target_velocity(f32 src[3]){
    if(src)
        ml_vec3f_copy(baphysics_target_velocity, src);
    else
        ml_vec3f_clear(baphysics_target_velocity);
}

void baphysics_set_target_horizontal_velocity(f32 arg0){
    baphysics_target_horizontal_velocity = arg0;
}

void baphysics_set_target_yaw(f32 arg0){
    baphysics_target_yaw = mlNormalizeAngle(arg0);
}

void baphysics_set_vertical_velocity(f32 arg0){
    s_player_velocity[1] = arg0;
}

void baphysics_set_horizontal_velocity(f32 yaw, f32 magnitude) { \
    func_80256D0C(0.0f, yaw, 0.0f, 0.0f, magnitude, &s_player_velocity[0], &s_player_velocity[1], &s_player_velocity[2]);
}

void baphysics_set_velocity(f32 src[3]){
    if(src)
        ml_vec3f_copy(s_player_velocity, src);
    else
        ml_vec3f_clear(s_player_velocity);
}

f32 baphysics_get_gravity(void){
    return s_gravity;
}

BaPhysicsType baphysics_get_type(void){
    return baphysics_type;
}

f32 baphysics_get_target_horizontal_velocity(void){
    return baphysics_target_horizontal_velocity;
}

f32 baphysics_get_target_vertical_velocity(void){
    return baphysics_target_velocity[1];
}

f32 baphysics_get_target_yaw(void){
    return baphysics_target_yaw;
}

void baphysics_get_velocity(f32 dst[3]){
    ml_vec3f_copy(dst, s_player_velocity);
}

f32 baphysics_get_vertical_velocity(void){
    return s_player_velocity[1];
}

f32 baphysics_get_horizontal_velocity(void){
    return gu_sqrtf(s_player_velocity[0]*s_player_velocity[0] + s_player_velocity[2]*s_player_velocity[2]);
}

f32 baphysics_get_horizontal_velocity_percentage(void){
    f32 horz_vel;
    f32 target_vel;
    f32 temp_f12;

    horz_vel = baphysics_get_horizontal_velocity();
    target_vel = baphysics_get_target_horizontal_velocity();
    
    if(horz_vel < target_vel){
        temp_f12 = horz_vel/target_vel;
    }
    else{
        temp_f12 = 1.0f;
    }
    return temp_f12;
}

void baphysics_reset(void){
    baphysics_reset_gravity();
    baphysics_reset_terminal_velocity();
}

void baphysics_set_acceleration(f32 arg0){
    baphysics_acceleration = arg0;
}

void baphysics_reset_gravity(void){
    baphysics_set_gravity(baphysics_default_gravity);
}

void baphysics_reset_terminal_velocity(void){
    baphysics_set_terminal_velocity(baphysics_default_terminal_velocity);
}

void baphysics_set_goto_duration(f32 arg0){
    baphysics_goto.duration = arg0;
}

void baphysics_set_goto_position(f32 src[3]) { \
    ml_vec3f_copy(baphysics_goto.end_position, src);
}

void baphysics_set_gravity(f32 arg0){
    s_gravity = arg0;
}

void baphysics_set_terminal_velocity(f32 arg0){
    s_terminal_velocity = arg0;
}

int baphysics_is_slower_than(f32 arg0){
    return s_player_velocity[0]*s_player_velocity[0] + s_player_velocity[2]*s_player_velocity[2] <= (arg0*arg0);
}

int baphysics_goto_done(void){
    return baphysics_goto.state == 3;
}
