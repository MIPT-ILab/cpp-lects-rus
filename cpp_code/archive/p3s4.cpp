#include <cstdio>

using namespace std;

template <typename Type>
class Outer
{
public:
  template <typename InType>
  class Inner
  {
  public:
    template <typename X> void nested(void)
      {
        printf("victory\n");
      }
  };
}; 

template <typename T1, typename T2>
class Usage
{
public:
  void caller(typename Outer<T1>::template Inner<T2> &obj) 
    { 
      obj.template nested<int>();
    }
};


int main(void)
{
  Usage<int, int> u;
  Outer<int>::Inner<int> obj;
  u.caller(obj);
  return 0;
}


