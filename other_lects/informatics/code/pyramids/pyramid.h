#pragma once

#include <assert.h>
#include <string.h>

struct heap_t {
  int *arr;
  
  // size of pyramid in array
  int size;
  
  // length of array
  int length;
};

// get parent node
static inline int heap_parent(int i) { return (i - 1) / 2; }

// get left node
static inline int heap_left(int i) { return 2 * i + 1; }

// get right node
static inline int heap_right(int i) { return 2 * i + 2; }

// size of pyramid
static inline int heap_size(struct heap_t *p) { return p->size; }

// length of array under pyramid (capacity of pyramid)
static inline int heap_length(struct heap_t *p) { return p->length; }

// are heaps equal?
static inline int heap_equal(struct heap_t *lhs, struct heap_t *rhs) {
  if (heap_size(lhs) != heap_size(rhs))
    return 0;
  return (0 == memcmp(lhs->arr, rhs->arr, heap_size(lhs) * sizeof(int)));
}

// pointer to i-th element of pyramid
static inline int *heap_elt_ptr(struct heap_t *p, int i) {
  assert(i >= 0 && "index less then zero!");
  assert(i < heap_size(p) && "index overflows heap");
  return p->arr + i;
}

// i-th element of pyramid
static inline int heap_elt(struct heap_t *p, int i) {
  return *heap_elt_ptr(p, i);
}

// if heap is max-heap
int is_max_heap(struct heap_t *p);

// we are (almost) sure i is wrong
void max_heapify(struct heap_t *p, int i);

// build heap from array
struct heap_t build_heap(int *arr, int len);
