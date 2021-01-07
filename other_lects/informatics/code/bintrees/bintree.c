#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "bintree.h"

struct BTree_t *
create_node(int data, struct BTree_t *l, struct BTree_t *r) {
  struct BTree_t *ret = malloc(sizeof(struct BTree_t));
  assert(ret);
  
  ret->left = l;
  ret->right = r;
  ret->data = data;
  return ret;
}

static void lvl_print_tree(const struct BTree_t *top, int lvl) {
  int i;
  for(i = 0; i < lvl * 2; ++i)
    printf("%c", ' ');
  printf("%d\n", top->data);
  if (top->left)
    lvl_print_tree(top->left, lvl + 1);
  if (top->right)
    lvl_print_tree(top->right, lvl + 1);
}

// 11000
// 110010100
// 1011010 --> incorr
static struct BTree_t * reconstruct_zo_tree(int **curtop, int *end) {
  int *cur = *curtop;
  int *nxt;
  
  assert(cur < end);
  nxt = cur + 1;
  if (*cur == 1) {  
    struct BTree_t *t1, *t2;
    t1 = reconstruct_zo_tree(&nxt, end);
    t2 = reconstruct_zo_tree(&nxt, end);
    *curtop = nxt;
    return create_node(1, t1, t2);
  }
  *curtop = nxt;
  return NULL;
}

struct BTree_t * reconstruct_zack_tree(int *top, int *end) {
  
  return reconstruct_zo_tree(&top, end);
}

struct BTree_t * read_zero_one_tree(FILE *f) {
  int nnodes, res, i;
  int *nodes, *orig;
  struct BTree_t *ret;
  char c;

  assert(f);
  res = fscanf(f, "%d ", &nnodes);
  assert(res == 1);
  
  nnodes = nnodes * 2 + 1;

  nodes = calloc(nnodes, sizeof(int));
  orig = nodes;
  assert(nodes);
  
  for (i = 0; i < nnodes; ++i) {
    res = fscanf(f, "%c", &c);
    assert (res == 1);
    assert(c == '0' || c == '1');
    nodes[i] = c - '0';
  }
  
  ret = reconstruct_zo_tree(&nodes, nodes + nnodes);
    
  free(orig);
  return ret;
}

static void add_search_order(struct BTree_t *top, int data) {
  assert(top);
  if (data < top->data) {
    if (top->left != NULL)
      add_search_order(top->left, data);
    else
      top->left = create_node(data, NULL, NULL);
  }
  else {
    assert(data != top->data);
    if (top->right != NULL)
      add_search_order(top->right, data);
    else
      top->right = create_node(data, NULL, NULL);
  }
}

static struct BTree_t *reconstruct_search_tree(int *nodes, int nnodes) {
  int i;
  struct BTree_t *top;
  
  assert(nodes);
  assert(nnodes > 0);
  
  top = create_node(nodes[0], NULL, NULL);
  
  for (i = 1; i < nnodes; ++i)
    add_search_order(top, nodes[i]);
  
  return top;
}

struct BTree_t * read_search_tree(FILE *f) {
  int nnodes, res, i;
  int *nodes;
  struct BTree_t *ret;

  assert(f);
  res = fscanf(f, "%d ", &nnodes);
  assert(res == 1);

  nodes = calloc(nnodes, sizeof(int));
  assert(nodes);

  for (i = 0; i < nnodes; ++i) {
    int n;
    res = fscanf(f, "%d", &n);
    assert (res == 1);
    nodes[i] = n;
  }

  ret = reconstruct_search_tree(nodes, nnodes);
    
  free(nodes);
  return ret;
}

void print_tree(const struct BTree_t *top) {
  assert(top);
  lvl_print_tree(top, 0);
}

void free_tree(struct BTree_t *top) {
  assert(top);
  if (top->left)
    free_tree(top->left);
  if (top->right)
    free_tree(top->right);
  free(top);
}


