#include <cstdio>
#include <iostream>

using namespace std;

int 
main (void) {
  fputs ("Hello, world\n", stdout);
  fprintf (stdout, "%s\n", "Hello, world");
  cout.write("Hello, world\n", sizeof("Hello, world\n"));
  cout << "Hello, world" << endl;
  return 0;
}


