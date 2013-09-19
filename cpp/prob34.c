#include <stdio.h>

unsigned factorial_digit[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

unsigned sum_factorial_digits(unsigned n) {
    unsigned sum = 0;
    while (n > 0) {
	sum += factorial_digit[n % 10];
	n /= 10;
    }
    return sum;
}

int main() {
    printf("sum_factorial_digits(100)=%u\n", sum_factorial_digits(100));
    for (unsigned i = 3; i < 4000000000ULL; i++) {
	if (i == sum_factorial_digits(i))
	    printf("%u\n", i);
    }
    return 0;
}
