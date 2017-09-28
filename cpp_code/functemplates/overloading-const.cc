#include <iostream>

using std::cout;
using std::endl;

struct Conv {
  Conv (int) { cout << "int -> Conv" << endl; }
  operator int() { cout << "Conv -> int" << endl; }
};

// first conflict for const int: 10 or 11
// both -> amb
// if both are crossed out, look below

// void foo (int x) { cout << 10 << endl; }
// void foo (const int &x) { cout << 11 << endl; }

// second conflict for const int 
// forall x, y : (2x, 2y) -> amb
// if one left it wins
// if all are crossed out, see below

//void foo (char x) { cout << 20 << endl; }
// void foo (const char &x) { cout << 21 << endl; }
// void foo (double x) { cout << 22 << endl; }
// void foo (const double &x) { cout << 23 << endl; }

// third conflict for int
// (30, 31) -> amb
// if one left it wins
// if all are crossed out, see below

// void foo (Conv x) { cout << 30 << endl; }
// void foo (const Conv &x) { cout << 31 << endl; }

// fallback
// void foo (...) { cout << 40 << endl; }

// viable, but produces error
// void foo (int &x) { cout << 50 << endl; }

// these are not viable anyway
void foo (char &x) { cout << 51 << endl; }
void foo (double &x) { cout << 52 << endl; }

int
main ()
{
  foo(42);
}

