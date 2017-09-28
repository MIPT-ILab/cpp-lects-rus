#include <iostream>

using std::cout;
using std::endl;

template <typename T> struct Stack { 
  Stack() { cout << 1 << endl; }
};

template <typename T> struct Stack<T*> { 
  Stack() { cout << 2 << endl; }
};

template <typename T> struct Stack<T**> { 
  Stack() { cout << 3 << endl; }
}; 

int
main ()
{
  Stack<Stack<int>*> s1;
  Stack<Stack<int>**> s2;
  Stack<Stack<int>***> s3;
}


