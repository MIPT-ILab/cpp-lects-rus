#include "pyramid.h"

static void swap(int *p1, int *p2) {
  int a = *p1;
  *p1 = *p2;
  *p2 = a;
}

int is_max_heap(struct heap_t *p) {  
  for (int i = heap_size(p); i > 0; i--)
    if (heap_elt(p, heap_parent(i - 1)) < heap_elt(p, i - 1))
      return 0;
  return 1;
}

void max_heapify(struct heap_t *p, int i) {
  assert(p != NULL);
  assert(i >= 0);
  int largest = i;
  for (;;) {
    int old = largest;
    int l = heap_left(old);
    int r = heap_right(old);
    
    if ((l < heap_size(p)) && (heap_elt(p, old) < heap_elt(p, l)))
      largest = l;
    if ((r < heap_size(p)) && (heap_elt(p, largest) < heap_elt(p, r)))
      largest = r;
    
    if (largest == old)
      break;
    swap(heap_elt_ptr(p, old), heap_elt_ptr(p, largest));
    assert(l >= heap_size(p) || heap_elt(p, l) <= heap_elt(p, heap_parent(l)));
    assert(r >= heap_size(p) || heap_elt(p, r) <= heap_elt(p, heap_parent(r)));
  }
}

struct heap_t build_heap(int *arr, int len) {
  struct heap_t hp;
  hp.size = len;
  hp.length = len;
  hp.arr = arr;
  for (int i = len / 2; i >= 0; --i)
    max_heapify(&hp, i);
  return hp;
}