#include <iostream>
#include <fstream>

int
main (void)
{
  std::ofstream outfile("sample.tmp");
  outfile << "This is an apple";
  // auto pos = outfile.tellp();
  // outfile.seekp (pos - static_cast<decltype(pos)>(7));
  outfile.seekp (-7, std::ios::cur);
  outfile << " sam";
}

