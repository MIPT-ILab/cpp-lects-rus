#include <iostream>
#include <fstream>

std::ofstream 
openFile (const std::string& filename)
{
  std::ofstream file(filename);
  file << "hello, ";
  return file;
}

int 
main (void)
{
  std::ofstream file;
  file = openFile("xyz.tmp");
  file << "world" << std::endl;
}

