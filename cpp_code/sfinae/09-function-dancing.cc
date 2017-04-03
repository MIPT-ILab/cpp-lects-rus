#include <iostream>

using std::cout;
using std::endl;

template<typename T> 
void hook(T);

template<typename T> 
struct Dancing 
{
  void jab() { 
    hook(0);
  }
  void cross() { 
    cout << "hic salta" << endl; 
  }
};

template<typename T> 
void hook(T t) 
{
  Dancing<T> a; 
  a.cross();
}

int main() 
{
  Dancing<int> a; 
  a.jab();
}

