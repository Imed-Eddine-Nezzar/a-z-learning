#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#include <termios.h>
#include <unistd.h>

int main(void) {
  const std::string PASSWORD{"password"};


  { // hide password
    termios orgstt;
    tcgetattr(STDIN_FILENO, &orgstt);
    auto newstt = orgstt;
    newstt.c_lflag &= ~ECHO;

    tcsetattr(STDIN_FILENO, TCSANOW, &newstt);
    std::string fst_try, snd_try;
    std::cout << "password: ";
    std::getline(std::cin, fst_try);

    std::cout << "\nretype password: ";
    std::getline(std::cin, snd_try);

    if (fst_try != snd_try or snd_try != PASSWORD) {
      std::cout << "\nwrong password!\n";
      exit(EXIT_FAILURE);
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &orgstt);
  }

  std::vector<std::vector<float>> marks;
  {
    int groups;
    std::cout << "\nEnter number of groups: ";
    std::cin >> groups;
    marks.resize(groups);
  }

  int student_count;
  for (auto& group : marks) {
    std::cout << "Enter student number: ";
    std::cin >> student_count;
    group.resize(student_count);

    for (auto& mark : group) {
      std::cout << "Enter mark (0~100): ";
      std::cin >> mark;
    }

    std::sort(std::begin(group), std::end(group));

    std::cout << "\nReport:\n"
              <<   "=======\n";

    std::cout << "marks:\n";
    std::copy(std::begin(group), std::end(group),
              std::ostream_iterator<float>{std::cout, ", "});

    std::cout << "\n"
              << "min mark: " << *std::begin(group) << "\n"
              << "max mark: " << *std::rbegin(group)  << "\n";

    auto mid = std::lower_bound(std::begin(group), std::end(group), 50.0);
    std::cout << "failed: "    << std::distance(std::begin(group), mid)   << "\n"
              << "succeeded: " << std::distance(mid, std::end(group)) << "\n";
  }
}
