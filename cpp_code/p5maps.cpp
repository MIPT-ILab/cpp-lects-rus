#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cassert>

const int MAXLEN = 128;

int main(int argc, char** argv)
{
  char buf[MAXLEN];
  std::map <std::string, int> words;
  int count = 0;
  FILE *f;

  assert (argc > 0);

  f = fopen (argv[1], "r");
  assert (f != 0);
   
  while (std::fscanf(f, "%s", buf) > 0)
    {
      std::string word = buf;
      words[word] += 1;
      count += 1;
    }
  
  for (std::map <std::string, int>::iterator cur = words.begin(); 
       cur != words.end(); 
       cur++)
    fprintf (stdout, "%s -- %.3f%%\n", cur->first.c_str(), ((double)cur->second / count) * 100.0);

  return 0;
}

