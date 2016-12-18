#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

#include <cmath>
#include <cstdint>

static std::vector<std::uint32_t> primes;

void sieve(uint32_t n) {
    std::vector<bool> candidates(n, true);
    uint64_t x;
    for(uint32_t i = 2; i < std::sqrt(candidates.size()); ++i) {
        if (candidates[i]) {
            x = std::pow(i, 2);
            for (uint32_t j = x, k = 0; j < candidates.size();
                j = x + i * k, ++k) {
                candidates[j] = false;
            }
        }
    }

    for (uint32_t i = 2; i < candidates.size(); ++i) {
        if (candidates[i]) ::primes.push_back(i);
    }
}

void dump_primes(const char* path) {
    std::ofstream ofile{path};
    std::copy(std::begin(::primes), std::end(::primes),
              std::ostream_iterator<uint32_t>{ofile, " "});
}

void load_primes(std::ifstream& ifile) {
    std::copy(std::istream_iterator<uint32_t>{ifile},
              std::istream_iterator<uint32_t>{},
              std::back_inserter(::primes));
}

inline bool is_prime(uint32_t n) {
    return std::binary_search(std::begin(::primes), std::end(::primes), n);
}


int main(void) {
    const char* path = "primes.lst";

    {
        std::ifstream pfile{path};
        if (!pfile) {
            sieve(10000000);
            dump_primes(path);
        }
        else load_primes(pfile);
    }

    uint32_t num;
    for(int i = 0; i < 10; ++i) {
        std::cout << "Enter number: ";
        std::cin >> num;
        std::cout << num << " is " << ((::is_prime(num)) ? "" : "not ") << "prime\n";
    }
}