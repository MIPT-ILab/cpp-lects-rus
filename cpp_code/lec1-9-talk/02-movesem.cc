#include <iostream>

using namespace std;

struct Costly {
  Costly () { cout << "ctor" << endl; }
  Costly (const Costly&) { cout << "copy" << endl; }
  Costly& operator= (const Costly&) { cout << "assign" << endl; return *this; }

  Costly (Costly&&) { cout << "move ctor" << endl; }
  Costly& operator= (const Costly&&) { cout << "move" << endl; return *this; }
};

class Buffer {  
  int sz; int *buf;
public:
  Buffer (int s = 10) : sz(s), buf(new int[sz]) {}
  ~Buffer () { delete [] buf; }
  void dump() { cout << buf << " " << sz << endl; }
};


template <typename T> void
old_swap (T& x, T& y)
{
  T tmp = x;
  x = y;
  y = tmp;
}

template <typename T> void
new_swap (T& x, T& y)
{
  T tmp = move (x);
  x = move (y);
  y = move (tmp);
}

void
buf_swap (Buffer& x, Buffer& y)
{
  cout << "swap" << endl;
  x.dump(); y.dump();
  Buffer tmp = move (x);
  x = move (y);
  y = move (tmp);
  cout << "after swap" << endl;
  x.dump(); y.dump(); tmp.dump();
  cout << endl;
}

void use_Costly (Costly &&c) 
{
  volatile Costly x = c;
}

int main (void)
{
  Costly c1, c2;
  use_Costly (Costly{});
  cout << endl;
  old_swap (c1, c2);
  new_swap (c1, c2);
  cout << endl;
  // Buffer a, b;
  // buf_swap (a, b); UB!
}

