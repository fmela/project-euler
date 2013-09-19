#include <stdio.h>
#include <stdbool.h>

unsigned pentagonal(unsigned i);
bool is_pentagonal(unsigned n);

int main() {
#define N 3000
    for (unsigned i = 1; i < N; ++i) {
	unsigned p_i = pentagonal(i);
	for (unsigned j = i + 1; j < N; ++j) {
	    unsigned p_j = pentagonal(j);
	    if (is_pentagonal(p_j + p_i)) {
		if (is_pentagonal(p_j - p_i)) {
		    printf("* p[%u]=%u and p[%u]=%u\n", i, p_i, j, p_j);
		}
	    }
	}
    }
    return 0;
}

unsigned pentagonal(unsigned i) {
    return (i * (3 * i - 1)) / 2;
}

bool is_pentagonal(unsigned n) {
    for (unsigned i = 1; ; ++i) {
	unsigned p = pentagonal(i);
	if (p == n)
	    return true;
	if (p > n)
	    return false;
    }
}
