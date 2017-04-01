#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

struct Person
{
  const char *name;
  int age;
  Person (const char *aname, int anage) : name (aname), age(anage) {}
};

static bool
operator > (const Person &lhs, const Person &rhs)
{
  return lhs.age > rhs.age;
}

static bool
operator < (const Person &lhs, const Person &rhs)
{
  return lhs.age < rhs.age;
}

static bool
operator <= (const Person &lhs, const Person &rhs)
{
  return !(lhs > rhs);
}

static bool
operator == (const Person &lhs, const Person &rhs)
{
  return (&lhs == &rhs);
}

template <class T> const T&
max (const T &x, const T &y)
{
  return ((x > y) ? x : y);
}

template <class T> const T&
min (const T &x, const T &y)
{
  return ((x < y) ? x : y);
}

template <typename T> bool
test_minmax (const T &a, const T &b)
{
  assert (a <= b);
  return (min (a, b) == a) && (max (a, b) == b);
}

int
main (void)
{
  Person Ivan ("Ivan", 24);
  Person Danila ("Danila", 24);
  std::printf ("%d\n", test_minmax (5, 6));
  std::printf ("%d\n", test_minmax (Ivan, Danila));
  return 0;
}

