#include <stdio.h>

int diagonal(int n) {
    int sum = 1;
    printf("Starting with %d\n", sum);
    int current = 1;
    for (int inc = 2; inc < n; inc += 2) {
	current += inc * 4;
	sum += 4 * current - 6 * inc;
    }
    return sum;
}

int main()
{
    printf("%d\n", diagonal(5));
    printf("%d\n", diagonal(7));
    printf("%d\n", diagonal(1001));
    return 0;
}
