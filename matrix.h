/*
 *  matrix.h
 *
 *  copyright (c) 2019-2021 Xiongfei Shi
 *
 *  author: Xiongfei Shi <xiongfei.shi(a)icloud.com>
 *  license: Apache-2.0
 *
 *  https://github.com/shixiongfei/math
 */

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "vector.h"
#include <string.h> /* memset */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * | e0  e2 |
 * | e1  e3 |
 **/
typedef real_t mat22_t[4];

/**
 * | e0  e3  e6 |
 * | e1  e4  e7 |
 * | e2  e5  e8 |
 **/
typedef real_t mat33_t[9];

/**
 * | e0  e4   e8  e12 |
 * | e1  e5   e9  e13 |
 * | e2  e6  e10  e14 |
 * | e3  e7  e11  e15 |
 **/
typedef real_t mat44_t[16];

#define e0(e) e[0]
#define e1(e) e[1]
#define e2(e) e[2]
#define e3(e) e[3]
#define e4(e) e[4]
#define e5(e) e[5]
#define e6(e) e[6]
#define e7(e) e[7]
#define e8(e) e[8]
#define e9(e) e[9]
#define e10(e) e[10]
#define e11(e) e[11]
#define e12(e) e[12]
#define e13(e) e[13]
#define e14(e) e[14]
#define e15(e) e[15]

/**
 *---------------------------------------------
 *  Matrix22
 *---------------------------------------------
 **/

#define mat22_zero(e) memset(e, 0, sizeof(real_t) * 4)

#define mat22_equal(a, b)                                                      \
  (r_equal(e0(a), e0(b)) && r_equal(e1(a), e1(b)) && r_equal(e2(a), e2(b)) &&  \
   r_equal(e3(a), e3(b)))

#define mat22_identity(e)                                                      \
  do {                                                                         \
    mat22_zero(e);                                                             \
    e0(e) = e3(e) = r_one;                                                     \
  } while (0)

#define mat22_add(r, a, b)                                                     \
  do {                                                                         \
    e0(r) = e0(a) + e0(b);                                                     \
    e1(r) = e1(a) + e1(b);                                                     \
    e2(r) = e2(a) + e2(b);                                                     \
    e3(r) = e3(a) + e3(b);                                                     \
  } while (0)

#define mat22_sub(r, a, b)                                                     \
  do {                                                                         \
    e0(r) = e0(a) - e0(b);                                                     \
    e1(r) = e1(a) - e1(b);                                                     \
    e2(r) = e2(a) - e2(b);                                                     \
    e3(r) = e3(a) - e3(b);                                                     \
  } while (0)

#define mat22_mul(r, a, b)                                                     \
  do {                                                                         \
    e0(r) = e0(a) * e0(b) + e2(a) * e1(b);                                     \
    e1(r) = e1(a) * e0(b) + e3(a) * e1(b);                                     \
    e2(r) = e0(a) * e2(b) + e2(a) * e3(b);                                     \
    e3(r) = e1(a) * e2(b) + e3(a) * e3(b);                                     \
  } while (0)

#define mat22_determinant(e) (e0(e) * e3(e) - e1(e) * e2(e))

#define mat22_inverse(r, e)                                                    \
  do {                                                                         \
    real_t det = mat22_determinant(e);                                         \
    det = r_one / det;                                                         \
    e0(r) = det * e3(e);                                                       \
    e1(r) = -det * e1(e);                                                      \
    e2(r) = -det * e2(e);                                                      \
    e3(r) = det * e0(e);                                                       \
  } while (0)

#define mat22_transpose(r, e)                                                  \
  do {                                                                         \
    e0(r) = e0(e);                                                             \
    e1(r) = e2(e);                                                             \
    e2(r) = e1(e);                                                             \
    e3(r) = e3(e);                                                             \
  } while (0)

void mat22_rotation(mat22_t r, real_t theta);

/**
 *---------------------------------------------
 *  Matrix33
 *---------------------------------------------
 **/

#define mat33_zero(e) memset(e, 0, sizeof(real_t) * 9)

