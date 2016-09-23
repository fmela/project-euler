#include <cassert>
#include <cstdio>
#include <vector>

#include "is_prime.h"

template<typename T>
void find_primes(T& container, unsigned limit)
{
    container.clear();
    container.push_back(2);
    for (unsigned candidate = 3; candidate < limit; candidate += 2) {
        if (is_prime(candidate))
            container.push_back(candidate);
    }
}

int main()
{
    const unsigned limit = 1000000;
    printf("Finding all primes less than %u...\n", limit / 2);
    std::vector<unsigned> primes;
    find_primes(primes, limit);
    printf("Found %zu primes less than %u\n", primes.size(), limit / 2);

    long max_prime_length = 0;
    unsigned max_prime_sum = 0;
    unsigned max_prime_start = 0, max_prime_end = 0;
    for (std::vector<unsigned>::const_iterator start = primes.begin(); start != primes.end(); ++start) {
        std::vector<unsigned>::const_iterator current = start;
        for (unsigned sum = 0; current != primes.end(); ++current) {
            sum += *current;
            if (sum >= limit)
                break;
            if (max_prime_length < (current - start) && is_prime(sum)) {
                max_prime_length = current - start;
                max_prime_sum = sum;
                max_prime_start = *start;
                max_prime_end = *current;
                printf("new max: %u = %u + ... + %u\n", max_prime_sum, max_prime_start, max_prime_end);
            }
        }
    }
    return 0;
}
