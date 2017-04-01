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


