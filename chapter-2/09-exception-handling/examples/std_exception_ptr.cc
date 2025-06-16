#include <exception>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

// A function that may throw an exception.
void RiskyOperation() {
  throw std::runtime_error("Something went wrong in RiskyOperation");
}

// Function wrapper that catches exceptions and returns an exception pointer.
std::exception_ptr SafeExecute() noexcept {
  try {
    RiskyOperation();
  } catch (...) {
    return std::current_exception();  // Capture the exception
  }
  return nullptr;  // No exception occurred
}

// Function to handle and report exceptions.
void HandleException(const std::exception_ptr& eptr) noexcept {
  if (eptr) {
    try {
      std::rethrow_exception(eptr);
    } catch (const std::exception& e) {
      std::cerr << "Caught exception: " << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Caught unknown exception" << std::endl;
    }
  }
}

int main() {
  std::exception_ptr eptr = SafeExecute();
  HandleException(eptr);
  return 0;
}
