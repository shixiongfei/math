/*
 *  vector.h
 *
 *  copyright (c) 2019 Xiongfei Shi
 *
 *  author: Xiongfei Shi <jenson.shixf(a)gmail.com>
 *  license: Apache-2.0
 *
 *  https://github.com/shixiongfei/math
 */

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "real.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef real_t vec2_t[2];
typedef real_t vec3_t[3];
typedef real_t vec4_t[4];

#define vx(v) v[0]
#define vy(v) v[1]
#define vz(v) v[2]
#define vw(v) v[3]

/**
 *---------------------------------------------
 *  Vector2
 *---------------------------------------------
 **/

#define vec2_zero(v) (vx(v) = vy(v) = r_zero)

/* vx*vx + vy*vy */
#define vec2_lensq(v) (vx(v) * vx(v) + vy(v) * vy(v))

/* sqrt(vx*vx + vy*vy) */
#define vec2_len(v) r_sqrt(vec2_lensq(v))

/* ax*bx + ay*by */
#define vec2_dot(a, b) (vx(a) * vx(b) + vy(a) * vy(b))

/* ax*by - ay*bx */
#define vec2_cross(a, b) (vx(a) * vy(b) - vy(a) * vx(b))

/* rx,ry = -vx, -vy */
#define vec2_neg(r, v)                                                         \
  do {                                                                         \
    vx(r) = -vx(v);                                                            \
    vy(r) = -vy(v);                                                            \
  } while (0)

/* rx,ry = ax+bx, ay+by */
#define vec2_add(r, a, b)                                                      \
  do {                                                                         \
    vx(r) = vx(a) + vx(b);                                                     \
    vy(r) = vy(a) + vy(b);                                                     \
  } while (0)

/* rx,ry = ax-bx, ay-by */
#define vec2_sub(r, a, b)                                                      \
  do {                                                                         \
    vx(r) = vx(a) - vx(b);                                                     \
    vy(r) = vy(a) - vy(b);                                                     \
  } while (0)

/* rx,ry = ax*bx, ay*by */
#define vec2_mul(r, a, b)                                                      \
  do {                                                                         \
    vx(r) = vx(a) * vx(b);                                                     \
    vy(r) = vy(a) * vy(b);                                                     \
  } while (0)

/* rx,ry = ax/bx, ay/by */
#define vec2_div(r, a, b)                                                      \
  do {                                                                         \
    vx(r) = vx(a) / vx(b);                                                     \
    vy(r) = vy(a) / vy(b);                                                     \
  } while (0)

/* rx,ry = vx*s, vy*s */
#define vec2_scale(r, v, s)                                                    \
  do {                                                                         \
    vx(r) = vx(v) * (s);                                                       \
    vy(r) = vy(v) * (s);                                                       \
  } while (0)

/* vx,vy = vx*(length/vlen), vy*(length/vlen) */
real_t vec2_normalize(vec2_t v, real_t length);

/* rx,ry = x*cos(theta) - y*sin(theta), x*sin(theta) + y*cos(theta) */
void vec2_rotate(vec2_t r, const vec2_t v, real_t theta);

/**
 *---------------------------------------------
 *  Vector3
 *---------------------------------------------
 **/

#define vec3_zero(v) (vx(v) = vy(v) = vz(v) = r_zero)

/* vx*vx + vy*vy + vz*vz */
#define vec3_lensq(v) (vx(v) * vx(v) + vy(v) * vy(v) + vz(v) * vz(v))

/* sqrt(vx*vx + vy*vy + vz*vz) */
#define vec3_len(v) r_sqrt(vec3_lensq(v))

/* ax*bx + ay*by + az*bz */
#define vec3_dot(a, b) (vx(a) * vx(b) + vy(a) * vy(b) + vz(a) * vz(b))

/* rx,ry,rz = ay*bz - az*by, az*bx - ax*bz, ax*by - ay*bx */
#define vec3_cross(r, a, b)                                                    \
  do {                                                                         \
    vx(r) = vy(a) * vz(b) - vz(a) * vy(b);                                     \
    vy(r) = vz(a) * vx(b) - vx(a) * vz(b);                                     \
    vz(r) = vx(a) * vy(b) - vy(a) * vx(b);                                     \
  } while (0)

/* rx,ry,rz = -vx, -vy, -vz */
#define vec3_neg(r, v)                                                         \
  do {                                                                         \
    vx(r) = -vx(v);                                                            \
    vy(r) = -vy(v);                                                            \
    vz(r) = -vz(v);                                                            \
  } while (0)

/* rx,ry,rz = ax+bx, ay+by, az+bz */
#define vec3_add(r, a, b)                                                      \
  do {                                                                         \
    vx(r) = vx(a) + vx(b);                                                     \
    vy(r) = vy(a) + vy(b);                                                     \
    vz(r) = vz(a) + vz(b);                                                     \
  } while (0)

/* rx,ry,rz = ax-bx, ay-by, az-bz */
#define vec3_sub(r, a, b)                                                      \
  do {                                                                         \
    vx(r) = vx(a) - vx(b);                                                     \
    vy(r) = vy(a) - vy(b);                                                     \
    vz(r) = vz(a) - vz(b);                                                     \
  } while (0)

