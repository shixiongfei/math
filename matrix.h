/*
 *  matrix.h
 *
 *  copyright (c) 2019 Xiongfei Shi
 *
 *  author: Xiongfei Shi <jenson.shixf(a)gmail.com>
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
 * | e0  e3  e6 |
 * | e1  e4  e7 |
 * | e2  e5  e8 |
 **/
typedef real_t mat33_t[9];

/**
 * | e0 e4 e8  e12 |
 * | e1 e5 e9  e13 |
 * | e2 e6 e10 e14 |
 * | e3 e7 e11 e15 |
 **/
typedef real_t mat44_t[16];

#define m3e11(e) e[0]
#define m3e21(e) e[1]
#define m3e31(e) e[2]
#define m3e12(e) e[3]
#define m3e22(e) e[4]
#define m3e32(e) e[5]
#define m3e13(e) e[6]
#define m3e23(e) e[7]
#define m3e33(e) e[8]

#define m4e11(e) e[0]
#define m4e21(e) e[1]
#define m4e31(e) e[2]
#define m4e41(e) e[3]
#define m4e12(e) e[4]
#define m4e22(e) e[5]
#define m4e32(e) e[6]
#define m4e42(e) e[7]
#define m4e13(e) e[8]
#define m4e23(e) e[9]
#define m4e33(e) e[10]
#define m4e43(e) e[11]
#define m4e14(e) e[12]
#define m4e24(e) e[13]
#define m4e34(e) e[14]
#define m4e44(e) e[15]

/**
 *---------------------------------------------
 *  Matrix33
 *---------------------------------------------
 **/

#define mat33_zero(e) memset(e, 0, sizeof(real_t) * 9)

#define mat33_identity(e)                                                      \
  do {                                                                         \
    mat33_zero(e);                                                             \
    m3e11(e) = m3e22(e) = m3e33(e) = r_one;                                    \
  } while (0)

#define mat33_add(r, a, b)                                                     \
  do {                                                                         \
    m3e11(r) = m3e11(a) + m3e11(b);                                            \
    m3e21(r) = m3e21(a) + m3e21(b);                                            \
    m3e31(r) = m3e31(a) + m3e31(b);                                            \
    m3e12(r) = m3e12(a) + m3e12(b);                                            \
    m3e22(r) = m3e22(a) + m3e22(b);                                            \
    m3e32(r) = m3e32(a) + m3e32(b);                                            \
    m3e13(r) = m3e13(a) + m3e13(b);                                            \
    m3e23(r) = m3e23(a) + m3e23(b);                                            \
    m3e33(r) = m3e33(a) + m3e33(b);                                            \
  } while (0)

#define mat33_sub(r, a, b)                                                     \
  do {                                                                         \
    m3e11(r) = m3e11(a) - m3e11(b);                                            \
    m3e21(r) = m3e21(a) - m3e21(b);                                            \
    m3e31(r) = m3e31(a) - m3e31(b);                                            \
    m3e12(r) = m3e12(a) - m3e12(b);                                            \
    m3e22(r) = m3e22(a) - m3e22(b);                                            \
    m3e32(r) = m3e32(a) - m3e32(b);                                            \
    m3e13(r) = m3e13(a) - m3e13(b);                                            \
    m3e23(r) = m3e23(a) - m3e23(b);                                            \
    m3e33(r) = m3e33(a) - m3e33(b);                                            \
  } while (0)

