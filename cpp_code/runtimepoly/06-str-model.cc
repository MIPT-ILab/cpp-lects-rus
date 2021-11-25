#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

void draw(const int &x, std::ostream &out, size_t position) {
  out << std::string(position, ' ') << x << std::endl;
}

void draw(const std::string &x, std::ostream &out, size_t position) {
  out << std::string(position, ' ') << x << std::endl;
}

class object_t {
  struct concept_t {
    virtual ~concept_t() = default;
    virtual std::unique_ptr<concept_t> copy_() const = 0;
    virtual void draw_(std::ostream &, size_t) const = 0;
  };

  struct int_model_t final : concept_t {
    int data_;
    int_model_t(int x) : data_(std::move(x)) {}
    std::unique_ptr<concept_t> copy_() const override {
      return std::make_unique<int_model_t>(*this);
    }
    void draw_(std::ostream &out, size_t position) const override {
      ::draw(data_, out, position);
    }
  };

  struct string_model_t final : concept_t {
    std::string data_;
    string_model_t(std::string x) : data_(std::move(x)) {}
    std::unique_ptr<concept_t> copy_() const override {
      return std::make_unique<string_model_t>(*this);
    }
    void draw_(std::ostream &out, size_t position) const override {
      ::draw(data_, out, position);
    }
  };

  std::unique_ptr<concept_t> self_;

public:
  object_t(int x) : self_(std::make_unique<int_model_t>(std::move(x))) {}

  object_t(std::string x)
      : self_(std::make_unique<string_model_t>(std::move(x))) {}

  // copy ctor, move ctor and assignment
public:
  object_t(const object_t &x) : self_(x.self_->copy_()) {}
  object_t(object_t &&x) noexcept = default;
  object_t &operator=(object_t x) noexcept {
    self_ = std::move(x.self_);
    return *this;
  }

public:
  friend void draw(const object_t &x, std::ostream &out, size_t position) {
    x.self_->draw_(out, position);
  }
};

using document_t = std::vector<object_t>;

void draw(const document_t &x, std::ostream &out, size_t position) {
  out << std::string(position, ' ') << "<document>" << std::endl;
  for (const auto &e : x)
    draw(e, out, position + 2);
  out << std::string(position, ' ') << "</document>" << std::endl;
}

int main() {
  document_t document;
  document.emplace_back(0);
  document.emplace_back(std::string("Hello"));
  document.emplace_back(2);
  document.emplace_back(3);
  draw(document, std::cout, 0);
}
