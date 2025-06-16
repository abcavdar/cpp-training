#include <iostream>
#include <string>	// C++ Standard String library header
#include <cstring>	// For C-Style strings

void PrintString(const std::string& str) { // Pass std::string as const std::string& in function parameters to avoid unnecessary copies.
  std::cout << str << std::endl;
}

int main() {
  // Initialization
  std::string empty_str;                   // Empty string
  std::string str1 = "Hello";               // Using string literal
  std::string str2("World");                // Direct initialization
  std::string str3(5, '!');                 // Repeated characters: "!!!!!"
  std::string str4 = str1 + " " + str2;     // Concatenation

  PrintString(empty_str);
  PrintString(str1);
  PrintString(str2);
  PrintString(str3);
  PrintString(str4);

  // 1. Accessing characters
  std::string str = "Hello";

  // Using index operator
  std::cout << "First character: " << str[0] << std::endl;

  // Using at() method (with bounds checking)
  std::cout << "Second character: " << str.at(1) << std::endl;

  // Modifying a character
  str[0] = 'h';
  std::cout << "Modified string: " << str << std::endl;
  
  // 2. Iterating over characters
  // Using range-based for loop
  std::cout << "Characters: ";
  for (auto ch : str) {
    std::cout << ch << ' ';
  }
  std::cout << std::endl;

  // Using iterators
  std::cout << "Reversed: ";
  for (auto it = str.rbegin(); it != str.rend(); ++it) {
    std::cout << *it;
  }
  std::cout << std::endl;
  
  // 3. Common operations
  str = "Hello World";
  // Finding substrings
  std::size_t pos = str.find("World");
  if (pos != std::string::npos) {
    std::cout << "'World' found at index: " << pos << std::endl;
  }

  pos = str.find("Ahmet");
  if (pos == std::string::npos) {
    std::cout << "'Ahmet' NOT found!" << std::endl;
  }

  // Substring
  std::string sub = str.substr(6, 5);  // "World"
  std::cout << "Substring: " << sub << std::endl;

  // Insertion
  str.insert(5, ", Beautiful");
  std::cout << "After insertion: " << str << std::endl;

  // Erasing
  str.erase(5, 11);  // Removes ", Beautiful"
  std::cout << "After erasing: " << str << std::endl;

  // Replacing
  str.replace(6, 5, "Universe");
  std::cout << "After replacing: " << str << std::endl;
  
  // C-Style string compatibility
  std::string cpp_str = "Hello";
  
  // Getting C-style string
  const char* c_str = cpp_str.c_str();
  std::cout << "C-style string: " << c_str << std::endl;
  
  // Converting C-style string to std::string
  const char* another_c_str = "World";
  std::string another_cpp_str = another_c_str;
  std::cout << "std::string from C-string: " << another_cpp_str << std::endl;
  
  return 0;
}
