#include <iostream>
#include <map>
#include <string>

// Function to print the contents of a map
void PrintMap(const std::map<std::string, int>& map_data) {
  for (const auto& pair : map_data) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }
}

int main() {
  // 1. Declaration and Initialization
  std::map<std::string, int> student_grades;
  
  // 2. Inserting Elements
  student_grades["Ahmet"] = 85;  // Using operator[]
  student_grades["Birol"] = 92;
  student_grades.insert({"Ezgi", 78});  // Using insert()
  
  // 3. Accessing Elements
  std::cout << "Ahmet's Grade: " << student_grades["Ahmet"] << std::endl;
  
  // 4. Searching for a Key
  auto it = student_grades.find("Utku");
  if (it != student_grades.end()) {
    std::cout << "Utku's Grade: " << it->second << std::endl;
  } else {
    std::cout << "Utku is not in the map." << std::endl;
  }
  
  // 5. Modifying Elements
  student_grades["Ahmet"] = 100;  // Updates value for the existing key
  
  // 6. Erasing an Element
  student_grades.erase("Birol");
  
  // 7. Iterating through the Map
  std::cout << "Current Student Grades:" << std::endl;
  PrintMap(student_grades);
  
  // 8. Checking Size and Emptiness
  std::cout << "Number of Students: " << student_grades.size() << std::endl;
  if (student_grades.empty()) {
    std::cout << "No students in the map." << std::endl;
  } else {
    std::cout << "The map is not empty." << std::endl;
  }
  
  return 0;
}
