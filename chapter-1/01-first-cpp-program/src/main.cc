/*============================================================*\
 |      This is multi-line comment example                    |
 |      The first C++ program !!                              |
\*============================================================*/
#include <iostream>  // Include the header of the iostream library

int main(void) {  // Program execution starts from the main!
// Compiler-specific code
#ifdef __GNUC__
  // GCC-specific code
  std::cout << "Build with MinGW GCC..." << std::endl;  // Console output
#elif defined(_MSC_VER)
  // MSVC-specific code
  std::cout << "Build with MSVC..." << std::endl;  // Console output
#endif

  // This is single line comment example
  std::cout << "Hello world!" << std::endl;  // Console output

  // Console input
  int a = 0, b = 0;
  std::cout << "a: " << a << " b: " << b << std::endl;

  std::cout << "Enter two integers by seperating them with spaces. To complete "
               "entry, press <Enter> key: ";
  std::cin >> a >> b;
  std::cout << "a: " << a << " b: " << b << std::endl;

  // Formatting examples

  return 0;
}
