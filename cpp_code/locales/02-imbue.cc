#include <locale>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::locale;

int main ()
{
  cout << locale("").name() << endl;	
  cin.imbue(locale(""));
#ifdef _WIN32
  cout.imbue(locale("rus_RUS")); // fails on mingw, works in VS2015
#else
  cout.imbue(locale("ru_RU"));
#endif
  double value;
  if (cin >> value) 
    cout << value << endl;
}