#define mat33_equal(a, b)                                                      \
  (r_equal(e0(a), e0(b)) && r_equal(e1(a), e1(b)) && r_equal(e2(a), e2(b)) &&  \
   r_equal(e3(a), e3(b)) && r_equal(e4(a), e4(b)) && r_equal(e5(a), e5(b)) &&  \
   r_equal(e6(a), e6(b)) && r_equal(e7(a), e7(b)) && r_equal(e8(a), e8(b)))

#define mat33_identity(e)                                                      \
  do {                                                                         \
    mat33_zero(e);                                                             \
    e0(e) = e4(e) = e8(e) = r_one;                                             \
  } while (0)

#define mat33_add(r, a, b)                                                     \
  do {                                                                         \
    e0(r) = e0(a) + e0(b);                                                     \
    e1(r) = e1(a) + e1(b);                                                     \
    e2(r) = e2(a) + e2(b);                                                     \
    e3(r) = e3(a) + e3(b);                                                     \
    e4(r) = e4(a) + e4(b);                                                     \
    e5(r) = e5(a) + e5(b);                                                     \
    e6(r) = e6(a) + e6(b);                                                     \
    e7(r) = e7(a) + e7(b);                                                     \
    e8(r) = e8(a) + e8(b);                                                     \
  } while (0)

#define mat33_sub(r, a, b)                                                     \
  do {                                                                         \
    e0(r) = e0(a) - e0(b);                                                     \
    e1(r) = e1(a) - e1(b);                                                     \
    e2(r) = e2(a) - e2(b);                                                     \
    e3(r) = e3(a) - e3(b);                                                     \
    e4(r) = e4(a) - e4(b);                                                     \
    e5(r) = e5(a) - e5(b);                                                     \
    e6(r) = e6(a) - e6(b);                                                     \
    e7(r) = e7(a) - e7(b);                                                     \
    e8(r) = e8(a) - e8(b);                                                     \
  } while (0)

#define mat33_mul(r, a, b)                                                     \
  do {                                                                         \
    e0(r) = e0(a) * e0(b) + e3(a) * e1(b) + e6(a) * e2(b);                     \
    e1(r) = e1(a) * e0(b) + e4(a) * e1(b) + e7(a) * e2(b);                     \
    e2(r) = e2(a) * e0(b) + e5(a) * e1(b) + e8(a) * e2(b);                     \
    e3(r) = e0(a) * e3(b) + e3(a) * e4(b) + e6(a) * e5(b);                     \
    e4(r) = e1(a) * e3(b) + e4(a) * e4(b) + e7(a) * e5(b);                     \
    e5(r) = e2(a) * e3(b) + e5(a) * e4(b) + e8(a) * e5(b);                     \
    e6(r) = e0(a) * e6(b) + e3(a) * e7(b) + e6(a) * e8(b);                     \
    e7(r) = e1(a) * e6(b) + e4(a) * e7(b) + e7(a) * e8(b);                     \
    e8(r) = e2(a) * e6(b) + e5(a) * e7(b) + e8(a) * e8(b);                     \
  } while (0)

#define mat33_determinant(e)                                                   \
  (e0(e) * (e4(e) * e8(e) - e7(e) * e5(e)) -                                   \
   e1(e) * (e3(e) * e8(e) - e5(e) * e6(e)) +                                   \
   e2(e) * (e3(e) * e7(e) - e4(e) * e6(e)))

#define mat33_inverse(r, e)                                                    \
  do {                                                                         \
    real_t det = mat33_determinant(e);                                         \
    det = r_one / det;                                                         \
    e0(r) = det * (e4(e) * e8(e) - e7(e) * e5(e));                             \
    e1(r) = -det * (e3(e) * e8(e) - e5(e) * e6(e));                            \
    e2(r) = det * (e3(e) * e7(e) - e6(e) * e4(e));                             \
    e3(r) = -det * (e1(e) * e8(e) - e2(e) * e7(e));                            \
    e4(r) = det * (e0(e) * e8(e) - e2(e) * e6(e));                             \
    e5(r) = -det * (e0(e) * e7(e) - e6(e) * e1(e));                            \
    e6(r) = det * (e1(e) * e5(e) - e2(e) * e4(e));                             \
    e7(r) = -det * (e0(e) * e5(e) - e3(e) * e2(e));                            \
    e8(r) = det * (e0(e) * e4(e) - e3(e) * e1(e));                             \
  } while (0)

