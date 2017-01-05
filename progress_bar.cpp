#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <ios>

void progress_bar(size_t length, size_t step) {
  using namespace std::chrono_literals;
  std::cout.precision(1);
  std::cout << std::fixed << std::right;

  std::cout << "Doing some important stuff!\n";

  size_t progress = 0;
  float percent = 0.0;
  while (progress <= length) {
    percent = static_cast<float>(progress) * 100 / length;
    std::cout << "\rprogress: ["
              << std::string(progress, '|')
              << std::string(length - progress, '-')
              << "] "
              << percent << "%";
    std::flush(std::cout);

    progress += step;
    std::this_thread::sleep_for(500ms);
  }
  std::cout << "\nDone!!\n";
}

int main(void) {
  progress_bar(30, 1);
}
