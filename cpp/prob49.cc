#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <algorithm>
#include "is_prime.h"

using namespace std;

bool check(vector<unsigned> d)
{
    const unsigned start_value = d[3] + 10 * (d[2] + 10 * (d[1] + 10 * d[0]));
    set<unsigned> primes;
    do {
        unsigned value = d[3] + 10 * (d[2] + 10 * (d[1] + 10 * d[0]));
        // printf("    %u\n", value);
        if (is_prime(value))
            primes.insert(value);
    } while (next_permutation(d.begin(), d.end()));
    if (primes.size() >= 3) {
        printf("%u: %zu prime(s)\n", start_value, primes.size());
        for (set<unsigned>::const_iterator start = primes.begin(); start != primes.end(); ++start) {
            set<unsigned>::const_iterator next = start; ++next;
            for (; next != primes.end(); ++next) {
                unsigned candidate = *next + (*next - *start);
                if (primes.find(candidate) != primes.end()) {
                    printf("%u: %u, %u, and %u all prime!\n", start_value, *start, *next, candidate);
                }
            }
        }
    }
    return false;
}

int main()
{
    vector<unsigned> d(4);
    for (d[0] = 0; d[0] <= 9; ++d[0]) {
        for (d[1] = d[0]; d[1] <= 9; ++d[1]) {
            for (d[2] = d[1]; d[2] <= 9; ++d[2]) {
                for (d[3] = d[2]; d[3] <= 9; ++d[3]) {
                    // printf(">>> %u%u%u%u\n", d[0], d[1], d[2], d[3]);
                    check(d);
                }
            }
        }
    }
    return 0;
}
