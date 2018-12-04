#include <memory>

#include "myres.h"

using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;

struct Node {
  MyRes r;
  weak_ptr<Node> parent;
  shared_ptr<Node> left, right;
};

void use_parent (shared_ptr<Node> pnode) {
  auto newref = pnode->parent.lock(); // cnt:2
  if (newref) {
    newref->r.use();
    newref.reset(new Node());
  }
} // cnt:1 again

void create_no_leak () {
  shared_ptr<Node> master = make_shared<Node>(); // cnt:1
  shared_ptr<Node> slave = make_shared<Node>(); // cnt:1
  slave->parent = master; // cnt:1
  master->left = slave; // cnt:2
  master->left->r.use();
  use_parent(slave);
}

int main () {
  cout << "--- start ---" << endl;
  create_no_leak();
  cout << "--- finish ---" << endl;
}

