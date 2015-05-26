#include <iostream>
#include <utility>

using namespace std;

struct T
{
  int& ref;

  T(int&& r) : ref(r) {}

  T const& plus(int x) const { ref += x; return *this; }
  T const& mult(int x) const { ref *= x; return *this; }

  int get() const { return ref; }
};

int main()
{
  std::cout << T(1).plus(2).mult(3).get() << std::endl; // временный объект живёт до конца полного выражения

  int x = 1;
  std::cout << T(std::move(x)).plus(2).mult(3).get() << std::endl; // попутно изменяем переменную
  std::cout << x << std::endl;
  std::cout << T(int(x)).plus(2).mult(3).get() << std::endl; // создаём копию переменной, дальше ковыряем временный объект
  std::cout << x << std::endl;

  return 0;
}

