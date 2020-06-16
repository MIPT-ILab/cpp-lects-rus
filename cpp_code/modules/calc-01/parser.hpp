//------------------------------------------------------------------------------
//
// parser.hpp -- bison related extern defines and retval struct
//
//------------------------------------------------------------------------------

#pragma once

#include "INode.hpp"
#include <cstdarg>
#include <cstring>
#include <sstream>
#include <string>

struct yyRet {
  std::string name;
  int value;
  int linePos;
  int inLinePos;
  INode *treeNode;
  Ops op;
};

#define YYSTYPE yyRet

#include "compiler.cpp.h"

extern FILE *yyin;

int yylex();
int yyerror(char const *);
void PrintError(char const *s, ...);
void BeginToken(char *, int *);

// line number diagnostics
extern int yylineno;

// for string position diagnostics
static int yyinlinePos;
