#include <stdio.h>

int step2();
int step4();
int step6();
int step8();

int step1() {
  int i, s = 0;
  for (i = 0; i < 10; ++i)
    s += step2();
  return s;
}

int step3() {
  int i, s = 0;
  for (i = 0; i < 10; ++i)
    s += step4();
  return s;
}

int step5() {
  int i, s = 0;
  for (i = 0; i < 10; ++i)
    s += step6();
  return s;
}

int step7() {
  int i, s = 0;
  for (i = 0; i < 10; ++i)
    s += step8();
  return s;
}

int step9() {
  return 1; 
}

