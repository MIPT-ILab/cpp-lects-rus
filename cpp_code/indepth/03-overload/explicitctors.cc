#include <iostream>

struct S0 { S0() {} };
struct T0 { explicit T0() {} };

struct S2 { S2(int, int) {} };
struct T2 { explicit T2(int, int) {} };

void foo(S0) { std::cout << "S0" << std::endl; }
void bar(T0) { std::cout << "T0" << std::endl; }

void foo(S2) { std::cout << "S2" << std::endl; }
void bar(T2) { std::cout << "T2" << std::endl; }

int main() {
    foo({}); // works
    bar({}); // fails
    foo({42, 42}); // works
    bar({42, 42}); // fails
}
