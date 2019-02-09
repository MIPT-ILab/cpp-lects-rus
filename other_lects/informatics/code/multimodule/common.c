#include <assert.h>
#include <stdio.h>
#include "common.h"

void read_triangle(struct triangle_t *t) {
  int i;
  for (i = 0; i < 3; ++i) {
    int n;
    n = scanf("%lf%lf", &t->v[i].x, 
                        &t->v[i].y);
    assert(n == 2 && "Read error");
  }
}

double square(const struct triangle_t *t) {
  struct point_t p0 = t->v[0];
  struct point_t p1 = t->v[1];
  struct point_t p2 = t->v[2];
  double r = 
    (p1.x * p0.y - p0.x * p1.y
   - p2.x * p0.y + p0.x * p2.y
   + p2.x * p1.y - p1.x * p2.y);
  if (r < 0.0) r = -r;
  return r / 2.0;  
}

