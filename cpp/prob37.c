#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#include "is_prime.h"

// 3797, 797, 97, 7
int left_truncate(int x)
{
    if (x <= 1)
        return 0;
    const int num_digits = ceil(log10(x));
    const int leading_digit_place_value = (int) pow(10., num_digits - 1);
    return x % leading_digit_place_value;
}

// 3797, 379, 37, 9
int right_truncate(int x)
{
    return x / 10;
}

bool is_left_truncatable_prime(int x)
{
    do {
        if (x < 2 || !is_prime(x))
            return false;
        x = left_truncate(x);
    } while (x != 0);
    return true;
}

bool is_right_truncatable_prime(int x)
{
    do {
        if (x < 2 || !is_prime(x))
            return false;
        x = right_truncate(x);
    } while (x != 0);
    return true;
}

int main()
{
#if 0
    printf(" Shift left:");
    for (int x = 3797; x != 0; x = left_truncate(x))
        printf(" %d", x);
    printf("\n");

    printf("Shift right:");
    for (int x = 3797; x != 0; x = right_truncate(x))
        printf(" %d", x);
    printf("\n");
#endif
    int num_primes = 0;
    int sum_of_primes = 0;
    for (int x = 11; num_primes < 11; x += 2) {
        if (is_left_truncatable_prime(x) && is_right_truncatable_prime(x)) {
            printf("%d is truncatable\n", x);
            num_primes++;
            sum_of_primes += x;
        }
    }
    printf("sum: %d\n", sum_of_primes);
    return 0;
}
