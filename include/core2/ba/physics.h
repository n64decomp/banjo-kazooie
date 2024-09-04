#ifndef __BA_PHYSICS_H__
#define __BA_PHYSICS_H__

#include <ultra64.h>

typedef enum ba_physics_type_e{
    BA_PHYSICS_NONE,
    BA_PHYSICS_UNK1,
    BA_PHYSICS_NORMAL,
    BA_PHYSICS_LOCKED_ROTATION,
    BA_PHYSICS_UNK4, 
    BA_PHYSICS_INVERTED_YAW,
    BA_PHYSICS_AIRBORN,
    BA_PHYSICS_FREEZE,
    BA_PHYSICS_UNK8,
    BA_PHYSICS_NO_GRAVITY,
    BA_PHYSICS_CLIMB,
    BA_PHYSICS_TRANSFORM,
    BA_PHYSICS_GOTO,
    BA_PHYSICS_END
}BaPhysicsType;

void baphysics_get_position_change(f32 dst[3]);
void baphysics_init(void);
void baphysics_update(void);
void baphysics_reset_horizontal_velocity(void);
void baphysics_set_type(BaPhysicsType);
void baphysics_set_target_velocity(f32 src[3]);
void baphysics_set_target_horizontal_velocity(f32);
void baphysics_set_target_yaw(f32);
void baphysics_set_vertical_velocity(f32);
void baphysics_set_horizontal_velocity(f32, f32);
void baphysics_set_velocity(f32 src[3]);
f32  baphysics_get_gravity(void);
BaPhysicsType baphysics_get_type(void);
f32  baphysics_get_target_horizontal_velocity(void);
f32  baphysics_get_target_vertical_velocity(void);
f32  baphysics_get_target_yaw(void);
void baphysics_get_velocity(f32 dst[3]);
f32  baphysics_get_vertical_velocity(void);
f32  baphysics_get_horizontal_velocity(void);
f32  baphysics_get_horizontal_velocity_percentage(void);
void baphysics_reset(void);
void baphysics_set_acceleration(f32);
void baphysics_reset_gravity(void);
void baphysics_reset_terminal_velocity(void);
void baphysics_set_goto_duration(f32);
void baphysics_set_goto_position(f32 src[3]);
void baphysics_set_gravity(f32);
void baphysics_set_terminal_velocity(f32);
int  baphysics_is_slower_than(f32);
int  baphysics_goto_done(void);
#endif
