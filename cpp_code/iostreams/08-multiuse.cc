#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;

const char *filenames[] = {"testfile1.txt", "testfile2.txt"};

int
main (void)
{
  ifstream file;
  for (int idx = 0; idx < sizeof(filenames) / sizeof(const char *); ++idx)
    {
      file.open(filenames[idx]);

      char c;
      while (file.get(c)) {
        cout.put(c);
      }

      file.close();
    }
}