/* rx,ry,rz = ax*bx, ay*by, az*bz */
#define vec3_mul(r, a, b)                                                      \
  do {                                                                         \
    vx(r) = vx(a) * vx(b);                                                     \
    vy(r) = vy(a) * vy(b);                                                     \
    vz(r) = vz(a) * vz(b);                                                     \
  } while (0)

/* rx,ry,rz = ax/bx, ay/by, az/bz */
#define vec3_div(r, a, b)                                                      \
  do {                                                                         \
    vx(r) = vx(a) / vx(b);                                                     \
    vy(r) = vy(a) / vy(b);                                                     \
    vz(r) = vz(a) / vz(b);                                                     \
  } while (0)

/* rx,ry,rz = vx*s, vy*s, vz*s */
#define vec3_scale(r, v, s)                                                    \
  do {                                                                         \
    vx(r) = vx(v) * (s);                                                       \
    vy(r) = vy(v) * (s);                                                       \
    vz(r) = vz(v) * (s);                                                       \
  } while (0)

/* vx,vy,vz = vx*(length/vlen), vy*(length/vlen), vz*(length/vlen) */
real_t vec3_normalize(vec3_t v, real_t length);

/* ry,rz = vy*cos(theta) - vz*sin(theta), vy*sin(theta) + vz*cos(theta) */
void vec3_rotate_x(vec3_t r, const vec3_t v, real_t theta);

/* rx,rz = vz*sin(theta) + vx*cos(theta), vz*cos(theta) - vx*sin(theta) */
void vec3_rotate_y(vec3_t r, const vec3_t v, real_t theta);

/* rx,ry = vx*cos(theta) - vy*sin(theta), vx*sin(theta) + vy*cos(theta) */
void vec3_rotate_z(vec3_t r, const vec3_t v, real_t theta);

/**
 *---------------------------------------------
 *  Vector4
 *---------------------------------------------
 **/

#define vec4_zero(v) (vx(v) = vy(v) = vz(v) = vw(v) = r_zero)

/* vx*vx + vy*vy + vz*vz + vw*vw */
#define vec4_lensq(v)                                                          \
  (vx(v) * vx(v) + vy(v) * vy(v) + vz(v) * vz(v) + vw(v) * vw(v))

/* sqrt(vx*vx + vy*vy + vz*vz) */
#define vec4_len(v) r_sqrt(vec4_lensq(v))

/* ax*bx + ay*by + az*bz + aw*bw */
#define vec4_dot(a, b)                                                         \
  (vx(a) * vx(b) + vy(a) * vy(b) + vz(a) * vz(b) + vw(a) * vw(b))

/* rx,ry,rz,rw = -vx, -vy, -vz, -vw */
#define vec4_neg(r, v)                                                         \
  do {                                                                         \
    vx(r) = -vx(v);                                                            \
    vy(r) = -vy(v);                                                            \
    vz(r) = -vz(v);                                                            \
    vw(r) = -vw(v);                                                            \
  } while (0)

/* rx,ry,rz,rw = ax+bx, ay+by, az+bz, aw+bw */
#define vec4_add(r, a, b)                                                      \
  do {                                                                         \
    vx(r) = vx(a) + vx(b);                                                     \
    vy(r) = vy(a) + vy(b);                                                     \
    vz(r) = vz(a) + vz(b);                                                     \
    vw(r) = vw(a) + vw(b);                                                     \
  } while (0)

/* rx,ry,rz,rw = ax-bx, ay-by, az-bz, aw-bw */
#define vec4_sub(r, a, b)                                                      \
  do {                                                                         \
    vx(r) = vx(a) - vx(b);                                                     \
    vy(r) = vy(a) - vy(b);                                                     \
    vz(r) = vz(a) - vz(b);                                                     \
    vw(r) = vw(a) - vw(b);                                                     \
  } while (0)

/* rx,ry,rz,rw = ax*bx, ay*by, az*bz, aw*bw */
#define vec4_mul(r, a, b)                                                      \
  do {                                                                         \
    vx(r) = vx(a) * vx(b);                                                     \
    vy(r) = vy(a) * vy(b);                                                     \
    vz(r) = vz(a) * vz(b);                                                     \
    vw(r) = vw(a) * vw(b);                                                     \
  } while (0)

/* rx,ry,rz,rw = ax/bx, ay/by, az/bz, aw/bw */
#define vec4_div(r, a, b)                                                      \
  do {                                                                         \
    vx(r) = vx(a) / vx(b);                                                     \
    vy(r) = vy(a) / vy(b);                                                     \
    vz(r) = vz(a) / vz(b);                                                     \
    vw(r) = vw(a) / vw(b);                                                     \
  } while (0)

/* rx,ry,rz,rw = vx*s, vy*s, vz*s, vw*s */
#define vec4_scale(r, v, s)                                                    \
  do {                                                                         \
    vx(r) = vx(v) * (s);                                                       \
    vy(r) = vy(v) * (s);                                                       \
    vz(r) = vz(v) * (s);                                                       \
    vw(r) = vw(v) * (s);                                                       \
  } while (0)

/* vx,vy,vz,vw = vx*(length/vlen), vy*(length/vlen), vz*(length/vlen),
 * vw*(length/vlen) */
real_t vec4_normalize(vec4_t v, real_t length);

#ifdef __cplusplus
};
#endif

#endif /* __VECTOR_H__ */
