#include <utility>
#include <functional>
#include <iostream>

using namespace std;

void
simple_dangle ()
{
  int *myArray;
  myArray = new int[2]{ 100, 200 };
  int& ref = myArray[0];
  delete[] myArray;
  cout << "100 = " << ref << endl;  // dangling reference  
}

struct Base
{
  ~Base() { cout << "Base destructed" << endl; }
};
 
struct Derived : public Base
{
  ~Derived () {cout << "Derived destructed" << endl; }
};

ostream& operator << (ostream& p, const Base &b) { p << "Base printed"; return p; }
ostream& operator << (ostream& p, const Derived &d) { p << "Derived printed"; return p; }

Derived __attribute__ ((noinline))
derivedret ()
{
  return Derived();
}

#if 0
int& __attribute__ ((noinline))
refret (int x)
{
  return x;
}
#endif

int __attribute__ ((noinline))
xret (int x)
{
  return x;
}

void
tricky_1 ()
{
  // Base &wrong = derivedret (); // compilation error: invalid initialization of non-const reference of type ‘int&’ from an rvalue of type ‘int’
  const Base &corr = derivedret ();

  cout << "(1) " << corr << endl;
}

void
tricky_2 ()
{
  const int &ref0 = 0;
  int &&t = xret (2); /* all ok */
  int &&p = std::move (xret (3)); /* dangling reference! */
  int &x = t; /* bad idea */
  x += 1;
  int ival = x;
  int &&rval = std::move (ival);
  const int &&v = xret (4);
  int &&ref1 = 2;
  const int &&ref2 = 3;
  /* const int *dptr = &(xret (7)); lvalue required */
  /* int &ref3 = refret (6); reference to local is returned */
  /* int &ref4 = std::ref(xret(6)); use of deleted function */
  int &ref5 = ref1;
  ref5 += 1;
  cout << "(2) " << t << " " << p << " " << x << endl;
  cout << "(3) " << v << " " << ref1 << " " << ref2 <<  endl;
} 

void
tricky_2a ()
{
  int a = 3, b = 5;
  int &&t = a * b;
  const int &p = a * b;
  t = t + 1;
  int &x = t; 
  x += 1;
  cout << x << endl;
} 

int &&
rr_ret (int x)
{
  return std::move(x);
}

int &
lr_ret (int x)
{
  return std::ref(x);
}

std::reference_wrapper<int>
lr_ret_1 (int x)
{
  return std::ref (x);
}

int trycall (const int & x)
{
  return x;
}

void
tricky_3 ()
{
  int *val = new int[2]{ 100, 200 };
  int correct = *(val + 1);
  // int **wrong = &(val + 1); // compilation error: lvalue required as unary ‘&’ operand
  int &&t = rr_ret(3);
  int &x = lr_ret(3);
  std::reference_wrapper <int> rw = lr_ret_1(3);
  rw += 1;
  //x = 5; /* bad idea */
  /* rr_ret(x) = 5; using xvalue as lvalue  */
  int ival = correct;
  int &&rval = std::move(ival);

  struct S { int mi; const pair<int,int>& mp; };
  S a { 1, {2,3} };
  S* p = new S{ 1, {2,3} };

  cout << "(4) " << correct << " " << t << " " << x << " " << rw << endl;
  cout << "(5) " << a.mp.first << " " << p->mp.first << endl;

  delete p;
  delete [] val;
}


int
main (void)
{
  int t = 2;
  int &a = t;
  trycall (a);

  /* simple_dangle (); -- valgrind invalid read */
  tricky_1 (); // all ok, lifetime extended
  tricky_2 ();
  tricky_2a ();
  tricky_3 ();
  return 0;
}

