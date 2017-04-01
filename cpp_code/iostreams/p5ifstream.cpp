#include <iostream>
#include <fstream>

using namespace std;

int
main (void)
{
  ifstream f("a.txt");

  if (f.fail())
    {
      clog << "No file a.txt found" << endl;
    }

  return 0;
}

