/*---------------------------------------------------------------------------

std::exception  <-- Base class for all standard exceptions
│
├── std::logic_error       <-- Errors detectable before runtime (logic errors)
│   ├── std::domain_error      <-- Invalid domain of input
│   ├── std::invalid_argument  <-- Invalid argument in function
│   ├── std::length_error      <-- Too long object (e.g., string, vector)
│   ├── std::out_of_range      <-- Access out of valid range (e.g., vector.at())
│
├── std::runtime_error     <-- Errors that occur during program execution
│   ├── std::overflow_error    <-- Arithmetic overflow
│   ├── std::underflow_error   <-- Arithmetic underflow
│   ├── std::range_error       <-- Result is out of range
│   ├── std::system_error      <-- Errors from system calls (C++11)
│       ├── std::ios_base::failure <-- I/O operation failure (C++11)
│
├── std::bad_alloc         <-- Memory allocation failure (e.g., new fails)
├── std::bad_cast          <-- Invalid type casting using dynamic_cast
├── std::bad_typeid        <-- Accessing typeid on null pointer of polymorphic type
├── std::bad_exception     <-- Unexpected exception caught by `std::set_unexpected()`
│
└── std::ios_base::failure <-- I/O stream failures (moved under std::system_error in C++11)

-----------------------------------------------------------------------------*/
#include <iostream>
#include <stdexcept>

void InnerFunction1(int x) {
  if (x < 0) {
    throw std::domain_error("Domain Error in InnerFunction1!");
  } 
}

void InnerFunction2(int x) {
  if (x < 0) {
    std::cout << "InnerFunction2: x = " << x << std::endl;
  } else {
    throw std::runtime_error("Runtime Error in InnerFunction2!");
  }
}

void OuterFunction() {
  try {
    InnerFunction1(-1);
    InnerFunction2(1);
  } catch (const std::domain_error& e) {
    std::cerr << "Caught domain error in OuterFunction: " << e.what() << std::endl;
  }
  // Any other code
}

int main() {
  try {
    OuterFunction();
  } catch (const std::runtime_error& e) {
    std::cerr << "Caught runtime exception in main: " << e.what() << std::endl;
  } catch (const std::domain_error& e) {
    std::cerr << "Caught domain error in main: " << e.what() << std::endl;
  }
  std::cout << "After OuterFunction!!" << std::endl;

  return 0;
}