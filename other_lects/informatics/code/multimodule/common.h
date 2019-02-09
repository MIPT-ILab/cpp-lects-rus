#pragma once

struct point_t {
  double x;
  double y;
};

struct triangle_t {
  struct point_t v[3];
};

void read_triangle(struct triangle_t *t);

double square(const struct triangle_t *t);

