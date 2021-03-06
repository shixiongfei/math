/*
 *  matrix.c
 *
 *  copyright (c) 2019-2021 Xiongfei Shi
 *
 *  author: Xiongfei Shi <xiongfei.shi(a)icloud.com>
 *  license: Apache-2.0
 *
 *  https://github.com/shixiongfei/math
 */

#include "matrix.h"

void mat22_rotation(mat22_t r, real_t theta) {
  real_t c = r_cos(theta);
  real_t s = r_sin(theta);

  /**
   * | c -s |
   * | s  c |
   **/

  e0(r) = c;
  e1(r) = s;
  e2(r) = -s;
  e3(r) = c;
}

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

  e0(r) = c * sx - ky * s * sy; /* = a */
  e1(r) = s * sx + ky * c * sy; /* = b */
  e3(r) = kx * c * sx - s * sy; /* = c */
  e4(r) = kx * s * sx + c * sy; /* = d */
  e6(r) = x - ox * e0(r) - oy * e3(r);
  e7(r) = y - ox * e1(r) - oy * e4(r);
  e2(r) = e5(r) = r_zero;
  e8(r) = r_one;
}

void mat33_rotatex(mat33_t r, real_t theta) {
  real_t c = r_cos(theta);
  real_t s = r_sin(theta);

  /**
   * | 1  0  0 |
   * | 0  c -s |
   * | 0  s  c |
   **/

  mat33_identity(r);
  e4(r) = c;
  e5(r) = s;
  e7(r) = -s;
  e8(r) = c;
}

void mat33_rotatey(mat33_t r, real_t theta) {
  real_t c = r_cos(theta);
  real_t s = r_sin(theta);

  /**
   * |  c  0  s |
   * |  0  1  0 |
   * | -s  0  c |
   **/

  mat33_identity(r);
  e0(r) = c;
  e2(r) = -s;
  e6(r) = s;
  e8(r) = c;
}

void mat33_rotatez(mat33_t r, real_t theta) {
  real_t c = r_cos(theta);
  real_t s = r_sin(theta);

  /**
   * | c -s  0 |
   * | s  c  0 |
   * | 0  0  1 |
   **/

  mat33_identity(r);
  e0(r) = c;
  e1(r) = s;
  e3(r) = -s;
  e4(r) = c;
}

void mat33_rotateaxis(mat33_t r, real_t theta, vec3_t axis) {
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

  e0(r) = xx * t + c;
  e3(r) = xy * t - zs;
  e6(r) = xz * t + ys;

  e1(r) = xy * t + zs;
  e4(r) = yy * t + c;
  e7(r) = yz * t - xs;

  e2(r) = xz * t - ys;
  e5(r) = yz * t + xs;
  e8(r) = zz * t + c;
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
  e0(r) = c * sx - ky * s * sy; /* = a */
  e1(r) = s * sx + ky * c * sy; /* = b */
  e4(r) = kx * c * sx - s * sy; /* = c */
  e5(r) = kx * s * sx + c * sy; /* = d */
  e12(r) = x - ox * e0(r) - oy * e4(r);
  e13(r) = y - ox * e1(r) - oy * e5(r);
  e10(r) = e15(r) = r_one;
}

void mat44_rotatex(mat44_t r, real_t theta) {
  real_t c = r_cos(theta);
  real_t s = r_sin(theta);

  /**
   * | 1  0  0  0 |
   * | 0  c -s  0 |
   * | 0  s  c  0 |
   * | 0  0  0  1 |
   **/

  mat44_identity(r);
  e5(r) = c;
  e6(r) = s;
  e9(r) = -s;
  e10(r) = c;
}

void mat44_rotatey(mat44_t r, real_t theta) {
  real_t c = r_cos(theta);
  real_t s = r_sin(theta);

  /**
   * |  c  0  s  0 |
   * |  0  1  0  0 |
   * | -s  0  c  0 |
   * |  0  0  0  1 |
   **/

  mat44_identity(r);
  e0(r) = c;
  e2(r) = -s;
  e8(r) = s;
  e10(r) = c;
}

void mat44_rotatez(mat44_t r, real_t theta) {
  real_t c = r_cos(theta);
  real_t s = r_sin(theta);

  /**
   * | c -s  0  0 |
   * | s  c  0  0 |
   * | 0  0  1  0 |
   * | 0  0  0  1 |
   **/

  mat44_identity(r);
  e0(r) = c;
  e1(r) = s;
  e4(r) = -s;
  e5(r) = c;
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

  e0(r) = xx * t + c;
  e4(r) = xy * t - zs;
  e8(r) = xz * t + ys;

  e1(r) = xy * t + zs;
  e5(r) = yy * t + c;
  e9(r) = yz * t - xs;

  e2(r) = xz * t - ys;
  e6(r) = yz * t + xs;
  e10(r) = zz * t + c;
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

  e0(r) = r_two / rml;
  e5(r) = r_two / tmb;
  e10(r) = -r_two / fmn;

  e12(r) = -rpl / rml;
  e13(r) = -tpb / tmb;
  e14(r) = -fpn / fmn;
}

void mat44_frustum(mat44_t r, real_t left, real_t right, real_t bottom,
                   real_t top, real_t near, real_t far) {
  real_t rl = right - left;
  real_t tb = top - bottom;
  real_t fn = far - near;

  mat44_zero(r);

  e0(r) = (near * r_two) / rl;
  e5(r) = (near * r_two) / tb;
  e8(r) = (right + left) / rl;
  e9(r) = (top + bottom) / tb;
  e10(r) = -(far + near) / fn;
  e11(r) = -r_one;
  e14(r) = -(far * near * r_two) / fn;
}

void mat44_perspective(mat44_t r, real_t fovy, real_t aspect, real_t near,
                       real_t far) {
  real_t top = near * r_tan(fovy * r_pi / r_360);
  real_t right = top * aspect;

  mat44_frustum(r, -right, right, -top, top, near, far);
}

void mat44_lookat(mat44_t r, vec3_t eye, vec3_t target, vec3_t up) {
  vec3_t focal, x, y, z;

  vec3_sub(focal, target, eye);
  vec3_normalize(focal, r_one);

  vec3_cross(x, focal, up);
  vec3_normalize(x, r_one);

  vec3_cross(y, x, focal);
  vec3_neg(z, focal);

  mat44_identity(r);

  e0(r) = vx(x);
  e4(r) = vy(x);
  e8(r) = vz(x);
  e12(r) = -vec3_dot(x, eye);

  e1(r) = vx(y);
  e5(r) = vy(y);
  e9(r) = vz(y);
  e13(r) = -vec3_dot(y, eye);

  e2(r) = vx(z);
  e6(r) = vy(z);
  e10(r) = vz(z);
  e14(r) = -vec3_dot(z, eye);
}
