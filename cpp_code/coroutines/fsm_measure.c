// cl -O2 fsm_measure.c
// cl fsm_measure.c -DDEBUG

#include <assert.h>
#include <stdio.h>
#include <time.h>

#ifdef DEBUG
#define log(x) printf(x)
#else
#define log(x)
#endif

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

// FSM:
// A -- 'a' --> B
// A -- 'b' --> C
// B -- 'a' --> C
// B -- 'b' --> A
// C -- 'a' --> A
// C -- 'b' --> B

// basic test inp1.fsm: aaabba
// start: A
// output: ABCACBC

int run(char input) {
  static int state = 0;
  if (input == 0)
    state = 0;
  start(state) {
  A:
    log("A\n");
    yield(state, 1);
    if (input == 'a')
      goto B;
    if (input == 'b')
      goto C;
  B:
    log("B\n");
    yield(state, 2);
    if (input == 'a')
      goto C;
    if (input == 'b')
      goto A;
  C:
    log("C\n");
    yield(state, 3);
    if (input == 'a')
      goto A;
    if (input == 'b')
      goto B;
  }
  finish;

  return 0;
}

int main() {
  int a, s = 0, res;
  int n, m, i;
  clock_t start, fin;
  
  res = scanf("%d%d", &n, &m);
  assert(res);
  
  start = clock();
  
  for (int i = 0; i < m; ++i) {  
    run(0); // switch to first state
    for (int j = 0; j < n; ++j) {
      a = (rand() % 2) ? 'a' : 'b';
      s = run(a);
      assert(s != 0);
    }
  }

  fin = clock();

  printf("Elapsed: %lg seconds\n", (double)(fin - start) / CLOCKS_PER_SEC);
  return 0;
}
