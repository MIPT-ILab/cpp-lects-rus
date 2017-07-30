#include <cassert>
#include <cstring>

using std::strlen;
using std::strcmp;

int
main ()
{
  char astr[] = "hello"; 
  char bstr[15]; 
  int alen = strlen(astr); 
  assert(alen == 5); 
  strcpy(bstr, astr); 
  strcat(bstr, ", world!"); 
  int res = strcmp(astr, bstr); 
  assert(res < 0);
}

