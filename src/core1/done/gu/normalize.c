#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void guNormalize(float *x, float *y, float *z)
{
	float	m;

	m = gu_sqrtf((*x)*(*x) + (*y)*(*y) + (*z)*(*z));
    m = (f32)1.0/ m;
	*x *= m;
	*y *= m;
	*z *= m;
}