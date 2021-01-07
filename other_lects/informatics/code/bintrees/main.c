#include <stdio.h>

#include "bintree.h"

int main() {
  struct BTree_t *top;

  top = read_search_tree(stdin);
  print_tree(top);  
  free_tree(top);
}

