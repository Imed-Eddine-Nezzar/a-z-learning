#include <iostream>
#include <queue>      // std::priority_queue
#include <string>     // std::string, std::getline
#include <sstream>    // std::istringstream
#include <cassert>    // assert

template <typename T>
std::priority_queue<T> make_max_heap(const std::string& line) {
  std::priority_queue<T> pqueue;
  std::istringstream line_stream{ line };
  T chunk;

  while (line_stream >> chunk)
    pqueue.push(chunk);

  return pqueue;
}


int main(void) {

  using value_type = unsigned int;

  std::priority_queue<value_type> wights;
  std::priority_queue<value_type> prices;

  value_type ntests;
  std::cin >> ntests;

  value_type ndays, ndiamonds;
  std::string line;
  value_type profit;

  while (ntests--) {
    std::cin >> ndiamonds >> ndays;
    std::cin.ignore();

    // reading wights
    std::getline(std::cin, line);
    wights = make_max_heap<value_type>(line);
    assert(wights.size() == ndiamonds);

    // reading prices
    std::getline(std::cin, line);
    prices = make_max_heap<value_type>(line);
    assert(prices.size() == ndays);

    // calculating profit
    profit = 0;
    while (not prices.empty() and not wights.empty()) {
      profit += prices.top() * wights.top();
      prices.pop();
      wights.pop();
    }

    std::cout << profit << "\n";
  }
}
