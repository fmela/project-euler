#include <stdio.h>

int main()
{
    int sum = 0;
    int f1 = 1;
    int f2 = 2;
    while (f2 < 4000000) {
	if (f2 % 2 == 0) {
	    sum += f2;
	}
	int next = f1 + f2;
	f1 = f2;
	f2 = next;
    }
    printf("sum: %d\n", sum);
    return 0;
}
