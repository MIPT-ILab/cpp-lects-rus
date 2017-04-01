#ifdef FIRST

namespace lexer 
{ 
  enum lexelem 
  {
    TERMINAL = 0, 
    NONTERMINAL = 10, 
    STARTSYM = 25 
  }; 
} 

#else

namespace lexer 
{ 
  int const TERMINAL = 0; 
  int const NONTERMINAL = 10; 
  int const STARTSYM = 25; 
} 

#endif

#ifdef FIRST
int foo (enum lexer::lexelem x)
#else
int foo (const int x)
#endif
{
   switch (x) /* x either lexelem (1) or const int (2) */
   { 
     case lexer::STARTSYM: return 0; 
     case lexer::TERMINAL: return 1;
     case lexer::NONTERMINAL: return 2;
     case 30: return 3;
     default: return 4;
   } 
}

int
main (void)
{
#ifndef FIRST
  const int *z = &lexer::TERMINAL; 
#endif

  return 0;
}

