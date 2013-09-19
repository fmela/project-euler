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
    unsigned prime_index = 1;
    for (unsigned candidate = 3; ; candidate += 2) {
	if (smallest_factor(candidate) == 0) {
	    if (++prime_index == 10001) {
		printf("%u'th prime: %u\n", prime_index, candidate);
		break;
	    }
	}
    }
    return 0;
}
