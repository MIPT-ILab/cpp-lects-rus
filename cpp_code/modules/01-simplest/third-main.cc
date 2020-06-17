import <iostream>;
import first_module;

int main() {
  std::cout << "Hello imported: " << hello::bar() << std::endl;
}
