#ifndef __MATH_LIBRARY_H__
#define __MATH_LIBRARY_H__

void ml_vec3f_normalize_copy(f32 (*arg0)[3], f32 (*arg1)[3]);
void ml_vec3f_yaw_rotate_copy(f32 (* arg0)[3], f32 (* arg1)[3], f32 arg2);
void ml_vec3f_diff_copy(f32 (* arg0)[3], f32 (* arg1)[3], f32 (* arg2)[3]);
void ml_vec3f_set_length_copy(f32 (*arg0)[3], f32 (*arg1)[3], f32 arg2);
void ml_vec3f_set_length(f32 (*arg0)[3], f32 arg2);

#endif
