#include <iostream>
#include <sstream>
#include <string>
#include <utility>

using std::cout;
using std::forward;
using std::endl;
using std::ostringstream;
using std::string;

void addToStream(ostringstream&) {}

template<typename T, typename... Args>
void 
addToStream(ostringstream& a_stream, T&& a_value, Args&&... a_args)
{
  a_stream << forward<T>(a_value);
  addToStream(a_stream, forward<Args>(a_args)...);
}

template<typename... Args>
string 
concat(Args&&... a_args)
{
    ostringstream s;
    addToStream(s, forward<Args>(a_args)...);
    return s.str();
}

int
main ()
{
  bool ssl = true;
  string path = "my.com";
  string query = "?v=1";
  string s = concat (ssl ? "http" : "https", "://", path, "/", query);
  cout << s << endl;
}

