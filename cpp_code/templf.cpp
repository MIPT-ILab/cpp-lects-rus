#include <stdio.h>

template <typename T> T 
max (T x, T y) 
{ 
  return (x > y) ? x : y; 
} 

int two (void) { return 2; } 
int one (void) { return 1; } 

int main () { printf ("%d\n", max(one, two)()); } 

