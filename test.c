/*
 *  test.c
 *
 *  copyright (c) 2019-2021 Xiongfei Shi
 *
 *  author: Xiongfei Shi <jenson.shixf(a)gmail.com>
 *  license: Apache-2.0
 *
 *  https://github.com/shixiongfei/math
 */

#include "matrix.h"
#include "quaternion.h"
#include "vector.h"
#include <stdio.h>

static void print_vec2(const vec2_t v) {
  printf("vec2(%lf %lf)\n", vx(v), vy(v));
}

static void print_vec3(const vec3_t v) {
  printf("vec3(%lf %lf %lf)\n", vx(v), vy(v), vz(v));
}

static void print_vec4(const vec4_t v) {
  printf("vec4(%lf %lf %lf %lf)\n", vx(v), vy(v), vz(v), vw(v));
}

static void print_mat22(const mat22_t m) {
  printf("mat22(\n %lf %lf,\n %lf %lf)\n", e0(m), e2(m), e1(m), e3(m));
}

static void print_mat33(const mat33_t m) {
  printf("mat33(\n %lf %lf %lf,\n %lf %lf %lf,\n %lf %lf %lf)\n", e0(m), e3(m),
         e6(m), e1(m), e4(m), e7(m), e2(m), e5(m), e8(m));
}

static void print_mat44(const mat44_t m) {
  printf("mat44(\n %lf %lf %lf %lf,\n %lf %lf %lf %lf,\n %lf %lf %lf %lf,\n "
         "%lf %lf %lf %lf)\n",
         e0(m), e4(m), e8(m), e12(m), e1(m), e5(m), e9(m), e13(m), e2(m), e6(m),
         e10(m), e14(m), e3(m), e7(m), e11(m), e15(m));
}

static void print_quat(const quat_t q) {
  printf("quat(%lf %lf %lf %lf)\n", qw(q), qx(q), qy(q), qz(q));
}

