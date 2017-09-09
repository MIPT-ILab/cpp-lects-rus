#include <iostream>
#include <string>

#include <boost/tokenizer.hpp>

using boost::tokenizer;
using boost::char_separator;
using std::cout;
using std::endl;
using std::string;

int
main()
{
  string str = ";;Hello|world||-foo--bar;yow;baz|";
  char_separator<char> sep("-;|");
  tokenizer<char_separator<char> > tokens(str, sep);
  for (auto tok : tokens)
    cout << "<" << tok << "> ";
  cout << endl;
}
