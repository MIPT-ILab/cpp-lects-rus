#include <iostream>

using std::cout;
using std::endl;

class X {
	int private_;  
public:
	X() : private_(1) {}
	template <typename T> void f(const T& t) { /* .... */ }
	int value(void) const { return private_; }
};

namespace { struct Y {}; }
template <> void X::f<Y>(const Y&) { private_ = 2; }

int
main (void)
{
	X x;
	x.f(Y{});
	cout << x.value() << endl;
}

