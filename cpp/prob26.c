#include <stdio.h>
#include <assert.h>

int next(int divisor, int state) {
    int digit = state / divisor;
    assert(digit < 10);
    return (state - digit * divisor) * 10;
}

int main() {
    for (int divisor = 2; divisor <= 1000; ++divisor) {
	if (divisor % 2 == 0 || divisor % 5 == 0)
	    continue;
	printf("1/%d = 0.", divisor);
	int state = 10;
	for (int j = 0; state && j < 50; ++j) {
	    printf("%c", '0' + state/divisor);
	    state = next(divisor, state);
	    if (j == 49)
		printf("...");
	}
	printf("\n");

	int tortoise = 10;
	tortoise = next(divisor, tortoise);

	int hare = 10;
	hare = next(divisor, hare);
	hare = next(divisor, hare);

	while (tortoise != hare) {
	    tortoise = next(divisor, tortoise);
	    hare = next(divisor, hare);
	    hare = next(divisor, hare);
	}
	int mu = 0;
	tortoise = 10;
	while (tortoise != hare) {
	    tortoise = next(divisor, tortoise);
	    hare = next(divisor, hare);
	    ++mu;
	}

	int lam = 1;
	hare = next(divisor, tortoise);
	while (tortoise != hare) {
	    hare = next(divisor, hare);
	    ++lam;
	}
	printf("%d: mu=%d lam=%d\n", divisor, mu, lam);
    }
    return 0;
}
