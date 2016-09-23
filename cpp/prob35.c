#include <stdio.h>
#include <assert.h>

#include "is_prime.h"
unsigned rotate(unsigned n, unsigned power);

int
main(void)
{
    unsigned power = 1;
    for (unsigned i = 2; i < 1000000; ++i) {
	if (i >= power * 10)
	    power = power * 10;
	for (unsigned n = i; is_prime(n);) {
	    n = rotate(n, power);
	    if (n == i) {
		printf("%u\n", i);
		break;
	    }
	}
    }
    return 0;
}

unsigned rotate(unsigned n, unsigned power) {
    return (n % power) * 10 + (n / power);
}
