#include <iostream>
#include <abc_list.h>

using namespace abc;

int main() {
  abc::DoublyLinkedList<int> list;
  list.PushBack(10);
  list.PushBack(20);
  list.PushBack(30);
  list.PushBack(40);
  list.PushBack(50);

  std::cout << "The element at the front: " << list.front() << std::endl;
  std::cout << "The element at the back: " << list.back() << std::endl;

  std::cout << "Pushing from the front..." << std::endl;
  list.PushFront(5);
  std::cout << "The element at the front: " << list.front() << std::endl;

  std::cout << "Popping from the front..." << std::endl;
  list.PopFront();
  std::cout << "The element at the front: " << list.front() << std::endl;

  std::cout << "Popping from the back..." << std::endl;
  list.PopBack();
  std::cout << "The element at the back: " << list.back() << std::endl;

  std::cout << "Finding the element 30..." << std::endl;
  auto it = list.Find(30);
  if (it != list.end()) {
    std::cout << "Found " << *it << std::endl;
    std::cout << "Inserting before the iterator..." << std::endl;
    list.Insert(it, 25);
  }

  std::cout << "Emplace front..." << std::endl;
  list.EmplaceFront(1);
  
  std::cout << "Emplace back..." << std::endl;
  list.EmplaceBack(100);

  std::cout << "Iterating over the contents of the list..." << std::endl;
  for (int val : list) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  std::cout << "Clearing the list..." << std::endl;
  list.Clear();

  return 0;
}
