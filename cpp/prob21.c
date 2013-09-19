#include <stdio.h>
#include <inttypes.h>
#include "sum_of_proper_divisors.h"

int
main(void)
{
#define N 10000
    unsigned sum_of_amicable = 0;
    for (unsigned i = 1; i < N; ++i) {
	unsigned sum1 = sum_of_proper_divisors(i);
	if (i == sum1)
	    continue;
	unsigned sum2 = sum_of_proper_divisors(sum1);
	if (i == sum2 && i < sum1) {
	    printf("%u is amicable, adding %u and %u\n", i, i, sum1);
	    sum_of_amicable += i + sum1;
	}
    }
    printf("sum=%u\n", sum_of_amicable);
    return 0;
}
