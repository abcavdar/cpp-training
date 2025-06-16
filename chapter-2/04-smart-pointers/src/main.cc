#include <iostream>
#include <memory>

namespace abc::smart_pointers {

class Logger {
 public:
  explicit Logger(const std::string& name) : name_(name) {
    std::cout << "Logger " << name_ << " created.\n";
  }

  ~Logger() { std::cout << "Logger " << name_ << " destroyed.\n"; }

  void Log(const std::string& message) const {
    std::cout << "[" << name_ << "]: " << message << "\n";
  }

 private:
  std::string name_;
};

void Test() {
  std::unique_ptr<int[]> arr = std::make_unique<int[]>(10);

  for (int i = 0; i < 10; ++i) {
      arr[i] = i * 2;
  }

  int* ptr = arr.get();
  for (int i = 0; i < 10; ++i) {
      std::cout << *(ptr + i) << " ";
  }
  std::cout << '\n';
}

auto UseLogger() {
  std::unique_ptr<Logger> logger = std::make_unique<Logger>("AppLogger");
  // std::unique_ptr<Logger> ptr;
  // ptr = logger; // Not Allowed.
  logger->Log("Hello, world!");
  return std::move(logger);
}  // Logger is automatically destroyed here

// reset(): Releases the current resource and optionally assigns a new one
// 1) reset() destroys the managed object if it exists.
// 2) If reset(new T) is used, it assigns a new object.
// 3) After reset(), the smart pointer becomes nullptr.
void ResetDemo() {
  // std::unique_ptr<T>::reset() deletes the managed object and resets the smart
  // pointer.

  // std::shared_ptr<T>::reset() decreases the reference count and releases
  // ownership if the count reaches zero.
  std::unique_ptr<Logger> logger = std::make_unique<Logger>("MainLogger");
  logger->Log("Logging initialized.");

  logger.reset();  // Logger object is destroyed here

  if (logger == nullptr) {
    std::cout << "Logger has been reset and is now null.\n";
  }

  logger.reset(new Logger("NewLogger"));  // Assigns a new Logger
  logger->Log("New log message.");
}

class Resource {
 public:
  explicit Resource(const std::string& name, int value)
      : name_(name), value_(value) {
    std::cout << "Resource " << name_ << " allocated.\n";
  }

  ~Resource() { std::cout << "Resource " << name_ << " deallocated.\n"; }

  void Print() const { std::cout << "Using resource: " << name_ << "\n"; }
  int GetValue() const { return value_; }

 private:
  std::string name_;
  int value_;
};

// swap(): Exchanges ownership of resources between two smart pointers
// 1) swap() is useful when you need to efficiently exchange resources.
// 2) The destructor of the objects is not called during swapping.
void SwapDemo() {
  // std::unique_ptr<T>::swap(std::unique_ptr<T>& other): Swaps resources
  // between two unique_ptr instances.
  std::unique_ptr<Resource> ptr1 = std::make_unique<Resource>("Resource 1", 10);
  std::unique_ptr<Resource> ptr2 = std::make_unique<Resource>("Resource 2", 20);

  std::cout << "Before swap: ptr1 = " << ptr1->GetValue()
            << ", ptr2 = " << ptr2->GetValue() << "\n";

  ptr1.swap(ptr2);  // Swap ownership

  std::cout << "After swap: ptr1 = " << ptr1->GetValue()
            << ", ptr2 = " << ptr2->GetValue() << "\n";
}

void SharedResourceDemo() {
  std::shared_ptr<Resource> res1 = std::make_shared<Resource>("SharedRes", 10);

  std::cout << "Reference count: " << res1.use_count() << "\n";  // Output: 1
  {
    std::shared_ptr<Resource> res2 = res1;  // Shared ownership
    res2->Print();
    std::cout << "Reference count: " << res1.use_count() << "\n";  // Output: 2
  }  // res2 goes out of scope, but resource is still owned by res1

  std::cout << "Reference count: " << res1.use_count() << "\n";  // Output: 1
  res1->Print();  // Resource still exists
}  // res1 goes out of scope, resource is deallocated

// std::shared_ptr<T>::swap() exchanges ownership of resources between two
// shared_ptr instances. This means that the reference counts of the swapped
// objects remain unchanged, but the shared_ptr instances themselves now point
// to different resources. 

// 1) Efficient Resource Swapping – Instead of reassigning, swapping is 
// more efficient. 
// 2) Exception Safety – swap() provides a strong exception guarantee. 
// 3) Temporary Ownership Transfer – Useful when handling multiple 
// references dynamically.
void SwapSharedPtrDemo() {
  // std::shared_ptr<T>::swap(std::shared_ptr<T>& other): Swaps shared ownership
  // between shared_ptr instances.
  std::shared_ptr<Resource> ptr1 =
      std::make_shared<Resource>("Resource 1", 101);
  std::shared_ptr<Resource> ptr2 =
      std::make_shared<Resource>("Resource 2", 202);

  std::cout << "Before swap:\n";
  std::cout << "ptr1 ID: " << ptr1->GetValue()
            << ", Reference count: " << ptr1.use_count() << "\n";
  std::cout << "ptr2 ID: " << ptr2->GetValue()
            << ", Reference count: " << ptr2.use_count() << "\n";

  ptr1.swap(ptr2);  // Swap the managed resources

  std::cout << "\nAfter swap:\n";
  std::cout << "ptr1 ID: " << ptr1->GetValue()
            << ", Reference count: " << ptr1.use_count() << "\n";
  std::cout << "ptr2 ID: " << ptr2->GetValue()
            << ", Reference count: " << ptr2.use_count() << "\n";
}

class Device {
  public:
   Device() { std::cout << "Device initialized.\n"; }
   ~Device() { std::cout << "Device shut down.\n"; }
   void Operate() { std::cout << "Operating device...\n"; }
 };
 