#define mat33_transpose(r, e)                                                  \
  do {                                                                         \
    e0(r) = e0(e);                                                             \
    e1(r) = e3(e);                                                             \
    e2(r) = e6(e);                                                             \
    e3(r) = e1(e);                                                             \
    e4(r) = e4(e);                                                             \
    e5(r) = e7(e);                                                             \
    e6(r) = e2(e);                                                             \
    e7(r) = e5(e);                                                             \
    e8(r) = e8(e);                                                             \
  } while (0)

#define mat33_transform2(r, e, v)                                              \
  do {                                                                         \
    vx(r) = e0(e) * vx(v) + e3(e) * vy(v) + e6(e);                             \
    vy(r) = e1(e) * vx(v) + e4(e) * vy(v) + e7(e);                             \
  } while (0)

#define mat33_transform3(r, e, v)                                              \
  do {                                                                         \
    vx(r) = e0(e) * vx(v) + e3(e) * vy(v) + e6(e) * vz(v);                     \
    vy(r) = e1(e) * vx(v) + e4(e) * vy(v) + e7(e) * vz(v);                     \
    vz(r) = e2(e) * vx(v) + e5(e) * vy(v) + e8(e) * vz(v);                     \
  } while (0)

void mat33_transformation(mat33_t r, real_t x, real_t y, real_t theta,
                          real_t sx, real_t sy, real_t ox, real_t oy, real_t kx,
                          real_t ky);

void mat33_rotatex(mat33_t r, real_t theta);
void mat33_rotatey(mat33_t r, real_t theta);
void mat33_rotatez(mat33_t r, real_t theta);
void mat33_rotateaxis(mat33_t r, real_t theta, vec3_t axis);

#define mat33_tomat44(r4, e3)                                                  \
  do {                                                                         \
    mat44_identity(r4);                                                        \
    e0(r4) = e0(e3);                                                           \
    e1(r4) = e1(e3);                                                           \
    e2(r4) = e2(e3);                                                           \
    e4(r4) = e3(e3);                                                           \
    e5(r4) = e4(e3);                                                           \
    e6(r4) = e5(e3);                                                           \
    e8(r4) = e6(e3);                                                           \
    e9(r4) = e7(e3);                                                           \
    e10(r4) = e8(e3);                                                          \
  } while (0)

/**
 *---------------------------------------------
 *  Matrix44
 *---------------------------------------------
 **/

#define mat44_zero(e) memset(e, 0, sizeof(real_t) * 16)

#define mat44_equal(a, b)                                                      \
  (r_equal(e0(a), e0(b)) && r_equal(e1(a), e1(b)) && r_equal(e2(a), e2(b)) &&  \
   r_equal(e3(a), e3(b)) && r_equal(e4(a), e4(b)) && r_equal(e5(a), e5(b)) &&  \
   r_equal(e6(a), e6(b)) && r_equal(e7(a), e7(b)) && r_equal(e8(a), e8(b)) &&  \
   r_equal(e9(a), e9(b)) && r_equal(e10(a), e10(b)) &&                         \
   r_equal(e11(a), e11(b)) && r_equal(e12(a), e12(b)) &&                       \
   r_equal(e13(a), e13(b)) && r_equal(e14(a), e14(b)) &&                       \
   r_equal(e15(a), e15(b)))

#define mat44_identity(e)                                                      \
  do {                                                                         \
    mat44_zero(e);                                                             \
    e0(e) = e5(e) = e10(e) = e15(e) = r_one;                                   \
  } while (0)

