#include <vector>
int sum(const std::vector<int> &v) {
  int sum = 0;
  for (const auto &x : v) {
    sum += x;
  }
  return sum;
}

void double_all(std::vector<int> &v) {
  for (auto &x : v) {
    x *= 2;
  }
}

std::vector<int> evens(const std::vector<int> &v) {
  std::vector<int> evens;
  for (const auto &x : v) {
    if (x % 2 == 0) {
      evens.push_back(x);
    }
  }
  return evens;
}
