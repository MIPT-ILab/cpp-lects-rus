#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

class MyBuf {
  int x_;
  char *buf_;
public:
  MyBuf(int x) : x_(x), buf_(new char[x_]) {}
  MyBuf(const MyBuf &rhs) : 
    x_(rhs.x_), buf_(new char[x_]) 
  {
    memcpy (buf_, rhs.buf_, x_);
  }
  ~MyBuf() { delete [] buf_; }
  char &operator[](int x) { return buf_[x]; }
};


MyBuf
retvec() 
{
  MyBuf v(10000);
  v[0] = 1;
  return v;
}

int
main()
{
  unsigned idx, cnt = 0;

  for (idx = 0; idx != 1000000; ++idx)
    {
      MyBuf v = retvec();
      cnt += v[0];
    }

  fprintf (stderr, "cnt is %d\n", cnt);
  return 0;
}

