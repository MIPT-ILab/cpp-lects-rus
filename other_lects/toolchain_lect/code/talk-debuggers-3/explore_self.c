#include <stdio.h>

__attribute__((noinline)) void *foo() {
  return __builtin_return_address(0);
}

int main() {
  void *curip = foo();
  int i = 0, checksum = 0;
  unsigned char prevbyte = 0;
  printf("Address: 0x%lx\n", (long)curip);
  
  for (;;) {
    unsigned nextbyte = *((unsigned char *)curip + i);
    checksum += nextbyte;

    printf("\t0x%hhx", nextbyte);
    if (((i + 1) % 8) == 0)
      printf("\n");
    
    if ((prevbyte == 0xc9) && (nextbyte == 0xc3))
      break;

    i += 1;
    prevbyte = nextbyte;
  }

  printf("\nDone: %d\n", checksum);
}

