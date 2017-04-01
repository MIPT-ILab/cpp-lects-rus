template <unsigned int S> 
class Buffer 
{
  unsigned char bytes[S];
};

template <typename T, unsigned int S> 
class Array 
{
  T bytes[S];
};

template <typename T> 
class Array<T, 3> 
{
  T fst, snd, thrd;
public:
  T& operator[] (int n) {
    if (n == 0) return fst;
    if (n == 1) return snd;
    if (n == 2) return thrd;
  }
};

int
main (void)
{
  Buffer<10> b;
  Array<int, 10> a;
  Array<int, 3> a3;
  a3[0] = 5;
}


