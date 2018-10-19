#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned 
linear_search(const int *parr, unsigned len, int elem) {
  assert(parr);
  unsigned i;
  for (i = 0; i < len; ++i)
    if (parr[i] == elem)
      return i;
  return len;
}

void swap(unsigned *v1, unsigned *v2) {
  unsigned tmp = *v1;
  *v1 = *v2;
  *v2 = tmp;
}

void selsort(int *arr, unsigned len) {
  // TODO: code here
}

int
main() {
  int idx;
  int unsorted[5] = {67, 1, 89, 45, 23};
  int sorted[5] = {1, 23, 45, 67, 89};

  // sort unsorted
  selsort(unsorted, 5);
  
  // after sort check sorted == unsorted
  for (idx = 0; idx < 5; ++idx)
    assert(sorted[idx] == unsorted[idx]);

  return 0;
}
