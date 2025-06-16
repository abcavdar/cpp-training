#include <iostream>

//Function template
template <typename T>
void Swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

// Class templates
template <typename T1, typename T2>
class Pair {
 public:
  Pair(T1 first, T2 second) : first_(first), second_(second) {}

  void Display() const {
    std::cout << "First: " << first_ << ", Second: " << second_ << std::endl;
  }

 private:
  T1 first_;
  T2 second_;
};

int main() {
  // Function template usage
  int x = 5;
  int y = 10;
  std::string s;

  std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
  Swap(x, y);
  std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

  double d1 = 3.14;
  double d2 = 2.71;

  std::cout << "Before swap: d1 = " << d1 << ", d2 = " << d2 << std::endl;
  Swap(d1, d2);
  // Swap(x, d2); // Not allowed
  std::cout << "After swap: d1 = " << d1 << ", d2 = " << d2 << std::endl;

  // Class template usage
  Pair<int, double> int_double_pair(42, 3.14);
  int_double_pair.Display();

  Pair<std::string, char> string_char_pair("Hello", 'A');
  string_char_pair.Display();

  return 0;
}
