%option c++

%{

using std::cout;
using std::endl;

%}

WS      [ \t\n\v]+
DIGIT   [0-9]
DIGIT1  [1-9]

%%

{WS}              /* skip blanks and tabs */
"+"               { cout << "operator <" << yytext[0] << ">" << endl; return 1; }
"-"               { cout << "operator <" << yytext[0] << ">" << endl; return 1; }
"="               { cout << "operator <" << yytext[0] << ">" << endl; return 1; }
{DIGIT1}{DIGIT}*  { cout << "  number <" << yytext    << ">" << endl; return 1; }
.                 { cout << " UNKNOWN <" << yytext[0] << ">" << endl; return 1; }

%%

// nothing