#include <map>
#include <list>
#include <string>
#include <iostream>

#include <type_traits>
#include <typeinfo>
#include <memory>
#include <string>
#include <cstdlib>

#if 0
template <class T>
std::string
type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own
           (
                nullptr,
                std::free
           );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}
#endif

using namespace std;

/* error for c++11 */
#if 0
template <typename T> auto
makeAndProcessObject1 (const T& builder)
{
    auto val = builder.makeObject();
    /* do stuff with val */
    return val;
}
#endif


template <typename T> auto
makeAndProcessObject (const T& builder) -> decltype (builder.makeObject())
{
    auto val = builder.makeObject();
    /* do stuff with val */
    return val;
}

template<typename T, typename S>
auto min(T x, S y) -> decltype(x < y ? x : y) {
  return x < y ? x : y;
}

auto isquare (int x) { return x*x; }

auto sum_to (int i) 
{
  if (i < 2)
    return i; // return type deduced as int
  else
    return sum_to (i-1) + i;  // ok to call it now
}

#if 0
auto bad_sum_to (int i)
{
  if (i > 2)
    return bad_sum_to (i-1) + i;
  else
    return i;
}
#endif

struct Point { int x, y; };

int
main ()
{
  Point porig {1, 2};
  map <int,list<string>> m {{10, {"Hello", "World"}}, {20, {"Eric", "BloodAxe"}}};

  auto i = m.begin ();
  cout << i->first << ": " << i->second.front() << std::endl;
  decltype(i) j = i++;
  cout << j->first << ": " << j->second.back() << std::endl;

  const Point &p = porig;

  decltype(p.x) x1 /* int */;
  decltype((p.x)) x2 = porig.y; /* const int & */

  int x, y;
  typedef decltype(x) xval; 
  typedef decltype((x)) xref; 
  typedef decltype((x+1)) xval_again;
  typedef decltype((x+y)) xval_again_2;

  xval r0;
  /* xref r1; */
  xval_again r2;
  xval_again_2 r3;

  const int s = 5;

  auto s1 = 3;
  decltype (s) s2 = 3;
  s1 += 1;
  /* s2 += 1; */

  /* cout << type_name<decltype(s1)>() << "," << type_name<decltype(s2)>() << endl; */

  const int* const p1 = &x;
  auto p2 = p1;
  p2 = &x;
  /* *p2 = 3; */

  auto s3 = s; /* typeof(j) == int */
  decltype (auto) s4 = s; /* typeof (k) == const int */

  auto x4a = (x); /* decltype(x4a) is int */
  decltype(auto) x4d = (x); /* decltype(x4d) is int& */

  x4a = 5;
  x4d = 6;
  cout << x << endl;

  /* decltype (min (1, 2)) r4; */
  decltype (min (1, 2.0)) r5;

  cout << sum_to (10) << endl;

  return 0;
}

