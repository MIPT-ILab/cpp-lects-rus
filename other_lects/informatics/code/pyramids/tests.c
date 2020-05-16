#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pyramid.h"

void test_basic() {
  int h[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
  int nonh[] = {1, 14, 10, 8, 7, 9, 3, 2, 4, 16};
  struct heap_t hp = { h, 10, 10 };
  struct heap_t nhp = { nonh, 10, 10 };
  
  assert(h[heap_parent(0)] == 16);
  assert(h[heap_left(0)] == 14);
  assert(h[heap_right(0)] == 10);
  assert(h[heap_parent(3)] == 14);
  assert(h[heap_left(3)] == 2);
  assert(h[heap_right(3)] == 4);

  assert(is_max_heap(&hp) && "We know this is max-heap");
  assert(!is_max_heap(&nhp) && "We know this is not max-heap");
  
  assert(heap_equal(&hp, &hp) && "Equal fails");
  assert(!heap_equal(&hp, &nhp) && "Non equal fails");
}

void test_heapify() {
  int h[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
  int nonh[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
  int to_be_heap[] = {23, 17, 14, 6, 13, 10, 1, 5, 7, 12};
  
  int h_1[] = {33, 94, 26, 85, 70, 29, 5, 2, 69, 99};

  struct heap_t hp = { h, 10, 10 };
  struct heap_t nhp = { nonh, 10, 10 };
  struct heap_t oldhp = { to_be_heap, 10, 10 };
  struct heap_t newhp;

  max_heapify(&nhp, 1);
  assert(heap_equal(&hp, &nhp) && "Heapify failed");
  
  assert(!is_max_heap(&oldhp));
  newhp = build_heap(to_be_heap, 10);
  assert(is_max_heap(&newhp));
  
  newhp = build_heap(h_1, 10);
  assert(is_max_heap(&newhp));
}

enum { NRANDS = 10, ARRSZ = 10, RANDMAX = 100 };

static void arr_print(int *arr, int sz) {
  for (int i = 0; i < sz; ++i)
    printf("%d ", arr[i]);
}

void test_rand_heapify() {
  int *arr = calloc(ARRSZ, sizeof(int));
  int *shadow = calloc(ARRSZ, sizeof(int));
  srand(time(NULL));
  for (int i = 0; i < NRANDS; ++i) {    
    struct heap_t hp;
    for (int j = 0; j < ARRSZ; ++j) {
      int elt = rand() % RANDMAX;
      arr[j] = elt;
      shadow[j] = elt;
    }
    hp = build_heap(arr, ARRSZ);
    if (!is_max_heap(&hp)) {
      printf("Failed array: [");
      arr_print(shadow, ARRSZ);
      printf("]\n");
      printf("Incorrect result: [");
      arr_print(arr, ARRSZ);
      printf("]\n");
      assert(0 && "Not max heap");
    }
  }
  free(arr);
  free(shadow);
}

int main() {
  test_basic();
  test_heapify();
  test_rand_heapify();
  printf("%s\n", "Tests passed");
}