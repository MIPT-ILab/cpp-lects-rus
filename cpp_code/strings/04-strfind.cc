#include <cassert>
#include <string>

using std::string;
using szt = string::size_type; 

int
main ()
{
  string s = "Hello"; 
  szt notfound = s.find("bye"); 
  assert (notfound == string::npos); 
  szt ellp = s.find("ell"); 
  assert (ellp != string::npos); 
  szt hpos = s.find("H", ellp); 
  assert (hpos == std::string::npos);
}

