#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "is_prime.h"

int count_conseq_primes(int a, int b);

int
main(void)
{
    int max_primes = -1, max_a = 0, max_b = 0;
    for (int a = -999; a < 1000; ++a) {
	for (int b = -999; b < 1000; ++b) {
	    int primes = count_conseq_primes(a, b);
	    if (max_primes < primes) {
		max_primes = primes;
		max_a = a;
		max_b = b;
		printf("primes(%d,%d) = %d\n", max_a, max_b, max_primes);
	    }
	}
    }
    for (int n = 0; n <= max_primes; ++n) {
	int value = n * (n + max_a) + max_b;
	if (!is_prime(value)) {
	    printf("F(n)=n*n%+d*n%+d for n=%d is %d, which is not prime\n",
		   max_a, max_b, n, n * (n + max_a) + max_b);
	} else {
	    printf("%d: %d is prime\n", n, value);
	}
    }
    return 0;
}

int count_conseq_primes(int a, int b) {
    for (int n = 0; ; ++n) {
	int value = n * (n + a) + b;
	if (!is_prime(value))
	    return n;
    }
}
