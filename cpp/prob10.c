#include <stdio.h>
#include <inttypes.h>

unsigned smallest_factor(unsigned p) {
    if ((p & 1) == 0) {
	if (p == 2)
	    return 0;
	return 2;
    }
    for (unsigned factor = 3; ; factor += 2) {
	if (factor * factor >= p) {
	    if (factor * factor == p)
		return factor;
	    return 0;
	}
	if (p % factor == 0)
	    return factor;
    }
}

int
main(void)
{
    uint64_t sum = 2;
    for (unsigned candidate = 3; candidate <= 2000000; candidate += 2) {
	if (smallest_factor(candidate) == 0) {
	    sum += candidate;
	    if (sum < candidate)
		printf("overflow!\n");
	}
    }
    printf("sum=%" PRIu64 "\n", sum);
    return 0;
}
