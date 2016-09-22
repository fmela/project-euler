#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>

#import "is_prime.h"

bool has_triple_digit(int n, int *d1, int *d2, int *d3)
{
    int count[10];
    int index[10][10];
    memset(count, 0, sizeof(count));
    memset(index, 0, sizeof(index));
    int current_index = 0;
    do {
	int digit = n % 10;
	index[digit][count[digit]] = current_index++;
	if (++count[digit] == 3) {
	    *d1 = index[digit][0];
	    *d2 = index[digit][1];
	    *d3 = index[digit][2];
	    return true;
	}
    } while (n /= 10);
    return false;
}

int num_digits(int value)
{
    int num_digits = 1;
    while (value /= 10)
	++num_digits;
    return num_digits;
}

int change_digit(int value, int digit, int digit_value) {
    assert(value > 0);
    assert(digit_value >= 0);
    assert(digit_value <= 9);
    char buf[128];
    snprintf(buf, sizeof(buf), "%d", value);
    int len = strlen(buf);
    assert(len > 0);
    assert(digit < len);
    buf[(len - 1) - digit] = digit_value + '0';
    return strtol(buf, NULL, 10);
}

int main() {
    assert(change_digit(3, 0, 9) == 9);

    assert(change_digit(31, 0, 7) == 37);
    assert(change_digit(31, 1, 7) == 71);

    assert(change_digit(134, 0, 7) == 137);
    assert(change_digit(134, 1, 7) == 174);
    assert(change_digit(134, 2, 7) == 734);

    assert(change_digit(6592, 0, 7) == 6597);
    assert(change_digit(6592, 1, 7) == 6572);
    assert(change_digit(6592, 2, 7) == 6792);
    assert(change_digit(6592, 3, 7) == 7592);

    for (int n = 1001; n < 10000000; n += 2) {
	int d1, d2, d3;
	if (is_prime(n) && has_triple_digit(n, &d1, &d2, &d3)) {
	    int n_primes = 0;
	    for (int dv = 0; dv <= 9; ++dv) {
		if (dv == 0 && d3+1 == num_digits(n))
		    continue;
		int value = change_digit(change_digit(change_digit(n, d1, dv),
						      d2, dv),
					 d3, dv);
		if (is_prime(value))
		    ++n_primes;
	    }
	    if (n_primes >= 8)
		printf("%d (%d,%d,%d): %d primes\n", n, d1, d2, d3,
		       n_primes);
	}
    }
    return 1;
}