#define mat33_mul(r, a, b)                                                     \
  do {                                                                         \
    m3e11(r) =                                                                 \
        m3e11(a) * m3e11(b) + m3e12(a) * m3e21(b) + m3e13(a) * m3e31(b);       \
    m3e12(r) =                                                                 \
        m3e11(a) * m3e12(b) + m3e12(a) * m3e22(b) + m3e13(a) * m3e32(b);       \
    m3e13(r) =                                                                 \
        m3e11(a) * m3e13(b) + m3e12(a) * m3e23(b) + m3e13(a) * m3e33(b);       \
    m3e21(r) =                                                                 \
        m3e21(a) * m3e11(b) + m3e22(a) * m3e21(b) + m3e23(a) * m3e31(b);       \
    m3e22(r) =                                                                 \
        m3e21(a) * m3e12(b) + m3e22(a) * m3e22(b) + m3e23(a) * m3e32(b);       \
    m3e23(r) =                                                                 \
        m3e21(a) * m3e13(b) + m3e22(a) * m3e23(b) + m3e23(a) * m3e33(b);       \
    m3e31(r) =                                                                 \
        m3e31(a) * m3e11(b) + m3e32(a) * m3e21(b) + m3e33(a) * m3e31(b);       \
    m3e32(r) =                                                                 \
        m3e31(a) * m3e12(b) + m3e32(a) * m3e22(b) + m3e33(a) * m3e32(b);       \
    m3e33(r) =                                                                 \
        m3e31(a) * m3e13(b) + m3e32(a) * m3e23(b) + m3e33(a) * m3e33(b);       \
  } while (0)

#define mat33_determinant(e)                                                   \
  (m3e11(e) * (m3e22(e) * m3e33(e) - m3e32(e) * m3e23(e)) -                    \
   m3e21(e) * (m3e12(e) * m3e33(e) - m3e32(e) * m3e13(e)) +                    \
   m3e31(e) * (m3e12(e) * m3e23(e) - m3e22(e) * m3e13(e)))

#define mat33_inverse(r, e)                                                    \
  do {                                                                         \
    real_t det = mat33_determinant(e);                                         \
    det = r_one / det;                                                         \
    m3e11(r) = det * (m3e22(e) * m3e33(e) - m3e32(e) * m3e23(e));              \
    m3e21(r) = -det * (m3e21(e) * m3e33(e) - m3e31(e) * m3e23(e));             \
    m3e31(r) = det * (m3e21(e) * m3e32(e) - m3e31(e) * m3e22(e));              \
    m3e12(r) = -det * (m3e12(e) * m3e33(e) - m3e32(e) * m3e13(e));             \
    m3e22(r) = det * (m3e11(e) * m3e33(e) - m3e31(e) * m3e13(e));              \
    m3e32(r) = -det * (m3e11(e) * m3e32(e) - m3e31(e) * m3e12(e));             \
    m3e13(r) = det * (m3e12(e) * m3e23(e) - m3e22(e) * m3e13(e));              \
    m3e23(r) = -det * (m3e11(e) * m3e23(e) - m3e21(e) * m3e13(e));             \
    m3e33(r) = det * (m3e11(e) * m3e22(e) - m3e21(e) * m3e12(e));              \
  } while (0)

#define mat33_transpose(r, e)                                                  \
  do {                                                                         \
    m3e11(r) = m3e11(e);                                                       \
    m3e21(r) = m3e12(e);                                                       \
    m3e31(r) = m3e13(e);                                                       \
    m3e12(r) = m3e21(e);                                                       \
    m3e22(r) = m3e22(e);                                                       \
    m3e32(r) = m3e23(e);                                                       \
    m3e13(r) = m3e31(e);                                                       \
    m3e23(r) = m3e32(e);                                                       \
    m3e33(r) = m3e33(e);                                                       \
  } while (0)

#define mat33_transform2(r, e, v)                                              \
  do {                                                                         \
    vx(r) = m3e11(e) * vx(v) + m3e12(e) * vy(v) + m3e13(e);                    \
    vy(r) = m3e21(e) * vx(v) + m3e22(e) * vy(v) + m3e23(e);                    \
  } while (0)

#define mat33_transform3(r, e, v)                                              \
  do {                                                                         \
    vx(r) = m3e11(e) * vx(v) + m3e12(e) * vy(v) + m3e13(e) * vz(v);            \
    vy(r) = m3e21(e) * vx(v) + m3e22(e) * vy(v) + m3e23(e) * vz(v);            \
    vz(r) = m3e31(e) * vx(v) + m3e32(e) * vy(v) + m3e33(e) * vz(v);            \
  } while (0)

