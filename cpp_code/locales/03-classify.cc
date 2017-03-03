#include <locale>
#include <iostream>
#include <iosfwd>

int main ()
{
  std::locale loc{};
  std::cout << std::boolalpha << "Can loc classify chars? "
            << std::has_facet<std::ctype<char>>(loc) << std::endl;

  std::locale uloc = std::locale("deu_DEU");
  auto sym = std::use_facet<std::moneypunct<char, true>>(uloc).curr_symbol();
  std::cout << "Currency: " << sym << std::endl;
}

