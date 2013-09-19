#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

unsigned sum_of_proper_divisors(unsigned n) {
    unsigned sum = 1;
    for (unsigned factor = 2; factor*factor <= n; ++factor) {
	if (n % factor == 0) {
	    if (factor * factor == n)
		sum += factor;
	    else
		sum += factor + (n / factor);
	}
    }
    return sum;
}

int
main(void)
{
#define N 28124
    unsigned abundant[N] = { 0 }, num_abundant = 0;
    for (unsigned i = 1; i < N; ++i) {
	if (sum_of_proper_divisors(i) > i) {
	    abundant[num_abundant++] = i;
	}
    }
    bool sum_abundant[N] = { 0 };
    for (unsigned i = 0; i < num_abundant; ++i) {
	for (unsigned j = 0; j < num_abundant && abundant[i] + abundant[j] < N; ++j) {
	    sum_abundant[abundant[i] + abundant[j]] = true;
	}
    }
    unsigned sum = 0;
    for (unsigned i = 1; i < N; ++i) {
	if (!sum_abundant[i]) {
	    sum += i;
	}
    }
    printf("sum=%u\n", sum);
    return 0;
}