void mat33_transformation(mat33_t r, real_t x, real_t y, real_t theta,
                          real_t sx, real_t sy, real_t ox, real_t oy, real_t kx,
                          real_t ky);

/**
 *---------------------------------------------
 *  Matrix44
 *---------------------------------------------
 **/

#define mat44_zero(e) memset(e, 0, sizeof(real_t) * 16)

#define mat44_identity(e)                                                      \
  do {                                                                         \
    mat44_zero(e);                                                             \
    m4e11(e) = m4e22(e) = m4e33(e) = m4e44(e) = r_one;                         \
  } while (0)

#define mat44_translate2(e, v)                                                 \
  do {                                                                         \
    mat44_identity(e);                                                         \
    m4e14(e) = vx(v);                                                          \
    m4e24(e) = vy(v);                                                          \
  } while (0)

#define mat44_translate3(e, v)                                                 \
  do {                                                                         \
    mat44_identity(e);                                                         \
    m4e14(e) = vx(v);                                                          \
    m4e24(e) = vy(v);                                                          \
    m4e34(e) = vz(v);                                                          \
  } while (0)

#define mat44_scale2(e, v)                                                     \
  do {                                                                         \
    mat44_identity(e);                                                         \
    m4e11(e) = vx(v);                                                          \
    m4e22(e) = vy(v);                                                          \
  } while (0)

#define mat44_scale3(e, v)                                                     \
  do {                                                                         \
    mat44_identity(e);                                                         \
    m4e11(e) = vx(v);                                                          \
    m4e22(e) = vy(v);                                                          \
    m4e33(e) = vz(v);                                                          \
  } while (0)

#define mat44_shear2(e, v)                                                     \
  do {                                                                         \
    mat44_identity(e);                                                         \
    m4e21(e) = vx(v);                                                          \
    m4e12(e) = vy(v);                                                          \
  } while (0)

#define mat44_shear3(e, v)                                                     \
  do {                                                                         \
    mat44_identity(e);                                                         \
    m4e21(e) = m4e31(e) = vx(v);                                               \
    m4e12(e) = m4e32(e) = vy(v);                                               \
    m4e13(e) = m4e23(e) = vz(v);                                               \
  } while (0)

#define mat44_add(r, a, b)                                                     \
  do {                                                                         \
    m4e11(r) = m4e11(a) + m4e11(b);                                            \
    m4e21(r) = m4e21(a) + m4e21(b);                                            \
    m4e31(r) = m4e31(a) + m4e31(b);                                            \
    m4e41(r) = m4e41(a) + m4e41(b);                                            \
    m4e12(r) = m4e12(a) + m4e12(b);                                            \
    m4e22(r) = m4e22(a) + m4e22(b);                                            \
    m4e32(r) = m4e32(a) + m4e32(b);                                            \
    m4e42(r) = m4e42(a) + m4e42(b);                                            \
    m4e13(r) = m4e13(a) + m4e13(b);                                            \
    m4e23(r) = m4e23(a) + m4e23(b);                                            \
    m4e33(r) = m4e33(a) + m4e33(b);                                            \
    m4e43(r) = m4e43(a) + m4e43(b);                                            \
    m4e14(r) = m4e14(a) + m4e14(b);                                            \
    m4e24(r) = m4e24(a) + m4e24(b);                                            \
    m4e34(r) = m4e34(a) + m4e34(b);                                            \
    m4e44(r) = m4e44(a) + m4e44(b);                                            \
  } while (0)

