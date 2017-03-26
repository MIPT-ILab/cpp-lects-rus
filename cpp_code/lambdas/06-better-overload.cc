// overloaded lambdas demo

#include <iostream>
#include <utility>

using namespace std;

template<class F, class... Fs>
struct overload : F, overload<Fs...>
{
    using F::operator();
    using overload<Fs...>::operator();

    overload(F&& f, Fs&&... fs)
      : F(std::move(f))
      , overload<Fs...>(std::move(fs)...)
    {}
};

template<class F>
struct overload<F> : F
{
    using F::operator();

    overload(F&& f)
      : F(std::move(f))
    {}
};

auto const make_overload = [](auto... fs)
{
    return overload<decltype(fs)...>{std::move(fs)...};
};

int
main (void)
{
  auto f = make_overload (
     [](int i) { cout << "forint" << endl; },
     [](double d) { cout << "fordouble" << endl; });

  auto g = make_overload (
     [](int i) { cout << "forintg" << endl; },
     [](double d) { cout << "fordoubleg" << endl; });

  f(3);
  f(3.0);
  g(3);
  g(3.0);

  return 0;
}

