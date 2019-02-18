/*
 *  quaternion.c
 *
 *  copyright (c) 2019 Xiongfei Shi
 *
 *  author: Xiongfei Shi <jenson.shixf(a)gmail.com>
 *  license: Apache-2.0
 *
 *  https://github.com/shixiongfei/math
 */

#include "quaternion.h"

real_t quat_normalize(quat_t q, real_t length) {
  real_t ls = quat_len(q);
  if (!r_equal(ls, r_zero)) {
    length = length / ls;

    qw(q) = qw(q) * length;
    qx(q) = qx(q) * length;
    qy(q) = qy(q) * length;
    qz(q) = qz(q) * length;
  }
  return ls;
}

void quat_slerp(quat_t r, const quat_t from, const quat_t to, real_t t) {
  real_t scale_from, scale_to;
  real_t c, s, dot = quat_dot(from, to);

  if ((r_one - dot) > r_epsilon) {
    c = r_acos(dot);
    s = r_sin(c);
    scale_from = r_sin((r_one - t) * c) / s;
    scale_to = r_sin(t * c) / s;
  } else {
    scale_from = r_one - t;
    scale_to = t;
  }

  qw(r) = qw(from) * scale_from + qw(to) * scale_to;
  qx(r) = qx(from) * scale_from + qx(to) * scale_to;
  qy(r) = qy(from) * scale_from + qy(to) * scale_to;
  qz(r) = qz(from) * scale_from + qz(to) * scale_to;
}

void quat_rotate(vec3_t r, const quat_t q, const vec3_t v) {
  quat_t t, c;

  quat_conjugate(c, q);

  qw(t) = -qx(c) * vx(v) - qy(c) * vy(v) - qz(c) * vz(v);
  qx(t) = vx(v) * qw(c) + vy(v) * qz(c) - qy(c) * vz(v);
  qy(t) = vy(v) * qw(c) + qx(c) * vz(v) - vx(v) * qz(c);
  qz(t) = vz(v) * qw(c) + vx(v) * qy(c) - qx(c) * vy(v);

  vx(r) = qx(t) * qw(q) + qx(q) * qw(t) + qy(q) * qz(t) - qy(t) * qz(q);
  vy(r) = qy(t) * qw(q) + qy(q) * qw(t) + qx(t) * qz(q) - qx(q) * qz(t);
  vz(r) = qz(t) * qw(q) + qz(q) * qw(t) + qx(q) * qy(t) - qx(t) * qy(q);
}

void quat_tomatrix(mat33_t m, const quat_t q) {
  real_t xx = qx(q) * qx(q);
  real_t yy = qy(q) * qy(q);
  real_t zz = qz(q) * qz(q);
  real_t xy = qx(q) * qy(q);
  real_t xz = qx(q) * qz(q);
  real_t yz = qy(q) * qz(q);
  real_t wx = qw(q) * qx(q);
  real_t wy = qw(q) * qy(q);
  real_t wz = qw(q) * qz(q);

  m3e11(m) = r_one - r_two * (yy + zz);
  m3e12(m) = r_two * (xy - wz);
  m3e13(m) = r_two * (xz + wy);

  m3e21(m) = r_two * (xy + wz);
  m3e22(m) = r_one - r_two * (xx + zz);
  m3e23(m) = r_two * (yz - wx);

  m3e31(m) = r_two * (xz - wy);
  m3e32(m) = r_two * (yz + wx);
  m3e33(m) = r_one - r_two * (xx + yy);
}

void quat_toeuler(vec3_t r, const quat_t q) {
  real_t xx = qx(q) * qx(q);
  real_t yy = qy(q) * qy(q);
  real_t zz = qz(q) * qz(q);
  real_t xz = qx(q) * qz(q);
  real_t xy = qx(q) * qy(q);
  real_t yz = qy(q) * qz(q);
  real_t wx = qw(q) * qx(q);
  real_t wy = qw(q) * qy(q);
  real_t wz = qw(q) * qz(q);
  real_t ty = r_two * (xz + wy);

  vx(r) = r_atan2(r_two * (wx - yz), r_one - r_two * (xx + yy));
  vy(r) = r_asin((ty < r_negone) ? r_negone : (ty > r_one) ? r_one : ty);
  vz(r) = r_atan2(r_two * (wz - xy), r_one - r_two * (yy + zz));
}

void quat_fromeuler(quat_t r, const vec3_t v) {
  real_t hx = vx(v) * r_half;
  real_t hy = vy(v) * r_half;
  real_t hz = vz(v) * r_half;

  real_t sx = r_sin(hx);
  real_t sy = r_sin(hy);
  real_t sz = r_sin(hz);

  real_t cx = r_cos(hx);
  real_t cy = r_cos(hy);
  real_t cz = r_cos(hz);

  qw(r) = cx * cy * cz - sx * sy * sz;
  qx(r) = sx * cy * cz + cx * sy * sz;
  qy(r) = cx * sy * cz - sx * cy * sz;
  qz(r) = cx * cy * sz + sx * sy * cz;
}

void quat_fromangleaxis(quat_t r, const vec3_t v, real_t theta) {
  real_t ht, s, ls = vec2_len(v);

  if (r_equal(ls, r_zero)) {
    qw(r) = r_one;
    qx(r) = qy(r) = qz(r) = r_zero;
  } else {
    ls = r_one / ls;
    ht = theta * r_half;
    s = r_sin(ht);

    qw(r) = r_cos(ht);
    qx(r) = s * vx(v) * ls;
    qy(r) = s * vy(v) * ls;
    qz(r) = s * vz(v) * ls;
  }
}
