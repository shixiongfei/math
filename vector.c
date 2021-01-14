/*
 *  vector.c
 *
 *  copyright (c) 2019-2021 Xiongfei Shi
 *
 *  author: Xiongfei Shi <xiongfei.shi(a)icloud.com>
 *  license: Apache-2.0
 *
 *  https://github.com/shixiongfei/math
 */

#include "vector.h"

real_t vec2_normalize(vec2_t v, real_t length) {
  real_t ls = vec2_len(v);
  if (!r_equal(ls, r_zero)) {
    length = length / ls;
    vec2_scale(v, v, length);
  }
  return ls;
}

void vec2_rotate(vec2_t r, const vec2_t v, real_t theta) {
  real_t cos_theta = r_cos(theta);
  real_t sin_theta = r_sin(theta);

  vx(r) = vx(v) * cos_theta - vy(v) * sin_theta;
  vy(r) = vx(v) * sin_theta + vy(v) * cos_theta;
}

real_t vec3_normalize(vec3_t v, real_t length) {
  real_t ls = vec3_len(v);
  if (!r_equal(ls, r_zero)) {
    length = length / ls;
    vec3_scale(v, v, length);
  }
  return ls;
}

void vec3_rotate_x(vec3_t r, const vec3_t v, real_t theta) {
  real_t cos_theta = r_cos(theta);
  real_t sin_theta = r_sin(theta);

  vx(r) = vx(v);
  vy(r) = vy(v) * cos_theta - vz(v) * sin_theta;
  vz(r) = vy(v) * sin_theta + vz(v) * cos_theta;
}

void vec3_rotate_y(vec3_t r, const vec3_t v, real_t theta) {
  real_t cos_theta = r_cos(theta);
  real_t sin_theta = r_sin(theta);

  vx(r) = vz(v) * sin_theta + vx(v) * cos_theta;
  vy(r) = vy(v);
  vz(r) = vz(v) * cos_theta - vx(v) * sin_theta;
}

void vec3_rotate_z(vec3_t r, const vec3_t v, real_t theta) {
  real_t cos_theta = r_cos(theta);
  real_t sin_theta = r_sin(theta);

  vx(r) = vx(v) * cos_theta - vy(v) * sin_theta;
  ;
  vy(r) = vx(v) * sin_theta + vy(v) * cos_theta;
  ;
  vz(r) = vz(v);
}

real_t vec4_normalize(vec4_t v, real_t length) {
  real_t ls = vec4_len(v);
  if (!r_equal(ls, r_zero)) {
    length = length / ls;
    vec4_scale(v, v, length);
  }
  return ls;
}
