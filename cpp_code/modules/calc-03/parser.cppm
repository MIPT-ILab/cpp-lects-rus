//------------------------------------------------------------------------------
//
// parser.cppm -- bison related extern defines and retval struct
//
//------------------------------------------------------------------------------

module;

#include <cstdarg>
#include <cstring>

// inevitable hack
#include "yyret.h"

export module parser;

import <sstream>;
import <string>;

int currentinlinePos = 0;

export void PrintError(char const *errorstring, ...) {
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

export void BeginToken(char *t, int *yyinlinePos) {
  yylloc.first_line = yylineno;
  yylloc.first_column = *yyinlinePos;
  yylloc.last_line = yylineno;
  *yyinlinePos += strlen(t);
  yylloc.last_column = *yyinlinePos;

  currentinlinePos = *yyinlinePos;
}
