//------------------------------------------------------------------------------
//
// driver.cpp -- main entry point
//
//------------------------------------------------------------------------------

#include <cstdio>

#include "yyret.h"

import node;
import parser;

IScope *currentScope = nullptr;

int main(int argc, char *argv[]) {
  FILE *f = fopen(argv[1], "r");
  if (!f) {
    perror("Cannot open file");
    return 1;
  }
  yyin = f;
  currentScope = create_scope();
  yyparse();
  fclose(f);
  delete currentScope;

  return 0;
}