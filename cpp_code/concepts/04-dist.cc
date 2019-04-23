#include "junkiter.hpp"

int
main () {
  int arr[10];
  junk_iter_t fst(arr), snd(arr + 3);
  auto dist = std::distance(fst, snd);
}
