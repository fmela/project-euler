#include <stdio.h>

int main() {
    for (int num = 10; num <= 99; ++num) {
	for (int den = num + 1; den <= 99; ++den) {
	    if (num%10 == den/10 && num*(den%10) == den*(num/10))
		printf("%d/%d is equivalent to %d/%d\n", num, den,
		       num/10, den%10);
	}
    }
    return 0;
}
