/*
 *  real.h
 *
 *  copyright (c) 2019-2021 Xiongfei Shi
 *
 *  author: Xiongfei Shi <jenson.shixf(a)gmail.com>
 *  license: Apache-2.0
 *
 *  https://github.com/shixiongfei/math
 */

#ifndef __REAL_H__
#define __REAL_H__

#include <stddef.h>
#include <stdlib.h>

#include <float.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef double real_t;

#define r_zero 0.0
#define r_half 0.5
#define r_one 1.0
#define r_two 2.0
#define r_negone -1.0
#define r_epsilon DBL_EPSILON
#define r_pi 3.14159265358979323846
#define r_deg (180.0 / r_pi)
#define r_rad (r_pi / 180.0)

#define r_sqrt(x) sqrt(x)
#define r_abs(x) fabs(x)
#define r_sin(x) sin(x)
#define r_cos(x) cos(x)
#define r_tan(x) tan(x)
#define r_asin(x) asin(x)
#define r_acos(x) acos(x)
#define r_atan2(y, x) atan2(y, x)
#define r_equal(a, b) (r_abs((a) - (b)) < r_epsilon)

#define degrees(rad) ((rad)*r_deg)
#define radians(deg) ((deg)*r_rad)

#ifdef __cplusplus
};
#endif

#endif /* __REAL_H__ */
