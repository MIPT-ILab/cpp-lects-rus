#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::make_unique;
using std::ostream;
using std::size_t;
using std::string;
using std::unique_ptr;
using std::vector;

void draw (const int &x, ostream& out, size_t position) {
  out << string (position, ' ') << x << endl;
}

class object_t {
  struct int_model_t {
    int data_;
    int_model_t(int x) : data_(x) {}
    void draw(ostream& out, size_t position) const {
      // кстати отличный пример на disambiguation
      ::draw(data_, out, position);
    }
  };

  unique_ptr<int_model_t> self_;
public:
  object_t(int x): self_(make_unique<int_model_t>(x)) {}

// copy ctor and assignment
public:
  object_t(const object_t& x) : self_(make_unique<int_model_t>(*x.self_)) {}
  object_t& operator=(const object_t& x) {
    object_t tmp(x);
    self_ = move(tmp.self_);
    return *this;
  }

public:
  friend void draw(const object_t& x, ostream& out, size_t position) {
    x.self_->draw(out, position);
  }
};

using document_t = vector<object_t>;

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
