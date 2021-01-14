/*
 *  quaternion.h
 *
 *  copyright (c) 2019-2021 Xiongfei Shi
 *
 *  author: Xiongfei Shi <jenson.shixf(a)gmail.com>
 *  license: Apache-2.0
 *
 *  https://github.com/shixiongfei/math
 */

#ifndef __QUATERNION_H__
#define __QUATERNION_H__

#include "matrix.h"
#include "vector.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef real_t quat_t[4];

#define qw(q) q[0]
#define qx(q) q[1]
#define qy(q) q[2]
#define qz(q) q[3]

/**
 *---------------------------------------------
 *  Quaternion
 *---------------------------------------------
 **/

/* qw*qw + qx*qx + qy*qy + qz*qz */
#define quat_lensq(q)                                                          \
  (qw(q) * qw(q) + qx(q) * qx(q) + qy(q) * qy(q) + qz(q) * qz(q))

/* sqrt(qw*qw + qx*qx + qy*qy + qz*qz) */
#define quat_len(q) r_sqrt(quat_lensq(q))

/* rw,rx,ry,rz = aw+bw, ax+bx, ay+by, az+bz */
#define quat_add(r, a, b)                                                      \
  do {                                                                         \
    qw(r) = qw(a) + qw(b);                                                     \
    qx(r) = qx(a) + qx(b);                                                     \
    qy(r) = qy(a) + qy(b);                                                     \
    qz(r) = qz(a) + qz(b);                                                     \
  } while (0)

/* rw,rx,ry,rz = aw-bw, ax-bx, ay-by, az-bz */
#define quat_sub(r, a, b)                                                      \
  do {                                                                         \
    qw(r) = qw(a) - qw(b);                                                     \
    qx(r) = qx(a) - qx(b);                                                     \
    qy(r) = qy(a) - qy(b);                                                     \
    qz(r) = qz(a) - qz(b);                                                     \
  } while (0)

/**
 * rw = aw*bw - ax*bx - ay*by - az*bz
 * rx = ax*bw + bx*aw + by*az - ay*bz
 * ry = ay*bw + by*aw + ax*bz - bx*az
 * rz = az*bw + bz*aw + bx*ay - ax*by
 **/
#define quat_mul(r, a, b)                                                      \
  do {                                                                         \
    qw(r) = qw(a) * qw(b) - qx(a) * qx(b) - qy(a) * qy(b) - qz(a) * qz(b);     \
    qx(r) = qx(a) * qw(b) + qx(b) * qw(a) + qy(b) * qz(a) - qy(a) * qz(b);     \
    qy(r) = qy(a) * qw(b) + qy(b) * qw(a) + qx(a) * qz(b) - qx(b) * qz(a);     \
    qz(r) = qz(a) * qw(b) + qz(b) * qw(a) + qx(b) * qy(a) - qx(a) * qy(b);     \
  } while (0)

/* rw,rx,ry,rz = -qw, -qx, -qy, -qz */
#define quat_neg(r, q)                                                         \
  do {                                                                         \
    qw(r) = -qw(q);                                                            \
    qx(r) = -qx(q);                                                            \
    qy(r) = -qy(q);                                                            \
    qz(r) = -qz(q);                                                            \
  } while (0)

/* rw,rx,ry,rz = qw, -qx, -qy, -qz */
#define quat_conjugate(r, q)                                                   \
  do {                                                                         \
    qw(r) = qw(q);                                                             \
    qx(r) = -qx(q);                                                            \
    qy(r) = -qy(q);                                                            \
    qz(r) = -qz(q);                                                            \
  } while (0)

/* aw*bw + ax*bx + ay*by + az*bz */
#define quat_dot(a, b)                                                         \
  (qw(a) * qw(b) + qx(a) * qx(b) + qy(a) * qy(b) + qz(a) * qz(b))

/* qw,qx,qy,qz = qw*(len/qlen), qx*(len/qlen), qy*(len/qlen), qz*(len/qlen) */
real_t quat_normalize(quat_t q, real_t length);

void quat_slerp(quat_t r, const quat_t from, const quat_t to, real_t t);
void quat_rotate(vec3_t r, const quat_t q, const vec3_t v);
void quat_tomatrix(mat33_t m, const quat_t q);
void quat_toeuler(vec3_t r, const quat_t q);
void quat_fromeuler(quat_t r, const vec3_t v);
void quat_fromangleaxis(quat_t r, const vec3_t v, real_t theta);

#ifdef __cplusplus
};
#endif

#endif /* __QUATERNION_H__ */
