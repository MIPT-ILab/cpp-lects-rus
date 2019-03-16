#include <stdio.h>

int fact(int);

const char *name = "Hello, world!\n";

int
main () {
  asm("mov DWORD PTR [esp], 5\n"
      "call %P0\n"
      "mov DWORD PTR [esp+4], eax\n"
      "lea eax, %1\n"
      "mov DWORD PTR [esp], eax\n"
      "call %P2\n"::"i"(fact),"m"(name[0]),"i"(printf):"eax");
}