#define mat44_sub(r, a, b)                                                     \
  do {                                                                         \
    m4e11(r) = m4e11(a) - m4e11(b);                                            \
    m4e21(r) = m4e21(a) - m4e21(b);                                            \
    m4e31(r) = m4e31(a) - m4e31(b);                                            \
    m4e41(r) = m4e41(a) - m4e41(b);                                            \
    m4e12(r) = m4e12(a) - m4e12(b);                                            \
    m4e22(r) = m4e22(a) - m4e22(b);                                            \
    m4e32(r) = m4e32(a) - m4e32(b);                                            \
    m4e42(r) = m4e42(a) - m4e42(b);                                            \
    m4e13(r) = m4e13(a) - m4e13(b);                                            \
    m4e23(r) = m4e23(a) - m4e23(b);                                            \
    m4e33(r) = m4e33(a) - m4e33(b);                                            \
    m4e43(r) = m4e43(a) - m4e43(b);                                            \
    m4e14(r) = m4e14(a) - m4e14(b);                                            \
    m4e24(r) = m4e24(a) - m4e24(b);                                            \
    m4e34(r) = m4e34(a) - m4e34(b);                                            \
    m4e44(r) = m4e44(a) - m4e44(b);                                            \
  } while (0)

#define mat44_mul(r, a, b)                                                     \
  do {                                                                         \
    m4e11(r) = m4e11(a) * m4e11(b) + m4e12(a) * m4e21(b) +                     \
               m4e13(a) * m4e31(b) + m4e14(a) * m4e41(b);                      \
    m4e21(r) = m4e21(a) * m4e11(b) + m4e22(a) * m4e21(b) +                     \
               m4e23(a) * m4e31(b) + m4e24(a) * m4e41(b);                      \
    m4e31(r) = m4e31(a) * m4e11(b) + m4e32(a) * m4e21(b) +                     \
               m4e33(a) * m4e31(b) + m4e34(a) * m4e41(b);                      \
    m4e41(r) = m4e41(a) * m4e11(b) + m4e42(a) * m4e21(b) +                     \
               m4e43(a) * m4e31(b) + m4e44(a) * m4e41(b);                      \
    m4e12(r) = m4e11(a) * m4e12(b) + m4e12(a) * m4e22(b) +                     \
               m4e13(a) * m4e32(b) + m4e14(a) * m4e42(b);                      \
    m4e22(r) = m4e21(a) * m4e12(b) + m4e22(a) * m4e22(b) +                     \
               m4e23(a) * m4e32(b) + m4e24(a) * m4e42(b);                      \
    m4e32(r) = m4e31(a) * m4e12(b) + m4e32(a) * m4e22(b) +                     \
               m4e33(a) * m4e32(b) + m4e34(a) * m4e42(b);                      \
    m4e42(r) = m4e41(a) * m4e12(b) + m4e42(a) * m4e22(b) +                     \
               m4e43(a) * m4e32(b) + m4e44(a) * m4e42(b);                      \
    m4e13(r) = m4e11(a) * m4e13(b) + m4e12(a) * m4e23(b) +                     \
               m4e13(a) * m4e33(b) + m4e14(a) * m4e43(b);                      \
    m4e23(r) = m4e21(a) * m4e13(b) + m4e22(a) * m4e23(b) +                     \
               m4e23(a) * m4e33(b) + m4e24(a) * m4e43(b);                      \
    m4e33(r) = m4e31(a) * m4e13(b) + m4e32(a) * m4e23(b) +                     \
               m4e33(a) * m4e33(b) + m4e34(a) * m4e43(b);                      \
    m4e43(r) = m4e41(a) * m4e13(b) + m4e42(a) * m4e23(b) +                     \
               m4e43(a) * m4e33(b) + m4e44(a) * m4e43(b);                      \
    m4e14(r) = m4e11(a) * m4e14(b) + m4e12(a) * m4e24(b) +                     \
               m4e13(a) * m4e34(b) + m4e14(a) * m4e44(b);                      \
    m4e24(r) = m4e21(a) * m4e14(b) + m4e22(a) * m4e24(b) +                     \
               m4e23(a) * m4e34(b) + m4e24(a) * m4e44(b);                      \
    m4e34(r) = m4e31(a) * m4e14(b) + m4e32(a) * m4e24(b) +                     \
               m4e33(a) * m4e34(b) + m4e34(a) * m4e44(b);                      \
    m4e44(r) = m4e41(a) * m4e14(b) + m4e42(a) * m4e24(b) +                     \
               m4e43(a) * m4e34(b) + m4e44(a) * m4e44(b);                      \
  } while (0)

