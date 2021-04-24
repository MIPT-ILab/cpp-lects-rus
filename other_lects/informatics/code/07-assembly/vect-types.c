#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xmmintrin.h>

float rsqrt(float t) {
  float ret;
  __asm__("rsqrtss %0, %1" : "=x"(ret) :"x"(t));
  return ret;
}

int main(){
  float f = rsqrt(2.0);
  printf("%f\n", f);
}

