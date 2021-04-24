#include "structs.h"

int foo1(int x) {
  return x;
}

int foo2(int x, int y) {
  return x + y;
}

int foo4(int x, int y, int z, int w) {
  return x + y + z + w;
}

int foo8(int x, int y, int z, int w,
         int x0, int y0, int z0, int w0) {
  return x + y + z + w + x0 + y0 + z0 + w0;
}

int fooc2(int x, char y) {
  return x + y;
}

int fooc4(int x, char y, int z, char w) {
  return x + y + z + w;
}

int fooc8(int x, char y, int z, char w,
         int x0, char y0, int z0, char w0) {
  return x + y + z + w + x0 + y0 + z0 + w0;
}

int foos2(int x, struct S2 y) {
  return x + y.x + y.y;
}

int foos2p(int x, struct S4 y) {
  return x + y.x + y.y + y.z + y.w;
}

int foos4(int x, struct S2 y, int z, struct S4 w) {
  return x + y.x + z + w.x;
}

int *use(int *);

int foos4p(int x, int y, int z, int v, int w, struct S4 s) {
  int *p = &s;
//  p = use(p);
  int b = *p + *(p + 1) + *(p + 2) + *(p + 3);
  return b;
}

int foos8(int x, struct S2 y, int z, struct S4 w,
         int x0, struct S8 y0) {
  return x + y.x + z + w.x + x0 + y0.x;
}

