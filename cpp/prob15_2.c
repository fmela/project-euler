#include <stdio.h>

long gcd(long a, long b) {
    if (a < b) {
	long t = a;
	a = b;
	b = t;
    }
    for (;;) {
	long m = a % b;
	if (m == 0)
	    return b;
	a = b;
	b = m;
    }
}

long choose(int n, int k)
{
    if (k == 0)
	return 1;
    if (n == 0)
	return 0;
    long num = 1, den = 1;
    for (int i = 1; i <= k; ++i) {
	num *= n-k+i;
	den *= i;
	long g = gcd(num, den);
	if (g > 1) {
	    num = num / g;
	    den = den / g;
	}
    }
    return num / den;
}

int main()
{
    for (int i=1; i<=20; i++) {
	printf("%d: %ld\n", i, choose(i*2, i));
    }
    return 0;
}
