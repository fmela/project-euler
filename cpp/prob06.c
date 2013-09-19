#include <stdio.h>

int main()
{
    long square_of_sum = 0, sum_of_squares = 0;
    for (long i = 1; i <= 100; i++) {
	sum_of_squares += i * i;
	square_of_sum += i;
    }
    square_of_sum *= square_of_sum;
    printf("sum of squares: %ld\n", sum_of_squares);
    printf(" square of sum: %ld\n", square_of_sum);
    printf("    difference: %ld\n", square_of_sum - sum_of_squares);
    return 0;
}