#define mat44_translate2(e, v)                                                 \
  do {                                                                         \
    mat44_identity(e);                                                         \
    e12(e) = vx(v);                                                            \
    e13(e) = vy(v);                                                            \
  } while (0)

#define mat44_translate3(e, v)                                                 \
  do {                                                                         \
    mat44_identity(e);                                                         \
    e12(e) = vx(v);                                                            \
    e13(e) = vy(v);                                                            \
    e14(e) = vz(v);                                                            \
  } while (0)

#define mat44_scale2(e, v)                                                     \
  do {                                                                         \
    mat44_identity(e);                                                         \
    e0(e) = vx(v);                                                             \
    e5(e) = vy(v);                                                             \
  } while (0)

#define mat44_scale3(e, v)                                                     \
  do {                                                                         \
    mat44_identity(e);                                                         \
    e0(e) = vx(v);                                                             \
    e5(e) = vy(v);                                                             \
    e10(e) = vz(v);                                                            \
  } while (0)

#define mat44_shear2(e, v)                                                     \
  do {                                                                         \
    mat44_identity(e);                                                         \
    e1(e) = vx(v);                                                             \
    e4(e) = vy(v);                                                             \
  } while (0)

#define mat44_shear3(e, v)                                                     \
  do {                                                                         \
    mat44_identity(e);                                                         \
    e1(e) = e2(e) = vx(v);                                                     \
    e4(e) = e6(e) = vy(v);                                                     \
    e8(e) = e9(e) = vz(v);                                                     \
  } while (0)

#define mat44_add(r, a, b)                                                     \
  do {                                                                         \
    e0(r) = e0(a) + e0(b);                                                     \
    e1(r) = e1(a) + e1(b);                                                     \
    e2(r) = e2(a) + e2(b);                                                     \
    e3(r) = e3(a) + e3(b);                                                     \
    e4(r) = e4(a) + e4(b);                                                     \
    e5(r) = e5(a) + e5(b);                                                     \
    e6(r) = e6(a) + e6(b);                                                     \
    e7(r) = e7(a) + e7(b);                                                     \
    e8(r) = e8(a) + e8(b);                                                     \
    e9(r) = e9(a) + e9(b);                                                     \
    e10(r) = e10(a) + e10(b);                                                  \
    e11(r) = e11(a) + e11(b);                                                  \
    e12(r) = e12(a) + e12(b);                                                  \
    e13(r) = e13(a) + e13(b);                                                  \
    e14(r) = e14(a) + e14(b);                                                  \
    e15(r) = e15(a) + e15(b);                                                  \
  } while (0)

#define mat44_sub(r, a, b)                                                     \
  do {                                                                         \
    e0(r) = e0(a) - e0(b);                                                     \
    e1(r) = e1(a) - e1(b);                                                     \
    e2(r) = e2(a) - e2(b);                                                     \
    e3(r) = e3(a) - e3(b);                                                     \
    e4(r) = e4(a) - e4(b);                                                     \
    e5(r) = e5(a) - e5(b);                                                     \
    e6(r) = e6(a) - e6(b);                                                     \
    e7(r) = e7(a) - e7(b);                                                     \
    e8(r) = e8(a) - e8(b);                                                     \
    e9(r) = e9(a) - e9(b);                                                     \
    e10(r) = e10(a) - e10(b);                                                  \
    e11(r) = e11(a) - e11(b);                                                  \
    e12(r) = e12(a) - e12(b);                                                  \
    e13(r) = e13(a) - e13(b);                                                  \
    e14(r) = e14(a) - e14(b);                                                  \
    e15(r) = e15(a) - e15(b);                                                  \
  } while (0)

