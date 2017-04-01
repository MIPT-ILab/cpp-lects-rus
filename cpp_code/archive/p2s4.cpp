#include <cstdlib>
#include <cstdio>

using namespace std;

void usef(FILE *f);
int somemore(int x);
int another(FILE *f, int i);
int remainder(FILE *f, int x);

int foo_1 (const char * fname, int x)
{
  FILE *f = fopen(fname, "r");
  if (x < 5)
    {
       usef(f);
       fclose(f);
       return somemore(x);
     }
  else if (x > 7)
    {
       int i;
       for (i = 0; i < x; ++i)
         {
           if (another(f, i) != x)
             {
                fclose(f);
                return -1;
             }
           x += i;
         }
      fclose(f);
      return x;
    }
  
  remainder(f, x);
  fclose(f);
  return 0;
}

int foo_2 (const char * fname, int x)
{
  FILE *f = fopen(fname, "r");
  int retval = 0;
  if (x < 5)
    {
       usef(f);
       retval = somemore(x);
       goto cleanup;
     }
  else if (x > 7)
    {
       int i;
       for (i = 0; i < x; ++i)
         {
           if (another(f, i) != x)
             {
                retval = -1;
                goto cleanup;
             }
           x += i;
         }
      retval = x;
    }
  remainder(f, x);

cleanup:
  fclose(f);
  return retval;
}

static int foo_3_1 (FILE *f, int x)
{
  if (x < 5)
    {
       usef(f);
       return somemore(x);
     }
  else if (x > 7)
    {
       int i;
       for (i = 0; i < x; ++i)
         {
           if (another(f, i) != x)
             return -1;
           x += i;
         }
      return x;
    }
  
  remainder(f, x);
  return 0;
}

int foo_3 (const char * fname, int x)
{
  FILE *f = fopen(fname, "r");
  int retval = foo_3_1(f, x);
  fclose(f);
  return retval;
}

class CFile
{
public:
  CFile(const char * fname, const char *acc) { m_file = fopen(fname, acc); }
  ~CFile() { fclose(m_file); m_file = 0; }
  FILE *fl(void) const { return m_file; }
private:
  FILE *m_file;
};

int foo (const char * fname, int x)
{
  CFile f(fname, "r");
  if (x < 5)
    {
       usef(f.fl());
       return somemore(x);
     }
  else if (x > 7)
    {
       int i;
       for (i = 0; i < x; ++i)
         {
           if (another(f.fl(), i) != x)
             return -1;
           x += i;
         }
      return x;
    }
  
  remainder(f.fl(), x);
  return 0;
}

