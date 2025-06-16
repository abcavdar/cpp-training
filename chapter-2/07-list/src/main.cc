#include <iostream>
#include <list>

// Custom data type
struct Person {
  std::string name;
  int age;

  // Constructor
  Person(const std::string& name, int age) : name(name), age(age) {}
};

// Overloading << for easy printing
std::ostream& operator<<(std::ostream& os, const Person& person) {
  os << person.name << " (" << person.age << ")";
  return os;
}

int main() {
  // 1. Creation and modification
  // Create an empty list of integers
  std::list<int> numbers;

  // Add elements to the end and front
  numbers.push_back(10);
  numbers.push_back(20);
  numbers.push_front(5);

  // Insert an element at the second position
  auto it = numbers.begin();
  ++it;
  numbers.insert(it, 15);  // List: 5, 15, 10, 20

  // Erase the second element
  it = numbers.begin();
  ++it;
  numbers.erase(it);  // List: 5, 10, 20

  // Display the elements
  std::cout << "List elements: ";
  for (int num : numbers) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  // Clear the list
  numbers.clear();
  if (numbers.empty()) {
    std::cout << "The list is now empty." << std::endl;
  }

  // 2. Iterating with iterators
  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_back(3);
  numbers.push_back(4);
  numbers.push_back(5);
  numbers.push_back(6);
  
  // Iterate using an iterator
  std::cout << "Forward iteration: ";
  for (auto it = numbers.begin(); it != numbers.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  // Reverse iteration
  std::cout << "Reverse iteration: ";
  for (auto rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
    std::cout << *rit << " ";
  }
  std::cout << std::endl;
  
  // 3.  Using std::list with custom data type
  // Create a list of Person objects
  std::list<Person> people;
  people.emplace_back("Ahmet", 30);
  people.emplace_back("Birol", 25);
  people.emplace_back("Ezgi", 35);

  // Display the list of people
  std::cout << "People in the list: " << std::endl;
  for (const auto& person : people) {
    std::cout << person << std::endl;
  }
  
  // 4. 
  return 0;
}
