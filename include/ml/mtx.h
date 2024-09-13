#ifndef __ML_MTX__
#define __ML_MTX__

typedef struct {
    f32 m[4][4];
} MtxF;

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
void mlMtxSet(MtxF* arg0);
void mlMtxRotPitch(f32 arg0);
void mlMtxRotYaw(f32 arg0);
void mlMtxRotRoll(f32 arg0);
void mlMtx_rotate_pitch_deg(f32 arg0);
void mlMtx_rotate_yaw_deg(f32 arg0);
void mlMtxRotatePYR(f32 pitch, f32 yaw, f32 roll);
void mlMtxScale_xyz(f32 x, f32 y, f32 z);
void mlMtxScale(f32 scale);
void mlMtx_apply_f3(f32 dst[3], f32 x, f32 y, f32 z);
void mlMtx_apply_vec3s(s16 dst[3], s16 src[3]);
void mlMtxTranslate(f32 x, f32 y, f32 z);

MtxF *func_8024DD90(void);
MtxF *func_8024DD9C(void);

#endif
