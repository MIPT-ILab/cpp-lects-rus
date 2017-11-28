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

template <typename T>
void draw (const T &x, ostream& out, size_t position) {
  out << string (position, ' ') << x << endl;
}

class myclass_t {};

void draw(const myclass_t&, ostream& out, size_t position) {
  out << string(position, ' ') << "myclass_t" << endl;
}

class object_t; 
using document_t = vector<object_t>;

void draw (const document_t& x, ostream& out, size_t position);

class object_t {
  struct concept_t {
    virtual ~concept_t() = default;
    virtual unique_ptr<concept_t> copy_() const = 0;
    virtual void draw_(ostream&, size_t) const = 0;   
  };

  template <typename T>
  struct model final : concept_t {
    T data_;
    model(T x) : data_(move(x)) {}
    unique_ptr<concept_t> copy_() const override {
      return make_unique<model>(*this); 
     }
    void draw_(ostream& out, size_t position) const override {
      ::draw(data_, out, position);
    }
  };

  unique_ptr<concept_t> self_;
public:
  template <typename T>
  object_t(T x): self_(make_unique<model<T>>(move(x))) {}

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
  document.emplace_back(document);
  document.emplace_back(myclass_t{});
  draw(document, cout, 0);
}
