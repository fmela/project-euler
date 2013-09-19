#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

unsigned long n_choose_k(unsigned long n, unsigned long k);
unsigned long n_permutations(unsigned zeroes, unsigned ones);

int main() {
    for (int i = 1; i <= 20; ++i) {
	cout << i*2 << " choose " << i << " = " << n_choose_k(i*2, i) << endl;
    }
    return 0;
}

unsigned long n_permutations(unsigned zeroes, unsigned ones) {
    int values[zeroes+ones];
    for (unsigned i = 0; i < zeroes; ++i)
	values[i] = 0;
    for (unsigned i = 0; i < ones; ++i)
	values[zeroes + i] = 1;
    sort(values, values + zeroes + ones);
    unsigned long n_permutations = 0;
    do {
	++n_permutations;
    } while (next_permutation(values, values + zeroes + ones));
    return n_permutations;
}

unsigned long n_choose_k(unsigned long n, unsigned long k) {
    unsigned long value = 1;
    unsigned long denom_i = 2;
    for (unsigned long i = k + 1; i <= n; ++i) {
	value *= i;
	while (denom_i <= k && value % denom_i == 0) {
	    value /= denom_i++;
	}
    }
    assert(denom_i == k+1);
    return value;
}
