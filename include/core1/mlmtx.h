#ifndef BANJO_KAZOOIE_CORE1_MLMTX_H
#define BANJO_KAZOOIE_CORE1_MLMTX_H

void mlMtxGet(MtxF *dst);
MtxF *mlMtx_get_stack_pointer(void);
void mlMtxApply(Mtx *mPtr);
void mlMtxPop(void);
void mlMtx_push_duplicate(void);
void mlMtx_push_identity(void);
void mlMtx_push_translation(f32 x, f32 y, f32 z);
void mlMtx_push_mtx(f32* mtx);
void mlMtx_push_multiplied(f32* l_mtx);
void mlMtx_push_multiplied_2(MtxF * l_mtx, MtxF * r_mtx);
void mlMtxIdent(void);
void func_80251B5C(f32 x, f32 y, f32 z);
void mlMtxSet(MtxF* arg0);
void mlMtxRotate(f32 a, f32 x, f32 y, f32 z);
void mlMtxRotPitch(f32 arg0);
void mlMtxRotYaw(f32 arg0);
void mlMtxRotRoll(f32 arg0);
void mlMtx_rotate_pitch_deg(f32 arg0);
void mlMtx_rotate_yaw_deg(f32 arg0);
void mlMtxRotatePYR(f32 pitch, f32 yaw, f32 roll);
void mlMtxScale_xyz(f32 x, f32 y, f32 z);
void mlMtxScale(f32 scale);
void func_80252330(f32 x, f32 y, f32 z);
void mlMtx_apply_vec3f(f32 dst[3], f32 src[3]);
void mlMtx_apply_vec3f_restricted(f32 dst[3], f32 src[3]);
void mlMtx_apply_f3(f32 dst[3], f32 x, f32 y, f32 z);
void mlMtx_apply_vec3s(s16 dst[3], s16 src[3]);
void func_8025276C(s32 arg0[3], s32 arg1[3], s32 arg2[3], s32 arg3[3]);
void mlMtxTranslate(f32 x, f32 y, f32 z);
void func_80252A38(f32 x, f32 y, f32 z);
void func_80252AF0(f32 arg0[3], f32 arg1[3], f32 rotation[3], f32 scale, f32 arg4[3]);
void func_80252C08(f32 arg0[3], f32 rotation[3], f32 scale, f32 arg3[3]);
void func_80252CC4(f32 position[3], f32 rotation[3], f32 scale, f32 arg3[3]);
void func_80252D8C(f32 position[3], f32 rotation[3]);
void func_80252DDC(f32 position[3], f32 rotation[3]);
void func_80252E4C(f32 position[3], f32 rotation[3]);
void func_80252EC8(f32 position[3], f32 rotation[3]);
void func_80252F50(f32 rotation[3]);
void func_80252F8C(f32 rotation[3]);
void func_80252FC8(f32 rotation[3]);

#endif