#define mat44_determinant(e)                                                   \
  (m4e41(e) *                                                                  \
       (+m4e14(e) * m4e23(e) * m4e32(e) - m4e13(e) * m4e24(e) * m4e32(e) -     \
        m4e14(e) * m4e22(e) * m4e33(e) + m4e12(e) * m4e24(e) * m4e33(e) +      \
        m4e13(e) * m4e22(e) * m4e34(e) - m4e12(e) * m4e23(e) * m4e34(e)) +     \
   m4e42(e) *                                                                  \
       (+m4e11(e) * m4e23(e) * m4e34(e) - m4e11(e) * m4e24(e) * m4e33(e) +     \
        m4e14(e) * m4e21(e) * m4e33(e) - m4e13(e) * m4e21(e) * m4e34(e) +      \
        m4e13(e) * m4e24(e) * m4e31(e) - m4e14(e) * m4e23(e) * m4e31(e)) +     \
   m4e43(e) *                                                                  \
       (+m4e11(e) * m4e24(e) * m4e32(e) - m4e11(e) * m4e22(e) * m4e34(e) -     \
        m4e14(e) * m4e21(e) * m4e32(e) + m4e12(e) * m4e21(e) * m4e34(e) +      \
        m4e14(e) * m4e22(e) * m4e31(e) - m4e12(e) * m4e24(e) * m4e31(e)) +     \
   m4e44(e) *                                                                  \
       (-m4e13(e) * m4e22(e) * m4e31(e) - m4e11(e) * m4e23(e) * m4e32(e) +     \
        m4e11(e) * m4e22(e) * m4e33(e) + m4e13(e) * m4e21(e) * m4e32(e) -      \
        m4e12(e) * m4e21(e) * m4e33(e) + m4e12(e) * m4e23(e) * m4e31(e)))

