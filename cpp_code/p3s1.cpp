#include <cstdio>

using namespace std;

/* 1. max of two ints */ 
inline int const& max (int const& a, int const& b) 
{ 
  printf("%d\n", 1);
  return a < b ? b : a; 
} 

/* 2. maximum of two values of any type */ 
template <typename T> 
inline T const& max (T const& a, T const& b) 
{ 
  printf("%d\n", 2);
  return a < b ? b : a; 
} 

/* 3. maximum of three values of any type */ 
template <typename T> 
inline T const& max (T const& a, T const& b, T const& c) 
{ 
  printf("%d\n", 3);
  return max (max(a,b), c); 
} 

int main(void) 
{ 
  max(7, 42, 68);     /* calls [3]<int>, [1], [1]   */ 
  max(7.0, 42.0);     /* calls [2]<double> */ 
  max('a', 'b');      /* calls [2]<char>   */ 
  max(7, 42);         /* calls [1]         */ 
  max<int>(7, 42);       /* calls [2]<int>    */ 
  max<>(7, 42);       /* calls [2]<int>    */ 
  max<double>(7, 42); /* calls [2]<double> */ 
  max('a', 42.7);     /* calls [1]         */ 
  return 0;
} 

