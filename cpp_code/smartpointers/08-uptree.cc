#include <cassert>
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

template <typename Data> 
class Tree
{
  struct Node {
    unique_ptr<Node> left, right;
    Data d;
    Node(Data din) : left(nullptr), right(nullptr), d(din) {}
    ~Node() { cout << "destroying " << d << endl; }
  };

  Node *top_;
public:
  explicit Tree(int *n, int size) // tree out of array
    {
    }

  void release_subtree(unique_ptr<Node> u) {}
};