#define mat44_inverse(r, e)                                                    \
  do {                                                                         \
    real_t det = mat44_determinant(e);                                         \
    det = r_one / det;                                                         \
    m4e11(r) =                                                                 \
        det *                                                                  \
        (m4e23(e) * m4e34(e) * m4e42(e) - m4e24(e) * m4e33(e) * m4e42(e) +     \
         m4e24(e) * m4e32(e) * m4e43(e) - m4e22(e) * m4e34(e) * m4e43(e) -     \
         m4e23(e) * m4e32(e) * m4e44(e) + m4e22(e) * m4e33(e) * m4e44(e));     \
    m4e21(r) =                                                                 \
        det *                                                                  \
        (m4e24(e) * m4e33(e) * m4e41(e) - m4e23(e) * m4e34(e) * m4e41(e) -     \
         m4e24(e) * m4e31(e) * m4e43(e) + m4e21(e) * m4e34(e) * m4e43(e) +     \
         m4e23(e) * m4e31(e) * m4e44(e) - m4e21(e) * m4e33(e) * m4e44(e));     \
    m4e31(r) =                                                                 \
        det *                                                                  \
        (m4e22(e) * m4e34(e) * m4e41(e) - m4e24(e) * m4e32(e) * m4e41(e) +     \
         m4e24(e) * m4e31(e) * m4e42(e) - m4e21(e) * m4e34(e) * m4e42(e) -     \
         m4e22(e) * m4e31(e) * m4e44(e) + m4e21(e) * m4e32(e) * m4e44(e));     \
    m4e41(r) =                                                                 \
        det *                                                                  \
        (m4e23(e) * m4e32(e) * m4e41(e) - m4e22(e) * m4e33(e) * m4e41(e) -     \
         m4e23(e) * m4e31(e) * m4e42(e) + m4e21(e) * m4e33(e) * m4e42(e) +     \
         m4e22(e) * m4e31(e) * m4e43(e) - m4e21(e) * m4e32(e) * m4e43(e));     \
    m4e12(r) =                                                                 \
        det *                                                                  \
        (m4e14(e) * m4e33(e) * m4e42(e) - m4e13(e) * m4e34(e) * m4e42(e) -     \
         m4e14(e) * m4e32(e) * m4e43(e) + m4e12(e) * m4e34(e) * m4e43(e) +     \
         m4e13(e) * m4e32(e) * m4e44(e) - m4e12(e) * m4e33(e) * m4e44(e));     \
    m4e22(r) =                                                                 \
        det *                                                                  \
        (m4e13(e) * m4e34(e) * m4e41(e) - m4e14(e) * m4e33(e) * m4e41(e) +     \
         m4e14(e) * m4e31(e) * m4e43(e) - m4e11(e) * m4e34(e) * m4e43(e) -     \
         m4e13(e) * m4e31(e) * m4e44(e) + m4e11(e) * m4e33(e) * m4e44(e));     \
    m4e32(r) =                                                                 \
        det *                                                                  \
        (m4e14(e) * m4e32(e) * m4e41(e) - m4e12(e) * m4e34(e) * m4e41(e) -     \
         m4e14(e) * m4e31(e) * m4e42(e) + m4e11(e) * m4e34(e) * m4e42(e) +     \
         m4e12(e) * m4e31(e) * m4e44(e) - m4e11(e) * m4e32(e) * m4e44(e));     \
    m4e42(r) =                                                                 \
        det *                                                                  \
        (m4e12(e) * m4e33(e) * m4e41(e) - m4e13(e) * m4e32(e) * m4e41(e) +     \
         m4e13(e) * m4e31(e) * m4e42(e) - m4e11(e) * m4e33(e) * m4e42(e) -     \
         m4e12(e) * m4e31(e) * m4e43(e) + m4e11(e) * m4e32(e) * m4e43(e));     \
    m4e13(r) =                                                                 \
        det *                                                                  \
        (m4e13(e) * m4e24(e) * m4e42(e) - m4e14(e) * m4e23(e) * m4e42(e) +     \
         m4e14(e) * m4e22(e) * m4e43(e) - m4e12(e) * m4e24(e) * m4e43(e) -     \
         m4e13(e) * m4e22(e) * m4e44(e) + m4e12(e) * m4e23(e) * m4e44(e));     \
    m4e23(r) =                                                                 \
        det *                                                                  \
        (m4e14(e) * m4e23(e) * m4e41(e) - m4e13(e) * m4e24(e) * m4e41(e) -     \
         m4e14(e) * m4e21(e) * m4e43(e) + m4e11(e) * m4e24(e) * m4e43(e) +     \
         m4e13(e) * m4e21(e) * m4e44(e) - m4e11(e) * m4e23(e) * m4e44(e));     \
    m4e33(r) =                                                                 \
        det *                                                                  \
        (m4e12(e) * m4e24(e) * m4e41(e) - m4e14(e) * m4e22(e) * m4e41(e) +     \
         m4e14(e) * m4e21(e) * m4e42(e) - m4e11(e) * m4e24(e) * m4e42(e) -     \
         m4e12(e) * m4e21(e) * m4e44(e) + m4e11(e) * m4e22(e) * m4e44(e));     \
    m4e43(r) =                                                                 \
        det *                                                                  \
        (m4e13(e) * m4e22(e) * m4e41(e) - m4e12(e) * m4e23(e) * m4e41(e) -     \
         m4e13(e) * m4e21(e) * m4e42(e) + m4e11(e) * m4e23(e) * m4e42(e) +     \
         m4e12(e) * m4e21(e) * m4e43(e) - m4e11(e) * m4e22(e) * m4e43(e));     \
    m4e14(r) =                                                                 \
        det *                                                                  \
        (m4e14(e) * m4e23(e) * m4e32(e) - m4e13(e) * m4e24(e) * m4e32(e) -     \
         m4e14(e) * m4e22(e) * m4e33(e) + m4e12(e) * m4e24(e) * m4e33(e) +     \
         m4e13(e) * m4e22(e) * m4e34(e) - m4e12(e) * m4e23(e) * m4e34(e));     \
    m4e24(r) =                                                                 \
        det *                                                                  \
        (m4e13(e) * m4e24(e) * m4e31(e) - m4e14(e) * m4e23(e) * m4e31(e) +     \
         m4e14(e) * m4e21(e) * m4e33(e) - m4e11(e) * m4e24(e) * m4e33(e) -     \
         m4e13(e) * m4e21(e) * m4e34(e) + m4e11(e) * m4e23(e) * m4e34(e));     \
    m4e34(r) =                                                                 \
        det *                                                                  \
        (m4e14(e) * m4e22(e) * m4e31(e) - m4e12(e) * m4e24(e) * m4e31(e) -     \
         m4e14(e) * m4e21(e) * m4e32(e) + m4e11(e) * m4e24(e) * m4e32(e) +     \
         m4e12(e) * m4e21(e) * m4e34(e) - m4e11(e) * m4e22(e) * m4e34(e));     \
    m4e44(r) =                                                                 \
        det *                                                                  \
        (m4e12(e) * m4e23(e) * m4e31(e) - m4e13(e) * m4e22(e) * m4e31(e) +     \
         m4e13(e) * m4e21(e) * m4e32(e) - m4e11(e) * m4e23(e) * m4e32(e) -     \
         m4e12(e) * m4e21(e) * m4e33(e) + m4e11(e) * m4e22(e) * m4e33(e));     \
  } while (0)

