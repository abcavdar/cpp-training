#include <iostream>
#include <vector>

using namespace std;

int main() {
  int number = -35;
  double d = 3.14;
  double d1 = 22 / 7.0;
  bool is_defined = false;  // 0: false, nonzero: true

  // if statement
  if (d) {  // Valid, but not recommended
    std::cout << "d is true" << std::endl;
  }

  if (number) {  // Valid, but not recommended
    std::cout << "Number is true" << std::endl;
  }

  if (d1 == d) {  // Recommended use: logical expression
    cout << "d and d1 are EQUAL!" << endl;
  } else {
    cout << "d and d1 are NOT EQUAL!" << endl;
  }

  if (!is_defined) {  // Recommended use: bool variable
    std::cout << "Value of is_defined: " << is_defined << std::endl;
  }

  if (number > 5) {  // Recommended use: logical expression
    cout << "Number is greater than 5." << endl;
  }

  if (number > 0)  // Be careful to use curly braces!
    cout << number;
  number++;  // Indentation here is not important!

  int *ptr;
  if (is_defined && (ptr = new int{35}) != nullptr) {
    *ptr = 50;
  }

  if (ptr != nullptr) {
    cout << "*ptr: " << *ptr << endl;
  }

  // if-else
  if (number >= 0) {
    cout << "Number is greater than or equal to 0: " << number << endl;
  } else {
    cout << "Number is less than 0: " << number << endl;
  }

  // if-else ladder
  if (number >= 0) {
    cout << "Number is greater than or equal to 0: " << number << endl;
  } else if (number < 0 && number > -10) {
    cout << "Number is between -10 and 0: " << number << endl;
  } else if (number <= -10 && number > -20) {
    cout << "Number is between -20 and -10: " << number << endl;
  } else {
    cout << "Number is less than or equal to -20: " << number << endl;
  }

  // switch
  int choice = 5;

  switch (choice) {
    case 1:
      cout << "Option 1 selected." << endl;
      break;
    case 2:
      cout << "Option 2 selected." << endl;
      break;
    case 3:
      cout << "Option 3 selected." << endl;
      break;
    case 4:
    case 5:
      cout << "Option 4 or 5 selected." << endl;
      break;
    default:
      cout << "Invalid option!" << endl;
  }

  // For loop
  cout << "Displaying numbers between 1 and 10" << endl;
  for (int i = 0; i < 10; i++) {
    cout << i + 1 << endl;
  }

  cout << "Displaying even numbers between 0 and 9" << endl;
  for (int i = 0; i < 10; i += 2) {
    cout << i << endl;
  }

  // while loop
  cout << "Displaying numbers between 1 and 10 using while statement" << endl;
  int i = 11;
  while (i < 10) {
    cout << i + 1 << endl;
    i++;
  }

  // do-while loop
  cout << "Displaying numbers between 1 and 10 using do-while statement"
       << endl;
  i = 11;
  do {
    cout << i + 1 << endl;
    i++;
  } while (i < 10);

  std::vector<double> nums = {1.0, 2.0, 3.0, 4.0, 5.0};
  cout << "With for loop " << endl;
  for (std::vector<double>::iterator it = nums.begin(); it != nums.end();
       it++) {
    cout << *it << " ";
  }
  std::cout << std::endl;

  // C++11 range-based for loop
  cout << "With range based for loop " << endl;
  for (auto num : nums) {  // num is deduced as int
    std::cout << num << " ";
  }
  std::cout << std::endl;

  int arr[5]{1, 2, 3, 4, 5};

  cout << "Iterate arr array with range based for loop " << endl;
  for (auto num : arr) {  // num is deduced as int
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}