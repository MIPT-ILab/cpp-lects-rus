#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ostream;
using std::size_t;
using std::string;
using std::vector;

using object_t = int;
using document_t = vector<object_t>;

void draw (const object_t& x, ostream& out, size_t position) {
  out << string (position, ' ') << x << endl;
}

void draw (const document_t& x, ostream& out, size_t position) {
  out << string (position, ' ') << "<document>" << endl;
  for (const auto& e : x)
    draw (e, out, position + 2);
  out << string (position, ' ') << "</document>" << endl;
}

int main () {
  document_t document;
  document.emplace_back(0);
  document.emplace_back(1);
  document.emplace_back(2);
  document.emplace_back(3);
  draw(document, cout, 0);
}
