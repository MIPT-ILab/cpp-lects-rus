#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ostream;
using std::shared_ptr;
using std::size_t;
using std::string;
using std::vector;

struct object_t {
  virtual ~object_t() {}
  virtual void draw(ostream&, size_t) const = 0;
};

using document_t = vector<shared_ptr<object_t>>;

void draw (const document_t& x, ostream& out, size_t position) {
  out << string (position, ' ') << "<document>" << endl;
  for (const auto& e : x)
    e->draw (out, position + 2);
  out << string (position, ' ') << "</document>" << endl;
}

struct myclass_t final : public object_t {
  void draw(ostream &out, size_t position) const override {
    out << string (position, ' ') << "my class" << endl;
  }
};

int
main ()
{
  document_t document;
  document.emplace_back(new myclass_t());
  draw(document, cout, 0);
}
