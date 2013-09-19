#include <stdio.h>
#include <stdlib.h>

int triangle(int n);
int num_factors(int n);

int main(void)
{
    int i = 1;
    for (i = 1; ; ++i) {
	int n_factors = num_factors(triangle(i));
	if (n_factors >= 500)
	    break;
    }
    printf("%d: %d\n", i, triangle(i));
    return 0;
}

int triangle(int n) {
    return (n * (n + 1)) / 2;
}

int num_factors(int n) {
    int num_factors = 0;
    for (int factor = 2, factor2 = 4, factor2_increment = 5; ; ++factor) {
	if (factor2 >= n) {
	    if (factor2 == n)
		num_factors += 1;
	    break;
	}
	if (n % factor == 0) {
	    num_factors += 2;
	}
	factor2 += factor2_increment;
	factor2_increment += 2;
    }
    return num_factors;
}
