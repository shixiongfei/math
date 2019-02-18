/*
 *  matrix.c
 *
 *  copyright (c) 2019 Xiongfei Shi
 *
 *  author: Xiongfei Shi <jenson.shixf(a)gmail.com>
 *  license: Apache-2.0
 *
 *  https://github.com/shixiongfei/math
 */

#include "matrix.h"

void mat33_transformation(mat33_t r, real_t x, real_t y, real_t theta,
                          real_t sx, real_t sy, real_t ox, real_t oy, real_t kx,
                          real_t ky) {
  real_t c = r_cos(theta);
  real_t s = r_sin(theta);

  /**
   * |1    x| |c -s  | |sx     | | 1 ky  | |1   -ox|
   * |  1  y| |s  c  | |   sy  | |kx  1  | |  1 -oy|
   * |     1| |     1| |      1| |      1| |     1 |
   *   move    rotate    scale     skew      origin
   **/

  mat33_zero(r);
  m3e11(r) = c * sx - ky * s * sy; /* = a */
  m3e21(r) = s * sx + ky * c * sy; /* = b */
  m3e12(r) = kx * c * sx - s * sy; /* = c */
  m3e22(r) = kx * s * sx + c * sy; /* = d */
  m3e13(r) = x - ox * m3e11(r) - oy * m3e12(r);
  m3e23(r) = y - ox * m3e21(r) - oy * m3e22(r);
  m3e33(r) = r_one;
}

void mat44_transformation(mat44_t r, real_t x, real_t y, real_t theta,
                          real_t sx, real_t sy, real_t ox, real_t oy, real_t kx,
                          real_t ky) {
  real_t c = r_cos(theta);
  real_t s = r_sin(theta);

  /**
   * |1     x| |c -s    | |sx       | | 1 ky    | |1     -ox|
   * |  1   y| |s  c    | |   sy    | |kx  1    | |  1   -oy|
   * |    1  | |     1  | |      1  | |      1  | |    1    |
   * |      1| |       1| |        1| |        1| |       1 |
   *   move      rotate      scale       skew       origin
   **/

  mat44_zero(r);
  m4e11(r) = c * sx - ky * s * sy; /* = a */
  m4e21(r) = s * sx + ky * c * sy; /* = b */
  m4e12(r) = kx * c * sx - s * sy; /* = c */
  m4e22(r) = kx * s * sx + c * sy; /* = d */
  m4e14(r) = x - ox * m4e11(r) - oy * m4e12(r);
  m4e24(r) = y - ox * m4e21(r) - oy * m4e22(r);
  m4e33(r) = m4e44(r) = r_one;
}

void mat44_rotatex(mat44_t r, real_t theta) {
  real_t c = r_cos(theta);
  real_t s = r_sin(theta);

  mat44_identity(r);
  m4e22(r) = c;
  m4e32(r) = s;
  m4e23(r) = -s;
  m4e33(r) = c;
}

void mat44_rotatey(mat44_t r, real_t theta) {
  real_t c = r_cos(theta);
  real_t s = r_sin(theta);

  mat44_identity(r);
  m4e11(r) = c;
  m4e31(r) = -s;
  m4e13(r) = s;
  m4e33(r) = c;
}

void mat44_rotatez(mat44_t r, real_t theta) {
  real_t c = r_cos(theta);
  real_t s = r_sin(theta);

  mat44_identity(r);
  m4e11(r) = c;
  m4e21(r) = s;
  m4e12(r) = -s;
  m4e22(r) = c;
}

void mat44_rotateaxis(mat44_t r, real_t theta, vec3_t axis) {
  real_t c = r_cos(theta);
  real_t s = r_sin(theta);
  real_t t = 1 - c;
  real_t xx = vx(axis) * vx(axis);
  real_t xy = vx(axis) * vy(axis);
  real_t xz = vx(axis) * vz(axis);
  real_t yy = vy(axis) * vy(axis);
  real_t yz = vy(axis) * vz(axis);
  real_t zz = vz(axis) * vz(axis);
  real_t xs = vx(axis) * s;
  real_t ys = vy(axis) * s;
  real_t zs = vz(axis) * s;

  mat44_identity(r);

  m4e11(r) = xx * t + c;
  m4e21(r) = xy * t - zs;
  m4e31(r) = xz * t + ys;

  m4e12(r) = xy * t + zs;
  m4e22(r) = yy * t + c;
  m4e32(r) = yz * t - xs;

  m4e13(r) = xz * t - ys;
  m4e23(r) = yz * t + xs;
  m4e33(r) = zz * t + c;
}

void mat44_ortho(mat44_t r, real_t left, real_t right, real_t bottom,
                 real_t top, real_t near, real_t far) {
  real_t rml = right - left;
  real_t tmb = top - bottom;
  real_t fmn = far - near;

  real_t rpl = right + left;
  real_t tpb = top + bottom;
  real_t fpn = far + near;

  mat44_identity(r);

  m4e11(r) = r_two / rml;
  m4e22(r) = r_two / tmb;
  m4e33(r) = -r_two / fmn;

  m4e14(r) = -(rpl / rml);
  m4e24(r) = -(tpb / tmb);
  m4e34(r) = -(fpn / fmn);
}

void mat44_perspective(mat44_t r, real_t fovy, real_t aspect, real_t near,
                       real_t far) {
  real_t f = r_tan(r_pi / r_two - fovy / r_two);

  mat44_zero(r);

  m4e11(r) = f / aspect;
  m4e22(r) = f;
  m4e33(r) = (far + near) / (near - far);
  m4e34(r) = (r_two * far * near) / (near - far);
  m4e43(r) = -r_one;
}
