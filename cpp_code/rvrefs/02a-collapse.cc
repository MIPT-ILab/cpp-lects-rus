#include <iostream>

using namespace std;

template <typename T> struct TD;

int foo (int x) 
{
  int &y = x;
  auto &a = y;
  const auto &b = move(x);
  auto &&c = y;
  auto &&d = move(x);

  // TD<decltype(a)> t1;
  // TD<decltype(b)> t2;
  // TD<decltype(c)> t3;
  // TD<decltype(d)> t4;

  decltype(y) &&e = y;

  // TD<decltype(e)> t5;

  auto &&f = x;
  decltype(x) &&g = 1;
  decltype((x)) &&h = x;
  decltype(auto) i = move (x);

  // TD<decltype(f)> t6;
  // TD<decltype(h)> t7;
  // TD<decltype(i)> t8;
}

