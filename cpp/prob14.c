#include <stdio.h>
#include <stdlib.h>

#define MAX_N	1000000

unsigned *memoize = NULL;
unsigned chain_length(unsigned n);

int main() {
    memoize = malloc(sizeof(*memoize) * (MAX_N + 1));
    for (unsigned i = 0; i <= MAX_N; ++i) {
	memoize[i] = 0;
    }
    memoize[1] = 1;

    unsigned max_i = 0, max_length = 0;
    for (unsigned i = 1; i <= MAX_N; ++i) {
	unsigned length = chain_length(i);
	if (max_length < length) {
	    max_length = length;
	    max_i = i;
	    printf("length(%u)=%u\n", max_i, max_length);
	}
    }
    free(memoize);
    return 0;
}

unsigned chain_length(unsigned n) {
    if (n <= MAX_N && memoize[n]) {
	return memoize[n];
    }
    unsigned next_n = (n & 1) ? 3*n + 1 : n >> 1;
    unsigned length = 1 + chain_length(next_n);
    if (n <= MAX_N) {
	memoize[n] = length;
    }
    return length;
}
