#include <iostream>
#include <fstream>

using namespace std;

int
main (void)
{
  {
    ofstream o("p5.out");
    o << "Hello ";
  }

  {
    ofstream o("p5.out", ios_base::app);
    o << "World ";
  }

  return 0;
}

