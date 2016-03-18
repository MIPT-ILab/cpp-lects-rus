#include <cassert>  

template <typename T, typename U> bool 
operator == (const T &x, const U &y) 
{
  return !(x < y) && !(y < x);  
} 

template <typename T, typename U> bool 
operator != (const T &x, const U &y) 
{ 
  return !(x == y);  
} 

template <typename T, typename U>  
struct Pair  
{ 
  T m_x; 
  U m_y; 
  Pair (T x, U y = 0): m_x(x), m_y(y) {}

#if 0
  template <typename T1, typename T2>
  bool operator < (const Pair<T1, T2> &rhs) 
  { 
    return (m_x < rhs.m_x) || ((m_x == rhs.m_x) && (m_y < rhs.m_y)); 
  } 
#endif
};  

#if 0
template bool Pair<int, int>::operator<(const Pair<int, int>&);
#endif

#if 0
template <typename T1, typename T2> bool
operator < (const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs)
{
  return (lhs.m_x < rhs.m_x) || ((lhs.m_x == rhs.m_x) && (lhs.m_y < rhs.m_y));
}
#endif

bool 
operator < (const Pair<int, int> &lhs, const Pair<int, int> &rhs)
{
  return (lhs.m_x < rhs.m_x) || ((lhs.m_x == rhs.m_x) && (lhs.m_y < rhs.m_y));
}

int 
main (void) 
{ 
  Pair<int, int> a (2);  
  Pair<int, int> b (2, 1);  
  int c = 2, d = 2; 
  /* 1 */ assert (b != a);  
  /* 2 */ assert (c == d); 
  /* 3 */ assert (a == c); 
  /* 4 */ assert (d == b); 
  return 0; 
} 

