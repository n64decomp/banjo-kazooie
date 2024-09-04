#ifndef __ML_MTX__
#define __ML_MTX__

void mlMtxIdent(void);
void mlMtxRotPitch(f32 pitch);
void mlMtxRotYaw(f32 yaw);
void mlMtxRotRoll(f32 roll);
void mlMtxScale_xyz(f32 x, f32 y, f32);
void mlMtxTranslate(f32 x, f32 y, f32 z);

#endif
