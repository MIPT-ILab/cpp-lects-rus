#include <cassert>
#include <iostream>
#include <memory>

using std::cout;
using std::endl;

template <typename Data> 
class Tree
{
  struct Node {
    unique_ptr<Node> left, right;
    Data d;
    Node(Data din) : left(nullptr), right(nullptr), d(din) {}
    ~Node() { cout << "destroying " << d << endl;
  };

  unique_ptr<Node> top_;
public:
  explicit Tree(int n[], int size) // tree out of array
    {
    }

  void release_subtree(unique_ptr<Node> u) {}
};