int main(int argc, char *argv[]) {
  vec2_t a = {0.0};
  vec2_t b = {3.0};
  vec2_t c = {5.0, 7.0};
  vec2_t r2;

  vec3_t e = {0.0};
  vec3_t f = {3.0};
  vec3_t g = {5.0, 7.0, 0.0};
  vec3_t h = {8.0, 6.0, 4.0};
  vec3_t r3;

  mat33_t m = {0};
  mat33_t n = {11.0, 0.0, 0.0, 0.0, 22.0, 0.0, 0.0, 0.0, 33.0};
  mat33_t k = {1.0, 0.0, 5.0, 2.0, 1.0, 6.0, 3.0, 4.0, 0.0};
  mat33_t r33;

  quat_t q = {0.0};
  quat_t p = {1.0, 0.5, 0.5, 0.75};
  quat_t r = {1.0, 0.0, 1.0, 0.0};
  quat_t rq;

  print_vec2(a);
  printf(" len: %lf\n", vec2_len(a));
  printf(" lensq: %lf\n", vec2_lensq(a));

  print_vec2(b);
  printf(" len: %lf\n", vec2_len(b));
  printf(" lensq: %lf\n", vec2_lensq(b));

  print_vec2(c);
  printf(" len: %lf\n", vec2_len(c));
  printf(" lensq: %lf\n", vec2_lensq(c));

  print_vec3(e);
  printf(" len: %lf\n", vec3_len(e));
  printf(" lensq: %lf\n", vec3_lensq(e));

  print_vec3(f);
  printf(" len: %lf\n", vec3_len(f));
  printf(" lensq: %lf\n", vec3_lensq(f));

  print_vec3(g);
  printf(" len: %lf\n", vec3_len(g));
  printf(" lensq: %lf\n", vec3_lensq(g));

  print_vec3(h);
  printf(" len: %lf\n", vec3_len(h));
  printf(" lensq: %lf\n", vec3_lensq(h));

  vec2_neg(r2, b);
  printf("-b = ");
  print_vec2(r2);

  vec2_add(r2, b, c);
  printf("b + c = ");
  print_vec2(r2);

  vec2_sub(r2, b, c);
  printf("b - c = ");
  print_vec2(r2);

  vec2_mul(r2, b, c);
  printf("b * c = ");
  print_vec2(r2);

  vec2_div(r2, b, c);
  printf("b / c = ");
  print_vec2(r2);

  printf("b dot c = %lf\n", vec2_dot(b, c));
  printf("b cross c = %lf\n", vec2_cross(b, c));

  vec2_scale(r2, c, 2.0);
  printf("c scale 2 = ");
  print_vec2(r2);

  printf("c norm = %lf\n", vec2_normalize(c, 1.0));
  print_vec2(c);
  printf(" len: %lf\n", vec2_len(c));
  printf(" lensq: %lf\n", vec2_lensq(c));

  vec2_rotate(r2, c, radians(90.0));
  printf("c dot (c rotate (rad 90)) = %lf\n", vec2_dot(c, r2));

  vec3_neg(r3, g);
  printf("-g = ");
  print_vec3(r3);

  vec3_add(r3, g, h);
  printf("g + h = ");
  print_vec3(r3);

  vec3_sub(r3, g, h);
  printf("g - h = ");
  print_vec3(r3);

  vec3_mul(r3, g, h);
  printf("g * h = ");
  print_vec3(r3);

  vec3_div(r3, g, h);
  printf("g / h = ");
  print_vec3(r3);

  printf("g dot h = %lf\n", vec3_dot(g, h));

  vec3_cross(r3, g, h);
  printf("d cross h = ");
  print_vec3(r3);

  vec3_scale(r3, g, 2.0);
  printf("g scale 2 = ");
  print_vec3(r3);

  printf("h norm = %lf\n", vec3_normalize(h, 1.0));

  print_vec3(h);
  printf(" len: %lf\n", vec3_len(h));
  printf(" lensq: %lf\n", vec3_lensq(h));

  vec3_rotate_x(r3, h, radians(90.0));
  printf("h dot (h rotatx (rad 90)) = %lf\n", vec3_dot(h, r3));

  vec3_rotate_y(r3, h, radians(90.0));
  printf("h dot (h rotaty (rad 90)) = %lf\n", vec3_dot(h, r3));

  vec3_rotate_z(r3, h, radians(90.0));
  printf("h dot (h rotatz (rad 90)) = %lf\n", vec3_dot(h, r3));

  print_mat33(m);
  print_mat33(n);
  print_mat33(k);

  mat33_add(r33, n, k);
  printf("n + k = ");
  print_mat33(r33);

  mat33_sub(r33, n, k);
  printf("n - k = ");
  print_mat33(r33);

  mat33_mul(r33, n, k);
  printf("n * k = ");
  print_mat33(r33);

  mat33_inverse(r33, k);
  printf("inverse k = ");
  print_mat33(r33);

  mat33_transpose(r33, k);
  printf("transpose k = ");
  print_mat33(r33);

  printf("det k = %lf\n", mat33_determinant(k));

  mat33_transformation(m, 1.0, 2.0, radians(90.0), 3.0, 4.0, 5.0, 6.0, 7.0,
                       8.0);
  printf("transformation: m");
  print_mat33(r33);

  vx(r2) = 3.0;
  vy(r2) = 7.0;
  mat33_transform2(r33, m, r2);
  printf("m transform2 3.0, 7.0 = ");
  print_mat33(r33);

  mat33_transform2(r33, m, c);
  printf("m trnasform2 c = ");
  print_mat33(r33);

  vx(r3) = 1.0;
  vy(r3) = 5.0;
  vz(r3) = 7.0;
  mat33_transform3(r33, m, r3);
  printf("m transform3 1.0, 5.0, 7.0 = ");
  print_mat33(r33);

  mat33_transform3(r33, m, h);
  printf("m transform3 h = ");
  print_mat33(r33);

  mat33_identity(n);
  printf("identity n = ");
  print_mat33(n);

  print_quat(q);
  print_quat(p);
  printf(" len: %lf\n", quat_len(p));
  printf(" lensq: %lf\n", quat_lensq(p));
  print_quat(r);

  quat_add(rq, p, r);
  printf("p + r = ");
  print_quat(rq);

  quat_sub(rq, p, r);
  printf("p - r = ");
  print_quat(rq);

  quat_mul(rq, p, r);
  printf("p * r = ");
  print_quat(rq);

  vx(r3) = 1.0;
  vy(r3) = 1.0;
  vz(r3) = 1.0;
  quat_rotate(rq, r, r3);
  printf("r rotate 1.0, 1.0, 1.0 = ");
  print_quat(rq);

  quat_neg(rq, p);
  printf("neg p = ");
  print_quat(rq);

  quat_conjugate(rq, p);
  printf("p conjugate = ");
  print_quat(rq);

  quat_tomatrix(r33, r);
  printf("r to matrix = ");
  print_mat33(r33);

  quat_toeuler(r3, r);
  printf("r to euler = ");
  print_vec3(r3);

  return 0;
}
