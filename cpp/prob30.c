#include <stdio.h>
#include <stdbool.h>

bool is_product_of_fifth_powers(long n) {
    long sum = 0;
    long m = n;
    while (m) {
	long digit = m % 10;
	m = m / 10;
	sum += digit * digit * digit * digit * digit;
    }
    return n == sum;
}

int main() {
    for (long i = 1; i <= 1000000; ++i) {
	if (is_product_of_fifth_powers(i))
	    printf("%ld\n", i);
    }
    return 0;
}
