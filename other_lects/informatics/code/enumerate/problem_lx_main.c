#include "problem_lx.h"

int main() {
  int res;
  struct lex_array_t *plarr;
  char inp[181] = {0};
  res = scanf("%180s", inp);
  assert(res == 1);
  
  plarr = lex_string(inp);
  
  if (plarr != NULL) {
    dump_lexarray(plarr);
    free(plarr->lexems);
  }
}
