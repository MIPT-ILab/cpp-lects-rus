#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int 
foo (const char *pc)
{
  string s = pc;
}

void
bar ()
{
  const char s[] = "Hello";
  cout << s << endl;
  cout << static_cast<const void*>(&s[0]) << endl;
}

int
main ()
{
  // foo (nullptr); // BOOM!
  bar();
}

