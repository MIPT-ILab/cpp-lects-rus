#include <stdlib.h>
#include <stdio.h>

int main() {
  int n;
  char *ix = malloc(10);
  for (int i = 0; i < 10; ++i)
    ix[i] = i;

  scanf("%d", &n); 
  printf("%d\n", ix[n]);

  return 0;
}

