#include <iostream>
#include <stdexcept>

void InnerFunction() { throw std::runtime_error("Error in InnerFunction!"); }

void OuterFunction() {
  try {
    InnerFunction();
  } catch (const std::runtime_error& e) {
    std::cerr << "Caught exception in OuterFunction: " << e.what() << std::endl;
    throw;  // Rethrow the exception
  }
}

int main() {
  try {
    OuterFunction();
  } catch (const std::runtime_error& e) {
    std::cerr << "Caught exception in main: " << e.what() << std::endl;
  }

  return 0;
}