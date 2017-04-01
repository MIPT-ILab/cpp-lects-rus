#include <cstdio>

using namespace std;

/* Works both 1 and 0 here  */
#if 1

class Node 
{
private: 
  int data;
  int key;
  /* ... */

  friend class BinaryTree; /* class BinaryTree can now access data directly */
};

#else

class Node 
{
    private: 
    int data;
    int key;
    /* ... */

    friend int BinaryTree::find(); /* Only BinaryTree's find function has access */
};

#endif

class BinaryTree
{
  private:
  Node *root;

  int find(int key);
};

int BinaryTree::find(int key)
{
  /* check root */
  if(root->key == key)
    {
      /* no need to go through an accessor function */
      return root->data;
    }
  /* rest of find */
}

class Parent
{
    friend class Family;
    protected:
        virtual void Answer() = 0;
};

class Child : public Parent
{
  private:
    void Answer() { printf("Child!\n"); }
};

class Family
{
friend class Parent;
public:
  void ParentAnswer(Parent *p) { p->Answer(); } /* ok */
#if 0
  void ChildAnswer(Child *c) { c->Answer(); } /* error! */
#endif
};

int test(void)
{
  Child c;
  Family f;
  f.ParentAnswer(&c); /* ok */
  return 0;
}