 // get(): Returns the raw pointer without transferring ownership
 // 1) get() does not transfer ownership, so the smart pointer is 
 // still responsible for deallocating the object.
 // 2) It is useful when interfacing with APIs that require raw pointers.
 void GetDemo() {
  // std::unique_ptr<T>::get(): Retrieves the raw pointer managed by unique_ptr.
  std::unique_ptr<Device> device = std::make_unique<Device>();
  Device* raw_ptr = device.get();  // Obtain raw pointer

  raw_ptr->Operate();  // Use raw pointer safely
}

class Sensor {
  public:
   Sensor() { std::cout << "Sensor activated.\n"; }
   ~Sensor() { std::cout << "Sensor deactivated.\n"; }
 };
 
// release(): Transfers ownership and sets the smart pointer to nullptr
// 1) release() returns the raw pointer and makes the unique_ptr null.
// 2) The caller must manually delete the raw pointer to avoid memory leaks.
 void ReleaseDemo() {
  Sensor* raw_sensor = nullptr;
  {
    std::unique_ptr<Sensor> sensor = std::make_unique<Sensor>();
    raw_sensor = sensor.release();  // Transfers ownership
    if (!sensor) {
      std::cout << "sensor is now null after release.\n";
    }
  }
   
  delete raw_sensor;  // Manually delete the raw pointer
}

class Node {
 public:
  explicit Node(int value) : value_(value) {
    std::cout << "Node " << value_ << " created.\n";
  }

  ~Node() { std::cout << "Node " << value_ << " destroyed.\n"; }
  int value() const {
    return value_;
  }

  std::weak_ptr<Node> prev() const {
    return prev_;
  }
  void SetNext(std::shared_ptr<Node> next) { next_ = next; }
  void SetPrev(std::weak_ptr<Node> prev) { prev_ = prev; }

 private:
  int value_;
  std::shared_ptr<Node> next_;
  std::weak_ptr<Node> prev_;  // Weak reference to prevent cyclic ownership
};

void WeakPointerDemo() {
  std::shared_ptr<Node> node1 = std::make_shared<Node>(1);
  std::shared_ptr<Node> node2 = std::make_shared<Node>(2);

  std::cout << "node1 use count before: " << node1.use_count() << std::endl;
  node1->SetNext(node2);
  node2->SetPrev(node1);  // Prevent cyclic reference with std::weak_ptr
  std::cout << "node1 use count after: " << node1.use_count() << std::endl;
  std::cout << "node2 value: " << node2->value() << std::endl;
  // std::cout << node2->prev()->value() << std::endl;
  auto p = node2->prev().lock();
  if (p != nullptr) {
    std::cout << "Value of prev: " << p->value() << std::endl;
  }
}  // Both nodes are deallocated properly

}  // namespace abc::smart_pointers

using namespace abc::smart_pointers;

int main() {
  // Test();
  // auto ptr = abc::smart_pointers::UseLogger();
  // ptr->Log("Log from outer scope!");

  // abc::smart_pointers::ResetDemo();
  // abc::smart_pointers::SwapDemo();
  // abc::smart_pointers::GetDemo();
  // abc::smart_pointers::ReleaseDemo();
  // abc::smart_pointers::SharedResourceDemo();
  // abc::smart_pointers::SwapSharedPtrDemo();
  abc::smart_pointers::WeakPointerDemo();
  return 0;
}
