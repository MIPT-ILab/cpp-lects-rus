#include <memory>

#include "myres.h"

using std::make_shared;
using std::shared_ptr;

struct Node {
  MyRes r;
  shared_ptr<Node> parent, left, right;
};

void create_leak () {
  shared_ptr<Node> master = make_shared<Node>(); // cnt:1
  shared_ptr<Node> slave = make_shared<Node>(); // cnt:1
  slave->parent = master; // cnt:2
  master->left = slave; // cnt:2
  master->left->r.use();
  slave->parent->r.use();
}

int main () {
  cout << "--- start ---" << endl;
  create_leak();
  cout << "--- finish ---" << endl;
}

