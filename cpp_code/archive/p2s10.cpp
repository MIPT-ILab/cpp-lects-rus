/* copy and assign */

class Empty {};

#if 0

/* There is nothing empty in C++ */
class Empty {
public:
  Empty() { /* default implementation */ }
  Empty(const Empty &rhs) { /* default implementation */ }
  ~Empty() { /* default implementation */ }
  Empty& operator=(const Empty &rhs) { /* default implementation */ }
};

#endif

Empty test(void)
{
  Empty e1;
  Empty e2(e1); /* copy constructor called */
  e1 = e2; /* assignment called */
  return e1;
}

#include <cassert>
#include <cstring>
using namespace std;

class CBuffer {
public:
  CBuffer(int size = 10) { m_size = size; m_buffer = new char[size]; }
  ~CBuffer() { delete[] m_buffer; }
  char &get(int x) { assert(x >= 0 && x < m_size); return m_buffer[x]; } 
private:
  char *m_buffer;
  int m_size;
};

void wrong(void)
{
  CBuffer b1;
  CBuffer b2 = b1;
} /* Segfault here */

class CCopyableBuffer {
public:
  CCopyableBuffer(int size) { m_size = size; m_buffer = new char[size]; }
  ~CCopyableBuffer() { delete[] m_buffer; }
  CCopyableBuffer(const CCopyableBuffer& rhs) { 
    m_size = rhs.m_size; m_buffer = new char[m_size];
    memcpy(m_buffer, rhs.m_buffer, m_size);
  } 
  CCopyableBuffer& operator= (const CCopyableBuffer& rhs)
  {
    if (&rhs == this) return *this;
    delete [] m_buffer;
    m_size = rhs.m_size; m_buffer = new char[m_size];
    memcpy(m_buffer, rhs.m_buffer, m_size);
  }
  char &get(int x) { assert(x >= 0 && x < m_size); return m_buffer[x]; } 
private:
  char *m_buffer;
  int m_size;
};

class CNoncopyableBuffer {
public:
  CNoncopyableBuffer(int size) { m_size = size; m_buffer = new char[size]; }
  ~CNoncopyableBuffer() { delete[] m_buffer; }
  char &get(int x) { assert(x >= 0 && x < m_size); return m_buffer[x]; } 
private:
  char *m_buffer;
  int m_size;
  CNoncopyableBuffer(const CNoncopyableBuffer& rhs);
  CNoncopyableBuffer& operator= (const CNoncopyableBuffer& rhs);
};

