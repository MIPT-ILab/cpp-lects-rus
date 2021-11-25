#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct object_t {
  virtual ~object_t() {}
  virtual void draw(std::ostream &, size_t) const = 0;
};

using document_t = std::vector<std::shared_ptr<object_t>>;

void draw(const document_t &x, std::ostream &out, size_t position) {
  out << std::string(position, ' ') << "<document>" << std::endl;
  for (const auto &e : x)
    e->draw(out, position + 2);
  out << std::string(position, ' ') << "</document>" << std::endl;
}

struct myclass_t final : public object_t {
  void draw(std::ostream &out, size_t position) const override {
    out << std::string(position, ' ') << "my class" << std::endl;
  }
};

struct yourclass_t final : public object_t {
  void draw(std::ostream &out, size_t position) const override {
    out << std::string(position, ' ') << "your class" << std::endl;
  }
};

int main() {
  document_t document;
  document.emplace_back(new myclass_t());
  document.emplace_back(new yourclass_t());
  draw(document, std::cout, 0);
}
