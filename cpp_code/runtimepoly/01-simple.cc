#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using object_t = int;
using document_t = std::vector<object_t>;

void draw(const object_t &x, std::ostream &out, size_t position) {
  out << std::string(position, ' ') << x << std::endl;
}

void draw(const document_t &x, std::ostream &out, size_t position) {
  out << std::string(position, ' ') << "<document>" << std::endl;
  for (const auto &e : x)
    draw(e, out, position + 2);
  out << std::string(position, ' ') << "</document>" << std::endl;
}

int main() {
  document_t document;
  document.emplace_back(0);
  document.emplace_back(1);
  document.emplace_back(2);
  document.emplace_back(3);
  draw(document, std::cout, 0);
}
