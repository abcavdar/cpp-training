#include <iostream>
#include <vector>

int main() {
  // 1. Creation and initialization
  // Empty vector of integers
  std::vector<int> empty_vector;

  // Vector with initial size 5, all elements initialized to 0
  std::vector<int> size_initialized(5);

  // Vector with initial size 5, all elements initialized to 42
  std::vector<int> value_initialized(5, 42);

  // Vector initialized using an initializer list
  std::vector<int> initializer_list = {1, 2, 3, 4, 5};

  // Copy constructor
  std::vector<int> copy_vector(initializer_list);

  // Move constructor
  std::vector<int> moved_vector(std::move(copy_vector));

  // Output the contents
  std::cout << "initializer_list: ";
  for (const auto& elem : initializer_list) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  std::cout << "moved_vector: ";
  for (const auto& elem : moved_vector) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  // 2. Accessing elements
  std::vector<int> numbers = {10, 20, 30, 40, 50};
  // Access using operator[]
  std::cout << "First element (operator[]): " << numbers[0] << std::endl;

  // Access using .at() (with bounds checking)
  std::cout << "Second element (at()): " << numbers.at(1) << std::endl;

  // Accessing the first and last elements
  std::cout << "First element: " << numbers.front() << std::endl;
  std::cout << "Last element: " << numbers.back() << std::endl;  
  
  // 3. Modifying elements
  // Adding elements
  numbers.push_back(10);
  numbers.push_back(20);
  numbers.push_back(30);
  
  // Inserting elements
  numbers.insert(numbers.begin() + 1, 15);

  // Erasing elements
  numbers.erase(numbers.begin() + 2);

  // Clearing all elements
  numbers.clear();

  std::cout << "Size after clearing: " << numbers.size() << std::endl;
  
  // 4. Iteration
  // Using index-based loop
  for (std::size_t i = 0; i < numbers.size(); ++i) {
    std::cout << "Index " << i << ": " << numbers[i] << std::endl;
  }

  // Using range-based for loop
  std::cout << "Range-based loop: ";
  for (const auto& number : numbers) {
    std::cout << number << " ";
  }
  std::cout << std::endl;

  // Using iterators
  std::cout << "Iterator loop: ";
  for (auto it = numbers.begin(); it != numbers.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  
  // 5. Capacity management
  std::vector<int> numbers2;
  std::cout << "Initial size: " << numbers2.size() << std::endl;
  std::cout << "Initial capacity: " << numbers2.capacity() << std::endl;

  numbers2.reserve(10);  // Pre-allocate space for 10 elements
  std::cout << "Capacity after reserve(10): " << numbers2.capacity() << std::endl;

  numbers2.push_back(1);
  numbers2.push_back(2);

  std::cout << "Size after push_back: " << numbers2.size() << std::endl;
  std::cout << "Capacity after push_back: " << numbers2.capacity() << std::endl;

  numbers2.shrink_to_fit();  // Reduce capacity to fit the current size
  std::cout << "Capacity after shrink_to_fit: " << numbers2.capacity() << std::endl;

  return 0;
}
