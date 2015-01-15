#include <cstdio>

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
operator >= (const Person &lhs, const Person &rhs)
{
  return lhs.age >= rhs.age;
}

static bool
operator < (const Person &lhs, const Person &rhs)
{
  return lhs.age < rhs.age;
}

static bool
operator <= (const Person &lhs, const Person &rhs)
{
  return lhs.age <= rhs.age;
}

template <class T> const T&
max (const T &x, const T &y)
{
  return ((x > y) ? x : y);
}

template <class T> const T&
min (const T &x, const T &y)
{
  return ((x <= y) ? x : y);
}

int
main (void)
{
  Person Ivan ("Ivan", 24);
  Person Danila ("Danila", 24);
  std::printf ("%d %d\n", min (5, 6), max (5, 6));
  std::printf ("%s %s\n", min (Ivan, Danila).name, max (Ivan, Danila).name);
  return 0;
}

