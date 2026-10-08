#include <cassert>
#include <cstddef>
#include <iostream>

class IntArray {
  int *data_;
  std::size_t size_;

public:
  explicit IntArray(std::size_t n) : data_(new int[n]), size_(n) {};
  ~IntArray() { delete[] data_; }; // destructor
  IntArray(const IntArray &other)
      : data_(new int[other.size_]), size_(other.size_) {
    for (std::size_t i = 0; i < size_; i++) {
      data_[i] = other.data_[i];
    }
  }; // copy constructor

  IntArray() : data_(nullptr), size_(0) {};

  IntArray &operator=(const IntArray &other) {
    if (this == &other) {
      return *this;
    }
    delete[] data_;
    size_ = other.size_;
    data_ = new int[size_];
    for (std::size_t i = 0; i < size_; i++) {
      data_[i] = other.data_[i];
    }

    return *this;
  }

  int &operator[](std::size_t i) { return data_[i]; };
  std::size_t size() const { return size_; };
};

int main() {
  // constructor + operator[]
  IntArray a(3);
  for (std::size_t i = 0; i < a.size(); i++) {
    a[i] = static_cast<int>(i) + 1; // a = {1, 2, 3}
  }
  assert(a.size() == 3 && a[0] == 1 && a[2] == 3);

  // copy constructor: deep copy
  IntArray b = a;
  b[0] = 99;
  assert(a[0] == 1 && b[0] == 99);

  // copy assignment into an array of a different size
  IntArray c(5);
  c = a;
  assert(c.size() == 3 && c[2] == 3);
  c[1] = 42;
  assert(a[1] == 2);

  // self-assignment
  a = a;
  assert(a.size() == 3 && a[0] == 1);

  // chained assignment
  IntArray d, e;
  d = e = a;
  assert(d.size() == 3 && e.size() == 3);

  // empty default object: copy it, assign into it, assign from it
  IntArray empty;
  IntArray emptyCopy = empty;
  assert(emptyCopy.size() == 0);
  empty = a;
  assert(empty.size() == 3);
  c = IntArray();
  assert(c.size() == 0);

  std::cout << "All tests passed\n";
  return 0;
}