#define mat44_mul(r, a, b)                                                     \
  do {                                                                         \
    e0(r) = e0(a) * e0(b) + e4(a) * e1(b) + e8(a) * e2(b) + e12(a) * e3(b);    \
    e4(r) = e0(a) * e4(b) + e4(a) * e5(b) + e8(a) * e6(b) + e12(a) * e7(b);    \
    e8(r) = e0(a) * e8(b) + e4(a) * e9(b) + e8(a) * e10(b) + e12(a) * e11(b);  \
    e12(r) =                                                                   \
        e0(a) * e12(b) + e4(a) * e13(b) + e8(a) * e14(b) + e12(a) * e15(b);    \
    e1(r) = e1(a) * e0(b) + e5(a) * e1(b) + e9(a) * e2(b) + e13(a) * e3(b);    \
    e5(r) = e1(a) * e4(b) + e5(a) * e5(b) + e9(a) * e6(b) + e13(a) * e7(b);    \
    e9(r) = e1(a) * e8(b) + e5(a) * e9(b) + e9(a) * e10(b) + e13(a) * e11(b);  \
    e13(r) =                                                                   \
        e1(a) * e12(b) + e5(a) * e13(b) + e9(a) * e14(b) + e13(a) * e15(b);    \
    e2(r) = e2(a) * e0(b) + e6(a) * e1(b) + e10(a) * e2(b) + e14(a) * e3(b);   \
    e6(r) = e2(a) * e4(b) + e6(a) * e5(b) + e10(a) * e6(b) + e14(a) * e7(b);   \
    e10(r) =                                                                   \
        e2(a) * e8(b) + e6(a) * e9(b) + e10(a) * e10(b) + e14(a) * e11(b);     \
    e14(r) =                                                                   \
        e2(a) * e12(b) + e6(a) * e13(b) + e10(a) * e14(b) + e14(a) * e15(b);   \
    e3(r) = e3(a) * e0(b) + e7(a) * e1(b) + e11(a) * e2(b) + e15(a) * e3(b);   \
    e7(r) = e3(a) * e4(b) + e7(a) * e5(b) + e11(a) * e6(b) + e15(a) * e7(b);   \
    e11(r) =                                                                   \
        e3(a) * e8(b) + e7(a) * e9(b) + e11(a) * e10(b) + e15(a) * e11(b);     \
    e15(r) =                                                                   \
        e3(a) * e12(b) + e7(a) * e13(b) + e11(a) * e14(b) + e15(a) * e15(b);   \
  } while (0)

#define mat44_determinant(e)                                                   \
  (e3(e) * (e12(e) * e9(e) * e6(e) - e8(e) * e13(e) * e6(e) -                  \
            e12(e) * e5(e) * e10(e) + e4(e) * e13(e) * e10(e) +                \
            e8(e) * e5(e) * e14(e) - e4(e) * e9(e) * e14(e)) +                 \
   e7(e) * (e0(e) * e9(e) * e14(e) - e0(e) * e13(e) * e10(e) +                 \
            e12(e) * e1(e) * e10(e) - e8(e) * e1(e) * e14(e) +                 \
            e12(e) * e13(e) * e2(e) - e12(e) * e9(e) * e2(e)) +                \
   e11(e) * (e0(e) * e13(e) * e6(e) - e0(e) * e5(e) * e14(e) -                 \
             e12(e) * e1(e) * e6(e) + e4(e) * e1(e) * e14(e) +                 \
             e12(e) * e5(e) * e2(e) - e4(e) * e13(e) * e2(e)) +                \
   e15(e) * (-e8(e) * e5(e) * e2(e) - e0(e) * e9(e) * e6(e) +                  \
             e0(e) * e5(e) * e10(e) + e8(e) * e1(e) * e6(e) -                  \
             e4(e) * e1(e) * e10(e) + e4(e) * e9(e) * e2(e)))

