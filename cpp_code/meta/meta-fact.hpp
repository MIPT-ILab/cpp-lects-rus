template <int n>
struct factorial 
{
  enum { value = n * factorial<n - 1>::value };
};
 
template <>
struct factorial<0> {
  enum { value = 1 };
};

template <int n, int idx, int product>
struct fact_rec
{
  enum { value = fact_rec <n, idx + 1, product * idx>::value };
};

template <int n, int product>
struct fact_rec <n, n, product>
{
  enum { value = product * n };
};

template <int n>
struct factorial2
{
  enum { value = fact_rec <n, 1, 1> :: value };
};

