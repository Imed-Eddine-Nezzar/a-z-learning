#include <iostream>
#include <string>
#include <algorithm>

int main(void) {
  std::string input;
  std::getline(std::cin, input);

  bool has_duplicates = (std::unique(input.begin(), input.end()) != input.end());
  std::cout << "input has duplicate letters: "
            << (has_duplicates ? "yes" : "no") << "\n";
}
