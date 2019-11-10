// use: a.exe < inp1.fsm

#include <stdio.h>

#define start(state)                                                           \
  switch (state) {                                                             \
  case 0:;

#define finish                                                                 \
  default:;                                                                    \
    }

#define yield(state, value)                                                    \
  do {                                                                         \
    state = __LINE__;                                                          \
    return (value);                                                            \
  case __LINE__:;                                                              \
  } while (0)

struct coroutine {
  int state;
};

// FSM:
// A -- 'a' --> B
// A -- 'b' --> C
// B -- 'a' --> C
// B -- 'b' --> A
// C -- 'a' --> A
// C -- 'b' --> B

int run(char input) {
  static int state = 0;
  start(state) {
  A:
    printf("Entered state A\n");
    yield(state, 1);
    if (input == 'a')
      goto B;
    if (input == 'b')
      goto C;
  B:
    printf("Entered state B\n");
    yield(state, 1);
    if (input == 'a')
      goto C;
    if (input == 'b')
      goto A;
  C:
    printf("Entered state C\n");
    yield(state, 1);
    if (input == 'a')
      goto A;
    if (input == 'b')
      goto B;
  }
  finish;

  return 0;
}

int main() {
  int a;
  while ((a = getchar()) != EOF && run(a))
    ;
  return 0;
}
