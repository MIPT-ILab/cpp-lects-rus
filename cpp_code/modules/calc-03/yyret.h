import node;
import <string>;

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

// line number diagnostics
extern int yylineno;