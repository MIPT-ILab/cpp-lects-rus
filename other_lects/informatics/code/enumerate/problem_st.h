#pragma once

#include "problem_lx.h"

enum node_kind_t { OP, VAL};

struct node_data_t { 
  enum node_kind_t k;
  union {
    enum operation_t op;
    int d; 
  } u;
};

struct node_t {
  struct node_t *left, *right;
  struct node_data_t data;
};

struct node_t *build_syntax_tree(struct lexarray_t lexarr);

int calc_result(struct node_t *top);
