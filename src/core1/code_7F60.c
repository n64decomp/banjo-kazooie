#include <ultra64.h>
#include "functions.h"
#include "variables.h"

static void _guMtxIdentF(float mf[4][4]);

u8 D_80275900[] = {0xCF, 0xAD, 0xA2, 0x90, 0x93, 0x4A, 0x83, 0xF1};
f32 D_80275908 = BAD_DTOR;

static s32 guFToFix32(f32 arg0){
	return arg0*65536.0f;
}

static void __guMtxF2L(float mf[4][4], Mtx *m)
{
	int	i, j;
	int	e1,e2;
	int	*ai,*af;


	ai=(int *) &m->m[0][0];
	af=(int *) &m->m[2][0];

	for (i=0; i<4; i++)
	for (j=0; j<2; j++) {
		e1=guFToFix32(mf[i][j*2]);
		e2=guFToFix32(mf[i][j*2+1]);
		*(ai++) = ( e1 & 0xffff0000 ) | ((e2 >> 16)&0xffff);
		*(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff);
	}
}

void _guMtxF2L(float mf[4][4], Mtx *m) //should be mf[4][4]
{
  int i;
  int j;
  int e1;
  int e2;
  int *ai;
  int *af;
    float * a2;
    
  ai = (int *) (&m->m[0][0]);
  af = (int *) (&m->m[2][0]);
  a2 = mf[0];
  for (i = 0; i < 8; i+=4)
    for (j = 0; j < 4; j++) {
		e1=(*(a2++))* 65536;
		e2=(*(a2++))* 65536;
      *(ai++) = (e1 & 0xffff0000) | ((e2 >> 16) & 0xffff);
      *(af++) = ((e1 <<  16) & 0xffff0000) | (e2 & 0xffff);
    }
}

void _guFustrumF(f32 mf[4][4], f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    s32 i, j;

    _guMtxIdentF(mf);
    mf[0][0] = (2 * arg5) / (arg2 - arg1);
    mf[1][1] = (2 * arg5) / (arg4 - arg3);
    mf[2][0] = (arg2 + arg1) / (arg2 - arg1);
    mf[2][1] = (arg4 + arg3) / (arg4 - arg3);
    mf[2][2] = -(arg6 + arg5) / (arg6 - arg5);
    mf[2][3] = -1.0f;
    mf[3][2] = (-2 * arg6 * arg5) / (arg6 - arg5);
    mf[3][3] = 0.0f;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			mf[i][j] *= arg7;
		}
	}
}

static void _guMtxIdentF(float mf[4][4]) //static
{
	int	i, j;

	for (i=0; i<4; i++)
	for (j=0; j<4; j++)
		if (i == j) mf[i][j] = 1.0;
		else mf[i][j] = 0.0;
}

void guMtxCatF(f32 lmf[4][4], f32 rmf[4][4], f32 dst[4][4]) {
	s32 i, j, k;
    f32 sp1C[4][4];

	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			sp1C[i][j] = 0.0f;
			for(k = 0; k < 4; k++){
				sp1C[i][j] += lmf[i][k]*rmf[k][j];
			}
		}
	}
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			dst[i][j] = sp1C[i][j];
		}
	}
}

static void _guNormalize(f32 *arg0, f32 *arg1, f32 *arg2) {
    f32 inv_len;

    inv_len = 1.0f / gu_sqrtf((*arg0 * *arg0) + (*arg1 * *arg1) + (*arg2 * *arg2));
    *arg0 *= inv_len;
    *arg1 *= inv_len;
    *arg2 *= inv_len;
}

