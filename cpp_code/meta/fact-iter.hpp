namespace Iter {

template <unsigned n, unsigned idx, unsigned product>
struct Fact_rec
{
  enum { value = Fact_rec <n, idx + 1, product * idx>::value };
};

template <unsigned n, unsigned product>
struct Fact_rec <n, n, product>
{
  enum { value = product * n };
};

template <unsigned n>
struct Factorial
{
  enum { value = Fact_rec <n, 1, 1> :: value };
};

}
