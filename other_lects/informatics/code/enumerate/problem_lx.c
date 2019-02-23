#include "problem_lx.h"

struct lex_array_t lex_string(const char *str) {
  assert(str != NULL);
  
  struct lex_array_t larr = {malloc(ICAP * sizeof()), 0, ICAP}; 
  assert(larr.lexems != NULL);
  
  // TODO:
  // for each char in str
  //   if char reminds space, skip it
  //   if char reminds number, lex number
  //   if char reminds brace, lex brace
  //   if char reminds operation, lex operation
  //   otherwise report error, free lex array, return NULL
    
  return larr;
}

void dump_lexarray(struct lex_array_t pl) {
  assert(pl.lexems != NULL);
}
