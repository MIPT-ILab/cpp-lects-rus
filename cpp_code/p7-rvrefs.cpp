#include <iostream>

class Foo
{
    int m_x;
  public:
    Foo () : m_x( 3 ) {}
    void func ()
      {
        int x = 0;

        /* error: by-copy x is readonly */
        // [x] { x += 3; } ();
        
        /* by-copy x, ok */ 
        [x] () mutable { x += 3; } ();

        /* error: non-variable by-copy */
        // [m_x] () mutable { m_x += 3; } (); 

        /* amend: local copy of m_x */
        [captured_mx = m_x] () mutable { captured_mx += 3; } (); 

        /* by-ref x, ok */
        [&x] () { x += 3; } ();

        /* ok, x and this captured by ref */
        [&] () { x += m_x; } ();

        /* error: capture of non-variable m_x */
        // [&m_x] () mutable { std::cout << m_x; } (); 

        /* amend: m_x field by reference */
        [&captured_mx = m_x] () mutable { captured_mx += 3; } (); 

        /* amend error case: m_x field address by reference */
        // [&captured_mx = &m_x] () mutable { *captured_mx += 3; } ();

        /* amend: byval ok */
        [captured_mx = &m_x] () mutable { *captured_mx += 3; } ();

        /* error: by-ref x, but this not captured */
        // [&x] () mutable { x += m_x; } (); 

        /* ok: by-ref x, this->mx used */
        [=, &x] { x += m_x; } ();

        /* ok: this->m_x used */
        [=] () { std::cout << m_x; } ();
      }
};

