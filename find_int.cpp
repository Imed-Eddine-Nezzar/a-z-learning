#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>

int main(void) {
  std::array<int, 10> arr{};

  std::cout << "Enter 10 values: ";
  for (auto& e : arr) std::cin >> e;

  // std::copy(std::begin(arr), std::end(arr), std::ostream_iterator<int>(std::cout, " "));

  int val;
  std::cout << "Enter value to search for: ";
  std::cin >> val;
  auto i = std::find(std::begin(arr), std::end(arr), val);
  std::cout << "position of x: "
            << ((i == std::end(arr)) ?
                  "not found" :
                  std::to_string(std::distance(std::begin(arr), i))) << "\n";
}