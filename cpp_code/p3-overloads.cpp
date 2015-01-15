#include <cstdio>
#include <complex>

using namespace std;

    template<typename T1, typename T2>
    void f( T1 x, T2 y) {printf ("1\n");}                       // 1
    template<typename T> void f( T x) {printf ("2\n");}       // 2
    template<typename T> void f( T x, T y) {printf ("3\n");}    // 3
    template<typename T> void f( T* px) {printf ("4\n");}      // 4
    template<typename T> void f( T* px, T y) {printf ("5\n");}   // 5
    template<typename T> void f( T x, T* py) {printf ("6\n");}   // 6
    template<typename T> void f( int x, T* py) {printf ("7\n");} // 7
    template<> void f<int>( int x) {printf ("8\n");}          // 8
    void f( int x, double y) {printf ("9\n");}                  // 9
    void f( int x) {printf ("10\n");}                          // 10


int
main (void)
{
    int             i;
    double          d;
    float           ff;
    complex<double> c;

    f( i );         // a
    f<int>( i );    // b
    f( i, i );      // c
    f( c );         // d
    f( i, ff );     // e
    f( i, d );      // f
    f( c, &c );     // g
    f( i, &d );     // h
    f( &d, d );     // i
    f( &d );        // j
    f( d, &i );     // k
    f( &i, &i );    // l

    f( i );         // a
  return 0;
}

