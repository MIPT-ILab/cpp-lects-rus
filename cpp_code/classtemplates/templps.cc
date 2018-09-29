#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename T> struct X {
  void print() { cout << "X<T>" << endl; } 
};

/*
template <typename T> struct X<vector<T>> {
  void print() { cout << "X<vector<T>>" << endl; } 
};
*/

template <template<class> typename C>
struct X<C<int>> {
  void print() { cout << "X<C<int>>" << endl; }   
};


template <typename T> struct Y {};

template <template<class> typename C, typename U>
struct Z {
  void print() { cout << "Z<C<?>, U>" << endl; }   
};

template <typename U>
struct Z<X, U> {
  void print() { cout << "Z<X<?>, U" << endl; }   
};

int
main () {
  X<int> a;
  X<vector<int>> b;
  X<X<int>> c;
  Z<Y, int> d;
  Z<X, int> e;

  a.print();
  b.print();
  c.print();
  d.print();
  e.print();
}

