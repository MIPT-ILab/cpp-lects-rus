// my pair structure
#define Pair(T1, T2) \
  struct Pair ## T1 ## T2 { \
    T1 fst; \
    T2 snd; \
  };

#define Instance(C, T1, T2) C ## T1 ## T2

Pair(int, double);

Instance(Pair, int, double) p = {1, 1.0};
