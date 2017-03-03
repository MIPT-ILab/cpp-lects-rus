#include <locale>
#include <cstdio>
#include <cwchar>

int main (void)
{
  std::setlocale (LC_ALL, "");
  std::wprintf (L"%.3f\n", 1.0);  
#ifndef MSC_VER_
  std::setlocale (LC_ALL, "rus_RUS");
#else
  std::setlocale (LC_ALL, "ru_RU");
#endif
  std::wprintf (L"%.3f\n", 1.0);  
}


