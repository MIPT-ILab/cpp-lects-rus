#include <algorithm>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::make_unique;
using std::move;
using std::ostream;
using std::reverse;
using std::size_t;
using std::string;
using std::unique_ptr;
using std::vector;

void draw (const int &x, ostream& out, size_t position) {
  out << string (position, ' ') << x << endl;
}

void draw (const string &x, ostream& out, size_t position) {
  out << string (position, ' ') << x << endl;
}


class object_t {
  struct concept_t {
    virtual ~concept_t() = default;
    virtual unique_ptr<concept_t> copy_() const = 0;
    virtual void draw_(ostream&, size_t) const = 0;   
  };

  struct int_model_t final : concept_t {
    int data_;
    int_model_t(int x) : data_(move(x)) {}
    unique_ptr<concept_t> copy_() const override {
      return make_unique<int_model_t>(*this); 
     }
    void draw_(ostream& out, size_t position) const override {
      ::draw(data_, out, position);
    }
  };

  struct string_model_t final : concept_t {
    string data_;
    string_model_t(string x) : data_(move(x)) {}
    unique_ptr<concept_t> copy_() const override {
      return make_unique<string_model_t>(*this); 
     }
    void draw_(ostream& out, size_t position) const override {
      ::draw(data_, out, position);
    }
  };

  unique_ptr<concept_t> self_;
public:
  object_t(int x): self_(make_unique<int_model_t>(move(x))) {}

  object_t(string x): self_(make_unique<string_model_t>(move(x))) {}

// copy ctor, move ctor and assignment
public:
  object_t(const object_t& x) : self_(x.self_->copy_()) {}
  object_t(object_t&& x) noexcept = default;
  object_t& operator=(object_t x) noexcept {
    self_ = move(x.self_);
    return *this;
  }

public:
  friend void draw(const object_t& x, ostream& out, size_t position) {
    x.self_->draw_(out, position);
  }
};

using document_t = vector<object_t>;

void draw (const document_t& x, ostream& out, size_t position) {
  out << string (position, ' ') << "<document>" << endl;
  for (const auto& e : x)
    draw (e, out, position + 2);
  out << string (position, ' ') << "</document>" << endl;
}

int
main () {
  document_t document;
  document.emplace_back(0);
  document.emplace_back(string("Hello"));
  document.emplace_back(2);
  document.emplace_back(3);
  draw(document, cout, 0);
}
