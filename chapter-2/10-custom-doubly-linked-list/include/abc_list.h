#ifndef CPP_TRAINING_DOUBLY_LINKED_LIST_H_
#define CPP_TRAINING_DOUBLY_LINKED_LIST_H_

#include <iterator>
#include <memory>
#include <utility>

namespace abc {

// Doubly Linked List Implementation

template <typename T>
class DoublyLinkedList {
 private:
  struct Node {
    T data;
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;
    explicit Node(const T& value) : data(value) {}
    explicit Node(T&& value) : data(std::move(value)) {}
    virtual ~Node() { std::cout << "~Node() has been called!" << std::endl; }
  };

  std::shared_ptr<Node> head_;
  std::shared_ptr<Node> tail_;
  size_t size_ = 0;

 public:
  // Define Iterator **before** any method that uses it.
  class Iterator {
   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    explicit Iterator(std::shared_ptr<Node> node) : node_(node) {}

    reference operator*() const { return node_->data; }
    pointer operator->() const { return &node_->data; }

    Iterator& operator++() {
      node_ = node_->next;
      return *this;
    }
    Iterator operator++(int) {
      Iterator tmp = *this;
      ++(*this);
      return tmp;
    }
    Iterator& operator--() {
      node_ = node_->prev.lock();
      return *this;
    }
    Iterator operator--(int) {
      Iterator tmp = *this;
      --(*this);
      return tmp;
    }

    bool operator==(const Iterator& other) const {
      return node_ == other.node_;
    }
    bool operator!=(const Iterator& other) const { return !(*this == other); }

   private:
    std::shared_ptr<Node> node_;
    friend class DoublyLinkedList;
  };

  DoublyLinkedList() = default;
  ~DoublyLinkedList() = default;

  DoublyLinkedList(const DoublyLinkedList&) = delete;
  DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

  DoublyLinkedList(DoublyLinkedList&& other) noexcept {
    *this = std::move(other);
  }
  DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept {
    if (this != &other) {
      Clear();
      head_ = std::move(other.head_);
      tail_ = std::move(other.tail_);
      size_ = other.size_;
      other.size_ = 0;
    }
    return *this;
  }

  T& front() {
    // Precondition: list must not be empty.
    return head_->data;
  }

  const T& front() const { return head_->data; }

  T& back() { return tail_->data; }

  const T& back() const { return tail_->data; }

  void PushFront(const T& value) {
    auto new_node = std::make_shared<Node>(value);
    new_node->next = head_;
    if (head_) {
      head_->prev = new_node;
    }
    head_ = new_node;
    if (!tail_) {
      tail_ = new_node;
    }
    ++size_;
  }

  void PopFront() {
    if (!head_) return;
    head_ = head_->next;
    if (head_) {
      head_->prev.reset();
    } else {
      tail_.reset();
    }
    --size_;
  }

  void PopBack() {
    if (!tail_) return;
    if (tail_ == head_) {
      Clear();
      return;
    }
    if (auto prev = tail_->prev.lock()) {
      prev->next.reset();
      tail_ = prev;
    }
    --size_;
  }

  void PushBack(const T& value) {
    auto new_node = std::make_shared<Node>(value);
    if (!head_) {
      head_ = new_node;
      tail_ = new_node;
    } else {
      new_node->prev = tail_;
      tail_->next = new_node;
      tail_ = new_node;
    }
    ++size_;
  }

  void PushBack(T&& value) {
    auto new_node = std::make_shared<Node>(std::move(value));
    if (!head_) {
      head_ = new_node;
      tail_ = new_node;
    } else {
      new_node->prev = tail_;
      tail_->next = new_node;
      tail_ = new_node;
    }
    ++size_;
  }

  template <typename... Args>
  void EmplaceBack(Args&&... args) {
    auto new_node = std::make_shared<Node>(T(std::forward<Args>(args)...));
    if (!head_) {
      head_ = new_node;
      tail_ = new_node;
    } else {
      new_node->prev = tail_;
      tail_->next = new_node;
      tail_ = new_node;
    }
    ++size_;
  }

  template <typename... Args>
  void EmplaceFront(Args&&... args) {
    auto new_node = std::make_shared<Node>(T(std::forward<Args>(args)...));
    new_node->next = head_;
    if (head_) {
      head_->prev = new_node;
    }
    head_ = new_node;
    if (!tail_) {
      tail_ = new_node;
    }
    ++size_;
  }

  Iterator Find(const T& value) {
    for (auto it = begin(); it != end(); ++it) {
      if (*it == value) {
        return it;
      }
    }
    return end();
  }

  void Insert(Iterator pos, const T& value) {
    if (!pos.node_) {
      PushBack(value);
      return;
    }
    auto new_node = std::make_shared<Node>(value);
    new_node->prev = pos.node_->prev;
    new_node->next = pos.node_;
    if (auto prev = pos.node_->prev.lock()) {
      prev->next = new_node;
    } else {
      head_ = new_node;
    }
    pos.node_->prev = new_node;
    ++size_;
  }

  void Erase(Iterator pos) {
    if (!pos.node_) return;
    if (pos.node_ == head_) {
      head_ = head_->next;
      if (head_) head_->prev.reset();
    } else {
      if (auto prev = pos.node_->prev.lock()) {
        prev->next = pos.node_->next;
      }
      if (pos.node_->next) {
        pos.node_->next->prev = pos.node_->prev;
      }
    }
    --size_;
  }

  void Clear() {
    head_.reset();
    tail_.reset();
    size_ = 0;
  }

  size_t Size() const { return size_; }
  bool Empty() const { return size_ == 0; }

  Iterator begin() { return Iterator(head_); }
  Iterator end() { return Iterator(nullptr); }
};

}  // namespace abc

#endif  // !CPP_TRAINING_DOUBLY_LINKED_LIST_H_
