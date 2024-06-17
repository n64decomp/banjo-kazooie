#ifndef _YAW_H_
#define _YAW_H_

enum yaw_state_e{
    YAW_STATE_0_NONE,
    YAW_STATE_1_DEFAULT,
    YAW_STATE_2_UNBOUNDED,
    YAW_STATE_3_BOUNDED
};

void yaw_init(void);
void yaw_update(void);
void yaw_setUpdateState(s32);
void yaw_setIdeal(f32 arg0);
void yaw_set(f32 arg0);
void yaw_applyIdeal(void);
s32 yaw_getUpdateState(void);
f32 yaw_get(void);
f32 yaw_getIdeal(void);
void yaw_setVelocityBounded(f32 arg0, f32 arg1);
void yaw_setVelocityUnbounded(f32 arg0);
void yaw_rotateTimed(f32 time_sec);
#endif
