#include <stdexcept>
#include <unordered_map>
#include <vector>
std::unordered_map<int, int> frequency(const std::vector<int> &v) {
  std::unordered_map<int, int> frequencies;
  for (int x : v) {
    frequencies[x]++;
  }
  return frequencies;
}

int most_common(const std::vector<int> &v) {
  if (v.empty()) {
    throw std::invalid_argument("most_common: empty input");
  }
  std::unordered_map<int, int> frequencies = frequency(v);
  int most_common;
  int max_occurrences = 0;
  for (const auto &entry : frequencies) {
    if (max_occurrences < entry.second) {
      most_common = entry.first;
      max_occurrences = entry.second;
    }
  }
  return most_common;
}