#define mat44_inverse(r, e)                                                    \
  do {                                                                         \
    real_t det = mat44_determinant(e);                                         \
    det = r_one / det;                                                         \
    e0(r) = det * (e9(e) * e14(e) * e7(e) - e13(e) * e10(e) * e7(e) +          \
                   e13(e) * e6(e) * e11(e) - e5(e) * e14(e) * e11(e) -         \
                   e9(e) * e6(e) * e15(e) + e5(e) * e10(e) * e15(e));          \
    e1(r) = det * (e13(e) * e10(e) * e3(e) - e9(e) * e14(e) * e3(e) -          \
                   e13(e) * e2(e) * e11(e) + e1(e) * e14(e) * e11(e) +         \
                   e9(e) * e2(e) * e15(e) - e1(e) * e10(e) * e15(e));          \
    e2(r) = det * (e5(e) * e14(e) * e3(e) - e13(e) * e6(e) * e3(e) +           \
                   e13(e) * e2(e) * e7(e) - e1(e) * e14(e) * e7(e) -           \
                   e5(e) * e2(e) * e15(e) + e1(e) * e6(e) * e15(e));           \
    e3(r) = det * (e9(e) * e6(e) * e3(e) - e5(e) * e10(e) * e3(e) -            \
                   e9(e) * e2(e) * e7(e) + e1(e) * e10(e) * e7(e) +            \
                   e5(e) * e2(e) * e11(e) - e1(e) * e6(e) * e11(e));           \
    e4(r) = det * (e12(e) * e10(e) * e7(e) - e8(e) * e14(e) * e7(e) -          \
                   e12(e) * e6(e) * e11(e) + e4(e) * e14(e) * e11(e) +         \
                   e8(e) * e6(e) * e15(e) - e4(e) * e10(e) * e15(e));          \
    e5(r) = det * (e8(e) * e14(e) * e3(e) - e12(e) * e10(e) * e3(e) +          \
                   e12(e) * e2(e) * e11(e) - e0(e) * e14(e) * e11(e) -         \
                   e8(e) * e2(e) * e15(e) + e0(e) * e10(e) * e15(e));          \
    e6(r) = det * (e12(e) * e6(e) * e3(e) - e4(e) * e14(e) * e3(e) -           \
                   e12(e) * e2(e) * e7(e) + e0(e) * e14(e) * e7(e) +           \
                   e4(e) * e2(e) * e15(e) - e0(e) * e6(e) * e15(e));           \
    e7(r) = det * (e4(e) * e10(e) * e3(e) - e8(e) * e6(e) * e3(e) +            \
                   e8(e) * e2(e) * e7(e) - e0(e) * e10(e) * e7(e) -            \
                   e4(e) * e2(e) * e11(e) + e0(e) * e6(e) * e11(e));           \
    e8(r) = det * (e8(e) * e13(e) * e7(e) - e12(e) * e9(e) * e7(e) +           \
                   e12(e) * e5(e) * e11(e) - e4(e) * e13(e) * e11(e) -         \
                   e8(e) * e5(e) * e15(e) + e4(e) * e9(e) * e15(e));           \
    e9(r) = det * (e12(e) * e9(e) * e3(e) - e8(e) * e13(e) * e3(e) -           \
                   e12(e) * e1(e) * e11(e) + e0(e) * e13(e) * e11(e) +         \
                   e8(e) * e1(e) * e15(e) - e0(e) * e9(e) * e15(e));           \
    e10(r) = det * (e4(e) * e13(e) * e3(e) - e12(e) * e5(e) * e3(e) +          \
                    e12(e) * e1(e) * e7(e) - e0(e) * e13(e) * e7(e) -          \
                    e4(e) * e1(e) * e15(e) + e0(e) * e5(e) * e15(e));          \
    e11(r) = det * (e8(e) * e5(e) * e3(e) - e4(e) * e9(e) * e3(e) -            \
                    e8(e) * e1(e) * e7(e) + e0(e) * e9(e) * e7(e) +            \
                    e4(e) * e1(e) * e11(e) - e0(e) * e5(e) * e11(e));          \
    e12(r) = det * (e12(e) * e9(e) * e6(e) - e8(e) * e13(e) * e6(e) -          \
                    e12(e) * e5(e) * e10(e) + e4(e) * e13(e) * e10(e) +        \
                    e8(e) * e5(e) * e14(e) - e4(e) * e9(e) * e14(e));          \
    e13(r) = det * (e8(e) * e13(e) * e2(e) - e12(e) * e9(e) * e2(e) +          \
                    e12(e) * e1(e) * e10(e) - e0(e) * e13(e) * e10(e) -        \
                    e8(e) * e1(e) * e14(e) + e0(e) * e9(e) * e14(e));          \
    e14(r) = det * (e12(e) * e5(e) * e2(e) - e4(e) * e13(e) * e2(e) -          \
                    e12(e) * e1(e) * e6(e) + e0(e) * e13(e) * e6(e) +          \
                    e4(e) * e1(e) * e14(e) - e0(e) * e5(e) * e14(e));          \
    e15(r) = det * (e4(e) * e9(e) * e2(e) - e8(e) * e5(e) * e2(e) +            \
                    e8(e) * e1(e) * e6(e) - e0(e) * e9(e) * e6(e) -            \
                    e4(e) * e1(e) * e10(e) + e0(e) * e5(e) * e10(e));          \
  } while (0)

