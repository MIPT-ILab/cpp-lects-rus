#include <iostream>
#include <exception>
#include <stdexcept>

using std::cerr;
using std::endl;
using std::runtime_error;
using std::exception_ptr;
using std::current_exception;
using std::rethrow_exception;

void do_raise () {
  throw runtime_error("Exception!");
}

exception_ptr get_exception () {
  try {
    do_raise ();
  }
  catch (...) {
    return current_exception ();
  }
  return nullptr;
}

int main () {
  exception_ptr e = get_exception ();
  try {
    rethrow_exception(e);
  }
  catch (runtime_error &e) {
    cerr << e.what() << endl;
  }
}

