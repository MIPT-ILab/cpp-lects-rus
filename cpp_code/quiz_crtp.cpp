#include <cassert>  
 
template <typename T>
struct OperatorMixin
{
};

template <typename T> bool 
operator == (const OperatorMixin<T>& lhs, const OperatorMixin<T>& rhs)
{
    const T& d1 = static_cast<const T&> (lhs);
    const T& d2 = static_cast<const T&> (rhs);

    return !(d1 < d2) && !(d2 < d1);
}

template <typename T> bool 
operator != (const OperatorMixin<T>& o1, const OperatorMixin<T>& o2)
{
    return !(o1 == o2);
}
  
struct Pair : public OperatorMixin<Pair> 
{ 
  int m_x, m_y; 
  Pair (int x, int y = 0): m_x(x), m_y(y) {}  
};  

bool 
operator < (const Pair &lhs, const Pair &rhs) 
{ 
  return (lhs.m_x < rhs.m_x) || ((lhs.m_x == rhs.m_x) && (lhs.m_y < rhs.m_y)); 
}  

int 
main (void) 
{ 
  Pair a (2);  
  Pair b (2, 1);  
  int c = 2, d = 2; 
  /* 1 */ assert (b != a);  
  /* 2 */ assert (c == d);
  /* 3 */ assert (a == Pair(c));
  /* 4 */ assert (Pair(d) == b); 
  return 0; 
}

