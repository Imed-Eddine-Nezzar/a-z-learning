#include <cmath>
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

static std::vector<size_t> primes;

void sieve(size_t n) {
    std::vector<bool> candidates(n, true);
    unsigned long x;
    for(size_t i = 2; i < std::sqrt(candidates.size()); ++i) {
        if (candidates[i]) {
            x = std::pow(i, 2);
            for (size_t j = x, k = 0; j < candidates.size();
                 j = x + i * k, ++k) {
                candidates[j] = false;
            }
        }
    }

    for (size_t i = 2; i < candidates.size(); ++i) {
        if (candidates[i])
            ::primes.push_back(i);
    }
}

using pair_prime_pow = std::pair<size_t, size_t>;

std::vector<pair_prime_pow> factorize(size_t n) {
    std::vector<pair_prime_pow> factors;
    size_t power, rest = n;
    for (const auto& prime : primes) {
        power = 0;
        while(rest % prime == 0) {
            rest /= prime;
            power += 1;
            if (not rest) break;
        }
        if (power)
            factors.push_back(std::make_pair(prime, power));
    }
    return factors;
}

void list_factors(size_t n) {
    auto factors = factorize(n);
    for (const auto& f : factors) {
        std::cout << "(" << f.first ;
        if (f.second > 1)
            std::cout << "**" << f.second;
        std::cout << ")";
    }
    std::cout << "\n";
}

// helper functions
void load_primes(std::ifstream& ifile);
void dump_primes(const char* path);

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
    
    size_t num;
    for(;;) {
        std::cout << "Enter number: ";
        std::cin >> num;
        list_factors(num);
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
