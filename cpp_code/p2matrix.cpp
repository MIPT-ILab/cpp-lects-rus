#include <cstdio>
#include <cstring>

class Matrix
{
public:
  Matrix (int n, int m) : m_n (n), m_m (m), m_buf (new int[n*m]()) {}
  ~Matrix () { delete [] m_buf; }

  Matrix (const Matrix &rhs) : m_n (rhs.m_n), m_m (rhs.m_m), m_buf (new int[m_n * m_m])
    {
      std::memcpy (m_buf, rhs.m_buf, rhs.m_n * rhs.m_m * sizeof (int));
    }

  void set (int x, int y, int val) { m_buf[x*m_m + y] = val; }
  int get (int x, int y) { return m_buf[x*m_m + y]; }

private:
  int m_n, m_m;
  int *m_buf;
};

int
main (void)
{
  Matrix m (2, 3);

  m.set (1, 2, 10);

  Matrix n = m;
  

  std::printf ("%d\n", n.get (1, 2));  

  return 0;
}

