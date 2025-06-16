#include <iostream>
#include <stdexcept>
#include <string>

class MyCustomException : public std::exception {
 private:
  std::string message;

 public:
  MyCustomException(const std::string& msg) : message(msg) {}

  const char* what() const noexcept override { return message.c_str(); }
};

void ProcessInput(int input) {
  if (input == 0) {
    throw MyCustomException("Input cannot be zero!");
  }
  std::cout << "Input is valid: " << input << std::endl;
}

int main() {
  try {
    ProcessInput(0);  // This will throw a custom exception
  } catch (const MyCustomException& e) {
    std::cerr << "Caught custom exception: " << e.what() << std::endl;
  }

  return 0;
}