#include <iostream>

using namespace std;

struct Costly {
  Costly () { cout << "ctor" << endl; }
  Costly (const Costly&) { cout << "copy ctor" << endl; }
  Costly& operator= (const Costly&) { cout << "assign" << endl; return *this; }

  Costly (Costly&&) { cout << "move ctor" << endl; }
  Costly& operator= (const Costly&&) { cout << "move" << endl; return *this; }
  ~Costly () { cout << "dtor" << endl; }
};

class SillyBuffer {  
  int sz; int *buf;
public:
  SillyBuffer (int s = 10) : sz(s), buf(new int[sz]) {}
  ~SillyBuffer () { delete [] buf; }
  void dump() { cout << buf << " " << sz << endl; }
};


template <typename T> void
old_swap (T& x, T& y)
{
  cout << "C++98 swap" << endl;
  T tmp = x;
  x = y;
  y = tmp;
}

template <typename T> void
new_swap (T& x, T& y)
{
  cout << "C++11 swap" << endl;
  T tmp = move (x);
  x = move (y);
  y = move (tmp);
}

void
buf_swap (SillyBuffer& x, SillyBuffer& y)
{
  cout << "swap" << endl;
  x.dump(); y.dump();
  SillyBuffer tmp = move (x);
  x = move (y);
  y = move (tmp);
  cout << "after swap" << endl;
  x.dump(); y.dump(); tmp.dump();
  cout << endl;
}

int main (void)
{
  Costly c1, c2;
  old_swap (c1, c2);
  new_swap (c1, c2);
  cout << endl;

#ifdef SILLYSWAP
  SillyBuffer a, b;
  buf_swap (a, b);   // UB
#endif
}

