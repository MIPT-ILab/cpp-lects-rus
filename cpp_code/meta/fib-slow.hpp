namespace Slower
{

template <unsigned TreePos, unsigned N>
struct FibSlower
{
    enum
    {
      value = FibSlower<TreePos, N - 1>::value + FibSlower<TreePos + (1 << N), N - 2>::value
    };
};

template <unsigned TreePos>
struct FibSlower<TreePos, 1>
{
    enum
    {
      value = 1
    };
};

template <unsigned TreePos>
struct FibSlower<TreePos, 0>
{
    enum
    {
      value = 0
    };
};

template <unsigned N>
using Fibonacci = FibSlower<0, N>;

}