#define mat44_transpose(r, e)                                                  \
  do {                                                                         \
    e0(r) = e0(e);                                                             \
    e1(r) = e4(e);                                                             \
    e2(r) = e8(e);                                                             \
    e3(r) = e12(e);                                                            \
    e4(r) = e1(e);                                                             \
    e5(r) = e5(e);                                                             \
    e6(r) = e9(e);                                                             \
    e7(r) = e13(e);                                                            \
    e8(r) = e2(e);                                                             \
    e9(r) = e6(e);                                                             \
    e10(r) = e10(e);                                                           \
    e11(r) = e14(e);                                                           \
    e12(r) = e3(e);                                                            \
    e13(r) = e7(e);                                                            \
    e14(r) = e11(e);                                                           \
    e15(r) = e15(e);                                                           \
  } while (0)

#define mat44_transform2(r, e, v)                                              \
  do {                                                                         \
    vx(r) = e0(e) * vx(v) + e4(e) * vy(v) + e12(e);                            \
    vy(r) = e1(e) * vx(v) + e5(e) * vy(v) + e13(e);                            \
  } while (0)

#define mat44_transform3(r, e, v)                                              \
  do {                                                                         \
    vx(r) = e0(e) * vx(v) + e4(e) * vy(v) + e8(e) * vz(v) + e12(e);            \
    vy(r) = e1(e) * vx(v) + e5(e) * vy(v) + e9(e) * vz(v) + e13(e);            \
    vz(r) = e2(e) * vx(v) + e6(e) * vy(v) + e10(e) * vz(v) + e14(e);           \
  } while (0)

void mat44_transformation(mat44_t r, real_t x, real_t y, real_t theta,
                          real_t sx, real_t sy, real_t ox, real_t oy, real_t kx,
                          real_t ky);

void mat44_rotatex(mat44_t r, real_t theta);
void mat44_rotatey(mat44_t r, real_t theta);
void mat44_rotatez(mat44_t r, real_t theta);
void mat44_rotateaxis(mat44_t r, real_t theta, vec3_t axis);

void mat44_ortho(mat44_t r, real_t left, real_t right, real_t bottom,
                 real_t top, real_t near, real_t far);
void mat44_frustum(mat44_t r, real_t left, real_t right, real_t bottom,
                   real_t top, real_t near, real_t far);
void mat44_perspective(mat44_t r, real_t fovy, real_t aspect, real_t near,
                       real_t far);
void mat44_lookat(mat44_t r, vec3_t eye, vec3_t target, vec3_t up);

#define mat44_tomat33(r3, e4)                                                  \
  do {                                                                         \
    e0(r3) = e0(e4);                                                           \
    e1(r3) = e1(e4);                                                           \
    e2(r3) = e2(e4);                                                           \
    e3(r3) = e4(e4);                                                           \
    e4(r3) = e5(e4);                                                           \
    e5(r3) = e6(e4);                                                           \
    e6(r3) = e8(e4);                                                           \
    e7(r3) = e9(e4);                                                           \
    e8(r3) = e10(e4);                                                          \
  } while (0)

#ifdef __cplusplus
};
#endif

#endif /* __MATRIX_H__ */
