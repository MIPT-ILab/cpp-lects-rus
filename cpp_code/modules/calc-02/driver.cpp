//------------------------------------------------------------------------------
//
// driver.cpp -- main entry point
//
//------------------------------------------------------------------------------

#include "parser.hpp"

IScope *currentScope = nullptr;

static int currentinlinePos = 0;

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

// note: those 2 functions are logically from parser.hpp

void PrintError(char const *errorstring, ...) {
  static char errmsg[10000];
  va_list args;

  bool isNotNullPar = false;
  for (int i = 0; i < strlen(errorstring) - 1; ++i) {
    if (errorstring[i + 1] == '%' && errorstring[i] != '\\') {
      isNotNullPar = true;
      break;
    }
  }

  va_start(args, errorstring);
  vsprintf(errmsg, errorstring, args);
  va_end(args);
  if (!isNotNullPar)
    fprintf(stdout, "Error: %s - Line %d:c%d\n", errmsg, yylineno,
            currentinlinePos);
  else
    fprintf(stdout, "Error: %s\n", errmsg);

  exit(1);
}

void BeginToken(char *t, int *yyinlinePos) {
  yylloc.first_line = yylineno;
  yylloc.first_column = *yyinlinePos;
  yylloc.last_line = yylineno;
  *yyinlinePos += strlen(t);
  yylloc.last_column = *yyinlinePos;

  currentinlinePos = *yyinlinePos;
}
