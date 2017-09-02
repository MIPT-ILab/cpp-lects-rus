#include <memory>

using std::unique_ptr;

class MyClass;

struct MyClassDeleter {
  void operator()(MyClass *p);
};

struct MyWrapper { 
  MyClass *c; 
  MyWrapper() : c(nullptr) {}
};

struct MySafeWrapper { 
  unique_ptr<MyClass, MyClassDeleter> c; 
  MySafeWrapper() : c(nullptr) {}
};

