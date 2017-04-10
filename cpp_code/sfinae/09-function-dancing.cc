#include <iostream>

using std::cout;
using std::endl;

template<typename T> 
void proceed(T);

template<typename T> 
struct Dancing 
{
  void tearup() { 
    proceed(0);
  }
  void finalize() { 
    cout << "hic salta" << endl; 
  }
};

template<typename T> 
void proceed(T t) 
{
  Dancing<T> a; 
  a.finalize();
}

int main() 
{
  Dancing<int> a; 
  a.tearup();
}

