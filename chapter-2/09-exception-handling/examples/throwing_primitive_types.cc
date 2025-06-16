#include <iostream>

void CheckValue(int value) {
  if (value < 0) {
    throw "Value cannot be negative!";  // Throwing a C-string
  }
  std::cout << "Value is valid: " << value << std::endl;
}

int main() {
  try {
    CheckValue(-5);  // This will throw an exception
  } catch (const char* e) {
    std::cerr << "Caught an exception: " << e << std::endl;
  }

  return 0;
}