#define mat44_transpose(r, e)                                                  \
  do {                                                                         \
    m4e11(r) = m4e11(e);                                                       \
    m4e21(r) = m4e12(e);                                                       \
    m4e31(r) = m4e13(e);                                                       \
    m4e41(r) = m4e14(e);                                                       \
    m4e12(r) = m4e21(e);                                                       \
    m4e22(r) = m4e22(e);                                                       \
    m4e32(r) = m4e23(e);                                                       \
    m4e42(r) = m4e24(e);                                                       \
    m4e13(r) = m4e31(e);                                                       \
    m4e23(r) = m4e32(e);                                                       \
    m4e33(r) = m4e33(e);                                                       \
    m4e43(r) = m4e34(e);                                                       \
    m4e14(r) = m4e41(e);                                                       \
    m4e24(r) = m4e42(e);                                                       \
    m4e34(r) = m4e43(e);                                                       \
    m4e44(r) = m4e44(e);                                                       \
  } while (0)

#define mat44_transform2(r, e, v)                                              \
  do {                                                                         \
    vx(r) = m4e11(e) * vx(v) + m4e12(e) * vy(v) + m4e14(e);                    \
    vy(r) = m4e21(e) * vx(v) + m4e22(e) * vy(v) + m4e24(e);                    \
  } while (0)

#define mat44_transform3(r, e, v)                                              \
  do {                                                                         \
    vx(r) = m4e11(e) * vx(v) + m4e12(e) * vy(v) + m4e13(e) * vz(v) + m4e14(e); \
    vy(r) = m4e21(e) * vx(v) + m4e22(e) * vy(v) + m4e23(e) * vz(v) + m4e24(e); \
    vz(r) = m4e31(e) * vx(v) + m4e32(e) * vy(v) + m4e33(e) * vz(v) + m4e34(e); \
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
void mat44_perspective(mat44_t r, real_t fovy, real_t aspect, real_t near,
                       real_t far);

#ifdef __cplusplus
};
#endif

#endif /* __MATRIX_H__ */
