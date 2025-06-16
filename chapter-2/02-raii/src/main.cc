#include <iostream>
#include <stdexcept>
#include <vector>

class BufferManager {
public:
    BufferManager(size_t size) : bufferSize(size) {
        // Allocate the buffer on the stack
        buffer = new char[bufferSize];
        std::memset(buffer, 0, bufferSize); // Clear the buffer
        std::cout << "Buffer of size " << bufferSize << " allocated.\n";
    }

    ~BufferManager() {
        // Release the buffer
        delete[] buffer;
        std::cout << "Buffer released.\n";
    }

    char* getBuffer() const {
        return buffer;
    }

    size_t getSize() const {
        return bufferSize;
    }

private:
    char* buffer;    // Pointer to the buffer
    size_t bufferSize; // Size of the buffer
};

// Function simulating a processing task
void processData() {
    BufferManager buffer(256); // Allocate a 256-byte buffer on the stack
    char* data = buffer.getBuffer();
    throw std::exception("Exception occurred!");
    // Simulate data processing
    std::strncpy(data, "Hello, Embedded World!", buffer.getSize());
    std::cout << "Processing data: " << data << "\n";
    
    // Buffer is automatically released when it goes out of scope
}

int main() {
    try {
    processData();
    } catch (const std::exception& e) {
      std::cout << e.what() << std::endl;
    }

    return 0;
}