void guPerspectiveF(float mf[4][4], u16 *perspNorm, float fovy, float aspect, float near, float far, float scale)
{
  float cot;
  float tmp;
  int i;
  int j;
  near = (near < 1.0f) ? (1.0f) : (near);
  far = (far < (near + 100.0f)) ? (near + 100.0f) : (far);
  tmp = ((2 * near) * far) / (near - far);
  if (((tmp * scale) > 32767) || ((tmp * scale) < (-32767)))
  {
    tmp = ((tmp * scale) > 32767) ? (32767) : (-32767);
    near = ((-(tmp / scale)) * far) / ((2 * far) - (tmp / scale));
  }
  guMtxIdentF(mf);
  fovy *= BAD_DTOR;
  cot = cosf(fovy / 2) / sinf(fovy / 2);
  mf[0][0] = cot / aspect;
  mf[1][1] = cot;
  mf[2][2] = (near + far) / (near - far);
  mf[2][3] = -1;
  if (!far)
  {
  }
  mf[3][2] = ((2 * near) * far) / (near - far);
  mf[3][3] = 0;
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 4; j++)
    {
      mf[i][j] *= scale;
    }

  }

  if (perspNorm != ((u16 *) 0))
  {
    if ((near + far) <= 2.0)
    {
      *perspNorm = (u16) 0xFFFF;
    }
    else
    {
      *perspNorm = (u16) ((2.0 * 65536.0) / (near + far));
      if ((*perspNorm) <= 0)
      {
        *perspNorm = (u16) 0x0001;
      }
    }
  }
}


void guPerspective(Mtx *m, u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale) {
    f32 sp28[4][4];

    guPerspectiveF(sp28, perspNorm, fovy, aspect, near, far, scale);
    __guMtxF2L(sp28, m);
}

void _guRotateF(f32 mf[4][4], f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    volatile f32 sp24;

    _guNormalize(&arg2, &arg3, &arg4);
    arg1 *= D_80275908;
    sp34 = sinf(arg1);
    sp30 = cosf(arg1);
    sp2C = arg2 * arg3 * (1.0f - sp30);
    sp28 = arg3 * arg4 * (1.0f - sp30);
    sp24 = (arg4 * arg2 * (1.0f - sp30));
    _guMtxIdentF(mf);
    mf[0][0] = ((1.0f - (arg2 * arg2)) * sp30) + (arg2 * arg2);
    mf[2][1] = (sp28 - (arg2 * sp34));
    mf[1][2] = ((arg2 * sp34) + sp28);

    mf[1][1] = (((1.0f - (arg3 * arg3)) * sp30) + (arg3 * arg3));
    mf[2][0] = ((arg3 * sp34) + sp24);
    mf[0][2] = (sp24 - (arg3 * sp34));
	
    mf[2][2] = (((1.0f - (arg4 * arg4)) * sp30) + (arg4 * arg4));
    mf[1][0] = (sp2C - (arg4 * sp34));
    mf[0][1] = (arg4 * sp34) + sp2C;
}

void guRotateRollF(f32 mf[4][4], f32 arg1){
	f32 c, s;
	arg1 *= D_80275908;
	_guMtxIdentF(mf);
	c = cosf(arg1);
	mf[1][1] = c;
	mf[2][2] = c;
	s = sinf(arg1);
	mf[1][2] = s;
	mf[2][1] = -s;
}

void guRotatePitchF(f32 mf[4][4], f32 arg1){
	f32 c, s;
	arg1 *= D_80275908;
	_guMtxIdentF(mf);
	c = cosf(arg1);
	mf[0][0] = c;
	mf[2][2] = c;
	s = sinf(arg1);
	mf[2][0] = s;
	mf[0][2] = -s;
}

void guRotateYawF(f32 mf[4][4], f32 arg1){
	f32 c, s;
	arg1 *= D_80275908;
	_guMtxIdentF(mf);
	c = cosf(arg1);
	mf[0][0] = c;
	mf[1][1] = c;
	s = sinf(arg1);
	mf[0][1] = s;
	mf[1][0] = -s;
}

void _guScaleF(f32 mf[4][4], f32 arg1, f32 arg2, f32 arg3){
	_guMtxIdentF(mf);
	mf[0][0] = arg1;
	mf[1][1] = arg2;
	mf[2][2] = arg3;
	mf[3][3] = 1.0f;
}

void _guTranslateF(f32 mf[4][4], f32 arg1, f32 arg2, f32 arg3){
	_guMtxIdentF(mf);
	mf[3][0] = arg1;
	mf[3][1] = arg2;
	mf[3][2] = arg3;
}
